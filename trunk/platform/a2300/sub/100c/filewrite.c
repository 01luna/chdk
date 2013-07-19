/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 7 // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1;
    int file_offset;
    int full_size;
    int unkn2, unkn3, unkn4;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int seek_flag;
    char name[32];       // open stage: sub_FFA52A4C (1.00f) --> "ADD     R7, R4, #0x54"
                         // offset of 'name' from start = 0x54 = 84 bytes = 21 words
} fwt_data_struct;
#define FWT_MUSTSEEK    2   // value of the masked seek_flag indicating seek is required
#define FWT_SEEKMASK    0xffffffff   // masks out unneeded bits of seek_flag

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFA5231C - 0xFFA52460, length=82
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R7,LR} \n"
"    LDR     R7, =0x96BC \n"
"    MOV     R6, #0 \n"

"loc_FFA52328:\n"
"    LDR     R0, [R7, #0x14] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R5, R7 \n"
"    BL      sub_003F7218 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x38E \n"
"    LDRNE   R0, =0xFFA52460 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xB \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FFA52328 \n"
"    B       loc_FFA52430 \n"
"    B       loc_FFA52430 \n"
"    B       loc_FFA52430 \n"
"    B       loc_FFA52430 \n"
"    B       loc_FFA52430 \n"
"    B       loc_FFA52430 \n"
"    B       loc_FFA52430 \n"
"    B       loc_FFA52438 \n"
"    B       loc_FFA5238C \n"
"    B       loc_FFA523FC \n"
"    B       loc_FFA523F4 \n"

"loc_FFA5238C:\n"
"    STR     R6, [SP] \n"

"loc_FFA52390:\n"
"    LDR     R0, [R5, #0x14] \n"
"    MOV     R1, SP \n"
"    BL      sub_003F745C /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFA523BC \n"
"    LDR     R0, [R5, #0x14] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_003F7218 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFA52390 \n"

"loc_FFA523BC:\n"
"    LDR     R0, [R5, #8] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFA523E8 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R5, #8] \n"
"    LDR     R0, =0x131D20 \n"
"    STR     R6, [R5, #4] \n"
"    BL      sub_FF8669E0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF864CF8 \n"

"loc_FFA523E8:\n"
"    LDR     R0, [R5, #0x10] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFA52328 \n"

"loc_FFA523F4:\n"
"    BL      sub_FFA52018_my \n"  // --> Patched. Old value = 0xFFA52018. Open stage
"    B       loc_FFA52328 \n"

"loc_FFA523FC:\n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #8] \n"
"    MOV     R2, #0 \n"
"    BL      fwt_lseek \n"  // --> Patched. Old value = _lseek.
"    CMN     R0, #1 \n"
"    LDREQ   R0, =0x9200013 \n"
"    MOV     R1, R4 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    MOVNE   R0, #0 \n"
"    MOVEQ   R0, #7 \n"
"    BL      sub_FFA51F5C \n"
"    B       loc_FFA52328 \n"

"loc_FFA52430:\n"
"    BL      sub_FFA52658_my \n"  // --> Patched. Old value = 0xFFA52658. Write stage
"    B       loc_FFA52328 \n"

"loc_FFA52438:\n"
"    BL      sub_FFA52184_my \n"  // --> Patched. Old value = 0xFFA52184. Close stage
"    B       loc_FFA52328 \n"
);
}

/*************************************************************/
//** sub_FFA52018_my @ 0xFFA52018 - 0xFFA52180, length=91
void __attribute__((naked,noinline)) sub_FFA52018_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    LDR     R6, =0x96BC \n"
"    MOV     R4, R0 \n"
//hook start placed here to avoid bne a few instructions below
//R0 holds data block start
"    STMFD   SP!, {R4-R12,LR}\n"
"    BL      filewrite_main_hook\n"
"    LDMFD   SP!, {R4-R12,LR}\n"
//hook end
"    LDR     R0, [R6, #4] \n"
"    SUB     SP, SP, #0x3C \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFA52154 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF8669E0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF864BBC \n"
"    LDR     R0, [R4, #0x10] \n"
"    BL      sub_FF810364 \n"
"    LDR     R0, [R4, #0x50] \n"
"    LDR     R9, =0x1B6 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #0xC] \n"
"    ADD     R7, R4, #0x54 \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #0xC] \n"
"    LDR     R8, [R4, #0xC] \n"
"    LDR     R5, [R4, #0x10] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R8 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    CMN     R0, #1 \n"
"    BNE     loc_FFA520E4 \n"
"    MOV     R0, R7 \n"
"    BL      sub_FF831CB4 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R7 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_003FC17C \n"
"    MOV     R0, #0 \n"
"    LDR     R1, =0x41FF \n"
"    STRB    R0, [SP, #0x13] \n"
"    STR     R1, [SP, #0x24] \n"
"    MOV     R1, #0x10 \n"
"    STR     R0, [SP, #0x2C] \n"
"    STR     R1, [SP, #0x28] \n"
"    ADD     R1, SP, #0x24 \n"
"    ADD     R0, SP, #4 \n"
"    STR     R5, [SP, #0x30] \n"
"    STR     R5, [SP, #0x34] \n"
"    STR     R5, [SP, #0x38] \n"
"    BL      sub_FF864538 \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R8 \n"
"    MOV     R0, R7 \n"
"    BL      _Open \n"

"loc_FFA520E4:\n"
"    CMN     R0, #1 \n"
"    MOV     R5, R0 \n"
"    STR     R0, [R6, #8] \n"
"    BNE     loc_FFA52120 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF8669E0 \n"
"    LDR     R1, [R6, #0x1C] \n"
"    BL      sub_FF864CF8 \n"
"    LDR     R1, [R6, #0x18] \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FFA5217C \n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,LR} \n"
"    LDR     R0, =0x9200001 \n"
"    BX      R1 \n"

"loc_FFA52120:\n"
"    MOV     R0, #1 \n"
"    STR     R0, [R6, #4] \n"
"    LDR     R0, =0x131D20 \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x54 \n"
"    BL      sub_003FC364 \n"
//mod start
"    LDR     R3, =current_write_ignored\n"
"    LDR     R3, [R3]\n"
"    CMP     R3, #0\n"
"    BNE     loc_A\n" // jump over the next block
//mod end
"    LDR     R1, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF831984 \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, R4 \n"
"    MOVEQ   R0, #7 \n"
"    BEQ     loc_FFA52178 \n"

"loc_FFA52154:\n"
"loc_A:\n"
"    LDR     R0, [R4, #0x50] \n"
"    CMP     R0, #2 \n"
"    BEQ     loc_FFA52170 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, R4 \n"
"    BEQ     loc_FFA52178 \n"

"loc_FFA52170:\n"
"    MOV     R1, R4 \n"
"    MOV     R0, #9 \n"

"loc_FFA52178:\n"
"    BL      sub_FFA51F5C \n"

"loc_FFA5217C:\n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"
);
}

/*************************************************************/
//** sub_FFA52658_my @ 0xFFA52658 - 0xFFA52734, length=56
void __attribute__((naked,noinline)) sub_FFA52658_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FFA52684 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x18]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FFA5269C \n"
"    B       loc_FFA52690 \n"

"loc_FFA52684:\n"
"    LDR     R1, =0x2DD \n"
"    LDR     R0, =0xFFA52460 \n"
"    BL      _DebugAssert \n"

"loc_FFA52690:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFA52730 \n"

"loc_FFA5269C:\n"
"    LDR     R9, =0x96BC \n"
"    MOV     R4, R7 \n"

"loc_FFA526A4:\n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #8] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FFA52704 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_FFA52690 \n"

"loc_FFA52704:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    ADD     R8, R8, R0 \n"
"    MOVCS   R1, #0x308 \n"
"    LDRCS   R0, =0xFFA52460 \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFA526A4 \n"
"    LDR     R0, [R5] \n"
"    MOV     R1, R5 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFA52730:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFA51F5C \n"
);
}

/*************************************************************/
//** sub_FFA52184_my @ 0xFFA52184 - 0xFFA52318, length=102
void __attribute__((naked,noinline)) sub_FFA52184_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0, #0x50] \n"
"    LDR     R5, =0x96BC \n"
"    CMP     R0, #3 \n"
"    SUB     SP, SP, #0x38 \n"
"    BEQ     loc_FFA522FC \n"
"    LDR     R0, [R5, #8] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFA521D8 \n"
"    LDR     R1, [R4, #0xC] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FFA521C4 \n"
//mod start
"    LDR     R3, =current_write_ignored\n"
"    LDR     R3, [R3]\n"
"    CMP     R3, #0\n"
"    BNE     loc_B\n" // jump over the next block
//mod end
"    BL      sub_FF8316D8 \n"
"    B       loc_FFA521C8 \n"

"loc_FFA521C4:\n"
"loc_B:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.

"loc_FFA521C8:\n"
"    CMP     R0, #0 \n"
"    MVN     R0, #0 \n"
"    STRNE   R6, [R4, #0x14] \n"
"    STR     R0, [R5, #8] \n"

"loc_FFA521D8:\n"
"    LDR     R0, [R4, #0x14] \n"
"    TST     R0, #1 \n"
"    BNE     loc_FFA522E0 \n"
"    LDR     R0, [R4, #0xC] \n"
"    TST     R0, #8 \n"
"    BNE     loc_FFA521FC \n"
"    LDR     R0, [R4, #0x50] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_FFA5222C \n"

"loc_FFA521FC:\n"
"    ADD     R1, SP, #0x20 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF864480 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x346 \n"
"    LDREQ   R0, =0xFFA52460 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R4, #4] \n"
"    ADD     R0, R0, R1 \n"
"    STR     R0, [SP, #0x28] \n"
"    B       loc_FFA5225C \n"

"loc_FFA5222C:\n"
"    LDR     R0, =0x81FF \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x20 \n"
"    STR     R0, [SP, #0x24] \n"
"    LDR     R0, [R4, #4] \n"
"    STR     R0, [SP, #0x28] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [SP, #0x2C] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [SP, #0x30] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [SP, #0x34] \n"

"loc_FFA5225C:\n"
"    LDR     R0, [R4, #0x50] \n"
"    CMP     R0, #2 \n"
"    BEQ     loc_FFA522E0 \n"
"    ADD     R1, SP, #0x20 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF864538 \n"
"    LDR     R0, [R4, #0x50] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFA522E0 \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x54 \n"
"    MOV     R0, SP \n"
"    BL      sub_003FC364 \n"
"    MOV     R0, SP \n"
"    BL      _strlen \n"
"    MOV     R2, #0x54 \n"
"    ADD     R0, R0, SP \n"
"    MOV     R1, #0x4D \n"
"    STRB    R2, [R0, #-3] \n"
"    STRB    R1, [R0, #-2] \n"
"    MOV     R1, #0x50 \n"
"    STRB    R1, [R0, #-1] \n"
"    MOV     R1, SP \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF863DD0 \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, #0x164 \n"
"    LDREQ   R0, =0xFFA52460 \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, SP \n"
"    BL      sub_FF864994 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF864994 \n"

"loc_FFA522E0:\n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF8669E0 \n"
"    LDR     R1, [R5, #0x1C] \n"
"    BL      sub_FF864CF8 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R5, #4] \n"
"    B       loc_FFA52304 \n"

"loc_FFA522FC:\n"
"    LDR     R0, [R5, #0x1C] \n"
"    BLX     R0 \n"

"loc_FFA52304:\n"
"    LDR     R1, [R5, #0x18] \n"
"    CMP     R1, #0 \n"
"    LDRNE   R0, [R4, #0x14] \n"
"    BLXNE   R1 \n"
"    ADD     SP, SP, #0x38 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}
