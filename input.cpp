#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string temp;
    getline(cin, temp);
    int N = stoi(temp);
    map<string, string> phoneList;
    for(int n = 0; n < N; n++){
        string line;
        getline(cin, line);
        vector<string> result;
        istringstream iss(line);
        for(string s; iss >> line; )
            result.push_back(line);
        string name = result.at(0);
        string number = result.at(1);
        //cout << "name " << name << endl;
        //cout << "number " << number << endl;
        //for (auto i = result.begin(); i != result.end(); ++i)
           // cout << *i << ' ' << endl;
        phoneList.insert(std::pair<string, string>(name, number));
        //cout << "for loop end \n" ;
    }
    string name;
    while(getline(cin, name))
    {
        std::map<string, string>::iterator it;
        it = phoneList.find(name);
        if (it == phoneList.end()){
            cout << "Not found" << endl;
        } else {
            cout << name << "=" << it->second << endl;
        }
    }

    return 0;
}
