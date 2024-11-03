#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;

//DailyProblem 796:- Rotate String
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 
//CODE:-
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string doubled = s + s; // double the string so that even if we shift it entirely, it can be found 
        return (doubled.find(goal) != string::npos); //find the string wanted from the new string "doubled"
    }
};