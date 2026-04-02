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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool leftToright = true;
        while (!q.empty())
        {
            int s = q.size();
            vector<int> level(s);
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int index;
                if (leftToright)
                {
                    index = i;
                }
                else
                {
                    index = s - 1 - i;
                }
                level[index] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(level);
            leftToright = !leftToright;
        }
        return ans;
    }
};



//TC : O(n)
//SC : O(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;        // result store করবো এখানে
        queue<TreeNode*> q;             // BFS এর জন্য queue
        q.push(root);                   // root দিয়ে শুরু
        if(root == NULL)                
        return ans;
        int level = 0;                  // কোন level এ আছি track করতে
        while(!q.empty())               
        {
            vector<int> v;              // এই level এর nodes রাখবো
            int n = q.size();           // এই level এ কতটা node আছে
            for(int i = 0; i < n; i++)  // এই level এর সব node process করো
            {
                TreeNode* curr = q.front();  // queue এর সামনের node নাও
                q.pop();                     // সেটা queue থেকে বের করো
                v.push_back(curr->val);      // node এর value রাখো
                if(curr->left)               // left child থাকলে
                    q.push(curr->left);      // পরের level এর জন্য queue তে দাও
                if(curr->right)              // right child থাকলে
                    q.push(curr->right);     // পরের level এর জন্য queue তে দাও
            }
            if(level % 2 != 0)          // odd level হলে (1, 3, 5...)
            {
                reverse(v.begin(), v.end()); // vector উল্টে দাও
            }
            ans.push_back(v);           // এই level এর result ans এ রাখো
            level++;                    // পরের level এ যাও
        }
        return ans;
    }
};
