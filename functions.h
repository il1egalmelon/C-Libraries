#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <tuple>

std::tuple<int, int> fast_div(int a, int b) {
	if (b == 0) {
		std::cout << "\nDivided by 0\n";
		exit(0);
	}
	int result = 0;
	int remainder;

	for (a = a; a > b; result++)
		a = a - b;
	if (a < b && a != 0)
		remainder = b - a;
	return std::make_tuple(result, remainder);
}

auto inputf(int length) {
	char* x = new char[length];
	fgets(x, length, stdin);
	return x;
}

auto print = [](auto in) {
	std::cout << in;
};

auto println = [](auto in) {
	std::cout << in << std::endl;
};

double f_sqrt(const double number) {
	const double ACCURACY = 0.001;
	double lower, upper, guess;

	if (number < 1) {
		lower = number;
		upper = 1;
	} 
	else {
		lower = 1;
		upper = number;
	}
	while ((upper - lower) > ACCURACY) {
		guess = (lower + upper) / 2;
		if (guess * guess > number)
			upper = guess;
		else
			lower = guess;
	}
	return (lower + upper) / 2;
}

double f_power(double base, int n) {
	double result = 1;

	if (n == 0) {
		return result;
	}
	else if (n > 0) {
		for (int i = 0; i < n; i++) {
			result *= base;
		}
	}
	else {
		int abs_n = std::abs(n);
		for (int i = 0; i < abs_n; i++) {
			result /= base;
		}
	}
	return result;
}