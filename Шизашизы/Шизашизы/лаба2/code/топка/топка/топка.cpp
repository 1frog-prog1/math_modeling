#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

int m = 1;
int p = 3000;
int n = 10;
int c = 460;
int tA = 300;
double k = 25;
double s = 0.01;
const double sigma = 5.7 * pow(10, -8);
int tR = 600;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::to_string;

double losses(double t) {
    return s * (k * (t - tA) + sigma * (pow(t, 4) - pow(tA, 4)));
}

double h(double t) {
    // cout << '\t' << ((tR - t) > 0 ? (tR - t) : 0)*1.0/(tR - tA) << endl;
    return 1.0 * floor(ceil(pow((((tR - t) > 0 ? (tR - t) : 0) * 1.0 / (tR - tA)), 1.0 * tA / tR) * (1 - losses(tR) / p) * n) + n * losses(tR) / p);
}

double f(double t) {
    // cout << ' ' << p << ' ' << losses(t) << ' ' << p- losses(t) << endl;
    // cout << ' ' << c << ' ' << m << ' ' << c*m << endl;
    // cout << ' ' << losses(t) << endl;
    return (1.0 * (p * h(t) / n - losses(t)) / (c * m));
}

int main() {
    ofstream fout("output.txt");
    string x = "";
    string y = "";
    double t = tA;
    for (int i = 0; i < 100; i++) {
        cout << i << ' ' << h(t) << ' ' << t << ' ' << f(t) << endl;
        x += to_string(i);
        x += ", ";
        y += to_string(t);
        y += ", ";
        //cout << ' ' << h(t) << endl;
        //' ' << 1.0*floor(sqrt((tR - t)*1.0/(tR - tA)) * (1 - losses(tR)/p) * n *n + n*n*losses(tR)/p) << endl;
        //  << ' ' << sqrt((tR - t)*1.0/(tR - tA)) * (1 - losses(tR)/p) * n 
        // cout << ' ' << n*(n*losses(tR)/p) << endl;
        t += (double)f(t);
    }
    cout << "  " << n * losses(tR) / p << ' ' << losses(tR);
    fout << x << endl << y << endl;
    fout.close();
}