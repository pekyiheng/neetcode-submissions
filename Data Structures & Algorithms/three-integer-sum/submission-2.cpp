class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::unordered_map<int, int> m;
        set<vector<int>> s;
        vector<vector<int>> res;
        for (int i : nums) {
            ++m[i];
        }

        for (const auto [first, _] : m) {
            for (const auto [second, count] : m) {
                int target = -(first + second);
                if (first == second && first == target && m.count(target) && m[target] > 2) {
                    s.insert({target, target, target});
                } else if (first == second && count > 1 && target != first && m.count(target) > 0) {
                    std::cout << "first == second";
                    if (first > target) {
                        s.insert({target, first, first});
                    } else {
                        s.insert({first, second, target});
                    }
                } else if ((first == target || second == target) && m.count(target) > 1) {
                    vector<int> v = {first, second, target};
                    std::sort(v.begin(), v.end());
                    s.insert(v);
                } else if (first != second && first != target && second != target && m.count(target) > 0) {
                    vector<int> v = {first, second, target};
                    std::sort(v.begin(), v.end());
                    s.insert(v);
                }
            }
        }

        for (auto& x : s) {
            res.push_back(x);
        }

        return res;
    }
};
