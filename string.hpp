/**
 * Michael Hayworth
 * string.hpp
 * CS 23001
 */

/**
 * String Header:
 * Defines methods and functions for String.
 */

////////////////////////////////////////////////////
// CLASS INV: str[length()] == 0             &&
//            length()      == capacity()    &&
//            capacity()    == stringSize - 1
//

#ifndef CS23001_STRING_INTERFACE_HPP
#define CS23001_STRING_INTERFACE_HPP

#include <iostream>
#include <cassert>
#include <vector>

class String {
public:
            String        ();                               //Empty string
            String        (char);                           //String('x')
            String        (const char[]);                   //String("abc")
            String        (const String&);                  //Copy Constructor
            ~String       ();                               //Destructor
    void    swap          (String&);                        //Constant time swap
    String& operator=     (String);                         //Assignment Copy
    char&   operator[]    (int);                            //Accessor/Modifier
    char    operator[]    (int)                     const;  //Accessor
    int     capacity      ()                        const;  //Max chars that can be stored (not including null)
    int     length        ()                        const;  //Actual number of chars in string
    String  operator+     (const String&)           const;
    String& operator+=    (const String&);
    bool    operator==    (const String&)           const;
    bool    operator<     (const String&)           const;
    String  substr        (int, int)                const;  //The sub-string from staring position to ending position
    int     findch        (int,  char)              const;  //Find location of charater starting at a position
    int     findstr       (int,  const String&)     const;  //Find location of str starting at a position

            std::vector<String> split(char)         const;  //Split String into vector of strings at the char given.

    friend  std::ostream& operator<<(std::ostream&, const String&);
    friend  std::istream& operator>>(std::istream&, String&);

            String        (int);                            //String(10) - capacity 10, empty string
            String        (int, const char[]);              //String(10, "abc") - capacity 10 with "abc"

private:
    void    resetCapacity (int);                            //Resets capacity to N, keeps string intact

    char    *str;                                           //Pointer to char[]
    int     stringSize;                                     //Size includes NULL terminator
};

String  operator+       (const char[],  const String&);
String  operator+       (char,          const String&);
bool    operator==      (const char[],  const String&);
bool    operator==      (char,          const String&);
bool    operator<       (const char[],  const String&);
bool    operator<       (char,          const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);

#endif