int fun(struct node *root)
{
   if (root == NULL)
      return 0;
   if (root->left == NULL && root->right == NULL)
      return 0;
   return 1 + fun(root->left) + fun(root->right);
}