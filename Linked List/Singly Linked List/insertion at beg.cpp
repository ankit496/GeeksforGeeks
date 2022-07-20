#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
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
int main(){
    /*node *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=NULL;*/
    node* head;
    head=NULL;
    head=insertatbeg(head,5);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
