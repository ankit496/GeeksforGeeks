#include<iostream>
using namespace std;
struct deque{
    int cap;
    int size;
    int* a;
    deque(int c){
        cap=c;
        size=0;
        a=new int(c);
    }
    bool isFull(){
        return (cap==size);
    }
    bool isEmpty(){
        return (size==0);
    }
    void insertFront(int x){
        if(isFull())
            return;
        for(int i=size-1;i>=0;i--)
            a[i+1]=a[i];
        a[0]=x;
        size++;
    }
    void insertRear(int x){
        if(isFull())
            return;
        size++;
        a[size]=x;
    }
    void deleteRear(){
        if(isEmpty())
            return;
        size--;
    }
    void deleteFront(){
        if(isEmpty())
            return;
        for(int i=1;i<size;i++)
            a[i-1]=a[i];
    }
    int getFront(){
        return a[0];
    }
    int getRear(){
        return a[size];
    }
};
int main(){
    deque q(5);
    q.insertFront(5);
    q.insertFront(6);
    q.insertRear(7);
    cout<<q.getFront()<<" ";
    q.deleteFront();
    cout<<q.getFront()<<" ";
    return 0;
}
