class Solution {
    static double dist(int a, int b) {
        return std::sqrt(a*a + b*b);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto descendingCmp = [](vector<int>& p1, vector<int>& p2) {
            return (p1[0] * p1[0] + p1[1] * p1[1]) > (p2[0] * p2[0] + p2[1] * p2[1]); 
        };

        std::priority_queue<vector<int> , vector<vector<int>>, decltype(descendingCmp)> pq;
        vector<vector<int>> res;
        std::unordered_map<float, vector<int>> m;
        for (auto& p : points) {
            pq.push(p);
        }

        for (int i = 0; i < k; ++i) {
            auto d = pq.top();
            res.push_back(d);
            pq.pop();
        }

        return res;
    }

};
