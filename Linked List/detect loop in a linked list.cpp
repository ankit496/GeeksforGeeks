#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    //bool visited;
    node(int x){
        data=x;
        next=NULL;
        // visited=false;
    }
};
/*int loop(node* head){
    int havealoop=0;
    node* temp1=head;
    while(temp1->next!=NULL){
        node* temp2=head;
        while(temp2->next!=NULL){
            if(temp1->next==temp2){
                havealoop=1;
                break;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
        if(havealoop==1)
            break;
    }
    return havealoop;
}
//if modification in the structure is allowed
bool loop(node* head){
    node* temp=head;
    while(temp!=NULL){
        if(temp->visited==false){
            temp->visited=true;
        }
        else{
            return true;
        }
        temp=temp->next;
    }
    return false;
}
//this method works fine but changes or destroys the linked list
bool aloop(node* head){
    node* temp;
    node* cur=head;
    while(cur!=NULL){
        if(cur->next==NULL)
            return false;
        if(cur->next==temp)
            return true;
        node* cur_next=cur->next;
        cur->next=temp;
        cur=cur_next;
        return false;
    }
}*/
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
    //cout<<loop(head);
    cout<<aloop(head);
    return 0;
}
