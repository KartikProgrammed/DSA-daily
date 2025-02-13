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

//3066. Minimum Operations to Exceed Threshold Value II
// You are given a 0-indexed integer array nums, and an integer k.

// In one operation, you will:

// Take the two smallest integers x and y in nums.
// Remove x and y from nums.
// Add min(x, y) * 2 + max(x, y) anywhere in the array.
// Note that you can only apply the described operation if nums contains at least two elements.

// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

//APPROACH:-
//take a priority min queue push the elements
//pop 2 elements perform the operation and then push it back
//do it until you're left with no element less than k in the priority queue

//CODE:-
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
           priority_queue<double,vector<double>,greater<double>> pq;
           if(nums.size()<2){
            return -1;
           }
           for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
           }
           int count=0;
           while(pq.size() > 1 && pq.top()<k){
            count++;
            double num1=pq.top();
            pq.pop();
            double num2=pq.top();
            pq.pop();
            pq.push(num1*2+num2);
           }
           return count;
        }
    };