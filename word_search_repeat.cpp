#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std; 



bool isWord(string &str, string B)
{
    // Linearly search all words 
    if (str == B){
       // cout << " si ";
      return true;
    }          
    return false;
}


// A recursive function to print all words present on boggle
void findWordsUtil(vector<string> &A, deque< deque<bool> >& visited, int i,
                   int j, string &B,  int k, int& flag, int M, int N, string& str)
{
    //visited[i][j] = true;

   cout << "curr" << i << " " << j <<  " at " << k << " " << str << "| " <<  endl;
    str = str + A[i][j];
    cout << "====================================================================" << "GOT" << str << endl;
    if (isWord(str,B)){
       cout << " si ";
      flag = 1;
      return;
    }
    //cout << "making pairs " << endl; 
    deque< pair<int, int> > dirs;
    dirs.push_back(pair<int,int>(i-1,j));
    dirs.push_back(pair<int,int>(i,j-1));
    dirs.push_back(pair<int,int>(i,j+1));
    dirs.push_back(pair<int,int>(i+1,j));
    cout << "dir siz" << dirs.size() << endl;
    int ct = 0;
    for (int d =0; d < dirs.size(); d++){
         cout << "ct" << " " << ct << endl;
         int l = dirs[d].first;
         int m = dirs[d].second;
        cout << "checking" << l  << " " << m << " " << M << " " << N << endl;
        if (l>=0 && m>=0 && !visited[l][m] && l < M && m < N ){
          //cout << "selected partial" << endl;
          if (B[k+1] == A[l][m]){
           // cout << "ORIG " << B << " K+1 " << k+1 << endl;
            cout << "|goin " << l << " " << m << " " << "{" << str << "}" << " | as " << B[k+1] << " = " << A[l][m]  << endl;
            k += 1;
           return findWordsUtil(A, visited, l, m, B, k, flag, M, N,str);
          }
        }
        ++ct;
    }
    return;
}



int Solution(vector<string> &A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  // cout << "==========================";
    int M = A.size();
    int N = A[0].length();
    //bool visited[M][N] = {{false}};
    deque< deque<bool> > visited;
    visited.resize(M,deque<bool>(N,false));
    
    // Initialize current string
    string str = "";

    // Consider every character and look for all words
    // starting with this character
    int flag = 0;
    for (int i=0; i<M; i++)
       for (int j=0; j<N; j++)
             if (A[i][j] == B[0]){
             // cout << "STR " << str << endl;
              findWordsUtil(A, visited, i, j, B,0,flag, M, N,str);
              str  = "";
              visited.clear();
              visited.resize(M,deque<bool>(N,false));
             }
   // cout << "flag " << flag;
  return flag;  
}

int main(){
  vector<string> A;
  int T;
  cin >> T;
  while(T-- > 0){
    string el;
    cin >> el;
    A.push_back(el);
  }
  string B;
  cin >> B;
  cout << "ANS " << Solution(A,B) << endl;
  return 0;
}