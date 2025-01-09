#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

//2185. Counting Words With a Given Prefix
// You are given an array of strings words and a string pref.
// Return the number of strings in words that contain pref as a prefix.
// A prefix of a string s is any leading contiguous substring of s.


//APPROACH:-
//brute force

//CODE:-
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(int i=0;i<words.size();i++){
            bool flag=true;
            for(int j=0;j<pref.length();j++){
                if(words[i][j]!=pref[j]){
                    flag=false;
                    break;
                }
                
            }
            if(flag){
                res++;
            }
        }
        return res;
    }
};