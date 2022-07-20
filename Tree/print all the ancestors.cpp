#include<iostream>
#include<vector>
using namespace std;
struct node{
    int key;
    node* left;
    node* right;
    node(int x){
        left=NULL;
        right=NULL;
        key=x;
    }
};
vector<int> v;
bool ancestors(node* root,int n){
    if(root==NULL)
        return false;
    v.push_back(root->key);
    if(root->key==n)
        return true;
    if(ancestors(root->left,n)||ancestors(root->right,n))
        return true;
    v.pop_back();
    return false;
}
int main(){
    node* root=new node(3);
    root->left=new node(4);
    root->left->left=new node(5);
    root->left->right=new node(9);
    root->right=new node(8);
    root->right->right=new node(7);
    root->right->left=new node(6);
    cout<<ancestors(root,6);
    cout<<endl;

    for(int i=0;i<v.size()-1;i++)
        cout<<v[i]<<" ";
    return 0;
}
