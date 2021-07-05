#pragma once
#include<iostream>
#include<cmath>

using functions = double(*)(const double& x) ;

double polynom_1(const double& x) {
	return (0.15083588 * x * x + 0.12171106 * x);
}

double polynom_2(const double& x) {
	return (0.420735492 * x * x - 0.2103677462 * x);
}

double function_f(const double & x) {
	return (exp(-sin(x))+sin(x)-1);
}

double max_d(double a, double b, const double& eps, functions f, functions p) {
	double x_1, x_2, F, ó_1, y_2;
	while (fabs(a-b)>eps){
		F = 0.5+sqrt(5)/2;
		x_1 = b - (b - a) / F;
		x_2 = a + (b - a) / F;
		ó_1 = fabs(f(x_1) - p(x_1));
		y_2 = fabs(f(x_2) - p(x_2));
		if (ó_1 <= y_2) {
			a = x_1;
		}
		else {
			b = x_2;
		}
	}
	return ((a + b) / 2);
}

double min_d(double a, double b, const double& eps, functions f, functions p) {
	double x_1, x_2, F, ó_1, y_2;
	while (fabs(a - b) > eps) {
		F = 0.5 + sqrt(5) / 2;
		x_1 = b - (b - a) / F;
		x_2 = a + (b - a) / F;
		ó_1 = fabs(f(x_1) - p(x_1));
		y_2 = fabs(f(x_2) - p(x_2));
		if (ó_1 >= y_2) {
			a = x_1;
		}
		else {
			b = x_2;
		}
	}
	return ((a + b) / 2);
}

void print(const double& a , const double& b, const double& h, const double& eps) {
	using std::cout;
	double x_1 = max_d(a, b, eps, &function_f, &polynom_1);
	double x_2 = max_d(a, b, eps, &function_f, &polynom_2);
	cout << " interval ends\n a = " << a << "      b = " << b << "     step = " << h
		<< "\n\n First polynom with Newton interpolation to function F,\n the points are obtained using the Euler method \n max difference F and P\n"<<
		" x = "<< x_2 << " max difference =  " << fabs(function_f(x_2) - polynom_2(x_2)) <<"\n" ;
	cout << "\n\n Second polynom with Newton interpolation to function F,\n the points are obtained by substituting into the equation \n the solution of which is obtained analytically \n max difference F and P\n" <<
		" x = " << x_1 << " max difference =  " << fabs(function_f(x_1) - polynom_1(x_1)) << "\n";
	return;
}