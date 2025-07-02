#ifndef LIB_COLIB_H
#define LIB_COLIB_H

#include <stdio.h>
#include <omp.h>

#define BEGIN do {
#define END } while (0);

#define COBEGIN _Pragma("omp parallel sections")
#define COEND

#define COSECTION _Pragma("omp section")

#endif
