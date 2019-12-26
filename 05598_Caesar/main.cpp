#include <iostream>
#include <cstring>

using namespace std;
int main() {
    char password[1000];
    cin>>password;
    int len = strlen(password);

    for(int i=0;i<len;++i){
        password[i] -= 3;
        if(password[i] < 65){
            password[i] += 26;
        }
    }

    cout<<password;
    return 0;
}