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

// 2115. Find All Possible Recipes from Given Supplies
// You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
// You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
// Return a list of all the recipes that you can create. You may return the answer in any order.
// Note that two recipes may contain each other in their ingredients.

//APPROACH:-
//BRUTEFORCE(TLE)

//CODE:-
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        unordered_set<string> available(supplies.begin(), supplies.end());
        bool changed=true;
        while(changed){
            changed=false;
            int prev=res.size();
            for(int i=0;i<recipes.size();i++){
                string curr=recipes[i];
                if (available.count(curr)) continue;
                bool ok=true;
                for (string& ing : ingredients[i]) {
                    if (!available.count(ing)) {
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    res.push_back(curr);
                    supplies.push_back(curr);
                    changed=true;
                }
            }
            if(res.size()==prev){
                break;
            }
        }
        return res;
    }
};


//APPROACH 2:-
//TOPOLOGICAL SORT

//CODE:-
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        unordered_map<string,vector<string>> map;
        unordered_map<string,int> indegree;
        for(int i=0;i<recipes.size();i++){
            string curr=recipes[i];
            for(int j=0;j<ingredients[i].size();j++){
                map[ingredients[i][j]].push_back(curr);
                indegree[curr]++;
            }
        }

        queue<string> q;
        for(int i=0;i<supplies.size();i++){
            q.push(supplies[i]);
        }
        unordered_set<string> made;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            for(auto& it:map[curr]){
                if(--indegree[it]==0){
                    made.insert(it);
                    q.push(it);
                }
            }
        }

        for(int i=0;i<recipes.size();i++){
            if(made.count(recipes[i])){
                res.push_back(recipes[i]);
            }
        }
        return res;
    }
};