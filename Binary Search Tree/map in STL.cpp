#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> m;
    m.insert({10,20});
    cout<<m.size()<<endl;
    cout<<m[10];
    //square operator adds key if the key is not present in the set
    m[5]=400;
    cout<<endl<<m[5]<<endl;
    //at operator just insert the value in the existing key in the map
    m.at(5)=300;
    cout<<endl<<m[5]<<endl;

    //iterating the map

    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->first<<" "<<i->second<<" ";
    }
    auto it=m.find(10);
    cout<<it->first;
    it=m.lower_bound(5);
    it=m.upper_bound(15);
    return 0;
}
