/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

// Forward declarations
extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
//extern void task_FileWrite();

void taskHook(context_t **context)
{ 
	task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

	// Replace firmware task addresses with ours
	if(tcb->entry == (void*)task_CaptSeq)           tcb->entry = (void*)capt_seq_task;
	if(tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
	if(tcb->entry == (void*)task_MovieRecord)       tcb->entry = (void*)movie_record_task;
	if(tcb->entry == (void*)task_ExpDrv)            tcb->entry = (void*)exp_drv_task;
	//if(tcb->entry == (void*)task_FileWrite)         tcb->entry = (void*)filewritetask;
}

/*----------------------------------------------------------------------
	CreateTask --> core_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
	_CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

/*----------------------------------------------------------------------
	boot()

	Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//** boot @ 0xFF81000C - 0xFF810160, length=86
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
"    MOV     R0, #0x35 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000035 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF80002D \n"
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
"    MOV     R1, #0xFF \n"
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
"    LDR     R0, =0xFFC8AB28 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x1049C \n"

"loc_FF81013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81013C \n"
"    LDR     R1, =0x1774EC \n"
"    MOV     R2, #0 \n"

"loc_FF810154:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF810154 \n"
"    B       sub_FF810358_my \n"  // --> Patched. Old value = 0xFF810358.
);
}

/*************************************************************/
//** sub_FF810358_my @ 0xFF810358 - 0xFF8103C0, length=27
void __attribute__((naked,noinline)) sub_FF810358_my() {

	//http://chdk.setepontos.com/index.php/topic,4194.0.html
	*(int*)0x1938=(int)taskHook;
	*(int*)0x193C=(int)taskHook;

	// replacement of sub_FF024B5C for correct power-on.
	// http://chdk.setepontos.com/index.php?topic=6341.msg76409#msg76409
	*(int*)(0x25F4) = (*(int*)0xC0220130)&1 ? 0x200000 : 0x100000;

asm volatile (
"    LDR     R0, =0xFF8103D0 \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF810408 \n"

"loc_FF810364:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF810364 \n"
"    LDR     R0, =0xFF810408 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF81061C \n"

"loc_FF810380:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF810380 \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF8103B4:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF8103B4 \n"
"    BL      sub_FF8111B0_my \n"  // --> Patched. Old value = 0xFF8111B0.
);
}

/*************************************************************/
//** sub_FF8111B0_my @ 0xFF8111B0 - 0xFF811248, length=39
void __attribute__((naked,noinline)) sub_FF8111B0_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_FFB9C62C \n"
"    MOV     R0, #0x53000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x1774EC \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x371F80 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x68 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R1, =0x379C00 \n"
"    LDR     R0, =0x19B \n"
"    STR     R1, [SP] \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x96 \n"
"    STR     R2, [SP, #0x10] \n"
"    STR     R1, [SP, #0x14] \n"
"    STR     R0, [SP, #0x24] \n"
"    STR     R0, [SP, #0x28] \n"
"    MOV     R0, #0x64 \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP, #0x30] \n"
"    STR     R0, [SP, #0x34] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x5C] \n"
"    MOV     R0, #0x800 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0xA0 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x280 \n"
"    STR     R0, [SP, #0x68] \n"
"    LDR     R1, =sub_FF815EE0_my \n"  // --> Patched. Old value = 0xFF815EE0.
"    LDR     PC, =0xFF81124C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF815EE0_my @ 0xFF815EE0 - 0xFF815F54, length=30
void __attribute__((naked,noinline)) sub_FF815EE0_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF810B28 \n"
"    BL      sub_FF81A374 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815FF4 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF815B18 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815FFC /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF81600C /*'/_term'*/ \n"
"    BL      sub_FF815C00 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF816014 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF81600C /*'/_term'*/ \n"
"    BL      sub_FF813CA8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF816028 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF819D00 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF816034 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF811690 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF816040 /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       taskcreate_Startup_my \n"  // --> Patched. Old value = 0xFF81FCB4.
);
}

/*************************************************************/
//** taskcreate_Startup_my @ 0xFF81FCB4 - 0xFF81FD60, length=44
void __attribute__((naked,noinline)) taskcreate_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    MOV     R6, #0 \n"
//"  BL      _sub_FF864DF8 \n"  // --> Nullsub call removed.
"    BL      sub_FF83D9B0 \n"
"    LDR     R9, =0xC0220000 \n"
"    MOVS    R7, R0 \n"
"    MOV     R8, #1 \n"
"    BNE     loc_FF81FD1C \n"
"    BL      sub_FF8372F0 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF81FD1C \n"
"    LDR     R0, [R9, #0x12C] \n"
"    BIC     R5, R8, R0 \n"
"    LDR     R0, [R9, #0x128] \n"
"    BIC     R4, R8, R0 \n"
"    BL      sub_FF833DDC \n"
"    CMP     R0, #1 \n"
"    MOVEQ   R6, #1 \n"
"    ORR     R0, R4, R5 \n"
"    ORRS    R0, R0, R6 \n"
"    BNE     loc_FF81FD2C \n"
"    BL      sub_FF834190 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R9, #0x1C] \n"
"    BL      sub_FF834380 \n"

"loc_FF81FD18:\n"
"    B       loc_FF81FD18 \n"

"loc_FF81FD1C:\n"
"    LDR     R0, [R9, #0x128] \n"
"    BIC     R4, R8, R0 \n"
"    LDR     R0, [R9, #0x12C] \n"
"    BIC     R5, R8, R0 \n"

"loc_FF81FD2C:\n"
"    MOV     R3, R6 \n"
"    MOV     R2, R7 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R4 \n"
//"  BL      _sub_FF864E00 \n"  // See begin of sub_FF000364_my()
//"  BL      _sub_FF864DFC \n"  // --> Nullsub call removed.
"    BL      sub_FF83BB7C \n"
"    LDR     R1, =0x3CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF83BFEC \n"
"    BL      sub_FF83BD94 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF81FBF4.
"    LDR     PC, =0xFF81FD64 \n"  // Continue in firmware
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF81FBF4 - 0xFF81FC4C, length=23
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF816588 \n"
"    BL      sub_FF835D30 \n"
"    BL      sub_FF833DEC \n"
//"  BL      _sub_FF86559C \n"  // --> Nullsub call removed.
"    BL      sub_FF83DBE4 \n"
"    BL      sub_FF834F90 \n"
"    BL      sub_FF833870 \n"
//"  BL      _sub_FF83DA8C \n"  // start diskboot.bin
"    BL      sub_FF89AFCC \n"
"    BL      sub_FF816488 \n"
"    BL      sub_FF836A50 \n"
"    LDR     R1, =0x7C007C00 \n"
"    LDR     R0, =0xC0F1800C \n"
"    BL      sub_FF835D3C /*_EngDrvOut*/ \n"
"    LDR     R0, =0xC0F18010 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF835D3C /*_EngDrvOut*/ \n"
"    LDR     R0, =0xC0F18018 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF835D3C /*_EngDrvOut*/ \n"
"    LDR     R0, =0xC0F1801C \n"
"    MOV     R1, #0x1000 \n"
"    BL      sub_FF835D3C /*_EngDrvOut*/ \n"
"    LDR     R0, =0xFF81FD90 \n"
"    MOV     R1, #8 \n"
"    BL      sub_FF835D3C /*_EngDrvOut*/ \n"
"    LDR     R0, =0xFF81FD94 \n"
"    MOV     R1, #0xE000000 \n"
"    BL      sub_FF835D3C /*_EngDrvOut*/ \n"
"    BL      sub_FF8164C0 \n"
"    BL      sub_FF832280 \n"
"    BL      sub_FF83DC14 \n"
"    BL      sub_FF83B320 \n"
"    BL      sub_FF83DD94 \n"

"    BL      CreateTask_spytask\n"  // added

"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF8349EC.
"    LDR     PC, =0xFF81FC84 \n"  // Continue in firmware
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF8349EC - 0xFF834A0C, length=9
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C3C \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF834A20 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF8349B8.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw
"    LDR     PC, =0xFF834A10 \n"  // Continue in firmware
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF89E66C - 0xFF89E688, length=8
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF89669C \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF8966C8 \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    LDR     PC, =0xFF89E68C \n"  // Continue in firmware
);
}
