#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 40. COMBINATION SUM-II   
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.
//also the returned array should be sorted,in lexical order

// CODE
class Solution {
public:
    void rec(int index,vector<int>&arr,int target,vector<int>& pb,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(pb); //we got the target
            return;
        }
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1]){ //since we need no duplicate elements in our final list we shift any duplicates if found from creating another recursion call since they'll already be counted once
            
                continue; 
            }
            if(arr[i]>target){
                break;
            }
            pb.push_back(arr[i]);
            rec(i+1,arr,target-arr[i],pb,ans); //reduce target by arr[i] and next index is put up as i+1 for satisfying the duplicate constraint again
            pb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> pb;
        rec(0,candidates,target,pb,result);
        return result;
    }
};