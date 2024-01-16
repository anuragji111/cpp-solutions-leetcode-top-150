**Sort List**

Problem Statement 108) Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

----------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // Base cases: empty or single-node list

        ListNode* slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // Split the list into two halves

        return merge(sortList(head), sortList(slow)); // Recursively sort and merge
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *tail = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2; // Append remaining nodes
        return dummy->next;
    }
};

--------------------------Explanation:-
  Key Features:

Merge Sort: A divide-and-conquer algorithm that recursively sorts sublists and merges them.
In-Place Splitting: Uses the fast/slow pointer technique to split the list without extra space.
Code Breakdown:

1. sortList Function (Main Function):

Base Cases: If the list is empty or has a single node, it's already sorted; return it.
Split the list into two halves using the fast/slow pointer technique:
fast pointer moves twice as fast as slow, effectively finding the middle point.
prev pointer marks the end of the first half.
Recursively sort the two halves: sortList(head) and sortList(slow).
Merge the sorted halves using the merge function.
Return the head of the sorted list.
2. merge Function (Merges Two Sorted Lists):

Creates a dummy head node for the merged list.
Iterates through both lists, comparing elements and appending the smaller one to the merged list.
Appends any remaining nodes from either list.
Returns the head of the merged list (excluding the dummy node).
Time and Space Complexity:

Time: O(N log N), due to the recursive calls and merge operations.
Space: O(log N) for recursion stack depth (balanced merge tree).
