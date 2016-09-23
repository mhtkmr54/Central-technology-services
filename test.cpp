
#include <iostream>       // std::cin, std::cout
#include <queue> 
#include <cstring>          // std::queue
#include <map>

using namespace std;

int main ()
{
  char arr[] = "aaaa";
  map<char,int> mymap;
  for (int i =0 ; i < strlen(arr); i++){
    mymap[arr[i]] += 1;
  }
  for (auto el : mymap){
    cout << el.first << " : " << el.second << endl;
  }
 cout << endl;
  return 0;
}
