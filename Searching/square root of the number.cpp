#include<iostream>
using namespace std;
int square_root(int x){
    int low=0;
    int high=x;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid==x)
            return mid;
        else if(mid*mid>x)
            high=mid-1;
        else{
            low=mid+1;
            ans=mid;
        }
    }
    return ans;
}
int main(){
    int x=15;
    cout<<square_root(x);
    return 0;
}
