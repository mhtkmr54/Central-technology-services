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

deque<lli> convert(lli x) {
  deque<lli> ret;
  while(x) {
    if (x&1)
      ret.push_back(1);
    else
      ret.push_back(0);
    x>>=1;  
  }
  reverse(ret.begin(),ret.end());
  return ret;
}

lli getans(lli M, lli P){
	//cout << "ANS for " << M << " and " << P << endl;
    deque<lli> mM = convert(M);
    deque<lli> pP = convert(P); 
    if(mM.size() > pP.size()){
    	while (pP.size() != mM.size()){
    		//cout << "m>n" << endl;
    		pP.push_front(0);
    	}
    }
    if(mM.size() < pP.size()){
    	while (mM.size() != pP.size()){
    		//cout << "n > m" << endl;
    		mM.push_front(0);
    	}
    }
    lli diff = 0;
    for (lli k =0; k < mM.size(); k++){
    	if (mM[k] != pP[k]){
    		++diff;
    	}
    }
    //cout << diff << endl;
    return diff;
}

int main(){
	lli T;
	deque<lli> mine;
	cin >> T;
	while (T-- > 0){
		lli P;
		lli M;
		cin >> M >> P;
		mine.push_back(getans(M,P));
	}
	for (auto elem : mine){
		cout << elem << endl;
	}
	return 0;
}