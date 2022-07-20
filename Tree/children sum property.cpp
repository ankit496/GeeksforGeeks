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
bool children_sum(node* root){
    if(root==NULL||root->left==NULL||root->right==NULL)
        return true;
    if(root->key==root->left->key+root->right->key){
        children_sum(root->left);
        children_sum(root->right);
    }
    else{
        return false;
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(8);
    root->right=new node(2);
    //root->left->left=new node(3);
    //root->left->right=new node(5);
    root->right->right=new node(2);
    if(children_sum(root)==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
