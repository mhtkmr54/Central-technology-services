#include <iostream>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <sstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <locale>



using namespace std;
using namespace std;

int fib(int n)
{
  int f[n+1];
  int i;
  f[0] = 0;
  f[1] = 1;
  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];
  }
  return f[n];
}

int main()
{   int N, Q;
    cin >> N;
    deque < deque <int> > mat;
    mat.resize(N,deque<int>(N, 0));
    cin >> Q;
    while(Q-- >= 0){
     deque<string> result;
   	 //cout << "start of while loop" << endl;
   	 string str2;
     getline (cin,str2);
     istringstream iss(str2);
     for(string s; iss >> s; ){
     	result.push_back(s);
     } 	
     if (result.size() == 2){
      int to_disp = 0;
       for (int i = 1; i <= stoi(result[1]); i++){
     		to_disp += mat[i][i]; 
     	}
     	cout << to_disp << endl;
     }else{
       cout << " sdac" << result[1] << endl;
     	for (int i = stoi(result[1]); i < N+1; i++){
     		mat[i][i] = fib(i);
     	}
     }
    }
   	
    return 0;
}
