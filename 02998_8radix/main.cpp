#include <iostream>
#include <string>

using namespace std;
int main() {
    string origianl,expand,answer,temp,num;
    int len,count,check;
    cin>>origianl;
    len = origianl.length();
    if(len%3 ==1){
        expand = "00" + origianl;
    }
    else if(len%3 == 2){
        expand = "0" + origianl;
    }
    else{
        expand = origianl;
    }

    count = expand.length()/3;
    for(int i=0;i<count;i++){
        temp = expand.substr(i*3,3);
        check = stoi(temp);
        if(check == 0){
            num = "0";
        }
        else if(check == 1){
            num = "1";
        }
        else if(check == 10){
            num = "2";
        }
        else if(check == 11){
            num = "3";
        }
        else if(check == 100){
            num = "4";
        }
        else if(check == 101){
            num = "5";
        }
        else if(check == 110){
            num = "6";
        }
        else if(check == 111){
            num = "7";
        }
        answer += num;
    }
    cout<<answer;
    return 0;
}