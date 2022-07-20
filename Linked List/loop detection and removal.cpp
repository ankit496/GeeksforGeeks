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
void deleteloop(node* head){
    node* slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
            break;
    }
    if(slow!=fast)
        return;
    slow=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
    node* t=head;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
}
void display(node* head){
    while(head!=NULL){
        head=head->next;
        cout<<head->data<<" ";
    }
}
int main(){
    node *first=new node(10);
    node *second=new node(15);
    node *third=new node(12);
    node* fourth=new node(20);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=second;
    node* head=first;
    deleteloop(head);
    display(head);
    return 0;
}
