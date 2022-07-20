#include<iostream>
using namespace std;
int maxdifference(int a[],int n){
    int max_difference=-999;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int difference=a[j]-a[i];
            if(difference>max_difference)
                max_difference=difference;
        }
    }
    return max_difference;
}
int maxd(int a[],int n){
    int res=a[1]-a[0],minval=a[0];
    for(int j=1;j<n;j++){
        res=max(res,a[j]-minval);
        minval=min(minval,a[j]);
    }
    return res;
}
int main(){
    int a[]={30,10,8,2};
    cout<<maxdifference(a,4);
    cout<<endl<<maxd(a,4);
    return 0;
}
