#include <iterator>
#include <string>
#include <sstream>
#include <functional>
#include <iostream>
#include <map>


using namespace std;
map<int,int> memo;

int solve(int m){
	//cout << m << endl;
	if(memo.find(m) != memo.end()){
		//cout << "ret" << endl;
		return memo[m];
	}
	if(m == 4){
		//cout << "rett 4 rea" << endl;
		return 0;
	}
	if (m % 2 == 0 && m > 4){
		return  memo[m] = min(1+solve(m-1), 1+solve(m/2));
    }
	if (m % 2 != 0 && m > 4){
		return memo[m] = 1+solve(m-1);
	}
	
}

int main(){
	cout << solve(6) << endl;
	return 0;
}