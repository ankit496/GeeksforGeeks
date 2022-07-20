#include<iostream>
using namespace std;
using namespace std;
void primefactors(int n){
    if(n<=1) return;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            cout<<i<<endl;
            n=n/i;
        }
    }
    if(n>1)
        cout<<n;
}
int main(){
    primefactors(12);
    return 0;
}
