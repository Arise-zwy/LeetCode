#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk1;//�����߼������
        stack<char> stk2;//���桰����
        //�����ң����ұ��������һ��')'����ʱһ��ֻʣstk2��һ��Ԫ��
        for (int i = 0; i < expression.size(); i++) {
            //�ǲ���������stk1
            if (expression[i] == '|' || expression[i] == '&' || expression[i] == '!')
                stk1.push(expression[i]);
            //��')'��֪��Ҫ����һ��������
            else if (expression[i] == ')') {
                int t = 0;//��¼f��t���ֵĴ���
                int f = 0;
                while (stk2.top() != '(') {//���������ľ���Ҫ�����ġ�����
                    if (stk2.top() == 't')
                        t++;
                    if (stk2.top() == 'f')
                        f++;
                    stk2.pop();
                }
                stk2.pop();
                char x = stk1.top();//�����߼������
                stk1.pop();
                //�������������㣬�������ѹջ
                if (x == '!') {
                    if (t == 1)
                        stk2.push('f');
                    else
                        stk2.push('t');
                }
                else if (x == '|') {
                    if (t != 0)
                        stk2.push('t');
                    else
                        stk2.push('f');
                }
                else if (x == '&') {
                    if (f != 0)
                        stk2.push('f');
                    else
                        stk2.push('t');
                }
            }
            else
                stk2.push(expression[i]);
        }
        if (stk2.top() == 't') return true;//�ڱ��ʽû�д������������һ��ֻ��ʣһ��
        else return false;

    }
};
