#include <bits/stdc++.h>
#include <sciplot/sciplot.hpp>
#include "bessel.cpp"

using namespace sciplot;

int main(int argc, char* argv[]){
    if(argc < 5)
        return -1;

    int v = atoi(argv[1]),
        begin = atoi(argv[2]),
        end = atoi(argv[3]);
    double precision = atof(argv[4]);

    vector<long double> xs, ys;
    for(long double x = (long double) begin; x < (long double) end; x += 0.01){
        xs.emplace_back(x);
        ys.emplace_back(bessel(x, v, precision));
    }

    long double ymin = *min_element(ys.begin(), ys.end()), 
        ymax = *max_element(ys.begin(), ys.end());

    Plot2D plt;
    
    plt.palette("set1");
    plt.gnuplot("set xzeroaxis lt -1 lw 1.5");
    plt.gnuplot("set xtics font ',5'");
    plt.gnuplot("set ytics font ',5'");
    plt.yrange(ymin, ymax);
    plt.xrange((long double) begin, (long double) end);
    plt.gnuplot("set xtics " + to_string(begin) + ", " + to_string((end-begin)/10) + ", " + to_string(end));  // start, step, end
    plt.gnuplot("set ytics " + to_string(ymin) + ", " + to_string((ymax-ymin)/10) + ", " + to_string(ymax));
    plt.legend().atOutsideBottomLeft().fontSize(2).displaySymbolLength(2);             
    plt.gnuplot("set pointsize 0.5");
    plt.drawPoints(xs, ys).pointType(7).lineColor("blue").label("J0");
    Canvas canvas = {{ Figure{{plt}} }};
    canvas.show();
    return 0;
}