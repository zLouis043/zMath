# zMath
 An intuitive single header library for doing linear algebra calcualtions.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![GitHub last commit (branch)](https://img.shields.io/github/last-commit/zLouis043/zMath/main)
![GitHub top language](https://img.shields.io/github/languages/top/zLouis043/zMath)

## How-To
Just include the header file your project and define its implementation: 

```c

#define ZMATH_IMPLEMENTATION
#include "zmath.h"

```

## Test and functionalities 

### How to setup the test file

For Windows:

```console

$ ./run.bat 

```

For Linux:

```console

$ ./run.sh

```

### Example 

```c

#include <stdio.h>

#define ZMATH_IMPLEMENTATION
#include "src/zmath/zmath.h"

int main(void){

  zVec v1 = newZVector(1.0f, 2.0f, 3.0f, 4.0f);
  printV(v1);

  zVec v2 = newDefaultVector(4, 1.0f);
  printV(v2);

  zVec v3 = sumVector(v1, v2);
  printV(v3);

  return 0;

}

Output > | Vector of size 4: {
         |    [ 2.000000, 3.000000, 4.000000, 5.000000 ]
         |  }

```
