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
int main(){
    node* first=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    node* fourth=new node(40);
    node* fifth=new node(25);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;
    node* head=first;
    node* ptr;
    ptr=third;
    node* temp=ptr->next;
    ptr->data=temp->data;
    ptr->next=temp->next;
    delete(temp);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
