#include <iostream>
#include <string>
#include <algorithm>
#define max_l 1000

using namespace std;
int main() {
    string word[max_l];
    cin>>word[0];
    int len;
    len = word[0].length();

    for(int i=1;i<len;++i){
        word[i] = word[0].substr(i);
    }
    sort(&word[0],&word[len]);

    for(int i=0;i<len;++i){
        cout<<word[i]<<endl;
    }
    return 0;
}