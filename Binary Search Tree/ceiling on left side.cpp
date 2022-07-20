#include<iostream>
#include<set>
using namespace std;
void printCeil(int arr[],int n){
    cout<<"-1"<<" ";
    for(int i=1;i<n;i++){
        int diff=INT_MAX;
        for(int j=0;j<i;j++){
            if(arr[j]>=arr[i])
                diff=min(diff,arr[j]-arr[i]);
        }
            if(diff==INT_MAX)
               cout<< "-1 ";
            else
                cout<<arr[i]+diff<<" ";
    }
}
void printceil(int a[],int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
        auto it=s.upper_bound(a[i]);
        if(it==s.end())
            cout<<"-1 ";
        else
            cout<<*it<<" ";
    }
}
int main(){
    int a[]={2,8,30,15,25,12};
    printCeil(a,6);
    cout<<"\n";
    printceil(a,6);
    return 0;
}
