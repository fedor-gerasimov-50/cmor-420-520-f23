#include <stdio.h>
#include "foo.h"

void print_Foo(const Foo * foo){
  printf("foo->x = %d\n", foo->x);
}
