class Solution {
public:
    int longestWith2Characters(char c1, char c2, string& s){
        int cnt1 = 0;
        int cnt2 = 0;
        int len = 0;
        unordered_map<int, int> mpp;

        for(int i=0; i<s.length(); ++i){
            if(s[i] == c1) ++cnt1;
            else if(s[i] == c2) ++cnt2;
            else {cnt1 = 0; cnt2 = 0; mpp.clear(); continue;}

            if(cnt1 == cnt2){ len = max(len, cnt1 + cnt2); continue;}

            int diff = cnt1 - cnt2;

            if(mpp.count(diff)) len = max(len, i - mpp[diff]);
            else mpp[diff] = i;
        }

        return len;
    }

    int longestBalanced(string s) {
        int n = s.length();

        // best substring is contributed by only 1 character
        int l1 = 1;
        int cnt = 1;
        for(int i=1; i<n; ++i){
            if(s[i-1] != s[i]){
                l1 = max(l1, cnt);
                cnt = 1;
            }
            else ++cnt;
        }
        l1 = max(l1, cnt);


        // best answer is contributed by 2 characters
        int l2 = 0;
        for(char c1='a'; c1<'d'; ++c1)
            for(char c2='a'; c2<'d'; ++c2)
                if(c1 != c2)
                    l2 = max(l2, longestWith2Characters(c1, c2, s));
                

        
        // best answer is contributed by 3 characters
        int l3 = 0;
        unordered_map<string, int> mmpp;

        int cnt1=0, cnt2=0, cnt3=0;
        for(int i=0; i<n; ++i){
            if(s[i] == 'a') ++cnt1;
            else if(s[i] == 'b') ++cnt2;
            else ++cnt3;

            if(cnt1 == cnt2 && cnt2 == cnt3){ l3 = max(l3, cnt1+cnt2+cnt3); continue;}

            int d1 = cnt1 - cnt2;
            int d2 = cnt2 - cnt3;
            
            string d = to_string(d1) + "_" + to_string(d2);
            if(mmpp.count(d)){
                l3 = max(l3, i - mmpp[d]);
            }
            else mmpp[d] = i;
        }


        return max({l1, l2, l3});
    }
};