#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1.0);

size_t factorial(int n){
    size_t f = 1;
    for(int i = 2; i <= n; i++)
        f*=i;
    return f;
}

// Jv = SUM [ (-1)^n(x/2)^{2n + v} / n!(n + v)! ]
// an = an_ [ (-1)(x/2)² / n(n + v) ]

long double bessel(long double x, int v, double precision){
	// Diverge em ~45
//	if(x < 30){
        long double sum = 0, 
            term = pow(x/2, v)/factorial(v),
            prev = LDBL_MAX - 10;
        for(int n = 1; fabs(sum - prev) >= precision; n++){
            prev = sum;
            sum += term;
            term *= -(x*x/4)/(n*(n + v));
        }
        return sum;
//    }
	// Aproximacao de Bessel para valores suficientemente grandes
//    return sqrt(2 /(pi*x) )*cos(x - v*pi/2 - pi/4);
}
