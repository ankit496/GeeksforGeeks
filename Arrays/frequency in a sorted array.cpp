#include<iostream>
using namespace std;
void frequency(int a[],int n){
    int freq=1,i=1;
    while(i<n){
        while(i<n&&a[i]==a[i-1]){
            freq++;
            i++;
        }
        cout<<a[i-1]<<":-"<<freq<<endl;
        i++;
        freq=1;
    }
    if(n==1||a[n-1]!=a[n-2])
        cout<<a[n-1]<<":-"<<1;
}
void freq(int a[],int n){
    int visited_a[n],frequency;
    for(int i=0;i<n;i++){
        visited_a[i]=0;
    }
    for(int i=0;i<n;i++){
        if(visited_a[i]==0){
            for(int j=0;j<n;j++){
                if(a[i]==a[j]){
                    frequency++;
                    visited_a[j]=1;
                }
            }
            printf("The frequency of the element %d is %d\n",a[i],frequency);
            frequency=0;
        }
    }
}
int main(){
    int a[]={10,10,10,30,30,40};
    frequency(a,6);
    freq(a,6);
    return 0;
}
