
#ifndef DCPU_HPP
#define DCPU_HPP

#include <cstdint>
#include <memory>

enum DCPUVariant
{
    BASE,
    EXTENDED
};

enum Register
{
    A = 0,
    B,
    C,
    X,
    Y,
    Z,
    I,
    J,
    PC,
    SP,
    EX,
    IA,
    RM,
    MB,
    REGISTERS_COUNT
};

enum BasicOp
{
    SPECIAL = 0x00,
    SET = 0x01,
    ADD = 0x02,
    SUB = 0x03,
    MUL = 0x04,
    MLI = 0x05,
    DIV = 0x06,
    DVI = 0x07,
    MOD = 0x08,
    MDI = 0x09,
    AND = 0x0A,
    BOR = 0x0B,
    XOR = 0x0C,
    SHR = 0x0D,
    ASR = 0x0E,
    SHL = 0x0F,
    IFB = 0x10,
    IFC = 0x11,
    IFE = 0x12,
    IFN = 0x13,
    IFG = 0x14,
    IFA = 0x15,
    IFL = 0x16,
    IFU = 0x17,
    
    ADX = 0x1A,
    SBX = 0x1B,
    
    STI = 0x1E,
    STD = 0x1F
};

enum SpecialOp
{
    RESERVED = 0x00,
    JSR = 0x01,
    
    MBG = 0x05,
    MBO = 0x06,
    HCF = 0x07,
    INT = 0x08,
    IAG = 0x09,
    IAS = 0x0A,
    RFI = 0x0B,
    IAQ = 0x0C,
    
    HWN = 0x10,
    HWQ = 0x11,
    HWI = 0x12,
    
    GRM = 0x16,
    DRM = 0x17,
    SRT = 0x18
};

#define REG_A   mRegisters[A]
#define REG_B   mRegisters[B]
#define REG_C   mRegisters[C]
#define REG_X   mRegisters[X]
#define REG_Y   mRegisters[Y]
#define REG_Z   mRegisters[Z]
#define REG_I   mRegisters[I]
#define REG_J   mRegisters[J]
#define REG_PC  mRegisters[PC]
#define REG_SP  mRegisters[SP]
#define REG_EX  mRegisters[EX]
#define REG_IA  mRegisters[IA]
#define REG_RM  mRegisters[RM]
#define REG_MB  mRegisters[MB]

#define BASIC(NAME) void NAME(uint8_t a, uint8_t b)
#define SPECIAL(NAME) void NAME(uint8_t a)

typedef uint16_t instruction_t;
typedef uint16_t word_t;
typedef uint32_t dword_t;
typedef uint8_t access_t;

class DCPU;

typedef void (DCPU::*func_basic_t)(uint8_t, uint8_t);
typedef void (DCPU::*func_special_t)(uint8_t);

class DCPUManager;

class DCPU
{

public:
    DCPU(DCPUManager& manager, DCPUVariant variant);
    ~DCPU();
    
    void initialize();
    
    void prepareCycle();
    void cycle();

public:
    /* Opcode Funcions */
    BASIC(specialOp);
    BASIC(set);
    BASIC(add);
    BASIC(sub);
    BASIC(mul);
    BASIC(mli);
    BASIC(div);
    BASIC(dvi);
    BASIC(mod);
    BASIC(mdi);
    BASIC(bitwise_and);
    BASIC(bor);
    BASIC(bitwise_xor);
    BASIC(shr);
    BASIC(asr);
    BASIC(shl);
    BASIC(ifb);
    BASIC(ifc);
    BASIC(ife);
    BASIC(ifn);
    BASIC(ifg);
    BASIC(ifa);
    BASIC(ifl);
    BASIC(ifu);
    BASIC(adx);
    BASIC(sbx);
    BASIC(sti);
    BASIC(std);
    BASIC(undefinedBasic);
    
    SPECIAL(jsr);
    SPECIAL(mbg);
    SPECIAL(mbo);
    SPECIAL(hcf);
    SPECIAL(interrupt);
    SPECIAL(iag);
    SPECIAL(ias);
    SPECIAL(rfi);
    SPECIAL(iaq);
    SPECIAL(hwn);
    SPECIAL(hwq);
    SPECIAL(hwi);
    SPECIAL(grm);
    SPECIAL(drm);
    SPECIAL(srt);
    SPECIAL(undefinedSpecial);
    SPECIAL(reserved);

private:
    DCPUManager& mManager;

    DCPUVariant mVariant;
    
    uint64_t    mMemorySize;
    uint8_t     mMemoryBankMax;
    std::unique_ptr<word_t[]> mMemory;
    std::unique_ptr<access_t[]> mAccess;
    
    word_t      mRegisters[REGISTERS_COUNT];
    
    uint8_t     mNextOpcode;
    uint8_t     mNextAValue;
    uint8_t     mNextBValue;
};

#undef BASIC
#undef SPECIAL

/* 'self' is an uber hack - since these are extern C, we have to hack in the C++ support */
extern "C" void dcpuDoBasicOperation(DCPU* self, uint8_t a, uint8_t b);
extern "C" void dcpuDoSpecialOperation(DCPU* self, uint8_t b);

#endif // DCPU_HPP
