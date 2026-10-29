class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::map<int, int> m;

        if (hand.size() % groupSize != 0) {
            return false;
        }

        int k = hand.size() / groupSize;

        for (auto c : hand) {
            if (!m[c]) {
                m[c] = 1;
            } else {
                m[c]++;
            }
        }

        while (k > 0) {
            auto ptr = m.begin();
            int j = ptr->first;
            for (int i = j; i < j + groupSize; ++i) {
                if (!m[i] || m[i] < 1) {
                    return false;
                }

                if (m[i] == 1) {
                    m.erase(i);
                } else {
                    m[i]--;
                }
            }
            --k;
        }

        return true;
    }
};
