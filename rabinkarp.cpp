#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

#define totalchars 256;
// could have used strlen()
void rabin_karp_search(char arr[], char patt[], int prime){
    int arrsize = strlen(arr);
    int pattsize = strlen(patt);
    int hash_patt = 0;
    int hash_roll = 0;
    //int h = pow(totalchars,pattsize-1)%prime;

    //initial hash
    for (int i = 0; i < pattsize; i++){
    	hash_patt = hash_patt +  patt[i]*pow(prime,i);
    	hash_roll = hash_roll +  arr[i]*pow(prime,i);
    }
    
    for (int j = 0; j <= (arrsize - pattsize); j++){
    	
    	cout << "hash patt   " <<  hash_patt << endl;
    	cout << "hash roll   " << hash_roll << endl;
        cout << "j   " << j << endl;
    	if (hash_patt == hash_roll){
    		int k; 
            for (k = 0; k < pattsize; k++)
            {
                if (arr[j+k] != patt[k])
                    break;
            }
            if (k == pattsize){
            	cout << "///////////////////////////////////////////found at " << j << " " << endl;
    	    }
        }

    	if (j < (arrsize - pattsize)){
    		cout << hash_roll << " - " << arr[j] << " " << hash_roll - arr[j] << " " << endl;
    		hash_roll = (hash_roll - arr[j])/prime + arr[j+pattsize]*pow(prime,pattsize-1);
    	}
            
    }
	return;
}








int main(){
    char arr[] = "GEErKS FOR GEEKS"; 
    char patt[] = "GEEK";
    rabin_karp_search(arr,patt,101); 
	return 0;
}

