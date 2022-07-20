#include<iostream>
using namespace std;
int counttrailingzeroes(int n){
    int res=0;
    for(int i=5;i<=n;i=i*5)
        res=res+n/i;
    return res;
}
int main(){
    //just count the number of 5 in the prime factorization
    int num;
    cout<<"Enter the number"<<endl;
    cin>>num;
    cout<<"The number of trailing zeros will be "<<counttrailingzeroes(num)<<endl;
    return 0;
}
