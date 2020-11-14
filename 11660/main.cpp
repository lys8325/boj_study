#include <iostream>
using namespace std;

int board[1025][1025];
int memo[1025][1025];

int dp(int x, int y){
    int &v = memo[x][y];

    if(y == 0){
        return 0;
    }

    if(v != 0){
        return v;
    }

    for(int i=1;i<=y;++i){
        v += board[x][i];
    }

    return v;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, x1, x2, y1, y2, sum;
    cin>>n>>m;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<m;++i){
        cin>>x1>>y1>>x2>>y2;

        sum = 0;
        for(int j=x1;j<=x2;++j){
            sum += (dp(j, y2) - dp(j, y1-1));
        }
        cout<<sum<<"\n";
    }
    return 0;
}
