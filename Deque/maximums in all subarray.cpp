#include<iostream>
#include<deque>
using namespace std;
void printMax(int a[],int n,int k){
    for(int i=0;i<n-k+1;i++){
        int max_element=0;
        for(int j=i;j<i+k;j++)
            max_element=max(max_element,a[j]);
        cout<<max_element<<" ";
    }
}
void maximum_in_subarray(int a[],int n,int k){
    deque<int> d;
    for(int i=0;i<k;i++){
        while(d.empty()==false&&a[i]>=a[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    for(int i=k;i<n;i++){
        cout<<a[d.front()]<<" ";
        while(d.empty()==false&&d.front()<=i-k)
            d.pop_front();
        while(d.empty()==false&&a[i]>=a[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    cout<<a[d.front()]<<" ";
}
int main(){
    int a[]={20,5,3,8,6,15};
    printMax(a,6,4);
    cout<<endl;
    maximum_in_subarray(a,6,4);
    return 0;
}
