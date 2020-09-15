#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int w, h, x, y;
    int b[1000][1000]={};

    cin>>h>>w>>x>>y;
    for(int i=0;i<h+x;++i){
        for(int j=0;j<w+y;++j){
            cin>>b[i][j];
        }
    }

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(i>=x && i<h && j>=y && j<w){
                b[i][j] -= b[i-x][j-y];
            }
        }
    }

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}
