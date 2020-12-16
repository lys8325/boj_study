#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans, cnt;
bool map[25][25];
bool visit[25][25];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int grouping(int y, int x){
    int nextY, nextX;

    for(int i=0;i<4;++i){
        nextY = y + dy[i];
        nextX = x + dx[i];

        if(0 <= nextY && nextY < n && 0 <= nextX && nextX < n
            && map[nextY][nextX] && !visit[nextY][nextX]){


                ++cnt;
                visit[nextY][nextX] = true;
                grouping(nextY, nextX);
        }
    }

    return cnt;
}

int main() {
    vector<int> cntList;
    string str;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        for(int j=0;j<n;++j){
            if(str[j] == '1'){
                map[i][j] = true;
            }
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(map[i][j] && !visit[i][j]){
                ++ans;
                cnt = 1;
                visit[i][j] = true;
                cntList.push_back(grouping(i, j));
            }
        }
    }

    cout<<ans<<"\n";
    sort(cntList.begin(), cntList.end());
    for(int i : cntList){
        cout<<i<<"\n";
    }

    return 0;
}
