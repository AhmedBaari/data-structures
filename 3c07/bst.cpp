#include<iostream>
using namespace std;

struct node
{
int data;
node* left;
node* right;
};

class bst
{
public:
node* insert(node*root,node*temp)
{
if(root==NULL)
return temp;
else if(temp->data<root->data)
root->left=insert(root->left,temp);
else if(temp->data>=root->data)
root->right=insert(root->right,temp);
return root;
}

node* find_largest(node*root)
{
if(root->right==NULL)
return root;
else
return find_largest(root->right);
}

node* find_smallest(node* root)
{
if(root->left==NULL)
return root;
else
return find_smallest(root->left);
}

void preorder(node* root)
{
if(root!=NULL)
{
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}
}

void inorder(node* root)
{
if(root!=NULL)
{
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
}

void postorder(node* root)

{
if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";
}
}

node* del (node* root,int key)
{
if(root==NULL)
return NULL;
else if (root->data<key)
root->right=del(root->right,key);
else if (root->data>key)
root->left=del(root->left,key);
else
{
if(root->right==NULL)
{
node* temp=root->left;
delete root;
return temp;
}
else if (root->left==NULL)
{
node* temp=root->right;
delete root;
return temp;
}
else
{
node * largest=find_largest(root->left);
node*delnode=root;
cout<<largest->data<<" moved to "<<root->data<<endl;
root->data=largest->data;
root->left=del(root->left,largest->data);
}
}
return root;
}

node * search(node* root,int target)
{
if(root==NULL)
return NULL;
if(target<root->data)
return search(root->left,target);
else if(target>root->data)
return search(root->right,target);
else
return root;
}
};

int main()
{
bst b;
node *root=NULL,*l=NULL,*s=NULL,*temp=NULL;
int x,ch;
cout<<"1-Insert, 2-Delete,3-Search,4-Find largest value,5-Find Smallest value,6-Preorder Traversal,7-Inorder Traversal,8-Postorder Traversal,0-Exit:-\n";
while(ch!=0)
{
cout<<"Enter choice: ";
cin>>ch;
switch(ch)
{
case 1:
cout<<"Enter value to insert: ";
cin>>x;
temp=new node;
temp->data=x;
temp->left=temp->right=NULL;
cout<<"Node created successfully."<<endl;
root=b.insert(root,temp);
cout<<"Element "<<x<<" inserted sucessfully!\n";
break;
case 2:
cout<<"Enter value to delete: ";
int x;
cin>>x;
if(!b.search(root,x))
cout<<"Element does not exist."<<endl;
else
{
root=b.del(root,x);
cout<<"Element successfully deleted!!"<<endl;
}
break;
case 3:
cout<<"Enter value to search: ";
cin>>x;
if(b.search(root,x))
cout<<"Element present in tree."<<endl;
else
cout<<"Element not present in tree!"<<endl;
break;
case 4:
l=b.find_largest(root);
cout<<"Largest value: "<<l->data<<endl;
break;
case 5:
s=b.find_smallest(root);
cout<<"Smallest value: "<<s->data<<endl;
break;
case 6:
b.preorder(root);
cout<<endl;
break;
case 7:
b.inorder(root);
cout<<endl;
break;
case 8:
b.postorder(root);
cout<<endl;
break;
case 0:
 break;
default:
cout<<"Incorrect choice."<<endl;
}
}
}
