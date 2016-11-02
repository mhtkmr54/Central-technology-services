#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <iterator>
#include <string>
#include <initializer_list>

using namespace std;;

typedef long long int lli;
deque<lli> my_deq;
int ith;

int chunk(lli element){
  //cout << "welcone element we test is " << element << endl;
	string whole = to_string(element);
	int l = whole.size();
	int start = l - (5*ith);
	int end = l - (1 + (5*(ith-1)));
  //cout << start << " till " << end << endl;
	string answer;
	int ans;
    if (start < 0 && end < 0){
      return 0;
    }else if (start < 0 && end >= 0){
        answer = whole.substr(0,end-0+1);
    }
    else if (start >= 0 && end > 0){
    //  cout << "uncase " << endl;
    	answer = whole.substr(start,end-start+1);
      //cout << "read  gotcha " << endl;
    }
    else{
      answer = "0";
    }
    ans = stoi(answer);
    //cout << "chunk " << ans << " of element " << element << endl; 
	return ans;
}

void merge_sort(deque<lli>& my_deq){
/*  cout << " ith " << ith << endl;
  if (ith == 3){
    for (auto el : my_deq){
      cout << el << " ";
    }
    //cout << endl;
  }*/
   if (my_deq.size() > 1){
   	int mid = my_deq.size()/2;
   	deque<lli> lefthalf(my_deq.begin(), my_deq.begin() + mid);
   	deque<lli> righthalf(my_deq.begin() + mid, my_deq.begin() + my_deq.size());
   	merge_sort(lefthalf);
   	merge_sort(righthalf);
   	int i = 0;
   	int j = 0;
   	int k = 0;

    while (i < lefthalf.size() && j < righthalf.size()){
         if (chunk(lefthalf[i]) <= chunk(righthalf[j])){
                my_deq[k] = lefthalf[i];
                k++;
                i++;
         }
         else{
         	   my_deq[k] = righthalf[j];
               k++;
               j++;
         }
    }

    while (i < lefthalf.size()){
                my_deq[k] = lefthalf[i];
                k++;
                i++;
    }

    while (j < righthalf.size()){
                my_deq[k] = righthalf[j];
                k++;
                j++;
    }

   }

   return;
}

int main()
{
	int T;
    cin >> T;
    deque<lli> test;
    for (int k =0; k < T; k++)
    {
      //cout << "sDA " << endl;
       lli el; 
       cin >> el;
       ith = 1;
       my_deq.push_back(el);
    }
    while (ith != -666){
        test = my_deq;
        int iter = 0;
        
        for (auto el : my_deq){
        //cout << el << " --|-- " ;
        if (chunk(el) == 0){
          ++iter;
        }
       }
       /*cout << "------------------------------" << endl;  
       cout << endl;*/
       if (iter == my_deq.size()){
        ith = -666;
        break;
       }

       merge_sort(my_deq);
      for (auto el : my_deq){
        cout << el << " ";
       }
       cout << endl;
        ++ith;
       }

}
