class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = -1;
        int sum = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int dif = gas[i] - cost[i];
            sum += dif;
            if (dif >= sum && dif >= 0) {
                sum = dif;
                start = i;
            } else if (sum < 0) {
                sum = 0;
            }
        }

        if (start == -1) {
            return start;
        }

        int j = start;
        int s = 0;
        do {
            int dif = gas[j] - cost[j];
            s += dif;
            if (s < 0) {
                return -1;
            }
            j = (j+1) % gas.size();
        } while (j != start);

        return start;
    }
};
