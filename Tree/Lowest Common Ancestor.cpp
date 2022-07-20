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
bool ancestors(node* root,vector<int> &v,int n){
    if(root==NULL)
        return false;
    v.push_back(root->key);
    if(root->key==n)
        return true;
    if(ancestors(root->left,v,n)||ancestors(root->right,v,n))
        return true;
    v.pop_back();
    return false;
}
int lca(node* root,int n1,int n2){
    vector<int> path1,path2;
    if(ancestors(root,path1,n1)==false||ancestors(root,path2,n2)==false)
        return -1;
    for(int i=0;i<path1.size()-1&&i<path2.size()-1;i++)
        if(path1[i+1]!=path2[i+1])
            return path1[i];
    return -1;
}
int main(){
    node* root=new node(3);
    root->left=new node(4);
    root->left->left=new node(5);
    root->left->right=new node(9);
    root->right=new node(8);
    root->right->right=new node(7);
    root->right->left=new node(6);
    cout<<lca(root,9,6);
    return 0;
}
