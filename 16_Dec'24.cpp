#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
using namespace std;

//204. Count Primes
//Given an integer n, return the number of prime numbers that are strictly less than n.

//APPROACH:-
//Sieve of Eratosthenes - please go and watch a video on it very hard to explain with comments

//CODE:-
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n,1);
        for(double i=2;i<primes.size();i++){
            double j=i;
            while(i*j<n){
                primes[i*j]=0;
                j++;
            }
        }
        int result=0;
        for(int i=2;i<primes.size();i++){
            if(primes[i]==1){
                result++;
            }
        }
        return result;
    }
};

//78. Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

//APPROACH:-
//Backtracking and basic recursion 

//CODE:-
class Solution {
public:
    vector<vector<int>> recursion(vector<int>nums, vector<vector<int>> res){
        if(nums.empty()){
            return res;
        }
        int n=nums[0];
        nums.erase(nums.begin());
        int size=res.size();
        for(int i=0;i<size;i++){
            vector<int> temp= res[i];
            temp.push_back(n);
            res.push_back(temp);
        }
        return recursion(nums,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        return recursion(nums,res);
    }
};