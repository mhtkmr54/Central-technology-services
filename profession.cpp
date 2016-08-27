#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

class Node{

    public :
          int data;
          Node *first;
          Node *second;
          Node (int d){
              data = d;
              first = second = NULL;
          }
};

class Solution{
   public:
     Node* root;
     void makeFamily(Node* head,int level){
        cout << "    ->lvl     ------------------------------" << level;
        if (root == NULL)
         {
           root = head;
           return;
         }
         if (level == 1 | head == NULL)
         {
           return;
         }
        if (head->data == 1){
             if (head->first == NULL){
                 head->first = new Node(1);
             }
             if (head->second == NULL){
                 head->second = new Node(2);
             }
         }
        if (head->data == 2){
             if (head->first == NULL){
                 head->first = new Node(2);
             }
             if (head->second == NULL){
                 head->second = new Node(1);
             }
         }
         makeFamily(head->first,level-1);
         makeFamily(head->second,level-1);
     }

     void PrintGivenLevel(Node* root, int level, vector<int> levelvec){
            if (root ==NULL){
              return;
            }
            if (level == 1 ){
              cout << endl;
              cout << "root data pushed  " << root->data << " for lrvl   " << level << endl;
              levelvec.push_back(root->data);
            }

              PrintGivenLevel(root->first,level-1,levelvec);
              PrintGivenLevel(root->second,level-1,levelvec);
     }
};



int main() {
  //code
  Solution FamilyTree;
  Node* root = new Node(1);
  FamilyTree.makeFamily(root,4);
  vector <int> levelvec;
  FamilyTree.PrintGivenLevel(root,4,levelvec);
  vector<int>::iterator it;
  for(it = levelvec.begin(); it != levelvec.end(); ++it)
  {
         cout << *it <<" koun  ss" ;
  }
  cout << endl;
  return 0;
}
