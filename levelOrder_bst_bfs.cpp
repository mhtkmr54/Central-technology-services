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
      Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }
           return root;
           }
        }

      void levelOrder(Node * root){
        	  deque<Node*> curr;
            queue<Node*> frontier;
            curr.push_back(root);
            int rootdata = root->data;
            int j = 0;
            int k = 0;
            int sum = 0;
            while (!curr.empty())
                {

                  if(curr.front()->data == -99){
                    cout << "-99 found" << endl;
                    Node* temp = new Node(-99);
                    curr.push_back(temp);
                    cout << "level ->  " << k << endl;
                    cout << "Sum For Level " << k << " SUM : " << sum << endl;
                    sum = 0;
                    k++;
                    curr.pop_front();
                   }


                   cout << curr.front()->data << " " << endl;
                   if (curr.front()->data != -99 && curr.front()->data!= rootdata)
                   {
                    sum += curr.front()->data;
                   }
                   /*if (curr[1]->data == -99)
                   {
                    cout << "Sum For Level " << k << " SUM : " << sum << endl;
                   }*/
                   if (curr.front()->left != NULL){
                       curr.push_back(curr.front()->left);
                   }
                   if (curr.front()->right != NULL){
                       curr.push_back(curr.front()->right);
                   }

                   if (j == 0){
                    Node* temp = new Node(-99);
                    curr.push_back(temp);
                    cout << "level ->  j == 0    " << k << endl;
                    k++;
                    j = 1;
                   }
                   cout << "last el       " <<curr[curr.size()-1]->data << endl;
                   curr.pop_front();

                }
           }
        };

int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
