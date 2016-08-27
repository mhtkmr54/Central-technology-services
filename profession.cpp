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
        if (head == NULL)
         {
           root = head;
           return;
         }
         if (level == 1)
         {
           return;
         }
        if (head->data == 1){
             if (head->first == NULL){
                 Node* Eng = new Node(1);
                 head->first = Eng;
             }
             if (head->second == NULL){
                 Node* Doc = new Node(2);
                 head->second = Doc;
             }
         }
        if (head->data == 2){
             if (head->first == NULL){
                 Node* Doc = new Node(2);
                 head->second = Doc;
             }
             if (head->second == NULL){
                 Node* Eng = new Node(1);
                 head->first = Eng;
             }
         }
         makeFamily(head->first,level-1);
         makeFamily(head->second,level-1);
     }

     void PrintGivenLevel(Node* root, int level, vector<int> levelvec){
            if (level == 1){
              levelvec.push_back(root->data);
            }
            else{
              level--;
              PrintGivenLevel(root->first,level,levelvec);
              PrintGivenLevel(root->second,level,levelvec);
            }
     }
};



int main() {
  //code
  Solution FamilyTree;
  Node* root = new Node(1);
  FamilyTree.makeFamily(root,4);
  vector <int> levelvec;
  FamilyTree.PrintGivenLevel(root,3,levelvec);
  for(auto elem : levelvec)
  {
         cout << elem <<" " ;
  }
  cout << endl;
  return 0;
}
