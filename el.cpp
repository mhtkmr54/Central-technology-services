// min_element/max_element example
#include <iostream>     // std::cout
#include <algorithm>    // std::min_element, std::max_element
#include <deque>

using namespace std;
bool myfn(int i, int j) { 
  i = i * -1;
  j = j * -1;
  return i<j; }


int main () {
  int myints[] = {3,7,2,5,6,4,9};
  int size = sizeof(myints)/sizeof(int);
  deque<int> mydeq;
  for (int k = 0; k < size; k++){
    mydeq.push_back(myints[k]);
  }
  // using default comparison:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7) << '\n';

  // using function myfn as comp:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7,myfn) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7,myfn) << '\n';
 
  std::cout << "The smallest element in deque is " << *min_element(mydeq.begin(),mydeq.end(),myfn) << '\n';
  std::cout << "The largest element in deque is "  << *max_element(mydeq.begin(),mydeq.end(),myfn) << '\n';
  
  return 0; 
}

