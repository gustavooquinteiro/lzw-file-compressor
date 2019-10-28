#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define EOF_CODE 256

#include <fstream>

template <typename T> class InputStream
{
    T& input;
    int m_code_size;
    int m_available_bits;
    unsigned int m_pending_bits;
    public:
        InputStream(T &input, unsigned int maximo);
        bool operator>> (unsigned int& i);
};

template <typename T> class OutputStream
{
    T& output;
    public:
        OutputStream(T& output);
        void operator<< (const std::string& simbolo);
};

#endif
