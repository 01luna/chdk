/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFFC488A4 - 0xFFC48B28, length=162
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R6, =0x52D0 \n"

"loc_FFC488AC:\n"
"    LDR     R0, [R6, #8] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_FFC1763C /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFC488D8 \n"
"    LDR     R1, =0x48E \n"
"    LDR     R0, =0xFFC485CC /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FFC488D8:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x19 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFC48AEC \n"
"    B       loc_FFC48954 \n"
"    B       loc_FFC4895C \n"
"    B       loc_FFC489DC \n"
"    B       loc_FFC489F0 \n"
"    B       loc_FFC489E8 \n"
"    B       loc_FFC489F8 \n"
"    B       loc_FFC48A00 \n"
"    B       loc_FFC48A0C \n"
"    B       loc_FFC48A64 \n"
"    B       loc_FFC489F0 \n"
"    B       loc_FFC48A6C \n"
"    B       loc_FFC48A74 \n"
"    B       loc_FFC48A7C \n"
"    B       loc_FFC48A84 \n"
"    B       loc_FFC48A8C \n"
"    B       loc_FFC48A98 \n"
"    B       loc_FFC48AA0 \n"
"    B       loc_FFC48AA8 \n"
"    B       loc_FFC48AB0 \n"
"    B       loc_FFC48ABC \n"
"    B       loc_FFC48AC4 \n"
"    B       loc_FFC48ACC \n"
"    B       loc_FFC48AD4 \n"
"    B       loc_FFC48ADC \n"
"    B       loc_FFC48AE4 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48954:\n"
"    BL      sub_FFD0B650 \n"
"    BL      shooting_expo_param_override\n"      // added
"    B       loc_FFC48A04 \n"

"loc_FFC4895C:\n"
"    LDR     R4, [R0, #0xC] \n"
"    LDR     R0, [R4, #8] \n"
"    ORR     R0, R0, #1 \n"
"    STR     R0, [R4, #8] \n"
"    BL      sub_FFD0B640 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFD0BA28 \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, R4 \n"
"    MOVNE   R1, #1 \n"
"    BNE     loc_FFC48A5C \n"
"    BL      sub_FFD2A204 \n"
"    BL      sub_FFC57098 \n"
"    STR     R0, [R4, #0x14] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFD0CA20 \n"
"    BL      sub_FFD0D484 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFD0CAE8_my \n"  // --> Patched. Old value = 0xFFD0CAE8.
"    BL      capt_seq_hook_raw_here \n"         // added
"    MOV     R5, R0 \n"
"    BL      sub_FFD0E464 \n"
"    BL      sub_FFD0E4A0 \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFC47080 \n"
"    BL      sub_FFD0CE98 \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #8] \n"
"    ORRNE   R0, R0, #0x2000 \n"
"    STRNE   R0, [R4, #8] \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC489DC:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FFD0B7E4 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC489E8:\n"
"    BL      sub_FFD0B2B0 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC489F0:\n"
"    BL      sub_FFD0B630 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC489F8:\n"
"    BL      sub_FFD0B638 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48A00:\n"
"    BL      sub_FFD0B704 \n"

"loc_FFC48A04:\n"
"    BL      sub_FFC46D00 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48A0C:\n"
"    LDR     R4, [R0, #0xC] \n"
"    BL      sub_FFD0B640 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFD0BDA8 \n"
"    TST     R0, #1 \n"
"    MOV     R5, R0 \n"
"    BNE     loc_FFC48A4C \n"
"    BL      sub_FFC57098 \n"
"    STR     R0, [R4, #0x14] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFD0CA20 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFD0CEF8 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4, #0x14] \n"
"    BL      sub_FFC572A4 \n"

"loc_FFC48A4C:\n"
"    BL      sub_FFD0B630 \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #9 \n"
"    MOV     R0, R5 \n"

"loc_FFC48A5C:\n"
"    BL      sub_FFC47080 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48A64:\n"
"    BL      sub_FFD0B764 \n"
"    B       loc_FFC48A04 \n"

"loc_FFC48A6C:\n"
"    BL      sub_FFD0C024 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48A74:\n"
"    BL      sub_FFD0C20C \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48A7C:\n"
"    BL      sub_FFD0C29C \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48A84:\n"
"    BL      sub_FFD0C350 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48A8C:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FFD0C4F4 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48A98:\n"
"    BL      sub_FFD0C644 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48AA0:\n"
"    BL      sub_FFD0C6D8 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48AA8:\n"
"    BL      sub_FFD0C7A0 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48AB0:\n"
"    BL      sub_FFD0B900 \n"
"    BL      sub_FFC149A0 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48ABC:\n"
"    BL      sub_FFD0C40C \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48AC4:\n"
"    BL      sub_FFD0C450 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48ACC:\n"
"    BL      sub_FFD0E448 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48AD4:\n"
"    BL      sub_FFD0E464 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48ADC:\n"
"    BL      sub_FFD0E474 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48AE4:\n"
"    BL      sub_FFD0E4A0 \n"
"    B       loc_FFC48AF8 \n"

"loc_FFC48AEC:\n"
"    LDR     R1, =0x58E \n"
"    LDR     R0, =0xFFC485CC /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FFC48AF8:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R6, #4] \n"
"    BL      sub_FFC173B8 /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x10D \n"
"    LDREQ   R0, =0xFFC485CC /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R4, #8] \n"
"    B       loc_FFC488AC \n"
);
}

/*************************************************************/
//** sub_FFD0CAE8_my @ 0xFFD0CAE8 - 0xFFD0CB58, length=29
void __attribute__((naked,noinline)) sub_FFD0CAE8_my() {
asm volatile (
"    STMFD   SP!, {R0-R10,LR} \n"
"    MOV     R6, #0 \n"
"    MOV     R4, R0 \n"
"    BL      sub_FFD0D5E8 \n"
"    MVN     R1, #0 \n"
"    BL      sub_FFC173EC /*_ClearEventFlag*/ \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R0, #0x8A \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0x218 \n"
"    LDRNE   R0, =0xFFD0CCFC /*'SsCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R8, =0x1973C \n"
"    LDR     R5, =0x19690 \n"
"    LDRSH   R1, [R8, #0xE] \n"
"    LDR     R0, [R5, #0x74] \n"
//"  BL      _sub_FFCCB1F0 \n"  // --> Nullsub call removed.
"    BL      _GetCCDTemperature \n"
"    LDR     R2, =0x888C \n"
"    ADD     R3, R4, #0x8C \n"
"    STRH    R0, [R4, #0x88] \n"
"    STRD    R2, [SP] \n"
"    MOV     R1, R0 \n"
"    LDRH    R0, [R5, #0x4C] \n"
"    LDRSH   R2, [R8, #0xC] \n"
"    LDR     R3, =0x8888 \n"
"    BL      sub_FFD0DAD4 \n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDR     PC, =0xFFD0CB5C \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFFC900B8 - 0xFFC906A8, length=381
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x20 \n"
"    LDR     R8, =0xBB8 \n"
"    LDR     R7, =0x64D4 \n"
"    LDR     R5, =0x3D3DC \n"
"    MOV     R0, #0 \n"
"    ADD     R6, SP, #0x10 \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FFC900D8:\n"
"    LDR     R0, [R7, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FFC1763C /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFC90120 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    BEQ     loc_FFC9023C \n"
"    CMP     R0, #0x27 \n"
"    BEQ     loc_FFC90214 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FFC90068 \n"

"loc_FFC90120:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2C \n"
"    BNE     loc_FFC90150 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FFC9131C \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FFC173B8 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x20 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FFC90150:\n"
"    CMP     R1, #0x2B \n"
"    BNE     loc_FFC9016C \n"
"    LDR     R2, [R0, #0x88]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FFC906A0 \n"

"loc_FFC9016C:\n"
"    CMP     R1, #0x25 \n"
"    BNE     loc_FFC901BC \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FFC173EC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFFC8CB5C \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FFD02FE0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FFC172F0 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0xD1B \n"
"    BNE     loc_FFC90200 \n"

"loc_FFC901A8:\n"
"    LDR     R1, [SP, #0x1C] \n"
"    LDR     R0, [R1, #0x8C] \n"
"    LDR     R1, [R1, #0x88] \n"
"    BLX     R1 \n"
"    B       loc_FFC906A0 \n"

"loc_FFC901BC:\n"
"    CMP     R1, #0x26 \n"
"    BNE     loc_FFC9020C \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FFC90068 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FFC173EC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFFC8CB6C \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FFD03268 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FFC172F0 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFC901A8 \n"
"    LDR     R1, =0xD25 \n"

"loc_FFC90200:\n"
"    LDR     R0, =0xFFC8D25C /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FFC901A8 \n"

"loc_FFC9020C:\n"
"    CMP     R1, #0x27 \n"
"    BNE     loc_FFC90224 \n"

"loc_FFC90214:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FFC90068 \n"
"    B       loc_FFC901A8 \n"

"loc_FFC90224:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FFC9023C \n"
"    BL      sub_FFC6FF10 \n"
"    BL      sub_FFC70CDC \n"
"    BL      sub_FFC70760 \n"
"    B       loc_FFC901A8 \n"

"loc_FFC9023C:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R4, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x11 \n"
"    CMPNE   R1, #0x12 \n"
"    BNE     loc_FFC902AC \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FFC8EBE8 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FFC916F4 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x90] \n"
"    LDR     R2, [R0, #0x94] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    B       loc_FFC905E0 \n"

"loc_FFC902AC:\n"
"    CMP     R1, #0x13 \n"
"    CMPNE   R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    BNE     loc_FFC90360 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFC8EE30 \n"
"    CMP     R0, #1 \n"
"    MOV     R4, R0 \n"
"    CMPNE   R4, #5 \n"
"    BNE     loc_FFC902FC \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, R4 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0xC]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FFC90334 \n"

"loc_FFC902FC:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    CMP     R4, #2 \n"
"    LDR     R3, [R0, #0x8C] \n"
"    CMPNE   R4, #6 \n"
"    BNE     loc_FFC90348 \n"
"    LDR     R12, [R0, #0x88] \n"
"    MOV     R0, SP \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFC8FDB4 \n"

"loc_FFC90334:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R4 \n"
"    BL      sub_FFC90008 \n"
"    B       loc_FFC905E0 \n"

"loc_FFC90348:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x88] \n"
"    ADD     R0, R0, #4 \n"
"    MOV     R2, R4 \n"
"    BLX     R12 \n"
"    B       loc_FFC905E0 \n"

"loc_FFC90360:\n"
"    CMP     R1, #0x21 \n"
"    CMPNE   R1, #0x22 \n"
"    BNE     loc_FFC903AC \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FFC8E174 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FFC8E464 \n"
"    B       loc_FFC905E0 \n"

"loc_FFC903AC:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R12} \n"
"    STMIA   R6, {R2,R3,R12} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x24 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFC905C0 \n"
"    B       loc_FFC9045C \n"
"    B       loc_FFC9045C \n"
"    B       loc_FFC90464 \n"
"    B       loc_FFC9046C \n"
"    B       loc_FFC9046C \n"
"    B       loc_FFC9046C \n"
"    B       loc_FFC9045C \n"
"    B       loc_FFC90464 \n"
"    B       loc_FFC9046C \n"
"    B       loc_FFC9046C \n"
"    B       loc_FFC904C8 \n"
"    B       loc_FFC904C8 \n"
"    B       loc_FFC905B4 \n"
"    B       loc_FFC905BC \n"
"    B       loc_FFC905BC \n"
"    B       loc_FFC905BC \n"
"    B       loc_FFC905BC \n"
"    B       loc_FFC905C0 \n"
"    B       loc_FFC905C0 \n"
"    B       loc_FFC905C0 \n"
"    B       loc_FFC905C0 \n"
"    B       loc_FFC905C0 \n"
"    B       loc_FFC90474 \n"
"    B       loc_FFC9047C \n"
"    B       loc_FFC9047C \n"
"    B       loc_FFC904D4 \n"
"    B       loc_FFC904D4 \n"
"    B       loc_FFC904DC \n"
"    B       loc_FFC9050C \n"
"    B       loc_FFC9053C \n"
"    B       loc_FFC9056C \n"
"    B       loc_FFC9059C \n"
"    B       loc_FFC9059C \n"
"    B       loc_FFC905C0 \n"
"    B       loc_FFC905C0 \n"
"    B       loc_FFC905A4 \n"
"    B       loc_FFC905AC \n"

"loc_FFC9045C:\n"
"    BL      sub_FFC8D044 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC90464:\n"
"    BL      sub_FFC8D2D4 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC9046C:\n"
"    BL      sub_FFC8D4D8 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC90474:\n"
"    BL      sub_FFC8D740 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC9047C:\n"
"    BL      sub_FFC8D934 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC904C8:\n"
"    BL      sub_FFC8DB9C_my \n"  // --> Patched. Old value = 0xFFC8DB9C.
"    MOV     R4, #0 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC904D4:\n"
"    BL      sub_FFC8DCD8 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC904DC:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R1, [R5, #2] \n"
"    STRH    R1, [SP, #0x12] \n"
"    LDRH    R1, [R5, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R5, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x18] \n"
"    BL      sub_FFC91390 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC9050C:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R1, [R5, #2] \n"
"    STRH    R1, [SP, #0x12] \n"
"    LDRH    R1, [R5, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R5, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R5, #8] \n"
"    STRH    R1, [SP, #0x18] \n"
"    BL      sub_FFC91510 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC9053C:\n"
"    LDRH    R1, [R5] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x12] \n"
"    LDRH    R1, [R5, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R5, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R5, #8] \n"
"    STRH    R1, [SP, #0x18] \n"
"    BL      sub_FFC915BC \n"
"    B       loc_FFC905C0 \n"

"loc_FFC9056C:\n"
"    LDRH    R1, [R5] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R1, [R5, #2] \n"
"    STRH    R1, [SP, #0x12] \n"
"    LDRH    R1, [R5, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R5, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x18] \n"
"    BL      sub_FFC9165C \n"
"    B       loc_FFC905C0 \n"

"loc_FFC9059C:\n"
"    BL      sub_FFC8DF4C \n"
"    B       loc_FFC905C0 \n"

"loc_FFC905A4:\n"
"    BL      sub_FFC8E568 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC905AC:\n"
"    BL      sub_FFC8E7A0 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC905B4:\n"
"    BL      sub_FFC8E918 \n"
"    B       loc_FFC905C0 \n"

"loc_FFC905BC:\n"
"    BL      sub_FFC8EAB0 \n"

"loc_FFC905C0:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    CMP     R4, #1 \n"
"    BNE     loc_FFC90628 \n"

"loc_FFC905E0:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, #0xC \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R4, R0, #8 \n"
"    LDR     R0, =0x3D3DC \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFE4E008 \n"
"    LDR     R0, =0x3D3E8 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFE4E008 \n"
"    LDR     R0, =0x3D3F4 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R4 \n"
"    BL      sub_FFE4E008 \n"
"    B       loc_FFC906A0 \n"

"loc_FFC90628:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FFC90670 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FFC8CE4C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    B       loc_FFC9069C \n"

"loc_FFC90670:\n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"
"    BL      sub_FFC8CE4C \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"

"loc_FFC9069C:\n"
"    BL      sub_FFC8CF8C \n"

"loc_FFC906A0:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FFC9131C \n"
"    B       loc_FFC900D8 \n"
);
}

/*************************************************************/
//** sub_FFC8DB9C_my @ 0xFFC8DB9C - 0xFFC8DC58, length=48
void __attribute__((naked,noinline)) sub_FFC8DB9C_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x64D4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_FFC173EC /*_ClearEventFlag*/ \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FFC8CBE0 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FFC8CCEC \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FFC8CD44 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FFC8CD9C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    BL      sub_FFC8CDF4 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x3D3F4 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, #0 \n"
"    BEQ     loc_FFC8DC2C \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FFC8DC2C \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFFC8CB4C \n"
"    MOV     R2, #2 \n"
"    BL      sub_FFD03134 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FFC8DC34 \n"

"loc_FFC8DC2C:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FFC8DC34:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FFC8DC50 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R2, #0x20 \n"
"    LDR     R1, =0xFFC8CBD0 \n"
"    BL      sub_FFC9134C \n"

"loc_FFC8DC50:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FFC6FC5C_my \n"  // --> Patched. Old value = 0xFFC6FC5C.
"    LDR     PC, =0xFFC8DC5C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFC6FC5C_my @ 0xFFC6FC5C - 0xFFC6FCC4, length=27
void __attribute__((naked,noinline)) sub_FFC6FC5C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x5FAC \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0x16D \n"
"    LDRNE   R0, =0xFFC6F9F4 /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x173 \n"
"    LDREQ   R0, =0xFFC6F9F4 /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_FFC9E864 \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FFCA25DC \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,LR} \n"
"    MOVNE   R1, #0x178 \n"
"    LDRNE   R0, =0xFFC6F9F4 /*'Shutter.c'*/ \n"
"    BNE     _DebugAssert \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}
