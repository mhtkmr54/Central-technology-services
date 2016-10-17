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
vector< vector<string> > mas;
deque<string> res;
deque<string> res2;
deque<int> poss;
/*void toupper(string& s){
	for(int i = 0; i < strlen(s); i++)
       s[i] = toupper(s[i]);
  return;


  inserting string at index 6
  str.insert(6,str2);
}*/

//reverse(s.begin(),s.end())
void executive_decision(deque<string>& result, string& sas){
	int j = result.size()-2;
    while (j >= 0 ){
    	cout << "examining " << result[j] << " j " << j << endl;
    	if (result[j] == "print"){
    	}
        if (result[j] == "toupper"){
        	cout << "uppering" << endl;
        	for(int i = 0; i < sas.length(); i++){
        		sas[i] = toupper(sas[i]);
        	}
        }
        if (result[j] == "append"){
        	sas += "a";
        }
        if (result[j] == "reverse"){
        	reverse(sas.begin(),sas.end());
        }
        j = j -1;
    }
  cout << sas << endl;
  return;	
}








/* 
string str = "102:330:3133:76531:451:000:12:44412";
for (int i=0; i<str.length(); i++)
{
    if (str[i] == ':')
        str[i] = ' ';
}


*/
int main (){
   string strg;
   while (strg != "end"){
   	 cin >> strg;
   	 istringstream iss(strg);
   	vector<string> tokens;
		copy(istream_iterator<string>(iss),
		     istream_iterator<string>(),
		     back_inserter(tokens));
     mas.push_back(tokens);
   }
   
   int i = 0;
   for (auto el : mas)
   {
   	     for (auto e : el)
		   {

		   	  cout << e << " ";
              
		   	  res.push_back(e);
              i = i++;
		   }
		   cout << res.size() << endl;
   }
   i = 0;
   int count = 0;
   for (auto el : res){
     if (el == "str"){
       poss.push_back(i);
       count++;
     }     
   i++;
   }
   cout << "count" <<  count << endl;
   int k = 0;
   while (count-- >= 0){
   	deque<string> result;
   	cout << "start of while loop" << endl;
   	string str2;
   	getline (cin,str2);
     istringstream iss(str2);
     for(string s; iss >> s; ){
     	result.push_back(s);
     } 
     cout << "result.size() " << result.size() << endl;
     if (k != 0 ){
     string sas = result.back();
     executive_decision(result,sas);
     }
     k++;
   }
	return 0;
}

