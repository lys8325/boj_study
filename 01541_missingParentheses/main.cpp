#include <iostream>
#include <string.h>
#include <cmath>
#include <stack>

using namespace std;

char original[51];
stack<int> numList;
stack<char> operatorList;
stack<int> result;

int main() {
    int num = 0;
    int numLen = 0;
    int index = 0;
    int temp,answer=0;

    cin>>original;
    char copy[strlen(original)+1];
    strcpy(copy,original);

    char *tok = strtok(original,"+-");
    while(tok != NULL){
        num = 0;
        numLen = strlen(tok);
        index += numLen;
        for(int i=0;i<numLen;++i){
            num += (tok[i]-'0') * pow(10,numLen-1-i);
        }
        numList.push(num);
        operatorList.push(copy[index++]);
        tok = strtok(NULL,"+-");
    }
    operatorList.pop(); // 오퍼레이터 스택에 들어간 '\0' 제거

    while(!operatorList.empty()){
        if(operatorList.top() == '-'){ // 연산자가 '-' 이면 top 을 연산 대기 스택으로 이동
            result.push(numList.top());
            numList.pop();
        }else{ // 연산자가 '+' 이면 top부터 2개 원소를 더하고 제거 후 탑 갱신
            temp = numList.top();
            numList.pop();
            temp += numList.top();
            numList.pop();
            numList.push(temp);
        }
        operatorList.pop();
    }
    result.push(numList.top()); // numList 에 남아있는 마지막 숫자 연산 대기 스택으로 이동

    answer = result.top();
    result.pop();
    while(!result.empty()){
        answer -= result.top();
        result.pop();
    }
    cout<<answer;
    return 0;
}
