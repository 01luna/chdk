/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

const char * const new_sa = &_end;

extern volatile int jogdial_stopped;
void JogDial_task_my(void);

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

#define DPs (void*)0xC022006C					// direct-print (blue)
#define LED_AF (void*)0xC0220094	//LED_AF
#define LED_ISO (void*)0xC02200B0	//LED_ISO   
#define LED_PWR (void*)0xC0220068	//LED_PWR   
#define LED_BLUE (void*)0xC022006C	//LED_BLUE
#define DELAYs 3000000

void taskCreateHook(int *p) {
    p-=16;
    if (p[0]==0xff861210)  p[0]=(int)capt_seq_task;
    if (p[0]==0xff8b8b90)  p[0]=(int)exp_drv_task;
    if (p[0]==0xff85d4c0)  p[0]=(int)movie_record_task;
    if (p[0]==0xffa2ac20)  p[0]=(int)filewritetask;
    if (p[0]==0xff877284)  p[0]=(int)init_file_modules_task;
    if (p[0]==0xff849530)  p[0]=(int)JogDial_task_my;
}

void boot()
{
    long *canon_data_src = (void*)0xFFB2E384; // OK	//canon_data_src!!!  @FF810130
    long *canon_data_dst = (void*)0x1900;	// OK  //MEMBASEADDR   @FF810134
    long canon_data_len = 0x140E4- 0x1900; // data_end - data_start     
    long *canon_bss_start = (void*)0x140e4; // just after data 	// OK	//@FF810138
    long canon_bss_len = 0xb0b68 - 0x140e4; //  MEMISOSTART - 

    long i;


    // Enable CPU caches and MPU
    asm volatile (
    "MRC     p15, 0, R0,c1,c0\n"
    "ORR     R0, R0, #0x1000\n"
    "ORR     R0, R0, #4\n"
    "ORR     R0, R0, #1\n"
    "MCR     p15, 0, R0,c1,c0\n"
    :::"r0");

    for(i=0;i<canon_data_len/4;i++)
    canon_data_dst[i]=canon_data_src[i];

    for(i=0;i<canon_bss_len/4;i++)
    canon_bss_start[i]=0;

    //Replacement of sub_FF848C84 (sub_FF822E10) for correct power-on.
    //(short press = playback mode, long press = record mode)
    *(int*)(0x261C+8)= (*(int*)0xC02200C0)&1 ? 1 : 2;

    *(int*)0x1930=(int)taskCreateHook;
    *(int*)0x1934=(int)taskCreateHook;

    // jump to init-sequence that follows the data-copy-routine
    asm volatile ("B      sub_FF8101A4_my\n");
};


/*************************************************************/
//** sub_FF8101A4_my @ 0xFF8101A4 - 0xFF81020C, length=27
void __attribute__((naked,noinline)) sub_FF8101A4_my() {
asm volatile (
"    LDR     R0, =0xFF81021C \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF810254 \n"

"loc_FF8101B0:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8101B0 \n"
"    LDR     R0, =0xFF810254 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF810468 \n"

"loc_FF8101CC:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8101CC \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF810200:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF810200 \n"
"    BL      sub_FF810FB8_my \n"  // --> Patched. Old value = 0xFF810FB8.
);
}

/*************************************************************/
//** sub_FF810FB8_my @ 0xFF810FB8 - 0xFF811058, length=41
void __attribute__((naked,noinline)) sub_FF810FB8_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R0, SP \n"
"    MOV     R1, #0x74 \n"
"    BL      sub_FFABD388 \n"
"    MOV     R0, #0x53000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0xB0B68 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x2ABC00 \n"
"    LDR     R1, =0x2A4968 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R1, R0 \n"
"    ADD     R3, SP, #0xC \n"
"    STR     R2, [SP] \n"
"    STMIA   R3, {R0-R2} \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x68 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R0, =0x19B \n"
"    MOV     R1, #0x64 \n"
"    STRD    R0, [SP, #0x20] \n"
"    MOV     R0, #0x78 \n"
"    STRD    R0, [SP, #0x28] \n"
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
"    LDR     R1, =uHwSetup_my \n"  // --> Patched. Old value = 0xFF814DBC.
"    MOV     R0, SP \n"
"    MOV     R2, #0 \n"
"    BL      sub_FF812D70 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** uHwSetup_my @ 0xFF814DBC - 0xFF814E30, length=30
void __attribute__((naked,noinline)) uHwSetup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF81095C \n"
"    BL      sub_FF819948 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814ED0 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF8149E0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814ED8 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF814EE8 /*'/_term'*/ \n"
"    BL      sub_FF814ACC \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814EF0 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF814EE8 /*'/_term'*/ \n"
"    BL      sub_FF81357C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814F04 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF8194D0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814F10 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF8114D0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814F1C /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       CreateTask_Startup_my \n"  // --> Patched. Old value = 0xFF81DC0C.
);
}

/*************************************************************/
//** CreateTask_Startup_my @ 0xFF81DC0C - 0xFF81DC88, length=32
void __attribute__((naked,noinline)) CreateTask_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
//"  BL      _sub_FF822E08 \n"  // --> Nullsub call removed.
"    BL      sub_FF82C8FC \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81DC4C \n"
"    BL      sub_FF824568 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R2, =0xC0220000 \n"
"    LDREQ   R0, [R2, #0xC0] \n"
"    LDREQ   R1, [R2, #0xC4] \n"
"    ORREQ   R0, R0, R1 \n"
"    TSTEQ   R0, #1 \n"
"    BNE     loc_FF81DC4C \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R2, #0x4C] \n"

"loc_FF81DC48:\n"
"    B       loc_FF81DC48 \n"

"loc_FF81DC4C:\n"
//"  BL      _sub_FF848C84 \n"  // removed, see boot() function
//"  BL      _sub_FF822E0C \n"  // --> Nullsub call removed.
"    BL      sub_FF82A488 \n"
"    MOV     R1, #0x300000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF82A6D0 \n"
"    BL      sub_FF82A67C /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF81DBB0.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF81DC90 /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R12,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF81DBB0 - 0xFF81DC08, length=23
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF81517C \n"
"    BL      sub_FF823FA0 \n"
"    BL      sub_FF820E60 \n"
//"  BL      _sub_FF849478 \n"  // --> Nullsub call removed.
"    BL      sub_FF82CADC \n"
//"  BL      _sub_FF82C9C4 \n"  // load DISKBOOT.BIN
"    BL      CreateTask_spytask\n" // added
"    BL      sub_FF873410 \n"
"    BL      sub_FF82CB2C \n"
"    BL      sub_FF8299CC \n"
"    BL      sub_FF82CCA8 \n"
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF822DA8. Checks buttons and acts accordingly
"    BL      sub_FF82629C \n"
"    BL      sub_FF82CCC0 \n"
//"  BL      _sub_FF820B00 \n"  // --> Nullsub call removed.
"    BL      sub_FF822130 \n"
"    BL      sub_FF82C6A8 \n"
"    BL      sub_FF8228D4 \n"
"    BL      sub_FF82203C \n"
"    BL      sub_FF82D720 \n"
"    BL      sub_FF821FF8 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF815088 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF822DA8 - 0xFF822DE0, length=15
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C98 \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF822DDC \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF822D74.
"    MOV     R2, #0x800 \n"
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF822FA0 /*'PhySw'*/ \n"
"    BL      sub_FF81BDC8 /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #0x10] \n"

"loc_FF822DDC:\n"
"    LDMFD   SP!, {R3-R5,LR} \n"
"    B       sub_FF84962C \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF877284 - 0xFF8772B8, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF86FFF8 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF870024_my \n"  // --> Patched. Old value = 0xFF870024.
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    MOVEQ   R0, R5 \n"
"    LDMEQFD SP!, {R4-R6,LR} \n"
"    MOVEQ   R1, #0 \n"
"    BEQ     _PostLogicalEventToUI \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF870024_my @ 0xFF870024 - 0xFF87005C, length=15
void __attribute__((naked,noinline)) sub_FF870024_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF85235C_my \n"  // --> Patched. Old value = 0xFF85235C.
"    LDR     R4, =0x5AC4 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF870054 \n"
"    BL      sub_FF87FD60 \n"
"    BL      sub_FF90B938 \n"
"    BL      sub_FF87FD60 \n"
"    BL      sub_FF91848C \n"
"    BL      sub_FF87FD70 \n"
"    BL      sub_FF90B9E0 \n"

"loc_FF870054:\n"
"    MOV     R0, #1 \n"
"    STR     R0, [R4] \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FF85235C_my @ 0xFF85235C - 0xFF8523F4, length=39
void __attribute__((naked,noinline)) sub_FF85235C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF851F2C \n"
"    LDR     R4, =0x168D0 \n"
"    MOV     R5, #0 \n"
"    LDR     R0, [R4, #0x38] \n"
"    BL      sub_FF8528F4 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x2D34 \n"
"    STREQ   R5, [R0, #0xC] \n"
"    STREQ   R5, [R0, #0x10] \n"
"    STREQ   R5, [R0, #0x14] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF851F6C \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF852198_my \n"  // --> Patched. Old value = 0xFF852198.
"    MOV     R5, R0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF852204 \n"
"    LDR     R1, [R4, #0x3C] \n"
"    AND     R2, R5, R0 \n"
"    CMP     R1, #0 \n"
"    MOV     R0, #0 \n"
"    MOVEQ   R0, #0x80000001 \n"
"    BEQ     loc_FF8523F0 \n"
"    LDR     R3, [R4, #0x2C] \n"
"    CMP     R3, #2 \n"
"    MOVEQ   R0, #4 \n"
"    CMP     R1, #5 \n"
"    ORRNE   R0, R0, #1 \n"
"    BICEQ   R0, R0, #1 \n"
"    CMP     R2, #0 \n"
"    BICEQ   R0, R0, #2 \n"
"    ORREQ   R0, R0, #0x80000000 \n"
"    BICNE   R0, R0, #0x80000000 \n"
"    ORRNE   R0, R0, #2 \n"

"loc_FF8523F0:\n"
"    STR     R0, [R4, #0x40] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF852198_my @ 0xFF852198 - 0xFF852200, length=27
void __attribute__((naked,noinline)) sub_FF852198_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x2D34 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, #0x17 \n"
"    MUL     R1, R0, R6 \n"
"    LDR     R0, =0x168D0 \n"
"    ADD     R4, R0, R1, LSL#2 \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R6 \n"
"    BL      sub_FF852030_my \n"  // --> Patched. Old value = 0xFF852030.
"    CMP     R0, #0 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R6 \n"
"    BL      sub_FF852A0C \n"
"    CMP     R0, #0 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF851B4C \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #1 \n"
"    STRNE   R1, [R5, #0x10] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF852030_my @ 0xFF852030 - 0xFF852194, length=90
void __attribute__((naked,noinline)) sub_FF852030_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R8, R0 \n"
"    MOV     R0, #0x17 \n"
"    MUL     R1, R0, R1 \n"
"    LDR     R0, =0x168D0 \n"
"    MOV     R6, #0 \n"
"    ADD     R7, R0, R1, LSL#2 \n"
"    LDR     R0, [R7, #0x3C] \n"
"    MOV     R5, #0 \n"
"    CMP     R0, #6 \n"
"    ADDLS   PC, PC, R0, LSL#2 \n"
"    B       loc_FF85217C \n"
"    B       loc_FF852094 \n"
"    B       loc_FF85207C \n"
"    B       loc_FF85207C \n"
"    B       loc_FF85207C \n"
"    B       loc_FF85207C \n"
"    B       loc_FF852174 \n"
"    B       loc_FF85207C \n"

"loc_FF85207C:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x200 \n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ualloc \n"
"    MOVS    R4, R0 \n"
"    BNE     loc_FF85209C \n"

"loc_FF852094:\n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FF85209C:\n"
"    LDR     R12, [R7, #0x4C] \n"
"    MOV     R3, R4 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R8 \n"
"    BLX     R12 \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8520C8 \n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ufree \n"
"    B       loc_FF852094 \n"

"loc_FF8520C8:\n"
"    MOV     R0, R8 \n"
"    BL      sub_FF929040 \n"

"    MOV     R1, R4\n"              //  pointer to MBR in R1
"    BL      mbr_read_dryos\n"      //  total sectors count in R0 before and after call

// Start of DataGhost's FAT32 autodetection code
// Policy: If there is a partition which has type W95 FAT32, use the first one of those for image storage
// According to the code below, we can use R1, R2, R3 and R12.
// LR wasn't really used anywhere but for storing a part of the partition signature. This is the only thing
// that won't work with an offset, but since we can load from LR+offset into LR, we can use this to do that :)
"    MOV     R12, R4\n"             // Copy the MBR start address so we have something to work with
"    MOV     LR, R4\n"              // Save old offset for MBR signature
"    MOV     R1, #1\n"              // Note the current partition number
"    B       dg_sd_fat32_enter\n"   // We actually need to check the first partition as well, no increments yet!
"dg_sd_fat32:\n"
"    CMP     R1, #4\n"              // Did we already see the 4th partition?
"    BEQ     dg_sd_fat32_end\n"     // Yes, break. We didn't find anything, so don't change anything.
"    ADD     R12, R12, #0x10\n"     // Second partition
"    ADD     R1, R1, #1\n"          // Second partition for the loop
"dg_sd_fat32_enter:\n"
"    LDRB    R2, [R12, #0x1BE]\n"   // Partition status
"    LDRB    R3, [R12, #0x1C2]\n"   // Partition type (FAT32 = 0xB)
"    CMP     R3, #0xB\n"            // Is this a FAT32 partition?
"    CMPNE   R3, #0xC\n"            // Not 0xB, is it 0xC (FAT32 LBA) then?
"    CMPNE   R3, #0x7\n"            // exFat?
"    BNE     dg_sd_fat32\n"         // No, it isn't. Loop again.
"    CMP     R2, #0x00\n"           // It is, check the validity of the partition type
"    CMPNE   R2, #0x80\n"
"    BNE     dg_sd_fat32\n"         // Invalid, go to next partition
                                    // This partition is valid, it's the first one, bingo!
"    MOV     R4, R12\n"             // Move the new MBR offset for the partition detection.

"dg_sd_fat32_end:\n"
// End of DataGhost's FAT32 autodetection code

"    LDRB    R1, [R4, #0x1C9] \n"
"    LDRB    R3, [R4, #0x1C8] \n"
"    LDRB    R12, [R4, #0x1CC] \n"
"    MOV     R1, R1, LSL#24 \n"
"    ORR     R1, R1, R3, LSL#16 \n"
"    LDRB    R3, [R4, #0x1C7] \n"
"    LDRB    R2, [R4, #0x1BE] \n"
//"  LDRB    LR, [R4, #0x1FF] \n"
"    ORR     R1, R1, R3, LSL#8 \n"
"    LDRB    R3, [R4, #0x1C6] \n"
"    CMP     R2, #0 \n"
"    CMPNE   R2, #0x80 \n"
"    ORR     R1, R1, R3 \n"
"    LDRB    R3, [R4, #0x1CD] \n"
"    MOV     R3, R3, LSL#24 \n"
"    ORR     R3, R3, R12, LSL#16 \n"
"    LDRB    R12, [R4, #0x1CB] \n"
"    ORR     R3, R3, R12, LSL#8 \n"
"    LDRB    R12, [R4, #0x1CA] \n"
"    ORR     R3, R3, R12 \n"
//"  LDRB    R12, [R4, #0x1FE] \n"  // Replaced, see below
//mod start
"    LDRB    R12, [LR,#0x1FE]\n"           // New! First MBR signature byte (0x55)
"    LDRB    LR, [LR,#0x1FF]\n"            //      Last MBR signature byte (0xAA)
//mod end
"    MOV     R4, #0 \n"
"    BNE     loc_FF852150 \n"
"    CMP     R0, R1 \n"
"    BCC     loc_FF852150 \n"
"    ADD     R2, R1, R3 \n"
"    CMP     R2, R0 \n"
"    CMPLS   R12, #0x55 \n"
"    CMPEQ   LR, #0xAA \n"
"    MOVEQ   R6, R1 \n"
"    MOVEQ   R5, R3 \n"
"    MOVEQ   R4, #1 \n"

"loc_FF852150:\n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ufree \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF852188 \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF929040 \n"
"    MOV     R5, R0 \n"
"    B       loc_FF852188 \n"

"loc_FF852174:\n"
"    MOV     R5, #0x40 \n"
"    B       loc_FF852188 \n"

"loc_FF85217C:\n"
"    LDR     R1, =0x365 \n"
"    LDR     R0, =0xFF852024 /*'Mounter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF852188:\n"
"    STR     R6, [R7, #0x44]! \n"
"    MOV     R0, #1 \n"
"    STR     R5, [R7, #4] \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** JogDial_task_my @ 0xFF849530 - 0xFF849628, length=63
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R3-R11,LR} \n"
"    BL      sub_FF849700 \n"
"    LDR     R11, =0x80000B01 \n"
"    LDR     R8, =0xFFAC6350 \n"
"    LDR     R7, =0xC0240000 \n"
"    LDR     R6, =0x263C \n"
"    MOV     R9, #1 \n"
"    MOV     R10, #0 \n"

"loc_FF849550:\n"
"    LDR     R3, =0x191 \n"
"    LDR     R0, [R6, #0xC] \n"
"    LDR     R2, =0xFF8497B8 /*'JogDial.c'*/ \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF81BEB0 /*_TakeSemaphoreStrictly*/ \n"
"    MOV     R0, #0x28 \n"
"    BL      _SleepTask \n"
//------------------  added code ---------------------
"sleep_loop:\n"
"    LDR     R0, =jogdial_stopped\n"
"    LDR     R0, [R0]\n"
"    CMP     R0, #1\n"
"    BNE     sleep_done\n"
"    MOV     R0, #40\n"
"    BL      _SleepTask\n"
"    B       sleep_loop\n"
"sleep_done:\n"
//------------------  original code ------------------
"    LDR     R0, [R7, #0x304] \n"
"    MOV     R0, R0, ASR#16 \n"
"    STRH    R0, [R6] \n"
"    LDRSH   R2, [R6, #2] \n"
"    SUB     R1, R0, R2 \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FF849614 \n"
"    MOV     R5, R1 \n"
"    RSBLT   R5, R5, #0 \n"
"    MOVLE   R4, #0 \n"
"    MOVGT   R4, #1 \n"
"    CMP     R5, #0xFF \n"
"    BLS     loc_FF8495C8 \n"
"    CMP     R1, #0 \n"
"    RSBLE   R1, R2, #0xFF \n"
"    ADDLE   R1, R1, #0x7F00 \n"
"    ADDLE   R0, R1, R0 \n"
"    RSBGT   R0, R0, #0xFF \n"
"    ADDGT   R0, R0, #0x7F00 \n"
"    ADDGT   R0, R0, R2 \n"
"    ADD     R5, R0, #0x8000 \n"
"    ADD     R5, R5, #1 \n"
"    EOR     R4, R4, #1 \n"

"loc_FF8495C8:\n"
"    LDR     R0, [R6, #0x14] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF84960C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF8495F4 \n"
"    LDR     R1, [R8, R4, LSL#2] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FF8495FC \n"
"    LDR     R0, =0xB01 \n"
"    BL      sub_FF872EB0 \n"

"loc_FF8495F4:\n"
"    MOV     R0, R11 \n"
"    BL      sub_FF872EB0 \n"

"loc_FF8495FC:\n"
"    LDR     R0, [R8, R4, LSL#2] \n"
"    MOV     R1, R5 \n"
"    STR     R0, [R6, #0x1C] \n"
"    BL      sub_FF872E0C \n"

"loc_FF84960C:\n"
"    LDRH    R0, [R6] \n"
"    STRH    R0, [R6, #2] \n"

"loc_FF849614:\n"
"    STR     R10, [R7, #0x300] \n"
"    STR     R9, [R7, #0x308] \n"
"    LDR     R0, [R6, #0x10] \n"
"    CMP     R0, #0 \n"
"    BLNE    _SleepTask \n"
"    B       loc_FF849550 \n"
);
}
