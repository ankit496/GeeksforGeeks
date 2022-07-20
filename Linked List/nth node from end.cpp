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
int nth_node(node* head,int n){
    node* temp=head,* temp2=head;
    int length=0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    int index=length-n;
    if(n>length)
        return 0;
    else{
        for(int i=1;i<=index;i++)
            temp2=temp2->next;
        return temp2->data;
    }
}
int n_node(node* head,int n){
    node* first=head;
    node* second=head;
    for(int i=1;i<=n;i++){
        first=first->next;
    }
    while(first!=NULL){
        first=first->next;
        second=second->next;
    }
    return second->data;
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
    cout<<nth_node(head,2);
    cout<<endl;
    cout<<n_node(head,2);
    return 0;
}

