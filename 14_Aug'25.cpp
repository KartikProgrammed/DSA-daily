#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

//2264. Largest 3-Same-Digit Number in String
// You are given a string num representing a large integer. An integer is good if it meets the following conditions:
// It is a substring of num with length 3.
// It consists of only one unique digit.
// Return the maximum good integer as a string or an empty string "" if no such integer exists.
// Note:
// A substring is a contiguous sequence of characters within a string.
// There may be leading zeroes in num or a good integer.

// Approach:
// 1. Iterate through the string and check every substring of length 3.
// 2. If the substring consists of the same digit, keep track of the maximum found
// 3. Return the maximum good integer or an empty string if none found.
    
// Code:
class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int> resvec;
        string res="";
        for(int i=0,j=1,k=2;k<num.size();i++,j++,k++){
            if(num[i]==num[j] && num[i]==num[k]){
                resvec.push_back(num[i]-'0');
            }
        }
        sort(resvec.begin(),resvec.end());
        int n=resvec.size()-1;
        if(n>=0){
            int num=resvec[n];
            char temp=num+'0';
            res=string(3, temp);
        }
        return res;
    }
};


//402. Remove K Digits

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Approach:
// 1. Use a stack to maintain the digits of the resulting number.
// 2. Iterate through the digits of num, and for each digit, pop from the stack while the current digit is smaller than the top of the stack and k is greater than 0.
// 3. Push the current digit onto the stack.
// 4. If k is still greater than 0 after processing all digits, remove the last k digits from the stack.

// Code:
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        string res="";
        for(int i=0;i<num.size();i++){
            while(!stk.empty() && stk.top()>num[i] && k>0){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while(k>0 && !stk.empty()){
            stk.pop();
            k--;
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(),res.end());
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') idx++;
        res = res.substr(idx);
        if (res.empty()) return "0";
        return res;
    }
};