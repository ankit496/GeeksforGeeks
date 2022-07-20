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
node* removedups(node* head){
    node* cur=head;
    while(cur!=NULL&&cur->next!=NULL){
        if(cur->data==cur->next->data){
            node* del=cur->next;
            cur->next=cur->next->next;
            delete del;
        }
        else
            cur=cur->next;
    }
    return head;
}
int main(){
    node* head=NULL;
    head=insertatbeg(head,10);
    head=insertatbeg(head,20);
    head=insertatbeg(head,20);
    head=insertatbeg(head,30);
    head=insertatbeg(head,30);
    head=insertatbeg(head,30);
    display(head);
    head=removedups(head);
    cout<<endl;
    display(head);
    return 0;
}

