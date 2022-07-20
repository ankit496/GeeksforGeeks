#include<iostream>
using namespace std;
bool pairSum(int a[],int n,int x){
    for(int i=0;i<n;i++){
        int p1=a[i];
        for(int j=i+1;j<n;j++){
            int p2=a[j];
            if(p1+p2==x)
                return true;
        }
    }
    return false;
}

bool PAIR_SUM(int a[],int n,int x){
    int left_pointer=0;
    int right_pointer=n-1;
    while(left_pointer<right_pointer){
        if(a[left_pointer]+a[right_pointer]==x)
            return true;
        else if(a[left_pointer]+a[right_pointer]>x)
            right_pointer--;
        else
            left_pointer++;
    }
    return false;
}
bool triplet_sum(int a[],int n,int x){
    int left=0;
    int right=n-1;
    while(left<right){
        int y=x-(a[left]+a[right]);
        for(int i=left;i<=right;i++){
            if(a[i]==y)
                return true;
        }
        if((a[left]+a[right])>x)
            right--;
        else
            left++;
    }
    return false;
}
int main(){
    int a[]={2,3,4,8,9,20,40};
    int x=32;
    cout<<pairSum(a,7,x);
    cout<<endl<<PAIR_SUM(a,7,x);
    cout<<endl<<triplet_sum(a,7,x);
    return 0;
}
