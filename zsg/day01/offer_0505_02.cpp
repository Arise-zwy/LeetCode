#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* temphead = pHead;
        ListNode* p1 = pHead;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        if (p2 == NULL) {
            return temphead;
        }
        if (p2->next == NULL) {
            if (p1->val == p2->val) {
                return nullptr;
            }
            else {
                return temphead;
            }
        }
        while (p3 != NULL||p2!=NULL) {
            if (p2->val == p3->val) {
                p2 = p3->next;
                p3 = p2->next;
                p1->next = p2;
            }
            else {
                p1 = p1->next;
                p2 = p1->next;
                p3 = p2->next;
            }
           
        }
        return temphead;
    }
};

//β�巨����������
ListNode* Creat_LinkList_R()
{
    int x;
    ListNode* head, * p, * tail;//tail��βָ��
    head = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL)
        return head;
    head->next = NULL;
    tail = head; //һ��ʼβָ��ָ��ͷָ���λ��
    cout << "������Ҫ¼�������0����" << endl;
    cin >> x;
    while (x != 0)
    {
        p = (ListNode*)malloc(sizeof(ListNode));
        if (p == NULL)
            return head;
        p->val = x;
        tail->next = p; //��p���뵽β�ڵ�ĺ���
        tail = p;   //�޸�β�ڵ��ָ��
        tail->next = NULL;    //��β�ڵ��ָ�����޸�Ϊ��
        cin >> x;
    }
    return head;

}
int main() {
    ListNode* pHead = Creat_LinkList_R();//β�巨
    Solution xx;
    xx.deleteDuplication(pHead);
    return 0;
}