#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num, len;
    int cnt[10001] = {0,};
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>num;
        ++cnt[num];
    }

    for(int i=1;i<=10000;++i){
        len = cnt[i];
        if(len > 0){
            for(int j=0;j<len;++j){
                cout<<i<<"\n";
            }
        }
    }
    return 0;
}
