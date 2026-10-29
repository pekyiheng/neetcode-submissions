class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, total = 0;
        for (int i = 0; i < (int)gas.size(); ++i) {
            int dif = gas[i] - cost[i];
            total += dif;
            tank += dif;
            if (tank < 0) {    
                start = i + 1;
                tank = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
