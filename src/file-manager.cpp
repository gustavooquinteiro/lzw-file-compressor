#include "../include/file-manager.h"

template <typename T> InputStream<T>::InputStream(T& in, unsigned int maximo):input(in)
{
    m_available_bits = 0;
    m_pending_bits = 0;
    m_code_size = 1;
    while(maximo >>= 1)
        m_code_size++;
}

template <typename T> bool InputStream<T>::operator>> (unsigned int& i)
{
    while (m_available_bits < m_code_size)
    {
        char c;
        if (!input.get(c))
            return false;
        m_pending_bits|= (c & 0xff) << m_available_bits;
        m_available_bits += 8;
    }
    i = m_pending_bits & ~(~0 << m_code_size);
    m_pending_bits >>= m_code_size;
    m_available_bits -= m_code_size;
    if (i == EOF_CODE)
        return false;
    else
        return true;
}

template <typename T>OutputStream<T>::OutputStream(T& out): output(out) {}
template<typename T> void OutputStream<T>::operator<< (const std::string& simbolo)
{
    output << simbolo;
}
