#include <iostream>
using namespace std;

int num[8];
int n,m;

void dfs(int len){
    if(len == m){
        for(int i=1;i<=m;++i){
            cout<<num[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=n;++i){
        num[len+1] = i;
        dfs(len+1);
    }
}

int main() {
    cin>>n>>m;

    for(int i=1;i<=n;++i){
        num[1] = i;
        dfs(1);
    }
    return 0;
}
