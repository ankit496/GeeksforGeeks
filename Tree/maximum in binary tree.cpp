#include<iostream>
#include<cmath>
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
int maximum=0;
int getmax(node* root){
    if(root==NULL)
        return maximum;
    else{
        getmax(root->left);
        maximum=max(maximum,root->key);
        getmax(root->right);
    }
}
//or
int getMax(node* root){
    if(root==NULL)
        return -1;
    else{
        return max(root->key,max(getMax(root->left),getMax(root->right)));
    }
}
int main(){
    node* root=new node(1000);
    root->left=new node(80);
    root->right=new node(70);
    root->left->left=new node(30);
    root->left->right=new node(40);
    node* root2=NULL;
    cout<<getmax(root);
    return 0;
}
