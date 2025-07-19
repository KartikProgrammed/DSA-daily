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

//1233. Remove Sub-Folders from the Filesystem
// Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.
// If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".
// The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.
// For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.

// Approach:
// 1. Sort the folders lexicographically.
// 2. Use a vector to store the result.
// 3. Iterate through the sorted folders and check if the current folder is a sub-folder of the last added folder.
// 4. If it is not a sub-folder, add it to the result.
// 5. Return the result vector.

// CODE:
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(),folder.end());
        res.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string curr=folder[i];
            string prev=res.back();
            prev+='/';
            if(curr.find(prev)!=0){
                res.push_back(curr);
            }
        }
        return res;
    }
};

//2095. Delete the Middle Node of a Linked List
// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

// Approach:
// 1. Use two pointers, slow and fast.
// 2. Move slow by one step and fast by two steps.
// 3. When fast reaches the end, slow will be at the middle node.
// 4. Remove the middle node by adjusting the pointers.

// CODE:
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=head;
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=slow->next;
        return head;
    }
};

// 148. Sort List
// Given the head of a linked list, return the list after sorting it in ascending order.

// Approach:
// 1. Use merge sort to sort the linked list.
// 2. Find the middle of the list using the slow and fast pointer technique.
// 3. Recursively sort the left and right halves of the list.
// 4. Merge the two sorted halves.

// CODE:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                temp->next=left;
                temp=temp->next;
                left=left->next;

            }
            else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        while(left!=NULL){
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        while(right!=NULL){
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* left=head;
        ListNode* mid=findMid(head);
        ListNode* right=mid->next;
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);
        ListNode* newhead=merge(left,right);
        return newhead;
    }
};

//160. Intersection of Two Linked Lists
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
// For example, the following two linked lists begin to intersect at node c1:

//Approach:
// count the length of both linked lists.
// If the lengths are different, move the pointer of the longer list ahead by the difference in lengths.
// Then move both pointers one step at a time until they meet or reach the end of the lists.

// CODE:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA=0;
        ListNode* temp=headA;
        while(temp!=NULL){
            countA++;
            temp=temp->next;
        }
        temp=headB;
        int countB=0;
        while(temp!=NULL){
            countB++;
            temp=temp->next;
        }
        ListNode* left=headA;
        ListNode* right=headB;
        if(countA>countB){
            int diff=countA-countB;
            for(int i=0;i<diff;i++){
                left=left->next;
            }
        }
        else{
            int diff=countB-countA;
            for(int i=0;i<diff;i++){
                right=right->next;
            }
        }
        if(left==right){
            return left;
        }
        while(left!=NULL && right!=NULL && left->next != right->next){
            left=left->next;
            right=right->next;
        }
        if(left==NULL || right==NULL){
            return NULL;
        }
        return left->next;
    }
};

