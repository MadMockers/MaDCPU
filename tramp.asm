
; This makes a RWX section - code here can be written to.

use64

global dcpuDoBasicOperation
global dcpuDoSpecialOperation
global dcpuNextBasicJump
global dcpuNextSpecialJump
section poly progbits alloc exec write align=16
dcpuDoBasicOperation:
db 0xe9         ; JMP opcode
dcpuNextBasicJump:
dd 0

dcpuDoSpecialOperation:
db 0xe9         ; JMP opcode
dcpuNextSpecialJump:
dd 0

