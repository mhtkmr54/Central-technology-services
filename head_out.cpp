/*
 * Complete the function below.
 */
deque < deque <int> > vis;
int R;
int C;

int visit1(vector < vector < int > > board, int i,int j){
     if (i == R-1){
      return board[i][j];
     }    
      int el = board[i][j];
      return max(( el + visit1(board,i+1,j)),  (el + visit1(board,i+1,j+1)), (el + visit1(board,i+1,j-1))); 
}



int maxPathSum(vector < vector < int > > board, int p, int q) {
    R = board.size();
    C = board[0].size();
    int ans = max(visit1(board,0,p,board[0][p]),);
    
}

