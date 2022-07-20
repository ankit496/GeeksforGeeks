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
void postorder_traversal(node* root){
    if(root!=NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout<<root->key<<" ";
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    postorder_traversal(root);
    return 0;
}
