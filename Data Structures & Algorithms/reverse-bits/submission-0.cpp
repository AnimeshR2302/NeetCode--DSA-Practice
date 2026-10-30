class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);

        for(int i = 0,j=31;i<j;i++, j--) if(b[i] != b[j]) {
            b[i].flip();
            b[j].flip();
        }

        return static_cast<uint32_t>(b.to_ulong());
    }
};
