class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        for (char c : tasks)
        {
            freq[c - 'A']++;
        }
        int maxFreq = 0, maxCount = 0;
        for (int f : freq)
        {
            if (f > maxFreq)
            {
                maxFreq = f;
                maxCount = 1;
            }
            else if (f == maxFreq)
            {
                maxCount++;
            }
        }
        int partCount = maxFreq - 1;
        int emptySlots = partCount * (n - (maxCount - 1));
        int availableTasks = tasks.size() - maxFreq * maxCount;
        int idles = max(0, emptySlots - availableTasks);
        int totalTime = tasks.size() + idles;
        return totalTime;
    }
};