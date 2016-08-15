	void levelOrder(Node * root){
      //Write your code here
  	  queue<Node*> curr;
      queue<Node*> frontier;
      curr.push(root);
      while (!curr.empty())
          {
             cout << curr.front()->data << " ";
             if (curr.front()->left != NULL){
                 curr.push(curr.front()->left);
             }
             if (curr.front()->right != NULL){
                 curr.push(curr.front()->right);
             }
             curr.pop();
          }
        
        
	}
