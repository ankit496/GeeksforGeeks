#include<iostream>
#include<cstring>
using namespace std;
string s="abba";
bool palindrome(string s,int i,int j){
    if(i>=j)
        return true;
    return(s[i]==s[j]&&palindrome(s,i+1,j-1));
}
int main(){
    //getline(cin,s);
    cout<<palindrome(s,0,s.length()-1);
    return 0;
}
