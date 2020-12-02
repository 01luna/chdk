/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
//extern void task_MovieRecord();
extern void task_ExpDrv();
//extern void task_FileWrite();

/*----------------------------------------------------------------------
	spytask
-----------------------------------------------------------------------*/
void spytask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;
	core_spytask();
}

/*----------------------------------------------------------------------
	CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
	_CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

///*----------------------------------------------------------------------
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
short *jog_position;

#define GREEN_LED       0xC022D1FC
#define AF_LED          0xC022D034
//debug use only

int debug_blink(int save_R0) {
	int i;
	*((volatile int *) GREEN_LED) = 0x93d800; // Turn on LED
	for (i=0; i<800000; i++) // Wait a while
		{
    		asm volatile ( "nop\n" );
		}

	*((volatile int *) GREEN_LED) = 0x83dc00; // Turn off LED
	for (i=0; i<800000; i++) // Wait a while
		{
    		asm volatile ( "nop\n" );
		}
	return save_R0;
};

void __attribute__((naked,noinline)) my_blinker(int n) {
	asm volatile (
      "            STMFD   SP!, {R0-R9,LR}\n"
);
	int i, j;
	for (j=0; j<n; j++)
	{
		*((volatile int *) GREEN_LED) = 0x93d800; // Turn on LED
		for (i=0; i<0x200000; i++) { asm volatile ( "nop \n" ); }

		*((volatile int *) GREEN_LED) = 0x83dc00; // Turn off LED
		for (i=0; i<0x400000; i++) { asm volatile ( "nop \n" ); }
	}
	for (i=0; i<0x900000; i++) { asm volatile ( "nop \n" ); }
	asm volatile (
      "            LDMFD   SP!, {R0-R9,PC}\n"
	);
}

/*----------------------------------------------------------------------
	boot()

	Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//** boot @ 0xFF02000C - 0xFF02017C, length=93
void __attribute__((naked,noinline)) boot() {
asm volatile (
"    LDR     R1, =0xC0410000 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x78 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    MOV     R1, #0 \n"
"    MCR     p15, 0, R1, c7, c10, 4 \n"
"    MCR     p15, 0, R1, c7, c5 \n"
"    MCR     p15, 0, R1, c7, c6 \n"
"    MOV     R0, #0x3D \n"
"    MCR     p15, 0, R0, c6, c0 \n"
"    MOV     R0, #0xC000002F \n"
"    MCR     p15, 0, R0, c6, c1 \n"
"    MOV     R0, #0x37 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000037 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF00002F \n"
"    MCR     p15, 0, R0, c6, c5 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0, 1 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c3, c0 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 2 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 3 \n"
"    MRC     p15, 0, R0, c1, c0 \n"
"    ORR     R0, R0, #0x1000 \n"
"    ORR     R0, R0, #4 \n"
"    ORR     R0, R0, #1 \n"
"    MCR     p15, 0, R0, c1, c0 \n"
"    MOV     R1, #0x80000006 \n"
"    MCR     p15, 0, R1, c9, c1 \n"
"    MOV     R1, #6 \n"
"    MCR     p15, 0, R1, c9, c1, 1 \n"
"    MRC     p15, 0, R1, c1, c0 \n"
"    ORR     R1, R1, #0x50000 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    LDR     R2, =0xC0200000 \n"
"    MOV     R1, #1 \n"
"    STR     R1, [R2, #0x10C] \n"
"    MVN     R1, #0 \n"
"    STR     R1, [R2, #0xC] \n"
"    STR     R1, [R2, #0x1C] \n"
"    STR     R1, [R2, #0x2C] \n"
"    STR     R1, [R2, #0x3C] \n"
"    STR     R1, [R2, #0x4C] \n"
"    STR     R1, [R2, #0x5C] \n"
"    STR     R1, [R2, #0x6C] \n"
"    STR     R1, [R2, #0x7C] \n"
"    STR     R1, [R2, #0x8C] \n"
"    STR     R1, [R2, #0x9C] \n"
"    STR     R1, [R2, #0xAC] \n"
"    STR     R1, [R2, #0xBC] \n"
"    STR     R1, [R2, #0xCC] \n"
"    STR     R1, [R2, #0xDC] \n"
"    STR     R1, [R2, #0xEC] \n"
"    STR     R1, [R2, #0xFC] \n"
"    LDR     R1, =0xC0400008 \n"
"    LDR     R2, =0x430005 \n"
"    STR     R2, [R1] \n"
"    MOV     R1, #1 \n"
"    LDR     R2, =0xC0243100 \n"
"    STR     R2, [R1] \n"
"    LDR     R2, =0xC0242010 \n"
"    LDR     R1, [R2] \n"
"    ORR     R1, R1, #1 \n"
"    STR     R1, [R2] \n"
"    LDR     R0, =0xFF8C92E8 \n"
"    LDR     R1, =0x6B1000 \n"
"    LDR     R3, =0x6E28C6 \n"

"loc_FF02013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF02013C \n"
"    LDR     R0, =0xFF8B1358 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x19890 \n"

"loc_FF020158:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF020158 \n"
"    LDR     R1, =0x2FF248 \n"
"    MOV     R2, #0 \n"

"loc_FF020170:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF020170 \n"
/* Install task hooks via 0x193x is not possible with this new dryos version
   So the below code patches the CreateTask function in RAM to install our
   hook -- ERR99
*/
// Install CreateTask patch
"    LDR     R0, =patch_CreateTask\n"   // Patch data
"    LDM     R0, {R1,R2}\n"             // Get two patch instructions
"    LDR     R0, =hook_CreateTask\n"    // Address to patch
"    STM     R0, {R1,R2}\n"             // Store patch instructions

"    B       sub_FF0203C4_my \n"  // --> Patched. Old value = 0xFF0203C4.

"patch_CreateTask:\n"
"    LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my\n"
);
}

/*************************************************************/
//** CreateTask_my @ 0x006B5658 - 0x006B565C, length=2
void __attribute__((naked,noinline)) CreateTask_my() {
asm volatile (
"    STMFD   SP!, {R0}\n"
//R3 = Pointer to task function to create

/*** INSTALL capt_seq_task() hook ***/
"    LDR     R0, =task_CaptSeq\n"       // DryOS original code function ptr.
"    CMP     R0, R3\n"                  // is the given taskptr equal to our searched function?
"    LDREQ   R3, =capt_seq_task\n"      // if so replace with our task function base ptr.
"    BEQ     exitHook\n"                // below compares not necessary if this check has found something.

/*** INSTALL exp_drv_task() hook ***/
// hook not fully implemented in capt_seq.c - reyalp
/*
"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =exp_drv_task\n"
"    BEQ     exitHook\n"
*/

/*** INSTALL filewrite() hook ***/
//"    LDR     R0, =task_FileWrite\n"
//"    CMP     R0, R3\n"
//"    LDREQ   R3, =filewritetask\n"
//"    BEQ     exitHook\n"

/*** INSTALL JogDial() hook ***/
// was commented out in boot.c from http://chdk.setepontos.com/index.php?topic=12418.msg123489#msg123489
// but not in codegen file - reyalp
//"    LDR     R0, =task_RotaryEncoder\n"
//"    CMP     R0, R3\n"
//"    LDREQ   R3, =JogDial_task_my\n"
//"    BEQ     exitHook\n"

/*** INSTALL movie_record_task() hook ***/
"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =movie_record_task\n"
"    BEQ     exitHook\n"

/*** INSTALL liveimage_task() hook ***/
"    LDR     R0, =task_LiveImageTask\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =liveimage_task\n"
"    BEQ     exitHook\n"

/*** INSTALL init_file_modules_task() hook ***/
"    LDR     R0, =task_InitFileModules\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =init_file_modules_task\n"

"exitHook:\n" 
// restore overwritten registers
"    LDMFD   SP!, {R0}\n"
// Execute overwritten instructions from original code, then jump to firmware
"    STMFD   SP!, {R1-R9,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     PC, =0x006B5660 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF0203C4_my @ 0xFF0203C4 - 0xFF020434, length=29
void __attribute__((naked,noinline)) sub_FF0203C4_my() {

    //Replacement of sub_ for correct power-on.
    //(short press on ON/OFF button = playback mode, long press = record mode)
    // see sub_ff02bbc0 and sub_ff073c68 (100c)
    // NOTE this might break other startup modes (such as NFC)
    *(int*)(0x2cf4+0x8) = (*(int*)0xc022f48c) & 0x80000 ? 0x400000 : 0x200000;

asm volatile (
"    LDR     R0, =0xFF02043C \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF020474 \n"

"loc_FF0203D0:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF0203D0 \n"
"    LDR     R0, =0xFF020474 \n"
"    MOV     R1, #0x1C0 \n"
"    LDR     R3, =0xFF02065C \n"

"loc_FF0203EC:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF0203EC \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x3A8 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF020420:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF020420 \n"
"    B       sub_FF0228D4_my \n"  // --> Patched. Old value = 0xFF0228D4.
);
}

/*************************************************************/
//** sub_FF0228D4_my @ 0xFF0228D4 - 0xFF0229E0, length=68
void __attribute__((naked,noinline)) sub_FF0228D4_my() {
asm volatile (
"    LDR     R1, =0x1A5C \n"
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x7C \n"
"    MOV     R0, #0x80000 \n"
"    STR     R0, [R1] \n"
"    LDR     R0, =0x40D42F80 \n"
"    LDR     R1, =0x1A60 \n"
"    STR     R0, [R1] \n"
"    LDR     R1, =0x1A64 \n"
"    ADD     R0, R0, #0x2000 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x78 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_006DABD4 \n"
"    MOV     R0, #0xA0000 \n"
"    STR     R0, [SP, #8] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x2FF248 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x56346C \n"
"    STR     R0, [SP, #0xC] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0x10] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x1C] \n"
"    MOV     R0, #0x98 \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x1E8 \n"
"    STR     R2, [SP, #0x14] \n"
"    STR     R0, [SP, #0x24] \n"
"    LDR     R1, =0x56E000 \n"
"    MOV     R0, #0xFA \n"
"    STR     R0, [SP, #0x28] \n"
"    MOV     R0, #0xB6 \n"
"    STR     R1, [SP, #4] \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, #0x85 \n"
"    STR     R0, [SP, #0x30] \n"
"    MOV     R0, #0x40 \n"
"    STR     R0, [SP, #0x34] \n"
"    MOV     R0, #4 \n"
"    STR     R0, [SP, #0x38] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP, #0x3C] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0x1000 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x100 \n"
"    STR     R0, [SP, #0x68] \n"
"    MOV     R0, #0x2000 \n"
"    STR     R1, [SP, #0x18] \n"
"    STR     R0, [SP, #0x6C] \n"
"    LDR     R1, =sub_FF024704_my \n"  // --> Patched. Old value = 0xFF024704.
"    MOV     R2, #0 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_006B1BC8 \n"
"    ADD     SP, SP, #0x7C \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF024704_my @ 0xFF024704 - 0xFF02479C, length=39
void __attribute__((naked,noinline)) sub_FF024704_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R4, =0xFF0247C0 /*'/_term'*/ \n"
"    BL      sub_FF020858 \n"
"    LDR     R1, =0x1A5C \n"
"    LDR     R0, =0x19F0 \n"
"    LDR     R1, [R1] \n"
"    LDR     R0, [R0] \n"
"    ADD     R1, R1, #0x10 \n"
"    CMP     R0, R1 \n"
"    LDRCC   R0, =0xFF0247D0 /*'USER_MEM size checking'*/ \n"
"    BLCC    _err_init_task \n"
"    BL      sub_FF0234E0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0247E8 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF0224E8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0247F0 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF0225C8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF024800 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF022100 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF024814 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF024D70 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF024820 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF0210A8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF02482C /*'extlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF027A44_my \n"  // --> Patched. Old value = 0xFF027A44.
);
}

/*************************************************************/
//** sub_FF027A44_my @ 0xFF027A44 - 0xFF027AB4, length=29
void __attribute__((naked,noinline)) sub_FF027A44_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_FF033F14 \n"
"    BL      sub_FF037D3C \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF027A68 \n"
"    BL      sub_FF02D16C /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF027A6C \n"

"loc_FF027A68:\n"
"    MOV     R0, #0 \n"

"loc_FF027A6C:\n"
"    BL      sub_FF02BBC0_my \n"  // --> Patched. Old value = 0xFF02BBC0.
"    CMP     R0, #0 \n"
"    BNE     loc_FF027A80 \n"
"    BL      sub_FF02B3A4 \n"

"loc_FF027A7C:\n"
"    B       loc_FF027A7C \n"

"loc_FF027A80:\n"
"    BL      sub_006B8AD0 \n"
"    LDR     R1, =0x60E000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF03822C \n"
"    BL      sub_006B8E18 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF0279DC.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF027AC0 /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF02BBC0_my @ 0xFF02BBC0 - 0xFF02BC6C, length=44
void __attribute__((naked,noinline)) sub_FF02BBC0_my() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    MOV     R4, #0 \n"
"    MOV     R10, R0 \n"
"    MOV     R5, R4 \n"
"    MOV     R7, R4 \n"
//"  BL      _sub_FF073C60 \n"  // --> Nullsub call removed.
"    MOV     R0, #0x47 \n"
"    BL      sub_FF071738 \n"
"    MOV     R6, #1 \n"
"    BIC     R8, R6, R0 \n"
"    MOV     R0, #0x48 \n"
"    BL      sub_FF071738 \n"
"    BIC     R9, R6, R0 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF073C40 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF02BC10 \n"
"    MOV     R0, #0x49 \n"
"    BL      sub_FF071738 \n"
"    BIC     R5, R6, R0 \n"

"loc_FF02BC10:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF073C40 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF02BC2C \n"
"    MOV     R0, #0x4E \n"
"    BL      sub_FF071738 \n"
"    BIC     R4, R6, R0 \n"

"loc_FF02BC2C:\n"
"    CMP     R10, #0 \n"
"    BEQ     loc_FF02BC44 \n"
"    ORR     R0, R8, R9 \n"
"    ORR     R0, R0, R5 \n"
"    ORRS    R0, R0, R4 \n"
"    BEQ     loc_FF02BC6C \n"

"loc_FF02BC44:\n"
"    BL      sub_FF037D3C \n"
"    MOV     R2, R0 \n"
"    MOV     R3, R5 \n"
"    MOV     R1, R9 \n"
"    MOV     R0, R8 \n"
"    STR     R4, [SP, #4] \n"
"    STR     R7, [SP] \n"
//"  BL      _sub_FF073C68 \n"  // Disable StartUpChecks
//"  BL      _sub_FF073C64 \n"  // --> Nullsub call removed.
"    MOV     R0, #1 \n"

"loc_FF02BC6C:\n"
"    LDMFD   SP!, {R2-R10,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF0279DC - 0xFF027A40, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF022C84 \n"
"    BL      sub_FF02C090 \n"
"    BL      sub_FF02B350 \n"
//"  BL      _sub_FF074CE0 \n"  // --> Nullsub call removed.
"    BL      sub_FF037F58 \n"
//"  BL      _sub_FF037E18 \n"  // load DISKBOOT.BIN
"    BL      sub_FF0380B8 \n"
"    BL      sub_FF038300 \n"
//"  BL      _sub_FF0380AC \n"  // --> Nullsub call removed.
"    BL      sub_FF037F94 \n"
"    BL      sub_FF033E4C \n"
"    BL      sub_FF038308 \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF02BA68.
"    BL      init_required_fw_features\n" // added
"    BL      sub_FF0314D8 \n"
"    BL      sub_FF0C74B4 \n"
"    BL      sub_FF028E34 \n"
"    BL      sub_FF02ACC8 \n"
"    BL      sub_FF037B24 \n"
"    BL      sub_FF02B304 \n"
"    BL      sub_FF02AC5C \n"
//"  BL      _sub_FF0380B0 \n"  // --> Nullsub call removed.
"    BL      sub_FF029C10 \n"
"    BL      sub_FF02AC18 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF022DD4 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF02BA68 - 0xFF02BAB0, length=19
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    BL      sub_FF036D84 \n"
"    BL      sub_FF02D0A4 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BLEQ    sub_FF036CEC /*_OpLog.Start_FW*/ \n"
"    LDR     R4, =0x1CA0 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF02BAAC \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF02BA34.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF02BC80 /*'PhySw'*/ \n"
"    BL      sub_006B7BE0 /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF02BAAC:\n"
"    LDMFD   SP!, {R3-R5,LR} \n"
"    B       sub_FF074BC4 \n"
);
}

// Workaround for cards becoming read-only in camera when diskboot'ing to playback mode.
// The following flag is checked by the function that calls WriteSDCard (sub_ff0300dc)
// See the porting thread for related discussions. https://chdk.setepontos.com/index.php?topic=12418
void fix_writable_media_flag() {
    *(int*)0x1d60 = 1;
}

/*************************************************************/
//** init_file_modules_task @ 0xFF061C70 - 0xFF061CA4, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF0B0B54 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF0B0B84 \n"
"    BL      fix_writable_media_flag\n" // port specific hack
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0 \n"
"    B       _PostLogicalEventToUI \n"
);
}

/*************************************************************/
//** JogDial_task_my @ 0xFF0748A0 - 0xFF074BC0, length=201
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R4-R11,LR} \n"
"    SUB     SP, SP, #0x24 \n"
"    BL      sub_FF074C04 \n"
"    LDR     R3, =0x2D20 \n"
"    LDR     R6, =0xFF63F04C \n"
"    MOV     R0, #0 \n"
"    ADD     R11, SP, #0xC \n"
"    ADD     R9, SP, #0x10 \n"

// Save pointer for kbd.c routine
"    LDR     R2, =jog_position \n"
"    STR     R9, [R2] \n"

"    MOV     R10, R0 \n"

"loc_FF0748C4:\n"
"    ADD     R1, SP, #0x18 \n"
"    ADD     R12, R1, R0, LSL#1 \n"
"    ADD     R2, SP, #0x14 \n"
"    STRH    R10, [R12] \n"
"    ADD     R12, R2, R0, LSL#1 \n"
"    STRH    R10, [R12] \n"
"    STR     R10, [R9, R0, LSL#2] \n"
"    STR     R10, [R11, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #1 \n"
"    BLT     loc_FF0748C4 \n"

"loc_FF0748F0:\n"
"    LDR     R0, =0x2D20 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R0, #8] \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_006B849C /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x229 \n"
"    LDRNE   R1, =0xFF074B6C /*'RotaryEncoder.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    AND     R4, R0, #0xFF \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x100 \n"
"    BEQ     loc_FF074968 \n"
"    CMP     R0, #0x200 \n"
"    BEQ     loc_FF0749A0 \n"
"    CMP     R0, #0x300 \n"
"    BNE     loc_FF0748F0 \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R2, =0x296 \n"
"    LDREQ   R1, =0xFF074B6C /*'RotaryEncoder.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    ADD     R0, R6, R0, LSL#2 \n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF02BAB4 \n"
"    STR     R10, [R9, R4, LSL#2] \n"
"    B       loc_FF0748F0 \n"

"loc_FF074968:\n"
//------------------  added code ---------------------
"labelA:\n"
"    LDR     R0, =jogdial_stopped\n"
"    LDR     R0, [R0]\n"
"    CMP     R0, #1\n"
"    BNE     labelB\n"
"    MOV     R0, #40\n"
"    BL      _SleepTask\n"
"    B       labelA\n"
"labelB:\n"
//------------------  original code ------------------
"    LDR     R0, =0x2D2C \n"
"    LDR     R0, [R0, R4, LSL#2] \n"
"    BL      sub_FF025FF0 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF0747E4 \n"
"    ORR     R3, R4, #0x200 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x28 \n"
"    BL      sub_FF025F20 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R11, R4, LSL#2] \n"
"    BEQ     loc_FF0748F0 \n"
"    LDR     R2, =0x23B \n"
"    B       loc_FF074B54 \n"

"loc_FF0749A0:\n"
"    RSB     R5, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    LDR     R1, =0xC0240000 \n"
"    ADD     R0, R1, R0, LSL#8 \n"
"    LDR     R0, [R0, #0x104] \n"
"    MOV     R1, R0, ASR#16 \n"
"    ADD     R0, SP, #0x18 \n"
"    ADD     R0, R0, R4, LSL#1 \n"
"    STR     R0, [SP, #0x20] \n"
"    STRH    R1, [R0] \n"
"    ADD     R0, SP, #0x14 \n"
"    ADD     R0, R0, R4, LSL#1 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDRSH   R3, [R0] \n"
"    SUB     R2, R1, R3 \n"
"    CMP     R2, #0 \n"
"    BNE     loc_FF074A28 \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF074B10 \n"
"    LDR     R7, =0x2D2C \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF025FF0 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF0747F0 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF025F20 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF074B10 \n"
"    MOV     R2, #0x254 \n"
"    B       loc_FF074B04 \n"

"loc_FF074A28:\n"
"    MOV     R0, R2 \n"
"    RSBLT   R0, R0, #0 \n"
"    MOVLE   R7, #0 \n"
"    MOVGT   R7, #1 \n"
"    CMP     R0, #0xFF \n"
"    BLS     loc_FF074A68 \n"
"    LDR     R0, =0x7FFF \n"
"    CMP     R2, #0 \n"
"    SUBLE   R0, R0, R3 \n"
"    ADDLE   R0, R0, R1 \n"
"    MVNLE   R1, #0x8000 \n"
"    SUB     R0, R0, R1 \n"
"    ADDGT   R1, R0, R3 \n"
"    MVNGT   R0, #0x8000 \n"
"    SUBGT   R0, R1, R0 \n"
"    EOR     R7, R7, #1 \n"

"loc_FF074A68:\n"
"    STR     R0, [SP, #8] \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    ADDEQ   R0, R6, R5, LSL#2 \n"
"    LDREQ   R0, [R0, #8] \n"
"    BEQ     loc_FF074AA0 \n"
"    ADD     R8, R6, R5, LSL#2 \n"
"    ADD     R1, R8, R7, LSL#2 \n"
"    LDR     R1, [R1, #0x10] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FF074AA4 \n"
"    LDR     R0, [R8, #0xC] \n"
"    BL      sub_FF02BAB4 \n"
"    LDR     R0, [R8, #8] \n"

"loc_FF074AA0:\n"
"    BL      sub_FF02BAB4 \n"

"loc_FF074AA4:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    ADD     R7, R0, R7, LSL#2 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R1, [SP, #8] \n"
"    BL      sub_FF02BAC4 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R7, =0x2D2C \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDRH    R1, [R0] \n"
"    LDR     R0, [SP, #0x1C] \n"
"    STRH    R1, [R0] \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF025FF0 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF0747F0 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF025F20 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF074B10 \n"
"    LDR     R2, =0x285 \n"

"loc_FF074B04:\n"
"    LDR     R1, =0xFF074B6C /*'RotaryEncoder.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FF074B10:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    LDR     R0, [R0, #0x18] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF074BA8 \n"
"    LDR     R0, =0x2D20 \n"
"    LDR     R0, [R0, #0x10] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF074BA8 \n"
"    LDR     R2, =0xFF0747E4 \n"
"    ORR     R3, R4, #0x400 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF025F20 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R11, R4, LSL#2] \n"
"    BEQ     loc_FF0748F0 \n"
"    MOV     R2, #0x28C \n"

"loc_FF074B54:\n"
"    LDR     R1, =0xFF074B6C /*'RotaryEncoder.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF0748F0 \n"

"loc_FF074BA8:\n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    LDR     R1, =0xC0240000 \n"
"    ADD     R0, R1, R0, LSL#8 \n"
"    STR     R10, [R0, #0x100] \n"
"    MOV     R1, #1 \n"
"    STR     R1, [R0, #0x108] \n"
"    B       loc_FF0748F0 \n"
);
}
/*
    *** TEMPORARY workaround ***
    Init stuff to avoid asserts on cameras running DryOS r54+
    Execute this only once
 */
void init_required_fw_features(void) {
    extern void _init_focus_eventflag();
    //extern void _init_zoom_semaphore(); // for MoveZoomLensWithPoint

    _init_focus_eventflag();
}
