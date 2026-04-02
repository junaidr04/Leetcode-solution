// TC : O(n) where n is the number of nodes in the tree
// SC : O(n) where n is the number of nodes in the tree (in worst case when tree is skewed)

/**
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
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        if (root == NULL)
            return ans;
        while (!q.empty())
        {
            vector<double> v;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            double sum = 0;
            for (int x : v)
            {
                sum += x;
            }
            double avg = sum / v.size();
            ans.push_back(avg);
        }
        return ans;
    }
};