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
bool isBalanced(node* root){
    if(root==NULL)
        return true;
    int height_left=height(root->left);
    int height_right=height(root->right);
    if(abs(height_left-height_right)>=0&&abs(height_left-height_right)<=1){
        isBalanced(root->left);
        isBalanced(root->right);
    }
    else
        return false;
}
int Balanced(node* root){
    if(root==NULL)
        return 0;
    int lh=Balanced(root->left);
    if(lh==-1)
        return -1;
    int rh=Balanced(root->right);
    if(rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    return max(lh,rh)+1;
}
int main(){
    node* root=new node(3);
    root->left=new node(4);
    root->left->left=new node(5);
    root->left->right=new node(9);
    root->right=new node(8);
    root->right->right=new node(7);
    root->right->right->left=new node(6);
    cout<<isBalanced(root);
    cout<<Balanced(root);
    return 0;
}
