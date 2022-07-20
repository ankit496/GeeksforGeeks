#include<iostream>
#include<queue>
#include<vector>
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
vector<int> size_of_tree(node* root){
    vector<int> v;
    if(root==NULL){
        return v;
    }
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        node* curr=q.front();
        q.pop();
        v.push_back(curr->key);
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
    return v;
}
//using recursion
int getsize(node* root){
    if(root==NULL)
        return 0;
    else{
        return 1+getsize(root->left)+getsize(root->right);
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(80);
    root->right=new node(70);
    root->left->left=new node(30);
    root->left->right=new node(40);
    node* root2=NULL;
    vector<int> v=size_of_tree(root);
    cout<<v.size()<<endl;
    cout<<getsize(root);
    return 0;
}
