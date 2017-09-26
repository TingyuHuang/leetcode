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
