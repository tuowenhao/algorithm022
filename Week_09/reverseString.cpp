class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() <= 1) return;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
};
