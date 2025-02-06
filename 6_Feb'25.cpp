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

//1726. Tuple with Same Product
// Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

//APPROACH:-
//basic intuition to use a hashmap to count the number of times a pair matches
//a pair can get 8 tuples(check examples)
//multiply the pairs with 8 and return

//CODE:-
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                map[nums[i]*nums[j]]++;
            }
        }
        int count=0;
        for(auto&iter:map){
            if(iter.second>1){
                count+=(iter.second*(iter.second-1))/2;
            }
        }
        return 8*count;
    }
};