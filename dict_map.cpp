#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int len;
    string gene;
    cin >> len >> gene;
    int wanted = len/4;
    map<char,int> dict;
    map<char,int> dictm;
    vector<pair<char,int>> myvect;
    dict['A'] = 0;
    dict['C'] = 0;
    dict['T'] = 0;
    dict['G'] = 0;
   
    for (int j=0; j < len; j++ )
    {
       dict[gene[j]] ++;
    }
    for(auto elem : dict)
    {
       cout << elem.first << " " << elem.second << " " <<  "\n";
       myvect.push_back(elem);
    }
    sort(myvect.begin(),myvect.end(),compare);
    cout << myvect.size();
    for(int c = 0; c < myvect.size(); c++)
        {
             cout << myvect[c].first << ", " << myvect[c].second << endl;
        }
    for (int m =0; m < len; m++)
    {
       dictm.insert( pair <char,int> (myvect[m].first,myvect[m].second));
    }
    
    for(auto el : dictm)
    {
       cout << el.first << " " << el.second << " " <<  "\n";
       //myvect.push_back(elem);
    }
    return 0;
}

