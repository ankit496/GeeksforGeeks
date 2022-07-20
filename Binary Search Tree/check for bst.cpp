#include<iostream>
#include<climits>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
int maximum(node* root){
    if(root==NULL)
        return INT_MIN;
    int res=root->data;
    int lres=maximum(root->left);
    int rres=maximum(root->right);
    return max(res,max(lres,rres));
}
int minimum(node* root){
    if(root==NULL)
        return INT_MAX;
    int res=root->data;
    int lres=minimum(root->left);
    int rres=minimum(root->right);
    return min(res,min(lres,rres));
}
bool check_bst(node* root){
    if(root==NULL)
        return true;
    if(root->left!=NULL&&maximum(root->left)>=root->data)
        return false;
    if(root->right!=NULL&&minimum(root->right)<=root->data)
        return false;
    if(!check_bst(root->left)||!check_bst(root->right))
        return false;
    return true;
}
bool is_bst(node* root,int lower_bound,int upper_bound){
    if(root==NULL)
        return true;
    return (root->data>lower_bound&&root->data<upper_bound&&is_bst(root->left,lower_bound,root->data)&&is_bst(root->right,root->data,upper_bound));
}
//using inorder traversal
//int prev=INT_MIN;
bool isBST(node* root,int *prev){
    if(root==NULL)
        return true;
    if(isBST(root->left,prev)==false)
        return false;
    if(root->data<=*prev)
        return false;
    *prev=root->data;
    return isBST(root->right,prev);
}
int main(){
    node* root=new node(20);
    root->left=new node(8);
    root->right=new node(30);
    root->right->right=new node(35);
    root->right->left=new node(9);
    cout<<check_bst(root)<<endl;
    cout<<is_bst(root,-9999,9999)<<endl;
    int prev=INT_MIN;
    cout<<isBST(root,&prev);
    return 0;
}
