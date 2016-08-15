    int getHeight(Node* root){
         if(!root) {
              return -1;
          }
          int leftDepth = getHeight(root->left);
          int rightDepth = getHeight(root->right);

          return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;

        }

