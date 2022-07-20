#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};
node* insertatbeg1(node* head,int newdata){
    node* newnode=new node(newdata);
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        newnode->next=head;
        head=newnode;
        temp->next=newnode;
    }
    return head;
}
node* insertatbeg2(node* head,int newdata){
    node* newnode=new node(newdata);
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        newnode->next=head->next;
        head->next=newnode;
        int t=head->data;
        head->data=newnode->data;
        newnode->data=t;
    }
    return head;
}
node* insertatend(node* head,int newdata){
    node* newnode=new node(newdata);
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
node* deletebeg(node* head){
    if(head==NULL)
        return head;
    else if(head->next==NULL){
        delete head;
        return NULL;
    }
    else{
        node* temp=head;
        node* del=head;
        while(temp->next!=head)
            temp=temp->next;
        head=head->next;
        temp->next=head;
        delete del;
        return head;
    }
}
node* deletefromend(node* head){
    if(head==NULL)
        return head;
    else{
        node* temp=head;
        temp=temp->next;
        node* prev=head;
        while(temp->next!=head){
            temp=temp->next;
            prev=prev->next;
        }
        prev->next=head;
        delete temp;
        return head;
    }
}
void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}
int main(){
    node* first=new node(10);
    node* second=new node(5);
    node* third=new node(20);
    node* fourth=new node(40);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=first;
    node* head=first;
    head=insertatbeg1(head,50);
    head=insertatbeg2(head,60);
    head=insertatend(head,33);
    display(head);
    cout<<endl;
    head=deletebeg(head);
    head=deletefromend(head);
    display(head);
    return 0;
}
