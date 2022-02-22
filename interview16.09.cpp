class Operations {
public:
    Operations() {

    }
    
    int minus(int a, int b) {
        if (b == 0) return a;
        return a + revert(b);
    }
    
    int multiply(int a, int b) {
        if (b == 0 || a == 0) return 0;

        long long res = 0; 
        long long ra = (b > 0 ? a : revert(a));
        long long stcount = (b < 0 ? 1 : minu1);
        long long count = stcount;
        long long addnum = ra;
        while (b != 0) {
            bool diffSign = ((b > 0 && b + count < 0) || (b < 0 && b + count > 0));
            if (diffSign) {
                count = stcount;
                addnum = ra;
            }
            res += addnum;
            b += count;
            count += count;
            addnum += addnum;
        }
        return res;
    }
    
    int divide(int a, int b) {
        if (a == 0) return 0;
        
        long long res = 0;
        long long rb = b;
        long long stcount = minu1;
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
            rb = revert(b);
            stcount = 1;
        }
        long long count = stcount;
        long long addnum = rb;
        long long lefta = a;
        bool signa = (a > 0);
        while ((signa && (lefta > 0)) || (!signa && (lefta < 0))) {
            if ((signa && lefta + addnum < 0) || (!signa && lefta + addnum > 0)) {
                addnum = rb;
                count = stcount;

                if (signa && (lefta + rb < 0)) break;
                if (!signa && lefta + rb > 0) break;
            }
            lefta += addnum;
            res += count;
            addnum += addnum;
            count += count;
        }
        return res;
    }

    long long revert(int b) {
        long long res = 0; 

        long long stcount = (b < 0 ? 1 : minu1);
        long long count = stcount;

        while (b != 0) {
            bool diffSign = ((b > 0 && b + count < 0) || (b < 0 && b + count > 0));
            if (diffSign) {
                count = stcount;
            }
            b += count;
            res += count;
            count += count;
        }
        return res;
    }

private:
    int32_t minu1 = (int32_t)(0xFFFFFFFF);
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */
