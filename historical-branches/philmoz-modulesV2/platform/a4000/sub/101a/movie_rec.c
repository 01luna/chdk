#include "conf.h"

void change_video_tables(int a, int b){}

void  set_quality(int *x){ // -17 highest; +12 lowest
    if (conf.video_mode) 
        *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

//** movie_record_task  @ 0xFF95ED68 

void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
      "STMFD   SP!, {R2-R10,LR} \n"
      "LDR     R6, =0xFF95E200 \n"
      "LDR     R7, =0xFF95E72C \n" //This function was used to take values for set_quality -->
      "LDR     R4, =0x63E0 \n"
      "LDR     R9, =0x69B \n"
      "LDR     R10, =0x2710 \n"
      "MOV     R8, #1 \n"
      "MOV     R5, #0 \n"
"loc_FF95ED88:\n"
      "LDR     R0, [R4, #0x24] \n"
      "MOV     R2, #0 \n"
      "ADD     R1, SP, #4 \n"
      "BL      sub_003F7218 \n"
      "LDR     R0, [R4, #0x2C] \n"
      "CMP     R0, #0 \n"
      "LDRNE   R0, [R4, #0xC] \n"
      "CMPNE   R0, #2 \n"
      "LDRNE   R0, [R4, #0x44] \n"
      "CMPNE   R0, #6 \n"
      "BNE     loc_FF95EEAC \n"
      "LDR     R0, [SP, #4] \n"
      "LDR     R1, [R0] \n"
      "SUB     R1, R1, #2 \n"
      "CMP     R1, #0xB \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF95EEAC \n"
      "B       loc_FF95EE5C \n" //(01)
      "B       loc_FF95EE80 \n" //(02)
      "B       loc_FF95EE90 \n" //(03)
      "B       loc_FF95EE98 \n" //(04)
      "B       loc_FF95EE64 \n" //(05)
      "B       loc_FF95EEA0 \n" //(06)
      "B       loc_FF95EE70 \n" //(07)
      "B       loc_FF95EEAC \n" //(08)
      "B       loc_FF95EEA8 \n" //(09)
      "B       loc_FF95EE28 \n" //(10)
      "B       loc_FF95EDF8 \n" //(11)
"loc_FF95EDF8:\n" //Jump Table entry 11
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R5, [R4, #0x34] \n"
      "STRH    R5, [R4, #6] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xD0] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "MOV     R0, #6 \n"
      "STR     R0, [R4, #0x44] \n"
      "B       loc_FF95EE48 \n"
"loc_FF95EE28:\n" //Jump Table entry 10
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xD0] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "STR     R8, [R4, #0x44] \n"
"loc_FF95EE48:\n"
      "LDR     R2, =0xFF95D960 \n"
      "LDR     R1, =0xAAE5C \n"
      "LDR     R0, =0xFF95DA74 \n"
      "BL      sub_FF84AECC \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE5C:\n" //Jump Table entry 01
      "BL      unlock_optical_zoom \n" //added
      "BL      sub_FF95E360 \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE64:\n" //Jump Table entry 05
      "LDR     R1, [R4, #0xD0] \n"
      "BLX     R1 \n"
//begin patch
      "LDR	   R0, =0x6464 \n"		// added, 0x6468-0x4 taken from  ""loc_FF95EC50:" see commented function below.
      "BL      set_quality \n"		// added
//end patch
      "B       loc_FF95EEAC \n"
"loc_FF95EE70:\n"  //Jump Table entry 07
      "LDR     R1, [R0, #0x18] \n"
      "LDR     R0, [R0, #4] \n"
      "BL      sub_FFA6CD34 \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE80:\n"  //Jump Table entry 02
      "LDR     R0, [R4, #0x44] \n"
      "CMP     R0, #5 \n"
      "STRNE   R8, [R4, #0x34] \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE90:\n"  //Jump Table entry 03
      "BL      sub_FF95DE60 \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE98:\n"  //Jump Table entry 04
      "BL      sub_FF95DAC0 \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EEA0:\n"  //Jump Table entry 06
      "BL      sub_FF95D8EC \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EEA8:\n"  //Jump Table entry 09
      "BL      sub_FF95F384 \n"
"loc_FF95EEAC:\n"
      "LDR     R1, [SP, #4] \n"
      "LDR     R3, =0xFF95D64C \n"
      "STR     R5, [R1] \n"
      "STR     R9, [SP] \n"
      "LDR     R0, [R4, #0x28] \n"
      "MOV     R2, R10 \n"
      "BL      sub_003F7B90 \n"
      "B       loc_FF95ED88 \n"
	);
}

//This function was used to take values for set_quality
//** sub_FF95E72C_my  @ 0xFF95E72C 
/*
void __attribute__((naked,noinline)) sub_FF95E72C_my() {
asm volatile (
      "STMFD   SP!, {R4-R11,LR} \n"
      "SUB     SP, SP, #0x64 \n"
      "MOV     R9, #0 \n"
      "LDR     R6, =0x63E0 \n"
      "STR     R9, [SP, #0x54] \n"
      "STR     R9, [SP, #0x4C] \n"
      "STR     R9, [R6, #0xB8] \n"
      "STR     R9, [R6, #0xBC] \n"
      "STR     R9, [R6, #0xC0] \n"
      "STR     R9, [R6, #0xC4] \n"
      "MOV     R4, R0 \n"
      "STR     R9, [R6, #0xC8] \n"
      "LDR     R0, [R6, #0x44] \n"
      "MOV     R11, #4 \n"
      "CMP     R0, #3 \n"
      "STREQ   R11, [R6, #0x44] \n"
      "LDR     R0, [R6, #0xB4] \n"
      "MOV     R8, R9 \n"
      "MOV     R5, #1 \n"
      "MOV     R7, R9 \n"
      "BLX     R0 \n"
      "LDR     R0, [R6, #0x44] \n"
      "CMP     R0, #6 \n"
      "BEQ     loc_FF95E7A0 \n"
      "LDR     R1, [R6, #0xC] \n"
      "CMP     R1, #2 \n"
      "BNE     loc_FF95E7C8 \n"
      "CMP     R0, #5 \n"
      "BEQ     loc_FF95E7D8 \n"
"loc_FF95E7A0:\n"
      "LDR     R2, =0xFF95E600 \n"
      "LDR     R1, =0xFF95E664 \n"
      "LDR     R0, =0xFF95E6C8 \n"
      "MOV     R7, #1 \n"
      "ADD     R3, SP, #0x30 \n"
      "BL      sub_FF84BA14 \n"
      "LDR     R0, [R6, #0x44] \n"
      "CMP     R0, #4 \n"
      "MOVNE   R5, #0 \n"
      "B       loc_FF95E7E8 \n"
"loc_FF95E7C8:\n"
      "CMP     R0, #4 \n"
      "BEQ     loc_FF95E7E8 \n"
      "CMP     R1, #2 \n"
      "BNE     loc_FF95E7E0 \n"
"loc_FF95E7D8:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF84BA80 \n"
"loc_FF95E7E0:\n"
      "ADD     SP, SP, #0x64 \n"
      "LDMFD   SP!, {R4-R11,PC} \n"
"loc_FF95E7E8:\n"
      "LDRH    R0, [R6, #6] \n"
      "CMP     R0, #3 \n"
      "BNE     loc_FF95E81C \n"
      "LDR     R0, [R6, #0xCC] \n"
      "CMP     R0, #0 \n"
      "LDREQ   R1, =0x8E8 \n"
      "LDREQ   R0, =0xFF95D64C \n"
      "BLEQ    _DebugAssert \n"
      "LDR     R0, [R6, #0x6C] \n"
      "LDR     R1, [R6, #0xCC] \n"
      "BL      sub_003FC934 \n"
      "CMP     R1, #0 \n"
      "MOVNE   R5, #0 \n"
"loc_FF95E81C:\n"
      "LDR     R0, [R6, #0x44] \n"
      "CMP     R0, #6 \n"
      "CMPNE   R0, #1 \n"
      "CMPNE   R0, #3 \n"
      "BNE     loc_FF95E860 \n"
      "CMP     R7, #1 \n"
      "CMPEQ   R5, #0 \n"
      "BNE     loc_FF95E860 \n"
      "BL      sub_FF84BA38 \n"
      "LDR     R0, [R6, #0x18] \n"
      "MOV     R1, #0x3E8 \n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9 \n"
      "BNE     loc_FF95ECCC \n"
      "MOV     R0, #0x90000 \n"
      "BL      sub_FF835FA4 \n"
      "B       loc_FF95E7E0 \n"
"loc_FF95E860:\n"
      "CMP     R5, #1 \n"
      "MOV     R10, #1 \n"
      "BNE     loc_FF95E888 \n"
      "ADD     R3, SP, #0x4C \n"
      "ADD     R2, SP, #0x50 \n"
      "ADD     R1, SP, #0x54 \n"
      "ADD     R0, SP, #0x58 \n"
      "BL      sub_FFA6CE0C \n"
      "MOVS    R9, R0 \n"
      "BNE     loc_FF95E8A4 \n"
"loc_FF95E888:\n"
      "LDR     R0, [R6, #0x34] \n"
      "CMP     R0, #1 \n"
      "BNE     loc_FF95EA20 \n"
      "LDR     R0, [R6, #0x6C] \n"
      "LDR     R1, [R6, #0x48] \n"
      "CMP     R0, R1 \n"
      "BCC     loc_FF95EA20 \n"
"loc_FF95E8A4:\n"
      "CMP     R9, #0x80000001 \n"
      "STREQ   R11, [R6, #0x70] \n"
      "BEQ     loc_FF95E8DC \n"
      "CMP     R9, #0x80000003 \n"
      "STREQ   R10, [R6, #0x70] \n"
      "BEQ     loc_FF95E8DC \n"
      "CMP     R9, #0x80000005 \n"
      "MOVEQ   R0, #2 \n"
      "BEQ     loc_FF95E8D8 \n"
      "CMP     R9, #0x80000007 \n"
      "STRNE   R8, [R6, #0x70] \n"
      "BNE     loc_FF95E8DC \n"
      "MOV     R0, #3 \n"
"loc_FF95E8D8:\n"
      "STR     R0, [R6, #0x70] \n"
"loc_FF95E8DC:\n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "BNE     loc_FF95E940 \n"
      "LDR     R0, =0xFF95E5F4 \n"
      "MOV     R1, #0 \n"
      "BL      sub_FFA38624 \n"
      "LDR     R1, [R6, #0x64] \n"
      "LDR     R2, =0xAAEA8 \n"
      "ADD     R3, SP, #0x5C \n"
      "ADD     R0, SP, #0x30 \n"
      "STRD    R0, [SP, #0x10] \n"
      "STRD    R2, [SP, #0x18] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "MVN     R3, #1 \n"
      "ADD     R0, SP, #0x60 \n"
      "STMEA   SP, {R0-R3} \n"
      "MOV     R3, #0 \n"
      "LDR     R0, =0xAAF08 \n"
      "MOV     R2, R3 \n"
      "MOV     R1, #0x40 \n"
      "BL      sub_FFA38578 \n"
      "B       loc_FF95E998 \n"
"loc_FF95E938:\n"
      "MOV     R1, #1 \n"
      "B       loc_FF95EC10 \n"
"loc_FF95E940:\n"
      "BL      sub_FF95F454 \n"
      "LDR     R2, [R6, #0x64] \n"
      "ADD     R3, SP, #0x5C \n"
      "MVN     R1, #1 \n"
      "MOV     R0, #0 \n"
      "ADD     R5, SP, #0x1C \n"
      "STMIA   R5, {R0-R3} \n"
      "LDR     R3, [R4, #0x1C] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "ADD     R0, SP, #0x60 \n"
      "ADD     R4, SP, #0xC \n"
      "STMIA   R4, {R0-R3} \n"
      "MOV     R3, #0 \n"
      "MOV     R1, #0x40 \n"
      "STMEA   SP, {R1,R3} \n"
      "MOV     R2, #0 \n"
      "STR     R3, [SP, #8] \n"
      "LDR     R3, =0xAAF08 \n"
      "MOV     R1, R2 \n"
      "MOV     R0, R2 \n"
      "BL      sub_FFA37268 \n"
"loc_FF95E998:\n"
      "LDR     R0, [R6, #0x18] \n"
      "LDR     R1, [R6, #0x60] \n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9 \n"
      "BEQ     loc_FF95E938 \n"
      "LDR     R0, [SP, #0x5C] \n"
      "CMP     R0, #0 \n"
      "BEQ     loc_FF95E9C0 \n"
"loc_FF95E9B8:\n"
      "MOV     R1, #1 \n"
      "B       loc_FF95EC28 \n"
"loc_FF95E9C0:\n"
      "LDR     R0, [R6, #0xC] \n"
      "MOV     R4, #5 \n"
      "CMP     R0, #2 \n"
      "MOV     R0, #1 \n"
      "BNE     loc_FF95EA0C \n"
      "BL      sub_FFA385EC \n"
      "BL      sub_FFA38608 \n"
      "BL      sub_FF84BA5C \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF84BA80 \n"
      "BL      sub_FF84BAB0 \n"
      "STR     R4, [R6, #0x44] \n"
      "LDR     R0, [R6, #0x64] \n"
      "CMP     R0, #1 \n"
      "BLEQ    sub_FFA38648 \n"
      "BL      sub_FF95F454 \n"
      "BL      sub_FF84BB0C \n"
      "STR     R10, [R6, #0x44] \n"
      "B       loc_FF95EA18 \n"
"loc_FF95EA0C:\n"
      "BL      sub_FFA37314 \n"
      "BL      sub_FFA3735C \n"
      "STR     R4, [R6, #0x44] \n"
"loc_FF95EA18:\n"
      "STR     R8, [R6, #0x34] \n"
      "B       loc_FF95E7E0 \n"
"loc_FF95EA20:\n"
      "CMP     R5, #1 \n"
      "BNE     loc_FF95ECC4 \n"
      "STR     R10, [R6, #0x38] \n"
      "LDR     R0, [R6, #0x6C] \n"
      "LDR     R11, [R4, #0xC] \n"
      "CMP     R0, #0 \n"
      "LDRNE   R9, [SP, #0x58] \n"
      "LDRNE   R10, [SP, #0x54] \n"
      "BNE     loc_FF95EB48 \n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "BNE     loc_FF95EAA0 \n"
      "LDR     R0, =0xFF95E5F4 \n"
      "MOV     R1, #0 \n"
      "BL      sub_FFA38624 \n"
      "LDR     R1, [R6, #0x64] \n"
      "LDR     R2, =0xAAEA8 \n"
      "ADD     R3, SP, #0x5C \n"
      "ADD     R0, SP, #0x30 \n"
      "STRD    R0, [SP, #0x10] \n"
      "STRD    R2, [SP, #0x18] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "MVN     R3, #0 \n"
      "ADD     R0, SP, #0x60 \n"
      "STMEA   SP, {R0-R3} \n"
      "LDR     R0, [SP, #0x58] \n"
      "LDR     R1, [SP, #0x54] \n"
      "LDR     R2, [SP, #0x50] \n"
      "LDR     R3, [SP, #0x4C] \n"
      "BL      sub_FFA38578 \n"
      "B       loc_FF95EAF4 \n"
"loc_FF95EAA0:\n"
      "LDR     R0, [R4, #0x20] \n"
      "LDR     R2, [R6, #0x64] \n"
      "ADD     R3, SP, #0x5C \n"
      "MVN     R1, #0 \n"
      "ADD     R9, SP, #0x1C \n"
      "STMIA   R9, {R0-R3} \n"
      "LDR     R3, [R4, #0x1C] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "ADD     R0, SP, #0x60 \n"
      "ADD     R9, SP, #0xC \n"
      "STMIA   R9, {R0-R3} \n"
      "LDR     R1, [SP, #0x50] \n"
      "LDR     R2, [SP, #0x54] \n"
      "LDR     R3, [SP, #0x4C] \n"
      "STMFA   SP, {R1,R3} \n"
      "STR     R2, [SP] \n"
      "LDMIB   R4, {R0,R1} \n"
      "LDR     R3, [SP, #0x58] \n"
      "MOV     R2, R11 \n"
      "BL      sub_FFA37268 \n"
"loc_FF95EAF4:\n"
      "LDR     R0, [R6, #0x18] \n"
      "LDR     R1, [R6, #0x60] \n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9 \n"
      "BEQ     loc_FF95E938 \n"
      "LDR     R0, [SP, #0x5C] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF95E9B8 \n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "MOV     R0, #1 \n"
      "BNE     loc_FF95EB2C \n"
      "BL      sub_FFA385EC \n"
      "B       loc_FF95EB30 \n"
"loc_FF95EB2C:\n"
      "BL      sub_FFA37314 \n"
"loc_FF95EB30:\n"
      "STR     R8, [R6, #0xC4] \n"
      "LDR     R0, [SP, #0x60] \n"
      "LDR     R1, [SP, #0x58] \n"
      "ADD     R9, R1, R0 \n"
      "LDR     R1, [SP, #0x54] \n"
      "SUB     R10, R1, R0 \n"
"loc_FF95EB48:\n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "BNE     loc_FF95EBA8 \n"
      "LDR     R0, =0xFF95E2DC \n"
      "MOV     R1, #0 \n"
      "BL      sub_FFA38624 \n"
      "LDR     R1, [R6, #0x64] \n"
      "LDR     R2, =0xAAEA8 \n"
      "ADD     R0, SP, #0x30 \n"
      "ADD     R3, SP, #0x5C \n"
      "STRD    R0, [SP, #0x10] \n"
      "STRD    R2, [SP, #0x18] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "LDR     R3, [R6, #0x68] \n"
      "ADD     R0, SP, #0x60 \n"
      "STMEA   SP, {R0-R3} \n"
      "LDR     R2, [SP, #0x50] \n"
      "LDR     R3, [SP, #0x4C] \n"
      "MOV     R1, R10 \n"
      "MOV     R0, R9 \n"
      "BL      sub_FFA38578 \n"
      "BL      sub_FF84BA38 \n"
      "B       loc_FF95EBF8 \n"
"loc_FF95EBA8:\n"
      "LDR     R0, [R4, #0x20] \n"
      "LDR     R1, [R6, #0x68] \n"
      "LDR     R2, [R6, #0x64] \n"
      "ADD     R3, SP, #0x5C \n"
      "ADD     R12, SP, #0x1C \n"
      "STMIA   R12, {R0-R3} \n"
      "LDR     R3, [R4, #0x1C] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "ADD     R0, SP, #0x60 \n"
      "ADD     R12, SP, #0xC \n"
      "STMIA   R12, {R0-R3} \n"
      "LDR     R2, [SP, #0x50] \n"
      "LDR     R3, [SP, #0x4C] \n"
      "STMFA   SP, {R2,R3} \n"
      "STR     R10, [SP] \n"
      "LDMIB   R4, {R0,R1} \n"
      "MOV     R3, R9 \n"
      "MOV     R2, R11 \n"
      "BL      sub_FFA37268 \n"
"loc_FF95EBF8:\n"
      "LDR     R0, [R6, #0x18] \n"
      "LDR     R1, [R6, #0x60] \n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9 \n"
      "BNE     loc_FF95EC18 \n"
      "MOV     R1, #0 \n"
"loc_FF95EC10:\n"
      "MOV     R0, #0x90000 \n"
      "B       loc_FF95EC2C \n"
"loc_FF95EC18:\n"
      "LDR     R0, [SP, #0x5C] \n"
      "CMP     R0, #0 \n"
      "BEQ     loc_FF95EC34 \n"
      "MOV     R1, #0 \n"
"loc_FF95EC28:\n"
      "MOV     R0, #0xA0000 \n"
"loc_FF95EC2C:\n"
      "BL      sub_FF95E584 \n"
      "B       loc_FF95E7E0 \n"
"loc_FF95EC34:\n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "MOV     R0, #0 \n"
      "BNE     loc_FF95EC4C \n"
      "BL      sub_FFA385EC \n"
      "B       loc_FF95EC50 \n"
"loc_FF95EC4C:\n"
      "BL      sub_FFA37314 \n"
"loc_FF95EC50:\n"
      "LDR     R0, [SP, #0x58] \n"
      "LDR     R1, [SP, #0x60] \n"
      "BL      sub_FFA6D034 \n"
      "LDR     R0, [R6, #0x68] \n"
      "LDR     R3, =0x6468 \n"        // <- 6468
      "ADD     R1, R0, #1 \n"
      "STR     R1, [R6, #0x68] \n"
      "LDR     R0, [SP, #0x60] \n"
      "SUB     R2, R3, #4 \n"         // <- -4
      "BL      sub_FFA6A8A8 \n"
#if 0
      "LDR	   R0, =0x6464 \n"		// added, 0x6468-0x4
      "BL      set_quality \n"		// added
#endif
      "LDR     R0, [R6, #0x64] \n"
      "CMP     R0, #1 \n"
      "BNE     loc_FF95ECC4 \n"
      "ADD     R0, SP, #0x48 \n"
      "BL      sub_FFA386A8 \n"
      "LDR     R1, =0xAAE78 \n"
      "LDR     R0, [R1, #4] \n"
      "LDR     R1, [R1] \n"
      "SUB     R2, R0, #0x400 \n"
      "SUBS    R2, R2, #0x38 \n"
      "ADDEQ   R0, R0, #8 \n"
      "MOV     R1, R1, LSR #4 \n"
      "MOV     R0, R0, LSR #4 \n"
      "MUL     R1, R0, R1 \n"
      "LDR     R0, [SP, #0x48] \n"
      "BL      sub_003FC934 \n"
      "LDR     R1, =0xAAEA8 \n"
      "STR     R0, [SP, #0x48] \n"
      "BL      sub_FFA6ABD8 \n"
"loc_FF95ECC4:\n"
      "CMP     R7, #1 \n"
      "BNE     loc_FF95ECD8 \n"
"loc_FF95ECCC:\n"
      "BL      sub_FF84BA5C \n"
      "MOV     R0, #1 \n"
      "BL      sub_FF84BA80 \n"
"loc_FF95ECD8:\n"
      "CMP     R5, #1 \n"
      "LDRNEH  R0, [R6, #6] \n"
      "CMPNE   R0, #3 \n"
      "BNE     loc_FF95E7E0 \n"
      "LDR     R0, [R6, #0x6C] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R6, #0x6C] \n"
      "LDRH    R1, [R6, #6] \n"
      "CMP     R1, #3 \n"
      "LDRNE   R1, [R6, #0x54] \n"
      "MULNE   R0, R1, R0 \n"
      "LDRNE   R1, [R6, #0x50] \n"
      "BNE     loc_FF95ED28 \n"
      "LDR     R1, [R6, #0x58] \n"
      "CMP     R1, #0x19 \n"
      "LDRNE   R1, =0x3E9 \n"
      "MOVEQ   R1, #0x3E8 \n"
      "MUL     R0, R1, R0 \n"
      "LDRNE   R1, =0x1770 \n"
      "LDREQ   R1, =0x1388 \n"
"loc_FF95ED28:\n"
      "BL      sub_003FC934 \n"
      "MOV     R4, R0 \n"
      "BL      sub_FFA6D3C8 \n"
      "LDR     R0, [R6, #0x8C] \n"
      "CMP     R0, R4 \n"
      "BNE     loc_FF95ED4C \n"
      "LDR     R0, [R6, #0x3C] \n"
      "CMP     R0, #1 \n"
      "BNE     loc_FF95ED60 \n"
"loc_FF95ED4C:\n"
      "LDR     R1, [R6, #0x98] \n"
      "MOV     R0, R4 \n"
      "BLX     R1 \n"
      "STR     R4, [R6, #0x8C] \n"
      "STR     R8, [R6, #0x3C] \n"
"loc_FF95ED60:\n"
      "STR     R8, [R6, #0x38] \n"
      "B       loc_FF95E7E0 \n"
	);
}
*/