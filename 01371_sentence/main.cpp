#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace std;
int main() {
    int a,max;
    int letter[26]={0};
    while((a=getchar()) != EOF){
        if(a>=97 && a<=122){
            ++letter[a-97];
        }
    }
    max=0;
    for(int i=0;i<26;++i){
        if(max < letter[i]){
            max = letter[i];
        }
    }

    for(int i=0;i<26;++i){
        if(max == letter[i]){
            printf("%c",i+97);
        }
    }
    return 0;
}