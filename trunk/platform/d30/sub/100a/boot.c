/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

void CreateTask_PhySw();
void CreateTask_spytask();

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_PhySw();
extern void task_FileWrite();

void taskHook(context_t **context) {
    task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

	if(tcb->entry == (void*)task_PhySw)             tcb->entry = (void*)mykbd_task;
    if(tcb->entry == (void*)task_CaptSeq)           tcb->entry = (void*)capt_seq_task;
    if(tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
    if(tcb->entry == (void*)task_MovieRecord)       tcb->entry = (void*)movie_record_task;
    if(tcb->entry == (void*)task_ExpDrv)            tcb->entry = (void*)exp_drv_task;
    if(tcb->entry == (void*)task_FileWrite)         tcb->entry = (void*)filewritetask;
}

/*----------------------------------------------------------------------
    CreateTask_spytask
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
//** boot @ 0xFF00000C - 0xFF00017C, length=93
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
"    LDR     R0, =0xFF4ADCD0 \n"
"    LDR     R1, =0x471000 \n"
"    LDR     R3, =0x48078C \n"

"loc_FF00013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF00013C \n"
"    LDR     R0, =0xFF49F914 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0xFCBC \n"

"loc_FF000158:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000158 \n"
"    LDR     R1, =0x171710 \n"
"    MOV     R2, #0 \n"

"loc_FF000170:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF000170 \n"
"    B       sub_FF000380_my \n"  // --> Patched. Old value = 0xFF000380.
);
}

/*************************************************************/
//** sub_FF000380_my @ 0xFF000380 - 0xFF0003E8, length=27
void __attribute__((naked,noinline)) sub_FF000380_my() {

    //http://chdk.setepontos.com/index.php/topic,4194.0.html
    *(int*)0x1938=(int)taskHook;
    *(int*)0x193C=(int)taskHook;

    // Replacement of sub_FF04C05C for correct power-on.
    // (short press = playback mode, long press = record mode)
    // look at power-on switch 100a @ 0xFF00A6EC: C0220000 (@ff00a6f4) + 0x12C (@ff00a73c)
    *(int*)(0x2630+4) = (*(int*)0xC022012C) & 0x800000 ? 0x200000 : 0x100000;

asm volatile (
"    LDR     R0, =0xFF0003F8 \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF000430 \n"

"loc_FF00038C:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF00038C \n"
"    LDR     R0, =0xFF000430 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF000644 \n"

"loc_FF0003A8:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF0003A8 \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF0003DC:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF0003DC \n"
"    BL      sub_FF0011D8_my \n"  // --> Patched. Old value = 0xFF0011D8.
);
}

/*************************************************************/
//** sub_FF0011D8_my @ 0xFF0011D8 - 0xFF001284, length=44
void __attribute__((naked,noinline)) sub_FF0011D8_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_0047C448 \n"
"    MOV     R0, #0x57000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(OPT_CHDK_IN_EXMEM) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x171710 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x36D440 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x7C \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R1, =0x375C00 \n"
"    LDR     R0, =0x1CD \n"
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
"    LDR     R1, =sub_FF004288_my \n"  // --> Patched. Old value = 0xFF004288.
"    LDR     PC, =0xFF001274 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF004288_my @ 0xFF004288 - 0xFF0042FC, length=30
void __attribute__((naked,noinline)) sub_FF004288_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF000B50 \n"
"    BL      sub_FF005174 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF00439C /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF003EC0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043A4 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF0043B4 /*'/_term'*/ \n"
"    BL      sub_FF003FA8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043BC /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF0043B4 /*'/_term'*/ \n"
"    BL      sub_FF0029C8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043D0 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF004B10 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043DC /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF0016C8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043E8 /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF00A6BC_my \n"  // --> Patched. Old value = 0xFF00A6BC.
);
}

/*************************************************************/
//** sub_FF00A6BC_my @ 0xFF00A6BC - 0xFF00A6E8, length=12
void __attribute__((naked,noinline)) sub_FF00A6BC_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_004777E0 \n"
"    BL      sub_004779F8 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =sub_FF00A694_my \n"  // --> Patched. Old value = 0xFF00A694.
"    MOV     R2, #0x200 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00A798 /*'Booting'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF00A694_my @ 0xFF00A694 - 0xFF00A6B8, length=10
void __attribute__((naked,noinline)) sub_FF00A694_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
//"  BL      _sub_FF04C054 \n"  // --> Nullsub call removed.
"    BL      sub_FF01F840 \n"
"    BL      sub_FF01D43C \n"
"    BL      sub_FF025FFC \n"
"    BL      sub_FF01E9F4 \n"
"    BL      sub_FF01DB08 \n"
"    BL      sub_FF01CBF0 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF00A6EC_my \n"  // --> Patched. Old value = 0xFF00A6EC.
);
}

/*************************************************************/
//** sub_FF00A6EC_my @ 0xFF00A6EC - 0xFF00A790, length=42
void __attribute__((naked,noinline)) sub_FF00A6EC_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    BL      sub_FF025D98 \n"
"    LDR     R6, =0xC0220000 \n"
"    MOVS    R4, R0 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF00A73C \n"
"    BL      sub_FF020174 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF00A73C \n"
"    LDR     R0, [R6, #0x128] \n"
"    BIC     R1, R5, R0 \n"
"    LDR     R0, [R6, #0x12C] \n"
"    BIC     R0, R5, R0 \n"
"    ORRS    R2, R0, R1 \n"
"    BNE     loc_FF00A74C \n"
"    BL      sub_FF01D7EC \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R6, #0x1C] \n"
"    BL      sub_FF01D9DC \n"

"loc_FF00A738:\n"
"    B       loc_FF00A738 \n"

"loc_FF00A73C:\n"
"    LDR     R0, [R6, #0x12C] \n"
"    LDR     R1, [R6, #0x128] \n"
"    BIC     R0, R5, R0 \n"
"    BIC     R1, R5, R1 \n"

"loc_FF00A74C:\n"
"    MOV     R3, #0 \n"
"    MOV     R2, R4 \n"
//"  BL      _sub_FF04C05C \n"  // See begin of sub_FF00038C_my. StartUp mode detection.
//"  BL      _sub_FF04C058 \n"  // --> Nullsub call removed.
"    BL      sub_004777E0 \n"
"    LDR     R1, =0x3CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF024374 \n"
"    BL      sub_004779F8 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF00A638.
"    LDR     PC, =0xFF00A77C \n"  // Continue in firmware
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF00A638 - 0xFF00A690, length=23
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF0048C8 \n"
//"  BL      _sub_FF04C794 \n"  // --> Nullsub call removed.
//"  BL      _sub_FF025EA4 \n"  // start diskboot.bin
"    BL      sub_FF026158 \n"
"    BL      sub_FF026324 \n"
"    BL      sub_FF0439A8 \n"
"    BL      sub_FF02602C \n"
"    BL      sub_FF0242A8 \n"
"    BL      sub_FF02632C_my \n"  // --> Patched. Old value = 0xFF02632C.
"    BL      CreateTask_spytask\n"  // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF01E454.
"    LDR     PC, =0xFF00A664 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF02632C_my @ 0xFF02632C - 0xFF026340, length=6
void __attribute__((naked,noinline)) sub_FF02632C_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF080DE0_my \n"  // --> Patched. Old value = 0xFF080DE0.
"    BL      sub_FF07E434 \n"
"    BL      sub_FF07EDE8 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF07FDEC \n"
);
}

/*************************************************************/
//** sub_FF080DE0_my @ 0xFF080DE0 - 0xFF080E98, length=47
void __attribute__((naked,noinline)) sub_FF080DE0_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF0200C4 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    LDR     R4, =0x3390 \n"
"    LDRNE   R0, =0xFF02437C \n"
"    STRNE   R0, [R4, #4] \n"
"    LDRNE   R0, =0xFF024380 \n"
"    STRNE   R0, [R4, #8] \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    LDR     R0, [R4] \n"
"    CMP     R0, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    LDR     R5, =0x493E0 \n"  // --> Patched. Old value = 0x927C0. Reduce the memory size reserved for the UI
"    MOV     R0, R5 \n"
"    BL      sub_FF024384 /*_malloc_strictly*/ \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF00129C \n"
"    TST     R0, #1 \n"
"    STR     R0, [R4] \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0x4D \n"
"    LDR     R0, =0xFF080E5C /*'UiMemory.c'*/ \n"
"    B       _DebugAssert \n"
"    LDR     R1, =0x3390 \n"
"    LDR     R1, [R1, #4] \n"
"    BX      R1 \n"
"    LDR     R1, =0x3390 \n"
"    LDR     R1, [R1, #8] \n"
"    BX      R1 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF01E454 - 0xFF01E474, length=9
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C30 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF01E488 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF01E420.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw
"    LDR     PC, =0xFF01E478 \n"  // Continue in firmware
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF083A34 - 0xFF083A50, length=8
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF07AC50 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF07AC84 \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    LDR     PC, =0xFF083A54 \n"  // Continue in firmware
);
}
