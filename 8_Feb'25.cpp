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

// 2349. Design a Number Container System
// Design a number container system that can do the following:

// Insert or Replace a number at the given index in the system.
// Return the smallest index for the given number in the system.
// Implement the NumberContainers class:

// NumberContainers() Initializes the number container system.
// void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
// int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.


//APPROACH:-
//create 2 maps
//1 stores index->number
//2nd stores number->indices

//CODE:-
class NumberContainers {
    private:
        unordered_map<int, int> map;
        unordered_map<int, set<int>> indices;
        int currindex=0;
    public:
        NumberContainers() {
        }
        
        void change(int index, int number) {
            if(map.find(index)!=map.end()){
                int old=map[index];
                indices[old].erase(index);
                if (indices[old].empty()) {
                    indices.erase(old);
                }
            }
            map[index]=number;
            indices[number].insert(index);
            
        }
        
        int find(int number) {
            if(indices.find(number)!=indices.end()){
                return *indices[number].begin();
            }
            return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */


//55. Jump Game
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

//APPROACH:-
//use DP to try all ways and find all paths

//CODE:-
class Solution {
    public:
        bool recursion(int curr,vector<int> &nums,unordered_map<int,bool> &memo){
            if(curr==nums.size()-1){
                return true;
            }
            if(nums[curr]==0 && curr<nums.size()){
                return false;
            }
            if (memo.find(curr) != memo.end()) {
                return memo[curr];
            }
            bool res=false;
            for(int i=0;curr+i+1<nums.size() && i<nums[curr];i++){
                if (recursion(curr + i+1, nums, memo)) {
                    res = true;
                    break; 
                }
            }
            return memo[curr]=res;
        }
        bool canJump(vector<int>& nums) {
            unordered_map<int,bool> memo;
            return recursion(0,nums,memo);
        }
    };

//APPROACH 2:- 
//greedy approach

//CODE:-
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int reachable=0;
            for(int i=0;i<nums.size();i++){
                if(reachable<i)
                    return false;
                reachable=max(reachable,nums[i]+i);
            }
            return true;
        }
    };


//45. Jump Game II
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].


//APPROACH:-
//create a current end var and a maxreach var to calculate the max reachable point 
//break when the current end matches last index

//CODE:- (Beats 100%)
class Solution {
    public:
        int jump(vector<int>& nums) {
            int count=0;
            int maxreach=0;
            int currend=0;
            for(int i=0;i<nums.size()-1;i++){
                maxreach = max(maxreach, i + nums[i]);
                if(i==currend){
                    count++;
                    currend = maxreach;
                    if (currend >= nums.size() - 1)
                        break;
                }
            }
            return count;
        }
    };