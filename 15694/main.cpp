#include <iostream>
using namespace std;

int num[9];
bool visit[9];
int n, m;

void dfs(int len){
    if(len == m){
        for(int i=1;i<=m;++i){
            cout<<num[i]<<" ";
        }
        cout<<"\n";
    }

    for(int i=1;i<=n;++i){
        if(!visit[i]){
            num[len+1] = i;
            visit[i] = true;
            dfs(len+1);
            visit[i] = false;
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=1;i<=n;++i){
        num[1] = i;
        visit[i] = true;
        dfs(1);
        visit[i] = false;
    }

    return 0;
}
