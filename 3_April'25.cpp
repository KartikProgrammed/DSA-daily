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

//FLOYD WARSHALL

//CODE:-
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1){
                    mat[i][j]=1e9;
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1e9){
                    mat[i][j]=-1;
                }
            }
        }
    }
};


// 1319. Number of Operations to Make Network Connected
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

//APPROACH:-
//DISJOINT SET

//CODE:-
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        int nc=0;
        for(auto it:connections){
            int st=it[0];
            int end=it[1];
            if(ds.findUPar(st)==ds.findUPar(end)){
                extra++;
            }
            ds.unionBySize(st,end);
        }
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                nc++;
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (extra >= ans) return ans;
        return -1;
    }
};

//DISJOINT SET

//APPROACH:-
//REFER CHEATSHEET

//CODE:-
class disjointSet{
    vector<int> size;
    vector<int> parent;

    public:
        disjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUparent(int u){
            if(u!=parent[u]){
                parent[u]=findUparent(parent[u]);
            }
            return parent[u];
        }

        void unionFind(int u,int v){
            int uu=findUparent(u);
            int uv=findUparent(v);
            if(uv==uu){
                return;
            }
            if(size[uu]<size[uv]){
                parent[uu]=uv;
                size[uv]+=size[uu];
            }
            else{
                parent[uv]=uu;
                size[uu]+=size[uv];
            }
        }
};


// 947. Most Stones Removed with Same Row or Column
// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

//APPROACH:-
//Disjoint sets

//CODE:-
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrows=0;
        int maxcol=0;
        for(auto it:stones){
            maxrows=max(maxrows,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        unordered_map<int,int> map;
        disjointSet ds(maxrows+maxcol+1);
        for(auto it:stones){
            int currrow=it[0];
            int currcol=it[1]+maxrows+1;
            ds.unionFind(currrow,currcol);
            map[currrow]=1;
            map[currcol]=1;
        }
        int count=0;
        for(auto it:map){
            if(ds.findUparent(it.first)==it.first){
                count++;
            }
        }
    return n-count;
    }
};