#include<iostream>
using namespace std;
int normal_max(int a[],int n){
    int res=0;
    int maxending=a[0];
    for(int i=1;i<n;i++){
        maxending=max(maxending+a[i],a[i]);
        res=max(maxending,res);
    }
    return res;
}
int circular_max(int a[],int n){
    int res=0;
    int sum=a[0];
    int maxending=a[0];
    for(int i=1;i<n;i++){
        maxending=min(maxending+a[i],a[i]);
        res=min(maxending,res);
        sum+=a[i];
    }
    res=sum-res;
    return res;
}
int maxcircularsum(int a[],int n){
    int res=a[0];
    for(int i=0;i<n;i++){
        int cur_max=a[i];
        int cur_sum=a[i];
        for(int j=1;j<n;j++){
            int index=(i+j)%n;
            cur_sum+=a[index];
            cur_max=max(cur_max,cur_sum);
        }
        res=max(res,cur_max);
    }
    return res;
}
int main(){
    int a[]={5,-2,3,4};
    int nres=normal_max(a,4);
    int cres=circular_max(a,4);
    cout<<cres;
    cout<<endl<<maxcircularsum(a,4);
    return 0;
}
