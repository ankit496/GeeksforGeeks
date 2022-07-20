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

void roots_at_k(node* root,int k){
    if(root==NULL)
        return;
    if(k==1){
        cout<<root->key<<" ";
        return;
    }
    else{
        roots_at_k(root->left,k-1);
        roots_at_k(root->right,k-1);
    }
}
void print(int n,int k1){
    if(k1==1){
        cout<<k1<<" ";
        return;
    }
    print(n,k1--);
    print(n,k1--);
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->right=new node(70);
    roots_at_k(root,2);
    //print(2,2);
    return 0;
}
