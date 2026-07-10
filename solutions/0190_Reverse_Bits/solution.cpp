class Solution {
public:
    int reverseBits(int n) {
        bitset<32> a(n);
        string s = a.to_string();
        reverse(s.begin(), s.end());
        bitset<32> b(s);

        return (uint32_t)b.to_ulong();
    }
};