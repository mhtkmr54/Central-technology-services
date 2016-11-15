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

struct rod{
	int in;
	int ou;
	int price;

};

bool compare(rod a, rod b){
    return  a.price <  b.price;
}

int main(){
	int T;
	cin >> T;
	while (T-- > 0){
		int N;
		int M;
		int L;
		cin >> N >> M >> L;
		deque<rod> mi;
		for(int l =0; l<N; l++){
			rod el;
			int i,o,p;
			cin >> i >> o >> p;
			el.in = i;
			el.ou = o;
			el.price = p;
			mi.push_back(el);
		}
		sort(mi.begin(),mi.end(), compare);
		int nu = mi.size();
		int i = 0;
		int flag = 0;
		while(nu-- > 0){
			if(mi[i].in < L && L < mi[i].ou){
				cout << mi[i].price << endl;
				flag = 1;
				break;
			}
            i++;

		}
		  if (flag == 0){
		  	for(int i = 0; i < mi.size(); i++){
		  		for(int j = i+1; j < mi.size(); j++){
					if((mi[i].in + mi[j].in) < L && L < (mi[i].ou + mi[j].ou)){
						cout << mi[i].price + mi[i].price << endl;
						flag = 1;
						break;
					}		  			
                    
		  		}
              }
		  	}
	}

	return 0;
}