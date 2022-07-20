#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    int lcount;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
        lcount=0;
    }
};
node* insert(node* root,int x){
    if(root==NULL)
        return new node(x);
    else if(x>root->data)
        root->right=insert(root->right,x);
    else{
        root->left=insert(root->left,x);
        root->lcount++;
    }
    return root;
}
int count=0;
void kth_smallest(node* root,int k){
    if(root!=NULL){
        kth_smallest(root->left,k);
        count++;
        if(count==k){
            cout<<root->data;
            return;
        }
        kth_smallest(root->right,k);
    }
}
void print_k(node* root,int k){
    if(root!=NULL){
        if(root->lcount+1==k)
            cout<<root->data;
        else if(root->lcount+1>k)
            print_k(root->left,k);
        else
            print_k(root->right,k-root->lcount-1);
    }
}
int main(){
    node* root=NULL;
    root=insert(root,50);
    root=insert(root,20);
    root=insert(root,10);
    root=insert(root,40);
    root=insert(root,100);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);
    root=insert(root,120);
    cout<<root->lcount<<" ";
    kth_smallest(root,3);
    cout<<endl;
    print_k(root,3);
    return 0;
}
