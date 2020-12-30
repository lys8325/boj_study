#include <iostream>
#include <algorithm>
using namespace std;

int lcs[1001][1001];

int main() {
    string str1, str2, ans;
    int maxLen, str1Len, str2Len, y, x;
    cin>>str1>>str2;

    str1Len = str1.length();
    str2Len = str2.length();
    y = str1Len;
    x = str2Len;
    for(int i=0;i<str1Len;++i){
        for(int j=0;j<str2Len;++j){
            if(str1[i] == str2[j]){
                lcs[i+1][j+1] = lcs[i][j] + 1;
            }else{
                lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j]);
            }
        }
    }

    maxLen = lcs[str1Len][str2Len];
    cout<<maxLen<<"\n";

    if(maxLen){
        while(lcs[y][x] != 0){
            if(str1[y-1] == str2[x-1]){
                ans.push_back(str1[y-1]);
                --y, --x;
            }else{
                if(lcs[y-1][x] == lcs[y][x]){
                    --y;
                }else{
                    --x;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        cout<<ans;
    }

    return 0;
}
