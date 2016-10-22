#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <iterator>
#include <deque>

using namespace std;

int rows;
int columns;
int starti;
int startj;

int main(){
/*	cin >> rows;
	cin >> columns;
	deque <deque<char> > arr;
	arr.resize(rows,deque<char>(columns, '0'));
	for (int i =0; i < rows ; i++)
	  {
	     for (int j =0; j < columns; j++)
	     {
	        cin >> arr[i][j];
	        if (arr[i][j] == 'M'){
	          starti = i;
	          startj = j;
	        }

	     }
	     cout << endl; 
	  }


  for (int i =0; i < rows ; i++)
       {
        for (int j =0; j < columns; j++)
         {
            cout << arr[i][j] << " " ;
         }
         cout << endl;
       }*/
    int a = 0;
    int b = 0;
    int k = a++ + 99;
    k = a + 99;
    cout << k << ++b << endl;
    cout << a << b << endl;
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    FILE *fp = fopen("test.txt", "wx");
    if (fp == NULL)
    {
        puts("Couldn't open file or file already exists");
        exit(0);
    }
    else
    {
        fputs("GeeksforGeeks", fp);
        puts("Done");
        fclose(fp);
    }
    return 0;
}