#include <iostream>
#include <string.h>

#define maxN 1000
using namespace std;

int cycle[maxN+1] = {0}; // 인덱스의 시작이 1이니 1000+1 생성
bool check[maxN+1] = {false}; // 방문했는지 검사

int t,n,ans,start;
// start는 지금 검사중인 세트의 시작 인덱스

void findanswer(int index){
    int temp;
    check[index] = true; // 시작위치 방문 표시
    temp = cycle[index]; // 다음 방문 인덱스

    while(temp != start && !check[temp]){ // start와 같으면 싸이클,
        // 이미 방문한 곳이지만 start와 다르면 싸이클이 아님.
        check[temp] = true; // 지금 조사중인 곳 방문 표시
        temp = cycle[temp]; // 다음 방문 인덱스
    }
    //반복문을 빠져나왔는데
    if(temp == start){ // 싸이클이었다면
        ++ans;
    }

    for(int a=1;a<=n;++a){ // 방문 안한 인덱스, 즉 싸이클에 속하지 않은
        // 인덱스 구하기
        if(!check[a]){
            start = a; // 그 지점을 start로
            findanswer(start); // dfs
            return;
        }
    }
    return;
}

int main() {
    cin>>t;
    for(int i=1;i<=t;++i){
        ans=0;
        memset(cycle,0,maxN+1);
        memset(check, 0, maxN + 1);
        cin>>n;
        for(int j=1;j<=n;++j){
            cin>>cycle[j];
        }
        start = 1;
        findanswer(1);
        cout<<ans<<endl;
    }
    return 0;
}