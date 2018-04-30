#ifndef _TEX_H
  #define _TEX_H

  #ifdef __cplusplus
  extern "C"{
  #endif

  // Standard headers inclusion.
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>

  // Casual types definition.
  typedef unsigned int uint;

  // Additional headers inclusion.
  #include "libText.h"
  #include "fxlib.h"
  #include "debug.h"

  // Symbols used in program.
  #define TEX_FONT TXT_SYSTEM
  #define TEX_MAXP 2
  #define TEX_MODE TXT_XOR

  // Global functions prototypes.
  int   TeX_isTeX          (char* expr);
  void  TeX_sizeComplex    (char *expression, int *width, int *height, int *baseline);
  void  TeX_sizeSimple     (char *element, int *width, int *height, int *baseline);
  char *TeX_getElement     (char *expression);
  char *TeX_getParameter   (char *command);
  char *TeX_extract        (char *begin, char *end);
  int   TeX_getParamNumber (char *command);
  void  TeX_drawComplex    (char *expression, int x, int y);
  void  TeX_drawSimple     (char *element, int x, int baseline);

  #ifdef __cplusplus
  }
  #endif

#endif // _TEX_H
