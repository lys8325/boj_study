#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int board[9][9];
int n;
vector<pair<int, int>> v;

bool checkY(int x, int target){
    for(int i=0;i<9;++i){
        if(board[i][x] == target){
            return false;
        }
    }

    return true;
}

bool checkX(int y, int target){
    for(int i=0;i<9;++i){
        if(board[y][i] == target){
            return false;
        }
    }

    return true;
}

bool checkBox(int y, int x, int target){
    y -= y % 3;
    x -= x % 3;

    for(int i=y;i<y+3;++i){
        for(int j=x;j<x+3;++j){
            if(board[i][j] == target){
                return false;
            }
        }
    }

    return true;
}

void dfs(int cnt){
    if(cnt == n){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }

    int y = v[cnt].first;
    int x = v[cnt].second;
    for(int i=1;i<=9;++i){
        if(checkY(x, i) && checkX(y, i) && checkBox(y, x, i)){
            board[y][x] = i;
            dfs(cnt+1);
            board[y][x] = 0;
        }
    }
}

int main() {
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cin>>board[i][j];
            if(board[i][j] == 0){
                ++n;
                v.push_back({i, j});
            }
        }
    }

    dfs(0);
    return 0;
}
