/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode head;
	struct ListNode *last = &head;
	int carry = 0;

	while (NULL != l1 || NULL != l2 || 0 != carry) {
		int l1val = l1 ? l1->val : 0;
		int l2val = l2 ? l2->val : 0;
		int sum = l1val + l2val + carry;

		last->next = (struct ListNode*) malloc(sizeof(struct ListNode));
		last->next->next = NULL;
		last->next->val = sum % 10;
		carry = sum / 10;

		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
		last = last->next;
	}

	return head.next;
}
