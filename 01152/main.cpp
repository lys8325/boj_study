#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>

using namespace std;
int main() {
    char a[1000001];
    char *b;
    int num=0;
    fgets(a,1000001,stdin);
    b = strtok(a," ");
    while(b){
        if(strcmp(b,"\n") != 0){
            ++num;
        }
        b = strtok(NULL," ");
    }
    cout<<num;
    return 0;
}