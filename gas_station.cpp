#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef pair<int,int> pii;


int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  
        // Consider first petrol pump as a starting point
    int start = 0;
    int end =  1;
 
    int curr_petrol = gas[start] - cost[start];
    cout << "FIST CUR petrol " << curr_petrol << endl; 
    int n = gas.size();
    if (n==1){
        return 0;
    }
    /* Run a loop while all petrol pumps are not visited.
      And we have reached first petrol pump again with 0 or more petrol */
    while (end != start || curr_petrol < 0)
    {
        // If curremt amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while (curr_petrol < 0 && start != end)
        {
            // Remove starting petrol pump. Change start
            curr_petrol -= gas[start] - cost[start];
            cout << "changing start FROM  " << start << endl;
            start = (start + 1)%n;
            cout << "changing it to ->  " << start << endl;
            // If 0 is being considered as start again, then there is no
            // possible solution
            if (start == 0){
                return -1;
            }
               
        }
 
        // Add a petrol pump to current tour
        curr_petrol += gas[end] - cost[end];
        cout << "curr petro " <<curr_petrol << endl;
        
 
        end = (end + 1)%n;
    }
 
    // Return starting point
    return start;
    
}

int main(){
    
    vector<int> gas;
    vector<int> cost;
    gas = {959, 329, 987, 951, 942, 410, 282, 376, 581, 507, 546, 299, 564, 114, 474, 163, 953, 481, 337, 395, 679, 21, 335, 846, 878, 961, 663, 413, 610, 937, 32, 831, 239, 899, 659, 718, 738, 7, 209};
    cost ={862, 783, 134, 441, 177, 416, 329, 43, 997, 920, 289, 117, 573, 672, 574, 797, 512, 887, 571, 657, 420, 686, 411, 817, 185, 326, 891, 122, 496, 905, 910, 810, 226, 462, 759, 637, 517, 237, 884};
    cout <<  "ANS  "<<canCompleteCircuit(gas,cost) << endl;
    return 0;
}