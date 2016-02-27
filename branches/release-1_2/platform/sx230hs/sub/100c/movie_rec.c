/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*************************************************************/
//** movie_record_task @ 0xFF18D7C0 - 0xFF18D938, length=95
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R6, =0xFF18C57C \n"
"    LDR     R7, =0xFF18D218 \n"
"    LDR     R4, =0x85E0 \n"
"    LDR     R9, =0x67F \n"
"    LDR     R10, =0x2710 \n"
"    MOV     R8, #1 \n"
"    MOV     R5, #0 \n"

"loc_FF18D7E0:\n"
"    LDR     R0, [R4, #0x24] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02B17C /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x2C] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF18D91C \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF18D91C \n"
"    B       loc_FF18D8BC \n"
"    B       loc_FF18D8E0 \n"
"    B       loc_FF18D8F0 \n"
"    B       loc_FF18D8F8 \n"
"    B       loc_FF18D900 \n"
"    B       loc_FF18D908 \n"
"    B       loc_FF18D8C4 \n"
"    B       loc_FF18D910 \n"
"    B       loc_FF18D8D0 \n"
"    B       loc_FF18D91C \n"
"    B       loc_FF18D918 \n"
"    B       loc_FF18D888 \n"
"    B       loc_FF18D858 \n"

"loc_FF18D858:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R5, [R4, #0x34] \n"
"    STRH    R5, [R4, #6] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF18D8A8 \n"

"loc_FF18D888:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    STR     R8, [R4, #0x44] \n"

"loc_FF18D8A8:\n"
"    LDR     R2, =0xFF18BBB8 \n"
"    LDR     R1, =0xC6A08 \n"
"    LDR     R0, =0xFF18BCCC \n"
"    BL      sub_FF0453CC \n"
"    B       loc_FF18D91C \n"

"loc_FF18D8BC:\n"
);
if (conf.ext_video_time == 1)
{
asm volatile (
"    BL      sub_FF18CE08_my \n"  // --> Patched. Old value = 0xFF18CE08.
);
}
else
{
asm volatile (
"    BL      sub_FF18CE08 \n"
);
}
asm volatile (
"    B       loc_FF18D91C \n"

"loc_FF18D8C4:\n"
"    LDR     R1, [R4, #0xF0] \n"
"    BLX     R1 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    B       loc_FF18D91C \n"

"loc_FF18D8D0:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FF306C24 \n"
"    B       loc_FF18D91C \n"

"loc_FF18D8E0:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R8, [R4, #0x34] \n"
"    B       loc_FF18D91C \n"

"loc_FF18D8F0:\n"
"    BL      sub_FF18C258 \n"
"    B       loc_FF18D91C \n"

"loc_FF18D8F8:\n"
"    BL      sub_FF18BF6C \n"
"    B       loc_FF18D91C \n"

"loc_FF18D900:\n"
"    BL      sub_FF18BD24 \n"
"    B       loc_FF18D91C \n"

"loc_FF18D908:\n"
"    BL      sub_FF18B94C \n"
"    B       loc_FF18D91C \n"

"loc_FF18D910:\n"
"    BL      sub_FF18B8CC \n"
"    B       loc_FF18D91C \n"

"loc_FF18D918:\n"
"    BL      sub_FF18DE6C \n"

"loc_FF18D91C:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFF18B630 \n"
"    STR     R5, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, R10 \n"
"    BL      sub_FF02BAF4 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FF18D7E0 \n"
);
}

/*************************************************************/
//** sub_FF18CE08_my @ 0xFF18CE08 - 0xFF18D0E8, length=185
void __attribute__((naked,noinline)) sub_FF18CE08_my() {
asm volatile (
"    STMFD   SP!, {R0-R8,LR} \n"
"    LDR     R6, =0x85E0 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R6, #0x34] \n"
"    STR     R0, [R6, #0x38] \n"
"    MOV     R0, R6 \n"
"    LDR     R0, [R0, #0x5C] \n"
"    LDRH    R1, [R6, #6] \n"
"    MOV     R3, #0x3E8 \n"
"    MUL     R0, R3, R0 \n"
"    CMP     R1, #0 \n"
"    MOV     R2, #1 \n"
"    BNE     loc_FF18CE4C \n"
"    LDR     R1, [R6, #0x90] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_FF18CE5C \n"
"    B       loc_FF18CE54 \n"

"loc_FF18CE4C:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_FF18CE5C \n"

"loc_FF18CE54:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_FF18CE68 \n"

"loc_FF18CE5C:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_FF3B61A8 \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF18CE68:\n"
"    LDR     R4, =0xC6A3C \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF18CED0 \n"
"    LDR     R0, [R6, #0x58] \n"
"    MOV     R1, #4 \n"
"    CMP     R0, #0x18 \n"
"    BEQ     loc_FF18D064 \n"
"    BGT     loc_FF18CEAC \n"
"    CMP     R0, #0xA \n"
"    CMPNE   R0, #0xF \n"
"    STREQ   R7, [R4, #0x14] \n"
"    BEQ     loc_FF18CED0 \n"
"    CMP     R0, #0x14 \n"
"    BNE     loc_FF18CEC4 \n"
"    B       loc_FF18D064 \n"

"loc_FF18CEAC:\n"
"    CMP     R0, #0x1E \n"
"    BEQ     loc_FF18D064 \n"
"    CMP     R0, #0x3C \n"
"    MOVEQ   R0, #8 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    BEQ     loc_FF18CED0 \n"

"loc_FF18CEC4:\n"
"    LDR     R1, =0x777 \n"
"    LDR     R0, =0xFF18B630 \n"
"    BL      _DebugAssert \n"

"loc_FF18CED0:\n"
"    LDR     R2, =0x85E2 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_FF08C390 \n"
"    LDR     R2, =0x85E4 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_FF08C390 \n"
"    LDR     R2, =0x8630 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_FF08C390 \n"
"    LDR     R2, =0x8634 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_FF08C390 \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x86E0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xD \n"
"    BLNE    sub_FF086824 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R5, =0x86E0 \n"
"    LDR     R8, =0xC6A24 \n"
"    CMP     R0, #2 \n"
"    CMPNE   R0, #3 \n"
"    BNE     loc_FF18CFCC \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x443FC000 \n"
"    STRNE   R0, [R5] \n"
"    BNE     loc_FF18CFCC \n"
"    LDR     R0, =0x460B8600 \n"
"    LDR     R1, =0x10959E0 \n"
"    STR     R0, [R5] \n"
"    STR     R1, [R5, #4] \n"
"    LDMIA   R8, {R1,R2} \n"
"    STR     R0, [R6, #0xA0] \n"
"    MUL     R1, R2, R1 \n"
"    MOV     R2, #0 \n"
"    MOV     R3, R1, LSL#1 \n"
"    ADD     R1, R0, R3 \n"
"    STR     R3, [R6, #0x9C] \n"
"    STR     R1, [R6, #0xA4] \n"
"    STMEA   SP, {R1-R3} \n"
"    MOV     R3, R2 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x10 \n"
"    BL      sub_FF2B0840 \n"
"    LDR     R1, [R5] \n"
"    LDR     R0, [R6, #0x9C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R5] \n"
"    LDR     R1, [R5, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R5, #4] \n"

"loc_FF18CFCC:\n"
"    LDR     R3, =0xFF18CDD4 \n"
"    LDMIA   R5, {R0,R1} \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =0xC6A3C \n"
"    SUB     R2, R3, #0x18 \n"
"    BL      sub_FF305594_my \n"  // --> Patched. Old value = 0xFF305594.
"    LDR     R3, [R6, #0xB8] \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x90] \n"
"    LDRD    R2, [R6, #0xF8] \n"
"    BL      sub_FF3059A0 \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R3, =0x8668 \n"
"    AND     R1, R0, #0xFF \n"
"    LDR     R0, [R8] \n"
"    SUB     R2, R3, #4 \n"
"    BL      sub_FF3032C0 \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xFF18CA98 \n"
"    STREQ   R0, [R6, #0xF0] \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xFF18C6DC \n"
"    STREQ   R1, [R6, #0xF0] \n"
"    LDR     R2, [R6, #0xC] \n"
"    LDR     R1, =0xFF4144D0 \n"
"    CMP     R2, #2 \n"
"    BNE     loc_FF18D06C \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R8, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FF2B6938 \n"
"    LDR     R0, =0xFF18C658 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF2B6E4C \n"
"    B       loc_FF18D0A8 \n"

"loc_FF18D064:\n"
"    STR     R1, [R4, #0x14] \n"
"    B       loc_FF18CED0 \n"

"loc_FF18D06C:\n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF18D088 \n"
"    LDR     R1, [R6, #0x98] \n"
"    MOV     R0, #5 \n"
"    BL      sub_FF2B6E60 \n"
"    BL      sub_FF2B6EF0 \n"
"    B       loc_FF18D0A8 \n"

"loc_FF18D088:\n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R8, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FF2B50D4 \n"
"    LDR     R0, =0xFF18C658 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF2B581C \n"

"loc_FF18D0A8:\n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF18D0DC \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF306AA0 \n"
"    LDR     R1, [R4, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF05D068 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF306AA0 \n"
"    LDR     R1, [R4, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF05D068 \n"

"loc_FF18D0DC:\n"
"    LDR     R0, =0xFF18C610 \n"
"    STR     R7, [R6, #0x44]! \n"
"    STR     R0, [R6, #0x94] \n"
"    LDMFD   SP!, {R0-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF305594_my @ 0xFF305594 - 0xFF305944, length=237
void __attribute__((naked,noinline)) sub_FF305594_my() {
asm volatile (
"    STMFD   SP!, {R0-R12,LR} \n"
"    MOV     R8, R0 \n"
"    LDR     R0, [R2, #0x10] \n"
"    LDR     R7, [SP, #0x38] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x32A \n"
"    LDREQ   R0, =0xFF3041A8 \n"
"    MOV     R5, #0 \n"
"    MOV     R4, R2 \n"
"    MOV     R9, R3 \n"
"    MOV     R6, R5 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R11, =0xDE88 \n"
"    LDR     R0, [R4] \n"
"    MOV     R10, #0x1E \n"
"    STR     R0, [R11, #0xD0] \n"
"    LDR     R0, [R4, #4] \n"
"    STR     R0, [R11, #0xD4] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [R11, #0xE0] \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R0, =0x7530 \n"
"    CMP     R1, #0xB \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF305680 \n"
"    B       loc_FF305634 \n"
"    B       loc_FF305624 \n"
"    B       loc_FF30565C \n"
"    B       loc_FF305670 \n"
"    B       loc_FF305680 \n"
"    B       loc_FF305680 \n"
"    B       loc_FF305680 \n"
"    B       loc_FF305680 \n"
"    B       loc_FF305654 \n"
"    B       loc_FF30564C \n"
"    B       loc_FF30563C \n"

"loc_FF305624:\n"
"    LDR     R6, =0x5DC0 \n"
"    MOV     R0, #0x18 \n"
"    STR     R6, [R11, #0x12C] \n"
"    B       loc_FF305668 \n"

"loc_FF305634:\n"
"    MOV     R6, R0 \n"
"    B       loc_FF305640 \n"

"loc_FF30563C:\n"
"    LDR     R6, =0x5DC \n"

"loc_FF305640:\n"
"    STR     R0, [R11, #0x12C] \n"
"    STR     R10, [R11, #0xD8] \n"
"    B       loc_FF30568C \n"

"loc_FF30564C:\n"
"    LDR     R6, =0xBB8 \n"
"    B       loc_FF305640 \n"

"loc_FF305654:\n"
"    LDR     R6, =0x1770 \n"
"    B       loc_FF305640 \n"

"loc_FF30565C:\n"
"    LDR     R6, =0x57600000 \n"  // --> Patched. Old value = 0x3A980. 2hrs 240fps
"    STR     R0, [R11, #0x12C] \n"
"    MOV     R0, #0xF0 \n"

"loc_FF305668:\n"
"    STR     R0, [R11, #0xD8] \n"
"    B       loc_FF30568C \n"

"loc_FF305670:\n"
"    STR     R0, [R11, #0x12C] \n"
"    LDR     R6, =0x28800000 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs 120fps
"    MOV     R0, #0x78 \n"
"    B       loc_FF305668 \n"

"loc_FF305680:\n"
"    LDR     R1, =0x35B \n"
"    LDR     R0, =0xFF3041A8 \n"
"    BL      _DebugAssert \n"

"loc_FF30568C:\n"
"    LDR     R0, [R11, #0xD8] \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0xE0F. 2hrs
"    MOV     R0, R0, LSR#1 \n"
"    STR     R0, [R11, #0xDC] \n"
"    LDR     R0, [R9] \n"
"    STR     R0, [R11, #0xE4] \n"
"    LDRH    R0, [R9, #0x10] \n"
"    STR     R0, [R11, #0xE8] \n"
"    LDR     R0, [R9, #4] \n"
"    STRH    R0, [R11, #2] \n"
"    LDR     R0, [R9, #8] \n"
"    STRH    R0, [R11, #4] \n"
"    LDR     R0, [R9, #0x14] \n"
"    STR     R0, [R11, #0xEC] \n"
"    STR     R7, [R11, #0x128] \n"
"    LDR     R0, [R11, #0xD0] \n"
"    CMP     R0, #0x140 \n"
"    MOVEQ   R0, #0x20000 \n"
"    MOVEQ   R5, #1 \n"
"    STREQ   R0, [R11, #0xAC] \n"
"    BEQ     loc_FF305720 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R5, #2 \n"
"    STREQ   R0, [R11, #0xAC] \n"
"    BEQ     loc_FF305720 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x707. 2hrs
"    MOVEQ   R5, #4 \n"
"    STREQ   R0, [R11, #0xAC] \n"
"    BEQ     loc_FF305720 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_FF305728 \n"
//"  MOV     R0, #0x200000 \n"
"    MOV     R0, #2097152 \n" // 10 mins
"    MOV     R5, #5 \n"
"    STR     R0, [R11, #0xAC] \n"

"loc_FF305720:\n"
"    STR     R1, [R11, #0x4C] \n"
"    B       loc_FF305734 \n"

"loc_FF305728:\n"
"    LDR     R1, =0x383 \n"
"    LDR     R0, =0xFF3041A8 \n"
"    BL      _DebugAssert \n"

"loc_FF305734:\n"
"    LDR     R0, [R11, #0x4C] \n"
"    LDR     R1, =0x138D \n"
"    MUL     R0, R6, R0 \n"
"    BL      sub_FF3B61A8 \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"
"    STR     R0, [R11, #0x48] \n"
"    LDR     R7, [R4, #8] \n"
"    CMP     R7, #2 \n"
"    CMPNE   R7, #3 \n"
"    BNE     loc_FF30578C \n"
"    RSB     R0, R6, R6, LSL#4 \n"
"    LDR     R1, =0x3E9 \n"
"    MOV     R0, R0, LSL#1 \n"
"    STR     R10, [R11, #0x4C] \n"
"    BL      sub_FF3B61A8 \n"
"    LDR     R1, [R11, #0xE0] \n"
"    MOV     R6, R1 \n"
"    BL      sub_FF3B61A8 \n"
"    ADD     R0, R0, #1 \n"
"    MUL     R0, R6, R0 \n"
"    STR     R0, [R11, #0x48] \n"

"loc_FF30578C:\n"
"    LDR     R0, [R4, #0xC] \n"
"    LDR     R6, [R9, #0xC] \n"
"    MOVS    R1, R0 \n"
"    MOV     R0, R6, LSR#1 \n"
"    STR     R6, [R11, #0x94] \n"
"    STR     R0, [R11, #0x98] \n"
"    ADD     R0, R8, #3 \n"
"    BIC     R0, R0, #3 \n"
"    STR     R0, [R11, #0xF4] \n"
"    LDR     R2, [R11, #0x48] \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R2, LSL#2 \n"
"    ADD     R3, R0, R2 \n"
"    STR     R3, [R11, #0xF8] \n"
"    LDRH    R12, [R11, #4] \n"
"    LDR     R0, [SP, #4] \n"
"    ADD     R2, R2, R3 \n"
"    CMP     R12, #0 \n"
"    ADD     R0, R0, R8 \n"
"    BEQ     loc_FF305904 \n"
"    STR     R2, [R11, #0xFC] \n"
"    LDR     R3, [R11, #0x4C] \n"
"    LDR     R8, =0x11D628 \n"
"    ADD     R2, R2, R3, LSL#3 \n"
"    ADD     R2, R2, #0x1F \n"
"    BIC     R2, R2, #0x1F \n"
"    STR     R2, [R11, #0x100] \n"
"    LDR     R3, [R11, #0xAC] \n"
"    LDR     R10, =0xE008 \n"
"    ADD     R2, R2, R3 \n"
"    ADD     R3, R2, #0x100000 \n"
"    STR     R2, [R11, #0x78] \n"
"    SUB     R0, R0, R3 \n"
"    RSB     R2, R6, #0 \n"
"    ADD     R0, R0, R2, LSL#1 \n"
"    MOV     R0, R0, LSR#15 \n"
"    MOV     R0, R0, LSL#15 \n"
"    STR     R3, [R11, #0x104] \n"
"    ADD     R7, R3, R0 \n"
"    STR     R0, [R11, #0x110] \n"
"    STR     R7, [R11, #0x108] \n"
"    MOV     R2, #0 \n"
"    ADD     R9, R8, #0x10 \n"
"    STR     R7, [R11, #0x10C] \n"

"loc_FF30583C:\n"
"    MLA     R0, R2, R6, R7 \n"
"    ADD     R12, R8, R2, LSL#3 \n"
"    ADD     R0, R0, #3 \n"
"    BIC     R0, R0, #3 \n"
"    STR     R0, [R10, R2, LSL#2] \n"
"    MOV     R0, #0 \n"
"    ADD     LR, R9, R2, LSL#3 \n"

"loc_FF305858:\n"
"    STR     R3, [R12, R0, LSL#2] \n"
"    STR     R3, [LR, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #2 \n"
"    BLT     loc_FF305858 \n"
"    ADD     R2, R2, #1 \n"
"    CMP     R2, #2 \n"
"    BLT     loc_FF30583C \n"
"    LDRH    R3, [R4, #0x14] \n"
"    LDR     R2, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF0DA84C \n"
"    LDR     R1, [R11, #0x94] \n"
"    ADD     R0, R0, R1 \n"

"loc_FF305890:\n"
"    STR     R0, [R11, #0x8C] \n"
"    LDMFD   SP!, {R0-R12,PC} \n"

"loc_FF305904:\n"
"    ADD     R2, R2, #0x1F \n"
"    BIC     R2, R2, #0x1F \n"
"    STR     R2, [R11, #0x100] \n"
"    LDR     R3, [R11, #0xAC] \n"
"    ADD     R2, R2, R3 \n"
"    SUB     R0, R0, R2 \n"
"    MOV     R0, R0, LSR#15 \n"
"    MOV     R0, R0, LSL#15 \n"
"    STR     R2, [R11, #0x104] \n"
"    STR     R0, [R11, #0x110] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R11, #0x108] \n"
"    LDRH    R3, [R4, #0x14] \n"
"    MOV     R2, R7 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF0DA84C \n"
"    B       loc_FF305890 \n"
);
}