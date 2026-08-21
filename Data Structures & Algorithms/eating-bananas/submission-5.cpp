class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum = 0;
        long maxB = 0;
        for (long b : piles) {
            sum += b;
            maxB = std::max(maxB, b);
        }
        long l = sum / h;
        long r = maxB;
        int res = r;

        while (l < r) {
            int mid = (l + r) / 2;
            // std::cout << "l: " << l << " r: " << r << " mid: " << mid << "\n";
            if (mid == 0) {
                return 1;
            }     
            int hrs = 0;
            for (long b : piles) {
                hrs += std::ceil(static_cast<double>(b) / mid);
            }
            if (hrs <= h) {
                res = mid;
                r = mid;
            } else {
                l = mid+1;
            } 
        }

        return res;
    }
};
