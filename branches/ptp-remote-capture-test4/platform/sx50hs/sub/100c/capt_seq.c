#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"

static long *nrflag = (long*)(0xCD4C);

#define NR_AUTO (0)                         //have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 300          //Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

//** capt_seq_task @ 0xFF085A8C
void __attribute__((naked,noinline)) capt_seq_task() {
    asm volatile (
            "STMFD   SP!, {R3-R7,LR}\n"
            "LDR     R4, =0x43FA0\n"
            "LDR     R7, =0x3A9C\n"
            "MOV     R6, #0\n"
    "loc_FF085A9C:\n"
            "LDR     R0, [R7,#4]\n"
            "MOV     R2, #0\n"
            "MOV     R1, SP\n"
            "BL      sub_68BDE0\n"
            "TST     R0, #1\n"
            "BEQ     loc_FF085AC8\n"
            "LDR     R1, =0x491\n"
            "LDR     R0, =0xFF0853D8 \n"  // SsShootTask.c
            "BL      _DebugAssert \n"
            "BL      _ExitTask \n"
            "LDMFD   SP!, {R3-R7,PC}\n"
    "loc_FF085AC8:\n"
            "LDR     R0, [SP]\n"
            "LDR     R1, [R0]\n"
            "CMP     R1, #0x28 \n"
            "ADDCC   PC, PC, R1,LSL#2\n"
            "B       loc_FF085D74\n"
    "loc_FF085ADC:\n"
            "B       loc_FF085B7C\n"
            "B       loc_FF085B94\n"
            "B       loc_FF085BA0\n"
            "B       loc_FF085BC0\n"
            "B       loc_FF085BB8\n"
            "B       loc_FF085BCC\n"
            "B       loc_FF085BD4\n"
            "B       loc_FF085BDC\n"
            "B       loc_FF085BF8\n"
            "B       loc_FF085C4C\n"
            "B       loc_FF085C04\n"
            "B       loc_FF085C10\n"
            "B       loc_FF085C18\n"
            "B       loc_FF085C34\n"
            "B       loc_FF085C3C\n"
            "B       loc_FF085C44\n"
            "B       loc_FF085C54\n"
            "B       loc_FF085C5C\n"
            "B       loc_FF085C64\n"
            "B       loc_FF085C6C\n"
            "B       loc_FF085C74\n"
            "B       loc_FF085C7C\n"
            "B       loc_FF085C84\n"
            "B       loc_FF085C8C\n"
            "B       loc_FF085C94\n"
            "B       loc_FF085C9C\n"
            "B       loc_FF085CA8\n"
            "B       loc_FF085CB0\n"
            "B       loc_FF085CBC\n"
            "B       loc_FF085CC4\n"
            "B       loc_FF085CF4\n"
            "B       loc_FF085CFC\n"
            "B       loc_FF085D04\n"
            "B       loc_FF085D0C\n"
            "B       loc_FF085D14\n"
            "B       loc_FF085D1C\n"
            "B       loc_FF085D28\n"
            "B       loc_FF085D30\n"
            "B       loc_FF085D3C\n"
            "B       loc_FF085D80\n"
    "loc_FF085B7C:\n"
    //PATCH BEGIN
            "BL      shooting_expo_iso_override\n"
    //PATCH END
            "BL      sub_FF086364\n"
    //PATCH BEGIN
            "BL      shooting_expo_param_override\n"
    //PATCH END
            "BL      sub_FF082A44\n"
    //PATCH BEGIN
            //"LDR     R0, [R4,#0x28]\n"
            //"CMP     R0, #0\n"
            //"BLNE    sub_FF1F5FE8\n"
            "MOV     R0, #0\n"
            "STR     R0, [R4,#0x28]\n"          //fixes overrides  behavior at short shutter
    //PATCH END
            "B       loc_FF085D80\n"
    "loc_FF085B94:\n"
            "LDR     R0, [R0,#0x10]\n"
    //PATCH BEGIN TODO
            //"BL      sub_FF085EC8\n"
    	    "BL      sub_FF085EC8_my\n"  //
    //PATCH END
            "B       loc_FF085D80\n"
    "loc_FF085BA0:\n"
            "MOV     R0, #1\n"
            "BL      sub_FF0866F8\n"
            "LDR     R0, [R4,#0xC]\n"
            "CMP     R0, #0\n"
            "BLNE    sub_FF087594\n"
            "B       loc_FF085D80\n"
    "loc_FF085BB8:\n"
            "BL      sub_FF08601C\n"
            "B       loc_FF085BC4\n"
    "loc_FF085BC0:\n"
            "BL      sub_FF086344\n"
    "loc_FF085BC4:\n"
            "STR     R6, [R4,#0x28]\n"
            "B       loc_FF085D80\n"
    "loc_FF085BCC:\n"
            "BL      sub_FF08634C\n"
            "B       loc_FF085D80\n"
    "loc_FF085BD4:\n"
            "BL      sub_FF0865A4\n"
            "B       loc_FF085BFC\n"
    "loc_FF085BDC:\n"
            "LDR     R5, [R0,#0x10]\n"
            "MOV     R0, R5\n"
            "BL      sub_FF1F60FC\n"
            "MOV     R2, R5\n"
            "MOV     R1, #9\n"
            "BL      sub_FF0834FC\n"
            "B       loc_FF085D80\n"
    "loc_FF085BF8:\n"
            "BL      sub_FF086660\n"
    "loc_FF085BFC:\n"
            "BL      sub_FF082A44\n"
            "B       loc_FF085D80\n"
    "loc_FF085C04:\n"
            "LDR     R0, [R4,#0x58]\n"
            "BL      sub_FF086F60\n"
            "B       loc_FF085D80\n"
    "loc_FF085C10:\n"
            "BL      sub_FF0872F0\n"
            "B       loc_FF085D80\n"
    "loc_FF085C18:\n"
            "LDRH    R0, [R4]\n"
            "SUB     R1, R0, #0x8200\n"
            "SUBS    R1, R1, #0x39\n"
            "MOVNE   R0, #0\n"
            "MOVEQ   R0, #1\n"
            "BL      sub_FF087354\n"
            "B       loc_FF085D80\n"
    "loc_FF085C34:\n"
            "BL      sub_FF087684\n"
            "B       loc_FF085D80\n"
    "loc_FF085C3C:\n"
            "BL      sub_FF087AF8\n"
            "B       loc_FF085D80\n"
    "loc_FF085C44:\n"
            "BL      sub_FF087BAC\n"
            "B       loc_FF085D80\n"
    "loc_FF085C4C:\n"
            "BL      sub_FF086344\n"
            "B       loc_FF085D80\n"
    "loc_FF085C54:\n"
            "BL      sub_FF1F3A18\n"
            "B       loc_FF085D80\n"
    "loc_FF085C5C:\n"
            "BL      sub_FF1F3CAC\n"
            "B       loc_FF085D80\n"
    "loc_FF085C64:\n"
            "BL      sub_FF1F3D7C\n"
            "B       loc_FF085D80\n"
    "loc_FF085C6C:\n"
            "BL      sub_FF1F3E30\n"
            "B       loc_FF085D80\n"
    "loc_FF085C74:\n"
            "BL      sub_FF1F3F08\n"
            "B       loc_FF085D80\n"
    "loc_FF085C7C:\n"
            "MOV     R0, #0\n"
            "B       loc_FF085CA0\n"
    "loc_FF085C84:\n"
            "BL      sub_FF1F4500\n"
            "B       loc_FF085D80\n"
    "loc_FF085C8C:\n"
            "BL      sub_FF1F4594\n"
            "B       loc_FF085D80\n"
    "loc_FF085C94:\n"
            "BL      sub_FF1F463C\n"
            "B       loc_FF085D80\n"
    "loc_FF085C9C:\n"
            "MOV     R0, #1\n"
    "loc_FF085CA0:\n"
            "BL      sub_FF1F439C\n"
            "B       loc_FF085D80\n"
    "loc_FF085CA8:\n"
            "BL      sub_FF086940\n"
            "B       loc_FF085D80\n"
    "loc_FF085CB0:\n"
            "BL      sub_FF0869D4\n"
            "BL      sub_FF1F74B0\n"
            "B       loc_FF085D80\n"
    "loc_FF085CBC:\n"
            "BL      sub_FF1F41DC\n"
            "B       loc_FF085D80\n"
    "loc_FF085CC4:\n"
            "MOV     R2, #2\n"
            "ADD     R1, R4, #0x6A\n"
            "MOV     R0, #0x6F \n"
            "BL      _GetPropertyCase \n"
            "TST     R0, #1\n"
            "LDRNE   R1, =0x592\n"
            "LDRNE   R0, =0xFF0853D8 \n" // SsShootTask.c
            "BLNE    _DebugAssert \n"
            "LDRH    R0, [R4,#0x6A]\n"
            "CMP     R0, #1\n"
            "BLEQ    sub_FF1F41D0\n"
            "B       loc_FF085D80\n"
    "loc_FF085CF4:\n"
            "BL      sub_FF1F42F8\n"
            "B       loc_FF085D80\n"
    "loc_FF085CFC:\n"
            "BL      sub_FF1F7584\n"
            "B       loc_FF085D80\n"
    "loc_FF085D04:\n"
            "BL      sub_FF01D9A8\n"
            "B       loc_FF085D80\n"
    "loc_FF085D0C:\n"
            "BL      sub_FF08CA00\n"
            "B       loc_FF085D80\n"
    "loc_FF085D14:\n"
            "BL      sub_FF08CB00\n"
            "B       loc_FF085D80\n"
    "loc_FF085D1C:\n"
            "LDR     R0, [R0,#0xC]\n"
            "BL      sub_FF1F4744\n"
            "B       loc_FF085D80\n"
    "loc_FF085D28:\n"
            "BL      sub_FF1F47B4\n"
            "B       loc_FF085D80\n"
    "loc_FF085D30:\n"
            "BL      sub_FF08CC8C\n"
            "BL      sub_FF08CB58\n"
            "B       loc_FF085D80\n"
    "loc_FF085D3C:\n"
            "MOV     R0, #1\n"
            "BL      sub_FF1F692C\n"
            "MOV     R0, #1\n"
            "BL      sub_FF1F6A60\n"
            "LDRH    R0, [R4,#0xAC]\n"
            "CMP     R0, #4\n"
            "LDRNEH  R0, [R4]\n"
            "SUBNE   R1, R0, #0x4200\n"
            "SUBNES  R1, R1, #0x2E\n"
            "BNE     loc_FF085D80\n"
            "BL      sub_FF08CB00\n"
            "BL      sub_FF08D3A4\n"
            "BL      sub_FF08D0AC\n"
            "B       loc_FF085D80\n"
    "loc_FF085D74:\n"
            "LDR     R1, =0x5F2\n"
            "LDR     R0, =0xFF0853D8 \n"
      "BL      _DebugAssert \n"
    "loc_FF085D80:\n"
            "LDR     R0, [SP]\n"
            "LDR     R1, [R0,#4]\n"
            "LDR     R0, [R7]\n"
            "BL      sub_68BB50\n"
            "LDR     R5, [SP]\n"
            "LDR     R0, [R5,#8]\n"
            "CMP     R0, #0\n"
            "LDREQ   R1, =0x117\n"
            "LDREQ   R0, =0xFF0853D8 \n"
            "BLEQ    _DebugAssert \n"
            "STR     R6, [R5,#8]\n"
            "B       loc_FF085A9C\n"

    );
}

//** sub_FF085EC8_my @ 0xFF085EC8
void __attribute__((naked,noinline)) sub_FF085EC8_my() {
    asm volatile(
"sub_FF085EC8:\n"
        "STMFD   SP!, {R4-R6,LR}\n"
        "LDR     R5, =0x43FA0\n"
        "MOV     R6, R0\n"
        "LDR     R0, [R5,#0x28]\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF085F18\n"
        "LDR     R0, [R5,#0x9C]\n"
        "TST     R0, #0x30\n"
        "BLNE    sub_FF08A648\n"
        "BL      sub_FF08A104\n"
        "MOV     R1, R6\n"
        "BL      sub_FF08A15C\n"
        "LDR     R0, =0x10F\n"
        "MOV     R2, #4\n"
        "ADD     R1, R6, #0x78\n"
        "BL      _SetPropertyCase \n"
        "MOV     R2, #4\n"
        "ADD     R1, R6, #0x7C\n"
        "MOV     R0, #0x2C \n"
        "BL      _SetPropertyCase \n"
"loc_FF085F18:\n"
        "LDR     R0, [R5,#0x9C]\n"
        "TST     R0, #0x20\n"
        "MOV     R0, R6\n"
        "BEQ     loc_FF085F30\n"
        "BL      sub_FF1F6EF8\n"
        "B       loc_FF085F34\n"
"loc_FF085F30:\n"
// PATCH
        //"BL      sub_FF1F5D70\n"
        "BL      sub_FF1F5D70_my\n"

    	"BL     capt_seq_hook_raw_here\n"
"loc_FF085F34:\n"
        "MOV     R4, R0\n"
        "MOV     R2, R6\n"
        "MOV     R1, #1\n"
        "BL      sub_FF0834FC\n"
        "TST     R4, #1\n"
        "LDMNEFD SP!, {R4-R6,PC}\n"
        "MOV     R0, R6\n"
        "BL      sub_FF1F4D68\n"
        "LDR     R0, [R5,#0x9C]\n"
        "TST     R0, #2\n"
        "LDMEQFD SP!, {R4-R6,PC}\n"
        "MOV     R0, R6\n"
        "LDMFD   SP!, {R4-R6,LR}\n"
        "B       sub_FF083800\n"
);
}

//** sub_FF1F5D70_my @ 0xFF1F5D70
void __attribute__((naked,noinline)) sub_FF1F5D70_my () {
    asm volatile(
            "STMFD   SP!, {R3-R7,LR}\n"
            "LDR     R6, =0x43FA0\n"
            "MOV     R4, R0\n"
            "LDR     R0, [R6,#0x28]\n"
            "LDR     R5, =0x420D\n"
            "CMP     R0, #0\n"
            "MOV     R7, #0\n"
            "BNE     loc_FF1F5E14\n"
            "LDR     R1, [R6,#0x9C]\n"
            "TST     R1, #6\n"
            "BNE     loc_FF1F5DB0\n"
            "MOV     R0, #0xC\n"
            "BL      sub_FF08F82C\n"
            "TST     R0, #1\n"
            "BEQ     loc_FF1F5E14\n"
            "B       loc_FF1F5E0C\n"
    "loc_FF1F5DB0:\n"
            "LDRH    R0, [R6]\n"
            "CMP     R0, R5\n"
            "LDRNEH  R0, [R6,#0xAA]\n"
            "CMPNE   R0, #3\n"
            "LDRNE   R0, [R4,#8]\n"
            "CMPNE   R0, #1\n"
            "BLS     loc_FF1F5DF4\n"
            "LDRH    R0, [R6,#0xA6]\n"
            "CMP     R0, #3\n"
            "BNE     loc_FF1F5DE0\n"
            "TST     R1, #2\n"
            "BNE     loc_FF1F5E14\n"
    "loc_FF1F5DE0:\n"
            "BL      sub_FF018814\n"
            "TST     R0, #1\n"
            "BEQ     loc_FF1F5E14\n"
            "BL      sub_FF08F88C\n"
            "B       loc_FF1F5E0C\n"
    "loc_FF1F5DF4:\n"
            "MOV     R0, #0xC\n"
            "BL      sub_FF08F82C\n"
            "TST     R0, #1\n"
            "BEQ     loc_FF1F5E14\n"
            "BL      sub_FF1F67A8\n"
            "BL      sub_FF083118\n"
    "loc_FF1F5E0C:\n"
            "MOV     R0, #1\n"
            "LDMFD   SP!, {R3-R7,PC}\n"
    "loc_FF1F5E14:\n"
            "MOV     R0, R4\n"
            "BL      sub_FF1F75F8\n"
            "BL      sub_FF086354\n"
            "LDR     R0, [R6,#0x28]\n"
            "CMP     R0, #0\n"
            "BNE     loc_FF1F5FD0\n"
            "MOV     R0, R4\n"
            "BL      sub_FF1F4C40\n"
            "TST     R0, #1\n"
            "LDMNEFD SP!, {R3-R7,PC}\n"
            "LDR     R0, [R6,#0x9C]\n"
            "AND     R0, R0, #0x40\n"
            "CMP     R0, #0\n"
            "LDRNEH  R0, [R6]\n"
            "CMPNE   R0, R5\n"
            "LDRNEH  R0, [R6,#0xAA]\n"
            "CMPNE   R0, #3\n"
            "LDRNE   R0, [R4,#8]\n"
            "CMPNE   R0, #1\n"
            "BLS     loc_FF1F5E80\n"
            "BL      sub_FF1F6C20\n"
            "MOV     R3, #0xB3 \n"
            "STR     R3, [SP]\n"
            "LDR     R2, =0x3A98\n"
            "LDR     R3, =0xFF1F60D8 \n"  //SsCaptureSeq.c
            "MOV     R1, #0x8000\n"
            "BL      sub_FF08FAA0\n"
    "loc_FF1F5E80:\n"
            "LDR     R0, [R6,#0x9C]\n"
            "AND     R0, R0, #4\n"
            "CMP     R0, #0\n"
            "LDRNEH  R0, [R6]\n"
            "CMPNE   R0, R5\n"
            "LDRNEH  R0, [R6,#0xAA]\n"
            "CMPNE   R0, #3\n"
            "LDRNE   R0, [R4,#8]\n"
            "CMPNE   R0, #1\n"
            "BLS     loc_FF1F5EB4\n"
            "LDR     R0, [R6,#0xA0]\n"
            "CMP     R0, #2\n"
            "BNE     loc_FF1F5EC0\n"
    "loc_FF1F5EB4:\n"
            "MOV     R0, R4\n"
            "BL      sub_FF1F5198\n"
            "BL      sub_FF1F66EC\n"

		//begin patch
    		"BL      wait_until_remote_button_is_released\n"
    		"BL      capt_seq_hook_set_nr\n"
    	//end patch    

    "loc_FF1F5EC0:\n"
            "LDRH    R0, [R6]\n"
            "CMP     R0, R5\n"
            "LDRNEH  R0, [R6,#0xAA]\n"
            "CMPNE   R0, #3\n"
            "LDRNE   R0, [R4,#8]\n"
            "CMPNE   R0, #1\n"
            "MOVLS   R0, #4\n"
            "BLLS    sub_FF1F6210\n"
            "LDR     R0, [R6,#0x9C]\n"
            "TST     R0, #4\n"
            "BEQ     loc_FF1F5F18\n"
            "LDR     R0, [R6,#0xA0]\n"
            "CMP     R0, #2\n"
            "BNE     loc_FF1F5F18\n"
            "LDRH    R0, [R6]\n"
            "CMP     R0, R5\n"
            "LDRNEH  R0, [R6,#0xAA]\n"
            "CMPNE   R0, #3\n"
            "LDRNE   R0, [R4,#8]\n"
            "CMPNE   R0, #1\n"
            "MOVLS   R0, #3\n"
            "BLLS    sub_FF1F6210\n"
    "loc_FF1F5F18:\n"
            "LDR     R0, [R6,#0x9C]\n"
            "TST     R0, #0x40\n"
            "BEQ     loc_FF1F5F80\n"
            "LDR     R0, =0x181\n"
            "MOV     R2, #4\n"
            "MOV     R1, SP\n"
            "BL      _GetPropertyCase \n"
            "TST     R0, #1\n"
            "MOVNE   R1, #0xD4 \n"
            "LDRNE   R0, =0xFF1F60D8 \n" //SsCaptureSeq.c
      "BLNE    _DebugAssert \n"
            "LDR     R0, [SP]\n"
            "CMP     R0, #0\n"
            "BNE     loc_FF1F5F60\n"
            "BL      sub_FF1F6C20\n"
            "MOV     R1, #0x8000\n"
            "BL      sub_68BB50\n"
            "B       loc_FF1F5F80\n"
    "loc_FF1F5F60:\n"
            "BL      sub_FF1F6C20\n"
            "MOV     R1, #0x8000\n"
            "BL      sub_68BB84\n"
            "LDR     R2, =0xFF1F5DA4\n"
            "LDR     R0, [SP]\n"
            "MOV     R3, #0x8000\n"
            "MOV     R1, R2\n"
            "BL      sub_FF020D10\n"
    "loc_FF1F5F80:\n"
            "LDR     R0, [R6,#0x9C]\n"
            "AND     R0, R0, #6\n"
            "CMP     R0, #0\n"
            "LDRNEH  R0, [R6]\n"
            "CMPNE   R0, R5\n"
            "LDRNEH  R0, [R6,#0xAA]\n"
            "CMPNE   R0, #3\n"
            "LDRNE   R0, [R4,#8]\n"
            "CMPNE   R0, #1\n"
            "MOVLS   R0, #2\n"
            "BLLS    sub_FF091040\n"
    		//begin patch
//    		        "BL      wait_until_remote_button_is_released\n"
//    		        "BL      capt_seq_hook_set_nr\n"
    		//end patch
            "LDR     R0, [R6,#0x9C]\n"
            "TST     R0, #0x10\n"
            "MOV     R0, R4\n"
            "BEQ     loc_FF1F5FC4\n"
            "BL      sub_FF38E63C\n"
            "B       loc_FF1F5FC8\n"
    "loc_FF1F5FC4:\n"
            "BL      sub_FF1F57E0\n"
    "loc_FF1F5FC8:\n"
            "MOV     R7, R0\n"
            "B       loc_FF1F5FE0\n"
    "loc_FF1F5FD0:\n"
            "LDR     R0, =0xA430\n"
            "LDR     R0, [R0]\n"
            "CMP     R0, #0\n"
            "MOVNE   R7, #0x1D\n"
    "loc_FF1F5FE0:\n"
            "MOV     R0, R7\n"
            "LDMFD   SP!, {R3-R7,PC}\n"

    );
}

//** exp_drv_task @ 0xFF0CCA8C
void __attribute__((naked,noinline)) exp_drv_task() {
    asm volatile(
            "STMFD   SP!, {R4-R9,LR}\n"
            "SUB     SP, SP, #0x2C\n"
            "LDR     R6, =0x502C\n"
            "LDR     R7, =0xBB8\n"
            "LDR     R4, =0x62050\n"
            "MOV     R0, #0\n"
            "ADD     R5, SP, #0x1C\n"
            "STR     R0, [SP,#0xC]\n"
    "loc_FF0CCAAC:\n"
            "LDR     R0, [R6,#0x20]\n"
            "MOV     R2, #0\n"
            "ADD     R1, SP, #0x28\n"
            "BL      sub_68BDE0\n"
            "LDR     R0, [SP,#0xC]\n"
            "CMP     R0, #1\n"
            "BNE     loc_FF0CCAF8\n"
            "LDR     R0, [SP,#0x28]\n"
            "LDR     R0, [R0]\n"
            "CMP     R0, #0x14\n"
            "CMPNE   R0, #0x15\n"
            "CMPNE   R0, #0x16\n"
            "CMPNE   R0, #0x17\n"
            "BEQ     loc_FF0CCC58\n"
            "CMP     R0, #0x2A \n"
            "BEQ     loc_FF0CCBE0\n"
            "ADD     R1, SP, #0xC\n"
            "MOV     R0, #0\n"
            "BL      sub_FF0CCA3C\n"
    "loc_FF0CCAF8:\n"
            "LDR     R0, [SP,#0x28]\n"
            "LDR     R1, [R0]\n"
            "CMP     R1, #0x30 \n"
            "BNE     loc_FF0CCB24\n"
            "BL      sub_FF0CDFF8\n"
            "LDR     R0, [R6,#0x1C]\n"
            "MOV     R1, #1\n"
            "BL      sub_68BB50\n"
            "BL      _ExitTask \n"
            "ADD     SP, SP, #0x2C\n"
            "LDMFD   SP!, {R4-R9,PC}\n"
    "loc_FF0CCB24:\n"
            "CMP     R1, #0x2F \n"
            "BNE     loc_FF0CCB40\n"
            "LDR     R2, [R0,#0x8C]!\n"
            "LDR     R1, [R0,#4]\n"
            "MOV     R0, R1\n"
            "BLX     R2\n"
            "B       loc_FF0CD114\n"
    "loc_FF0CCB40:\n"
            "CMP     R1, #0x28 \n"
            "BNE     loc_FF0CCB90\n"
            "LDR     R0, [R6,#0x1C]\n"
            "MOV     R1, #0x80 \n"
            "BL      sub_68BB84\n"
            "LDR     R0, =0xFF0C7970\n"
            "MOV     R1, #0x80 \n"
            "BL      sub_FF1DC3F8\n"
            "LDR     R0, [R6,#0x1C]\n"
            "MOV     R2, R7\n"
            "MOV     R1, #0x80 \n"
            "BL      sub_68BA90\n"
            "TST     R0, #1\n"
            "LDRNE   R1, =0x1643\n"
            "BNE     loc_FF0CCC4C\n"
    "loc_FF0CCB7C:\n"
            "LDR     R1, [SP,#0x28]\n"
            "LDR     R0, [R1,#0x90]\n"
            "LDR     R1, [R1,#0x8C]\n"
            "BLX     R1\n"
            "B       loc_FF0CD114\n"
    "loc_FF0CCB90:\n"
            "CMP     R1, #0x29 \n"
            "BNE     loc_FF0CCBD8\n"
            "ADD     R1, SP, #0xC\n"
            "BL      sub_FF0CCA3C\n"
            "LDR     R0, [R6,#0x1C]\n"
            "MOV     R1, #0x100\n"
            "BL      sub_68BB84\n"
            "LDR     R0, =0xFF0C7980\n"
            "MOV     R1, #0x100\n"
            "BL      sub_FF1DD1AC\n"
            "LDR     R0, [R6,#0x1C]\n"
            "MOV     R2, R7\n"
            "MOV     R1, #0x100\n"
            "BL      sub_68BA90\n"
            "TST     R0, #1\n"
            "BEQ     loc_FF0CCB7C\n"
            "LDR     R1, =0x164D\n"
            "B       loc_FF0CCC4C\n"
    "loc_FF0CCBD8:\n"
            "CMP     R1, #0x2A \n"
            "BNE     loc_FF0CCBF0\n"
    "loc_FF0CCBE0:\n"
            "LDR     R0, [SP,#0x28]\n"
            "ADD     R1, SP, #0xC\n"
            "BL      sub_FF0CCA3C\n"
            "B       loc_FF0CCB7C\n"
    "loc_FF0CCBF0:\n"
            "CMP     R1, #0x2D \n"
            "BNE     loc_FF0CCC08\n"
            "BL      sub_FF0B6830\n"
            "BL      sub_FF0B7608\n"
            "BL      sub_FF0B7118\n"
            "B       loc_FF0CCB7C\n"
    "loc_FF0CCC08:\n"
            "CMP     R1, #0x2E \n"
            "BNE     loc_FF0CCC58\n"
            "LDR     R0, [R6,#0x1C]\n"
            "MOV     R1, #4\n"
            "BL      sub_68BB84\n"
            "LDR     R1, =0xFF0C79A0\n"
            "LDR     R0, =0xFFFFF400\n"
            "MOV     R2, #4\n"
            "BL      sub_FF0B6280\n"
            "BL      sub_FF0B6510\n"
            "LDR     R0, [R6,#0x1C]\n"
            "MOV     R2, R7\n"
            "MOV     R1, #4\n"
            "BL      sub_68B9AC\n"
            "TST     R0, #1\n"
            "BEQ     loc_FF0CCB7C\n"
            "LDR     R1, =0x1675\n"
    "loc_FF0CCC4C:\n"
            "LDR     R0, =0xFF0C81AC \n"
      "BL      _DebugAssert \n"
            "B       loc_FF0CCB7C\n"
    "loc_FF0CCC58:\n"
            "LDR     R0, [SP,#0x28]\n"
            "MOV     R8, #1\n"
            "LDR     R1, [R0]\n"
            "CMP     R1, #0x12\n"
            "CMPNE   R1, #0x13\n"
            "BNE     loc_FF0CCCC0\n"
            "LDR     R1, [R0,#0x7C]\n"
            "ADD     R1, R1, R1,LSL#1\n"
            "ADD     R1, R0, R1,LSL#2\n"
            "SUB     R1, R1, #8\n"
            "LDMIA   R1, {R2,R3,R9}\n"
            "STMIA   R5, {R2,R3,R9}\n"
            "BL      sub_FF0CAC20\n"
            "LDR     R0, [SP,#0x28]\n"
            "LDR     R1, [R0,#0x7C]\n"
            "LDR     R3, [R0,#0x8C]\n"
            "LDR     R2, [R0,#0x90]\n"
            "ADD     R0, R0, #4\n"
            "BLX     R3\n"
            "LDR     R0, [SP,#0x28]\n"
            "BL      sub_FF0CE3FC\n"
            "LDR     R0, [SP,#0x28]\n"
            "LDR     R1, [R0,#0x7C]\n"
            "LDR     R2, [R0,#0x98]\n"
            "LDR     R3, [R0,#0x94]\n"
            "B       loc_FF0CCFD8\n"
    "loc_FF0CCCC0:\n"
            "CMP     R1, #0x14\n"
            "CMPNE   R1, #0x15\n"
            "CMPNE   R1, #0x16\n"
            "CMPNE   R1, #0x17\n"
            "BNE     loc_FF0CCD78\n"
            "ADD     R3, SP, #0xC\n"
            "MOV     R2, SP\n"
            "ADD     R1, SP, #0x1C\n"
            "BL      sub_FF0CAE84\n"
            "CMP     R0, #1\n"
            "MOV     R9, R0\n"
            "CMPNE   R9, #5\n"
            "BNE     loc_FF0CCD14\n"
            "LDR     R0, [SP,#0x28]\n"
            "MOV     R2, R9\n"
            "LDR     R1, [R0,#0x7C]!\n"
            "LDR     R12, [R0,#0x10]!\n"
            "LDR     R3, [R0,#4]\n"
            "MOV     R0, SP\n"
            "BLX     R12\n"
            "B       loc_FF0CCD4C\n"
    "loc_FF0CCD14:\n"
            "LDR     R0, [SP,#0x28]\n"
            "CMP     R9, #2\n"
            "LDR     R3, [R0,#0x90]\n"
            "CMPNE   R9, #6\n"
            "BNE     loc_FF0CCD60\n"
            "LDR     R12, [R0,#0x8C]\n"
            "MOV     R2, R9\n"
            "MOV     R1, #1\n"
            "MOV     R0, SP\n"
            "BLX     R12\n"
            "LDR     R0, [SP,#0x28]\n"
            "MOV     R2, SP\n"
            "ADD     R1, SP, #0x1C\n"
            "BL      sub_FF0CC78C\n"
    "loc_FF0CCD4C:\n"
            "LDR     R0, [SP,#0x28]\n"
            "LDR     R2, [SP,#0xC]\n"
            "MOV     R1, R9\n"
            "BL      sub_FF0CC9DC\n"
            "B       loc_FF0CCFE0\n"
    "loc_FF0CCD60:\n"
            "LDR     R1, [R0,#0x7C]\n"
            "LDR     R12, [R0,#0x8C]\n"
            "MOV     R2, R9\n"
            "ADD     R0, R0, #4\n"
            "BLX     R12\n"
            "B       loc_FF0CCFE0\n"
    "loc_FF0CCD78:\n"
            "CMP     R1, #0x24 \n"
            "CMPNE   R1, #0x25 \n"
            "BNE     loc_FF0CCDC4\n"
            "LDR     R1, [R0,#0x7C]\n"
            "ADD     R1, R1, R1,LSL#1\n"
            "ADD     R1, R0, R1,LSL#2\n"
            "SUB     R1, R1, #8\n"
            "LDMIA   R1, {R2,R3,R9}\n"
            "STMIA   R5, {R2,R3,R9}\n"
            "BL      sub_FF0C9954\n"
            "LDR     R0, [SP,#0x28]\n"
            "LDR     R1, [R0,#0x7C]\n"
            "LDR     R3, [R0,#0x8C]\n"
            "LDR     R2, [R0,#0x90]\n"
            "ADD     R0, R0, #4\n"
            "BLX     R3\n"
            "LDR     R0, [SP,#0x28]\n"
            "BL      sub_FF0C9E4C\n"
            "B       loc_FF0CCFE0\n"
    "loc_FF0CCDC4:\n"
            "ADD     R1, R0, #4\n"
            "LDMIA   R1, {R2,R3,R9}\n"
            "STMIA   R5, {R2,R3,R9}\n"
            "LDR     R1, [R0]\n"
            "CMP     R1, #0x28 \n"
            "ADDCC   PC, PC, R1,LSL#2\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCDE0:\n"
            "B       loc_FF0CCE80\n"
    "loc_FF0CCDE4:\n"
            "B       loc_FF0CCE80\n"
    "loc_FF0CCDE8:\n"
            "B       loc_FF0CCE88\n"
    "loc_FF0CCDEC:\n"
            "B       loc_FF0CCE90\n"
    "loc_FF0CCDF0:\n"
            "B       loc_FF0CCE90\n"
    "loc_FF0CCDF4:\n"
            "B       loc_FF0CCE90\n"
    "loc_FF0CCDF8:\n"
            "B       loc_FF0CCE80\n"
    "loc_FF0CCDFC:\n"
            "B       loc_FF0CCE88\n"
    "loc_FF0CCE00:\n"
            "B       loc_FF0CCE90\n"
    "loc_FF0CCE04:\n"
            "B       loc_FF0CCE90\n"
    "loc_FF0CCE08:\n"
            "B       loc_FF0CCEA8\n"
    "loc_FF0CCE0C:\n"
            "B       loc_FF0CCEA8\n"
    "loc_FF0CCE10:\n"
            "B       loc_FF0CCFB4\n"
    "loc_FF0CCE14:\n"
            "B       loc_FF0CCFBC\n"
    "loc_FF0CCE18:\n"
            "B       loc_FF0CCFBC\n"
    "loc_FF0CCE1C:\n"
            "B       loc_FF0CCFBC\n"
    "loc_FF0CCE20:\n"
            "B       loc_FF0CCFBC\n"
    "loc_FF0CCE24:\n"
            "B       loc_FF0CCFC4\n"
    "loc_FF0CCE28:\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE2C:\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE30:\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE34:\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE38:\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE3C:\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE40:\n"
            "B       loc_FF0CCE98\n"
    "loc_FF0CCE44:\n"
            "B       loc_FF0CCEA0\n"
    "loc_FF0CCE48:\n"
            "B       loc_FF0CCEA0\n"
    "loc_FF0CCE4C:\n"
            "B       loc_FF0CCEA0\n"
    "loc_FF0CCE50:\n"
            "B       loc_FF0CCEB4\n"
    "loc_FF0CCE54:\n"
            "B       loc_FF0CCEB4\n"
    "loc_FF0CCE58:\n"
            "B       loc_FF0CCEBC\n"
    "loc_FF0CCE5C:\n"
            "B       loc_FF0CCEF4\n"
    "loc_FF0CCE60:\n"
            "B       loc_FF0CCF2C\n"
    "loc_FF0CCE64:\n"
            "B       loc_FF0CCF64\n"
    "loc_FF0CCE68:\n"
            "B       loc_FF0CCF9C\n"
    "loc_FF0CCE6C:\n"
            "B       loc_FF0CCF9C\n"
    "loc_FF0CCE70:\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE74:\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE78:\n"
            "B       loc_FF0CCFA4\n"
    "loc_FF0CCE7C:\n"
            "B       loc_FF0CCFAC\n"
    "loc_FF0CCE80:\n"
            "BL      sub_FF0C7FBC\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE88:\n"
            "BL      sub_FF0C8300\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE90:\n"
            "BL      sub_FF0C856C\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCE98:\n"
            "BL      sub_FF0C8864\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCEA0:\n"
            "BL      sub_FF0C8A80\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCEA8:\n" // 10, 11
            // PATCH
    		//"BL      sub_FF0C8F84\n"
    		"BL      sub_FF0C8F84_my\n"

    		"MOV     R8, #0\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCEB4:\n"
            "BL      sub_FF0C9158\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCEBC:\n"
            "LDRH    R1, [R0,#4]\n"
            "STRH    R1, [SP,#0x1C]\n"
            "LDRH    R1, [R4,#2]\n"
            "STRH    R1, [SP,#0x1E]\n"
            "LDRH    R1, [R4,#4]\n"
            "STRH    R1, [SP,#0x20]\n"
            "LDRH    R1, [R4,#6]\n"
            "STRH    R1, [SP,#0x22]\n"
            "LDRH    R1, [R0,#0xC]\n"
            "STRH    R1, [SP,#0x24]\n"
            "LDRH    R1, [R4,#0xA]\n"
            "STRH    R1, [SP,#0x26]\n"
            "BL      sub_FF0CE08C\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCEF4:\n"
            "LDRH    R1, [R0,#4]\n"
            "STRH    R1, [SP,#0x1C]\n"
            "LDRH    R1, [R4,#2]\n"
            "STRH    R1, [SP,#0x1E]\n"
            "LDRH    R1, [R4,#4]\n"
            "STRH    R1, [SP,#0x20]\n"
            "LDRH    R1, [R4,#6]\n"
            "STRH    R1, [SP,#0x22]\n"
            "LDRH    R1, [R4,#8]\n"
            "STRH    R1, [SP,#0x24]\n"
            "LDRH    R1, [R4,#0xA]\n"
            "STRH    R1, [SP,#0x26]\n"
            "BL      sub_FF0CE1FC\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCF2C:\n"
            "LDRH    R1, [R4]\n"
            "STRH    R1, [SP,#0x1C]\n"
            "LDRH    R1, [R0,#6]\n"
            "STRH    R1, [SP,#0x1E]\n"
            "LDRH    R1, [R4,#4]\n"
            "STRH    R1, [SP,#0x20]\n"
            "LDRH    R1, [R4,#6]\n"
            "STRH    R1, [SP,#0x22]\n"
            "LDRH    R1, [R4,#8]\n"
            "STRH    R1, [SP,#0x24]\n"
            "LDRH    R1, [R4,#0xA]\n"
            "STRH    R1, [SP,#0x26]\n"
            "BL      sub_FF0CE2B0\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCF64:\n"
            "LDRH    R1, [R4]\n"
            "STRH    R1, [SP,#0x1C]\n"
            "LDRH    R1, [R4,#2]\n"
            "STRH    R1, [SP,#0x1E]\n"
            "LDRH    R1, [R4,#4]\n"
            "STRH    R1, [SP,#0x20]\n"
            "LDRH    R1, [R4,#6]\n"
            "STRH    R1, [SP,#0x22]\n"
            "LDRH    R1, [R0,#0xC]\n"
            "STRH    R1, [SP,#0x24]\n"
            "LDRH    R1, [R4,#0xA]\n"
            "STRH    R1, [SP,#0x26]\n"
            "BL      sub_FF0CE358\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCF9C:\n"
            "BL      sub_FF0C96E8\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCFA4:\n"
            "BL      sub_FF0C9F50\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCFAC:\n"
            "BL      sub_FF0CA4C4\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCFB4:\n"
            "BL      sub_FF0CA6EC\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCFBC:\n"
            "BL      sub_FF0CA8AC\n"
            "B       loc_FF0CCFC8\n"
    "loc_FF0CCFC4:\n"
            "BL      sub_FF0CAA14\n"
    "loc_FF0CCFC8:\n"
            "LDR     R0, [SP,#0x28]\n"
            "LDR     R1, [R0,#0x7C]\n"
            "LDR     R2, [R0,#0x90]\n"
            "LDR     R3, [R0,#0x8C]\n"
    "loc_FF0CCFD8:\n"
            "ADD     R0, R0, #4\n"
            "BLX     R3\n"
    "loc_FF0CCFE0:\n"
            "LDR     R0, [SP,#0x28]\n"
            "LDR     R0, [R0]\n"
            "CMP     R0, #0x10\n"
            "BEQ     loc_FF0CD018\n"
            "BGT     loc_FF0CD008\n"
            "CMP     R0, #1\n"
            "CMPNE   R0, #4\n"
            "CMPNE   R0, #0xE\n"
            "BNE     loc_FF0CD04C\n"
            "B       loc_FF0CD018\n"
    "loc_FF0CD008:\n"
            "CMP     R0, #0x13\n"
            "CMPNE   R0, #0x17\n"
            "CMPNE   R0, #0x1A\n"
            "BNE     loc_FF0CD04C\n"
    "loc_FF0CD018:\n"
            "LDRSH   R0, [R4]\n"
            "CMN     R0, #0xC00\n"
            "LDRNESH R1, [R4,#8]\n"
            "CMNNE   R1, #0xC00\n"
            "STRNEH  R0, [SP,#0x1C]\n"
            "STRNEH  R1, [SP,#0x24]\n"
            "BNE     loc_FF0CD04C\n"
            "ADD     R0, SP, #0x10\n"
            "BL      sub_FF0CE608\n"
            "LDRH    R0, [SP,#0x10]\n"
            "STRH    R0, [SP,#0x1C]\n"
            "LDRH    R0, [SP,#0x18]\n"
            "STRH    R0, [SP,#0x24]\n"
    "loc_FF0CD04C:\n"
            "LDR     R0, [SP,#0x28]\n"
            "CMP     R8, #1\n"
            "BNE     loc_FF0CD09C\n"
            "LDR     R1, [R0,#0x7C]\n"
            "MOV     R2, #0xC\n"
            "ADD     R1, R1, R1,LSL#1\n"
            "ADD     R0, R0, R1,LSL#2\n"
            "SUB     R8, R0, #8\n"
            "LDR     R0, =0x62050\n"
            "ADD     R1, SP, #0x1C\n"
            "BL      sub_690174\n"
            "LDR     R0, =0x6205C\n"
            "MOV     R2, #0xC\n"
            "ADD     R1, SP, #0x1C\n"
            "BL      sub_690174\n"
            "LDR     R0, =0x62068\n"
            "MOV     R2, #0xC\n"
            "MOV     R1, R8\n"
            "BL      sub_690174\n"
            "B       loc_FF0CD114\n"
    "loc_FF0CD09C:\n"
            "LDR     R0, [R0]\n"
            "MOV     R3, #1\n"
            "CMP     R0, #0xB\n"
            "BNE     loc_FF0CD0E0\n"
            "MOV     R2, #0\n"
            "STRD    R2, [SP]\n"
            "MOV     R2, R3\n"
            "MOV     R1, R3\n"
            "MOV     R0, #0\n"
            "BL      sub_FF0C7D90\n"
            "MOV     R3, #1\n"
            "MOV     R2, #0\n"
            "STRD    R2, [SP]\n"
            "MOV     R2, R3\n"
            "MOV     R1, R3\n"
            "MOV     R0, #0\n"
            "B       loc_FF0CD110\n"
    "loc_FF0CD0E0:\n"
            "MOV     R2, #1\n"
            "STRD    R2, [SP]\n"
            "MOV     R3, R2\n"
            "MOV     R1, R2\n"
            "MOV     R0, R2\n"
            "BL      sub_FF0C7D90\n"
            "MOV     R3, #1\n"
            "MOV     R2, R3\n"
            "MOV     R1, R3\n"
            "MOV     R0, R3\n"
            "STR     R3, [SP]\n"
            "STR     R3, [SP,#4]\n"
    "loc_FF0CD110:\n"
            "BL      sub_FF0C7F08\n"
    "loc_FF0CD114:\n"
            "LDR     R0, [SP,#0x28]\n"
            "BL      sub_FF0CDFF8\n"
            "B       loc_FF0CCAAC\n"

    );
}

//** sub_FF0C8F84_my @ 0xFF0C8F84
void __attribute__((naked,noinline)) sub_FF0C8F84_my() {
    asm volatile(
            "STMFD   SP!, {R4-R8,LR}\n"
            "LDR     R7, =0x502C\n"
            "MOV     R4, R0\n"
            "LDR     R0, [R7,#0x1C]\n"
            "MOV     R1, #0x3E \n"
            "BL      sub_68BB84\n"
            "MOV     R2, #0\n"
            "LDRSH   R0, [R4,#4]\n"
            "MOV     R1, R2\n"
            "BL      sub_FF0C7A08\n"
            "MOV     R6, R0\n"
            "LDRSH   R0, [R4,#6]\n"
            "BL      sub_FF0C7BBC\n"
            "LDRSH   R0, [R4,#8]\n"
            "BL      sub_FF0C7C14\n"
            "LDRSH   R0, [R4,#0xA]\n"
            "BL      sub_FF0C7C6C\n"
            "LDRSH   R0, [R4,#0xC]\n"
            "MOV     R1, #0\n"
            "BL      sub_FF0C7CC4\n"
            "MOV     R5, R0\n"
            "LDR     R0, [R4]\n"
            "LDR     R8, =0x62068\n"
            "CMP     R0, #0xB\n"
            "MOVEQ   R6, #0\n"
            "MOVEQ   R5, R6\n"
            "BEQ     loc_FF0C9018\n"
            "CMP     R6, #1\n"
            "BNE     loc_FF0C9018\n"
            "LDRSH   R0, [R4,#4]\n"
            "LDR     R1, =0xFF0C7960\n"
            "MOV     R2, #2\n"
            "BL      sub_FF1DC718\n"
            "STRH    R0, [R4,#4]\n"
            "MOV     R0, #0\n"
            "STR     R0, [R7,#0x28]\n"
            "B       loc_FF0C9020\n"
    "loc_FF0C9018:\n"
            "LDRH    R0, [R8]\n"
            "STRH    R0, [R4,#4]\n"
    "loc_FF0C9020:\n"
            "CMP     R5, #1\n"
            "LDRNEH  R0, [R8,#8]\n"
            "BNE     loc_FF0C903C\n"
            "LDRSH   R0, [R4,#0xC]\n"
            "LDR     R1, =0xFF0C79E4\n"
            "MOV     R2, #0x20 \n"
            "BL      sub_FF0CE048\n"
    "loc_FF0C903C:\n"
            "STRH    R0, [R4,#0xC]\n"
            "LDRSH   R0, [R4,#6]\n"
    // PATCH
            //"BL      sub_FF0B657C\n"
    		"BL      sub_FF0B657C_my\n"

            "LDRSH   R0, [R4,#8]\n"
            "MOV     R1, #1\n"
            "BL      sub_FF0B6DD0\n"
            "MOV     R1, #0\n"
            "ADD     R0, R4, #8\n"
            "BL      sub_FF0B6E58\n"
            "LDRSH   R0, [R4,#0xE]\n"
            "BL      sub_FF0C1BCC\n"
            "LDR     R4, =0xBB8\n"
            "CMP     R6, #1\n"
            "BNE     loc_FF0C9094\n"
            "LDR     R0, [R7,#0x1C]\n"
            "MOV     R2, R4\n"
            "MOV     R1, #2\n"
            "BL      sub_68BA90\n"
            "TST     R0, #1\n"
            "LDRNE   R0, =0xFF0C81AC \n"
            "MOVNE   R1, #0x820\n"
            "BLNE    _DebugAssert \n"
    "loc_FF0C9094:\n"
            "CMP     R5, #1\n"
            "LDMNEFD SP!, {R4-R8,PC}\n"
            "LDR     R0, [R7,#0x1C]\n"
            "MOV     R2, R4\n"
            "MOV     R1, #0x20 \n"
            "BL      sub_68BA90\n"
            "TST     R0, #1\n"
            "LDMEQFD SP!, {R4-R8,PC}\n"
            "LDMFD   SP!, {R4-R8,LR}\n"
            "LDR     R1, =0x825\n"
            "LDR     R0, =0xFF0C81AC \n"
            "B       _DebugAssert \n"

    );
}

//** sub_FF0B657C_my @ 0xFF0B657C
void __attribute__((naked,noinline)) sub_FF0B657C_my() {
    asm volatile(
            "STMFD   SP!, {R4-R6,LR}\n"
            "LDR     R5, =0x4C98\n"
            "MOV     R4, R0\n"
            "LDR     R0, [R5,#4]\n"
            "CMP     R0, #1\n"
            "MOVNE   R1, #0x154\n"
            "LDRNE   R0, =0xFF0B63B4 \n"
            "BLNE    _DebugAssert \n"
            "CMN     R4, #0xC00\n"
            "LDREQSH R4, [R5,#2]\n"
            "CMN     R4, #0xC00\n"
            "LDREQ   R1, =0x15A\n"
            "LDREQ   R0, =0xFF0B63B4 \n"
            "STRH    R4, [R5,#2]\n"
            "BLEQ    _DebugAssert \n"
            "MOV     R0, R4\n"
    //PATCH BEGIN
            //"BL      sub_FF2B4AF4 \n"
            "BL     apex2us\n"
    //PATCH END
            "MOV     R4, R0\n"
            "BL      sub_FF139E98\n"
            "MOV     R0, R4\n"
            "BL      sub_FF143808\n"
            "TST     R0, #1\n"
            "LDMEQFD SP!, {R4-R6,PC}\n"
            "LDMFD   SP!, {R4-R6,LR}\n"
            "LDR     R1, =0x15F\n"
            "LDR     R0, =0xFF0B63B4 \n"
            "B       _DebugAssert \n"
    		);
}
