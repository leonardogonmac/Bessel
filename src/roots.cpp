#include <bits/stdc++.h>
#include "./bessel.cpp"

long double dfdx(function<long double(long double)> f, long double x, long double h){
    return (f(x + h) - f(x - h))/(2*h);
}

long double newton_raphson(function<long double(long double)> f, long double start, long double precision){
    long double next = start;
    size_t iter = 0;
    while(fabs(f(next)) > precision)
        next = next - f(next)/dfdx(f, next, 1.0E-6);
    return next;
}

vector<long double> get_roots(const function<long double(long double)>& f, const function<long double(long double)>& guess, int n, long double precision){
    vector<long double> roots;
    for(int i = 0; i < n; i++)
        roots.emplace_back(newton_raphson(f, guess(i), precision));
    return roots;
}

int main(int argc, char* argv[]){
    if(argc < 4)
        return -1;
    
    int v = atoi(argv[1]),
        n = atoi(argv[2]);
    double precision = atof(argv[3]);

    auto f = [precision, v](long double x){return bessel(x, v, precision);};
    auto guess = [v](long double x){return (2*x + 1)*pi/2 + v*pi/2 + pi/4;};

    vector<long double> roots = get_roots(f, guess, n, precision);
    for(auto r: roots)
        cout << r << ' ';
    cout << "\n";
    for(auto r: roots)
        cout << fixed << setprecision(6) << bessel(r, v, precision) << ' ';
    cout << "\n";
}