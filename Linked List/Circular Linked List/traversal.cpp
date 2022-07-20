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
//Method1
void display(node* head){
    node* temp;
    temp=head;
    if(temp==NULL){
        cout<<" ";
        return;
    }
    cout<<temp->data<<" ";
    temp=temp->next;
    for(;temp!=head;temp=temp->next)
        cout<<temp->data<<" ";
}
//Method2
void print(node* head){
    node* temp=head;
    if(temp==NULL)
        return;
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

    display(head);
    print(head);
    return 0;
}
