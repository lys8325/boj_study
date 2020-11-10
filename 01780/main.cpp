#include <iostream>
using namespace std;

int paper[2187][2187];

int divide(int y, int x, int len, int type){
    bool isComplete = true;
    int cnt = 0;

    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            if(type != paper[i+y][j+x]){
                isComplete = false;
                break;
            }
        }
    }

    if(isComplete){
        return 1;
    }

    if(len == 1){
        return 0;
    }

    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            cnt += divide(y+i*len/3, x+j*len/3, len/3, type);
        }
    }

    return cnt;
}

int main() {
    int n;

    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>paper[i][j];
        }
    }

    cout<<divide(0, 0, n, -1)<<"\n";
    cout<<divide(0, 0, n, 0)<<"\n";
    cout<<divide(0, 0, n, 1)<<"\n";

    return 0;
}
