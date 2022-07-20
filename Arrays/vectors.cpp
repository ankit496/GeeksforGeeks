#include<iostream>
#include<vector>
using namespace std;
int main(){
    //initialization of vector
    vector <int> vector1={1,2,3,4,5};
    for(int i=0;i<5;i++)
        cout<<vector1[i]<<endl;

    //basic operation on vectors
    //1.Addition
    vector1.push_back(6);


    //2.Accessing element
    cout<<"Element at index"<<vector1.at(0)<<" "<<vector1[0]<<endl;

    //3.changing element
    vector1[5]=7;
    vector1.at(5)=8;

    //4.deletion
    vector1.pop_back();
    for(int i:vector1)
        cout<<i<<endl;
    vector<int>::iterator i;

    for(i=vector1.begin();i!=vector1.end();i++)
        cout<<*i<<endl;
    return 0;

}
