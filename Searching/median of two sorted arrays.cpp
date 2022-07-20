#include<iostream>
using namespace std;
double median(int a1[],int a2[],int n1,int n2){
    int beg=0;
    int en=n1-1;
    while(beg<=en){
        int i1=(beg+en)/2;
        int i2=(n1+n2+1)/2-i1;
        int min1=(i1==n1)?INT_MAX:a1[i1];
        int max1=(i1==0)?INT_MIN:a1[i1-1];
        int min2=(i2==n2)?INT_MAX:a2[i2];
        int max2=(i2==0)?INT_MIN:a1[i2-1];
        if(max1<=max2&&max2<=min1){
            if((n1+n2)%2==0)
                return (double)(max(max1,max2)+min(min1,min2))/2;
            else
                return (double)max(max1,max2);
        }
        else if(max1>min2)
            en=i1-1;
        else
            beg=i1+1;
    }
    return -1;
}
int main(){
    int a1[]={10,20,30,40,50};
    int a2[]={5,15,25,30,35,55,65,75,85};
    cout<<median(a1,a2,5,9);
    return 0;
}
