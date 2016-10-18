#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<string,unsigned long int> my_map;
string s;
unsigned long int uli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for (int j =0; j<t; j++){
        cin >> s >> uli;
        my_map[s] = uli;
    }
    while (1){
        string query;
        cin >> query;
        if (query.empty()){
            break;
        }
        if (my_map.find(query) != my_map.end()){
            cout << query << "=" << my_map[query] << endl;
        }
        else{
            cout << "Not found" << endl;
        }
    }
    return 0;
}
