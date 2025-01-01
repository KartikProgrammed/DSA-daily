#include <bits/stdc++.h>
using namespace std;

//494. Target Sum
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target

//APPROACH 1:- 
//Basic recursion very poorly passes the cases though but easy
//CODE
class Solution {
public:
    int recursion(vector<int>& nums,int target,int curriter,int currsum){
        if(curriter==nums.size()){
            if(currsum==target){
                return 1;
            }
            else
                return 0;
        }
        int plus=recursion(nums,target,curriter+1,currsum+nums[curriter]);
        int minus=recursion(nums,target,curriter+1,currsum-nums[curriter]);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(nums,target,0,0);
    }
};

//APPROACH 2:- 
//MEMOISATION

//CODE:- 
class Solution {
public:
    int recursion(vector<int>& nums,int target,int curriter,int currsum,unordered_map<string,int> &map){
        if(curriter==nums.size()){
            if(currsum==target){
                return 1;
            }
            else
                return 0;
        }
        string key=to_string(curriter)+'_'+to_string(currsum);
        if(map.count(key)){
            return map[key];
        }
        int plus=recursion(nums,target,curriter+1,currsum+nums[curriter],map);
        int minus=recursion(nums,target,curriter+1,currsum-nums[curriter],map);
        return map[key]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> map;
        return recursion(nums,target,0,0,map);
    }
};