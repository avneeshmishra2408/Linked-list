#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
    this->data=data;
    this->next=NULL;
    }
    ~Node(){
    int value=this->data;
    //Memory free
    if(this->next!=NULL){
        delete next;
        this->next=NULL;
    }
    cout<<"Memory is free "<<value<<endl;
    }
};

void insertAthead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void insertAttail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void insertAtposition(Node* &head,Node* &tail,int position,int data){
    if(position==1){
        insertAthead(head,data);
        return ;
    }
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    Node* nodeToInsert=new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void NodeTodelete(Node* &head,int position){
    if(position==1){
        Node* temp=head;
        head=head->next;
        //Memory free
        temp->next=NULL;
        delete temp;
    }else{
    Node* curr=head;
    Node* prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
    }
    prev->next=curr->next;
    curr->next=NULL;
        delete curr;
    }

}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
   Node* node1=new Node(10);
   Node* head=node1;
   Node* tail=node1;
   //cout<<node1->data<<endl;
   //cout<<node1->next<<endl;
   insertAthead(head,12);
   print(head);
   insertAttail(tail,15);
   print(head);
   insertAtposition(head,tail,3,19);
   print(head);
   NodeTodelete(head,4);
   print(head);
   return 0;
}
