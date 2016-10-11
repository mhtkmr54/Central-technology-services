      Node* insert(Node *head,int key)
      {
          //Complete this method
          Node* start = head;
          if (head->next == NULL)
          {
              cout << "inside IFFF"<< endl;
              head->next = new Node(key);
          }
          while(start->next != NULL)
          {
              cout << "inside While"<< endl;
              start=start->next;
          }
          head->next = new Node(key);
          return head;
      }


      Node* insert(Node *head,int data)
      {
          Node* newnode= new Node (data);
              if (head==NULL  ){
              return newnode;
          }
         Node* it = head;
          while (it->next!=NULL){
              it= it->next;
          }
          it->next= newnode;
          return head;
      }

/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
  Node* root = head;
  int i = 0;
  if (position == 0){
      head = root->next;
      return head;
  }
  while( i+1 != position){
      root = root->next;
      i++;
  }
  root->next = root->next->next;
  return head;
    
}

Node* Insert(Node *head,int data)
{
   Node* root = new Node();
  root->data = data;
  root->next = head ;
  head = root;
  return head;
    



}