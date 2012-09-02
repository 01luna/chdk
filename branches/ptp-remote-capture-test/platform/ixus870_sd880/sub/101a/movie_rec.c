#include "conf.h"

void change_video_tables(int a, int b){
}


void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}


void __attribute__((naked,noinline)) movie_record_task(){ 
 // from 0xFF85E03C (found via call to taskcreate_AviWrite)
 asm volatile(

                 "STMFD   SP!, {R2-R8,LR}\n"
                 "LDR     R7, =0x2710\n"
                 "LDR     R4, =0x51A8\n"
                 "MOV     R6, #0\n"
                 "MOV     R5, #1\n"
 "loc_FF85E050:\n"
                 "LDR     R0, [R4,#0x1C]\n"
                 "MOV     R2, #0\n"
                 "ADD     R1, SP, #0xC\n"
                 "BL      sub_FF827098\n"
                 "LDR     R0, [R4,#0x24]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF85E120\n"
                 "LDR     R0, [SP,#0xC]\n"
                 "LDR     R1, [R0]\n"
                 "SUB     R1, R1, #2\n"
                 "CMP     R1, #9\n"
                 "ADDLS   PC, PC, R1,LSL#2\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E084:\n"
                 "B       loc_FF85E0D4\n"
 "loc_FF85E088:\n"
                 "B       loc_FF85E0F4\n"
 "loc_FF85E08C:\n"
                 "B       loc_FF85E104\n"
 "loc_FF85E090:\n"
                 "B       loc_FF85E10C\n"
 "loc_FF85E094:\n"
                 "B       loc_FF85E0DC\n"
 "loc_FF85E098:\n"
                 "B       loc_FF85E114\n"
 "loc_FF85E09C:\n"
                 "B       loc_FF85E0E4\n"
 "loc_FF85E0A0:\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E0A4:\n"
                 "B       loc_FF85E11C\n"
 "loc_FF85E0A8:\n"
                 "B       loc_FF85E0AC\n"
 "loc_FF85E0AC:\n"
                 "STR     R6, [R4,#0x38]\n"
                 "LDR     R0, =0xFF85DD14\n"
                 "LDR     R2, =0xFF85D28C\n"
                 "LDR     R1, =0x1AB94\n"
                 "STR     R0, [R4,#0xA0]\n"
                 "LDR     R0, =0xFF85D370\n"
                 "STR     R6, [R4,#0x28]\n"
                 "BL      sub_FF8C3BFC\n"
                 "STR     R5, [R4,#0x3C]\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E0D4:\n"
                 "BL      unlock_optical_zoom\n" // + (used ixus980)
                 "BL      sub_FF85DE1C\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E0DC:\n"
                 "BL      sub_FF85D98C_my\n"  //--------------->
                 "B       loc_FF85E120\n"
 "loc_FF85E0E4:\n"
                 "LDR     R1, [R0,#0x10]\n"
                 "LDR     R0, [R0,#4]\n"
                 "BL      sub_FF92FDF0\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E0F4:\n"
                 "LDR     R0, [R4,#0x3C]\n"
                 "CMP     R0, #5\n"
                 "STRNE   R5, [R4,#0x2C]\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E104:\n"
                 "BL      sub_FF85D6CC\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E10C:\n"
                 "BL      sub_FF85D3BC\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E114:\n"
                 "BL      sub_FF85D218\n"
                 "B       loc_FF85E120\n"
 "loc_FF85E11C:\n"
                 "BL      sub_FF85E28C\n"
 "loc_FF85E120:\n"
                 "LDR     R1, [SP,#0xC]\n"
                 "MOV     R3, #0x430\n"
                 "STR     R6, [R1]\n"
                 "STR     R3, [SP]\n"
                 "LDR     R0, [R4,#0x20]\n"
                 "LDR     R3, =0xFF85D018\n"
                 "MOV     R2, R7\n"
                 "BL      sub_FF8279EC\n"
                 "B       loc_FF85E050\n"
 );
}


void __attribute__((naked,noinline)) sub_FF85D98C_my(){ 
 asm volatile(

                 "STMFD   SP!, {R4-R10,LR}\n"
                 "SUB     SP, SP, #0x40\n"
                 "MOV     R7, #0\n"
                 "LDR     R6, =0x51A8\n"
                 "MOV     R4, R0\n"
                 "STR     R7, [SP,#0x30]\n"
                 "STR     R7, [SP,#0x28]\n"
                 "LDR     R0, [R6,#0x3C]\n"
                 "MOV     R9, #4\n"
                 "CMP     R0, #3\n"
                 "STREQ   R9, [R6,#0x3C]\n"
                 "LDR     R0, [R6,#0xA0]\n"
                 "MOV     R8, #0\n"
                 "BLX     R0\n"
                 "LDR     R0, [R6,#0x3C]\n"
                 "CMP     R0, #4\n"
                 "BNE     loc_FF85DB10\n"
                 "LDRH    R0, [R6,#2]\n"
                 "MOV     R5, #1\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF85DA08\n"
                 "LDRH    R1, [R6,#4]\n"
                 "LDR     R0, [R6,#0x48]\n"
                 "MUL     R0, R1, R0\n"
                 "MOV     R1, #0x3E8\n"
                 "BL      sub_FFAD3D98\n"
                 "MOV     R1, R0\n"
                 "LDR     R0, [R6,#0x50]\n"
                 "BL      sub_FFAD3D98\n"
                 "CMP     R1, #0\n"
                 "BNE     loc_FF85DA24\n"
 "loc_FF85DA08:\n"
                 "ADD     R3, SP, #0x28\n"
                 "ADD     R2, SP, #0x2C\n"
                 "ADD     R1, SP, #0x30\n"
                 "ADD     R0, SP, #0x34\n"
                 "BL      sub_FF92FE8C\n"
                 "MOVS    R8, R0\n"
                 "BNE     loc_FF85DA40\n"
 "loc_FF85DA24:\n"
                 "LDR     R0, [R6,#0x2C]\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF85DB24\n"
                 "LDR     R0, [R6,#0x50]\n"
                 "LDR     R1, [R6,#0x40]\n"
                 "CMP     R0, R1\n"
                 "BCC     loc_FF85DB24\n"
 "loc_FF85DA40:\n"
                 "CMP     R8, #0x80000001\n"
                 "STREQ   R9, [R6,#0x54]\n"
                 "BEQ     loc_FF85DA78\n"
                 "CMP     R8, #0x80000003\n"
                 "STREQ   R5, [R6,#0x54]\n"
                 "BEQ     loc_FF85DA78\n"
                 "CMP     R8, #0x80000005\n"
                 "MOVEQ   R0, #2\n"
                 "BEQ     loc_FF85DA74\n"
                 "CMP     R8, #0x80000007\n"
                 "STRNE   R7, [R6,#0x54]\n"
                 "BNE     loc_FF85DA78\n"
                 "MOV     R0, #3\n"
 "loc_FF85DA74:\n"
                 "STR     R0, [R6,#0x54]\n"
 "loc_FF85DA78:\n"
                 "LDR     R0, =0x1ABC8\n"
                 "LDR     R0, [R0,#8]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF85DA90\n"
                 "BL      sub_FF847B84\n"
                 "B       loc_FF85DA94\n"
 "loc_FF85DA90:\n"
                 "BL      sub_FF85D218\n"
 "loc_FF85DA94:\n"
                 "LDR     R0, [R4,#0x14]\n"
                 "LDR     R1, [R4,#0x18]\n"
                 "ADD     R3, SP, #0x38\n"
                 "MVN     R2, #1\n"
                 "ADD     R7, SP, #0x18\n"
                 "STMIA   R7, {R0-R3}\n"
                 "MOV     R0, #0\n"
                 "ADD     R1, SP, #0x3C\n"
                 "ADD     R7, SP, #0x8\n"
                 "LDRD    R2, [R6,#0x68]\n"
                 "STMIA   R7, {R0-R3}\n"
                 "MOV     R3, #0\n"
                 "MOV     R2, #0x40\n"
                 "STRD    R2, [SP]\n"
                 "LDMIB   R4, {R0,R1}\n"
                 "LDR     R3, =0x1ABE0\n"
                 "MOV     R2, R10\n"
                 "BL      sub_FF8EDBE0\n"
                 "LDR     R0, [R6,#0x14]\n"
                 "MOV     R1, #0x3E8\n"
                 "BL      sub_FF8274B4\n"
                 "CMP     R0, #9\n"
                 "BEQ     loc_FF85DBA4\n"
                 "LDR     R0, [SP,#0x38]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF85DBC0\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF8EDC88\n"
                 "BL      sub_FF8EDCC4\n"
                 "MOV     R0, #5\n"
                 "STR     R0, [R6,#0x3C]\n"
 "loc_FF85DB10:\n"
                 "ADD     SP, SP, #0x40\n"
                 "LDMFD   SP!, {R4-R10,PC}\n"
 "loc_FF85DB18:\n"
                 "BL      sub_FF879164\n"
                 "MOV     R0, #1\n"
                 "B       loc_FF85DC5C\n"
 "loc_FF85DB24:\n"
                 "LDR     R12, [SP,#0x30]\n"
                 "CMP     R12, #0\n"
                 "BEQ     loc_FF85DCBC\n"
                 "STR     R5, [R6,#0x30]\n"
                 "LDR     R0, [R6,#0x50]\n"
                 "LDR     R8, [R4,#0xC]\n"
                 "CMP     R0, #0\n"
                 "LDRNE   LR, [SP,#0x34]\n"
                 "BNE     loc_FF85DBEC\n"
                 "LDR     R0, [R4,#0x14]\n"
                 "LDR     R1, [R4,#0x18]\n"
                 "ADD     R3, SP, #0x38\n"
                 "MVN     R2, #0\n"
                 "ADD     R9, SP, #0x18\n"
                 "STMIA   R9, {R0-R3}\n"
                 "LDRD    R2, [R6,#0x68]\n"
                 "LDR     R0, [SP,#0x28]\n"
                 "ADD     R1, SP, #0x3C\n"
                 "ADD     R9, SP, #0x8\n"
                 "STMIA   R9, {R0-R3}\n"
                 "LDR     R3, [SP,#0x2C]\n"
                 "STR     R12, [SP]\n"
                 "STR     R3, [SP,#4]\n"
                 "LDMIB   R4, {R0,R1}\n"
                 "LDR     R3, [SP,#0x34]\n"
                 "MOV     R2, R8\n"
                 "BL      sub_FF8EDBE0\n"
                 "LDR     R0, [R6,#0x14]\n"
                 "MOV     R1, #0x3E8\n"
                 "BL      sub_FF8274B4\n"
                 "CMP     R0, #9\n"
                 "BNE     loc_FF85DBB4\n"
 "loc_FF85DBA4:\n"
                 "BL      sub_FF930358\n"
                 "MOV     R0, #0x90000\n"
                 "STR     R5, [R6,#0x3C]\n"
                 "B       loc_FF85DB18\n"
 "loc_FF85DBB4:\n"
                 "LDR     R0, [SP,#0x38]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF85DBD0\n"
 "loc_FF85DBC0:\n"
                 "BL      sub_FF930358\n"
                 "MOV     R0, #0xA0000\n"
                 "STR     R5, [R6,#0x3C]\n"
                 "B       loc_FF85DB18\n"
 "loc_FF85DBD0:\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF8EDC88\n"
                 "LDR     R0, [SP,#0x3C]\n"
                 "LDR     R1, [SP,#0x34]\n"
                 "ADD     LR, R1, R0\n"
                 "LDR     R1, [SP,#0x30]\n"
                 "SUB     R12, R1, R0\n"
 "loc_FF85DBEC:\n"
                 "LDR     R0, [R4,#0x14]\n"
                 "LDR     R2, [R6,#0x4C]\n"
                 "LDR     R1, [R4,#0x18]\n"
                 "ADD     R3, SP, #0x38\n"
                 "ADD     R9, SP, #0x18\n"
                 "STMIA   R9, {R0-R3}\n"
                 "LDRD    R2, [R6,#0x68]\n"
                 "LDR     R0, [SP,#0x28]\n"
                 "ADD     R1, SP, #0x3C\n"
                 "ADD     R9, SP, #0x8\n"
                 "STMIA   R9, {R0-R3}\n"
                 "LDR     R3, [SP,#0x2C]\n"
                 "STR     R12, [SP]\n"
                 "STR     R3, [SP,#4]\n"
                 "LDMIB   R4, {R0,R1}\n"
                 "MOV     R3, LR\n"
                 "MOV     R2, R8\n"
                 "BL      sub_FF8EDBE0\n"
                 "LDR     R0, [R6,#0x14]\n"
                 "MOV     R1, #0x3E8\n"
                 "BL      sub_FF8274B4\n"
                 "CMP     R0, #9\n"
                 "BNE     loc_FF85DC64\n"
                 "BL      sub_FF930358\n"
                 "MOV     R0, #0x90000\n"
                 "STR     R5, [R6,#0x3C]\n"
                 "BL      sub_FF879164\n"
                 "MOV     R0, #0\n"
 "loc_FF85DC5C:\n"
                 "BL      sub_FF8EDC88\n"
                 "B       loc_FF85DB10\n"
 "loc_FF85DC64:\n"
                 "LDR     R0, [SP,#0x38]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF85DC84\n"
                 "BL      sub_FF930358\n"
                 "MOV     R0, #0xA0000\n"
                 "STR     R5, [R6,#0x3C]\n"
                 "BL      sub_FF879164\n"
                 "B       loc_FF85DB10\n"
 "loc_FF85DC84:\n"
                 "MOV     R0, #0\n"
                 "BL      sub_FF8EDC88\n"
                 "LDR     R0, [SP,#0x34]\n"
                 "LDR     R1, [SP,#0x3C]\n"
                 "BL      sub_FF9300B4\n"
                 "LDR     R0, [R6,#0x4C]\n"
                 "LDR     R3, =0x5214\n"    // ->----
                 "ADD     R1, R0, #1\n"     //       |
                 "STR     R1, [R6,#0x4C]\n" //       |
                 "STR     R3, [SP]\n"       //       |
                 "LDR     R0, [SP,#0x3C]\n" //       |
                 "SUB     R3, R3, #4\n"     // ->----|
                 "MOV     R2, #0xF\n"       //       |
                 "BL      sub_FF92E3B0\n"   //       |
                 "LDR     R0, =0x5214-4\n"  // -<----     // +
                 "BL      set_quality\n"                  // +
 "loc_FF85DCBC:\n"
                 "LDR     R0, [R6,#0x50]\n"
                 "ADD     R0, R0, #1\n"
                 "STR     R0, [R6,#0x50]\n"
                 "LDR     R1, [R6,#0x78]\n"
                 "MUL     R0, R1, R0\n"
                 "LDR     R1, [R6,#0x74]\n"
                 "BL      sub_FFAD3D98\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FF930390\n"
                 "LDR     R1, [R6,#0x70]\n"
                 "CMP     R1, R4\n"
                 "BNE     loc_FF85DCF8\n"
                 "LDR     R0, [R6,#0x34]\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF85DD0C\n"
 "loc_FF85DCF8:\n"
                 "LDR     R1, [R6,#0x84]\n"
                 "MOV     R0, R4\n"
                 "BLX     R1\n"
                 "STR     R4, [R6,#0x70]\n"
                 "STR     R7, [R6,#0x34]\n"
 "loc_FF85DD0C:\n"
                 "STR     R7, [R6,#0x30]\n"
                 "B       loc_FF85DB10\n"
 );
}

