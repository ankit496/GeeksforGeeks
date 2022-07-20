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
struct node* getSuccessor(node* cur){
    while(cur!=NULL||cur->left!=NULL)
        cur=cur->left;
    return cur;
}
struct node* delNode(node* root,int x){
    if(root==NULL)
        return root;
    if(root->key<x)
        root->left=delNode(root->left,x);
    else if(root->key>x)
        root->right=delNode(root->right,x);
    else{
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            node* succ=getSuccessor(root);
            printf("%d ",succ->key);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
}
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
node* in(node* root,int x){
    if(root==NULL)
        return new node(x);
    else if(root->key<x)
        root->right=in(root->right,x);
    else if(root->key>x)
        root->left=in(root->left,x);
    return root;
}
void display(node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        display(root->left);
        display(root->right);
    }
}
int main(){
    node* root=NULL;
    root=in(root,50);
    root=in(root,30);
    root=in(root,70);
    root=in(root,10);
    root=in(root,40);
    root=in(root,60);
    root=in(root,80);
    display(root);
    cout<<endl;
    root=delNode(root,10);
    display(root);
    return 0;
}
