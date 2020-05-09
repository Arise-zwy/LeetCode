#include <bits/stdc++.h>
using namespace std;


 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
  public:
      // �̿����д������ӱ�־λ
      // flag=1���ڶ��η��ʣ�����һ�γ�ջ��
      // flag=2�������η��ʣ����ڶ��γ�ջ����Ϊ�ڶ��η��ʺ��������ջ��
      struct PostTreeNode {
          TreeNode* TNode;
          int flag;
      };

      vector<int> postorderTraversal(TreeNode* root) {
          if (root == nullptr) {
              return {};
          }
          TreeNode* cur = root;
          vector<int> ans;
          stack<PostTreeNode*> s;
          PostTreeNode* p;
          while (cur != nullptr || !s.empty()) {
              if (cur != nullptr) {
                  p = new PostTreeNode;
                  // ��һ�η��ʣ���ջʱ�������
                  p->TNode = cur;
                  p->flag = 1;
                  s.push(p);
                  cur = cur->left;
              }
              else {
                  p = s.top();
                  s.pop();
                  if (p->flag == 1) {
                      // �ǵڶ��η��ʣ�������������û�з���
                      s.push(p);
                      p->flag = 2;
                      cur = p->TNode->right;
                  }
                  else {
                      // �ǵ����η��ʣ����������������ʹ���
                      ans.push_back(p->TNode->val);
                  }
              }
          }
          return ans;
      }
  };
