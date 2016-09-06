#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <iterator>

using namespace std;

deque<pair<int,string> >mydeque;
deque<pair<int,string> >sorted_mydeque;
pair<int,string> prs;
deque<pair<int,string> >ans_mydeque;
deque<pair<int,string> >::iterator it;
int total;
deque<int> buckets;
deque<int> min_max;
deque<int> sorted;
int range;



int findthispos(int v){
	int loop = 0;
	for (auto el : mydeque){
	 	if (el.first == v){
	 		return loop;
	 	}
	 	else{
	 	  loop++;
	 	}
    } 

}






void count_sort(){
 for (auto el : mydeque){
 	min_max.push_back(el.first);
 }   
 int max = *max_element(min_max.begin(), min_max.end());
 int min = *min_element(min_max.begin(), min_max.end());
 range = max - min + 1;
 buckets.resize(range,0);
 cout << "-------------------------------b4 sort" << endl;
 int looper = 0;
 for (auto el : mydeque){
 	if (looper < total/2){
 	 el.second = el.second + 'Z';
     mydeque[looper] = make_pair(el.first,el.second);
 	}
 	looper++;
 	cout << el.first << "  "<< el.second << endl;
 }  
// dump idea
 sorted_mydeque = mydeque;
 sort(sorted_mydeque.begin(),sorted_mydeque.end());
 cout << " SSSSORTWD  " << endl;
  for (auto el : mydeque){
 	cout << el.first << "  "<< el.second << endl;
 }  
// dump idea
/* for (auto el : min_max){
 	buckets[el - min] += 1;
 }
 for (int l = 0; l < range; l++){
 	for (int j = 0 ; j < buckets[l]  ; j++)
 	sorted.push_back(j);
 }
 cout << "sorted ?? ------------------------" << endl;
 for (auto el : sorted){
 	cout << el << "  " << endl;
 } */

int counter = 0;

 while(counter < total){
 	int to_find = sorted_mydeque[0].first;
 	cout << "to find  " << to_find << endl;
 	sorted_mydeque.pop_front();
    int dist = findthispos(to_find);
    it = mydeque.begin()+dist;
    cout << "FOUND  " << it->first << " " << it->second << endl;

    ans_mydeque.push_back(make_pair(it->first,it->second));
    //cout << "FOUND  and NOW ERASING   " << it->first << " " << it->second << endl;
    mydeque.erase(it);
    counter++;
 }
 cout << "==========================+ANS=================================" << endl;
  for (auto el : ans_mydeque){
  	string Z;
  	if (el.second.back() == 'Z' ){
  		cout << "  "<< "-";
  	}
  	else{
  		cout  << "  "<< el.second;
  	}
 	
 }
 cout << endl;

}






int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    cin >> total;
    int f;
    string s;
    for (int k =0; k < total; k++){
    	cin >> f >> s;
    	mydeque.push_back(make_pair(f ,s));
    }
    count_sort();
    return 0;
}
