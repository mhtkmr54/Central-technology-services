#include<stdio.h>
 
/* The function assumes that there are at least two
   elements in array.
   The function returns a negative value if the array is
   sorted in decreasing order.
   Returns 0 if elements are equal  */
int maxDiff(int arr[], int arr_size)
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
  return max_diff;
}    
 
/* Driver program to test above function */
int main()
{
  int arr[] = {1, 2, 6, 80, 100};
  //2 3 10 6 4 8 1
  int arr1[] = {2,3,10,6,4,8,1};
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("Maximum difference is %d",  maxDiff(arr1, 7));
  getchar();
  return 0;
}