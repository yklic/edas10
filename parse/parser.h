#ifndef _PARSER_H
#define _PARSER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <time.h>

#define WORD_LEN    12
#define SHAPEN_LEN  6
#define RECT_SIZE   4
#define TPZD_SIZE   16
#define SHAPEG_NAME "net"
#define SHAPEGN_LEN strlen(SHAPEG_NAME)
#define INIT_SHAPE  SHAPEG_NAME "0"

#define DEBUG

typedef struct layout_field {
  // the number of nets
  int nn; 
  // the number of shapes
  int ns;
  // the boundary of field
  double * b;
  // the dielectric
  double * d;
  // the nets list
  double * nets;
  // the shapes indicator
  int    * shps;
} lf;

lf * get_lf(FILE * fp);
int * free_lf(lf * field);

#ifdef __cplusplus
}
#endif

#endif
