#include <cstdio>
using namespace std;

int num[9];
bool visit[9];
int n, m;

void dfs(int len, int start){
    if(len == m){
        for(int i=1;i<=m;++i){
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }

    for(int i=start;i<=n;++i){
        if(!visit[i]){
            num[len+1] = i;
            visit[i] = true;
            dfs(len+1, i+1);
            visit[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;++i){
        num[1] = i;
        visit[i] = true;
        dfs(1, i+1);
        visit[i] = false;
    }
    return 0;
}
