#include<iostream>
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
void preorder_traversal(node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
int preindex=0;
node* convert(int in[],int pre[],int is,int ie){
    if(is>ie){
        return NULL;
    }
    node* root=new node(pre[preindex++]);
    int inIndex=0;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->key){
            inIndex=i;
            break;
        }
    }
    root->left=convert(in,pre,is,inIndex-1);
    root->right=convert(in,pre,inIndex+1,ie);
    return root;
}
int main(){
    int in[]={20,10,40,30,50};
    int pre[]={10,20,30,40,50};
    node* root=convert(in,pre,0,4);
    preorder_traversal(root);
    return 0;
}
