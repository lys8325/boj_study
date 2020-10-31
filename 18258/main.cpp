#include <iostream>
using namespace std;

int q[2000000];
int f = 0, e = 0;

void push(int num){
    q[e++] = num;
}

int pop(){
    if(f == e){
        return -1;
    }else{
        return q[f++];
    }
}

int size(){
    return e - f;
}

int empty(){
    if(f == e){
        return 1;
    }else{
        return 0;
    }
}

int front(){
    if(f == e){
        return -1;
    }else{
        return q[f];
    }
}

int back(){
    if(f == e){
        return -1;
    }else{
        return q[e-1];
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num;
    string op;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>op;

        if(op == "push"){
            cin>>num;
            push(num);
        }else if(op == "pop"){
            cout<<pop()<<"\n";
        }else if(op == "size"){
            cout<<size()<<"\n";
        }else if(op == "empty"){
            cout<<empty()<<"\n";
        }else if(op == "front"){
            cout<<front()<<"\n";
        }else if(op == "back"){
            cout<<back()<<"\n";
        }
    }
    return 0;
}
