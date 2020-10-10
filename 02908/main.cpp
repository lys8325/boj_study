#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;
    cin>>str1>>str2;

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    if(stoi(str1) < stoi(str2)){
        cout<<str2;
    }else{
        cout<<str1;
    }

    return 0;
}
