#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1000][1000];
int word[1000];
int n, m;

int calc(int idx, int pos){
    if(idx >= n){ // 모든 단어를 다 썻다면,
        return 0;
    }
    if(pos >= m){ // 쓸 위치가 m 이상이라면, 다음 줄에 적고 그 시작 값은 단어의 길이값.
        if(pos == m){ // 이전 단어를 적고서 한 칸을 띄었는데 pos 가 m 이었다면,
            return calc(idx+1, word[idx]+1)+1; // 마지막 한 칸 더해주기
        }else{
            return calc(idx+1, word[idx]+1);
        }
    }

    int ret = dp[pos][idx];
    if(ret != -1){
        return ret;
    }

    // 우선 다음 줄에 적어본다 => m-(pos-1)의 제곱 더하기.
    ret = calc(idx+1, word[idx]+1) + ((m - pos + 1) * (m - pos + 1));

    // 다음 줄에서 적기로 하고 구한 ret 값과, 현재 줄에 적을 수 있을 때의 경우 중 작은 값으로 갱신.
    if(pos + word[idx] <= m){ // 위 조건문에 못들어오면 어차피 다음줄에 적었어야했다!
        ret = min(ret, calc(idx+1, pos + word[idx] + 1));
    }
    dp[pos][idx] = ret; // dp 갱신
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        scanf("%d", &word[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", calc(1,word[0]+1)); // 첫 줄에 첫 단어는 무조건 적어야함.
    return 0;
}