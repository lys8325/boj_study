#include <iostream>
using namespace std;

int num[9];
int n, m;

void dfs(int len, int start){
    if(len == m){
        for(int i=1;i<=m;++i){
            cout<<num[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=start;i<=n;++i){
        num[len+1] = i;
        dfs(len+1, i);
    }
}
int main() {
    cin>>n>>m;

    for(int i=1;i<=n;++i){
        num[1] = i;
        dfs(1, i);
    }
    return 0;
}
