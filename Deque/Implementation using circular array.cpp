#include<iostream>
using namespace std;
struct deque{
    int *a;
    int front,cap,size;
    deque(int c){
        a=new int(c);
        cap=c;
        front=0;
        size=0;
    }
    void insertRear(int x){
        int rear=(front+size-1)%cap;
        rear=(rear+1)%cap;
        size++;
        a[rear]=x;
    }
    void insertFront(int x){
        front=(front-1+cap)%cap;
        size++;
        a[front]=x;
    }
    int getFront(){
        return a[front];
    }
    int getRear(){
        int rear=(front+size-1)%cap;
        return a[rear];
    }
    int deleteFront(){
        int x=a[front];
        front=(front+1)%cap;
        return x;
    }
    int deleteRear(){
        int rear=(front+size-1)%cap;
        int x=a[rear];
        rear=(rear-1+cap)%cap;
        return x;
    }
};
int main(){
    deque q(5);
    q.insertRear(5);
    q.insertRear(10);
    q.insertFront(15);
    q.insertFront(10);
    q.insertRear(10);
//    q.enque(10);
    cout<<q.getFront();
    q.deleteFront();
    cout<<q.getFront();
    q.deleteRear();
    cout<<q.getFront();

    return 0;
}

