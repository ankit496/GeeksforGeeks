#include<iostream>
using namespace std;

struct queue{
    int size,cap;
    int *arr;
    queue(int d){
        cap=d;
        size=0;
        arr=new int(cap);
    }
    bool isFull(){return (size==cap);}
    bool isEmpty(){return (size==0);}
    void enque(int x){
        if(isFull()) return;
        arr[size]=x;
        size++;
    }
    void deque(){
        if(isEmpty()) return;
        for(int i=0;i<size-1;i++)
            arr[i]=arr[i-1];
        size--;
    }
    int getfront(){
        if(isEmpty())
            return -1;
        else
            return 0;
    }
    int getRear(){
        if(isEmpty())
            return -1;
        else
            return size-1;
    }
};
int main(){
    queue q(5);
    q.enque(5);
    q.enque(10);
    q.enque(15);
    q.enque(10);
    q.enque(10);
    q.enque(10);
    cout<<q.getfront();
    q.deque();
    cout<<q.getfront();
    q.deque();
    cout<<q.getfront();

    return 0;
}
