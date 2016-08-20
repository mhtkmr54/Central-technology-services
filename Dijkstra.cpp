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

using namespace std;

int main(){
  int testcase;
  cin >> testcase;
  map < int, vector<pair<int,int> > > mymapofvec;
  for (int j=0 ; j < testcase; j++)
  {
    int f,s,dist;
    cin >> f >> s >> dist;
    vector<pair<int,int> > temp;
    temp.push_back(make_pair(dist,s));
    mymapofvec[f].push_back(temp);
    delete temp;
  }

  for (auto elem : mymapofvec)
  {
    cout << elem.first << " " endl;
    for (auto el : elem.second)
    {
        cout << el.first << " " << el.second << " " << endl;
    }
  }

  return 0;
}

