#include<iostream>
#include<deque>
using namespace std;
int first_petrol_pump(int petrol[],int dist[],int n){
    for(int start=0;start<n;start++){
        int cur_petrol=0;
        int end=start;
        while(true){
            cur_petrol+=(petrol[end]-dist[end]);
            if(cur_petrol<0)
                break;
            end=(end+1)%n;
            if(end==start)
                return start+1;
        }
    }
    return -1;
}
int first_loop(int petrol[],int dist[],int n){
    int cur_petrol=0;
    deque<int> dq;
    for(int start=0;start<n;start++){
        cur_petrol+=petrol[start]-dist[start];
        if(cur_petrol>0){
            dq.push_back(start);
        }
        else{
            dq.push_back(start);
            while(dq.empty()==false&&(cur_petrol)<0){
                cur_petrol+=petrol[dq.front()]-dist[dq.front()];
                dq.pop_front();
            }
        }
    }
    if(dq.empty())
        return -1;
    return dq.front();
}
int first_petrol(int petrol[],int dist[],int n){
    int start=0,cur_pet=0;
    int prev_pet=0;
    for(int i=0;i<n;i++){
        cur_pet+=petrol[i]-dist[i];
        if(cur_pet<0){
            start=i+1;
            prev_pet+=cur_pet;
            cur_pet=0;
        }
    }
    return (cur_pet+prev_pet>=0)?start+1:-1;
}
int main(){
    int petrol[]={8,9,4};
    int dist[]={5,10,12};
    cout<<first_petrol_pump(petrol,dist,3)<<endl;
    cout<<first_loop(petrol,dist,3);
    cout<<first_petrol(petrol,dist,3);
    return 0;
}
