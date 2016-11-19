/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* head;
    ListNode* root;
    vector <int> mine;
    ListNode* H1 = A;
    ListNode* H2 = B;
    while (H1 != NULL && H2 != NULL){
        if(H1->val < H2->val){
            root = new ListNode(H1->val);
            mine.push_back(root->val);
            //cout << root->val << " ";
            //root->next = el;
            root = root->next;
            H1 = H1->next;
        }else{
            root = new ListNode(H2->val);
             mine.push_back(root->val);
            //cout << root->val << " ";
            //root->next = el;
            root = root->next;
            H2 = H2->next;
        }
    }
    while (H2 != NULL){
        
        root = new ListNode(H2->val);
         mine.push_back(root->val);
        //cout << root->val << " ";
        //root->next = el;
        root = root->next;
        H2 = H2->next;
    }
    while (H1 != NULL){
        root = new ListNode(H1->val);
         mine.push_back(root->val);
        //cout << root->val << " ";
        //root->next = el;
        root = root->next;
        H1 = H1->next;
    }
 
     ListNode *start = new ListNode(mine[0]);
     head = start;
     //int i = 0;
     for(int i = 1; i < mine.size(); i++)
          {
            start->next = new ListNode(mine[i]);
            start=start->next;
          }

    
    return head;
}











ListNode* mergeTwoLists(ListNode* A, ListNode* B) {

    ListNode* head;
    ListNode* tail; //<-- a tail is introduced
    ListNode* root;

    ListNode* H1 = A;
    ListNode* H2 = B;
    int flag = 0;
    while (H1 != NULL && H2 != NULL){
        if(H1->val < H2->val){
            root = new ListNode(H1->val);
            //cout << root->val << " ";
            if (flag == 0){ //<-- fixed
                 head = root;
                 tail=head;
                flag = 1;
            }
            else
            {
                tail->next=root;
                tail = root;
            }


            //root->next = el;
            //root = root->next;
            H1 = H1->next;
        }else{
            root = new ListNode(H2->val);
            if (flag == 0){  //<-- fixed
               head  =root;
               tail=head;
                flag = 1;
            }
            else
            {
                tail->next=root;
                tail = root;
            }
            //cout << root->val << " ";
            //root->next = el;
           // root = root->next;
            H2 = H2->next;
        }
    }
    while (H2 != NULL){

        root = new ListNode(H2->val);
        //cout << root->val << " ";
        //root->next = el;
        tail->next=root;
        tail=root;
       // root = root->next;
        H2 = H2->next;
    }
    while (H1 != NULL){
        root = new ListNode(H1->val);
        //cout << root->val << " ";
        //root->next = el;
        tail->next=root;
        tail=root;
        //root = root->next;
        H1 = H1->next;
    }

     ListNode *start=head;
        while(start)
          {
            cout<<start->val<<" ";
            start=start->next;
          }


    return head;
}


ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   deque<int> m;
   ListNode* head = A;
   while (head != NULL){
       m.push_back(head->val);
       head= head->next;
   }
   int a = m.size()-B;
   m.erase(m.begin()+a);
    ListNode *start = new ListNode(m[0]);
     head = start;
     //int i = 0;
     for(int i = 1; i < m.size(); i++)
          {
            start->next = new ListNode(m[i]);
            start=start->next;
          }
    return head;
}


/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/


SUCCCSESSFIUl HUCKERR
Node* MergeLists(Node *headA, Node* headB)
{
  if (headA == NULL){
      return headB;
  }
  if (headB == NULL){
      return headA;
  }
  Node* a = headA;
  Node* b = headB;
  Node* abc = new Node();
  Node* abcH = abc;
  if (a->data < b->data){
      abc->data = a->data;
      a = a->next;
  }
  else{
      abc->data = b->data;
      b = b->next;
  }
    
  while (a != NULL && b != NULL){
      if (a->data < b->data){
        Node* el  = new Node();
        el->data = a->data;
        abc->next = el;
        abc = abc->next;
        a = a->next;
      }
      else {
        Node* el  = new Node();
        el->data = b->data;
        abc->next = el;
        abc = abc->next;
        b = b->next;
      } 
  }
  while (a != NULL){
        Node* el  = new Node();
        el->data = a->data;
        abc->next = el;
        abc = abc->next;
        a = a->next;
  }
  while (b != NULL){
        Node* el  = new Node();
        el->data = b->data;
        abc->next = el;
        abc = abc->next;
        b = b->next;
  }
  return abcH;
}
