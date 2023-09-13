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

  MZ_Vec v1 = MZ_new_vector(1.0f, 2.0f, 3.0f, 4.0f);
  MZ_print_vector(stdout, v1);

  MZ_Vec v2 = MZ_new_default_vector(4, 1.0f);
  MZ_print_vector(stdout, v2);

  MZ_Vec v3 = MZ_add_two_vectors(v1, v2);
  MZ_print_vector(stdout, v3);

  return 0;

}

Output > | Vector of size 4: {
         |    [ 2.000000, 3.000000, 4.000000, 5.000000 ]
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
