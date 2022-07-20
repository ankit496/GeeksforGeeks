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
node* insertatpos(node* head,int newdata,int pos){
    node* newnode=new node(newdata);
    node* t=head;
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
                t=t->next;
                i++;
            }
            if(t==NULL)
                cout<<"Position Out of Bound"<<endl;
            else{
                newnode->next=t->next;
                t->next=newnode;
            }
        }
    }
    return head;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
//iterative approach and it takes O(n) time
node* reverse_iterative(node* head){
    node* prev;
    node* cur;
    prev=NULL;
    cur=head;
    while(cur!=NULL){
        node* nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
    }
    return prev;
}
int main(){
    node* head=NULL;
    head=insertatpos(head,1,1);
    head=insertatpos(head,2,2);
    head=insertatpos(head,3,3);
    head=insertatpos(head,4,4);
    head=insertatpos(head,5,5);
    display(head);
    head=reverse_iterative(head);
    cout<<endl;
    display(head);
    return 0;
}
