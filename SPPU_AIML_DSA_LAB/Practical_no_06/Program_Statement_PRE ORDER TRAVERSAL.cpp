
/*Q. Implement In-order Threaded Binary Tree and traverse it in In-order and Preorder.*/


 PRE-ORDER TRAVERSAL:

#include<iostream>
#include<list>
using namespace std;
class node
{
 int data; 
 node *left,*right; 
 bool rbit; 
 friend class tree; 
};
class tree
{
node *root,*temp; 
list<node*>q; 
public:
tree(); 
inline node* get_root()
{
return root;
} 
void accept(int); 
node *insert(node*,node*); 
 void display(); 
void putPre(node*); 
void thread(node*); 
};
tree :: tree()
{
 root = NULL; 
}
void tree :: accept(int total)
{
for(int i=0;i<total;i++)
 {
 temp = new node;
cout<<"\nEnter the element : ";
cin>>temp->data;
 temp->rbit = false;
 temp->left = NULL;
 temp->right = NULL;
 root = insert(root,temp); 
 }
 thread(root);
}
node* tree :: insert(node* r,node* t)
{
if(r == NULL)
 return t;
 else if(r->data > t->data)
 {
 r->left = insert(r->left,t);
 }
 else
 {
 r->right = insert(r->right,t);
 }
 return r;
}
void tree :: display()
{
 node *cur = root; 
while(cur != NULL)
 {
cout<<"\t"<<cur->data; 
 if(cur->rbit) 
 {
 cur = cur->right;
cout<<"(T)";
 }
 else if(cur->left) 
 cur = cur->left;
 else
 cur = cur->right; 
 }
}
void tree :: putPre(node *r)
{
if(r != NULL)
 {
q.push_back(r);
putPre(r->left);
putPre(r->right);
 }
}
void tree :: thread(node *r)
{
 bool check = false; 
 node *cur ;
putPre(r); 
 while(!check) 
 {
 cur = q.front(); 
 if(q.empty()) 
 check = true;
 else
 {
q.pop_front(); 
 if(!cur->right && !cur->left)
 {
 if(q.empty()) 
 cur->right = NULL; 
 else
 {
 cur->right = q.front(); 
 cur->rbit = true; 
 }
 }
 }
 }
}
int main()
{
tree t;
int ch,total;
do
{
cout<<"\n\t|| PORGRAM TO CONVERT BST TO Pre-Order TBT ||\n";
cout<<"\n1.Create Tree";
cout<<"\n2.Display Pre-Order";
cout<<"\n3.Exit";
cout<<"\n>>";
cin>>ch;
switch(ch)
{
case 1:
 if(t.get_root() != NULL)
 {
cout<<"\n\t***** Tree already exists... This program converts a binary tree to a threaded 
binary tree *****\n";
 break;
 }
cout<<"\nEnter the total number of elements : ";
cin>>total;
t.accept(total);
break;
case 2:
 if(!t.get_root())
 {
cout<<"\n\t**** Tree doesn't exist ****\n";
 break;
 }
cout<<"\n\t*** Nodes having threads are displayed succeeding with (T) 
***\n";
cout<<"\n| Pre - Ordeer : |";
t.display();
cout<<endl;
break;
case 3:
cout<<"\n\t\t********Exit*********\n";
break;
default:
cout<<"\nInvalid Choice\n";
break;
}
}while(ch!=3);
return 0;
}

