#include <iostream>
#include "stdio.h"
#include "math.h"

const double earth_r = 6371393;

double calcDistance(double x_longtitude, double x_latitude, double x_height, double y_longtitude, double y_latitude,
                    double y_height) {
    double longtitude_rad = M_PI * x_longtitude / 180.0;
    double latitude_rad = M_PI * x_latitude / 180.0;
    double x[3], y[3];
    x[0] = cos(latitude_rad) * cos(longtitude_rad);
    x[1] = cos(latitude_rad) * sin(longtitude_rad);
    x[2] = sin(latitude_rad);
    longtitude_rad = M_PI * y_longtitude / 180.0;
    latitude_rad = M_PI * y_latitude / 180.0;
    y[0] = cos(latitude_rad) * cos(longtitude_rad);
    y[1] = cos(latitude_rad) * sin(longtitude_rad);
    y[2] = sin(latitude_rad);
    double alpha = 0;
    for (int i = 0; i < 3; ++i) {
        alpha += x[i] * y[i];
    }
    alpha = acos(alpha);
    std::cout << "alpha = " << alpha*4 << std::endl;
    return alpha * (earth_r + ((x_height + y_height) / 2));
}

int main() {
//    double distance = calcDistance(113.9982033333, 22.6052016667, 141.14, 113.9982066667, 22.6051765000, 141.86);
    double distance = calcDistance(113.9982033333, 22.6052016667, 0, 113.9982066667, 22.6051765000, 0);
    std::cout << "distance = " << distance << std::endl;
    return 0;
}
