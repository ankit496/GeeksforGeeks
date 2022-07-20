#include<iostream>
using namespace std;
/*struct queue{
    int *a;
    int cap,size;
    int front,rear;
    queue(int c){
        cap=c;
        size=0;
        front=0;
        rear=0;
        a=new int[cap];
    }
    void enque(int x){
        rear++;
        a[rear]=x;
        size++;
    }
    int deque(){
        int x=a[front];
        front=front+1;
        return x;
        size++;
    }
    int getsize(){
        return size;
    }
    int getfront(){
        return a[front];
    }
    int getrear(){
        return a[rear];
    }
    bool isFull(){
        if(rear==cap)
            return true;
        else
            return false;
    }
    bool isEmpty(){
        if(front==-1)
            return true;
        else
            return false;
    }
};*/
//using circular array
//front=(front+1)%cap;
//rear=(front+size-1)%cap

struct queue{
    int *a;
    int front,cap,size;
    queue(int c){
        a=new int(c);
        cap=c;
        front=0;
        size=0;
    }
    bool isFull(){
        return (cap==size);
    }
    bool isEmpty(){
        return (size==0);
    }
    int getfront(){
        if(isEmpty())
            return -1;
        else
            return front;
    }
    int getrear(){
        if(isEmpty())
            return -1;
        else
            return (front+size-1)%cap;
    }
    void enque(int x){
        if(isFull())
            return;
        int rear=getrear();
        rear=(rear+1)%cap;
        a[rear]=x;
        size++;
    }
    void deque(){
        if(isEmpty()) return;
        front=(front+1)%cap;
        size--;
    }
};
int main(){
    queue q(5);
    q.enque(5);
    q.enque(6);
    q.enque(7);
    q.enque(8);
    q.deque();
    return 0;
}
