// A function to find k'th largest element in a given tree.
void kthLargestUtil(Node *root, int k, int &c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= k)
        return;
 
    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);
 
    // Increment count of visited nodes
    c++;
 
    // If c becomes k now, then this is the k'th largest 
    if (c == k)
    {
        cout << "K'th largest element is "
             << root->key << endl;
        return;
    }
 
    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}
 
// Function to find k'th largest element
void kthLargest(Node *root, int k)
{
    // Initialize count of nodes visited as 0
    int c = 0;
 
    // Note that c is passed by reference
    kthLargestUtil(root, k, c);
}