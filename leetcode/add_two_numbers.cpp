#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	     int val;
	     ListNode *next;
	     ListNode() : val(0), next(nullptr) {}
	     ListNode(int x) : val(x), next(nullptr) {}
	     ListNode(int x, ListNode *next) : val(x), next(next) {}
	 };
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


		int length1 = 0;
		int length2 = 0;

		ListNode *l1c = l1;
		ListNode *l2c = l2;
		while (l1c != nullptr ) {
			l1c=l1c->next;
			length1++;
		}
		while (l2c != nullptr ) {
			l2c=l2c->next;
			length2++;
		}


		ListNode* root = (length1 >= length2) ? l1 : l2;

		if (length1 >= length2) {
			for (;l1 != nullptr; l1=l1->next) {

				if(l2!=nullptr) l1->val+=l2->val;
				if (l1->val >= 10) {
					l1->val %= 10;

					if (l1->next != nullptr) {
						l1->next->val+=1;
					} else {
						l1->next = new ListNode(1);
					}
				}

				if (l2 != nullptr) l2=l2->next;
			}
		}  else {
			for (;l2 != nullptr ; l2=l2->next) {

				if(l1 != nullptr) l2->val+=l1->val;


				if (l2->val >= 10) {
					l2->val %= 10;

					if (l2->next != nullptr) {
						l2->next->val+=1;
					} else {
						l2->next = new ListNode(1);
					}
				}

				if (l1 != nullptr) l1=l1->next;
			}
		}



		return root;


	}
};
