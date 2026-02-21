class Solution {
public:
    int result = INT_MAX;
    int n;

    void solve(int idx, vector<int>& cookies, vector<int>& chil, int k) {
        if (idx >= n) {
            int unfair = *max_element(chil.begin(), chil.end());
            result = min(result, unfair);
            return;
        }

        int cookie = cookies[idx];

        for (int j = 0; j < k; j++) {
            chil[j] += cookie;
            solve(idx + 1, cookies, chil, k);
            chil[j] -= cookie;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> chil(k, 0);
        solve(0, cookies, chil, k);
        return result;
    }
};