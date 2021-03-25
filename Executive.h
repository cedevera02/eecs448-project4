#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Restaurant.h"
#include <vector>

class Executive
{

    private:
    std::vector<Restaurant*>* m_restVector;

    public:
    Executive();
    ~Executive();
    void run();

};


#endif