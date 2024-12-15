#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
using namespace std;

//2220. Minimum Bit Flips to Convert Number
// A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

// For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
// Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

//APPROACH:-
//pretty simple and easy approach
//if we xor 2 operands we recieve an output wherein the number of 1s indicate the number of bit changes
//for example, 10=1010 and 7= 111.. we XOR both of them to get 1101 wherein we get 3 1s, which tells us 3 bit changes are required.

//CODE:-
//BEATS 100%
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result=0;
        int xorr=start^goal;
        while(xorr>0){
            if(xorr%2==1){
                result++;
            }
            xorr/=2;
        }
        return result;
    }
};

//136. Single Number
//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

//APPROACH:-
//XOR all the numbers and the remainder will be the missing number always
//Example:- 2,2,1
//10 XOR 10 XOR 01 gives 01 which is 1 and that is the missing number here

//CODE:-
//BEATS 100%
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            result=result^nums[i];
        }
        return result;
    }
};