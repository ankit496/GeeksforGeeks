#include<iostream>
#include<queue>
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
int height(node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return max(height(root->left),height(root->right))+1;
    }
}
void LOT(node* root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        roots_at_k(root,i);
    }
}
//using queue
void printLevel(node* root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        cout<<q.front()->key<<" ";
        node* cur=q.front();
        q.pop();
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->right=new node(70);
    LOT(root);
    cout<<endl;
    printLevel(root);
    return 0;
}
