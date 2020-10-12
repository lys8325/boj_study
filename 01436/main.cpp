#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, cnt = 0, i = 666;
    cin>>n;

    while(cnt != n){
        string tmp = to_string(i);
        if(tmp.find("666") != -1){
            ++cnt;
        }
        ++i;
    }

    cout<<i-1;
    return 0;
}
