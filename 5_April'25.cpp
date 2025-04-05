#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 1863. Sum of All Subset XOR Totals
// The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
// For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// Given an array nums, return the sum of all XOR totals for every subset of nums. 
// Note: Subsets with the same elements should be counted multiple times.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

//APPROACH:-
//RECURSION EITHER USE THE NUM IN XOR OR DONT

//CODE:-
class Solution {
public:
    int recursion(vector<int> nums,int index,int xors){
        if(index==nums.size()){
            return xors;
        }
        int with=recursion(nums,index+1,xors^nums[index]);
        int without=recursion(nums,index+1,xors);
        return with+without;
    }
    int subsetXORSum(vector<int>& nums) {
        return recursion(nums,0,0);
    }
};