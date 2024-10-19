#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 90:- Subset II
//DESCRIPTION:- Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
//NOTE:- the order of return must also be a sorted order and lexical order

//CODE:-
class Solution {
public:

    void recursion(int ind,vector<int> &nums,vector<vector<int>> &result,vector<int> &subs){
        result.push_back(subs);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){ //continues the loop for any duplicate elements if found
                continue; //[1,2,2] if suppose we at 2, the other 2 will be skipped since it is expected to create only 1 recursive call if not done, we would have 2 [2,2]
            }
            subs.push_back(nums[i]);
            recursion(i+1,nums,result,subs); // updates the index and head recursion is executed
            subs.pop_back();  //backtracks to other possible subsets
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subs;
        sort(nums.begin(),nums.end());
        recursion(0,nums,result,subs);
        return result;
    }
};