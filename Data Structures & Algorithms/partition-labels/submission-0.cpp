class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<unordered_map<char, int>> v;
        for (auto c : s) {
            bool seen = false;
            int cutoff = 0;
            for (auto& m : v) {
                if (m.contains(c)) {
                    m[c]++;
                    seen = true;
                    break;
                }
                cutoff++; 
            }

            if (!seen) {
                std::unordered_map<char, int> m;
                m[c] = 1;
                v.push_back(m);
            } else {
                while (v.size() - 1 > cutoff) {
                    auto& m = v[v.size() - 1];
                    for (auto& p : m) {
                        v[cutoff][p.first] = p.second;
                    }
                    v.pop_back();
                }
            }
        }

        vector<int> res;

        for (auto& m : v) {
            int sum = 0;
            for (auto& p : m) {
                sum += p.second;
            }
            res.push_back(sum);
        }
        
        return res;
    }
};
