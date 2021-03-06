#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;
 
int size = 4;
deque<int> mydeq;


# include <stdio.h>
#include <map>
#include <deque>
/*int main ()
{
        int i, j;
        char a [2] [3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}};
        char b [3] [2];
        char *p = *b;
        for (i = 0; i < 2; i++) {
              for (j = 0; j < 3; j++) {
              *(p + 2*j + i) = a [i] [j];
              }
        }
}*/

int main()
{
 mydeq.resize(4,4);
 int arr[mydeq.size()];
 cout << mydeq.size();
 if(arr[0])
  printf("Initialized to ZERO");
 else
  printf("Not initialized to ZERO");
  cout << endl;
  string s = "1234";
  char to_g = s[2];
  int a = to_g - '0';
  int z = stoi(s);
  cout << "stoi o whole str " << z << endl;
  cout << "ans " << a + 4 << endl;
  map <int,deque<int> > gone;
  map <int,deque<int> >::iterator i;
  gone[1].push_back(6);
  gone[1].push_back(100);
  gone[2].push_back(-90);
  if(gone.find(1) != gone.end()){
    i = gone.find(1);
    gone.erase(i);
  } 
  for (auto el : gone){
    cout << "the left one " << el.first << endl;
  }

  cout << "gone sie " << gone.size() << endl; 
  int first[]  = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  vector<int> v(10);              
  vector<int>::iterator it;
  sort (first,first+5);     //  5 10 15 20 25
  sort (second,second+5);   // 10 20 30 40 50
  
  it=set_union (first, first+5, second, second+5, v.begin());
  v.resize(it-v.begin());
  


  vector<int> intersec(10);                      
  it=set_intersection (first, first+5, second, second+5, intersec.begin());
  intersec.resize(it-intersec.begin());                                                
  
  for (auto el : v){
    cout << el << " " << endl;
  }
  cout << endl;

  for(auto elm : intersec){
    cout << elm << " " << endl; 
  }
  cout << endl;

    deque<int> first = {5,10,15,20,25};
  deque<int> second = {50,40,30,20,10};
  vector<int> v(first.size()+second.size());                      // 0  0  0  0  0  0  0  0  0  0
  vector<int>::iterator it;
  sort (first.begin(),first.end());     //  5 10 15 20 25
  sort (second.begin(),second.end());   // 10 20 30 40 50
  
  it=set_union (first.begin(), first.end(), second.begin(), second.end(), v.begin());
  v.resize(it-v.begin());
  


  vector<int> intersec(first.size()+second.size());                      
  it=set_intersection (first.begin(), first.end(), second.begin(), second.end(), intersec.begin());
  intersec.resize(it-intersec.begin());                                                
  
  for (auto el : v){
    cout << el << " " << endl;
  }
  cout << endl;

  for(auto elm : intersec){
    cout << elm << " " << endl; 
  }
  cout << endl;



 return 0;
}


bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
  std::vector<int> myvector (myints,myints+9);

  // using default comparison:
  std::vector<int>::iterator it;
  it = std::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                         //                ^

  myvector.resize( std::distance(myvector.begin(),it) ); // 10 20 30 20 10

  // using predicate comparison:
  std::unique (myvector.begin(), myvector.end(), myfunction);   // (no changes)