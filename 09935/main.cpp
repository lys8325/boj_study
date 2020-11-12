#include <iostream>
#include <deque>
using namespace std;

int main(){
    string str, target, ans;
    cin>>str>>target;

    deque<char> dq;
    deque<char> tmp;
    char trigger = target.back();
    int strLen = str.length();
    int tarLen = target.length();
    bool bomb;

    for(int i=0;i<tarLen-1;++i){
        dq.push_back(str[i]);
    }

    for(int i=tarLen-1;i<strLen;++i){
        dq.push_back(str[i]);
        if(dq.back() == trigger){
            bomb = true;
            for(int j=0;j<tarLen;++j){
                if(dq.back() != target[tarLen-1-j]){
                    bomb = false;
                    break;
                }
                tmp.push_back(dq.back());
                dq.pop_back();
            }

            while(!tmp.empty()){
                if(!bomb){
                    dq.push_back(tmp.back());
                }
                tmp.pop_back();
            }
        }
    }

    if(dq.empty()){
        cout<<"FRULA";
    }else{
        while(!dq.empty()){
            cout<<dq.front();
            dq.pop_front();
        }
    }

    return 0;
}