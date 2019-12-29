#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
int main() {
    int t,ans,flag;
    cin>>t;
    char word[t][100];
    char *index;
    char *index2;
    char search;

    for(int i=0;i<t;++i){
        cin>>word[i];
    }

    ans = 0;
    for(int i=0;i<t;++i){
        flag = 0;
        for(int j=97;j<=122;++j){
            search = j;
            index = strchr(word[i],search);
            while(index){
                index2 = index;
                index = strchr(index+1,search);
                if (index == NULL || index == index2+1){
                    continue;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
        }
        if(flag == 0){
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}