
#ifndef DCPUMANAGER_HPP
#define DCPUMANAGER_HPP

#include <list>
#include <memory>

#include "dcpu.hpp"

using std::list;

class DCPUManager
{
    
public:
    void prepareNextDCPU();
    
private:
    list<std::shared_ptr<DCPU>> mDCPUs;

};

void setNextBasic(func_basic_t func);
void setNextSpecial(func_special_t func);

#endif // !DCPUMANAGER_HPP