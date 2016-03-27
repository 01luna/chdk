/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

//static long *nrflag = (long*)0xC910; // FFAB026C

static long *nrflag = (long*)0x5CB4;

#define PAUSE_FOR_FILE_COUNTER 150

#include "../../../generic/capt_seq.c"


int capt_seq_hook_set_nr_my(int orig)
{
 
	camera_info.state.shutter_open_time = _time((void*)0); 
    camera_info.state.shutter_open_tick_count = get_tick_count();

	// Firmware also tests for 3 and 7, meaning unknown, so we don't touch them
	if (orig!=NR_ON && orig!=NR_OFF)
		return orig;

	switch (conf.raw_nr){
	case NOISE_REDUCTION_OFF:
		return NR_OFF;
	case NOISE_REDUCTION_ON:
		return NR_ON;
	case NOISE_REDUCTION_AUTO_CANON: // leave it alone
	default: // shut up compiler 
		return orig;
	};
}


/*************************************************************/
//** capt_seq_task @ 0xFF881EB4 - 0xFF88218C, length=183
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x39504 \n"
"    LDR     R6, =0x2DB4 \n"

"loc_FF881EC0:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R6, #4] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF83A27C /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF881EEC \n"
"    LDR     R1, =0x48B \n"
"    LDR     R0, =0xFF8818B0 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF881EEC:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x24 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF882150 \n"
"    B       loc_FF881F90 \n"
"    B       loc_FF881F98 \n"
"    B       loc_FF881FF0 \n"
"    B       loc_FF882004 \n"
"    B       loc_FF881FFC \n"
"    B       loc_FF88200C \n"
"    B       loc_FF882014 \n"
"    B       loc_FF882020 \n"
"    B       loc_FF88203C \n"
"    B       loc_FF882004 \n"
"    B       loc_FF882044 \n"
"    B       loc_FF882050 \n"
"    B       loc_FF882058 \n"
"    B       loc_FF882060 \n"
"    B       loc_FF882068 \n"
"    B       loc_FF882070 \n"
"    B       loc_FF882078 \n"
"    B       loc_FF882080 \n"
"    B       loc_FF882088 \n"
"    B       loc_FF882090 \n"
"    B       loc_FF882098 \n"
"    B       loc_FF8820A0 \n"
"    B       loc_FF8820A8 \n"
"    B       loc_FF8820B4 \n"
"    B       loc_FF8820BC \n"
"    B       loc_FF8820C8 \n"
"    B       loc_FF8820D0 \n"
"    B       loc_FF8820D8 \n"
"    B       loc_FF8820E0 \n"
"    B       loc_FF8820E8 \n"
"    B       loc_FF8820F0 \n"
"    B       loc_FF8820F8 \n"
"    B       loc_FF882104 \n"
"    B       loc_FF88210C \n"
"    B       loc_FF882118 \n"
"    B       loc_FF88215C \n"

"loc_FF881F90:\n"
"    BL      sub_FF882718 \n"
"    BL    shooting_expo_param_override\n"
"    B       loc_FF882018 \n"

"loc_FF881F98:\n"
"    LDR     R4, [R0, #0x10] \n"
"    BL      sub_FF883BA4 \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF883BFC \n"
"    LDR     R0, =0x10F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x24 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x28 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF98C47C_my \n"  // --> Patched. Old value = 0xFF98C47C.
"    BL    capt_seq_hook_raw_here \n"
"    MOV     R7, R0 \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF880050 \n"
"    TST     R7, #1 \n"
"    MOVEQ   R0, R4 \n"
"    BLEQ    sub_FF98BE48 \n"
"    B       loc_FF88215C \n"

"loc_FF881FF0:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF882A08 \n"
"    B       loc_FF88215C \n"

"loc_FF881FFC:\n"
"    BL      sub_FF8823B0 \n"
"    B       loc_FF88215C \n"

"loc_FF882004:\n"
"    BL      sub_FF8826F8 \n"
"    B       loc_FF88215C \n"

"loc_FF88200C:\n"
"    BL      sub_FF882700 \n"
"    B       loc_FF88215C \n"

"loc_FF882014:\n"
"    BL      sub_FF8828E0 \n"

"loc_FF882018:\n"
"    BL      sub_FF87FA30 \n"
"    B       loc_FF88215C \n"

"loc_FF882020:\n"
"    LDR     R4, [R0, #0x10] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF98C5CC \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #9 \n"
"    BL      sub_FF880050 \n"
"    B       loc_FF88215C \n"

"loc_FF88203C:\n"
"    BL      sub_FF882970 \n"
"    B       loc_FF882018 \n"

"loc_FF882044:\n"
"    LDR     R0, [R5, #0x50] \n"
"    BL      sub_FF882FDC \n"
"    B       loc_FF88215C \n"

"loc_FF882050:\n"
"    BL      sub_FF883384 \n"
"    B       loc_FF88215C \n"

"loc_FF882058:\n"
"    BL      sub_FF8833E8 \n"
"    B       loc_FF88215C \n"

"loc_FF882060:\n"
"    BL      sub_FF98B078 \n"
"    B       loc_FF88215C \n"

"loc_FF882068:\n"
"    BL      sub_FF98B2DC \n"
"    B       loc_FF88215C \n"

"loc_FF882070:\n"
"    BL      sub_FF98B398 \n"
"    B       loc_FF88215C \n"

"loc_FF882078:\n"
"    BL      sub_FF98B480 \n"
"    B       loc_FF88215C \n"

"loc_FF882080:\n"
"    BL      sub_FF98B554 \n"
"    B       loc_FF88215C \n"

"loc_FF882088:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF8820AC \n"

"loc_FF882090:\n"
"    BL      sub_FF98B97C \n"
"    B       loc_FF88215C \n"

"loc_FF882098:\n"
"    BL      sub_FF98BA10 \n"
"    B       loc_FF88215C \n"

"loc_FF8820A0:\n"
"    BL      sub_FF98BACC \n"
"    B       loc_FF88215C \n"

"loc_FF8820A8:\n"
"    MOV     R0, #1 \n"

"loc_FF8820AC:\n"
"    BL      sub_FF98B80C \n"
"    B       loc_FF88215C \n"

"loc_FF8820B4:\n"
"    BL      sub_FF882BDC \n"
"    B       loc_FF88215C \n"

"loc_FF8820BC:\n"
"    BL      sub_FF882C08 \n"
"    BL      sub_FF98D1A0 \n"
"    B       loc_FF88215C \n"

"loc_FF8820C8:\n"
"    BL      sub_FF98B6E0 \n"
"    B       loc_FF88215C \n"

"loc_FF8820D0:\n"
"    BL      sub_FF98B778 \n"
"    B       loc_FF88215C \n"

"loc_FF8820D8:\n"
"    BL      sub_FF98D26C \n"
"    B       loc_FF88215C \n"

"loc_FF8820E0:\n"
"    BL      sub_FF837BC8 \n"
"    B       loc_FF88215C \n"

"loc_FF8820E8:\n"
"    BL      sub_FF8858A0 \n"
"    B       loc_FF88215C \n"

"loc_FF8820F0:\n"
"    BL      sub_FF885914 \n"
"    B       loc_FF88215C \n"

"loc_FF8820F8:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF98BBF4 \n"
"    B       loc_FF88215C \n"

"loc_FF882104:\n"
"    BL      sub_FF98BC64 \n"
"    B       loc_FF88215C \n"

"loc_FF88210C:\n"
"    BL      sub_FF88597C \n"
"    BL      sub_FF885934 \n"
"    B       loc_FF88215C \n"

"loc_FF882118:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF98CCB4 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF98CDDC \n"
"    LDRH    R0, [R5, #0x98] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x4200 \n"
"    SUBNES  R1, R1, #0x2B \n"
"    BNE     loc_FF88215C \n"
"    BL      sub_FF885914 \n"
"    BL      sub_FF885F3C \n"
"    BL      sub_FF885DA4 \n"
"    B       loc_FF88215C \n"

"loc_FF882150:\n"
"    LDR     R1, =0x5EC \n"
"    LDR     R0, =0xFF8818B0 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF88215C:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R6] \n"
"    BL      sub_FF88C868 /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x117 \n"
"    LDREQ   R0, =0xFF8818B0 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R4, #8] \n"
"    B       loc_FF881EC0 \n"
);
}

/*************************************************************/
//** sub_FF98C47C_my @ 0xFF98C47C - 0xFF98C5C8, length=84
void __attribute__((naked,noinline)) sub_FF98C47C_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF887700 \n"
"    TST     R0, #1 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF98C5C8 \n"
"    LDR     R5, =0x39504 \n"
"    LDRH    R0, [R5, #0x96] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF98C538 \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF98C504 \n"
"    LDRH    R0, [R5, #0x94] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF98C538 \n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FF98C510 \n"
"    BL      sub_FF882CDC \n"
"    LDRH    R0, [R5, #0x96] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF98C538 \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF98C504 \n"
"    LDRH    R0, [R5, #0x94] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF98C538 \n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #2 \n"
"    BEQ     loc_FF98C534 \n"
"    B       loc_FF98C510 \n"

"loc_FF98C504:\n"
"    LDRH    R0, [R5, #0x94] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF98C538 \n"

"loc_FF98C510:\n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF98C538 \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF98C538 \n"
"    LDR     R0, [R4, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF98C538 \n"

"loc_FF98C534:\n"
"    BL      sub_FF98D2A4 \n"

"loc_FF98C538:\n"
"    BL      sub_FF98D26C \n"
"    BL      sub_FF882708 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF98BD50 \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF98C5C8 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF98C0F4 \n"
"    BL      sub_FF98CA8C \n"
"    MOV     R6, #1 \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF888D94 \n"
"    LDRH    R0, [R5] \n"
"    SUB     R1, R0, #0x8200 \n"
"    SUBS    R1, R1, #0x2E \n"
"    MOVNE   R0, R4 \n"
"    LDMNEFD SP!, {R3-R7,LR} \n"
"    BNE     sub_FFAE3934_my \n"  // --> Patched. Old value = 0xFFAE3934.
"    MOV     R2, #2 \n"
"    MOV     R1, SP \n"
"    ADD     R0, R2, #0x15C \n"
"    STR     R6, [SP] \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0xC5 \n"
"    LDRNE   R0, =0xFF98C658 /*'SsCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDRH    R0, [SP] \n"
"    CMP     R0, #1 \n"
"    MOVHI   R0, #0x1D \n"
"    STRHI   R6, [R4, #0xD8] \n"
"    BHI     loc_FF98C5C8 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R4, #0xD8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAE3934_my \n"  // --> Patched. Old value = 0xFFAE3934.

"loc_FF98C5C8:\n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** sub_FFAE3934_my @ 0xFFAE3934 - 0xFFAE3980, length=20
void __attribute__((naked,noinline)) sub_FFAE3934_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    MOV     R4, R0 \n"
"    MOV     R1, R0 \n"
"    LDR     R0, =0xFF98BE90 \n"
"    BL      sub_FF8BFAB4 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF98BDD0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF98C1A4 \n"
"    MOV     R7, R0 \n"
"    LDR     R1, =0xCEA8 \n"
"    MOV     R2, #4 \n"
"    MOV     R0, #0x8A \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x22F \n"
"    LDRNE   R0, =0xFFAE3B08 /*'SsStandardCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    BL      sub_FF884D50 \n"
"    BL      sub_FF98C3AC \n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDR     PC, =0xFFAE3984 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8CA794 - 0xFF8CAE60, length=436
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x24 \n"
"    LDR     R6, =0x453C \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x569B0 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x14 \n"
"    STR     R0, [SP, #0x10] \n"

"loc_FF8CA7B4:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x20 \n"
"    BL      sub_FF83A27C /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0x10] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8CA800 \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF8CA960 \n"
"    CMP     R0, #0x29 \n"
"    BEQ     loc_FF8CA8E8 \n"
"    ADD     R1, SP, #0x10 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8CA744 \n"

"loc_FF8CA800:\n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF8CA82C \n"
"    BL      sub_FF8CBC38 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF88C868 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x24 \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF8CA82C:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF8CA848 \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8CAE58 \n"

"loc_FF8CA848:\n"
"    CMP     R1, #0x27 \n"
"    BNE     loc_FF8CA898 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF88C89C /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8C62FC \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF97D2A4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF88C7A8 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1447 \n"
"    BNE     loc_FF8CA954 \n"

"loc_FF8CA884:\n"
"    LDR     R1, [SP, #0x20] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF8CAE58 \n"

"loc_FF8CA898:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF8CA8E0 \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF8CA744 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF88C89C /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8C630C \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF97E05C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF88C7A8 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8CA884 \n"
"    LDR     R1, =0x1451 \n"
"    B       loc_FF8CA954 \n"

"loc_FF8CA8E0:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF8CA8F8 \n"

"loc_FF8CA8E8:\n"
"    LDR     R0, [SP, #0x20] \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF8CA744 \n"
"    B       loc_FF8CA884 \n"

"loc_FF8CA8F8:\n"
"    CMP     R1, #0x2C \n"
"    BNE     loc_FF8CA910 \n"
"    BL      sub_FF8B7AA4 \n"
"    BL      sub_FF8B876C \n"
"    BL      sub_FF8B82D0 \n"
"    B       loc_FF8CA884 \n"

"loc_FF8CA910:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8CA960 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF88C89C /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF8C632C \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF8B7518 \n"
"    BL      sub_FF8B77A8 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF88C6C4 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8CA884 \n"
"    LDR     R1, =0x1479 \n"

"loc_FF8CA954:\n"
"    LDR     R0, =0xFF8C6A2C /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8CA884 \n"

"loc_FF8CA960:\n"
"    LDR     R0, [SP, #0x20] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF8CA9C8 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8C8E14 \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x20] \n"
"    BL      sub_FF8CBFD4 \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF8CAD44 \n"

"loc_FF8CA9C8:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF8CAAE8 \n"
"    ADD     R3, SP, #0x10 \n"
"    ADD     R2, SP, #4 \n"
"    ADD     R1, SP, #0x14 \n"
"    BL      sub_FF8C907C \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF8CAA84 \n"
"    LDR     R0, [SP, #0x20] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    ADD     R0, SP, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF8CAABC \n"

"loc_FF8CAA84:\n"
"    LDR     R0, [SP, #0x20] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF8CAAD0 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    ADD     R0, SP, #4 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x20] \n"
"    ADD     R2, SP, #4 \n"
"    ADD     R1, SP, #0x14 \n"
"    BL      sub_FF8CA490 \n"

"loc_FF8CAABC:\n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R2, [SP, #0x10] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF8CA6E4 \n"
"    B       loc_FF8CAD4C \n"

"loc_FF8CAAD0:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF8CAD4C \n"

"loc_FF8CAAE8:\n"
"    CMP     R1, #0x23 \n"
"    CMPNE   R1, #0x24 \n"
"    BNE     loc_FF8CAB34 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8C7EB4 \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x20] \n"
"    BL      sub_FF8C82C8 \n"
"    B       loc_FF8CAD4C \n"

"loc_FF8CAB34:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x27 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CABEC \n"
"    B       loc_FF8CABEC \n"
"    B       loc_FF8CABF4 \n"
"    B       loc_FF8CABFC \n"
"    B       loc_FF8CABFC \n"
"    B       loc_FF8CABFC \n"
"    B       loc_FF8CABEC \n"
"    B       loc_FF8CABF4 \n"
"    B       loc_FF8CABFC \n"
"    B       loc_FF8CABFC \n"
"    B       loc_FF8CAC14 \n"
"    B       loc_FF8CAC14 \n"
"    B       loc_FF8CAD20 \n"
"    B       loc_FF8CAD28 \n"
"    B       loc_FF8CAD28 \n"
"    B       loc_FF8CAD28 \n"
"    B       loc_FF8CAD28 \n"
"    B       loc_FF8CAD30 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CAC04 \n"
"    B       loc_FF8CAC0C \n"
"    B       loc_FF8CAC0C \n"
"    B       loc_FF8CAC20 \n"
"    B       loc_FF8CAC20 \n"
"    B       loc_FF8CAC28 \n"
"    B       loc_FF8CAC60 \n"
"    B       loc_FF8CAC98 \n"
"    B       loc_FF8CACD0 \n"
"    B       loc_FF8CAD08 \n"
"    B       loc_FF8CAD08 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CAD34 \n"
"    B       loc_FF8CAD10 \n"
"    B       loc_FF8CAD18 \n"

"loc_FF8CABEC:\n"
"    BL      sub_FF8C68B0 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CABF4:\n"
"    BL      sub_FF8C6B54 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CABFC:\n"
"    BL      sub_FF8C6D7C \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAC04:\n"
"    BL      sub_FF8C7054 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAC0C:\n"
"    BL      sub_FF8C726C \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAC14:\n"
"    BL      sub_FF8C75EC_my \n"  // --> Patched. Old value = 0xFF8C75EC.
"    MOV     R8, #0 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAC20:\n"
"    BL      sub_FF8C7734 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAC28:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    BL      sub_FF8CBCCC \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAC60:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    BL      sub_FF8CBDD4 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAC98:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    BL      sub_FF8CBE88 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CACD0:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    BL      sub_FF8CBF30 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAD08:\n"
"    BL      sub_FF8C7C8C \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAD10:\n"
"    BL      sub_FF8C83CC \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAD18:\n"
"    BL      sub_FF8C8674 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAD20:\n"
"    BL      sub_FF8C8854 \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAD28:\n"
"    BL      sub_FF8C8A9C \n"
"    B       loc_FF8CAD34 \n"

"loc_FF8CAD30:\n"
"    BL      sub_FF8C8C0C \n"

"loc_FF8CAD34:\n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF8CAD44:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF8CAD4C:\n"
"    LDR     R1, [SP, #0x20] \n"
"    LDR     R0, [R1] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF8CAD84 \n"
"    BGT     loc_FF8CAD74 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF8CAD94 \n"
"    B       loc_FF8CAD84 \n"

"loc_FF8CAD74:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF8CAD94 \n"

"loc_FF8CAD84:\n"
"    LDRH    R0, [R4] \n"
"    STRH    R0, [SP, #0x14] \n"
"    LDRH    R0, [R4, #8] \n"
"    STRH    R0, [SP, #0x1C] \n"

"loc_FF8CAD94:\n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8CADE0 \n"
"    LDR     R0, [R1, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R0, R0, R0, LSL#1 \n"
"    ADD     R0, R1, R0, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x569B0 \n"
"    ADD     R1, SP, #0x14 \n"
"    BL      sub_FFB8B798 \n"
"    LDR     R0, =0x569BC \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x14 \n"
"    BL      sub_FFB8B798 \n"
"    LDR     R0, =0x569C8 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_FFB8B798 \n"
"    B       loc_FF8CAE58 \n"

"loc_FF8CADE0:\n"
"    LDR     R0, [R1] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8CAE24 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8C6684 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8CAE54 \n"

"loc_FF8CAE24:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF8C6684 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF8CAE54:\n"
"    BL      sub_FF8C67FC \n"

"loc_FF8CAE58:\n"
"    LDR     R0, [SP, #0x20] \n"
"    BL      sub_FF8CBC38 \n"
"    B       loc_FF8CA7B4 \n"
);
}

/*************************************************************/
//** sub_FF8C75EC_my @ 0xFF8C75EC - 0xFF8C76B4, length=51
void __attribute__((naked,noinline)) sub_FF8C75EC_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x453C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_FF88C89C /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF8C638C \n"
"    MOV     R5, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8C64DC \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8C6534 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8C658C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8C65E4 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #0xE] \n"
"    BL      sub_FF8CBC68 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x569C8 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R5, #0 \n"
"    MOVEQ   R6, R5 \n"
"    BEQ     loc_FF8C7688 \n"
"    CMP     R5, #1 \n"
"    BNE     loc_FF8C7688 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8C62EC \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF97D5C8 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8C7690 \n"

"loc_FF8C7688:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8C7690:\n"
"    CMP     R6, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8C76AC \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF8C6370 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8CBC88 \n"

"loc_FF8C76AC:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8B7814_my \n"  // --> Patched. Old value = 0xFF8B7814.
"    LDR     PC, =0xFF8C76B8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8B7814_my @ 0xFF8B7814 - 0xFF8B7854, length=17
void __attribute__((naked,noinline)) sub_FF8B7814_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x41F0 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0x14D \n"
"    LDRNE   R0, =0xFF8B764C /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x153 \n"
"    LDREQ   R0, =0xFF8B764C /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF8B7858 \n"  // Continue in firmware
);
}