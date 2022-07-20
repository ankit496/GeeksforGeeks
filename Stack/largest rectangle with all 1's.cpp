#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
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
int max_area(int a[],int n){
    int cur=0,res=0;
    vector<int> ps=previous_smaller(a,n);
    vector<int> ns=next_smaller(a,n);
    for(int i=0;i<n;i++){
        cur=a[i];
        cur+=(i-ps[i]-1)*a[i];
        cur+=(ns[i]-i-1)*a[i];
        res=max(res,cur);
    }
    return res;
}
int maximum_area(int a[][4]){
    int result;
    int r=4,c=4;
    result=max_area(a[0],c);
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]==1){
                a[i][j]+=a[i-1][j];
            }
        }
        result=max(result,max_area(a[i],c));
    }
    return result;
}
int main(){
    int a[4][4]={0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0};
    cout<<maximum_area(a);
    return 0;
}
