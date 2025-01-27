#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
using namespace std;
// 1462. Course Schedule IV
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

// For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
// Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

// You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

// Return a boolean array answer, where answer[j] is the answer to the jth query.


//APPROACH:-
//Use dfs directly

//CODE:-
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj,int src,int dest,vector<bool> &visited){
        visited[src]=true;
        if(dest==src){
            return true;
        }
        bool ret=false;
        for(auto& iter:adj[src]){
            if(!visited[iter]){
                ret=ret || dfs(adj,iter,dest,visited);
            }
        }
        return ret;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        for(auto &iter:prerequisites){
            int src=iter[0];
            int dest=iter[1];
            adj[src].push_back(dest);
        }
        int q=queries.size();
        vector<bool> result(q);
        for(int i=0;i<q;i++){
            int src=queries[i][0];
            int dest=queries[i][1];
            vector<bool> visited(numCourses,false);
            result[i]=dfs(adj,src,dest,visited);
        }
        return result;
    }
};

//215. Kth Largest Element in an Array
// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

//APPROACH:-
//push them all into a priority queue and pop untill k=0
//return the top

//CODE:-
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int res=0;
        while(k>0){
            k--;
            res=pq.top();
            pq.pop();
        }
        return res;
    }
};


//23. Merge k Sorted Lists
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

//APPROACH:-
// send all the node val to a min heap priority queue and then create a linkedlist out of it

//CODE:-

//  * Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode() : val(0), next(nullptr) {}
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(ListNode* list:lists){
            while(list!=NULL){
                pq.push(list->val);
                list=list->next;
            }
        }
        struct ListNode *head=new ListNode(0);
        struct ListNode *curr=head;
        while(!pq.empty()){
            curr->next=new ListNode(pq.top());
            pq.pop();
            
            curr=curr->next;
        }
        return head->next;
    }
};