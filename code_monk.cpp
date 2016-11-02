#include <iostream>
#include <cstdlib>
#include <deque>
#include <map>
#include <set>
#include <iterator>

using namespace std;

int maxDiff(deque<int> arr, int arr_size)
{
  int max_diff = arr[1] - arr[0];
  int min_element = arr[0];
  int i;
  for(i = 1; i < arr_size; i++)
  {       
    if (arr[i] - min_element > max_diff)                               
      max_diff = arr[i] - min_element;
    if (arr[i] < min_element)
         min_element = arr[i];                     
  }
/*  if (max_diff = 0 || max_diff < 0){
    max_diff = -1;
  }*/
  return max_diff;
}   

int main()
{
	int cases;
	cin >> cases;
  deque<int> ans;;
	while(cases--){
	  int T;
    cin >> T;
    map<int,int> my_map;
    for (int i =0; i< T; i++){
    	int a;
    	cin >> a;
    	//cout << a << endl;
    	if (my_map.find(a) != my_map.end()){
    		my_map[a] += 1;
    	}
    	else{
    		my_map[a] =1;
    	}
    }
    deque<int> my_deq;
    for(auto el : my_map){
    	//cout << el.first << " : " << el.second << endl;
    	my_deq.push_back(el.second);
    }
    int elem;
    if (my_deq.size() > 1){
      elem = maxDiff(my_deq,my_deq.size());
      ans.push_back(elem);
    }
    else{
      ans.push_back(-1);
    }
    //cout << "elem " <<  elem << endl;
    	
	}
  cout << endl;
  for (auto el : ans){
    cout << el << endl;
  }
  return 0;
}
