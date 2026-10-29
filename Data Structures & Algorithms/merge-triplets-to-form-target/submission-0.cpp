class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> candidates;

        vector<bool> vb(3, false);

        for (auto& trio : triplets) {
            bool toAdd = true;
            for (int i = 0; i < 3; ++i) {
                if (trio[i] > target[i]) {
                    toAdd = false;
                    break;
                }
            }
            
            if (toAdd) {
                for (int i = 0; i < 3; ++i) {
                    if (trio[i] == target[i]) {
                        vb[i] = true;
                    }
                }
            }
        }

        bool res = true;
        for (int i = 0; i < 3; ++i) {
            res &= vb[i];
        }
        return res;
    }
};
