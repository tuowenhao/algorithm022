class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, pos = 31;
        while (n > 0) {
            ans += (n & 1) << pos;
            pos--;
            n >>= 1;
        }
        return ans;
    }
};
