#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string board[50];

int boardCheck(int y, int x){
    int cnt = 0;
    int base, tmp;
    int n = y + 8;
    int m = x + 8;

    base = (y+x) % 2;
    for(int i=y;i<n;++i){
        for(int j=x;j<m;++j){
            tmp = (i+j) % 2;
            if(tmp == base && board[i][j] != 'W'){
                ++cnt;
            }else if(tmp != base && board[i][j] != 'B'){
                ++cnt;
            }
        }
    }

    return min(cnt, 64 - cnt);
}

int main() {
    int n, m, ans = 65;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        cin>>board[i];
    }
    m -= 7; n -= 7;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ans = min(ans, boardCheck(i, j));
        }
    }

    cout<<ans;
    return 0;
}
