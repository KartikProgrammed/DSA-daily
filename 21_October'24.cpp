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
        int num=digits[curr]-'0';
        string mean=mp[num];
        for(int i=0;i<mean.length();i++){
            output=output+mean[i];
            function(output,curr+1,digits,result,mp);
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