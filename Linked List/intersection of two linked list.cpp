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
int getintersection(node* head1,node* head2){
    int i=1;
    while(head1!=NULL){
        if(head1->next==head2->next){
            return head1->data;
        }
        i++;
        head1=head1->next;
    }
    return i;
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    node* first=new node(5);
    node* second=new node(8);
    node* third=new node(7);
    node* fourth=new node(10);
    node* fifth=new node(12);
    node* sixth=new node(15);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;
    node* aux=new node(9);
    head2=aux;
    aux->next=fourth;
    cout<<getintersection(head1,head2);
    return 0;
}
