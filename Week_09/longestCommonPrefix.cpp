class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        int len = strs.size();
        string ans;
        if (len <= 0) return ans;

        while (i < 200) {
            if (i >= strs[0].size()) {
                return ans;
            }
            char c = strs[0][i];
            for (int j = 1; j < len; ++j) {
                if (c != strs[j][i] || i >= strs[j].size()) {
                    return ans;
                }
            }
            ans.push_back(c);
            i++;
        }
        return ans;
    }
};
