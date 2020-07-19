#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1-x2), 2)+pow((y1-y2), 2));
}

int main() {
    double pi = 3.141592653589793;
    double x[3];
    double y[3];
    while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2]) {
        double x_o{ }, y_o{ };
        // for (int i=0; i < 3; i++) {
        //     cin >> x[i] >> y[i];
        // }
        // double a1{ }, a2{ }, b1{ }, b2{ }, c1{ }, c2{ };
        // a1 = x[1] - x[2];
        // b1 = y[1] - y[2];
        // c1 = -(pow(x[1], 2)-pow(x[2], 2)+pow(y[1], 2)-pow(y[2], 2))/2;
        // a2 = x[0] - x[1];
        // b2 = y[0] - y[1];
        // c2 = -(pow(x[0], 2)-pow(x[1], 2)+pow(y[0], 2)-pow(y[1], 2))/2;
        // x_o = (b1*c2  - b2*c1)/(a1*b2 - a2*b1);
        // y_o = (a2*c1 - a1*c2)/(a1*b2 - a2*b1);
        // double final_ans = 2.0*pi*distance(x_o, y_o, x[0], y[0]);
        // printf("%.4f\n", final_ans);
        double a{ }, b{ }, c{ }, s{ }, r{ };
        a = distance(x[0], y[0], x[1], y[1]);
        b = distance(x[1], y[1], x[2], y[2]);
        c = distance(x[2], y[2], x[0], y[0]);
        s = (a+b+c)/2;
        r = (a*b*c)/(4*sqrt(s*(s-a)*(s-b)*(s-c)));
        double final_ans = 2.0*pi*r;
        printf("%.2f\n", final_ans);
        if (cin.eof()) break;
    }
}
