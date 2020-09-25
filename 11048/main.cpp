#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int map[1000][1000];
int dp[1000][1000];
int dy[3] = {1, 0, 1};
int dx[3] = {0, 1, 1};

int calc(int y, int x){
    if(y >= n || x >= m){
        return 0;
    }
    int ret = dp[y][x];
    int ty, tx, tmp = 0;
    if(ret != -1){
        return ret;
    }
    ret = map[y][x];
    for(int i=0;i<3;++i){
        ty = y + dy[i];
        tx = x + dx[i];
        tmp = max(tmp, calc(ty, tx));
    }
    ret += tmp;
    dp[y][x] = ret;
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d", &map[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    calc(0, 0);
    printf("%d", dp[0][0]);

    return 0;
}
