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

//141. Linked List Cycle
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

// Approach:
// 1. Use two pointers, slow and fast.
// 2. Move slow by one step and fast by two steps.
// 3. If they meet, there is a cycle; otherwise, if fast reaches the end, there is no cycle.

// CODE:
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp2!=NULL && temp2->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next->next;
            
            if(temp1==temp2){
                return true;
            }
        }
        return false;
    }
};

//142. Linked List Cycle II
// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.

// Approach:
// 1. Use two pointers, slow and fast.
// 2. Move slow by one step and fast by two steps until they meet.
// 3. When they meet, reset one pointer to the head and move both pointers by one step until they meet again.

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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        bool flag=false;
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp1!=NULL && temp1->next!=NULL){
            temp1=temp1->next->next;
            temp2=temp2->next;
            if(temp1==temp2){
                flag=true;
                break;
            }
        }
        if(flag){
            temp1=head;
            while(temp1!=temp2){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp1;
        }
        return NULL;
    }
};

//234. Palindrome Linked List
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.


// Approach:
//use a vector to store the values of the linked list.
// 1. Traverse the linked list and store the values in a vector.
// 2. Check if the vector is a palindrome by comparing the first half with the reversed second half.

//better approach:
// 1. Use a two-pointer technique to find the middle of the linked list.
// 2. Reverse the second half of the linked list.
// 3. Compare the first half with the reversed second half to check for palindrome.


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
    bool palindrome(vector<int>& temp){
        int l=0;
        int r=temp.size()-1;
        while(l<=r){
            if(temp[l]!=temp[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        return palindrome(vec);
    }
};


//328. Odd Even Linked List
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// Approach:
// 1. Use two pointers, one for odd indexed nodes and one for even indexed nodes.
// 2. Traverse the linked list and link odd indexed nodes together and even indexed nodes together.
// 3. Connect the last odd indexed node to the first even indexed node.
// 4. Set the next of the last even indexed node to NULL.

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        ListNode* head2=head->next;
        while(temp2!=NULL && temp2->next!=NULL){
            temp1->next=temp2->next;
            temp1=temp1->next;
            temp2->next=temp1->next;
            temp2=temp2->next;
        }
        temp1->next=head2;
        return head;

    }
};