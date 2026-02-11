class SegmentTree {
public:
    int n;
    vector<int> sum, mn, mx;

    SegmentTree(int n1) {
        n = n1;
        sum.assign(4 * n, 0);
        mn.assign(4 * n, 0);
        mx.assign(4 * n, 0);
    }

    void pull(int node) {
        int l = node * 2, r = node * 2 + 1;
        sum[node] = sum[l] + sum[r];
        mn[node] = min(mn[l], sum[l] + mn[r]);
        mx[node] = max(mx[l], sum[l] + mx[r]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            sum[node] = val;
            mn[node] = val;
            mx[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        pull(node);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int find(int node, int l, int r, int target, int sumBefore) {
        if (l == r) return l;

        int mid = (l + r) / 2;
        int lc = node * 2, rc = node * 2 + 1;

        int rightNeed = target - (sumBefore + sum[lc]);

        if (mn[rc] <= rightNeed && rightNeed <= mx[rc]) {
            return find(rc, mid + 1, r, target, sumBefore + sum[lc]);
        } else {
            return find(lc, l, mid, target, sumBefore);
        }
    }

    int findRightPre(int target) {
        if (!(mn[1] <= target && target <= mx[1]))
            return -1;
        return find(1, 0, n - 1, target, 0);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg(n);
        unordered_map<int, int> firstPos;
        int ans = 0;

        for (int l = n - 1; l >= 0; --l) {
            int num = nums[l];

            if (firstPos.count(num)) {
                seg.update(firstPos[num], 0);
            }

            firstPos[num] = l;
            seg.update(l, (num % 2 == 0) ? 1 : -1);

            int r = seg.findRightPre(0);

            if (r >= l)
                ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
