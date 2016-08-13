#include <iostream>
#include <cstdlib>

using namespace std;

class BST{

private:

  struct node
  {
     int data;
     node* left;
     node* right;
  };

  node* root;
  void AddLeafPrivate(int key, node* Ptr);
  void PrintInorderPrivate(node* Ptr);
  node* ReturnNodePrivate(int key, node* Ptr);
  int FindSmallestPrivate(node* Ptr);
  void RemoveNodePrivate(int key, node* parent);
  void RemoveRootMAtch();
  void RemoveMatch(node* parent, node* match, bool left);




public:
   BST();
   node* CreateLeaf(int key);
   node* ReturnNode(int key);
   void AddLeaf(int key);
   void PrintInorder();
   int ReturnRootKey();
   void PrintChildren(int key);
   int FindSmallest();
   void RemoveNode(int key);



};


BST::BST(){
  root = NULL;
}

BST::node* BST::CreateLeaf(int key)
{
  node* n = new node;
  n->data = key;
  n->left = NULL;
  n->right = NULL;

  return n;
}

void BST::AddLeaf(int key)
{
  AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
  if(root == NULL){
   root = CreateLeaf(key);
  }
  else if (key < Ptr->data){
    if(Ptr->left != NULL){
      AddLeafPrivate(key, Ptr->left);
    }
    else {
      Ptr->left = CreateLeaf(key);
    }

  }
  else if (key > Ptr->data){
    if(Ptr->right != NULL){
      AddLeafPrivate(key, Ptr->right);
    }
    else
    {
      Ptr->right = CreateLeaf(key);
    }

  }
  else
  {
    cout<<"The Key  "<< key << "is already added";
  }
}


void BST::PrintInorder(){

  PrintInorderPrivate(root);
}

void BST::PrintInorderPrivate(node* Ptr){
  if(root != NULL)
  {
   if(Ptr->left != NULL){
      PrintInorderPrivate(Ptr->left);
    }
    cout<< Ptr->data << " ";
    if(Ptr->right != NULL){
      PrintInorderPrivate(Ptr->right);
    }
  }
  else
  {
    cout << "Dude go make a treee \n";
  }

}

 BST::node* BST::ReturnNode(int key)
 {
   return ReturnNodePrivate(key, root);
 }

  BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
 {
   //cout<<"PTR data" << Ptr->data << "And Key to find-- "<< key << endl;
   if (Ptr != NULL)
   {
      if(Ptr->data == key)
      {
        return Ptr;
        //cout<<"PTR" << key << endl;
      }
      else{
        if(key < Ptr->data)
          {
           return ReturnNodePrivate(key, Ptr->left);
          }
        if(key > Ptr->data)
          {
           return ReturnNodePrivate(key, Ptr->right);
          }
      }
   }
   else
   {
     return NULL;
   }
 }


int BST::ReturnRootKey(){
  if (root!= NULL)
  {
     return root->data;
  }
  else
  {
     return -1000;
  }
}



void BST::PrintChildren(int key)
{
   node* Ptr = ReturnNode(key);
   if (Ptr != NULL)
   {
     Ptr->left == NULL ?  //Conditional Operator
     cout<<"Left Child = NULL\n"  :
     cout<<"Left Child = "<< Ptr->left->data <<endl;
     Ptr->right == NULL ?  //Conditional Operator
     cout<<"right Child = NULL\n" :
     cout<<"right Child = "<< Ptr->right->data <<endl;
   }
   else{
    cout << "Dude Where is the " << key << " " ;
   }
}


int BST::FindSmallest()
{
   FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
   if (root == NULL)
   {
    cout << "No Tree made";
    return -1000;
   }


    if (Ptr->left != NULL)
    {
     FindSmallestPrivate(Ptr->left);
    }
    else
    {
    cout<<"Smallest is " << Ptr->data <<endl;
    return Ptr->data;
    }

   }

void BST::RemoveNode(int key)
{
   RemoveNodePrivate(key,root);
}



void BST::RemoveNodePrivate(int key,node* parent)
{
  if (root != NULL)
  {
   if (root->data == key)
   {
     RemoveRootMatch();
   }
   else{
    if (key <  parent->data && parent->left != NULL)
    {
       parent->left->data == key ?
       RemoveMatch(parent, parent->left, true) : //true for right child
       RemoveNodePrivate(key,parent->left);
    }
    else if (key >  parent->data && parent->right != NULL)
    {
       parent->right->data == key ?
       RemoveMatch(parent, parent->right, false) :
       RemoveNodePrivate(key,parent->right);
    }
    else
    {
      cout <<"The Key not found to remove:";
    }
   }
  }
  else{
    cout<<"tree is empty";
  }
}

void BST::RemoveRootMatch()
{
  if (root!=NULL)
  {
     node* delPtr = root; //taking out old root pointer to b deleted
     int rootkey = root->data;
     int smallestinRightSubTree;

     //case 0-0 children
     if(root->left == NULL && root->right == NULL)
     {
      root = NULL;
      delete delPtr;
     }
     // case 1-1 children
     else if (root->left == NULL && root->right != NULL)
     {
         root = root->right;
         delPtr->right = NULL;
         delete delPtr;
         cout << "deleted  "<< rootkey << "new key "<< root->data<<endl;
     }
     else if (root->left != NULL && root->right == NULL)
     {
         root = root->left;
         delPtr->left = NULL;
         delete delPtr;
         cout << "deleted  "<< rootkey << "new key "<< root->data << endl;
     }
     //case 2-2 children
     else
     {
       smallestinRightSubTree = FindSmallestPrivate(root->right);
       RemoveNodePrivate(smallestinRightSubTree, root);
       root->data = smallestinRightSubTree;
       cout << "deleted  "<< rootkey << "new key "<< root->data << endl;
     }

  }
  else
  {
    cout<<"cannot remove private root" << endl;

  }

}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
  if(root != NULL)
  {
      node delPtr = root;
      int matchkey = match->data;
      int smallestinRightSubTree;


      if (match->left == NULL && match->right == NULL)
      {
           delPtr = match;
           left == true ? parent->left = NULL : parent->right == NULL;
           delete delPtr;
           cout<< "key deleted"<<endl;
      }
      else if (match->left == NULL && match->right != NULL)
      {

      }
  }

  else
  {
    cout << "cant del tree empty ?" << endl;
  }
}















































int main(){
  int TreeKeys[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
  BST myTree;
  cout << "Printing the tree in order\n before adding no.\n";
  myTree.PrintInorder();

  for (int i = 0; i < 16; i++)
  {
    myTree.AddLeaf(TreeKeys[i]);
  }

  cout << "Printing the tree in order\n AFTER adding no.\n";
  myTree.PrintInorder();
  cout << "\n";

  for (int j = 0; j < 16; j++)
  {
    cout<<"Treekey PArent "<<TreeKeys[j];
    cout<<endl;
    myTree.PrintChildren(TreeKeys[j]);
    cout<<endl;
  }
  cout << "\n";
  cout << "\n";
  cout<< myTree.FindSmallest();
  cout << "\n";
  cout<< "Key to del  or -1 to stop proc"<< endl;
  cin >> input;
  while(input != -1)
  {
    cout<<"Del Node : ";
    {
      if (input != -1)
      {
        cout << endl;
        myTree.RemoveNode(input);
        myTree.PrintInOrder();
        cout << endl;
      }
    }
  }



  return 0;

}
