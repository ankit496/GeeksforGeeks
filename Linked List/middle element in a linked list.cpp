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
node* insertatbeg(node* head,int newdata){
    node* newnode=new node(newdata);
    if(head==NULL)
        head=newnode;
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int middleelement(node* head){
    node* fast,*slow;
    fast=head;
    slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
    }
    int value=slow->data;
    return value;
}
int main(){
    node* head=NULL;
    head=insertatbeg(head,10);
    head=insertatbeg(head,20);
    head=insertatbeg(head,30);
    head=insertatbeg(head,40);
    head=insertatbeg(head,50);
    head=insertatbeg(head,60);
    display(head);
    cout<<endl;
    cout<<middleelement(head);
    return 0;
}
