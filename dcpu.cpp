
#include <cstring>
#include <cstdio>

#include "dcpumanager.hpp"
#include "dcpu.hpp"

static func_basic_t gBasicFunctions[] = 
{
    &DCPU::specialOp,
    &DCPU::set,
    &DCPU::add,
    &DCPU::sub,
    &DCPU::mul,
    &DCPU::mli,
    &DCPU::div,
    &DCPU::dvi,
    &DCPU::mod,
    &DCPU::mdi,
    &DCPU::bitwise_and,
    &DCPU::bor,
    &DCPU::bitwise_xor,
    &DCPU::shr,
    &DCPU::asr,
    &DCPU::shl,
    &DCPU::ifb,
    &DCPU::ifc,
    &DCPU::ife,
    &DCPU::ifn,
    &DCPU::ifg,
    &DCPU::ifa,
    &DCPU::ifl,
    &DCPU::ifu,
    &DCPU::undefinedBasic,
    &DCPU::undefinedBasic,
    &DCPU::adx,
    &DCPU::sbx,
    &DCPU::undefinedBasic,
    &DCPU::undefinedBasic,
    &DCPU::sti,
    &DCPU::std
};

static func_special_t gSpecialFunctions[] = 
{
    &DCPU::reserved,
    &DCPU::jsr,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::mbg,
    &DCPU::mbo,
    &DCPU::hcf,
    &DCPU::interrupt,
    &DCPU::iag,
    &DCPU::ias,
    &DCPU::rfi,
    &DCPU::iaq,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::hwn,
    &DCPU::hwq,
    &DCPU::hwi,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::grm,
    &DCPU::drm,
    &DCPU::srt,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial,
    &DCPU::undefinedSpecial
};

DCPU::DCPU(DCPUManager& manager, DCPUVariant variant) : mManager(manager), mVariant(variant)
{
    mManager = manager;
    mVariant = variant;
}

void DCPU::initialize()
{
    switch(mVariant)
    {
    case BASE:
        {
            mMemorySize = 0x10000;
            mMemoryBankMax = 1;
        }
        break;
        
    case EXTENDED:
        {
            mMemorySize = 0x10000;
            mMemoryBankMax = 8;
        }
        break;
    }
    mMemory.reset(new uint16_t[mMemorySize * mMemoryBankMax]);
    memset(mMemory.get(), 0, mMemorySize * mMemoryBankMax);
    memset(mRegisters, 0, REGISTERS_COUNT);
}

DCPU::~DCPU()
{
}

void DCPU::prepareCycle()
{
    instruction_t inst = mMemory[REG_PC++];
    mNextOpcode = inst & 0x1F;
    mNextAValue = (inst >> 5) & 0x1F;
    mNextBValue = (inst >> 10);
}

void DCPU::cycle()
{
    uint8_t a = mNextAValue;
    uint8_t b = mNextBValue;
    
    dcpuDoBasicOperation(this, a, b);
    //(this->*gBasicFunctions[op])(a, b);
}

void DCPU::set(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
    
    printf("test\n");
}

void DCPU::add(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::sub(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::mul(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::mli(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::div(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::dvi(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::mod(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::mdi(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::bitwise_and(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::bor(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::bitwise_xor(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::shr(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::asr(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::shl(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::ifb(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::ifc(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::ife(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::ifn(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::ifg(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::ifa(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::ifl(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::ifu(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::adx(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::sbx(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::sti(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::std(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::undefinedBasic(uint8_t a, uint8_t b)
{
    mManager.prepareNextDCPU();
}

void DCPU::specialOp(uint8_t a, uint8_t opCode)
{
    mManager.prepareNextDCPU();
}

void DCPU::reserved(uint8_t b)
{
    dcpuDoSpecialOperation(this, b);
}

void DCPU::jsr(uint8_t b)
{
    
}

void DCPU::mbg(uint8_t b)
{
    
}

void DCPU::mbo(uint8_t b)
{
    
}

void DCPU::hcf(uint8_t b)
{
    
}

void DCPU::interrupt(uint8_t b)
{
    
}

void DCPU::iag(uint8_t b)
{
    
}

void DCPU::ias(uint8_t b)
{
    
}

void DCPU::rfi(uint8_t b)
{
    
}

void DCPU::iaq(uint8_t b)
{
    
}

void DCPU::hwn(uint8_t b)
{
    
}

void DCPU::hwq(uint8_t b)
{
    
}

void DCPU::hwi(uint8_t b)
{
    
}

void DCPU::grm(uint8_t b)
{
    
}

void DCPU::drm(uint8_t b)
{
    
}

void DCPU::srt(uint8_t b)
{
    
}

void DCPU::undefinedSpecial(uint8_t b)
{
    
}
