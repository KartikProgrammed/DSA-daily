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

// 1865. Finding Pairs With a Certain Sum
// You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:
// Add a positive integer to an element of a given index in the array nums2.
// Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
// Implement the FindSumPairs class:
// FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
// void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
// int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

// Approach:
// 1. Use a hash map to store the frequency of each element in nums2.
// 2. For the add operation, update the frequency of the element at the given index
//    in the hash map.
// 3. For the count operation, iterate through nums1 and for each element, check
//    if the complement (tot - nums1[i]) exists in the hash map. If it does, add
//    the frequency of that complement to the count.

// CODE:
class FindSumPairs {
private:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int,int> map;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(int it:arr2){
            map[it]++;
        }
    }
    
    void add(int index, int val) {
        map[arr2[index]]--;
        arr2[index]=arr2[index]+val;
        map[arr2[index]]++;
    }
    
    int count(int tot) {
        int res=0;
        for(int it:arr1){
            int search=tot-it;
            if(map.find(search)!=map.end()){
                res=res+map[search];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */