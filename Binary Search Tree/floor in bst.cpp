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
vector<int> v;
void floor(node* root,int x){
    if(root!=NULL){
        if(root->data<=x)
            v.push_back(root->data);
        floor(root->left,x);
        floor(root->right,x);
    }
}
node* flr(node* root,int x){
    node* floor=NULL;
    while(root!=NULL){
        if(root->data==x)
            return root;
        else if(root->data>x)
            root=root->left;
        else{
            floor=root;
            root=root->right;
        }
    }
    return floor;
}
int main(){
    node* root=NULL;
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,12);
    root=insert(root,30);
    display(root);
    floor(root,30);
    int res=-1;
    for(int i=0;i<v.size();i++){
        res=max(res,v[i]);
    }
    cout<<endl<<res<<endl;
    node* f=flr(root,14);
    cout<<f->data;
    return 0;
}
