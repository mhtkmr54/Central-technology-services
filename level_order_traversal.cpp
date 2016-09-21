#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>
#include <deque>

using namespace std;
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
      Node* root;
      Solution(){
       root = NULL; 
      } 
      void insert(int key) //can also say addleaf coz you add leaf bi
      {
        AddLeafPrivate(key, root);
      }

      void AddLeafPrivate(int key, Node* Ptr)
      {
        if(root == NULL){
         root = new Node(key);
        }
        else if (key < Ptr->data){
          if(Ptr->left != NULL){
            AddLeafPrivate(key, Ptr->left);
          }
          else {
            Ptr->left = new Node(key);
          }

        }
        else if (key > Ptr->data){
          if(Ptr->right != NULL){
            AddLeafPrivate(key, Ptr->right);
          }
          else
          {
            Ptr->right =  new Node(key);
          }

        }
        else
        {
          cout<<"The Key  "<< key << "is already added";
        }
      }

     int Getheight(Node* root){
       if(root != NULL){
        int a  = Getheight(root->left);
        int b = Getheight(root->right);
        return max(a+1,b+1);
      }else{
       return 0;
      }
     };

     void Printlevel(Node* root,int level){
      if (root == NULL){
        return;
      }
      if (level == 1){
        cout << " " << root->data << " ";
        } 
      else{
        Printlevel(root->left, level-1);
        Printlevel(root->right, level-1);
      }
     };



      void levelOrder(){
             int height = Getheight(root);
             int k = 1;
             while (k <= height + 1){
              cout << "AT LEVEL -- > " << k << " " << endl;
              Printlevel(root,k);
              k++;
              cout << endl;
             }
             cout << endl;
           }
};

int main(){
    Solution myTree;
    Node* head=NULL;
    cout << "Enter the total no. of Nodes" << endl;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        myTree.insert(data);
    }
    myTree.levelOrder();
    return 0;
}
