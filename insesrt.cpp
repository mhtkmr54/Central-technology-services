#include <cstdio>
#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> test;


void insertsrt(){
	for (int i = 1; i < test.size(); i++){
		int key = test[i];
		int j  = i - 1;
		while ( j >= 0 && test[j] > key)
		{
			test[j+1] = test[j];
			j--;
		}
        test[j+1] = key;
	}
	return;
}

int qpartition(int l, int h){
	int pInd = l;
	int i = l;
	int pivot = test[h];
	cout << "pivot" << pivot << endl;
	for (i ; i <= h-1; i++){
		if(test[i] <= pivot){
			swap(test[pInd],test[i]);
			pInd++;
		}
	}
	swap(test[pInd],test[h]);
    for (auto el : test){
		cout << el << " ";
	}
	cout << endl;
	cout << "--------------------------" << endl;
    return pInd;
}

void quicksrt(int low,int high){
	if (low < high){
		int pIndex;
		pIndex = qpartition(low,high);
		quicksrt(low,pIndex-1);
		quicksrt(pIndex+1,high);
	}
	return;
}


int main(){

	test = {12, 11, 13, 5, 6};
	//insertsrt();
	quicksrt(0,4);
	cout << "ens" << endl;
	for (auto el : test){
		cout << el << " ";
	}
	cout << endl;
    return 0;
}