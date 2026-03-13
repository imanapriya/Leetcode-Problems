class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1;
        long long right = (long long)*min_element(workerTimes.begin(), workerTimes.end()) 
                          * mountainHeight * (mountainHeight + 1) / 2;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (canReduce(mid, mountainHeight, workerTimes))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

private:
    bool canReduce(long long t, int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;

        for (long long w : workerTimes) {
            long long x = (-1 + sqrt(1 + 8.0 * t / w)) / 2;
            total += x;
            if (total >= mountainHeight) return true;
        }

        return total >= mountainHeight;
    }
};