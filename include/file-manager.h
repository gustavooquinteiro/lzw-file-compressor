#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define EOF_CODE 256
#define BYTE 8
#define MASK 0xff

#include <fstream>
#include <iostream>
using namespace std;

class InputStream
{
    ifstream& input;
    int m_code_size;
    int m_available_bits;
    unsigned int m_pending_bits;
    unsigned int m_current_code;
    unsigned int m_next_bump;
    unsigned int m_max_code;
    public:
        InputStream(ifstream& input, unsigned int maximo);
        bool operator>> (unsigned int& i);
        ~InputStream();
};

class OutputStream
{
    ofstream& output;
    public:
        OutputStream(ofstream& output);
        void operator<< (const string& simbolo);
        ~OutputStream();
};

#endif
