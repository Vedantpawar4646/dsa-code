
#include<iostream>
using namespace std;
class node
{
public:
int data;
node *left;
node *right;
};
class BST
{
public:
node *root;
int cnt;
BST()
{
root = NULL;
cnt = 0;
}
void insert();
int search(int key);
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);
void smallest();
void largest();
void mirror(node *r);
int height(node *r);
};
void BST::insert()
{
node *new_node, *temp;
int flag = 0;
new_node = new node();
new_node->left = NULL;
new_node->right = NULL;
cout << "enter node value: ";
cin >> new_node->data;
if (root == NULL)
{
root = new_node;
}
else
{
temp = root;
while (flag == 0)
{
if (new_node->data < temp->data)
{
if (temp->left == NULL)
{
temp->left = new_node;
flag = 1;
}
else
{
temp = temp->left;
}
}
else if (new_node->data > temp->data)
{
if (temp->right == NULL)
{
temp->right = new_node;
flag = 1;
}
else
{
temp = temp->right;
}
}
else
{
cout << "\n data already exist";
}
}
}
}
int BST::search(int key)
{
node *temp;
temp = root;
while (1)
{
if (key < temp->data)
{
if (temp->left != NULL)
{
temp = temp->left;
}
else
{
return (0);
}
}
else if (key > temp->data)
{
if (temp->right != NULL)
{
temp = temp->right;
}
else
{
return (0);
}
}
else
{
return (1);
}
}
}
void BST::inorder(node *temp)
{
if (temp != NULL)
{
inorder(temp->left);
cout << temp->data << " ";
inorder(temp->right);
}
}
void BST::preorder(node *temp)
{
if (temp != NULL)
{
cout << temp->data << " ";
preorder(temp->left);
preorder(temp->right);
}
}
void BST::postorder(node *temp)
{
if (temp != NULL)
{
postorder(temp->left);
postorder(temp->right);
cout << temp->data << " ";
}
}
void BST::mirror(node *r)
{
node *temp;
if (r != NULL)
{
temp = r->left;
r->left = r->right;
r->right = temp;
mirror(r->left);
mirror(r->right);
}
}
void BST::smallest()
{
node *temp;
temp = root;
while (temp->left != NULL)
{
temp = temp->left;
}
cout << temp->data;
}
void BST::largest()
{
node *temp;
temp = root;
while (temp->right != NULL)
{
temp = temp->right;
}
cout << temp->data;
}
int BST::height(node *r)
{
int left_height, right_height;
if (r == NULL)
{
return 0;
}
if (r->left == NULL && r->right == NULL)
{
return 0;
}
left_height = height(r->left);
right_height = height(r->right);
if (left_height > right_height)
{
return (left_height + 1);
}
else
{
return (right_height + 1);
}
}
int main()
{
BST b;
int ch, key;
do
{
cout << "\n\t 1. insert ";
cout << "\n\t 2. search";
cout << "\n\t 3.display inorder";
cout << "\n\t 4.display preorder";
cout << "\n\t 5.display postorder";
cout << "\n\t 6. mirror image";
cout << "\n\t 7.smallest node of tree";
cout << "\n\t 8.largest node of tree";
cout << "\n\t 9.height of the tree ";
cout << "\n\t enter your choice: ";
cin >> ch;
switch (ch)
{
case 1:
cout << "\n\t inserting node ......";
b.insert();
break;
case 2:
cout << "\n enter element to be searched: ";
cin >> key;
if (b.search(key))
{
cout << "\n element found ";
}
else
{
cout << "\n element not found ";
}
break;
case 3:
b.inorder(b.root);
break;
case 4:
b.preorder(b.root);
break;
case 5:
b.postorder(b.root);
break;
case 6:
b.inorder(b.root);
cout << "\n inorder before mirror image ";
b.mirror(b.root);
cout << "\n inorder after mirror image ";
b.inorder(b.root);
break;
case 7:
cout << "\n smallest node is: ";
b.smallest();
break;
case 8:
cout << "\n largest node is: ";
b.largest();
break;
case 9:
cout << "height is: " << b.height(b.root);
}
} while (ch >= 1 && ch <= 9); // corrected loop condition
return 0;
}








