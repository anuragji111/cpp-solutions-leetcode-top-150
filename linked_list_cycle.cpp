Statement 57) Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

-----------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // Handle empty or single-node list

        ListNode *slow = head, *fast = head->next;

        while (slow != fast) {
            if (!fast || !fast->next) return false; // No cycle found
            slow = slow->next;
            fast = fast->next->next;
        }

        return true; // Cycle found
    }
};

---------------------------------------------------------------------------------------------------------------
Explanation:

Floyd's Cycle-Finding Algorithm: It employs two pointers, a slow pointer (slow) and a fast pointer (fast), that move through the list at different speeds.
Initialization: Both pointers start at the head of the list.
Traversal:
The slow pointer moves one node at a time.
The fast pointer moves two nodes at a time.
Cycle Detection: If there's a cycle, the fast pointer will eventually catch up to the slow pointer, and they will both point to the same node within the cycle.
No Cycle: If the fast pointer reaches the end of the list (or becomes nullptr), it means there's no cycle.
This algorithm is efficient, having a time complexity of O(n) and a space complexity of O(1), making it a widely used technique for cycle detection in linked lists.
