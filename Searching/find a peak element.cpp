#include<iostream>
using namespace std;
int peak_element(int a[],int n){
    int peak=0;
    for(int i=0;i<n;i++){
        if(i==0&&a[i]>=a[i+1])
            peak=a[i];
        else if(i==n-1&&a[i]>=a[i-1])
            peak=a[i];
        else{
            if(a[i]>=a[i+1]&&a[i]>=a[i-1])
                peak=a[i];
        }
    }
    return peak;
}
int peak(int a[],int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid==0||a[mid]>=a[mid-1]&&mid==n-1||a[mid]>=a[mid+1])
            return mid;
        else if(a[mid]<a[mid-1])
            high=mid-1;
        else if(a[mid]<a[mid+1])
            low=mid+1;
    }
}
int main(){
    int a[]={90};
    cout<<peak_element(a,1);
    cout<<endl<<a[peak(a,1)];
    ;
    return 0;
}
