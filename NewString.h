// .h file of NewString class
#ifndef NEWSTRING
#define NEWSTRING

// include iostream and cstring libriaries
#include <iostream>
#include <cstring>

class String{

    // initialize two private variables
    private:
        char* cstring;
        int length;

    // initialize all needed public functions
    public:

        // constructors
        String();
        String(const char*);
        String(const String&);

        // some special functio to get size, substring, and string copy
        int size();
        String substring(int, int);
        char* c_str();

        //overload operator functions
        String& operator= (const char*);
        String& operator= (const String&);
        String operator+ (const String&);
        String operator+ (char);
        bool operator== (const char*);
        bool operator== (const String&);
        bool operator> (const String&);
        char& operator[] (const int);

        // friend function to output and input cstring in String class
        friend std::ostream& operator<< (std::ostream&, const String&);
        friend std::istream& operator>> (std::istream&, String&);

        //destructor
        ~String();

};


#endif
