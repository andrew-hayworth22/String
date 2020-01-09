/**
 * Michael Hayworth
 * string.cpp
 * CS 23001
 */

/**
 * String Implementation:
 * Defines methods and functions for String.
 */

#include "string.hpp"

String::String() {
    stringSize = 1;
    str = new char[1];
    str[0] = 0;
}

String::String(char ch) {
    stringSize = 2;
    str = new char[stringSize];
    str[0] = ch;
    str[1] = 0;
}

String::String(const char rhs[]) {
    int i = 0;
    while(rhs[i] != 0) {
        ++i;
    }

    stringSize = i + 1;
    str = new char[stringSize];

    for(int j = 0; j < i; ++j) {
        str[j] = rhs[j];
    }
    str[stringSize - 1] = 0;
}

String::String(const String& rhs) {
    stringSize = rhs.stringSize;
    str = new char[stringSize];

    for(int i = 0; i < stringSize; ++i) {
        str[i] = rhs.str[i];
    }
}

String::~String() {
    delete[] str;
}

void String::swap(String& rhs) {
    char* temp = str;
    str = rhs.str;
    rhs.str = temp;

    int tmp = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = tmp;
}

String& String::operator=(String rhs) {
    if(str == rhs.str) return *this;

    delete[] str;
    stringSize = rhs.stringSize;
    str = new char[stringSize];

    for(int i = 0; i < stringSize; ++i) {
        str[i] = rhs.str[i];
    }
    return *this;
}

char& String::operator[](int index) {
    assert(index >= 0 && index < length());
    return str[index];
}

char String::operator[](int index) const {
    assert(index >= 0 && index < length());
    return str[index];
}

int String::capacity() const {
    return stringSize - 1;
}

int String::length() const {
    int i = 0;

    while(str[i] != 0)
        ++i;
    return i;
}

String String::operator+(const String& rhs) const {
    String result = String();

    for(int i = 0; i < length(); ++i) {
        result += str[i];
    }

    int k = 0;
    for(int j = length(); j < length() + rhs.length(); ++j) {
        result += rhs.str[k];
        ++k;
    }

    return result;
}

String operator+(const char lhs[], const String& rhs) {
    return String(lhs) + rhs;
}

String operator+(char lhs, const String& rhs) {
    return String(lhs) + rhs;
}

String& String::operator+=(const String& rhs) {
    char* tempS = str;
    int tempL = stringSize;

    stringSize += rhs.length();
    str = new char[stringSize];

    for(int i = 0; i < tempL - 1; ++i)
        str[i] = tempS[i];

    int k = 0;
    for(int j = tempL - 1; j < stringSize - 1; ++j) {
        str[j] = rhs.str[k];
        ++k;
    }
    str[stringSize - 1] = 0;

    return *this;
}

bool String::operator==(const String& rhs) const {
    int i = 0;

    while((str[i] != 0) && (str[i] == rhs.str[i]))
        ++i;
    return str[i] == rhs.str[i];
}

bool operator==(const char lhs[], const String& rhs) {
    return (String(lhs) == rhs);
}

bool operator==(char lhs, const String& rhs) {
    return (String(lhs) == rhs);
}

bool String::operator<(const String& rhs) const {
    int i = 0;

    while((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) {
        ++i;
    }

    return str[i] < rhs.str[i];
}

bool operator<(const char lhs[], const String& rhs) {
    return String(lhs) < rhs;
}

bool operator<(char lhs, const String& rhs) {
    return String(lhs) < rhs;
}

bool operator<=(const String& lhs, const String& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator>=(const String& lhs, const String& rhs) {
    return (rhs < lhs) || (lhs == rhs);
}

bool operator>(const String& lhs, const String& rhs) {
    return (rhs < lhs);
}

String String::substr(int start, int end) const {
    if(start < 0)
        return String();
    if(start > end)
        return String();
    if(end >= length())
        end = stringSize - 1;

    String result = String();
    int i = start;

    while(i <= end) {
        result += str[i];
        ++i;
    }

    return result;
}

int String::findch(int start, char ch) const {
    if((start < 0) || (start >= length()))
        return -1;

    int i = start;
    while(str[i] != 0) {
        if(str[i] == ch)
            return i;
        ++i;
    }

    return -1;
}

int String::findstr(int start, const String& search) const {
    if((start < 0) || (start > length() - search.length()))
        return -1;
    if(length() < search.length())
        return -1;

    int strlen = search.length();
    int i = start;
    while((str[i] != 0) && (i <= length() - strlen)) {
        if(search == substr(i, i + strlen - 1))
            return i;
        ++i;
    }
    return -1;
}

std::vector<String> String::split(char split) const {
    std::vector<String> result;
    String temp = String();

    for(int i = 0; i < length(); ++i) {
        if(str[i] == split) {
            result.push_back(temp);
            temp = String();
        }
        else
            temp += str[i];
    }

    result.push_back(temp);

    return result;
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    for(int i = 0; i < s.length(); ++i)
        out << s.str[i];
    return out;
}

std::istream& operator>>(std::istream& in, String& rhs) {
    rhs = String();
    char buf;

    in >> std::noskipws;

    while(in >> buf && !in.eof() && buf != '\n' && buf != ' ') {
        rhs += buf;
    }

    return in;
}

String::String(int len) {
    stringSize = len + 1;
    str = new char[stringSize];

    str[0] = 0;

    for(int i = 1; i < len; ++i)
        str[i] = ' ';
}

String::String(int len, const char in[]) {
    stringSize = len + 1;
    str = new char[stringSize];
    String s(in);

    for(int i = 0; i < s.length(); ++i)
        str[i] = s.str[i];
    str[s.length()] = 0;
    for(int i = s.length() + 1; i < stringSize - 1; ++i)
        str[i] = ' ';
}

void String::resetCapacity(int len) {
    char* temp = str;
    int tmp = stringSize;
    int smaller;

    stringSize = len + 1;
    str = new char[stringSize];

    if(len < tmp - 1)
        smaller = tmp;
    else
        smaller = len;

    for(int i = 0; i < smaller; ++i) {
        if(i > tmp - 1)
            str[i] = ' ';
        else
            str[i] = temp[i];
    }
}
