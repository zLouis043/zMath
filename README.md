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
  printVector(stdout, v1);

  zVec v2 = newDefaultZVector(4, 1.0f);
  printVector(stdout, v2);

  zVec v3 = sumVector(v1, v2);
  printVector(stdout, v3);

  return 0;

}

Output > | Vector of size 4: {
         |    [ +2, +3, +4, +5 ]
         |  }

```

### TO ENABLE THE RATIONAL VISUALIZATION WHEN PRINTING VECTORS OR MATRICES

Add the [zstring.h](https://github.com/zLouis043/zString) to your project and then in the **zmath.h** file go to :

```c

#define VISUALIZE_RATIONAL 0

```

and set it to :

```c

#define VISUALIZE_RATIONAL 1

```

#### TODO : FIND THE RANK OF THE MATRIX
