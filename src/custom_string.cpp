#include "custom_string.h"
#include <string>
#include <cstring>

CustomString::CustomString() {
    cout << "Invoking default constructor" << endl;
    data = nullptr;
    size_ = 0;
}

CustomString::CustomString(const string& str) {
    cout << "Invoking string& constructor" << endl;
    data = new char[str.size() + 1];
    copy(str.begin(), str.end(), data);
    size_ = str.size();
    data[size_] = '\0';
}

CustomString::CustomString(const char* cstr) {
    cout << "Invoking const char* constructor" << endl;
    size_ = strlen(cstr);
    data = new char[size_ + 1];
    strcpy(data, cstr);
    data[size_] = '\0';
}

CustomString::CustomString(string&& other) noexcept {
    cout << "Invoking string&& constructor" << endl;
    size_ = other.size();
    data = new char[size_ + 1];
    copy(other.begin(), other.end(), data);
    data[size_] = '\0';
    other.clear();
}

CustomString::~CustomString() {
    delete[] data;
}

CustomString::CustomString(const CustomString& other) {
    cout << "Invoking CustomString& constructor" << endl;
    data = new char[other.size() + 1];
    size_ = other.size();
    std::copy(other.data, other.data + other.size(), data);
    data[size_] = '\0';
}

CustomString::CustomString(CustomString &&other) noexcept:
    data(other.data), size_(other.size_) {
    cout << "Invoking CustomString&& constructor" << endl;
    other.data = nullptr;
    other.size_ = 0;
}

CustomString& CustomString::operator=(const CustomString& other) {
    cout << "Invoking CustomString& operator= constructor" << endl;
    if (this != &other) {
        if (data != nullptr) {
            delete[] data;
        }
        size_ = other.size();
        data = new char[size_ + 1];
        std::copy(other.data, other.data + other.size(), data);
        data[size_] = '\0';
        size_ = other.size();
    }
    return *this;
}

CustomString& CustomString::operator=(CustomString&& other) noexcept{
    cout << "Invoking CustomString&& operator= constructor" << endl;
    if (this != &other) {
        if (data != nullptr) {
            delete[] data;
        }
        data = other.data;
        size_ = other.size_;
        other.data = nullptr;
        other.size_ = 0;
    }
    return *this;
}

CustomString& CustomString::operator=(std::string str) noexcept {
    cout << "Invoking string operator= constructor" << endl;
    if (data != nullptr) {
        delete[] data;
    }
    size_ = str.size();
    data = new char[size_ + 1];
    copy(str.begin(), str.end(), data);
    data[size_] = '\0';
    return *this;
}

size_t CustomString::size() const {
    return this->size_;
}

bool CustomString::IsEmpty() const {
    return this->size_ == 0;
}

const char* CustomString::c_str() const {
    return this->data;
}

ostream& operator<<(ostream& os, const CustomString& str) {

    os << "CustomString: " << str.c_str() << ", Size: " << str.size();
    return os;
}