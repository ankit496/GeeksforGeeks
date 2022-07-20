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
node* sorted_insert(node* head,int newdata){
    node* temp=head;
    node* newnode=new node(newdata);
    if(head==NULL)
        head=newnode;
    if(newdata<head->data){
        newnode->next=head;
    }
    while((temp->next->data<newdata)&&(temp->next!=NULL))
        temp=temp->next;
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    node *first=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    node* temp3=new node(40);
    first->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=NULL;
    node* head=first;
    head=sorted_insert(head,50);
    display(head);
    return 0;
}
