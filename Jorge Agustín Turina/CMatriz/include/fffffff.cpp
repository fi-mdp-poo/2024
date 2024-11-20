#ifndef FFFFFFF_CPP
#define FFFFFFF_CPP


class fffffff
{
    public:
        fffffff();
        virtual ~fffffff();

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }
        unsigned int GetCofdsafds() { return m_Cofdsafds; }
        void SetCofdsafds(unsigned int val) { m_Cofdsafds = val; }

    protected:

    private:
        unsigned int m_Counter;
        unsigned int m_Cofdsafds;
};

#endif // FFFFFFF_CPP
