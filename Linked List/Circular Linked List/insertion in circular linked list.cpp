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
node* insertatend(node* head,int newdata){
    node* newnode=new node(newdata);
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        newnode->next=head->next;
        head->next=newnode;
        int t;
        t=newnode->data;
        newnode->data=head->data;
        head->data=t;
        head=newnode;
    }
    return head;
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
    head=insertatend(head,55);
    display(head);
    return 0;
}
