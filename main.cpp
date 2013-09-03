
#include "dcpumanager.hpp"
#include "dcpu.hpp"

int main()
{
    DCPUManager manager;
    DCPU cpu(manager, BASE);
    
    manager.prepareNextDCPU();
    cpu.cycle();
}