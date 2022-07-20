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
node* deleteatbeg(node* head){
    node* temp;
    if(head->next==NULL)
        head=NULL;
    else if(head==NULL)
        head=NULL;
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
    return head;
}
node* deleteatend(node* head){
    node* temp=head;
    if(head==NULL||head->next==NULL){
        node* t=head;
        head=NULL;
        delete t;
        return head;
    }
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        node* del=temp->next;
        temp->next=NULL;
        delete del;
        return head;
    }
}
node* deleteatpos(node* head,int position){
    int i=1;
    node* temp;
    temp=head;
    while(i!=position-1){
        temp=temp->next;
        i++;
    }
    if(temp->next->next==NULL)
        head=deleteatend(head);
    else{
        node* s=temp->next->next;
        node* del=temp->next;
        temp->next=s;
        s->prev=temp;
        delete del;
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
    display(head);
    cout<<endl;
    /*head=deleteatbeg(head);
    display(head);
    cout<<endl;
    head=deleteatend(head);
    display(head);
    */
    head=deleteatpos(head,2);
    display(head);
    return 0;
}
