#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//2780. Minimum Index of a Valid Split
// An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
// You are given a 0-indexed integer array nums of length n with one dominant element.
// You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:
// 0 <= i < n - 1
// nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
// Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
// Return the minimum index of a valid split. If no valid split exists, return -1.

//APPROACH:-
//try split at each ind from 0

//CODE:-
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        for(int num:nums){
            map2[num]++;
        }
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            map1[num]++;
            map2[num]--;

            int n1=i+1;
            int n2=n-i-1;

            if(map1[num]>n1/2 && map2[num]>n2/2){
                return i;
            }
        }
        return -1;
    }
};


// 733. Flood Fill
// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill:
// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.


//APPROACH:-
//BFS

//CODE:-
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]==color){
            return image;
        }
        q.push({sr,sc});
        int curr=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            if(x>0 && image[x-1][y]==curr){
                image[x-1][y]=color;
                q.push({x-1,y});
            }
            if(x<m-1 && image[x+1][y]==curr){
                image[x+1][y]=color;
                q.push({x+1,y});
            }
            if(y>0 && image[x][y-1]==curr){
                image[x][y-1]=color;
                q.push({x,y-1});
            }
            if(y<n-1 && image[x][y+1]==curr){
                image[x][y+1]=color;
                q.push({x,y+1});
            }
        }
        return image;
    }
};