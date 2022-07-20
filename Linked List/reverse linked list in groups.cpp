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
node* reverse_groups(node* head,int group_length){
    node* cur=head;
    node* prev=NULL;
    while(cur!=NULL){
        for(int i=1;i<=group_length;i++){
            node* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
    }
    head=prev;
    return head;
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
    head=reverse_groups(head,3);
    display(head);

    return 0;
}

