// .cpp file of NewString
#include <iostream>
#include <cstring>
#include "NewString.h"

using namespace std;

// constructor
String::String(){

    // set cstring to null
    length = 1;
    cstring = new char[length];
    strcpy(cstring,"\n");

}

// constructor by passing a cstring to the object
String::String(const char* stringChar){

    // get the length of a cstring and let length equals the length of the cstring
    length = strlen(stringChar);

    //dynamic allocate the string passed to the string in object
    cstring = new char[30];
    strcpy(cstring,stringChar);
}

//copy constructor
String::String(const String& stringNew){

    // copy the length
    this->length=stringNew.length;

    // dynamic allocate the cstrting to te object
    cstring = new char[length];
    strcpy(cstring,stringNew.cstring);
}

// the destructor
String::~String(){

    // delete the cstring
    delete[] cstring;
}

// the function which returns the length of cstring
int String::size(){
    return length;
}

// the functon which returns the substring in the cstring. Passing 2 values, one is the postion where new string starts, another is the length substring
String String::substring(int position, int newLength){

    // create a new String object
    String stringNew;

    // copy length to the new object
    stringNew.length = newLength;

    // dynamic allocate the substring to the cstring in new object
    stringNew.cstring = new char[stringNew.length];
    strncpy(stringNew.cstring,(this->cstring+position),stringNew.length);
    strcat(stringNew.cstring, "\0");
    stringNew.length += 1;


    //return the String object
    return stringNew;
}

// the function to return the copy of cstring
char* String::c_str(){

    // dynamic allocate the new string and copy cstring to it
    strcat(cstring, "\0");
    char* stringChar = new char[length+1];
    strcpy(stringChar, cstring);

    // return new string
    return stringChar;
}

// overload = function to pass a cstring which copy to the string in object and return a changed String object
String& String::operator= (const char* stringChar){

    // get the length of a cstring and let length equals the length of the cstring
    length = strlen(stringChar);

    // dynamic allocate the cstrting to te object
    cstring = new char[length];
    strcpy(cstring,stringChar);


    //return changed object
    return *this;
}

// overload = function to pass a string object and copy the variables in the object to this* object
String& String::operator= (const String& stringNew){

    //use if to check if two objects are the same
    if(&stringNew != this){

        //set length equals the new string's length
        this->length = stringNew.length;

        //dynamic allocate the cstrting to te object
        cstring = new char[length];
        strcpy(this->cstring,stringNew.cstring);
    }


    //return changed object
    return *this;
}

// overload + function to let two objects' varieables add together to return a new object
String String::operator+ (const String& stringNew){

    //create a new string
    String stringAdd;

    //let two lengths add together and put the result to stringAdd
    stringAdd.length = this->length + stringNew.length;

    //dynamic allocate the string in stringAdd which add two strings together
    stringAdd.cstring = new char[stringAdd.length];
    strcat(this->cstring , stringNew.cstring);
    strcpy(stringAdd.cstring , this->cstring);

    //return stringAdd
    return stringAdd;
}


// the overload == function to check whether two strings are equal
bool String::operator== (const char* stringChar){

    // compare two strings, if they are euqal, return true
    if( strcmp(cstring, stringChar)==0)
        return true;

    // else return false
    else
        return false;
}

// the overload == function to check whether two string objects are equal
bool String::operator== (const String& stringNew){

    // compare cstrings. if they are the same ,return true. if not, return false.

        if(strcmp(this->cstring ,stringNew.cstring)==0)
            return true;

        else
            return false;

}

// overload > function to compare the length of two string objects, and return true or false
bool String::operator> (const String& stringNew){

    // comparing the length of two objects, if this length is bigger, retuen true. if not, retuen false
    if(this->length > stringNew.length)
        return true;

    // else return false
    else
        return false;
}

// overload [] function to get the actually character in which place, and return this character
char& String::operator[] (const int index){

    // dereference the pointer to return the character in index place
    return *(cstring+index);
}

// overload << to display the cstring in the String object
ostream& operator<< (ostream& output, const String& stringNew){

    //output the cstring
    output<< stringNew.cstring<<endl;

    //return output
    return output;
}

// overload >> to receive a cstring to string object
istream& operator>> (std::istream& input, String& stringNew){

    // read the string in buffer and put it into stringNew
    input>>stringNew.cstring;\

    return input;

}
