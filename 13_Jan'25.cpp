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

//3223. Minimum Length of String After Operations
// You are given a string s.
// You can perform the following process on s any number of times:
// Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
// Delete the closest character to the left of index i that is equal to s[i].
// Delete the closest character to the right of index i that is equal to s[i].
// Return the minimum length of the final string s that you can achieve.

//APPROACH:-
//find the count of each character 
// we notice the odd numbers have at max +1 effect to the result and even number have at max +2 effect to the res
//aaaa->aa
//aaa->a
//aaaaa->a
//using this intuition and adding upon some more base cases we build the below code

//CODE:- (beats  98%)
class Solution {
public:
    int minimumLength(string s) {
        vector<int> map(26,0);
        int res=0;
        for(int i=0;i<s.length();i++){
            map[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(map[i]!=0 && map[i]%2==0){
                res+=2;
            }
            else if(map[i]!=0 && map[i]%2!=0){
                res+=1;
            }

        }
        return res;
    }
};