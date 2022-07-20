#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a,int b){
    int res;
    res=min(a,b);
    while(res>0){
        if(a%res==0&&b%res==0)
            return res;
        res--;
    }
    return res;
}
//using Euclidean Algorithm
int GCD(int a,int b){
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else
            b=b-a;
    }
    return a;
}
//optimized algorithm
int g(int a,int b){
    if(b==0)
        return a;
    else
        return g(b,a%b);
}
int main(){
    cout<<gcd(12,15)<<endl;
    cout<<gcd(12,15)<<endl;
    cout<<gcd(12,15)<<endl;
    return 0;
}
