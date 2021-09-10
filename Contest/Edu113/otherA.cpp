#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        string s;
        cin>>s;
        bool f1 = false,f2 =false;
        int j = -1;
        for(int i = 0;i<x;i++){
            if(s[i] == 'a') f1 = true;
            else f2 = true;
            if(f1 && f2){
                j = i;
                break;
            }
        }
        if(j == -1) cout<<"-1 -1"<<'\n';
        else cout<<j<<" "<<j+1<<'\n';
        
    }
    return 0;
}