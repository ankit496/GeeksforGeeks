#include<iostream>
#include<stack>
using namespace std;
struct node{
    char data;
    node* next;
    node(char d){
        data=d;
        next=NULL;
    }
};
struct mystack{
    node* head;
    int size_of_stack;
    mystack(){
        head=NULL;
        size_of_stack=0;
    }
    void push(char x){
        node* newnode=new node(x);
        newnode->next=head;
        head=newnode;
        size_of_stack++;
    }
    char pop(){
        if(head==NULL)
            return -1;
        int res=head->data;
        node* del=head;
        head=head->next;
        delete(del);
        size_of_stack--;
        return res;
    }
    int size(){
        return size_of_stack;
    }
    bool isempty(){
        return size_of_stack==-1;
    }
    char peek(){
        if(head==NULL)
            return -1;
        return head->data;
    }
};
bool check(char s1,char s2){
    if(s1=='('&&s2==')')
        return false;
    else if(s1=='{'&&s2=='}')
        return false;
    else if(s1=='['&&s2==']')
        return false;
    else
        return true;
}
bool check_paranthesis(string s,mystack stack){
    int i=0;
    int len=s.length();
    if(len%2!=0)
        return false;
    else{
        len=len/2;
        while(i<len){
            char t1=s[i];
            char t2=stack.pop();
            cout<<t1<<" "<<t2<<endl;
            if(check(t1,t2))
                return false;
            i++;
        }
        return true;
    }
}
//another way of solving it
bool matching(char a,char b){
    return (a=='('&&b==')'||a=='{'&&b=='}'||a=='['&&b==']');
}
bool isbalanced(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            st.push(s[i]);
        else{
            if(st.empty())
                return false;
            else if(matching(st.top(),s[i])==false)
                return false;
            else
                st.pop();
        }
    }
    return (st.empty()==true);
}
int main(){
    string s="{([])}";
    mystack stack;
    int i=0;
    while(s[i]!='\0'){
        stack.push(s[i]);
        i++;
    }
    cout<<check_paranthesis(s,stack);
    cout<<isbalanced(s);
    return 0;
}
