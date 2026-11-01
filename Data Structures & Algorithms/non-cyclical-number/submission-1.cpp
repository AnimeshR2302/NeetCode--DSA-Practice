class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        
        while(n!=1) {
            cout<<n<<endl;
            if(s.find(n) != s.end()) return false;
            s.insert(n);

            int temp = n;
            n=0;
            while(temp) {
                int rem = temp%10;
                temp /= 10;
                n+=rem*rem;
            }
        }

        return true;
    }
};
