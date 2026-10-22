class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};
        for (char task : tasks) {
            ++freq[task - 'A'];
        }

        int maxFreq = *max_element(freq, freq + 26);
        int numMax = count(freq, freq + 26, maxFreq);

        return max((int)tasks.size(),
                   (maxFreq - 1) * (n + 1) + numMax);
    }

    
};
