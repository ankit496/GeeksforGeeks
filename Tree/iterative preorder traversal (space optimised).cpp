#include<iostream>
#include<stack>
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
void printPreorder(node* root){
    stack<node*> st;
    st.push(root);
    node* curr=root;
    while(st.empty()==false||curr!=NULL){
        while(curr!=NULL){
            cout<<curr->key<<" ";
            if(curr->right!=NULL)
                st.push(curr->right);
            curr=curr->left;
        }
        if(st.empty()==false){
            curr=st.top();
            st.pop();
        }
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->left=new node(60);
    printPreorder(root);
    return 0;
}

