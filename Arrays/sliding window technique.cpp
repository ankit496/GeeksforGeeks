#include<iostream>
using namespace std;
int maxs(int a[],int k,int n){
    int maxsum=0;
    for(int i=0;i<=n-k;i++){
        int sum=0;
        for(int j=i;j<k+i;j++){
            sum=sum+a[j];
        }
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}
//using window sliding technique
int maxgivensum(int a[],int k,int n){
    int maxsum=0,cursum=0;
    for(int i=0;i<k;i++){
        cursum+=a[i];
    }
    maxsum=max(maxsum,cursum);
    for(int j=k;j<n;j++){
        cursum+=(a[j]-a[j-k]);
        maxsum=max(maxsum,cursum);
    }
    return maxsum;
}
int givensum(int a[],int gsum,int n){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[i];
        }
        if(sum==gsum)
            return 1;
    }
    return 0;
}
int main(){
    int a[]={1,8,30,-5,20,7};
    cout<<maxgivensum(a,3,6)<<endl;
    cout<<givensum(a,45,6);
    return 0;
}
