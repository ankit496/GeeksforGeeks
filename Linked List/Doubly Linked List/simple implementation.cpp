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
    display(head);
    return 0;
}
