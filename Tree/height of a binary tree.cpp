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
int height(node* root){
    if(root!=NULL){
        return max(height(root->left),height(root->right))+1;
    }
    return 0;
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    node* root2=NULL;
    cout<<height(root);
    return 0;
}
