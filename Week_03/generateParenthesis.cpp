class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(0, 0, n, "", ret);
        return ret;
    }

    void generate(int left, int right, int max, string str, vector<string>& ret) {
        if (left == max && right == max) {
            ret.push_back(str);
            return;
        }

        if (left < max) {
            generate(left + 1, right, max, str + '(', ret);
        }
        if (right < left) {
            generate(left, right + 1, max, str + ')', ret);
        }
        return;
    }
};
