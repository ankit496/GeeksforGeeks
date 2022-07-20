#include<iostream>
#include<vector>
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
int res=0;
int burnTree(node* root,int leaf,int &dist){
    if(root==NULL)
        return 0;
    if(root->key==leaf){
        dist=0;
        return 1;
    }
    int ldist=-1,rdist=-1;
    int lh=burnTree(root->left,leaf,ldist);
    int rh=burnTree(root->right,leaf,rdist);
    if(ldist!=-1){
        dist=ldist+1;
        res=max(res,dist+rh);
    }
    else if(rdist!=-1){
        dist=rdist+1;
        res=max(res,dist+lh);
    }
    return max(lh,rh)+1;
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->left->right=new node(5);
    root->left->left=new node(30);
    root->left->left->right=new node(50);
    root->left->left->left=new node(40);
    root->left->left->left->left=new node(60);
    root->left->left->left->left->left=new node(70);
    int dist=burnTree(root,50,dist);
    cout<<dist;
    return 0;
}
