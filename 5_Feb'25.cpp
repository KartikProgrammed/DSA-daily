#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 1790. Check if One String Swap Can Make Strings Equal
// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

//APPROACH:-
//1st loop calculates the number of mismatches
//2nd loop runs only when swap is exactly 1
//store the swapped variables and check if its a successful swap or just a character change 

//CODE:- (BEATS 100%)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int mismatches=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                mismatches++;
            }
        }
        if(mismatches==2){
            char change;
            char change2;
            int flag=0;
            for(int i=0;i<n;i++){
                if(flag==0 && s1[i]!=s2[i]){
                    change=s2[i];
                    change2=s1[i];
                    flag=1;
                }
                else if(flag==1 && s1[i]!=s2[i]){
                    if(s1[i]==change && s2[i]==change2){
                        return true;
                    }
                }
            }
        }
        else if(mismatches==0){
            return true;
        }
        return false;
    }
};