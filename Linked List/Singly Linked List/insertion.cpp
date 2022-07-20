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
//insertion at beginning
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
//insertion at end
node* insertatend(node* head,int newdata){
    node* newnode=new node(newdata);
    if(head==NULL)
        head=newnode;
    else{
        node* t;
        t=head;
        while(t->next!=NULL)
            t=t->next;
        t->next=newnode;
    }
    return head;
}
//insertion at given position
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
//delete from a singly linked list
node* deleteatbeg(node* head){
    if(head==NULL)
        return head;
    else{
        node* t=head;
        head=head->next;
        delete t;
        return head;
    }
}
//delete from end
node* deleteatend(node* head){
    if(head==NULL)
        return head;
    else{
        node* temp=head;
        while(temp->next->next!=NULL)
            temp=temp->next;
        node* del=temp->next;
        temp->next=NULL;
        delete(del);
        return head;
    }
}
//delete from a given position
node* deleteatpos(node* head,int pos){
    int i=1;
    node* temp=head;
    while(i!=pos-1){
        temp=temp->next;
        i++;
    }
    if(pos==1){
        head=deleteatbeg(head);
    }
    else if(temp->next==NULL)
        head=deleteatend(head);
    else{
        node* del=temp->next;
        temp->next=temp->next->next;
        delete del;
    }
    return head;
}
//searching in a linked list
//1.Iterative approach;
int search_iterative(node* head,int value){
    int i=1;
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==value){
            return i;
        }
        else{
            temp=temp->next;
            i++;
        }
    }
    return -1;
}
//2.Recursive approach
int search_recursive(node* head,int value){
    if(head==NULL) return -1;
    if(head->data==value) return 1;
    else{
        int res=search_recursive(head->next,value);
        if(res==-1) return -1;
        else return (res+1);
    }
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    node *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=NULL;
    /*node* head;
    head=NULL;
    //checking for corner cases
    head=insertatbeg(head,5);
    head=insertatend(head,35);
    head=insertatpos(head,66,1);
    head=deleteatbeg(head);
    head=deleteatend(head);
    head=deleteatpos(head,3);
    */
    display(head);
    cout<<endl;
    cout<<search_iterative(head,10);
    cout<<endl;
    cout<<search_recursive(head,10);
    return 0;
}
