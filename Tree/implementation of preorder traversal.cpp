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
void preorder_traversal(node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    preorder_traversal(root);
    return 0;
}
