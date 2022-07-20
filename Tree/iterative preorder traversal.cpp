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
void preorderIteration(node* root){
    stack<node*> st;
    st.push(root);
    while(st.empty()==false){
        node* curr=st.top();
        cout<<curr->key<<" ";
        st.pop();
        if(curr->right!=NULL)
            st.push(curr->right);
        if(curr->left!=NULL)
            st.push(curr->left);
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->left=new node(60);
    preorderIteration(root);
    return 0;
}
