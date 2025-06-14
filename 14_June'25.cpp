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

// 2566. Maximum Difference by Remapping a Digit
// You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
// Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
// Notes:
// When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
// Bob can remap a digit to itself, in which case num does not change.
// Bob can remap different digits for obtaining minimum and maximum values respectively.
// The resulting number after remapping can contain leading zeroes.

// Approach:
// 1. Convert the number to a string to easily manipulate its digits.
// 2. For each digit, try remapping it to every other digit (0-9).
// 3. Calculate the maximum and minimum values after remapping.
// 4. Return the difference between the maximum and minimum values.

// CODE:
class Solution {
public:
    int minMaxDifference(int num) {
        string nums=to_string(num);
        string maxi="";
        string mini="";
        char curr='\0';

        for(int i=0;i<nums.length();i++){
            if(curr=='\0' && nums[i]!='9'){
                curr=nums[i];
                maxi=maxi+'9';
            }
            else if(nums[i]==curr){
                maxi=maxi+'9';
            }
            else{
                maxi=maxi+nums[i];
            }
        }
        curr='\0';
        for(int i=0;i<nums.length();i++){
            if(curr=='\0' && nums[i]!='0'){
                curr=nums[i];
                mini=mini+'0';
            }
            else if(nums[i]==curr){
                mini=mini+'0';
            }
            else{
                mini=mini+nums[i];
            }
        }
        return stoi(maxi)-stoi(mini);
    }
};

//1752. Check if Array Is Sorted and Rotated
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
// There may be duplicates in the original array.
// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

// Approach:
//keep a bool flag to check if the array is sorted and rotated.


// CODE:
class Solution {
public:
    bool check(vector<int>& nums) {
        bool rotated=false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1] && !rotated){
                rotated=true;
                continue;
            }
            else if(nums[i]>nums[i+1] && rotated){
                return false;
            }
        }
        if(rotated && nums[0]<nums[nums.size()-1]){
            return false;
        }
        return true;
    }
};