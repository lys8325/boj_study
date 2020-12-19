#include <iostream>
#include <queue>
using namespace std;

bool map[101][101];
bool visit[101][101];
int n, m;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<pair<int, int>, int>> q;

int bfs(){
    int curY, curX, curCnt, nextY, nextX;

    while(!q.empty()){
        curY = q.front().first.first;
        curX = q.front().first.second;
        curCnt = q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            nextY = curY + dy[i];
            nextX = curX + dx[i];

            if(nextY == n && nextX == m){
                return curCnt + 1;
            }

            if(0 < nextY && nextY <= n && 0 < nextX && nextX <= m
                && map[nextY][nextX] && !visit[nextY][nextX]){
                q.push({{nextY, nextX}, curCnt+1});
                visit[nextY][nextX] = true;
            }
        }
    }
}

int main() {
    cin>>n>>m;
    string tmp;

    for(int i=1;i<=n;++i){
        cin>>tmp;
        for(int j=1;j<=m;++j){
            if(tmp[j-1] == '1'){
                map[i][j] = true;
            }
        }
    }

    q.push({{1,1},1});
    visit[1][1] = true;

    cout<<bfs();
    return 0;
}
