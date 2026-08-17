class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars; // {position, time}
        
        // Calculate time to reach target for each car
        for (int i = 0; i < speed.size(); ++i) {
            float time = (float)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        // Sort by position descending (right to left)
        std::sort(cars.begin(), cars.end(), std::greater<pair<int, float>>());
        
        std::stack<float> st;
        
        for (auto [pos, time] : cars) {
            // If current car takes MORE time, it's a new fleet
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            // Otherwise, it merges with the car ahead (do nothing)
        }
        
        return st.size();
    }
};