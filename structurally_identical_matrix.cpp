/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int cntMatrixUtil(TreeNode* A, TreeNode* B, int min,int max) {
        int inserts=-1;
        if(A!=NULL && B==NULL)
           return inserts;
        if(A!=NULL && B!=NULL)
          {
              inserts=0;
              
          }
         if(A==NULL && B ==NULL)
         {
             inserts=0;
             return inserts;
         }
         if(A==NULL && B!=NULL)
         
        {
             
            int mid=min+(max-min)/2;
            A = new TreeNode(mid);
            inserts=1;
        }
        int left=cntMatrixUtil(A->left,B->left,min,A->val);
        int right=cntMatrixUtil(A->right,B->right,A->val,max);
        if(left==-1 || right ==-1)
          return -1;
        return inserts+cntMatrixUtil(A->left,B->left,min,A->val)+cntMatrixUtil(A->right,B->right,A->val,max);
    }
 
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    return cntMatrixUtil(A,B,-99999,999999);
}
