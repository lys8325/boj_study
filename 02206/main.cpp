#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> map(1001, "x");
int n, m;
int minVal = 1000001;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
bool visit[1001][1001];

void dfs(int y, int x, int curVal, bool used){
    if(curVal >= minVal){
        return;
    }

    if(y == n && x == m){
        minVal = curVal;
        return;
    }

    int nextY, nextX;
    for(int i=0;i<4;++i){
        nextY = y + dy[i];
        nextX = x + dx[i];

        if(
                1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m
                && map[nextY][nextX] == '0' && !visit[nextY][nextX]
        ){
            visit[nextY][nextX] = true;
            dfs(nextY, nextX, curVal+1, used);
            visit[nextY][nextX] = false;
        }

        if(!used){
            if(
                    1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m
                    && map[nextY][nextX] == '1' && !visit[nextY][nextX]
                    ){
                visit[nextY][nextX] = true;
                dfs(nextY, nextX, curVal+1, true);
                visit[nextY][nextX] = false;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string str;
    cin>>n>>m;

    for(int i=1;i<=n;++i){
        cin>>str;
        map[i].append(str);
    }

    dfs(1, 1, 1, false);

    if(minVal == 1000001){
        cout<<-1;
    }else{
        cout<<minVal;
    }

    return 0;
}
