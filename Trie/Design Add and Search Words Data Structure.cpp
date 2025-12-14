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

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
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
    bool dfs(string &word, TrieNode *node, int pos)
    {
        if (pos == word.size())
            return node->isEnd;
        char c = word[pos];
        if (c != '.')
        {
            int idx = c - 'a';
            if (node->children[idx] == NULL)
                return false;
            return dfs(word, node->children[idx], pos + 1);
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->children[i] != NULL)
                {
                    if (dfs(word, node->children[i], pos + 1))
                        return true;
                }
            }
            return false;
        }
    }

    bool search(string word)
    {
        return dfs(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */