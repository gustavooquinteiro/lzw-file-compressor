#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define EOF_CODE 256

#include <fstream>
#include <iostream>
using namespace std;

class InputStream
{
    istream& input;
    int m_code_size;
    int m_available_bits;
    unsigned int m_pending_bits;
    unsigned int m_current_code;
    unsigned int m_next_bump;
    unsigned int m_max_code;
    public:
        InputStream(istream& input, unsigned int maximo);
        bool operator>> (unsigned int& i);
};

class OutputStream
{
    ostream& output;
    public:
        OutputStream(ostream& output);
        void operator<< (const string& simbolo);
};

#endif
