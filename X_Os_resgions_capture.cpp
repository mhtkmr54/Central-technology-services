void DFS_visit(int i, int j, int R, int C,vector<vector<char> > &A, deque < deque <int> >& vis, deque<pair<int,int> >& last, int& flag){
    vis[i][j] = 1;
    if ( i== 0 || j == 0 || i == R-1 || j == C-1){
       	         flag = 1;
       	        // cout << "flag 1";
       	    }
    last.push_back(make_pair(i,j));
    deque< pair<int, int> > dirs;
    dirs.push_back(pair<int,int>(i-1,j));
    dirs.push_back(pair<int,int>(i,j-1));
    dirs.push_back(pair<int,int>(i,j+1));
    dirs.push_back(pair<int,int>(i+1,j));
    for (int d =0; d < dirs.size(); d++){
       int l = dirs[d].first;
       int m = dirs[d].second;
       if (l >= 0 && m >= 0 && m < C && l < R){
       	   if (A[l][m] == 'O'  && vis[l][m] == 0){ 
       	      //cout << " |l " << l << " m " << m << "| ";
       	    if (l == 0 || m == 0 || l == R-1 || m == C-1){
       	         flag = 1;
       	         //cout << "flag 1";
       	    }
       	     DFS_visit(l,m,R,C,A,vis,last,flag);
       	   }

       }
    }
    //cout << "ret 0 " << " ";
	return;
}


void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int R = A.size();
    int C = A[0].size();
    if (R == 1 && C ==1 ){
        return;
    }
    deque < deque <int> > vis;
    vis.resize(R,deque<int>(C, 0));
    deque<pair<int,int> > last;
    //int count = 0;
     for (int i =0; i < R ; i++)
     { 
     for (int j =0; j < C; j++)
     {
        if (A[i][j] == 'O' and vis[i][j] == 0 ){
        	//count += 1;
        	int flag = 0;
        	DFS_visit(i,j,R,C,A,vis,last,flag);
          // cout << " |---------------------------recieved flag" << flag << "| ";
        	if (flag == 0){
        	    for(auto el : last){
        	        A[el.first][el.second] = 'X';
        	    }
        	}
        	last.clear();
        }
     }
     }
    // cout << count << endl;
    
}
