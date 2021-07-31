clear all;
value1 = csvread('GPSdata/2021-07-30-030152.csv');
value2 = csvread('GPSdata/2021-07-30-031221.csv');
value3 = csvread('GPSdata/2021-07-30-032710.csv');
value = value3;
clear value1;
clear value2;
clear value3;
longitude = deg2rad(value(:,2));
latitude = deg2rad(value(:,3));
r = 6371393;
X = r*(cos(latitude).*cos(longitude));
Y = r*cos(latitude).*sin(longitude);
Z = r*sin(latitude);
X = X - X(1:1);
Y = Y - Y(1:1);
Z = Z - Z(1:1);
plot3(X,Y,Z);
grid on
figure(2)
plot(X,Y);
grid on
