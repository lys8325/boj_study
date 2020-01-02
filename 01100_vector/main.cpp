#include <iostream>
#include <string>

using namespace std;

int main() {
    string board[8];
    int ans,ch;
    for(int i=0;i<8;++i){
        cin>>board[i];
    }

    ch = 'F';
    ans = 0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(board[i*2][j*2] == ch){
                ++ans;
            }
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(board[i*2+1][j*2+1] == ch){
                ++ans;
            }
        }
    }
    cout<<ans;
    return 0;
}