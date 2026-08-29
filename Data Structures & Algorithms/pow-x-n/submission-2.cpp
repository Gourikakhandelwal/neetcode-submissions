class Solution {
public:
    double func(double x, long long n) {
        if (n == 0) return 1;

        double half = func(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n; 

        if (N < 0)
            return 1.0 / func(x, -N);

        return func(x, N);
    }
};