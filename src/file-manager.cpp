#include "../include/file-manager.h"

 InputStream::InputStream(istream& in, unsigned int maximo):input(in)
{
    m_available_bits = 0;
    m_pending_bits = 0;
    m_code_size = 9;
    m_current_code = 256;
    m_next_bump = 512;
    m_max_code = maximo;
}

bool InputStream::operator>> (unsigned int& i)
{
    while (m_available_bits < m_code_size)
    {
        char c;
        if (!input.get(c))
            return false;
        m_pending_bits |= (c & 0xff) << m_available_bits;
        m_available_bits += 8;
    }
    i = m_pending_bits & ~(~0 << m_code_size);
    m_pending_bits >>= m_code_size;
    m_available_bits -= m_code_size;
    if (m_current_code < m_max_code){
        m_current_code++;
        if (m_current_code == m_next_bump){
            m_next_bump <<= 1;
            m_code_size++;
        }
    }
    if (i == EOF_CODE)
        return false;
    else
        return true;
}

OutputStream::OutputStream(ostream& out): output(out) {}

void OutputStream::operator<< (const string& simbolo)
{
    output << simbolo;
}
