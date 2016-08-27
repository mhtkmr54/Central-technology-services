#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>

using namespace std;

vector <int> levelvec;
vector<int>::iterator it;

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

     void PrintGivenLevel(Node* root, int level){
            if (root ==NULL){
              return;
            }
            if (level == 1 ){
              levelvec.push_back(root->data);
            }
              PrintGivenLevel(root->first,level-1);
              PrintGivenLevel(root->second,level-1);
     }
};



int main() {
  //code
  Solution FamilyTree;
  Node* root = new Node(1);
  FamilyTree.makeFamily(root,4);
  int tests;
  int lvl;
  int pos;
  cin >> tests;
  for (int j = 0; j < tests; j++)
  {
    cin >> lvl >> pos;
    FamilyTree.PrintGivenLevel(root,lvl);
      if (levelvec[pos-1] == 1)
      {
        cout<<"Engineer" << endl;
      }
      if (levelvec[pos-1] ==2)
      {
        cout<<"Doctor" << endl;
      }
  }
  return 0;
}
