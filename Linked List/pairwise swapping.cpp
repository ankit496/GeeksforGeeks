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
    if(head==NULL)
        head=newnode;
    else{
        node* t;
        t=head;
        while(t->next!=NULL)
            t=t->next;
        t->next=newnode;
    }
    return head;
}
//this method changes the data of the node
node* swappairs(node* head){
    node* cur=head;
    while(cur!=NULL&&cur->next!=NULL){
        swap(cur->data,cur->next->data);
        cur=cur->next->next;
    }
    return head;
}
//this method changes the link

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    printf("\n");
}
int main(){
    node* head=NULL;
    head=insertatend(head,5);
    head=insertatend(head,6);
    head=insertatend(head,7);
    head=insertatend(head,8);
    head=insertatend(head,10);
    head=insertatend(head,12);
    display(head);
    head=swappairs(head);
    display(head);
    return 0;
}
