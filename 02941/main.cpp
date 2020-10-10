#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, tmp;
    int strLen, idx = 0, ans = 0;
    cin>>str;
    strLen = str.length();

    while(idx < strLen){
        tmp = str.substr(idx, 2);
        if(str.substr(idx, 3) == "dz="){
            ++ans;
            idx += 3;
        }else if(
                tmp == "c=" ||
                tmp == "c-" ||
                tmp == "d-" ||
                tmp == "lj" ||
                tmp == "nj" ||
                tmp == "s=" ||
                tmp == "z="
                ){
            ++ans;
            idx += 2;
        }else{
            ++ans;
            ++idx;
        }
    }

    cout<<ans;
    return 0;
}
