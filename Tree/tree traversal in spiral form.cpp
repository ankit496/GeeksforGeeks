#include<iostream>
#include<queue>
#include<stack>
#include<deque>
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
bool even(int n){
    return n%2==0;
}
void display(node* root){
    if(root==NULL)
        return;
    queue<node *>q;
    stack<int> s;
    bool reverse=false;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
            node* curr=q.front();
            q.pop();
            if(reverse)
                s.push(curr->key);
            else
                cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        if(reverse){
            while(s.empty()==false){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
        cout<<endl;
    }
}
//using a doubly ended queue
void display_spiral(node* root){
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);
    while(s1.empty()==false||s2.empty()==false){
        node* curr=NULL;
        while(s1.empty()==false){
            curr=s1.top();
            s1.pop();
            cout<<curr->key<<" ";
            if(curr->right)
                s2.push(curr->right);
            if(curr->left)
                s2.push(curr->left);
        }
        while(s2.empty()==false){
            curr=s2.top();
            s2.pop();
            cout<<curr->key<<" ";
            if(curr->right)
                s1.push(curr->right);
            if(curr->left)
                s1.push(curr->left);
        }
    }
}
int main(){
    node* root=new node(3);
    root->left=new node(4);
    root->left->left=new node(5);
    root->left->right=new node(9);
    root->right=new node(8);
    root->right->right=new node(7);
    root->right->left=new node(6);
    display(root);
    cout<<endl;
    display_spiral(root);
    return 0;
}
