#include<iostream>
#include<vector>
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
node* insert(node* root,int x){
    if(root==NULL){
        return new node(x);
    }
    else if(x>root->data){
        root->right=insert(root->right,x);
    }
    else
        root->left=insert(root->left,x);
    return root;
}
void display(node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
    }
}
node* ceil(node* root,int x){
    node* curr=NULL;
    while(root!=NULL){
        if(root->data==x){
            return root;
        }
        else if(x>root->data){
            root=root->right;
        }
        else{
            curr=root;
            root=root->left;
        }
    }
    return curr;
}

int main(){
    node* root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,78);
    root=insert(root,55);
    root=insert(root,65);
    display(root);
    node* f=ceil(root,63);
    cout<<f->data;
    return 0;
}

