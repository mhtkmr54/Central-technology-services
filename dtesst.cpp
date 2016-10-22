#include <cstdio>
#include <iostream>

using namespace std;

int main (){

  int a = 5;
  int b = -2;
  cout << a%b; 
  int arr[4] = {1,2,3}; //4
  char arr1[3] = "abc"; //4
  char arr2[3] = {'a','b','c'};//3
  cout << endl;
  cout << " sizeof(arr)" << sizeof(arr) << "arr[4] -> " << arr[4]  << "       sizeof(arr1) " << sizeof(arr1) << " sizeof(&arr1)&arr1 " << sizeof(&arr1)<< " " << &arr1  << sizeof(arr2) << endl; 
  return 0;
}
