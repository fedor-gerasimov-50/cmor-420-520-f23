#include <iostream>
#include <utility>
#include <map>

using namespace std;

int main(void){

  map<string, int> x;
  x["this"] = 1;
  x["that"] = 10;

  x.insert(pair<string, int>("pair", 20));

  for (auto i = x.begin(); i != x.end(); ++i){
    std::cout << "First entry = " << i->first << std::endl;
    std::cout << "Second entry = " << i->second << std::endl << std::endl;
  }
  
  return 0;
}
