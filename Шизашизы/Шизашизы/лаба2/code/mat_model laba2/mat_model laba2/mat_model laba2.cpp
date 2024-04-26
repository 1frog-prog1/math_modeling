#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

int m = 1;
int p = 3000;
int c = 460;
int tA = 300;
double k = 25;
double s = 0.05;
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
    return t >= tR ? 0 : 1;
}

double f(double t) {
    return (1.0 * (1.0 * p * h(t) - losses(t)) / (c * m));
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
        t += (double)f(t);
    }
    fout << x << endl << y << endl;
    fout.close();
}