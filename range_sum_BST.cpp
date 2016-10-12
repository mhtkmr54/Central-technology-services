int getSum(node *root, int L, int H)
{
   // Base Case
   if (root == NULL)
      return 0;

   if (root->key < L)        
       return getSum(root->right, L, H);

  if (root->key > H)
      return getSum(root->left, L, H)

   if (root->key >= L && root->key <=H)        
      return getSum(root->left, L, H) + root->key +
             getSum(root->right, L, H);
}