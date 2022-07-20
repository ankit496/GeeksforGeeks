#include<iostream>
#include<stack>
#include<queue>

using namespace std;
bool allSame(queue<int> student_queue){
    int x=student_queue.front();
    while(student_queue.empty()==false){
        if(x==student_queue.front())
            student_queue.pop();
        else
            break;
    }
    if(student_queue.empty()==true)
        return true;
    else
        return false;
}
int number_of_remaining_students(int sandwiches[],int students[],int n){
    stack<int> sandwich_stack;
    queue<int> student_queue;
    for(int i=0;i<n;i++){
        sandwich_stack.push(sandwiches[i]);
        student_queue.push(students[i]);
    }
    while(sandwich_stack.empty()==false&&allSame(student_queue)==false){
        if(sandwich_stack.top()==student_queue.front()){
            sandwich_stack.pop();
            student_queue.pop();
        }
        else{
            int x=student_queue.front();
            student_queue.pop();
            student_queue.push(x);
        }
    }
    return sandwich_stack.size();
}

void reverse(int *a,int n){
    int low=0,high=n-1;
    while(low<high){
        int t;
        t=a[low];
        a[low]=a[high];
        a[high]=t;
        low++;
        high--;
    }
}
int main(){
    int sandwiches[6]={1,0,0,0,1,1};
    int students[6]={1,1,1,0,0,1};
    reverse(sandwiches,6);
    cout<<number_of_remaining_students(sandwiches,students,6);
    return 0;
}
