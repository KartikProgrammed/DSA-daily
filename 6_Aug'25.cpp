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

// 3479. Fruits Into Baskets III

// You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
// From left to right, place the fruits according to these rules:
// Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
// Each basket can hold only one type of fruit.
// If a fruit type cannot be placed in any basket, it remains unplaced.
// Return the number of fruit types that remain unplaced after all possible allocations are made.

// Approach:
// Sort the fruits and baskets, then iterate through the fruits and try to place them in the
// leftmost available basket that can accommodate them. Count the number of unplaced fruits.

// CODE:
class Solution {
public:
    void build(int i,int l,int r,vector<int>&baskets,vector<int> &segmentTree){
        if(l==r){
            segmentTree[i]=baskets[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,baskets,segmentTree);
        build(2*i+2,mid+1,r,baskets,segmentTree);
        segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
    }
    bool query(int i,int l,int r,int fruit,vector<int> &segments){
        if(segments[i]<fruit){
            return false;
        }
        if(l==r){
            segments[i]=-1;
            return true;
        }
        bool placed=false;
        int mid=l+(r-l)/2;
        if(segments[2*i+1]>=fruit){
            placed= query(2*i+1,l,mid,fruit,segments);
        }
        if(!placed){
            placed=query(2*i+2,mid+1,r,fruit,segments);
        }
        segments[i]=max(segments[2*i+1],segments[2*i+2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int> segments(4*n,-1);
        build(0,0,n-1,baskets,segments);
        int res=0;
        for(int fruit:fruits){
            if(!query(0,0,n-1,fruit,segments)){
                res++;
            }
        }
        return res;
    }
};


//40. Combination Sum II
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Approach:
// Use backtracking to explore all combinations of candidates that sum to the target, ensuring that each
// candidate is only used once in each combination.

// CODE:
class Solution {
public:
    void recursion(vector<vector<int>> &res,vector<int>&curr,vector<int> &candidates,int sum,int i,int target){
        if(sum==target){
            res.push_back(curr);
            return ;
        }
        if(i>=candidates.size() || sum>target){
            return; 
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1]){
                continue;
            }
            if(sum + candidates[j] > target)
                break;
            curr.push_back(candidates[j]);
            recursion(res,curr,candidates,sum+candidates[j],j+1,target);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        recursion(res,curr,candidates,0,0,target);
        return res;
    }
};


//90. Subsets II

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Approach:
// Use backtracking to explore all subsets, ensuring that duplicates are handled by skipping over
// duplicate elements in the input array.

// CODE:
class Solution {
public:
    void recursion(vector<vector<int>>&res,vector<int> &curr,vector<int> &nums,int i){
        res.push_back(curr);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            curr.push_back(nums[j]);
            recursion(res,curr,nums,j+1);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        recursion(res,curr,nums,0);
        return res;
    }
};

// 216. Combination Sum III
// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
 

// Approach:
// Use backtracking to explore all combinations of numbers from 1 to 9 that sum to
// the target n, ensuring that each number is used at most once and that the combination
// contains exactly k numbers.


//CODE:
class Solution {
public:
    void recursion(vector<vector<int>>&res,vector<int> &curr,int sum,int target,int i,int k){
        if(sum==target && curr.size()==k){
            res.push_back(curr);
            return ;
        }
        if(sum>target || curr.size()>k){
            return ;
        }
        for(int j=i;j<=9;j++){
            curr.push_back(j);
            recursion(res,curr,sum+j,target,j+1,k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        recursion(res,curr,0,n,1,k);
        return res;
    }
};


// 17. Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Approach:
// Use backtracking to explore all possible combinations of letters for the given digits, using a mapping
// of digits to letters. Each digit corresponds to a set of letters, and we generate combinations by
// recursively appending letters for each digit.

// CODE:
class Solution {
public:
    void recursion(vector<string> &res,string &curr,string digits,int i,unordered_map<int,string> &map){
        if(curr.length()==digits.length()){
            res.push_back(curr);
            return ;
        }
        string tbu=map[digits[i]-'0'];
        for(int j=0;j<tbu.length();j++){
            curr.push_back(tbu[j]);
            recursion(res,curr,digits,i+1,map);
            curr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        unordered_map<int, string> map;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";

        vector<string> res;
        string curr="";
        recursion(res,curr,digits,0,map);
        return res;
    }
};