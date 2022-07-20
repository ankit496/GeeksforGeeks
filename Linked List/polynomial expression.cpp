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
node* insertion(node* head,int newdata){
    node* newnode=new node(newdata);
    if(head==NULL){
        head=newnode;
        return head;
    }
    newnode->next=head;
    head=newnode;
    return head;
}
node* sum(node* head1,node* head2,int degree1,int degree2){
    node* head3=NULL;
    if(degree1==degree2){
        for(int i=degree1;i>=0;i--){
            int res=head1->data+head2->data;
            head3=insertion(head3,res);
            head1=head1->next;
            head2=head2->next;
        }
    }
    else if(degree1>degree2){
        for(int i=degree2;i>=0;i--){
            int res=head1->data+head2->data;
            head3=insertion(head3,res);
            head1=head1->next;
            head2=head2->next;
        }
        while(head1!=NULL){
            head3=insertion(head3,head1->data);
            head1=head1->next;
        }
    }
    else{
        for(int i=degree1;i>=0;i--){
            int res=head1->data+head2->data;
            head3=insertion(head3,res);
            head1=head1->next;
            head2=head2->next;
        }
        while(head2!=NULL){
            head3=insertion(head3,head2->data);
            head2=head2->next;
        }
    }
    return head3;
}
node* difference(node* head1,node* head2,int degree1,int degree2){
    node* head3=NULL;
    if(degree1==degree2){
        for(int i=degree1;i>=0;i--){
            int res=head1->data-head2->data;
            head3=insertion(head3,res);
            head1=head1->next;
            head2=head2->next;
        }
    }
    else if(degree1>degree2){
        for(int i=degree2;i>=0;i--){
            int res=head1->data-head2->data;
            head3=insertion(head3,res);
            head1=head1->next;
            head2=head2->next;
        }
        while(head1!=NULL){
            head3=insertion(head3,head1->data);
            head1=head1->next;
        }
    }
    else{
        for(int i=degree1;i>=0;i--){
            int res=head1->data-head2->data;
            head3=insertion(head3,res);
            head1=head1->next;
            head2=head2->next;
        }
        while(head2!=NULL){
            head3=insertion(head3,-(head2->data));
            head2=head2->next;
        }
    }
    return head3;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    int degree1=0,degree2=0;
    cout<<"Enter the degree of the Expression 1:-";
    cin>>degree1;
    //creating that much amount of nodes
    cout<<"Expression 1:-"<<endl;
    for(int i=degree1;i>=0;i--){
        int newdata;
        cout<<"Enter the coefficient of x^"<<i<<":-";
        cin>>newdata;
        head1=insertion(head1,newdata);
    }
    cout<<"Enter the degree of the Expression 2:-";
    cin>>degree2;
    cout<<"Expression 2:-"<<endl;
    for(int i=degree2;i>=0;i--){
        int newdata;
        cout<<"Enter the coefficient of x^"<<i<<":-";
        cin>>newdata;
        head2=insertion(head2,newdata);
    }
    node* head3=sum(head1,head2,degree1,degree2);
    int deg=degree1>degree2?degree1:degree2;
    for(int i=deg;i>=0;i--){
        if(i==0){
            cout<<head3->data;
        }
        else{
            cout<<head3->data<<"x^"<<i<<"+";
            //head3=head3->next;
        }
        head3=head3->next;
    }
    /*node* head4=difference(head1,head2,degree1,degree2);.

    for(int i=deg;i>=0;i--){
        if(i==0){
            cout<<head4->data;
        }
        else{
            cout<<head4->data<<"x^"<<i<<"-";
            //head3=head3->next;
        }
        head4=head4->next;
    }*/
    return 0;
}
