#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
int isEmpty(){
    if(head==NULL)
        return 1;
    else
        return 0;
}
void push(int d){
    //inserting the node at the beginning
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
int pop(){
    //deleting the head node;
    if(isEmpty())
        return -1;
    struct node* del=head;
    int data=head->data;
    head=head->next;
    free(del);
    return data;
}

int peek(){
    if(isEmpty())
        return -1;
    return head->data;
}

struct node* front=NULL;
struct node* rear=NULL;
void enque(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    return;
}
int deque(){
    if(front==NULL)
        return -1;
    int t;
    t=front->data;
    struct node* temp=front;
    front=front->next;
    free(temp);
    return t;
}
int isempty(){
    if(front==NULL)
        return 1;
    else
        return 0;
}
int getFront(){
    if(front==NULL)
        return -1;
    else
        return front->data;
}
int getRear(){
    if(front==NULL)
        return -1;
    else
        return rear->data;
}
int size(){
    struct node* t=front;
    int s=0;
    while(t!=NULL){
        t=t->next;
        s++;
    }
    return s;
}
int allSame(){
    int a[6];
    struct node* t=front;
    int i=0;
    while(t!=NULL){
        a[i++]=t->data;
        t=t->next;
    }
    for(int j=1;j<=i;j++){
        if(a[j]!=a[j-1])
            return 0;
        else
            return 1;
    }

}
int number_of_remaining_students(int sandwiches[],int students[],int n){
    for(int i=0;i<n;i++){
        push(sandwiches[i]);
        enque(students[i]);
    }
    while(isEmpty()==0&&allSame==0){
        if(peek()==getFront()){
            pop();
            deque();
        }
        else{
            int x=getFront();
            deque();
            enque(x);
        }
    }
    struct node* t=head;
    int s=0;
    while(t!=NULL){
        t=t->next;
        s++;
    }
    printf("%d ",s);
    return s;
}

void reverse(int *a,int n){
    int low=0,high=n-1;
    while(low<high){
        int t;
        t=a[low];
        a[low]=a[high];
        a[high]=t;
        low++;
        high--;
    }
}
int main(){
    int sandwiches[6]={1,1,0,0};
    int students[6]={0,1,0,1};
    reverse(sandwiches,4);
    printf("%d ",number_of_remaining_students(sandwiches,students,4));
    return 0;
}
