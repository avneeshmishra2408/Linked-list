#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
    int value=this->data;
    //Memory free
    if(next!=NULL){
        delete next;
        next=NULL;
    }
    cout<<"Memory is free "<<value<<endl;
    }

};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAthead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAttail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
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
    if(temp->next==NULL){
        insertAttail(tail,data);
        return;
    }
    Node* nodeToInsert=new Node(data);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}

void deleteNode(Node* head,int position){
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;

    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<position){
                prev=curr;
                curr=curr->next;
                count++;
        }
    curr->prev=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    }

}

int main()
{
    Node* node1=new Node(10);
    cout<<node1->data<<endl;
    Node* head=node1;
    Node* tail=node1;
    Node* nodeToInsert=node1;
    //cout<<node1->next<<endl;
    //cout<<node1->prev<<endl;
    cout<<getLength(head)<<endl;
    insertAthead(head,20);
    print(head);
    insertAthead(head,18);
    print(head);
    insertAthead(head,15);
    print(head);
    insertAthead(head,25);
    print(head);
    insertAttail(tail,27);
    print(head);
    insertAtposition(head,tail,4,17);
    print(head);
    deleteNode(head,4);
    print(head);
    deleteNode(head,2);
    print(head);
    deleteNode(head,1);
    print(head);



    return 0;
}
