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

// 2438. Range Product Queries of Powers
// Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.
// You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.
// Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

// Approach:
// 1. Generate the powers of 2 that sum to n and store them in a
//    vector called powers.
// 2. For each query, calculate the product of the specified range in powers.

// Code:
#define MOD 1000000007
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int power=0;
        vector<long long> powers;
        while(n>0){
            int num=n&1;
            n>>=1;
            if(num==1){
                powers.push_back(1LL << power);
            }
            power++;
        }
        vector<int> answers;
        for(int i=0;i<queries.size();i++){
            int ans=1;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                ans=(1LL * ans*powers[j]) % MOD;
            }
            answers.push_back(ans);
        }
        return answers;
    }
};


//496. Next Greater Element I
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Approach:
// 1. Use a stack to keep track of the next greater elements.
// 2. Iterate through nums2 and for each element, pop elements from the stack until the top of the stack is greater than the current element.
// 3. Store the next greater element in a map for quick access.
// 4. For each element in nums1, retrieve the next greater element from the map

// Code:
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> stk;
        for(int i=0;i<nums2.size();i++){
            while(!stk.empty() && stk.top()<nums2[i]){
                map[stk.top()]=nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            if(map.find(nums1[i])!=map.end()){
                ans[i]=map[nums1[i]];
            }
        }
        return ans;
    }
};


// 503. Next Greater Element II

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

// Approach:
// 1. Use a stack to keep track of the indices of the elements.
// 2. Iterate through the array twice to handle the circular nature.
// 3. For each element, pop elements from the stack until the top of the stack
//    is greater than the current element.

// Code:
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