#ifndef DDDDDD_H
#define DDDDDD_H


class dddddd
{
    public:
        dddddd();
        virtual ~dddddd();

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

    protected:

    private:
        unsigned int m_Counter;
};

#endif // DDDDDD_H
