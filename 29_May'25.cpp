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

// 3373. Maximize the Number of Target Nodes After Connecting Trees II
// There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
// Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
// Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
// Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
 

class Solution {
public:
    int dfs(vector<vector<int>> &adj_list,int curr,int k,vector<bool> &visited){
        int res=1;
        visited[curr]=true;
        if(k%2!=0){
            res=0;
        }
        for(int neighbour:adj_list[curr]){
            if(!visited[neighbour]){
                res+=dfs(adj_list,neighbour,k+1,visited);
            }
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>> adj_list1(n);
        vector<vector<int>> adj_list2(m);

        for(auto &it:edges1){
            adj_list1[it[0]].push_back(it[1]);
            adj_list1[it[1]].push_back(it[0]);
        }
        for(auto &it:edges2){
            adj_list2[it[0]].push_back(it[1]);
            adj_list2[it[1]].push_back(it[0]);
        }

        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            vector<bool> visited(m,false);
            maxi=max(maxi,dfs(adj_list2,i,1,visited));
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            res[i]=maxi+dfs(adj_list1,i,0,visited);
        }
        return res;
    }
};  

// 1048. Longest String Chain

// You are given an array of words where each word consists of lowercase English letters.
// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
// Return the length of the longest possible word chain with words chosen from the given list of words.

// Approach:
// 1. Sort the words by their lengths.
//start with the longest word and try to find the longest chain by checking if the current word can be formed by removing one character from the previous word.

//Code:-
class Solution {
public:
    bool checkpossible(string &s1,string &s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int first=0;
        int second=0;
        while(first<s1.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size()){
            return true;
        }
        return false;
    }
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), comp);
        int n=words.size();
        int maxi=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkpossible(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};