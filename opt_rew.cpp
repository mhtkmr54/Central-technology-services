#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <map>


using namespace std;
 
// A structure to represent a job
struct Job
{
   int mtime;      // Job Id
   int dead;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};
 
// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
     if (a.profit == b.profit && a.dead > b.dead){
      //return a.mtime < b.mtime;
      return a.dead < b.dead;
     }
     else{
      return a.profit > b.profit;
     }
     
}
 
// Returns minimum number of platforms reqquired
void JobScheduling(deque<Job>& arr)
{

    // Sort all jobs according to decreasing order of prfit
   int n = arr.size();
    sort(arr.begin(), arr.end(), comparison);

    for (auto el : arr){
      cout << el.profit << " " << el.dead << endl;
    }

   // STEPS
    // get max Deadline value
    //say dmax = 3
    // ------------------------------------------
    // -                                        -
    // -                                        -
    // ------------------------------------------
 
   cout << endl;
    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots
 
    // Initialize all slots to be free
    for (int i=0; i<n; i++){
      slot[i] = false;
    }
        
 
    // Iterate through all given jobs
    for (int i=0; i<n; i++)
    {
       // Find a free slot for this job (Note that we start
       // from the last possible slot)
       for (int j=min(n, arr[i].dead)-1; j>=0; j--)
       {
          // Free slot found
          if (slot[j]==false)
          {
             result[j] = i;  // Add this job to result
             slot[j] = true; // Make this slot occupied
             break;
          }
       }
    }
 
    // Print the result
    for (int i=0; i<n; i++){
      if (slot[i]){
        cout << arr[result[i]].profit << " ";
          }
       } 
}




// Driver program to test methods
int main()
{

   deque<Job> arr = { {1, 5, 100}, {1, 6, 19}, {1, 10, 27},
                   {1, 50, 25}, {1, 10, 15}};
  /*  int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);*/
/*    int N;
    cin >> N;
    deque<Job> arr;
    while(N-- > 0){
      Job a;
      cin >> a.dead >> a.profit >> a.mtime;
      arr.push_back(a);
    }*/
    JobScheduling(arr);
   
    
    return 0;
}