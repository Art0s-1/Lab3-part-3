#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
using namespace std;

size_t Digits(size_t a);

void find_minmax(const vector <double>& numbers,
	double& min, double& max);
	
vector <size_t> make_histogram(const vector <double>& numbers,
	double min, double max, size_t bin_count);

void show_histogram_text(const vector <size_t>& bins);
#endif 