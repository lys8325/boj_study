#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[1000];
    char b[1000];
    int c[26]={0};
    int d[26]={0};
    int len1,len2,ans,index;

    cin>>a>>b;
    len1=strlen(a);
    len2=strlen(b);

    for(int i=0;i<len1;++i){
        index=a[i]-97;
        ++c[index];
    }
    for(int i=0;i<len2;++i){
        index=b[i]-97;
        ++d[index];
    }
    ans=0;
    for(int i=0;i<26;++i){
        if(c[i]-d[i]!=0){
            ans += abs(c[i]-d[i]);
        }
    }
    cout<<ans;
    return 0;
}