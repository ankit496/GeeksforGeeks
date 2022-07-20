#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
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
vector<int> v;
int count_nodes(node* root){
    if(root==NULL)
        return -1;
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        node* curr=q.front();
        v.push_back(curr->key);
        q.pop();
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
    return v.size();
}
int countnode(node* root){
    if(root==NULL)
        return 0;
    else
        return 1+countnode(root->left)+countnode(root->right);
}
int height_left(node* root){
    if(root==NULL)
        return 0;
    else
        return 1+height_left(root->left);
}
int height_right(node* root){
    if(root==NULL)
        return 0;
    else
        return 1+height_right(root->right);
}
int countNodes(node* root){
    int lh=height_left(root);
    int rh=height_right(root);
    if(lh==rh){
        return pow(2,lh)-1;
    }
    else
        return 1+countNodes(root->left)+countNodes(root->right);
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
    cout<<count_nodes(root)<<endl;
    cout<<countnode(root)<<endl;
    cout<<countNodes(root);
    return 0;
}
