#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;
//Problem 17:- Letter Combination of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

//CODE:-
class Solution {
public:
    void function(string output,int curr,string digits,vector<string> &result,vector<string> mp){
        if(curr>=digits.length()){
            result.push_back(output);
            return;
        }
        int num=digits[curr]-'0'; //selects the digit
        string mean=mp[num]; //uses the digits meaning which would be traversed in the loop
        for(int i=0;i<mean.length();i++){
            output=output+mean[i];
            function(output,curr+1,digits,result,mp); //next digit recursion done
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mp= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
        vector<string> result;
        string output;
        if (digits.length() == 0) {
            return result;
        }
        function(output,0,digits,result,mp);
        return result;
    }
};

//DAILY PROBLEM
//Problem 1593:- split-a-string-into-the-max-number-of-unique-substrings
// Given a string s, return the maximum number of unique substrings that the given string can be split into.
// You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
// A substring is a contiguous sequence of characters within a string.

//CODE:-
class Solution {
public:
    int tot;
    void solve(int ind, const string& s, set<string>& used, int curr) {
        if (ind == s.size()) {
            tot = max(tot, curr);
            return;
        }

        string temp;
        for (int i = ind; i < s.size(); i++) {
            temp.push_back(s[i]);
            if (used.find(temp) == used.end()) {
                used.insert(temp);
                solve(i + 1, s, used, curr + 1);
                used.erase(temp);  // Backtrack
            }
        }
    }

    int maxUniqueSplit(string s) {
        set<string> used;
        tot = 0;
        solve(0, s, used, 0);
        return tot;
    }
};