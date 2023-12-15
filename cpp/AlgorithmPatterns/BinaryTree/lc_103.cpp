/**
 * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector <vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector <vector<int>> res;
        traverseNodes(root, res, 0);
        for (int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }

    void traverseNodes(TreeNode *node, vector <vector<int>> &order, int depth) {
        if (node == nullptr) {
            return;
        }
        if (order.size() <= depth) {
            order.push_back(vector<int>());
        }
        order[depth].push_back(node->val);
        traverseNodes(node->left, order, depth + 1);
        traverseNodes(node->right, order, depth + 1);
        return;
    }
};