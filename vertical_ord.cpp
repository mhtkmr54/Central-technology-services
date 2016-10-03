// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;
 
// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};
 
// A utility function to create a new node
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
map<int,deque<int> > hdmap;

void getVerticalOrder(Node* root, int hd)
{
   if (root == NULL){
    return;
   }
   cout << "vertical order "<<root << endl;
   hdmap[hd].push_back(root->key);
   getVerticalOrder(root->left, hd-1);
   getVerticalOrder(root->right, hd+1);
  
  return;

}
 
// The main function to print vertical oder of a binary tree
// with given root
void printVerticalOrder(Node* root)
{
   //cout << root->key << endl;
   cout << root << endl;
   getVerticalOrder(root, 0);
   for (auto el : hdmap){
    cout << el.first << " : ";
    for (auto e : el.second){
      cout << e << " ";
    }
    cout << endl;
   }
   return;
}
 
// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}