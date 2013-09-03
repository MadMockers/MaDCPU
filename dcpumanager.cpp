
#include "dcpumanager.hpp"

void DCPUManager::prepareNextDCPU()
{
    // TODO: Stub
    setNextBasic(&DCPU::set);
    setNextSpecial(&DCPU::jsr);
}

/* the address of these vars point to the relative jumps */
extern uint32_t dcpuNextBasicJump;
extern uint32_t dcpuNextSpecialJump;

void setNextBasic(func_basic_t func)
{
    uintptr_t gotoAddr = *reinterpret_cast<uintptr_t*>(&func);
    dcpuNextBasicJump = (gotoAddr - (uintptr_t) &dcpuNextBasicJump - 4);
}

void setNextSpecial(func_special_t func)
{
    uintptr_t gotoAddr = *reinterpret_cast<uintptr_t*>(&func);
    dcpuNextSpecialJump = (gotoAddr - (uintptr_t) &dcpuNextSpecialJump - 4);
}