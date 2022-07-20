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
bool loopfloyd(node* head){
    node* slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
        if(fast==slow)
            return true;
    }
    return false;
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
    cout<<loopfloyd(head);
    return 0;
}

