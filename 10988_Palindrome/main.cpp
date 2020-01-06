#include <iostream>
#include <string>

using namespace std;
int main() {
    string word;
    cin>>word;
    int len = word.length();
    int mid = len / 2; // mid엔 정수형으로 저장이 되기 때문에
    // 단어 길이가 홀수든 짝수든 대칭 비교가 가능하다.
    int answer = 1; // 단어 철자 비교시 같지 않음이 판명나면
    // answer에 0을 저장후 break하기 때문에 초기값은 1

    for(int i=0;i<mid;++i){
        if(word[i] != word[len-1-i]){ // 중간을 기준으로 대칭 지점에 있는 철자와 다르면
            answer = 0; // 팰린드롬이 아니다.
            break;
        }
    }
    cout<<answer;
    return 0;
}