#include <iostream>
#include <string>
#define maxN 100

using namespace std;
int main() {
    string target;
    string list[maxN];
    int num,ans,check;

    cin>>target>>num;
    for(int i=0;i<num;++i){
        cin>>list[i];
        list[i] += list[i];
    }
    ans = 0;
    for(int i=0;i<num;++i){
        check = list[i].find(target);
        if(check != -1){
            ++ans;
        }
    }
    cout<<ans;
}