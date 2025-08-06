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