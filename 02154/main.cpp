#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string str;
    int num;

    cin>>num;
    for(int i=1;i<=num;++i){
        str += to_string(i);
    }

    cout<<str.find(to_string(num))+1;
    return 0;
}
