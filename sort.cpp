#include <cstdio>
#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

//http://placement.freshersworld.com/oracle-placement-papers/aptitude-english/3313936

deque<int> test;
deque<int>::iterator it;

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

void selectsrt(){
    for (int i = 0; i < test.size()-1; i++)
    {
     int min_indx = i;
     for (int j = i+1; j < test.size(); j++)
     {
        if (test[j] < test[min_indx]){
        	min_indx = j;
        }
       	swap(test[min_indx],test[i]);
     }	  
    }
	return;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int main(){

	test = {12, 11, 13, 5, 6};
	//insertsrt();
	//quicksrt(0,4);
	selectsrt();
	cout << "ens" << endl;
	for (auto el : test){
		cout << el << " ";
	}
	cout << endl;
    return 0;
}