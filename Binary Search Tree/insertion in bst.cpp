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
bool search(node* root,int key){
    while(root!=NULL){
        if(root->key==key)
            return true;
        else if(key>root->key)
            root=root->right;
        else
            root=root->left;
    }
    return false;
}
node* insert(node* root,int value){
    node* newnode=new node(value);
    if(root==NULL){
        root=newnode;
    }
    else{
        if(search(root,value)==true)
            return root;
        while(root->left!=NULL||root->right!=NULL){
            if(value>root->key)
                root=root->right;
            else if(value<root->key)
                root=root->left;
        }
        if(root->key>value)
            root->left=newnode;
        else
            root->right=newnode;
    }
    return root;
}
node* insertinbst(node* root,int x){
    if(root!=NULL)
        return new node(x);
    else if(root->key<x)
        root->right=insert(root->right,x);
    else if(root->key>x)
        root->left=insert(root->left,x);
    return root;
}
node* in(node* root,int x){
    node* temp=new node(x);
    node* parent=NULL,*curr=root;
    while(curr!=NULL){
        parent=curr;
        if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else
            return root;
    }
    if(parent==NULL)
        return temp;
    if(parent->key>x)
        parent->left=temp;
    else
        parent->right=temp;
}
void display(node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        display(root->left);
        display(root->right);
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(5);
    root->right=new node(15);
    //root->left->left=new node(12);
    //root->left->right=new node(18);
    root->right->left=new node(12);
    root->right->right=new node(18);
    display(root);
    //insert(root,16);
    cout<<endl;
    cout<<endl;
    //root=insertinbst(root,16);
    in(root,16);
    display(root);
    return 0;
}
