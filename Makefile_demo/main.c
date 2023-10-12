#include <stdio.h>
#include "foo.h"
#include "bar.h"

int main(){  
  Foo foo = {1};
  print_Foo(&foo);

  Bar bar = {2};
  print_Bar(&bar);

  // comment 

  return 0;
}
