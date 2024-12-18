#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//496. Next Greater Element I
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above

//CODE:-
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> helper;
        for(int i=0;i<nums2.size();i++){
            while(!helper.empty() && helper.top()<nums2[i]){
                map[helper.top()]=nums2[i];
                helper.pop();
            }
            helper.push(nums2[i]);
        }
        while(!helper.empty()){
            map[helper.top()]=-1;
            helper.pop();
        }
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            result.push_back(map[nums1[i]]);
        }
        return result;
    }
};


//503. Next Greater Element II
//Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

//CODE:-
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1); 
        stack<int> helper; 
        
        for (int i = 0; i < 2 * n; ++i) {
            int currentIndex = i % n;
            while (!helper.empty() && nums[helper.top()] < nums[currentIndex]) {
                result[helper.top()] = nums[currentIndex];
                helper.pop();
            }
            if (i < n) {
                helper.push(currentIndex);
            }
        }
        
        return result;
    }
};


//1475. Final Prices With a Special Discount in a Shop
// You are given an integer array prices where prices[i] is the price of the ith item in a shop.
// There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.
// Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.

//CODE:-
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> helper;
        vector<int> result(prices.size(),0);
        for(int i=0;i<prices.size();i++){
            while(!helper.empty() && prices[helper.top()]>=prices[i]){
                int curr=helper.top();
                result[curr]=prices[curr]-prices[i];
                helper.pop();
            }
            helper.push(i);
        }
        while(!helper.empty()) {
            int idx = helper.top();
            result[idx] = prices[idx];
            helper.pop();
        }
        return result;
    }
};
