#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 2914:- minimum number of changes to make binary string beautiful
// You are given a 0-indexed binary string s having an even length.

// A string is beautiful if it's possible to partition it into one or more substrings such that:

// Each substring has an even length.
// Each substring contains only 1's or only 0's.
// You can change any character in s to 0 or 1.

// Return the minimum number of changes required to make the string s beautiful.

//CODE:-
//Intruisive approach:-
//why take pair of 2? since an even number of same digit is the requirement, a pair of 2 is the smallest even pair
class Solution {
public:
    int minChanges(string s) {
        if(s.length()%2!=0){ //if the length to the input is not even returning -1 since invalid string
            return -1;
        }
        int change=0;
        int j=0;
        int i=1; //working in pairs 
        while(i<s.length()){
            j=i-1; //j is the previous element i is the 2nd
            if(s[i]==s[j]){ //if both the elements same 00 || 11 skip
                i+=2;
                continue;
            }
            else{
                change++; // 01 -> 00 so change increases by 1
            }
            i+=2;
        }
        return change;
    }
};