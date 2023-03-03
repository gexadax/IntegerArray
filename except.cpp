#include "except.h"
using namespace std;

bad_length::bad_length(const char* msg, int error_data) : exception(msg) {
    this->error_data = error_data;
}
int bad_length::getError_data() const {
    return error_data;
}

bad_range::bad_range(const char* msg, int error_data) : exception(msg) {
    this->error_data = error_data;
}
int bad_range::getError_data() const {
    return error_data;
}