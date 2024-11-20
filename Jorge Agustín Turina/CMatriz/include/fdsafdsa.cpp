#ifndef FDSAFDSA_CPP
#define FDSAFDSA_CPP


class fdsafdsa
{
    public:
        fdsafdsa();
        virtual ~fdsafdsa();

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

    protected:

    private:
        unsigned int m_Counter;
};

#endif // FDSAFDSA_CPP
