#ifndef DFASFDASF_CPP
#define DFASFDASF_CPP


class DFASFDASF
{
    public:
        DFASFDASF();
        virtual ~DFASFDASF();

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

    protected:

    private:
        unsigned int m_Counter;
};

#endif // DFASFDASF_CPP
