#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;
//Problem 4A-Watermelon
// bool watermelon(int piece){
//     if(piece<=2){
//         return false;
//     }
//     return (piece%2==0);
// }
// int main(){
//     int pieces;
//     scanf("%d",&pieces);
//     if(watermelon(pieces)){
//         printf("YES");
//     }
//     else{
//         printf("NO");
//     }
// }

//Problem 236A:- Boy Or girl
int main(){
    string inp;
    cin >> inp;
    int hm[26]={0};
    for(int i=0;i<inp.length();i++){
        hm[inp[i]-'a']++;
    }
    int count=0;
    for(int i=0;i<26;i++){
        if(hm[i]>0){
            count++;
        }
        else{
            continue;
        }
    }
    if(count%2==0){
        printf("CHAT WITH HER!");
    }
    else{
        printf("IGNORE HIM!");
    }
}