#include <iostream>
#include <cstring>
#include <string>

using namespace std;
char mini;
int indexh = 0;
int indexl = 0;
int flag = 0;

void lexgreat(char *arr){
   for (int i = 0; i < strlen(arr); i++){
     if (arr[i] >= arr[i+1] && flag == 0){
      indexl = i; 
      flag = 1;
      mini =  arr[indexl];
     }
     if (i > indexl && arr[i] <= mini){
     	mini = arr[i];
     	indexh = i;
     }

   }
   return;
}


int main(){
	int hindex; 
	int lindex;
	char arr[] = "babaabba";
	int sizea = strlen(arr);
	lexgreat(arr);
	cout << indexl << ","<< indexh << endl;
	return 0;
}