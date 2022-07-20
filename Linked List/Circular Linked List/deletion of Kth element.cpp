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
node* deleteknode(node* head,int k){
    if(k==1){
        //use function deletebeg
    }
    else{
        node* cur=head;
        for(int i=0;i<k-2;i++)
            cur=cur->next;
        node* temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
    }
    return head;
}
void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
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
    display(head);
    cout<<endl;
    deleteknode(head,2);
    display(head);
    return 0;
}
