#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
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
/*
void inorder_creation(node* root,vector<int> &in){
    if(root!=NULL){
        inorder_creation(root->left,in);
        in.push_back(root->key);
        inorder_creation(root->right,in);
    }
}
void preorder_creation(node* root,vector<int> &pre){
    if(root!=NULL){
        pre.push_back(root->key);
        preorder_creation(root->left,pre);
        preorder_creation(root->right,pre);
    }
}

void serialize(node* root,vector<int> &in,vector<int> &pre)
{
    inorder_creation(root,in);
    preorder_creation(root,pre);
}
int preIndex=0;
node* convert(vector<int> in,vector<int> pre,int is,int ie){
    if(is>ie)
        return NULL;
    node* root=new node(pre[preIndex++]);
    int inIndex=0;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->key){
            inIndex=i;
            break;
        }
    }
    convert(in,pre,is,inIndex-1);
    convert(in,pre,inIndex+1,ie);
    return root;
}
node* deSerialize(vector<int> &in,vector<int> &pre){
    node* root=convert(in,pre,0,in.size()-1);
    return root;
}*/
const int empty=-1;
void serialize(node* root,vector<int> &a){
    if(root==NULL){
        a.push_back(empty);
        return;
    }
    a.push_back(root->key);
    serialize(root->left,a);
    serialize(root->right,a);
}
int i=0;
node* deserialize(vector<int> &a){
    if(i==a.size())
        return NULL;
    int val=a[i];
    i++;
    if(val==empty)
        return NULL;
    node* curr=new node(val);
    curr->left=deserialize(a);
    curr->right=deserialize(a);
    return curr;
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->right=new node(60);
    root->right->left=new node(70);
    root->left->left->left=new node(80);
    root->left->left->right=new node(90);
    root->left->right->left=new node(100);
    vector<int> in;
    vector<int> pre;
    vector<int> a;
    serialize(root,a);
    node* r=deserialize(a);
    cout<<r->key;

    return 0;
}
