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
int maxlevel=0;
void printLeft(node* root,int level){
    if(root==NULL)
        return;
    if(maxlevel<level){
        cout<<root->key<<" ";
        maxlevel=level;
    }
    printLeft(root->left,level+1);
    printLeft(root->right,level+2);

}
void printleft(node* root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
            node* curr=q.front();
            q.pop();
            if(i==0)
                cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->right=new node(70);
    printLeft(root,1);
    cout<<endl;
    printleft(root);
    return 0;
}
