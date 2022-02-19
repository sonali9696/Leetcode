class Solution {
public:
    int HALF_INT_MIN = -1073741824;

    int divide(int dividend, int divisor) {

        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        std::vector<int> doubles;
        std::vector<int> powersOfTwo;

        /* Nothing too exciting here, we're just making a list of doubles of 1 and
         * the divisor. This is pretty much the same as Approach 2, except we're
         * actually storing the values this time. */
        int powerOfTwo = -1;
        while (divisor >= dividend) {
            doubles.push_back(divisor);
            powersOfTwo.push_back(powerOfTwo);
            // Prevent needless overflows from occurring...
            if (divisor < HALF_INT_MIN) {
                break;
            }
            divisor += divisor;
            powerOfTwo += powerOfTwo;
        }

        int quotient = 0;
        /* Go from largest double to smallest, checking if the current double fits.
         * into the remainder of the dividend */
        for (int i = doubles.size() - 1; i >= 0; i--) {
            if (doubles[i] >= dividend) {
                // If it does fit, add the current powerOfTwo to the quotient.
                quotient += powersOfTwo[i];
                // Update dividend to take into account the bit we've now removed.
                dividend -= doubles[i];
            }
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
};