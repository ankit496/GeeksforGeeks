#include<iostream>
#include<vector>
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
node* lca(node* root,int n1,int n2){
    if(root==NULL)
        return NULL;
    if(root->key==n1||root->key==n2)
        return root;
    node* lca1=lca(root->left,n1,n2);
    node* lca2=lca(root->right,n1,n2);
    if(lca1!=NULL && lca2!=NULL)
        return root;
    if(lca1!=NULL)
        return lca1;
    else
        return lca2;
}
int main(){
    node* root=new node(3);
    root->left=new node(4);
    root->left->left=new node(5);
    root->left->right=new node(9);
    root->right=new node(8);
    root->right->right=new node(7);
    root->right->left=new node(6);
    node* t=lca(root,9,6);
    cout<<t->key;
    return 0;
}
