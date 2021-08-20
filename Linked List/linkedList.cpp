#include<bits/stdc++.h>
using namespace std;

//create a Node class

class Node{
   public:
    int data;
    Node* next;
    
    Node(int c){
        data=c;
        next= NULL;
    }
};

//insert function  which insert at the Head of linked List

Node* insert(Node* head,int x){
   
    Node* newNode= new Node(x);
    if(!head)
    { 
      head=newNode;
      return head;
    }
    newNode->next= head;
    head= newNode;
    return head;
}

// print the List

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

// Take inpute from user 

void takeInputList(Node*&head){
    int x;
    cin>>x;
    while(x!=-1){
     head=insert(head,x);   
     cin>>x;
    }
}

// overload left shift operator(>>) for taking input 

istream& operator>>(istream &is,Node*&head){
    takeInputList(head);
    return is;
}

// overload right shift operator(<<) for Printing List 

ostream& operator<<(ostream&os,Node*&head){
   printList(head);
   return os;
}

// count total no of nodes in Linked List

int countNode(Node* head){
 int x=0;
 while(head){
     x++;
     head=head->next;
 }
 return x;
}

// find middle Node in Linked List

Node* findMiddleNode(Node* head){
  if(head==NULL) 
   return NULL;
  Node* hair=head->next;
  Node*tortois=head;
  while(hair && hair->next){
      hair=hair->next->next;
      tortois=tortois->next;
  }
  return tortois;
}

// reverse the Linked List (recursive approach O(n^2))

Node* reverse(Node* head){
    if(head==NULL || head->next==NULL)
     return head;
    
    Node*newHead= reverse(head->next);
    Node*temp=newHead;
    while(temp->next!=NULL)
     temp=temp->next;
     
   temp->next=head;
   head->next=NULL;
   return newHead;
}

// reverse the Linked List (recursive approach O(n)) optimized

Node* optimizedRev(Node*head){
    if(head==NULL || head->next==NULL)
      return head;
    Node* newHead= optimizedRev(head->next);
    // Node* temp = head->next;
    // temp->next = head;
    head->next->next = head;
    head->next =NULL;
    return newHead;
}

//Find Kth Node from end in Linked List

Node* kthodeFromEnd(Node* head,int k){
    Node* hair= head;
    Node* tortois=head;
    while(k--){
        hair=hair->next;
    }
    while(hair){
        tortois=tortois->next;
        hair=hair->next;
    }
    return tortois;
}

// check weather there is cycle present in Linked List or not

bool cycleDetect(Node* head){
    Node* hair= head;
    Node* tortois=head;
    
    while(hair && hair->next){
        hair=hair->next->next;
        tortois=tortois->next;
        if(hair==tortois)
         return true;
    }
    
    return false;
    
}

// if there is a loop then Remove this loop

void removeloop(Node* head){
    if(cycleDetect(head)==false)
     {
         cout<<"there is no loop "<<endl;
         return ;
     }
     
       Node* hair= head;
    Node* tortois=head;
    Node* prev= NULL;
    while(hair && hair->next){
        hair=hair->next->next;
        tortois=tortois->next;
        if(hair==tortois)
          break;
      
    }
     
    hair=head;
    while(hair!=tortois){
        prev=tortois;
        hair=hair->next;
        tortois=tortois->next;
    }
    prev->next=NULL;

}

// Merge Two sorted Linked List (recursively)

Node* mergeSortedList(Node* head1,Node*head2){
    if(head1==NULL)
     return head2;
    if(head2==NULL)
      return head1;
     
    Node* newHead=NULL;  
    if(head1->data<head2->data)
     {
         newHead=head1;
         newHead->next= mergeSortedList(head1->next,head2);
     }
     else{
         newHead= head2;
         newHead->next= mergeSortedList(head1,head2->next);
     }
     return newHead;
}

// Sort two Linked List (Merge sort)

Node* mergeSort(Node* head){
    if(head->next==NULL)
      return head;
    Node* mid = findMiddleNode(head);
    Node* head1= head;
    Node* head2=mid->next;
    mid->next= NULL;
    head1= mergeSort(head1);
    head2=mergeSort(head2);
    Node* newHead=mergeSortedList(head1,head2);
    return newHead;
    
}

int main(){
  Node*head=NULL;
  Node*head1=NULL;
//   head=insert(head,5);
//   head=insert(head,4);
//   head=insert(head,3);
//   head=insert(head,2);
  
  //takeInputList(head);
  cin>>head;
 // cin>>head1;
//   printList(head);
//   printList(head1);
  
//   Node* middle=findMiddleNode(head);
//   cout<<middle->data<<endl;
 // cout<<head;
//  head= reverse(head);
//   cout<<head;
//   cout<<head1;
//   head1=optimizedRev(head1);
//   cout<<head1;
//   Node* kth =kthodeFromEnd(head,3);
//   Node* last = kthodeFromEnd(head,1);
//   last->next=kth;
 // cout<<last->data<<"->"<<last->next->data<<endl;
//   cout<<cycleDetect(head)<<endl;
//   removeloop(head);
//   cout<<cycleDetect(head)<<endl;
//  cout<<last->next;
//   cout<<kth->data;
  cout<<head;
 Node* newHead= mergeSort(head);
 //mergeSortedList(head,head1);
  cout<<newHead;
}