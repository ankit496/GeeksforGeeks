#include<iostream>
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
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->right=new node(40);
    return 0;
}
