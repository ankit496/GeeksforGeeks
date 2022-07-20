#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
    node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
node* insertatbeg(node* head,int newdata){
    node* newnode=new node(newdata);
    if(head==NULL)
        head=newnode;
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    return head;
}
node* insertatend(node* head,int newdata){
    node* temp=head;
    node* newnode=new node(newdata);
    if(head==NULL)
        head=newnode;
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
    return head;
}
node* insertatpos(node* head,int newdata,int pos){
    node* newnode=new node(newdata);
    node* temp=head;
    if(head==NULL){
        head=newnode;
    }
    else{
        if(pos==1){
            newnode->next=head;
            head=newnode;
        }
        else{
            int i=1;
            while(i!=pos-1){
                temp=temp->next;
                i++;
            }
            if(temp==NULL)
                cout<<"Position Out of Bound"<<endl;
            else{
                newnode->next=temp->next;
                newnode->prev=temp;
                temp->next->prev=newnode;
                temp->next=newnode;
            }
        }
    }
    return head;
}
int main(){
    node* first=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    first->prev=NULL;
    first->next=second;
    second->prev=first;
    second->next=third;
    third->prev=second;
    third->next=NULL;
    node* head=first;
    head=insertatbeg(head,5);
    head=insertatend(head,35);
    head=insertatpos(head,25,2);
    head=insertatbeg(head,66);
    display(head);
    return 0;
}

