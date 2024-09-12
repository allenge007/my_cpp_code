#include<bits/stdc++.h>
using namespace std;
string str;
string tmp="You are right, but ";
int main(){
    getline(cin, str);
    for(int i=0;i<19;i++){
        if(str[i]!=tmp[i]){
            printf("Human");
            return 0;
        }
    }
    printf("AI");
    return 0;
}