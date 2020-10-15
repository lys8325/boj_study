#include <iostream>
#include <cmath>
using namespace std;

int x[15];
bool board[15][15];
int n, ans;

bool checkX(int numQ, int target){
    for(int i=1;i<=numQ;++i){
        if(target == x[i] || abs(((numQ+1)-i)) ==  abs((target - x[i]))){
            return false;
        }
    }

    return true;
}

void dfs(int numQ, int y){
    if(numQ == n){
        ++ans;
        return;
    }

    for(int i=1;i<=n;++i){
        if(!board[y][i]){
            if(checkX(numQ, i)){
                board[y][i] = true;
                x[numQ+1] = i;
                dfs(numQ+1, y+1);
                board[y][i] = false;
            }
        }
    }
}

int main() {
    cin>>n;

    for(int i=1;i<=n;++i){
        board[1][i] = true;
        x[1] = i;
        dfs(1, 2);
        board[1][i] = false;
    }

    cout<<ans;
    return 0;
}
