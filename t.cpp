#include <stdio.h>

int main(){
	int *p  = (int *)20;
	int *q  = (int *)30;
    printf("%d\n", q - p);
}