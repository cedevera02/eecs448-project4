#include "Executive.h"
#include <vector>
#include <fstream>



Executive::Executive()
{
    m_restVector = new std::vector<Restaurant*>;
}


Executive::~Executive()
{
    for(int i = 0; i < m_restVector->size(); i++) {
        delete m_restVector->at(i);
    }
    delete m_restVector;
}