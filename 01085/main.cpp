#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, y, w, h;
    cin>>x>>y>>w>>h;
    cout<<min(min(abs(x-w), abs(x-0)), min(abs(y-h), abs(y-0)));
    return 0;
}
