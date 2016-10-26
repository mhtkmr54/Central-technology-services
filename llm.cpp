#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};

class Solution{
    public:
        Node* removeDuplicates(Node *head)
          {
              Node* start = head;
              while (start) {
                  if (start->next!=NULL) {
                      if (start->data == start->next->data) {
                          start->next = start->next->next;
                      } else {
                          start = start->next;
                      }
                  } else {
                      start = start->next;
                  }
              }
              return head;
          }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;
               }
              return head;
          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }

           Reverse(Node  head)
        prev=NULL       //Previous Pointer
        cur=head        //Current Node
        nxt=*cur.next   //Next Pointer
        while cur is not NULL
            nxt=(*cur).next
            (*cur).next=prev
            prev=cur
            cur=nxt
        head=prev
        return head

        Node* Insert(Node *head,int data)
  {
   Node* root = new Node();
  root->data = data;
  root->next = head ;
  head = root;
  return head;   
//inserting at head
}

Node* InsertNth(Node *head, int data, int position)
{
   Node* abc = new Node();
   Node* trav = head;
   abc->data = data;
   if (head == NULL || position == 0){
       abc->next = head;
       return abc;
   }
   int ct = 0;
   while (ct+1 < position){
       trav  = trav->next;
       ct++;
   }
   abc->next = trav->next;
   trav->next = abc;
   return head;
}

MergeSorted(Node a,Node b){
    if a is NULL and b is NULL
            return NULL
        if a is NULL
            return b
        if b is NULL
            return a

        Node c //Combined List
        if((*a).value<(*b).value){

        }
            c=a
            (*c).next=MergeSorted((*a).next,b)
        else
            c=b
            (*c).next=MergeSorted(a,(*b).next)      
        return c
}
};



int main()
{
  Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }
    head=mylist.removeDuplicates(head);

  mylist.display(head);

}
