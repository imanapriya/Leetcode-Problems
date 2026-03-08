class Solution {
public:
    
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;

        for (int i = 0; i < variables.size(); i++) {
            long long a = variables[i][0];
            long long b = variables[i][1];
            long long c = variables[i][2];
            long long m = variables[i][3];

            long long x = modPow(a, b, 10);
            long long y = modPow(x, c, m);

            if (y == target)
                ans.push_back(i);
        }

        return ans;
    }
};