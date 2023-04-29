#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>

namespace fun {
	std::tuple<int, int> fast_div(int a, int b) {
		if (b == 0) {
			std::cout << "\nDivided by 0\n";
			return std::make_tuple(0, -1);
		}
		int result = 0;
		int remainder;

		for (a = a; a > b; result++)
			a = a - b;
		if (a < b && a != 0)
			remainder = b - a;
		return std::make_tuple(result, remainder);
	}

	template<typename T>
	T inputf() {
		std::string inputStr;
		std::getline(std::cin, inputStr);
		std::istringstream inputSS(inputStr);
		T input;
		inputSS >> input;
		return input;
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

	double i_power(double base, int n) {
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

	std::string* ReadAllLines(std::string fileName) {
		std::ifstream file(fileName);
		std::string line;
		int count = 0;
		while (std::getline(file, line)) {
			count++;
		}
		std::string* re = new std::string[count];
		int secondcount = 0;

		if (file.is_open()) {
			while (std::getline(file, line)) {
				re[secondcount] = line;
				secondcount++;
			}
			file.close();
		}
		else {
			std::cout << "Unable to open file: " << fileName << '\n';
		}

		return re;
	}
}
