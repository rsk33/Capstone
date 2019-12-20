#ifndef UTILITY_H
#define UTILITY_H

#include <string>

// function to select a map
std::string SelectMap();

// function keeps prompting until int in range is obtained and returns the value
int get_int_in_range(int min_val, int max_val);

#endif