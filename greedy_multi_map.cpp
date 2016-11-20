int find_b(deque<pair <int,int> >& freq, int elem){
	int flag = 0;
	for(int i = 0; i < freq.size(); i++){
        if(freq[i].second == elem){
        	freq[i].first +=1 ;
        	//cout << "exis " << freq[i].first << endl;
        	flag =1;
        	break;
        }
	}
	return flag;
}


int Solution::majorityElement(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lm = A.size()/2;
     //priority_queue< pair<int,int>, vector<pair<int,int> >, std::function<bool(pair<int,int> a, pair<int,int> b)> > my_pq(Compare);
     map <int,int> freq;
     map <int,int> chk;
     for(int i = 0; i < A.size(); i++){
       if(chk[A[i]] != 0){
           freq.erase(chk[A[i]]);
           chk[A[i]] -= 1;
           freq[chk[A[i]]] = A[i];
       }else{
       	chk[A[i]] = -1;
       	freq[chk[A[i]]] = A[i];
       }
      
  }
  map<int,int>::iterator it;
  for (it = freq.begin(); it != freq.end(); ++it){
      if(abs(it->first) > lm){
          return it->second;
          break;
      }
  }
    
}
