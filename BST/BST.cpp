//Binary search tree Build and print 

#include<bits/stdc++.h>
using namespace std;

//ode class for BST

class Node{
  public:
  
   int data;
   Node*left;
   Node*right;
   
   Node(int data){
       this->data=data;
       left=NULL;
       right=NULL;
   }
   
};

// insert any data into binary search tree

Node* insertInBST(int data,Node*root){
    if(root==NULL)
      {
         Node*node= new Node(data);
         return node;
      }
     
     if(data<root->data)
      root->left=insertInBST(data,root->left);
     else
      root->right=insertInBST(data,root->right);
      
     return root;
}


// inorder print of BST (result in sorted data)

void inOrder(Node* root){
    if(root==NULL)
     return ;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// Take input and insert in BST

Node* bulidBST(){
    int x;
    cin>>x;
    Node* root=NULL;
    while(x!=-1){
      root= insertInBST(x,root);
        cin>>x;
    }
    return root;
}

int main(){
    Node* root;
    root=bulidBST();
    inOrder(root);
}