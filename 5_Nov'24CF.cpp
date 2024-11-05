#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;
//Problem 4A-Watermelon
bool watermelon(int piece){
    if(piece<=2){
        return false;
    }
    return (piece%2==0);
}
void main(){
    int pieces;
    scanf("%d",&pieces);
    if(watermelon(pieces)){
        printf("YES");
    }
    else{
        printf("NO");
    }
}