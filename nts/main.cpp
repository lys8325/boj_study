#include <iostream>
using namespace std;

void changeConvention(string input){
    char c;
    bool isSnake = false;
    int inputLen = input.length();

    if(input.find('_') != -1){
        isSnake = true;
    }

    if(isSnake){
        for(int idx=0;idx<inputLen;++idx){
            c = input[idx];
            if(c == '_') {
                input.erase(idx, 1);
                input[idx] -= 32;
                --inputLen;
            }
        }
    }else{
        for(int idx=0;idx<inputLen;++idx){
            c = input[idx];
            if(c >= 'A' && c <= 'Z'){
                input.insert(idx, "_");
                input[idx+1] += 32;
                ++inputLen;
                ++idx;
            }
        }
    }

    cout<<input;
}

int main() {
    string str1 = "sampleStringCase";
    string str2 = "sample_string_case";

    changeConvention(str1);
    cout<<"\n";
    changeConvention(str2);

    return 0;
}
