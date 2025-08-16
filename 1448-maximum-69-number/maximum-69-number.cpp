class Solution {
public:
    int maximum69Number (int num) {
        int digits = 0, great6 = -1;
        int dup = num;

        while (dup > 0) {
            digits++;
            int d = dup % 10;
            if (d == 6) great6 = digits;
            dup /= 10;
        }

        // if (great6 == -1) return pow(10, digits) - 1;
        // int res = pow(10, digits - great6) - 1;
        // res = res * 10 + 9;
        // res *= pow(10, great6 - 1);


        // return res;

        int max_pos = pow(10, digits) - 1;
        int dif = max_pos - num, dif_digits = 0;
        int dif_temp = dif;

        while (dif > 0) {
            dif_digits++;
            dif /= 10;
        }

        return max_pos - (dif_temp % max(1, int(pow(10, dif_digits - 1))));

    }
};