#pragma once
#include <iostream>
using namespace std;

class bad_length : public exception {
public:
    bad_length(const char* msg, int error_data);
    int getError_data() const;
private:
    int error_data;
};

class bad_range : public exception {
public:
    bad_range(const char* msg, int error_data);
    int getError_data() const;
private:
    int error_data;
};
