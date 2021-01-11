#include <iostream>
#include <queue>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    queue<int> q;
    int n, num;
    string op;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>op;
        if(op == "push"){
            cin>>num;
            q.push(num);
        }else if(op == "pop"){
            if(q.empty()){
                cout<<"-1\n";
            }else{
                cout<<q.front()<<"\n";
                q.pop();
            }
        }else if(op == "size"){
            cout<<q.size()<<"\n";
        }else if(op == "empty"){
            if(q.empty()){
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }else if(op == "front"){
            if(q.empty()){
                cout<<"-1\n";
            }else{
                cout<<q.front()<<"\n";
            }
        }else if(op == "back"){
            if(q.empty()){
                cout<<"-1\n";
            }else{
                cout<<q.back()<<"\n";
            }
        }
    }
    return 0;
}
