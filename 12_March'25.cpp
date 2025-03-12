#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 2529. Maximum Count of Positive Integer and Negative Integer
// Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
// In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
// Note that 0 is neither positive nor negative.

//APPROACH:-
// Create two pointers, negative and positive. Iterate both of them till the pointer reaches a point wherein the num's array doesn't have a positive value or a zero. Then iterate the positive value until we get the iterator to a point wherein the num's array doesn't have a value that is zero. And stop it right there. Subtract the positive iterator from the size of the array and return max

//CODE:-
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int neg=0;
            int pos=0;
            while(neg<nums.size() && nums[neg]<0){
                neg++;
            }
            pos=neg;
            while(pos<nums.size() && nums[pos]==0){
                pos++;
            }
            pos=nums.size()-pos;
            return max(neg,pos);
        }
    };