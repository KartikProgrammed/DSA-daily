#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 2275:-Largest Combination With Bitwise AND Greater Than Zero
// The bitwise AND of an array nums is the bitwise AND of all integers in nums.

// For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
// Also, for nums = [7], the bitwise AND is 7.
// You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.

// Return the size of the largest combination of candidates with a bitwise AND greater than 0

//CODE:-
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCounts(32, 0);
        
        for (int candidate : candidates) {
            for (int bit = 0; bit < 32; ++bit) {
                if (candidate & (1 << bit)) { //checks for the bit 1 at different positions 
                    bitCounts[bit]++;
                }
            }
        }
        return *max_element(bitCounts.begin(), bitCounts.end());
    }
};

//dry run
// for ex, choose [2,3]
// 2 is selected first 
//     32 times a loop will run as:
//         2 & (1<<0) == 2 & 0001 = 0
//         2 & (1<<1) == 2 & 0010 = 1 since 2 is 0010 and now the array bitcount will be incremented on index 1
//         2 & (1<<2) == 2 && 0100 =0 
//         so on 
// 3 is selected now and done the same way

// like this we can get the max elements which have 1 on a common position, when we have 1 at a common position, their AND is always > 0 and we return the max element of the bitcount arr

//Problem 231:- Power of Two
// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

//CODE:-
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1))==0;
    }
};

//Problem 29:- Divide two integers
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

//CODE:-
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        bool sign=true;
        if(dividend>=0 && divisor<0) 
            sign=false;
        if(dividend<0 && divisor>=0)
            sign=false;
        long n=abs(dividend);
        long d=abs(divisor);
        divisor=abs(divisor);
        long quotient=0;
        while(n>=d){
            int cnt=0;
            while(n >= (d<<(cnt+1))){
                cnt+=1;
            }
            quotient+=1<<cnt;
            n-=(d<<cnt);
        }
        if(quotient==(1<<31) && sign){
            return INT_MAX;
        }
        if(quotient==(1<<31) && !sign){
            return INT_MIN;
        }
        return sign? quotient:-quotient;
    }
};