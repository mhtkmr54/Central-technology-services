#include<stdio.h>
#include <iostream>

using namespace std;
#define ROW 4
#define COL 4
int M[ROW][COL] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
main()
{
    int i, j, t;
    for (i = 0; i < 4; i++)
    {
        for(j = i; j < 4; j++){
     t = M[i][j];
     M[i][j] = M[j][i];
     M[j][i] = t;
}
    }
    for (i = 0; i < 4; ++i)
   { printf("\n");
        for (j = 0; j < 4; ++j)
            printf ("%d\t", M[i][j]);
   }
}