class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        priority_queue<pair<int, char>> q;
        for (auto &p : freq)
            q.push({p.second, p.first});
        string ans = "";
        pair<int, char> prev = {0, '0'};
        while (!q.empty())
        {
            auto [count, ch] = q.top();
            q.pop();
            ans += ch;
            if (prev.first > 0)
                q.push(prev);
            prev = {count - 1, ch};
        }
        if (ans.size() != s.size())
            return "";
        return ans;
    }
};