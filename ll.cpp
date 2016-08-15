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
