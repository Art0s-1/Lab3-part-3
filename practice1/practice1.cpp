#include <iostream>
#include <vector>
#include <string>
#include "histogram.h"
#include "svg.h"

using namespace std;



vector <double> input_numbers(size_t count) {
	vector <double>  result(count);
	cerr << "Enter numbers: ";
	for (size_t i = 0; i < count; i++) {
		cin >> result[i];
	}
	return result;
}
 
int main() {
	size_t number_count;
	cerr << "Enter number count: ";
	cin >> number_count;
	const auto numbers = input_numbers(number_count);

	double min, max;
	find_minmax(numbers, min, max);

	size_t bin_count;
	cerr << "Enter bin count: ";
	cin >> bin_count;

	const auto bins = make_histogram(numbers, min, max, bin_count);

	show_histogram_svg(bins);
}

