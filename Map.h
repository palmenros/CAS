//
// Created by pedro on 29/04/18.
//

#pragma once


#include "Vector.h"

template <class Key, class Value>
class Map
{
private:

	//Linked list structure to handle collisions
	struct MapNode
	{
		Key key;
		Value value;

		MapNode* next;

		MapNode(const Key& key, const Value& value, MapNode* next)
			: key(key), value(value), next(next)
		{
		}
	};

	//Capacity of slots in the
	size_t slotsNum;

	//Current size of the map
	size_t size;

	//Raw data representing the map
	Vector<MapNode*> data;

public:

	Map()
		: slotsNum(16), data(Vector<MapNode*>(slotsNum)), size(0)
	{
		for(size_t i = 0; i < slotsNum; i++)
		{
			data.push(NULL);
		}
	}

	Map(size_t slotsNum)
		: slotsNum(slotsNum), data(Vector<MapNode*>(slotsNum)), size(0)
	{
		for(size_t i = 0; i < slotsNum; i++)
		{
			data.push(NULL);
		}
	}

	size_t getSize() const
	{
		return size;
	}

	bool isEmpty() const
	{
		return size == 0;
	}

	/**
	 * Gets Value from a given Key. Is key does not exist, NULL is returned
	 * @param key Key. Must be hashable
	 * @return Value pointer or NULL
	 */
	Value* get(const Key& key)
	{
		size_t hash = Algorithm::hash<Key>()(key) % slotsNum;
		MapNode* node = data[hash];

		//Search for Value in list
		while(node != NULL)
		{
			if(node->key == key)
			{
				return &node->value;
			}

			node = node->next;
		}

		return NULL;

	}

	/**
	 * Gets Value from a given Key. Is key does not exist, NULL is returned
	 * @param key Key. Must be hashable
	 * @return Value pointer or NULL
	 */
	const Value* get(const Key& key) const
	{
		size_t hash = Algorithm::hash<Key>()(key) % slotsNum;
		MapNode* node = data[hash];

		//Search for Value in list
		while(node != NULL)
		{
			if(node->key == key)
			{
				return &node->value;
			}

			node = node->next;
		}

		return NULL;
	}

	/**
	 * Adds key pair value to the map. If key is already present, the value is updated.
	 * @param key Key. Must be hashable
	 * @param value Value. If key is already present, this becomes the new value.
	 */
	Value& add(const Key& key, const Value& value)
	{
		size_t hash = Algorithm::hash<Key>()(key) % slotsNum;
		MapNode* head = data[hash];

		//Check if key is already present
		while (head != NULL)
		{
			if(head->key == key)
			{
				head->value = value;
				return head->value;
			}

			head = head->next;
		}

		//Insert key in chain
		size++;
		head = data[hash];
		MapNode* newNode = new MapNode(key, value, head);
		data[hash] = newNode;

		//If load factor is beyond threshold, double hash table size and rehash
		if(float(size) / slotsNum >= 0.7)
		{
			Vector<MapNode*> tmp = data;
			slotsNum *= 2;
			data = Vector<MapNode*>(slotsNum);
			size = 0;

			for(size_t i = 0; i < slotsNum; i++)
			{
				data.push(NULL);
			}

			for(size_t i = 0; i < tmp.getSize(); i++)
			{
				MapNode* node = tmp[i];
				while(node != NULL)
				{
					add(node->key, node->value);
					MapNode* tmpNode = node->next;
					delete node;
					node = tmpNode;
				}
			}

			//Search for new node
			size_t newHash = Algorithm::hash<Key>()(key) % slotsNum;
			MapNode* returnNode = data[newHash];

			while(returnNode != NULL)
			{
				if(returnNode->key == key)
				{
					return returnNode->value;
				}

				returnNode = returnNode->next;
			}

		}

		return newNode->value;
	}

	/**
	 * Deletes object from map. Does nothing if key is not found
	 * @param key Key. Must be hashable
	 */
	void remove(const Key& key)
	{
		size_t hash = Algorithm::hash<Key>()(key) % slotsNum;
		MapNode* head = data[hash];

		MapNode* prev = NULL;
		while(head != NULL)
		{
			if(head->key == key)
			{
				break;
			}
			prev = head;
			head = head->next;
		}

		//Key not found
		if(head == NULL)
		{
			return;
		}

		size--;

		if(prev == NULL)
		{
			//First in linked list
			data[hash] = head->next;
		}
		else
		{
			prev->next = head->next;
		}

		delete head;
	}

	~Map()
	{
		//Destruct all created MapNodes
		for(size_t i = 0; i < slotsNum; i++)
		{
			MapNode* head = data[i];
			while(head != NULL)
			{
				MapNode* newHead = head->next;
				delete head;
				head = newHead;
			}

		}
	}

	Map(const Map<Key, Value>& other)
	{
		slotsNum = other.slotsNum;
		size = 0;
		data = Vector<MapNode*>(slotsNum);

		for(size_t i = 0; i < slotsNum; i++)
		{
			data.push(NULL);
		}

		for(size_t i = 0; i < other.data.getSize(); i++)
		{
			MapNode* node = other.data[i];
			while(node != NULL)
			{
				add(node->key, node->value);
				node = node->next;
			}
		}

	}

	Map<Key, Value>& operator=(const Map<Key, Value>& other)
	{

		//Delete previous nodes

		for(size_t i = 0; i < slotsNum; i++)
		{
			MapNode* head = data[i];
			while(head != NULL)
			{
				MapNode* newHead = head->next;
				delete head;
				head = newHead;
			}

		}

		//Create copy

		slotsNum = other.slotsNum;
		size = 0;
		data = Vector<MapNode*>(slotsNum);

		for(size_t i = 0; i < slotsNum; i++)
		{
			data.push(NULL);
		}

		for(size_t i = 0; i < other.data.getSize(); i++)
		{
			MapNode* node = other.data[i];
			while(node != NULL)
			{
				add(node->key, node->value);
				node = node->next;
			}
		}

		return *this;

	}

	Value& operator[](const Key& key)
	{
		Value* value = get(key);
		if(value == NULL)
		{
			return add(key, Value());
		}
		return *value;
	}

	bool exists(const Key& key) const
	{
		return get(key) != NULL;
	}
};


