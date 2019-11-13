#include "../include/file-manager.h"

InputSymbol::InputSymbol(ifstream& in): input(in) {}

bool InputSymbol::operator>> ( char &c){
    if( input.get(c) )
        return true;
    else
        return false;
}

InputSymbol::~InputSymbol()
{
    input.close();
}

OutputSymbol::OutputSymbol(ofstream& out, unsigned int maximo):output(out)
{
    m_code_size = 9;
    m_pending_bits = 0;
    m_pending_output = 0;
    m_current_code = 256;
    m_next_bump = 512;
    m_max_code = maximo;
}

void OutputSymbol::flush(const int val)
{
    while(m_pending_bits >= val){
        output.put(m_pending_output & MASK);
        m_pending_output >>= 8;
        m_pending_bits -= 8;
    }
}

void OutputSymbol::operator<< (const unsigned int &i){
    m_pending_output |= i <<m_pending_bits;
    m_pending_bits += m_code_size;
    flush(8);
    if(m_current_code < m_max_code){
        m_current_code++;
        if( m_current_code == m_next_bump ){
            m_next_bump *= 2;
            m_code_size++;
        }
    }
}

OutputSymbol::~OutputSymbol(){
    output << EOF_CODE;
    flush(0);
    output.close();
}

InputStream::InputStream(ifstream& in, unsigned int maximo):input(in)
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
        m_pending_bits |= (c & MASK) << m_available_bits;
        m_available_bits += BYTE;
    }
    i = m_pending_bits & ~(~0 << m_code_size);
    m_pending_bits >>= m_code_size;
    m_available_bits -= m_code_size;
    if (m_current_code < m_max_code)
    {
        m_current_code++;
        if (m_current_code == m_next_bump)
        {
            m_next_bump <<= 1;
            m_code_size++;
        }
    }
    if (i == EOF_CODE)
        return false;
    else
        return true;
}

InputStream::~InputStream()
{
    input.close();
}


OutputStream::OutputStream(ofstream& out): output(out) {}

void OutputStream::operator<< (const string& simbolo)
{
    output << simbolo;
}

OutputStream::~OutputStream()
{
    output.close();
}
