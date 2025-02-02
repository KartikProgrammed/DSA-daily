#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//1752. Check if Array Is Sorted and Rotated
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.


//APPROACH:- (Beats 100%)
//find the number of rotations in the array if it exceeds 1 return false
//if the rotations is 1 and the 0th element is smaller than the last element return false
//else return true
//this is because if we rotate it accordingly we'll get another rotation
//eg 
// 34125 now rotations=1 at 2nd index
//but last element is greater than 1st element
//after rotating it back it becomes 12534 and we have one more rotaton hence this is false

//CODE:-
class Solution {
public:
    bool check(vector<int>& nums) {
        int rot=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                rot++;
            }
        }
        if(rot>1){
            return false;
        }
        if(rot==1 && nums[0]<nums[nums.size()-1]){
            return false;
        }
        return true;
    }
};

//347. Top K Frequent Elements
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

//APPROACH:-
//great question to test all the standard library of C++
//the catch is in the constraints which also includes negative number so an unordered map is a must
//we push the freq of each number into a priority queue along with the number itself
//push the top k numbers in the vector res if not already included
//use of set has been done to avoid duplicate pushing in the result vector

//CODE:-
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto& iter:map){
            pq.push({iter.second,iter.first});
        }
        vector<int> res;
        unordered_set<int> set;
        while(k>0 && !pq.empty()){
            int top=pq.top().first;
            int num=pq.top().second;
            pq.pop();  
            if(set.find(num) == set.end()){
                set.insert(num);
                res.push_back(num);
            }
            k--;
        }
        
        return res;
    }
};