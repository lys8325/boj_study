#include <cstdio>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int n, answer=0;
int bamboo[500][500]={0};
int dp[500][500]={0};

int dfs(int y, int x){
    int tmpY;
    int tmpX;
    int tmp;
    int maxLife = 0;

    if(dp[y][x] != 0){
        return dp[y][x];
    }
    dp[y][x] = 1;

    for(int i=0;i<4;++i){
        tmpY = y + dy[i];
        tmpX = x + dx[i];
        if(tmpY >= 0 && tmpY < n && tmpX >= 0 && tmpX < n){
            if(bamboo[y][x] < bamboo[tmpY][tmpX]){
                tmp = dfs(tmpY,tmpX);
                if(maxLife <= tmp){
                    maxLife = tmp;
                }
            }
        }
    }
    dp[y][x] += maxLife;
    return dp[y][x];
}

int main() {
    scanf("%d", &n);
    int tmp;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d", &bamboo[i][j]);
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            tmp = dfs(i, j);
            if(answer <= tmp){
                answer = tmp;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
