Statement 66) Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

--------------------------------------------------------------
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = new ListNode(0);  // Create dummy heads for two partitions
        ListNode* before = before_head;
        ListNode* after_head = new ListNode(0);
        ListNode* after = after_head;

        while (head) {
            if (head->val < x) {  // Place nodes less than x in the "before" list
                before->next = head;
                before = before->next;
            } else {  // Place nodes greater than or equal to x in the "after" list
                after->next = head;
                after = after->next;
            }
            head = head->next;  // Move to the next node
        }

        after->next = nullptr;  // Terminate the "after" list
        before->next = after_head->next;  // Connect the two partitions

        return before_head->next;  // Return the head of the partitioned list
    }
};
