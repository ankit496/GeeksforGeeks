#include<iostream>
using namespace std;
int majority_element(int a[],int n){
    int freq=1,index=-1,occurence=n/2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j])
                freq++;
        }
        if(freq>occurence)
            index=i;
        else
            freq=1;
    }
    return index;
}
//Moore's Voting Algorithm
int findmajority(int a[],int n){
    int res=0,cnt=1;
    for(int i=1;i<n;i++){
        if(a[res]==a[i])
            cnt++;
        else
            cnt--;
        if(cnt==0){
            res=i;
            cnt=1;
        }
    }
    cnt=0;
    for(int i=0;i<n;i++){
        if(a[res]==a[i])
            cnt++;
    }
    if(cnt<=n/2)
        res=-1;
    return res;
}
int main(){
    int a[]={20,30,40,50,50,50,50};
    cout<<majority_element(a,7);
    cout<<endl<<findmajority(a,7);
    return 0;
}
