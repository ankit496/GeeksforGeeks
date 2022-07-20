#include<iostream>
using namespace std;
struct twostack{
    int *arr;
    int top1;
    int top2;
    int cap;
    twostack(int size){
        cap=size;
        arr=new int[cap];
        top1=-1;
        top2=size;
    }
    void push1(int data){
        top1++;
        if(top1>=top2){
            cout<<"overflow"<<endl;
            return;
        }
        arr[top1]=data;
    }
    void push2(int data){
        top2--;
        if(top1>=top2){
            cout<<"overflow"<<endl;
            return;
        }
        arr[top2]=data;
    }
    int pop1(){
        if(top1==-1){
            cout<<"underflow"<<endl;
            return -1;
        }
        return arr[top1--];
    }
    int pop2(){
        if(top2==cap){
            cout<<"underflow"<<endl;
            return -1;
        }
        return arr[top2++];
    }
    int size1(){return top1+1;}
    int size2(){return top2-1;}
};
int main(){
    twostack s(10);
    s.push1(4);
    s.push1(5);
    s.push1(6);
    s.push1(7);
    s.push1(8);
    s.push2(2);
    s.push2(3);
    s.push2(4);
    s.push2(5);
    s.push2(6);
    s.push2(11);
    s.push1(13);
    cout<<s.pop1()<<endl;
    cout<<s.pop2()<<endl;
    return 0;
}
