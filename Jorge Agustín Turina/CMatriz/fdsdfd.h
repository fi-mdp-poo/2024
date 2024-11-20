#ifndef FDSDFD_CPP
#define FDSDFD_CPP


class fdsdfd
{
    public:
        fdsdfd();
        virtual ~fdsdfd();

        unsigned int GetCfff() { return m_Cfff; }
        void SetCfff(unsigned int val) { m_Cfff = val; }
        unsigned int GetCd() { return m_Cd; }
        void SetCd(unsigned int val) { m_Cd = val; }
        unsigned int Getdfdd() { return m_dfdd; }
        void Setdfdd(unsigned int val) { m_dfdd = val; }

    protected:

    private:
        unsigned int m_Cfff;
        unsigned int m_Cd;
        unsigned int m_dfdd;
};

#endif // FDSDFD_CPP
