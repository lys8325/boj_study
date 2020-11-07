#include <iostream>
using namespace std;

int divide(int y, int x, int n, int **paper, int color){
    bool isComplete = true;
    int cnt = 0;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(color != paper[i+y][j+x]){
                isComplete = false;
                break;
            }
        }
    }

    if(isComplete){
        return 1;
    }

    if(n == 1){
        return 0;
    }

    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            cnt += divide((y + n * i / 2), (x + n * j / 2), n / 2, paper, color);;
        }
    }

    return cnt;
}

int main() {
    int n, blue, white;
    int paper[129][129];

    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>paper[i][j];
        }
    }

    white = divide(1, 1, n, paper, 0);
    blue = divide(1, 1, n, paper, 1);

    cout<<white<<"\n"<<blue;
    return 0;
}
