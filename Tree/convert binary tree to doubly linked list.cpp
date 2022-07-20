#include<iostream>
using namespace std;
struct node{
    int key;
    node* left;
    node* right;
    node(int x){
        key=x;
        left=NULL;
        right=NULL;
    }
};
node* p=NULL;
node* converttodl(node* root){
    if(root==NULL)
        return NULL;
    node* head=converttodl(root->left);
    if(p==NULL)
        head=p;
    else{
        root->left=p;
        p->right=root;
    }
    p=root;
    converttodl(root->right);
    return head;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->key<<" ";
        head=head->right;
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    node* head=converttodl(root);
    display(head);
    return 0;
}
