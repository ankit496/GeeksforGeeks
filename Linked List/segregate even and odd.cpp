#include<iostream>
using namespace std;
#include<vector>
struct node{
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};
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
//naive approach which uses auxiliary space
node* segregrate_even_odd(node* head){
    vector <int> temp;
    node *eventemp=head;
    while(eventemp!=NULL){
        if((eventemp->data)%2==0)
            temp.push_back(eventemp->data);
        eventemp=eventemp->next;
    }
    node* oddtemp=head;
    while(oddtemp!=NULL){
        if((oddtemp->data)%2!=0)
            temp.push_back(oddtemp->data);
        oddtemp=oddtemp->next;
    }
    node* replica=head;
    int i=0;
    while(replica!=NULL){
        replica->data=temp[i];
        i++;
        replica=replica->next;
    }
    return head;
}
//efficient approach
node* segregateEvenOdd(struct node *head)
{
    node* cur=head;
    node* evenstart=NULL;
    node* oddstart=NULL;
    node* evenend=NULL;
    node* oddend=NULL;
    while(cur!=NULL){
        int x=cur->data;
        if(x%2==0){
            if(evenstart==NULL){
                evenstart=cur;
                evenend=evenstart;
            }
            else{
                evenend->next=cur;
                evenend=evenend->next;
            }
        }
        else{
            if(oddstart==NULL){
                oddstart=cur;
                oddend=oddstart;
            }
            else{
                oddend->next=cur;
                oddend=oddend->next;
            }
        }
        cur=cur->next;
    }
    if(evenstart==NULL||oddstart==NULL)
        return head;
    evenend->next=oddstart;
    oddend->next=NULL;
    head=evenstart;
    return head;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    printf("\n");
}
int main(){
    node* head=NULL;
    head=insertatend(head,17);
    head=insertatend(head,15);
    head=insertatend(head,8);
    head=insertatend(head,12);
    head=insertatend(head,10);
    head=insertatend(head,5);
    head=insertatend(head,4);
    display(head);
    head=segregrate_even_odd(head);
    display(head);
    head=segregateEvenOdd(head);
    display(head);
    return 0;
}
