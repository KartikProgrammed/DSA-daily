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


// 1061. Lexicographically Smallest Equivalent String
// You are given two strings of the same length s1 and s2 and a string baseStr.
// We say s1[i] and s2[i] are equivalent characters.
// For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
// Equivalent characters follow the usual rules of any equivalence relation:
// Reflexivity: 'a' == 'a'.
// Symmetry: 'a' == 'b' implies 'b' == 'a'.
// Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
// For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.
// Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

// Approach:
// Use union-find to group equivalent characters together.

// CODE:
class Solution {
public:
    int find(int x,vector<int> &parent){
        if(parent[x]!=x){
            parent[x]=find(parent[x],parent);
        }
        return parent[x];
    }

    void unite(int x,int y,vector<int> &parent){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py){
            return ;
        }
        if(px<py){
            parent[py]=px;
        }
        else{
            parent[px]=py;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        vector<int> parent(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            unite(s1[i]-'a',s2[i]-'a',parent);
        }

        string res="";
        for(int i=0;i<baseStr.length();i++){
            int curr=find(baseStr[i]-'a',parent);
            res+=(char)curr+'a';
        }
        return res;
    }
};

//85. Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Approach:
// Use dynamic programming to calculate the height of each column and then use a stack to find the largest rectangle in each row.

// CODE:
class Solution {
public:
    vector<int> newVec(vector<char> &curr,vector<int> &prev){
        int n=curr.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=curr[i]=='1'?1+prev[i]:0;
        }
        return res;
    }
    int maxRect(vector<int> curr){
        int n=curr.size();
        int res=0;
        stack<int> helper;
        vector<int> NSL(n,-1);
        vector<int> NSR(n,n);

        for(int i=0;i<n;i++){
            while(!helper.empty() && curr[helper.top()]>=curr[i]){
                helper.pop();
            }
            if(!helper.empty()){
                NSL[i]=helper.top();
            }
            helper.push(i);
        }

        while(!helper.empty()){
            helper.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!helper.empty() && curr[helper.top()]>=curr[i]){
                helper.pop();
            }
            if(!helper.empty()){
                NSR[i]=helper.top();
            }
            helper.push(i);
        }

        for(int i=0;i<n;i++){
            int temp=(NSR[i]-NSL[i]-1)*curr[i];
            res=max(temp,res);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        if(n==0){
            return 0;
        }
        int m=matrix[0].size();
        
        vector<int> prev(m,0);
        int res=0;
        for(int i=0;i<matrix.size();i++){
            prev=newVec(matrix[i],prev);
            int curr=maxRect(prev);
            res=max(curr,res);
        }
        return res;
    }
};