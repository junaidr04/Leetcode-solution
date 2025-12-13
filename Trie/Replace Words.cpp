class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (curr->children[idx] == NULL)
            {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    string getRoot(string word)
    {
        TrieNode *curr = root;
        string prefix = "";
        for (char c : word)
        {
            int idx = c - 'a';
            if (curr->children[idx] == NULL)
                break;
            prefix += c;
            curr = curr->children[idx];
            if (curr->isEnd)
                return prefix;
        }
        return "";
    }
};
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie trie;
        for (string root : dictionary)
            trie.insert(root);
        stringstream ss(sentence);
        string word, ans = "";
        while (ss >> word)
        {
            string root = trie.getRoot(word);
            if (root != "")
                ans += root;
            else
                ans += word;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};