struct node {
int data;
struct node *left, *right;
};

int count = 0;

void print(struct node *root, int k)
{
if (root != NULL && count <= k)
{
print(root->right, k);
count++;
if (count == k)
printf("%d ", root->data);
print(root->left, k);
}
}