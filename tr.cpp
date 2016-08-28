/* struct Node
{
  int data;
  struct Node *left,  *right;
  struct Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
vector <Node*> levelconn;


int getheight(Node *p){
    if (p == NULL){
        return 0;
    }
    int lheight = getheight(p->left);
    int rheight = getheight(p->left);
    if (lheight > rheight){
        return lheight+1;
    }
    if (lheight < rheight){
        return rheight+1;
    }

}

void connection(Node*p, int level){
   if (p = NULL){
       return;
   }
   if (level == 1){
       levelconn.push_back(p);
       return;
   }
   connection(p->left,level-1);
   connection(p->right,level-1);
}

void connect(struct Node *p)
{
   // Your Code Here
   int height = getheight(p);
   int level = height + 1;
   for (int i=2; i <= level; i++){
      connection(p,i);
      for (int m=0; m<levelconn.size(); m++){
          if (m+1 >= levelconn.size()){
             levelconn[m]->nextRight = levelconn[m+1];
          }
          else{
              levelconn[m]->nextRight = NULL;
          }
      }
      levelconn.clear();
   }
}




