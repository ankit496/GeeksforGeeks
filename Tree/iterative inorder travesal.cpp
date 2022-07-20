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
void printTraversal(node* root){
    stack<node*> st;
    node* curr=root;
    while(curr!=NULL||st.empty()==false){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->left=new node(60);
    printTraversal(root);
    return 0;
}

