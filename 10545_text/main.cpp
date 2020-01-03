#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int button[10] = {0}; // 버튼입력 정보
char text[100]; // 입력할 문자열
char click[500] = {0}; // 클릭할 번호를 저장할 문자열, 최악의 경우는 전부 4번 클릭하면서 #을 같이 기입하는 경우
int position = 0; // click 문자열에 기입할 위치

void typing(int num, int count){ // 쳐야할 번호 몇 번 치는지를 매개변수로 받아서
    if(click[position-1] == num + 48){ // 만약 쳐야할 문자가 이전 문자와 동일하다면 # 기입
        click[position] = '#';
        ++position; // 인덱스 증가
    }
    for(int i = 0;i<count;++i){
        click[position+i] = num + 48; // 정수에 48을 더해주면 char일 때의 수가 나온다.
    }
    position += count; // 횟수 만큼 인덱스 증가
}

int fix_button(int orginal){ // 새로 매핑된 번호 찾아 반환하는 함수
    for(int i=1;i<10;++i){
        if(button[i] == orginal){
            return i;
        }
    }
}

int main() {
    for(int i=1;i<10;++i){
        cin>>button[i];
    }
    cin>>text;
    int temp;
    int len  = strlen(text);
    for(int i=0;i<len;++i){
        switch (text[i]){
            case 'a':
                temp = fix_button(2); // temp에 새로 매핑된 번호를 받고,
                typing(temp, 1); // typing 함수에 번호와 쳐야할 count를 넘겨준다
                break;
            case 'b':
                temp = fix_button(2);
                typing(temp, 2);
                break;
            case 'c':
                temp = fix_button(2);
                typing(temp, 3);
                break;

            case 'd':
                temp = fix_button(3);
                typing(temp, 1);
                break;
            case 'e':
                temp = fix_button(3);
                typing(temp, 2);
                break;
            case 'f':
                temp = fix_button(3);
                typing(temp, 3);
                break;

            case 'g':
                temp = fix_button(4);
                typing(temp, 1);
                break;
            case 'h':
                temp = fix_button(4);
                typing(temp, 2);
                break;
            case 'i':
                temp = fix_button(4);
                typing(temp, 3);
                break;

            case 'j':
                temp = fix_button(5);
                typing(temp, 1);
                break;
            case 'k':
                temp = fix_button(5);
                typing(temp, 2);
                break;
            case 'l':
                temp = fix_button(5);
                typing(temp, 3);
                break;

            case 'm':
                temp = fix_button(6);
                typing(temp, 1);
                break;
            case 'n':
                temp = fix_button(6);
                typing(temp, 2);
                break;
            case 'o':
                temp = fix_button(6);
                typing(temp, 3);
                break;
            case 'p':
                temp = fix_button(7);
                typing(temp, 1);
                break;
            case 'q':
                temp = fix_button(7);
                typing(temp, 2);
                break;
            case 'r':
                temp = fix_button(7);
                typing(temp, 3);
                break;
            case 's':
                temp = fix_button(7);
                typing(temp, 4);
                break;
            case 't':
                temp = fix_button(8);
                typing(temp, 1);
                break;
            case 'u':
                temp = fix_button(8);
                typing(temp, 2);
                break;
            case 'v':
                temp = fix_button(8);
                typing(temp, 3);
                break;
            case 'w':
                temp = fix_button(9);
                typing(temp, 1);
                break;
            case 'x':
                temp = fix_button(9);
                typing(temp, 2);
                break;
            case 'y':
                temp = fix_button(9);
                typing(temp, 3);
                break;
            case 'z':
                temp = fix_button(9);
                typing(temp, 4);
                break;
        }
    }
    cout<<click; // 정답 출력
    return 0;
}