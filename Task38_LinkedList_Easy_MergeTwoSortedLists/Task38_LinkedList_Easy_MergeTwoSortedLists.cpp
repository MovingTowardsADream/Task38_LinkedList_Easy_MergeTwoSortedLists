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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        if (list1->val > list2->val) {
            std::swap(list1, list2);
        }
        ListNode* tmp1 = NULL;
        ListNode* tmp2 = NULL;
        ListNode* result = list1;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tmp1 = list1;
                if (list1->next == NULL) {
                    list1->next = list2;
                    break;
                }
                else {
                    list1 = list1->next;
                }
            }
            else if (list1->val == list2->val) {
                tmp2 = list2;
                list2 = list2->next;
                tmp1 = list1;
                list1 = list1->next;
                tmp1->next = tmp2;
                tmp2->next = list1;
                list1 = tmp1->next;
            }
            else {
                tmp2 = list2;
                list2 = list2->next;
                tmp1->next = tmp2;
                tmp2->next = list1;
                tmp1 = tmp1->next;
            }
        }
        return result;
    }
};