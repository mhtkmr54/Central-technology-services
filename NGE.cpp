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

using namespace std;
typedef long long int lli;
map<char,int>::iterator it;

// O(N)
void printNGE(int arr[], int n)
{
    int i = 0;
    struct stack s;
    s.top = -1;
    int element, next;
 
    /* push the first element to stack */
    push(&s, arr[0]);
 
    // iterate for rest of the elements
    for (i=1; i<n; i++)
    {
        next = arr[i];
 
        if (isEmpty(&s) == false)
        {
            // if stack is not empty, then pop an element from stack
            element = pop(&s);
 
            /* If the popped element is smaller than next, then
                a) print the pair
                b) keep popping while elements are smaller and
                stack is not empty */
            while (element < next)
            {
                printf("\n %d --> %d", element, next);
                if(isEmpty(&s) == true)
                   break;
                element = pop(&s);
            }
 
            /* If element is greater than next, then push
               the element back */
            if (element > next)
                push(&s, element);
        }
 
        /* push next to stack so that we can find
           next greater for it */
        push(&s, next);
    }
 
    /* After iterating over the loop, the remaining
       elements in stack do not have the next greater
       element, so print -1 for them */
    while (isEmpty(&s) == false)
    {
        element = pop(&s);
        next = -1;
        printf("\n %d -- %d", element, next);
    }
}

int main(){
	int T;
	cin >> T;
	deque<int> mine;
	deque<int>::iterator it;
	while (T-- > 0){
		int el;
		cin >> el;
		mine.push_back(el);		
	}
   deque<int> xx;
   deque<int> yy;
   for(int i = 0; i < mine.size()-1; i++){
      int el = *max_element(mine.begin()+i+1, mine.end());
      it = max_element(mine.begin()+i+1, mine.end());
      cout << "currently at " << i << endl;
      int e = it - mine.begin() + 1;
      cout << it - mine.begin() <<  " pos "<<endl;
      cout << el << " max_el" << endl;
      cout << endl;
      if(mine[i] < el){
         xx.push_back(e);
      }else{
      	xx.push_back(-1);
      }
   }
   xx.push_back(-1);
    for(int i = mine.size()-1; i > 0; i--){
      int el = *max_element(mine.begin(), mine.begin()+mine.size()-1);
      it = max_element(mine.begin(), mine.begin()+mine.size()-1);
      cout << "currently at " << i << endl;
      int e = it - mine.begin() + 1;
      cout << it - mine.begin() <<  " pos "<<endl;
      cout << el << " max_el" << endl;
      cout << endl;
      if(mine[i] < el){
         yy.push_front(e);
      }else{
      	yy.push_front(-1);
      }
   }
   yy.push_front(-1);
   
	return 0;
}