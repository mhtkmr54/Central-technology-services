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

typedef pair<int, int> pii;
typedef long long int;
const int MOD = 1000000009;

int main()
{
    int total_stacks;
    int queries;
  
     //for(i=2;i<=total_stacks;i++)
    //sort(my_deq[i].begin(),my_deq[i].end());

            //i=k;
            /*if(k!=1){
             //sort(my_deq[i].begin(),my_deq[i].end());
             ok=0;
             for(i=0i<[k].size();i++)
              if(my_deq[k][i]>=h){
                my_deq[k].insert(my_deq[k].begin()+i,h);
                ok=1;
                break;
              }
              if(ok==0)
              my_deq[k].push_back(h);
            }
            else{
                my_deq[k].push_back(h);
            }
            */

    cin >> total_stacks;
    deque <int> my_deq[total_stacks+2];
    int v,k,i,j;
    int x;
    int f=0,l;
    long height;
    cin>>l;
    i=1;
    if(l){
    	cin>>x;
    	my_deq[i].push_back(x);
    	for(j=1;j<l;j++){
    		cin>> height;
    		if( height <my_deq[1][j-1])
    		my_deq[i].push_back(height);
    		else
    		my_deq[i].push_back(my_deq[1][j-1]);
    	}
    }
    for(i=2; i<=total_stacks; i++){
    	cin>>l;
    	
    	for(j=1;j<=l;j++){
    		cin >> height;
    		my_deq[i].push_back(height);
    	}
    }
    	
    	cin>>queries;
    	while(queries--){
    		cin>>v;
    		if(v==0){
    			cin>>k;
    			if(!my_deq[k].empty())
    			my_deq[k].pop_back();
    		}else if(v==1){
    			cin >> k >> height;
    			if(k==1){
    				j=my_deq[k].size();
    				if(my_deq[k].size()==0||height<my_deq[1][j-1]){
                        my_deq[k].push_back(height);
                    }else{
                        my_deq[k].push_back(my_deq[1][j-1]);
                    } 
    			}
    			else{
    			
    				my_deq[k].push_back(height);
    				
    			}
    		}else{
    			
    				height =my_deq[1][my_deq[1].size()-1];
    				for(i=2; i <= total_stacks; i++){
    				k=lower_bound(my_deq[i].begin(),my_deq[i].end(),height+1)-my_deq[i].begin();
    				if(k==my_deq[i].size())
    				break;
    				height = my_deq[i][k];
    			//	f=1;
    				}
    				
    			if(i == total_stacks+1){
                   cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
    					
    		}
    		
    	}
    
    return 0;
}
