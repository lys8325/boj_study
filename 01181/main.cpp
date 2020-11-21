#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    map<int, set<string>> m;
    string str;
    int n, strlen;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        strlen = str.length();

        if(m.find(strlen) != m.end()){
            m[strlen].insert(str);
        }else{
            set<string> s;
            s.insert(str);

            m[strlen] = s;
        }
    }

    return 0;
}
