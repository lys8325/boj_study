#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string lamp[50];
int offCnt[50];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, k, answer = 0, cnt;

    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>lamp[i];
        cnt = 0;
        for(int j=0;j<m;++j){
            if(lamp[i][j] == '0'){
                ++cnt;
            }
        }
        offCnt[i] = cnt;
    }

    cin>>k;
    for(int i=0;i<n;++i){
        if(offCnt[i] == k || (offCnt[i] < k && (k-offCnt[i]) % 2 == 0)){
            cnt = 0;
            for(int j=0;j<n;++j){
                if(lamp[i] == lamp[j]){
                    ++cnt;
                }
            }
            answer = max(answer, cnt);
        }
    }

    cout<<answer;
    return 0;
}
