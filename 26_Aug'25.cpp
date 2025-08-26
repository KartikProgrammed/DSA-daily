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

//3000. Maximum Area of Longest Diagonal Rectangle
// You are given a 2D 0-indexed integer array dimensions.
// For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.
// Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.

//Approach:-
// We can calculate the diagonal of each rectangle using the Pythagorean theorem. The diagonal d of a rectangle with length l and width w is given by d = sqrt(l^2 + w^2). We can iterate through the list of rectangles, calculate the diagonal for each rectangle, and keep track of the maximum diagonal and the corresponding area.

//CODE:-
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=0;
        int maxDiag=0;
        for(int i=0;i<dimensions.size();i++){
            int len=dimensions[i][0];
            int breadth=dimensions[i][1];
            int diag=len*len+breadth*breadth;
            if(diag>maxDiag){
                maxDiag=diag;
                maxArea=len*breadth;
            }
            else if(diag==maxDiag){
                maxArea=max(maxArea,len*breadth);
            }
        }
        return maxArea;
    }
};


//1358. Number of Substrings Containing All Three Characters

// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

//Approach:-
// We can use a sliding window approach to solve this problem. We will maintain a window that contains at least one occurrence of each character a, b, and c. We will keep track of the count of each character in the current window and the number of valid substrings that can be formed with the current window.

//CODE:-
class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int n=s.length();
        int right=0;
        int res=0;
        unordered_map<char,int> map;
        while(right<s.length() && left<=right){
            map[s[right]]++;
            while(map.size()==3){
                res += (n - right);       
                map[s[left]]--;
                if (map[s[left]] == 0) {
                    map.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return res;
    }
};

//1423. Maximum Points You Can Obtain from Cards

// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

//Approach:-
// We can use a sliding window approach to solve this problem. We will calculate the total sum of the array and then find the minimum sum of the subarray of size n-k. The maximum score will be the total sum minus the minimum sum of the subarray.

//CODE:-
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0;
        int right=0;
        int n=cardPoints.size();
        int size=n-k;
        int ans=0;
        int tot=0;
        for(int i=0;i<cardPoints.size();i++){
            tot+=cardPoints[i];
        }
        int curr=0;
        while(right<size){
            curr+=cardPoints[right];
            right++;
        }
        ans=tot-curr;
        while(right<n){
            curr+=cardPoints[right++];
            curr-=cardPoints[left++];
            ans=max(ans,tot-curr);
        }
        return ans;
    }
};