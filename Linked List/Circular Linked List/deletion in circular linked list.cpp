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
void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}
//Naive method
node* deletebeg(node* head){
    if(head==NULL)
        return head;
    else if(head->next==NULL){
        delete head;
        return NULL;
    }
    else{
        node* temp=head;
        node* del=head;
        while(temp->next!=head)
            temp=temp->next;
        head=head->next;
        temp->next=head;
        delete del;
        return head;
    }
}
//Efficient approach
node* deletefrombeg(node* head){
    if(head==NULL) return NULL;
    else if(head->next==head){
        delete head;
        return NULL;
    }
    else{
        head->data=head->next->data;
        node* del=head->next;
        head->next=head->next->next;
        delete del;
        return head;
    }
}
//deletion from end
node* deletefromend(node* head){
    if(head==NULL)
        return head;
    else if(head->next=head){
        delete head;
        return NULL;
    }
    else{
        node* temp=head;
        temp=temp->next;
        node* prev=head;
        while(temp->next!=head){
            temp=temp->next;
            prev=prev->next;
        }
        prev->next=head;
        delete temp;
        return head;
    }
}
int main(){
    node* first=new node(10);
    node* second=new node(5);
    node* third=new node(20);
    node* fourth=new node(40);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=first;
    node* head=first;
    head=deletefrombeg(head);
    display(head);
    return 0;
}
