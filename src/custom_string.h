#ifndef UBUNTU_PLAYGROUND_CUSTOM_STRING_H
#define UBUNTU_PLAYGROUND_CUSTOM_STRING_H

#include <iostream>
#include <string>
using namespace std;

class CustomString {
private:
    char* data;
    size_t size_;
public:
    // Constructor & Destructor
    CustomString();
    explicit CustomString(const string& str);
    explicit CustomString(const char* cstr);
    explicit CustomString(string&& other) noexcept;
    CustomString& operator=(string str) noexcept;

    ~CustomString();
    CustomString(const CustomString& other);
    CustomString(CustomString&& other) noexcept;
    CustomString& operator=(const CustomString& other);
    CustomString& operator=(CustomString&& other) noexcept;

    // Capacity & Getter
    size_t size() const;
    bool IsEmpty() const;
    const char* c_str() const;

};

ostream& operator<<(ostream& os, const CustomString& str);

#endif //UBUNTU_PLAYGROUND_CUSTOM_STRING_H
