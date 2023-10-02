#include <stdio.h>
#include "foo.h"

void bar(struct Foo foo){
  printf("foo.x = %d\n", foo.x);
}
