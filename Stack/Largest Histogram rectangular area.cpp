#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int max_area(int a[],int n){
    int max_area=0;
    for(int i=0;i<n;i++){
        int area=a[i];
        for(int j=i-1;j>=0;j--){
            if(a[j]>=a[i])
                area+=a[i];
            else
                break;
        }
        for(int j=i+1;j<n;j++){
            if(a[j]>=a[i])
                area+=a[i];
            else
                break;
        }
        max_area=max(max_area,area);
    }
    return max_area;
}
vector<int> previous_smaller(int a[],int n){
    stack<int> s;
    vector<int> v;
    s.push(0);
    v.push_back(-1);
    for(int i=1;i<n;i++){
        while(s.empty()==false&&a[s.top()]>=a[i])
            s.pop();
        int r=s.empty()?-1:s.top();
        s.push(i);
        v.push_back(r);
    }
    return v;
}
vector<int> next_smaller(int a[],int n){
    stack<int> s;
    vector<int> v;
    s.push(0);
    v.push_back(n);
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false&&a[s.top()]>=a[i])
            s.pop();
        int r=s.empty()?n:s.top();
        s.push(i);
        v.push_back(r);
    }
    reverse(v.begin(),v.end());
    return v;
}
int max_area(int a[],vector<int> ps,vector<int> ns,int n){
    int cur=0,res=0;
    for(int i=0;i<n;i++){
        cur=a[i];
        cur+=(i-ps[i]-1)*a[i];
        cur+=(ns[i]-i-1)*a[i];
        res=max(res,cur);
    }
    return res;
}
int main(){
    int a[]={6,2,5,4,1,5,6};
    //cout<<max_area(a,7);
    vector<int> v=previous_smaller(a,7);
    for(int i=0;i<7;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> v2=next_smaller(a,7);
    for(int i=0;i<7;i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    cout<<max_area(a,v,v2,7);
    return 0;
}
