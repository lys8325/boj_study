#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    int n, num;
    deque<int> dq;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        if(str == "push_back" || str == "push_front"){
            cin>>num;
            if(str == "push_back"){
                dq.push_back(num);
            }else{
                dq.push_front(num);
            }
        }else if(str == "pop_back" || str == "pop_front"){
            if(dq.empty()){
                cout<<"-1\n";
            }else{
                if(str == "pop_back"){
                    cout<<dq.back()<<"\n";
                    dq.pop_back();
                }else{
                    cout<<dq.front()<<"\n";
                    dq.pop_front();
                }
            }
        }else if(str == "back" || str == "front"){
            if(dq.empty()){
                cout<<"-1\n";
            }else{
                if(str == "back"){
                    cout<<dq.back()<<"\n";
                }else{
                    cout<<dq.front()<<"\n";
                }
            }
        }else if(str == "empty"){
            cout<<dq.empty()<<"\n";
        }else if(str == "size"){
            cout<<dq.size()<<"\n";
        }
    }

    return 0;
}
