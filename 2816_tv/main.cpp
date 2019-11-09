#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> channel;
int n;
int pointing;

void remote1(){
    ++pointing;
    cout<<"1";
}

void remote2(){
    --pointing;
    cout<<"2";
}

void remote3(){
    channel[pointing].swap(channel[pointing+1]);
    ++pointing;
    cout<<"3";
}

void remote4(){
    channel[pointing].swap(channel[pointing-1]);
    --pointing;
    cout<<"4";
}

int main() {
    string name;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>name;
        channel.push_back(name);
    }
    pointing=0;

    while(channel[0]!="KBS1"){
        if(channel[pointing+1]=="KBS1"){
            remote3();
            if(channel[0]=="KBS1"){
                break;
            }
            else{
                remote2();
                while(channel[0]!="KBS1"){
                    remote4();
                }
            }
        }
        else{
            remote1();
        }
    }
    while(channel[1]!="KBS2"){
        if(channel[pointing+1]=="KBS2"){
            remote3();
            if(channel[1]=="KBS2"){
                break;
            }
            else{
                remote2();
                while(channel[1]!="KBS2"){
                    remote4();
                }
            }
        }
        else{
            remote1();
        }
    }
    return 0;
}