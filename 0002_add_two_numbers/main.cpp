
/**
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode head = ListNode(0);
			ListNode *last = &head;
			int carry = 0;

			while (nullptr != l1 || nullptr != l2 || 0 != carry) {
				int l1val = l1 ? l1->val : 0;
				int l2val = l2 ? l2->val : 0;
				int sum = l1val + l2val + carry;

				last->next = new ListNode(sum % 10);
				carry = sum / 10;

				if (l1) l1 = l1->next;
				if (l2) l2 = l2->next;
				last = last->next;
			}

			return head.next;
		}
};
