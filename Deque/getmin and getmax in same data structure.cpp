#include<iostream>
#include<deque>
using namespace std;
struct myds{
   deque<int> d;
   void insertMin(int x){
        d.push_front(x);
   }
   void insertMax(int x){
        d.push_back(x);
   }
   int getMin(){
        return d.front();
   }
   int getMax(){
        return d.back();
   }
};
int main(){
    myds s;
    s.insertMin(5);
    s.insertMax(10);
    s.insertMin(5);
    s.insertMax(10);
    s.insertMin(2);
    cout<<s.getMin();
    cout<<endl<<s.getMax();
    return 0;
}
