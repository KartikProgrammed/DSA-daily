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