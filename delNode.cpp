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
