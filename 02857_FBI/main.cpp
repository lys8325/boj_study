#include <iostream>
#include <string>

using namespace std;

int main() {
    string target;
    bool check[5]={false};
    int ans,temp;

    for(int i=0;i<5;++i){
        cin>>target;
        ans=target.find("FBI");
        if(ans != -1){
            check[i]=true;
        }
        target.clear();
    }
    temp=0;
    for(int i=0;i<5;++i){
        if(check[i]){
            cout<<i+1<<" ";
            temp=1;
        }
    }
    if(temp==0){
        cout<<"HE GOT AWAY!"<<endl;
    }
    return 0;
}