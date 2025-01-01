#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//1422. Maximum Score After Splitting a String
//Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

// The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.?

//APPROACH:- (Beats 100%)
//pre compute the number of zeros to the left of an index and number of 1s to the right of an index in a vector
//then in one go find the max of the scores by adding the ith index of ones and i-1 index of the zeros vectors

//CODE:-
class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int> ones(n,0);
        vector<int> zeros(n,0);
        if(n==1){
            return 1;
        }
        int curr=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                curr++;
            }
            zeros[i]=curr;
        }
        curr=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                curr++;
            }
            ones[i]=curr;
        }
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            int opt=ones[i]+zeros[i-1];
            ans=ans>opt?ans:opt;
        }
        return ans;
    }
};

//146. LRU Cache
//Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

//APPROACH:-
//use a doubly linked list and as well as a map for the traversal in O(1) time

//CODE:-
class LRUCache {
public:
class node
{
  public:
  int key;
  int val;
  node* next;
  node* prev;
  node(int _key,int _val)
  {
    key = _key;
    val = _val;
  }
};
node* head = new node(-1,-1);
node* tail = new node(-1,-1);

int size;
unordered_map<int,node*>mpp;
    LRUCache(int capacity) {
       size = capacity; 
       head->next = tail;
       tail->prev = head;  
    }

    void addNode(node* newNode){
       
       node* temp = head->next;
       newNode->next = temp;
       newNode->prev = head;
       head->next = newNode;
       temp->prev = newNode;
    }

    void deleteNode(node* delNode){
         
       node* delprev = delNode->prev;
       node* delnext = delNode->next;
       delprev->next = delnext;
       delnext->prev = delprev;
    }
    
    int get(int _key) {
        
        if(mpp.count(_key))
        {
          node* nde = mpp[_key];
          int curr = nde->val;
          mpp.erase(_key);
          deleteNode(nde);
          addNode(nde);
          mpp[_key] = head->next;
          return curr;
        }
        return -1;
    }
    
    void put(int _key, int value) {
        
        if(mpp.count(_key))
        {
           node* nde = mpp[_key];
           mpp.erase(_key);
           deleteNode(nde);
        }
        if(mpp.size()==size)
        {
           mpp.erase(tail->prev->key);
           deleteNode(tail->prev);
        }
        addNode(new node(_key,value));
        mpp[_key] = head->next;
    }
};