**Merge k Sorted Lists**

Problem Statement 110) You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

----------------------------------------------------------------------------------------------------------------------------
SOLUTION = /**
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr; // Handle empty input

        return mergeLists(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeLists(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left]; // Base case: single list

        int mid = left + (right - left) / 2;
        ListNode* leftMerged = mergeLists(lists, left, mid);
        ListNode* rightMerged = mergeLists(lists, mid + 1, right);

        return mergeTwoLists(leftMerged, rightMerged);
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2; // Append remaining nodes
        return dummy.next;
    }
};

--------------------------------------Explanations:- 
  Problem:

Given K sorted linked lists, combine them into a single sorted linked list.
Key Features:

Divide and Conquer: Recursively divides the lists into smaller groups and merges them.
Merge Two Lists: Function to merge two sorted lists efficiently.
Code Breakdown:

1. mergeKLists Function (Main Function):

Handles empty input by returning nullptr.
Recursively calls mergeLists to divide and merge lists.
Returns the head of the merged list.
2. mergeLists Function (Recursive Helper):

Base Case: If only one list remains, return it directly.
Recursively merges the left and right halves of the lists.
Merges the two merged halves using mergeTwoLists.
Returns the head of the fully merged list.
3. mergeTwoLists Function (Merges Two Lists):

Creates a dummy head node for the merged list.
Iterates through both lists, comparing and appending nodes in ascending order.
Appends any remaining nodes from either list.
Returns the head of the merged list, excluding the dummy node.
Time and Space Complexity:

Time: O(N log K), where N is the total number of nodes in all lists, and K is the number of lists.
The recursive calls contribute O(log K), and each merge operation within a level takes O(N).
Space: O(log K), due to the recursion stack depth.
