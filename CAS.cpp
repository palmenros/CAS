/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   File name : CAS.cpp                                         */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/

#include "String.h"
#include "Vector.h"
#include "Map.h"

//Export everything to C linkage. Keep C++ headers above the export in order to be able to benefit from C++ features
extern "C" {

#include "fxlib.h"
#include "syscall.h"

//****************************************************************************
//  AddIn_main (Sample program main function)
//
//  param   :   isAppli   : 1 = This application is launched by MAIN MENU.
//                        : 0 = This application is launched by a strip in eACT application.
//
//              OptionNum : Strip number (0~3)
//                         (This parameter is only used when isAppli parameter is 0.)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int AddIn_main(int isAppli, unsigned short OptionNum) {
  unsigned int key;

  Bdisp_AllClr_DDVRAM();

//  String arr[] = {"hola mundo", "me llamo pedro", "abcd", "abba", "cadabra", "magia", "magiad", "aaa"};
//  Vector<String> v(arr);
//  v.sort();
//
//  for(int i = 0; i < v.getSize(); i++)
//  {
//  	locate(1, i + 1);
//  	Print((const unsigned char*) v[i].getString());
//  }

//	Vector<int> ciphers;
//	int n = sizeof(size_t);
//	while(n != 0)
//	{
//		ciphers.push(n % 10);
//		n /= 10;
//	}
//
//	locate(1, 1);
//	for(int i = 0; i < ciphers.getSize(); i++)
//	{
//		Print((unsigned char*)String('0' + ciphers[i]).getString());
//	}
//
//	Map<String, int> m;
//	volatile int* i = m.get("Hola mundo");

  while (true) {
	GetKey(&key);
  }

  return 1;
}




//****************************************************************************
//**************                                              ****************
//**************                 Notice!                      ****************
//**************                                              ****************
//**************  Please do not change the following source.  ****************
//**************                                              ****************
//****************************************************************************


#pragma section _BR_Size
unsigned long BR_Size;
#pragma section

#pragma section _TOP

//****************************************************************************
//  InitializeSystem
//
//  param   :   isAppli   : 1 = Application / 0 = eActivity
//              OptionNum : Option Number (only eActivity)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int InitializeSystem(int isAppli, unsigned short OptionNum) {
  return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section

}