#include <cstdio>
#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> newtest;
deque<int> test;
deque<int>::iterator it;

void mergesrt(deque<int>& mydeq){
   if (mydeq.size() > 1){
   	int mid = mydeq.size()/2;
   	deque<int> lefthalf(mydeq.begin(), mydeq.begin() + mid);
   	deque<int> righthalf(mydeq.begin() + mid, mydeq.begin() + mydeq.size());
   	mergesrt(lefthalf);
   	mergesrt(righthalf);
   	int i = 0;
   	int j = 0;
   	int k = 0;

    while (i < lefthalf.size() && j < righthalf.size()){
         if (lefthalf[i] < righthalf[j]){
                mydeq[k] = lefthalf[i];
                k++;
                i++;
         }
         else{
         	   mydeq[k] = righthalf[j];
               k++;
               j++;
         }
    }

    while (i < lefthalf.size()){
                mydeq[k] = lefthalf[i];
                k++;
                i++;
    }

    while (j < righthalf.size()){
                mydeq[k] = righthalf[j];
                k++;
                j++;
    }

   }

   return;
}

int main(){

	test = {12, 11, 13, 5, 6};
	//insertsrt();
	mergesrt(test);
	newtest.resize(test.size(),0);
	cout << "ans" << endl;
	for (auto el : test){
		cout << el << " ";
	}
	cout << endl;
    return 0;


}