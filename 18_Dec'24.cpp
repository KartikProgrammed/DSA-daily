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


//42. Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

//CODE:-

//BASIC understanding
// calculate maximum heights of towers to the right and the left for each ith element, take the minimum of these towers and subtract with the current tower's height. Sum ut all up to get the final result

//APPROACH 1(TLE)
//Left max is updated as we proceed in the loop,rightmax is calculated everytime for n iterations
//TLE doesnt pass the last case
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        int leftmax=height[0];
        int count=0;
        for(int i=1;i<height.size()-1;i++){
            int j=i;
            int rightmax=INT_MIN;
            while(j<height.size()){
                rightmax=height[j]>rightmax?height[j]:rightmax;
                j++;
            }
            int mini=min(leftmax,rightmax);
            int incr=mini-height[i];
            if(incr>0){
                count+=incr;
            }
            if(height[i]>leftmax){
                leftmax=height[i];
            }
        }
        return count;
    }
};

//APPROACH 2:- Beats 100%
//just create an array to store the rightmax and the leftmax of each element~ basically trading off space for some time 
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        vector<int> rightMax(height.size(),-1);
        vector<int> leftMax(height.size(),-1);
        int currL;
        int currR;
        int count=0;
        for(int i=0,j=height.size()-1;i<height.size() && j>=0;i++,j--){
            if(i==0){
                leftMax[i]=-1;
                currL=height[i];
            }
            else {
                leftMax[i]=currL;     
                currL=max(currL, height[i]);
            }
            if(j==height.size()-1){
                rightMax[j]=-1;
                currR=height[j];
            }
            else {
                rightMax[j]=currR;
                currR=max(currR, height[j]);
            }
        }
        for(int i=1;i<height.size()-1;i++){
            int mini=min(leftMax[i],rightMax[i]);
            if(mini==-1){
                break;
            }
            int incr=mini-height[i];
            if(incr>0){
                count+=incr;
            }
        }
        return count;
    }
};
