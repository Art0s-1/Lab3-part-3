#include "histogram.h"
#include <iostream>
using namespace std;
size_t Digits(size_t a) {
	size_t digit = 0;
	while (a > 0) {
		a /= 10;
		digit++;
	}
	return digit;
}

void find_minmax(const vector <double>& numbers,
	double& min, double& max) {
	if (numbers.empty())
		return;
	min = numbers[0];
	max = numbers[0];
	for (double x : numbers) {
		if (x < min) {
			min = x;
		}
		else if (x > max) {
			max = x;
		}
	}
}

vector <size_t> make_histogram(const vector <double>& numbers,
	double min, double max, size_t bin_count) {
	double bin_size = (max - min) / bin_count;
	vector <size_t> bins(bin_count);
	for (size_t i = 0; i < numbers.size(); i++) {
		bool found = false;
		for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
			auto lo = min + j * bin_size;
			auto hi = min + (j + 1) * bin_size;
			if ((lo <= numbers[i]) && (numbers[i] < hi)) {
				bins[j]++;
				found = true;
			}
		}
		if (!found) {
			bins[bin_count - 1]++;
		}
	}
	return bins;
}

void show_histogram_text(const vector <size_t>& bins) {
	const size_t SCREEN_WIDTH = 80;
	const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
	size_t max_count = 0;
	for (size_t count : bins) {
		if (count > max_count) {
			max_count = count;
		}
	}
	size_t max_count_dig = Digits(max_count);

	for (size_t count : bins) {
		size_t count_dig = Digits(count);
		for (size_t i = 0; i < max_count_dig - count_dig; i++) {
			cout << " ";
		}
		cout << count << '|';

		size_t height;
		if (max_count <= MAX_ASTERISK) {
			height = count;
		}
		else {
			height = MAX_ASTERISK * (static_cast <double>(count) / max_count);
		}
		for (size_t i = 0; i < height; i++) {
			cout << '*';
		}
		cout << endl;
	}
}