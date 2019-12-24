#include <iostream>
#include <string>

using namespace std;
int main() {
    string text;
    int index,happy,sad;
    happy=0;
    sad=0;

    getline(cin,text);
    index = text.find(":-)");
    while(index != -1){
        ++happy;
        index = text.find(":-)",index+3);
    }
    index = text.find(":-(");
    while(index != -1){
        ++sad;
        index = text.find(":-(",index+3);
    }

    if(happy == 0 && sad == 0){
        cout<<"none";
    }
    else if(happy > sad){
        cout<<"happy";
    }
    else if(happy < sad){
        cout<<"sad";
    }
    else{
        cout<<"unsure";
    }
    return 0;
}