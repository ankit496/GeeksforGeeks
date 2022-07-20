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
bool search(node* root,int value){
    if(root==NULL)
        return false;
    else if(root->key==value)
        return true;
    else if(value>root->key)
        search(root->right,value);
    else if(value<root->key)
        search(root->left,value);
}
bool search2(node* root,int key){
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
int main(){
    node* root=new node(50);
    root->left=new node(30);
    root->right=new node(70);
    root->left->left=new node(10);
    root->left->right=new node(40);
    root->right->left=new node(60);
    root->right->right=new node(80);
    cout<<search(root,85);
    cout<<search2(root,50);
    return 0;
}
