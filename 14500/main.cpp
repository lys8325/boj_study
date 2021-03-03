#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int board[500][500];
int n, m, ans;

int calc(int y, int x, int cnt, int sum){

}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
        }
    }

    return 0;
}
