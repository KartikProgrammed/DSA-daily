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

//1400. Construct K Palindrome Strings
//Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

//APPROACH:-
//if the size of s==k the ans will be true since each char can be used as a pallindrome
//if the size is < k the ans will always be false
//if the no of odd chars> k the ans will always be false
//otherwise true everytime

//CODE:-
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k){
            return false;
        }
        if(s.length()==k){
            return true;
        }
        vector<int> map(26,0);
        for(int i=0;i<s.length();i++){
            map[s[i]-'a']++;
        }
        int oddcounts=0;
        for(int i=0;i<26;i++){
            if(map[i]%2!=0){
                oddcounts++;
            }
        }
        if(oddcounts>k){
            return false;
        }
        return true;
    }
};