#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  
  //constructor
  
  Node(int d){
    this->data = d;
    this->next = NULL;
  }
  
  //Destructor
  
  ~Node(){
    int value = this ->data;
    if(this ->next != NULL)
    {
      delete next;
      next = NULL;
    }
    cout<<"The value that has been deleted for value"<<value <<endl;
  }
};

void print(Node* tail){
    Node* temp=tail;
    do{
      cout<<tail->data<<" ";
      tail = tail -> next;
    }
    while(tail != temp);
        // cout<<tail->data<<" ";
        // tail=tail->next;
    cout<<endl;
}

void insertNode(Node* tail, int element, int d)
{
  if(tail == NULL)
  {
    Node* newNode = new Node(d);
    tail = newNode;
    newNode -> next = newNode;
    
  }
  else
  {
    Node* curr = tail;
    while(curr -> data != element)
    {
      curr = curr -> next;
    }
    Node* temp = new Node(d);
    temp -> next = curr-> next;
    curr -> next = temp;
  }
}

void deleteNode(Node* &tail,int value){
  if(tail == NULL){
    cout<<"Linked list empty"<<" ";
    return;
  }
  else
  {
    Node* prev = tail;
    Node* curr = prev -> next;
    while(curr->data != value){
      prev= prev ->next;
      curr = curr -> next;
    }
    
    prev->next = curr->next;
    if(tail == curr)
    {
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}

int main()
{
  
  Node* tail = NULL;
  print(tail);
  insertNode(tail,5,3);
  print(tail);
   insertNode(tail,3,5);
  print(tail);
   insertNode(tail,5,7);
  print(tail);
   insertNode(tail,3,9);
  print(tail);
   insertNode(tail,7,10);
  print(tail);
  
  return 0;
}

