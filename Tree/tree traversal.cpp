#include<iostream>
using namespace std;
struct node{
    int key;
    node* left;
    node* right;
    node(int k){
        key=k;
        left=right=NULL;
    }
};
void inorder_display(node* root){
    if(root!=NULL){
        inorder_display(root->left);
        cout<<root->key<<" " ;
        inorder_display(root->right);
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->right=new node(40);
    inorder_display(root);
    return 0;
}
