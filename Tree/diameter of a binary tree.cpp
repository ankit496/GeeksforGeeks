#include<iostream>
using namespace std;
struct node{
    int key;
    node* left;
    node* right;
    node(int x){
        left=NULL;
        right=NULL;
        key=x;
    }
};
int height(node* root){
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}
int max_diameter(node* root){
    if(root==NULL)
        return 0;
    int d1=1+height(root->left)+height(root->right);
    int d2=max_diameter(root->left);
    int d3=max_diameter(root->right);
    return max(d1,max(d2,d3));
}
int main(){
    node* root=new node(3);
    root->left=new node(4);
    root->left->left=new node(5);
    root->left->right=new node(9);
    root->right=new node(8);
    root->right->right=new node(7);
    root->right->left=new node(6);
    cout<<max_diameter(root);
    return 0;
}
