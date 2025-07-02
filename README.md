# colib

Colib is a C library that provides "BEGIN", "END", "COBEGIN", "COEND" and "COSECTION" blocks for C.

This is to help people working on parallelism related code/pseudocode that is based on "Concurrent Pascal"-based syntax that doesn't exist nowdays (Concurrent Pascal, Modula-2, etc...).

## How to use

### Code

 - BEGIN states the beginning of a block
 - END states the end of a block
 
 - COBEGIN states the beginning of a parallel block
 - COSECTION states a parallel section inside a COBEGIN block
   - This is used to separate different tasks that run concurrently
 - COEND states the end of a parallel block

### Compile

Colib uses the OpenMP library under the hood, so you have to compile including it (`-fopenmp` for GCC).

For example:
```
gcc -fopenmp main.c -o main
```

## Example
```
#include "colib.h"

int main() {
    BEGIN

      COBEGIN
          COSECTION
          {
              printf("Section 1\n");
          }
          COSECTION
          {
              printf("Section 2\n");
          }
      COEND

    END

    /*** * * ***/

    return 0;
}

```
