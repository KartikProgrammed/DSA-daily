#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

//APPROACH:-
//maintain an array of pairs which would contain the i,j of the poisitions of 0 in the matrix which would be then traced and their rows and columns would be converted to 0

//CODE:-
class Solution {
public:
    void helper(vector<vector<int>> &matrix,int i,int j){
        for(int k=0;k<matrix[0].size();k++){
            matrix[i][k]=0;
        }
        for(int k=0;k<matrix.size();k++){
            matrix[k][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> map;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    map.push_back({i,j});
                }
            }
        }
        for(auto x:map){
            helper(matrix,x.first,x.second);
        }
    }
};

//48. Rotate Image
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

//CODE:-
class Solution {
public:
    void swap(vector<vector<int>> &matrix,int i,int j){
        int temp=matrix[i][j];
        matrix[i][j]=matrix[j][i];
        matrix[j][i]=temp;
    }
    void swap2(vector<vector<int>> &matrix,int i,int j){
        int size=matrix[0].size();
        int temp=matrix[i][j];
        matrix[i][j]=matrix[i][size-j-1];
        matrix[i][size-j-1]=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int i=0,j=0;
        while(i<matrix.size()){
            j=i;
            while(j<matrix[0].size()){
                swap(matrix,i,j);
                j++;
            }
            i++;
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size()/2;j++){
                swap2(matrix,i,j);
            }
        }
    }

};

//769. Max Chunks To Make Sorted
// You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

// We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

// Return the largest number of chunks we can make to sort the array.

//CODE:-
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxVal = 0; 
        int count = 0;  

        for (int i = 0; i < arr.size(); i++) {
            maxVal = max(maxVal, arr[i]); 
            if (maxVal == i) { 
                count++;
            }
        }

        return count;
    }
};
