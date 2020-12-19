#include <iostream>
using namespace std;

int main() {
    int num, d = 2;

    cin>>num;
    while(num != 1){
        if(num % d == 0){
            cout<<d<<"\n";
            num /= d;
        }else{
            ++d;
        }
    }

    return 0;
}
