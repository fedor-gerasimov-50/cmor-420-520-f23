#include <iostream>
#include <utility>

using namespace std;

int main(void){

  pair<int, char> x;
  x.first = 100;
  x.second = 'G';
  cout << x.first << " ";
  cout << x.second << endl;  

  return 0;
}
