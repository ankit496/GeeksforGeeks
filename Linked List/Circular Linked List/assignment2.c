#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
struct node{
    int data;
    struct node *next;
};
void deleteatbeg(struct node** head){
    struct node *temp;
    temp=*head;
    *head=(*head)->next;
    free(temp);
}
void deleteatend(struct node** head){
    struct node *temp;
    struct node *prev;
    temp=(*head)->next;
    prev=*head;
    while(temp->next!=NULL){
        temp=temp->next;
        prev=prev->next;
    }
    prev->next=NULL;
    free(temp);
}
void deleteatindex(struct node** head,int pos){
    int i=1;
    struct node* temp=*head;
    while(i!=pos-1){
        temp=temp->next;
        i++;
    }
    if(pos==1){
        deleteatbeg(head);
        return;
    }
    else if(temp->next==NULL){
        deleteatend(head);
        return;
    }
    else{
        struct node* del=temp->next;
        temp->next=temp->next->next;
        free(del);
        return;
    }
}
void insertatindex(struct node** head,int pos,int newdata){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    struct node* temp;
    temp=*head;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    else{
        if(pos==1){
            newnode->next=*head;
            *head=newnode;
            return;
        }
        else{
            int i=1;
            while(i!=pos-1){
                temp=temp->next;
                i++;
            }
            if(temp==NULL){
                printf("Position Out of Bound\n");
                return;
            }
            else{
                newnode->next=temp->next;
                temp->next=newnode;
                return;
            }
        }
    }
}
void print(struct node* t){
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
}
int main(){
    struct node* head=NULL;
    int pos=0,newdata=0;
    printf("1:-Insertion at Index\n2:-Deletion:\n\t1:From Beginning\n\t2:From End\n\t3:From a position\n3:-print\n4:-exit\n");
    while(1){
        int choice=0,choice2=0,pos2=0;
        printf("Enter the choice:-");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter the position:-");
            scanf("%d",&pos);
            printf("Enter the data:-");
            scanf("%d",&newdata);
            insertatindex(&head,pos,newdata);
            break;
        case 2:
            printf("Enter choice of deletion:-");
            scanf("%d",&choice2);
            switch(choice2){
            case 1:
                    deleteatbeg(&head);
                    break;
            case 2:
                    deleteatend(&head);
                    break;
            case 3:
                    printf("Enter the position:-");
                    scanf("%d",&pos);
                    deleteatindex(&head,pos2);
                    break;
            }
            break;
        case 3:
            print(head);
        case 4:
            exit(0);
        }
    }
    return 0;
}
