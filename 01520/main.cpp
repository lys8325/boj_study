#include <iostream>
#define maxM 500
#define maxN 500
using namespace std;

int m,n;
int map[maxM][maxN] = {0};
int dp[maxM][maxN];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int dfsWithDp(int y, int x){
    if(y == m-1 && x == n-1){
        return 1;
    }
    if(dp[y][x] != -1){
        return dp[y][x];
    }
    dp[y][x] = 0;
    int tmpY,tmpX;
    for(int i=0;i<4;++i){
        tmpY = y + dy[i];
        tmpX = x + dx[i];
        if(tmpY >= 0 && tmpY < m && tmpX >= 0 && tmpX < n){
            if(map[y][x] > map[tmpY][tmpX]){
                dp[y][x] += dfsWithDp(tmpY, tmpX);
            }
        }
    }
    return dp[y][x];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>m>>n;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            dp[i][j] = -1;
        }
    }

    cout<<dfsWithDp(0, 0);

    return 0;
}