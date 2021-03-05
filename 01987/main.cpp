#include <iostream>
#include <algorithm>
using namespace std;

string board[20];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int r, c, maxCnt = -1;

void dfs(int y, int x, int state, int cnt){
    char val = board[y][x];

    if((state & 1 << (val-65)) != 0){
        return;
    }

    int newState = (state | (1 << (val-65)));
    maxCnt = max(maxCnt, cnt);

    int nextY, nextX;

    for(int i=0;i<4;++i){
        nextY = y + dy[i];
        nextX = x + dx[i];

        if(0 <= nextY && nextY < r && 0 <= nextX && nextX < c){
            dfs(nextY, nextX, newState, cnt+1);
        }
    }
}

int main() {
    cin>>r>>c;
    for(int i=0;i<r;++i){
        cin>>board[i];
    }

    dfs(0, 0, 0, 1);

    cout<<maxCnt;
    return 0;
}
