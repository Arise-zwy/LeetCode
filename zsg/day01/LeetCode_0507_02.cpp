#include <bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* pre0, * cur0;
        int count = 1;
        while (cur != NULL && count <= n) {
            //��curΪmʱ
            if (count == m) {
                //��ͷ��㣬��
                pre0 = pre;
                cur0 = cur;
                //�������
                pre = cur;
                cur = cur->next;
            }
            else if (count > m&& count < n)//��cur��m��n֮��ʱ
            {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            else if (count == n) {
                //��cur��nextָ��pre
                ListNode* temp = cur->next;
                cur->next = pre;
                //��pre0��nextָ���nԪ��
                if (pre0 == NULL) head = cur;
                else pre0->next = cur;
                //��ָ��m��cur0��nextָ��n��ĵ�һ��Ԫ��
                cur0->next = temp;
                //����pre��cur
                pre = cur0;
                cur = temp;
            }
            else {
                //���洦��
                pre = cur;
                cur = cur->next;
            }
            ++count;
        }
        return head;
    }
};