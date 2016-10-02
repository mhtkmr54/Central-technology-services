#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>
#include <string>
#include <sstream>


using namespace std;



class Job{
 public:
	int timestamp = 0;
	int id = 0;
	string orig = " ";
	string instruct = " ";
	int importance = 0;
	int duration = 0;
	Job(int one, int two, string three, string four, int five, int six){
		timestamp = one;
		id = two;
		orig = three;
		instruct = four;
		importance = five;
		duration = six;
	}

};


class DIR{
 public:
 	 int size;
 	 deque<pair<int,int> >mydeque;
     DIR(int d)
     {
       size=d;
       deque<pair<int,int> > slots;
       slots.resize(size, pair<int,int>(0,0));
     }
};

deque<Job*> job_queue;

void insertion(Job* job1){
  if (job_queue.size() == 0){
   job_queue.push_back(job1);
  }
  else{
    int pos = 0;
    for (auto el : job_queue){
      
      pos++;
    }
  }
}

void executive_decision(deque<string>& result, string& sas){
    	 if (sas == "cpus"){
        cout << "assigning cpu size " << endl;
    		int z = stoi(result[1]); 
	     	DIR *mydir = new DIR(z);  	
        cout << mydir->size << " " << endl;
    	  } 
          if ( sas == "job"){
            Job* job1 = new Job(stoi(result[1]),stoi(result[2]),result[3],result[4],stoi(result[5]),stoi(result[6]));
            insertion(job1);
          }
          if (sas == "assign"){
          	cout << "to be assign" << endl;

          }
            
          if (sas == "query"){
          	cout << "querry Huh ?" << endl;   
          } 
  return;	
}



int main(){
   while (1){
   	deque<string> result;
   	string str2;
   	getline (cin,str2);
   	if (str2 == " " | str2 == ""){
   		break;
   	}
    istringstream iss(str2);
     for(string s; iss >> s; ){
     	result.push_back(s);
     } 
     string sas = result.front();
     executive_decision(result,sas);
   }
   cout << " job queue size " << job_queue.size() << endl;
	return 0;
}