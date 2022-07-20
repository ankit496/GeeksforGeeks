#include<iostream>
using namespace std;
int maxsum(int a[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<j;k++)
                sum=sum+a[k];
            res=max(res,sum);
        }
    }
    return res;
}
int maxSum(int a[],int n){
    int maxending=0;
    int res=a[0];
    for(int i=1;i<n;i++){
        maxending=max(maxending+a[i],a[i]);
        res=max(maxending,res);
    }
    return res;
}
int main(){
    int a[]={1,2,3,4,-5,6};
    cout<<maxsum(a,6)<<endl;
    cout<<maxSum(a,6);
    return 0;
}
