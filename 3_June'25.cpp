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

// 1298. Maximum Candies You Can Get from Boxes
// You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:
// status[i] is 1 if the ith box is open and 0 if the ith box is closed,
// candies[i] is the number of candies in the ith box,
// keys[i] is a list of the labels of the boxes you can open after opening the ith box.
// containedBoxes[i] is a list of the boxes you found inside the ith box.
// You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
// Return the maximum number of candies you can get following the rules above.

// Approach: BFS with Queue

// CODE:
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n=status.size();
        vector<bool> open(n,false);
        for(int i=0;i<n;i++){
            if(status[i]==1){
                open[i]=true;
            }
        } 
        queue<int> q;
        bool flag=true;
        vector<bool> visited(n,false);
        for(int i=0;i<initialBoxes.size();i++){
            q.push(initialBoxes[i]);
            visited[initialBoxes[i]]=true;
        }
        int res=0;
        while(flag==true){
            int siz=q.size();
            flag=false;
            for(int i=0;i<siz;i++){
                int curr=q.front();
                q.pop();
                if(open[curr]==false){
                    q.push(curr);
                    
                }
                else{
                    res+=candies[curr];
                    for(int k=0;k<keys[curr].size();k++){
                        open[keys[curr][k]]=true;
                    }
                    for(int k=0;k<containedBoxes[curr].size();k++){
                        int newb=containedBoxes[curr][k];
                        if(!visited[newb]){
                            q.push(newb);
                            visited[newb]=true;
                        }
                    }
                    flag=true;
                }
            }
        }
        return res;
    }
};


//1106. Parsing A Boolean Expression
// A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
// 't' that evaluates to true.
// 'f' that evaluates to false.
// '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
// '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// Given a string expression that represents a boolean expression, return the evaluation of that expression.
// It is guaranteed that the given expression is valid and follows the given rules.


// Approach: Stack

// CODE:
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(int i=0;i<expression.size();i++){
            if(expression[i]==',' || expression[i]==' '){
                continue;
            }
            if(expression[i]!=')'){
                st.push(expression[i]);
            }
            else{
                vector<bool> temp;
                while(!st.empty() && (st.top() == 't' || st.top() == 'f')){
                    temp.push_back(st.top()=='t');
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') st.pop();
                char op=st.top();
                st.pop();

                bool result;

                if(op=='!'){
                    result=!temp[0];
                }
                else if(op=='|'){
                    result=false;
                    for(int j=0;j<temp.size();j++){
                        result=result||temp[j];
                    }
                }
                else{
                    result=true;
                    for(int j=0;j<temp.size();j++){
                        result=result&&temp[j];        
                    }
                }
                st.push(result?'t':'f');
            }
        }
        return st.top()=='t';
    }
};