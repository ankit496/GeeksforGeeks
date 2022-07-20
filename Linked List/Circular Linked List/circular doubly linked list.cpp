#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};
void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}
node* insertatbeg(node* head,int newdata){
    node* newnode=new node(newdata);
    newnode->next=head;
    newnode->prev=head->prev;
    head->prev->next=newnode;
    head=newnode;
    return head;
}
int main(){
    node* first=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    first->next=second;
    first->prev=third;
    second->next=third;
    second->prev=first;
    third->next=first;
    third->prev=second;
    node* head=first;
    head=insertatbeg(head,5);
    display(head);
    return 0;
}
