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

//2342. Max Sum of a Pair With Equal Sum of Digits
// You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

// Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

//APPROACH:- (TLE)
//find the sum of digits for each index
//for the same index find the max sum of nums[i],nums[j]

//CODE:-
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            vector<int> sumofdig(nums.size(),0);
            for(int i=0;i<nums.size();i++){
                int curr=nums[i];
                int sum=0;
                while(curr>0){
                    int rem=curr%10;
                    sum+=rem;
                    curr/=10;
                }
                sumofdig[i]=sum;
            }
            int res=0;
            bool changed=false;
            for(int i=0;i<sumofdig.size();i++){
                for(int j=i+1;j<sumofdig.size();j++){
                    if(sumofdig[i]==sumofdig[j]){
                        res=max(res,nums[i]+nums[j]);
                        changed=true;
                    }
                }
            }
            if(!changed){
                return -1;
            }
            return res;
        }
    };


//APPROACH:-
//store the sum of digits as key and the numbers as elements in a priority queue all this in an unordered map
//traverse this map and then find the sum of top2 numebers
//compute max for res and return -1 if no same sum of digits found

//CODE:-
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<int,priority_queue<int>> sumofdig;
            for(int i=0;i<nums.size();i++){
                int curr=nums[i];
                int sum=0;
                while(curr>0){
                    int rem=curr%10;
                    sum+=rem;
                    curr/=10;
                }
                sumofdig[sum].push(nums[i]);
            }
            int res=0;
            bool changed=false;
            for(auto&iter:sumofdig){
                int key=iter.first;
                if(iter.second.size()==1){
                    continue;
                }
                else{
                    changed=true;
                    int first = sumofdig[key].top(); sumofdig[key].pop();
                    int second = sumofdig[key].top(); sumofdig[key].pop();
                    res=max(res,first+second);
                }
            }
            if(!changed){
                return -1;
            }
            return res;
        }
    };