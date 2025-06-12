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

//3423. Maximum Difference Between Adjacent Elements in a Circular Array
//Given a circular array nums, find the maximum absolute difference between adjacent elements.
// Note: In a circular array, the first and last elements are adjacent.

//Approach:
// Iterate through the array and calculate the absolute difference between adjacent elements, including the circular connection.

// CODE:
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int curr;
            if(i==nums.size()-1){
                curr=abs(nums[i]-nums[0]);
            }
            else{
                curr=abs(nums[i]-nums[i+1]);
            }
            res=max(curr,res);
        }
        return res;
    }
};

//28. Find the Index of the First Occurrence in a String
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack

//Approach:
//use two loops to iterate through the haystack and needle strings, checking for a match.

// CODE:
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++){
            if(haystack[i]==needle[0] && i+needle.length()<=haystack.length()){
                bool found=true;
                int k;
                for(int j=0,k=i;j<needle.size();j++,k++){
                    if(needle[j]!=haystack[k]){
                        found=false;
                        break;
                    }
                }
                if(found){
                    return i;
                }
            }
            continue;
        }
        return -1;
    }
};