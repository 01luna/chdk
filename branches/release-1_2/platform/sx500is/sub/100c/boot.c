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
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

///*----------------------------------------------------------------------
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
short *jog_position;

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
"    MOV     R0, #0x33 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000033 \n"
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
"    LDR     R0, =0xFF4E1414 \n"
"    LDR     R1, =0x431000 \n"
"    LDR     R3, =0x44059C \n"

"loc_FF00013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF00013C \n"
"    LDR     R0, =0xFF4D317C \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0xFB98 \n"

"loc_FF000158:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000158 \n"
"    LDR     R1, =0x1791C0 \n"
"    MOV     R2, #0 \n"

"loc_FF000170:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF000170 \n"
/* Install task hooks via 0x193x is not possible with this new dryos version
   So the below code patches the CreateTask function in RAM to install our
   hook -- ERR99
*/
// Install CreateTask patch
"    LDR     R0, =patch_CreateTask\n"   // Patch data
"    LDM     R0, {R1,R2}\n"             // Get two patch instructions
"    LDR     R0, =hook_CreateTask\n"    // Address to patch
"    STM     R0, {R1,R2}\n"             // Store patch instructions

"    B       sub_FF000380_my \n"  // --> Patched. Old value = 0xFF000380.

"patch_CreateTask:\n"
"    LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my\n"
);
}

/*************************************************************/
//** CreateTask_my @ 0x004368B0 - 0x004368B4, length=2
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
"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =exp_drv_task\n"
"    BEQ     exitHook\n"

/*** INSTALL filewrite() hook ***/
"    LDR     R0, =task_FileWrite\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =filewritetask\n"
"    BEQ     exitHook\n"

/*** INSTALL JogDial() hook ***/
"    LDR     R0, =task_RotaryEncoder\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =JogDial_task_my\n"
"    BEQ     exitHook\n"

/*** INSTALL movie_record_task() hook ***/
"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =movie_record_task\n"
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
"    LDR     PC, =0x004368B8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF000380_my @ 0xFF000380 - 0xFF0003E8, length=27
void __attribute__((naked,noinline)) sub_FF000380_my() {

    //Replacement of sub_FF055F04 for correct power-on.
    //(short press = playback mode, long press = record mode)
    //look at power-on switch sub_FF0191E8
    *(int*)(0x2B14+0x4) = (*(int*)0xC0220104&1 ? 0x100000 : 0x200000);

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
"    LDR     R3, =0xFF000618 \n"

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
"    LDR     R0, =0x698 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF0003DC:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF0003DC \n"
"    BL      sub_FF001160_my \n"  // --> Patched. Old value = 0xFF001160.
);
}

/*************************************************************/
//** sub_FF001160_my @ 0xFF001160 - 0xFF00120C, length=44
void __attribute__((naked,noinline)) sub_FF001160_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_0043C3A0 \n"
"    MOV     R0, #0x57000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x1791C0 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x32D440 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x7C \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R1, =0x335C00 \n"
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
"    LDR     R1, =sub_FF004210_my \n"  // --> Patched. Old value = 0xFF004210.
"    MOV     R2, #0 \n"
"    MOV     R0, SP \n"
"    BL      sub_004327E8 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF004210_my @ 0xFF004210 - 0xFF004284, length=30
void __attribute__((naked,noinline)) sub_FF004210_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF000ADC \n"
"    BL      sub_FF0050FC \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004324 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF003E48 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF00432C \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF00433C \n"
"    BL      sub_FF003F30 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004344 \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF00433C \n"
"    BL      sub_FF002950 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004358 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF004A98 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004364 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF001650 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004370 \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF00A21C_my \n"  // --> Patched. Old value = 0xFF00A21C.
);
}

/*************************************************************/
//** sub_FF00A21C_my @ 0xFF00A21C - 0xFF00A298, length=32
void __attribute__((naked,noinline)) sub_FF00A21C_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_FF0209AC \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF00A23C \n"
"    BL      sub_FF01AD48 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF00A240 \n"

"loc_FF00A23C:\n"
"    MOV     R0, #0 \n"

"loc_FF00A240:\n"
"    BL      sub_FF0191E8_my \n"  // --> Patched. Old value = 0xFF0191E8.
"    CMP     R0, #0 \n"
"    BNE     loc_FF00A264 \n"
"    BL      sub_FF01883C \n"
"    LDR     R1, =0xC0220000 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R1, #0x12C] \n"
"    BL      sub_FF0189B0 \n"

"loc_FF00A260:\n"
"    B       loc_FF00A260 \n"

"loc_FF00A264:\n"
"    BL      sub_0043786C \n"
"    LDR     R1, =0x38E000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF01EFEC \n"
"    BL      sub_00437A84 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF00A1B4.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00A2A8 \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF0191E8_my @ 0xFF0191E8 - 0xFF019240, length=23
void __attribute__((naked,noinline)) sub_FF0191E8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R6, R0 \n"
//"  BL      _sub_FF055EFC \n"  // --> Nullsub call removed.
"    LDR     R0, =0xC0220104 \n"
"    BL      sub_FF0569E4 \n"
"    MOV     R4, #1 \n"
"    BIC     R5, R4, R0 \n"
"    LDR     R0, =0xC022010C \n"
"    BL      sub_FF0569E4 \n"
"    CMP     R6, #0 \n"
"    BIC     R4, R4, R0 \n"
"    BEQ     loc_FF019220 \n"
"    ORRS    R0, R5, R4 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF019220:\n"
"    BL      sub_FF0209AC \n"
"    MOV     R2, R0 \n"
"    MOV     R3, #0 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
//"  BL      _sub_FF055F04 \n"  // Disable StartUpChecks
//"  BL      _sub_FF055F00 \n"  // --> Nullsub call removed.
"    MOV     R0, #1 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF00A1B4 - 0xFF00A218, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF004850 \n"
"    BL      sub_FF01A36C \n"
"    BL      sub_FF01846C \n"
//"  BL      _sub_FF0569F8 \n"  // --> Nullsub call removed.
"    BL      sub_FF020BE0 \n"
//"  BL      _sub_FF020A88 \n"  // load DISKBOOT.BIN
"    BL      sub_FF020D70 \n"
"    BL      sub_FF020F3C \n"
"    BL      sub_FF020D34 \n"
"    BL      sub_FF020C28 \n"
"    BL      sub_FF01EF20 \n"
"    BL      sub_FF020F44 \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF019088.
"    BL      sub_FF01CB60 \n"
"    BL      sub_FF09A7E8 \n"
"    BL      sub_FF016214 \n"
"    BL      sub_FF017DB8 \n"
"    BL      sub_FF02076C \n"
"    BL      sub_FF018420 \n"
"    BL      sub_FF017D54 \n"
"    BL      sub_FF044334 \n"
"    BL      sub_FF016EAC \n"
"    BL      sub_FF017D18 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF004970 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF019088 - 0xFF0190DC, length=22
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1D30 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF0190BC \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF019054.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF019338 \n"
"    BL      sub_00437ADC /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF0190BC:\n"
"    BL      sub_FF056E68 \n"
"    BL      sub_FF086644 \n"
"    BL      sub_FF01AC98 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF0190DC \n"
"    LDR     R1, =0x33BC4 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0865B0 /*_OpLog.Start_FW*/ \n"

"loc_FF0190DC:\n"
"    LDMFD   SP!, {R3-R5,PC} \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF046F88 - 0xFF046FBC, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF088B84 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF088BB0 \n"
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
//** JogDial_task_my @ 0xFF056B3C - 0xFF056E64, length=203
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R4-R11,LR} \n"
"    SUB     SP, SP, #0x1C \n"
"    BL      sub_FF056ED4 \n"
"    LDR     R12, =0x2B34 \n"
"    LDR     R6, =0xFF39E4E8 \n"
"    MOV     R0, #0 \n"
"    ADD     R10, SP, #8 \n"
"    ADD     R9, SP, #0xC \n"
//Check this!!!
// Save pointer for kbd.c routine
"    LDR     R2, =jog_position \n"
"    STR     R9, [R2] \n"


"loc_FF056B5C:\n"
"    ADD     R2, SP, #0x14 \n"
"    MOV     R1, #0 \n"
"    ADD     R4, R2, R0, LSL#1 \n"
"    ADD     R3, SP, #0x10 \n"
"    STRH    R1, [R4] \n"
"    ADD     R4, R3, R0, LSL#1 \n"
"    STRH    R1, [R4] \n"
"    STR     R1, [R9, R0, LSL#2] \n"
"    STR     R1, [R10, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #1 \n"
"    BLT     loc_FF056B5C \n"

"loc_FF056B8C:\n"
"    LDR     R0, =0x2B34 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R0, #8] \n"
"    MOV     R1, SP \n"
"    BL      sub_004372A4 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x20B \n"
"    LDRNE   R0, =0xFF056DEC \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP] \n"
"    AND     R4, R0, #0xFF \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x100 \n"
"    BEQ     loc_FF056BFC \n"
"    CMP     R0, #0x200 \n"
"    BEQ     loc_FF056C34 \n"
"    CMP     R0, #0x300 \n"
"    BEQ     loc_FF056E38 \n"
"    CMP     R0, #0x400 \n"
"    BNE     loc_FF056B8C \n"
"    CMP     R4, #0 \n"
"    LDRNE   R1, =0x285 \n"
"    LDRNE   R0, =0xFF056DEC \n"
"    BLNE    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R0, LSL#2] \n"

"loc_FF056BF4:\n"
"    BL      sub_FF056EB8 \n"
"    B       loc_FF056B8C \n"

"loc_FF056BFC:\n"
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
"    LDR     R0, =0x2B40 \n"
"    LDR     R0, [R0, R4, LSL#2] \n"
"    BL      sub_FF01F564 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF056A88 \n"
"    ORR     R3, R4, #0x200 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x28 \n"
"    BL      sub_FF01F480 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF056B8C \n"
"    LDR     R1, =0x21D \n"
"    B       loc_FF056DD8 \n"

"loc_FF056C34:\n"
"    RSB     R5, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    LDR     R1, =0xC0240000 \n"
"    ADD     R0, R1, R0, LSL#8 \n"
"    LDR     R0, [R0, #0x104] \n"
"    MOV     R1, R0, ASR#16 \n"
"    ADD     R0, SP, #0x14 \n"
"    ADD     R11, R0, R4, LSL#1 \n"
"    ADD     R0, SP, #0x10 \n"
"    ADD     R0, R0, R4, LSL#1 \n"
"    STRH    R1, [R11] \n"
"    STR     R0, [SP, #0x18] \n"
"    LDRSH   R3, [R0] \n"
"    SUB     R2, R1, R3 \n"
"    CMP     R2, #0 \n"
"    BNE     loc_FF056CB8 \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF056D94 \n"
"    LDR     R7, =0x2B40 \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF01F564 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF056A94 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF01F480 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF056D94 \n"
"    LDR     R1, =0x236 \n"
"    B       loc_FF056D8C \n"

"loc_FF056CB8:\n"
"    MOV     R0, R2 \n"
"    RSBLT   R0, R0, #0 \n"
"    MOVLE   R7, #0 \n"
"    MOVGT   R7, #1 \n"
"    CMP     R0, #0xFF \n"
"    BLS     loc_FF056CF4 \n"
"    LDR     R0, =0x7FFF \n"
"    CMP     R2, #0 \n"
"    SUBLE   R0, R0, R3 \n"
"    ADDLE   R0, R0, R1 \n"
"    SUBGT   R0, R0, R1 \n"
"    ADDGT   R0, R0, R3 \n"
"    MVN     R1, #0x8000 \n"
"    SUB     R0, R0, R1 \n"
"    EOR     R7, R7, #1 \n"

"loc_FF056CF4:\n"
"    STR     R0, [SP, #4] \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    ADDEQ   R0, R6, R5, LSL#2 \n"
"    LDREQ   R0, [R0, #8] \n"
"    BEQ     loc_FF056D2C \n"
"    ADD     R8, R6, R5, LSL#2 \n"
"    ADD     R1, R8, R7, LSL#2 \n"
"    LDR     R1, [R1, #0x10] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FF056D30 \n"
"    LDR     R0, [R8, #0xC] \n"
"    BL      sub_FF0190E0 \n"
"    LDR     R0, [R8, #8] \n"

"loc_FF056D2C:\n"
"    BL      sub_FF0190E0 \n"

"loc_FF056D30:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    ADD     R7, R0, R7, LSL#2 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R1, [SP, #4] \n"
"    BL      sub_FF0190F0 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R7, =0x2B40 \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    LDRH    R1, [R11] \n"
"    LDR     R0, [SP, #0x18] \n"
"    STRH    R1, [R0] \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF01F564 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF056A94 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF01F480 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF056D94 \n"
"    LDR     R1, =0x267 \n"

"loc_FF056D8C:\n"
"    LDR     R0, =0xFF056DEC \n"
"    BL      _DebugAssert \n"

"loc_FF056D94:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    LDR     R0, [R0, #0x18] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF056E30 \n"
"    LDR     R0, =0x2B34 \n"
"    LDR     R0, [R0, #0x10] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF056E30 \n"
"    LDR     R2, =0xFF056A88 \n"
"    ORR     R3, R4, #0x400 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF01F480 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF056B8C \n"
"    LDR     R1, =0x26E \n"

"loc_FF056DD8:\n"
"    LDR     R0, =0xFF056DEC \n"
"    BL      _DebugAssert \n"
"    B       loc_FF056B8C \n"

"loc_FF056E30:\n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    B       loc_FF056BF4 \n"

"loc_FF056E38:\n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, #0x278 \n"
"    LDREQ   R0, =0xFF056DEC \n"
"    BLEQ    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    ADD     R0, R6, R0, LSL#2 \n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF0190E0 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    B       loc_FF056B8C \n"
);
}