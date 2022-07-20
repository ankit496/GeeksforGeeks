#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int > s;
    s.insert(10);
    s.insert(5);
    s.insert(50);
    for(int i:s)
        cout<<i<<" ";
    cout<<endl;
    for(auto i=s.begin();i!=s.end();i++)
        cout<<*i<<" ";
    cout<<endl;
    for(auto i=s.rbegin();i!=s.rend();i++)
        cout<<*i<<" ";
    //set ignore the duplicate values
    s.insert(5);
    for(int i:s)
        cout<<i<<" ";
    auto it=s.find(10);
    cout<<*it;
    //s.clear();
    //cout<<s.size();
    s.erase(10);
    cout<<s.size()<<"OR"<<endl;
    //we can pass the iterator s.erase(it);
        //to delete multiple element s.erase(it,s.end());
    auto r=s.lower_bound(6);
    if(it!=s.end()){
        cout<<endl<<*r;
    }
    auto i=s.upper_bound(6);
    if(i!=s.end()){
        cout<<endl<<*i;

    }
    return 0;
}
