#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[42]={
0x2000, 0x38D, 0x788, 0xBE1, 0x10CB,0x1642,0x1C48,0x22F9, 0x2A79, 0x32AA, 0x3C01, 0x4637, 0x5190, 0x5E0E,
0x5800, 0x9C5, 0x14B8,0x20C9,0x2E31,0x3D39,0x4DC9,0x6030, 0x74D1, 0x8B8D, 0xA509, 0xC160, 0xE054, 0x102AF,
0x10000,0x1C6A,0x3C45,0x5F60,0x8661,0xB21A,0xE249,0x117D2,0x153D5,0x195F8,0x1E01C,0x2328E,0x28C99,0x2F08B
};

long def_table2[9]={0x1CCD,-0x2E1,-0x579,0x4F33,-0x7EB,-0xF0C,0xE666,-0x170A,-0x2BC6};

long table1[42], table2[9];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<42;i++) table1[i]=(def_table1[i]*a)/b;
 for (i=0;i<9; i++) table2[i]=(def_table2[i]*a)/b;
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                "STMFD   SP!, {R4,LR}\n"    
                "SUB     SP, SP, #4\n"      
                "MOV     R4, SP\n"          
                "B       loc_FF963204\n"    
"loc_FF96313C:\n"                           
                "LDR     R3, =0x61140\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R2, #0\n"          
                "BNE     loc_FF9631CC\n"    
                "SUB     R3, R12, #2\n"     
                "CMP     R3, #9\n"          
                "LDRLS   PC, [PC,R3,LSL#2]\n" 
                "B       loc_FF9631CC\n"    
                ".long loc_FF96318C\n"
                ".long loc_FF9631A4\n"
                ".long loc_FF9631AC\n"
                ".long loc_FF9631B4\n"
                ".long loc_FF963194\n"
                ".long loc_FF9631BC\n"
                ".long loc_FF96319C\n"
                ".long loc_FF9631CC\n"
                ".long loc_FF9631C4\n"
                ".long loc_FF963184\n"
"loc_FF963184:\n"                           
                                        
                "BL      sub_FF9632B0\n"    
                "B       loc_FF9631C8\n"    
"loc_FF96318C:\n"                           
                                        
                "BL      sub_FF9634C0\n"    
                "B       loc_FF9631C8\n"    
"loc_FF963194:\n"                           
                                        
                "BL      sub_FF96396C_my\n"    //-------------->
                "B       loc_FF9631C8\n"    
"loc_FF96319C:\n"                           
                                        
                "BL      sub_FF963DA0\n"    
                "B       loc_FF9631C8\n"    
"loc_FF9631A4:\n"                           
                                        
                "BL      sub_FF963C04\n"    
                "B       loc_FF9631C8\n"    
"loc_FF9631AC:\n"                           
                                        
                "BL      sub_FF964018\n"    
                "B       loc_FF9631C8\n"    
"loc_FF9631B4:\n"                           
                                        
                "BL      sub_FF9641DC\n"    
                "B       loc_FF9631C8\n"    
"loc_FF9631BC:\n"                           
                                        
                "BL      sub_FF963F30\n"    
                "B       loc_FF9631C8\n"    
"loc_FF9631C4:\n"                           
                                        
                "BL      sub_FF963C54\n"    
"loc_FF9631C8:\n"                           
                                        
                "LDR     R1, [SP]\n"        
"loc_FF9631CC:\n"                           
                                        
                "LDR     R3, [R1]\n"        
                "CMP     R3, #9\n"          
                "BNE     loc_FF9631E4\n"    
                "MOV     R0, R1\n"          
                "BL      sub_FF964370\n" 
                "LDR     R1, [SP]\n"        
"loc_FF9631E4:\n"                           
                "LDR     R3, =0x61074\n"    
                "MOV     R2, #0\n"          
                "LDR     R0, [R3]\n"        
                "STR     R2, [R1]\n"        
                "BL      sub_FF8208D4\n" 
                "LDR     R3, =0x61220\n"    
                "LDR     R0, [R3]\n"        
                "BL      sub_FF821250\n"   
"loc_FF963204:\n"                           
                "LDR     R3, =0x61070\n"    
                "MOV     R1, R4\n"          
                "LDR     R0, [R3]\n"        
                "MOV     R2, #0\n"          
                "BL      sub_FF8204BC\n" 
                "LDR     R3, =0x61220\n"    
                "MOV     R1, #0\n"          
                "LDR     R0, [R3]\n"        
                "BL      sub_FF821068\n"   
                "LDR     R0, [SP]\n"        
                "LDR     R12, [R0]\n"       
                "CMP     R12, #0xC\n"       
                "MOV     R1, R0\n"          
                "BNE     loc_FF96313C\n"    
                "LDR     R3, =0x6106C\n"    
                "LDR     R0, [R3]\n"        
                "BL      sub_FF821250\n"   
                "BL      sub_FF821A18\n"        
                "ADD     SP, SP, #4\n"      
                "LDMFD   SP!, {R4,PC}\n"    
 );
}

void __attribute__((naked,noinline)) sub_FF96396C_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n" 
                "LDR     R5, =0x6115C\n"    
                "SUB     SP, SP, #0x34\n"   
                "LDR     R3, [R5]\n"        
                "CMP     R3, #3\n"          
                "MOV     R4, R0\n"          
                "MOVEQ   R3, #4\n"          
                "STREQ   R3, [R5]\n"        
                "LDR     R3, =0x6120C\n"    
                "MOV     LR, PC\n"          
                "LDR     PC, [R3]\n"        
                "LDR     R2, [R5]\n"        
                "CMP     R2, #4\n"          
                "BNE     loc_FF963B30\n"    
                "ADD     R0, SP, #0x30\n"   
                "ADD     R1, SP, #0x2C\n"   
                "ADD     R2, SP, #0x28\n"   
                "ADD     R3, SP, #0x24\n"   
                "BL      sub_FF965910_my\n"       // -------------------->
                "CMP     R0, #0\n"          
                "BNE     loc_FF9639E8\n"    
                "LDR     R3, =0x61148\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R2, #1\n"          
                "BNE     loc_FF9639FC\n"    
                "LDR     R2, =0x611A0\n"    
                "LDR     R1, =0x61174\n"    
                "LDR     R12, [R2]\n"       
                "LDR     R3, [R1]\n"        
                "CMP     R12, R3\n"         
                "BCC     loc_FF9639FC\n"    
"loc_FF9639E8:\n"                           
                "BL      sub_FF963B7C\n"    
                "BL      sub_FF963D7C\n"    
                "MOV     R3, #5\n"          
                "STR     R3, [R5]\n"        
                "B       loc_FF963B30\n"    
"loc_FF9639FC:\n"                           
                                        
                "LDR     R12, =0x611A8\n"   
                "LDR     R11, =0x611B4\n"   
                "LDMIB   R4, {R0-R2}\n"     
                "LDR     R10, [R12]\n"      
                "LDR     R7, [R11]\n"       
                "LDR     R4, [SP,#0x2C]\n"  
                "LDR     R5, [SP,#0x28]\n"  
                "LDR     R6, [SP,#0x24]\n"  
                "LDR     R8, =0x6114C\n"    
                "LDR     R3, [SP,#0x30]\n"  
                "ADD     R12, SP, #0x20\n"  
                "ADD     LR, SP, #0x1C\n"   
                "MOV     R9, #1\n"          
                "STMEA   SP, {R4-R6,R12}\n" 
                "STR     R10, [SP,#0x10]\n" 
                "STR     R7, [SP,#0x14]\n"  
                "STR     LR, [SP,#0x18]\n"  
                "STR     R9, [R8]\n"        
                "BL      sub_FF8984C8\n"    
                "LDR     R3, =0x61064\n"    
                "MOV     R1, #0x3E8\n"      
                "LDR     R0, [R3]\n"        
                "BL      sub_FF821068\n"   
                "CMP     R0, #9\n"          
                "BNE     loc_FF963A70\n"    
                "BL      sub_FF966184\n"    
                "LDR     R3, =0x6115C\n"    
                "LDR     R0, =0xFF963954\n" 
                "B       loc_FF963A88\n"    
"loc_FF963A70:\n"                           
                "LDR     R5, [SP,#0x1C]\n"  
                "CMP     R5, #0\n"          
                "BEQ     loc_FF963A94\n"    
                "BL      sub_FF966184\n"    
                "LDR     R3, =0x6115C\n"    
                "LDR     R0, =0xFF963960\n" 
"loc_FF963A88:\n"                           
                "STR     R9, [R3]\n"        
                "BL      sub_FF986B94\n"    
                "B       loc_FF963B30\n"    
"loc_FF963A94:\n"                           
                "BL      sub_FF898634\n"    
                "LDR     R0, [SP,#0x30]\n"  
                "LDR     R1, [SP,#0x20]\n"  
                "BL      sub_FF965E94\n"    
                "LDR     R4, =0x611A0\n"    
                "LDR     R3, [R4]\n"        
                "ADD     R3, R3, #1\n"      
                "LDR     R0, [SP,#0x20]\n"  
                "MOV     R1, R11\n"         
                "STR     R3, [R4]\n"        
                "MOV     R2, R5\n"          
                "BL      sub_FF964B98_my\n"   //----------------->
                "LDR     R3, =0x611C0\n"    
                "LDR     R1, [R4]\n"        
                "LDR     R2, [R3]\n"        
                "LDR     R12, =0x611BC\n"   
                "MUL     R0, R2, R1\n"      
                "LDR     R1, [R12]\n"       
                "BL      sub_FFB4AF3C\n"       
                "LDR     R7, =0x611B8\n"    
                "LDR     R3, [R7]\n"        
                "MOV     R4, R0\n"          
                "CMP     R3, R4\n"          
                "BNE     loc_FF963B08\n"    
                "LDR     R6, =0x61150\n"    
                "LDR     R3, [R6]\n"        
                "CMP     R3, #1\n"          
                "BNE     loc_FF963B24\n"    
                "B       loc_FF963B0C\n"    
"loc_FF963B08:\n"                           
                "LDR     R6, =0x61150\n"    
"loc_FF963B0C:\n"                           
                "LDR     R3, =0x611F0\n"    
                "MOV     R0, R4\n"          
                "MOV     LR, PC\n"          
                "LDR     PC, [R3]\n"        
                "STR     R5, [R6]\n"        
                "STR     R4, [R7]\n"        
"loc_FF963B24:\n"                           
                "LDR     R2, =0x6114C\n"    
                "MOV     R3, #0\n"          
                "STR     R3, [R2]\n"        
"loc_FF963B30:\n"                           
                "ADD     SP, SP, #0x34\n"   
                "LDMFD   SP!, {R4-R11,PC}\n" 
 );
}



void __attribute__((naked,noinline)) sub_FF965910_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n" 
                "LDR     R5, =0x61518\n"    
                "SUB     SP, SP, #0x14\n"   
                "LDR     LR, [R5]\n"        
                "LDR     R12, =0x61530\n"   
                "ADD     LR, LR, #1\n"      
                "LDR     R4, [R12]\n"       
                "STR     LR, [R5]\n"        
                "LDR     R12, =0x615B4\n"   
                "STR     R0, [SP,#0x10]\n"  
                "STR     R1, [SP,#0xC]\n"   
                "STR     R2, [SP,#8]\n"     
                "STR     R3, [SP,#4]\n"     
                "CMP     LR, R4\n"          
                "LDR     R11, [R12]\n"      
                "MOVHI   R0, #0x80000001\n" 
                "BHI     loc_FF965E40\n"    
                "LDR     R3, =0x61598\n"    
                "MOV     R0, LR\n"          
                "LDR     R1, [R3]\n"        
                "BL      sub_FFB4B5CC\n"       
                "CMP     R0, #1\n"          
                "BNE     loc_FF965B40\n"    
                "LDR     R0, =0x615BC\n"    
                "LDR     R1, =0x61500\n"    
                "LDR     R3, [R0]\n"        
                "LDR     R2, [R1]\n"        
                "CMP     R3, R2\n"          
                "LDREQ   R3, =0x615B8\n"    
                "LDREQ   R5, [R3]\n"        
                "MOVNE   R5, R2\n"          
                "LDR     R3, =0x61518\n"    
                "LDR     R2, =0x61598\n"    
                "LDR     R0, [R3]\n"        
                "LDR     R1, [R2]\n"        
                "BL      sub_FFB4AF3C\n"       
                "LDR     R2, =0xAAAAAAAB\n" 
                "ADD     R0, R0, #1\n"      
                "UMULL   R1, R3, R2, R0\n"  
                "MOV     R3, R3,LSR#1\n"    
                "ADD     R3, R3, R3,LSL#1\n" 
                "LDR     R2, =0x61508\n"    
                "RSB     R0, R3, R0\n"      
                "STR     R5, [R2,R0,LSL#2]\n" 
                "LDR     R3, =0x614FC\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R5, R2\n"          
                "BHI     loc_FF9659F0\n"    
                "LDR     R4, =0x61550\n"    
                "LDR     R3, [R4]\n"        
                "ADD     R3, R5, R3\n"      
                "ADD     R3, R3, #8\n"      
                "CMP     R2, R3\n"          
                "BCS     loc_FF9659F4\n"    
"loc_FF9659E8:\n"                           
                                        
                "MOV     R0, #0x80000003\n" 
                "B       loc_FF965E40\n"    
"loc_FF9659F0:\n"                           
                "LDR     R4, =0x61550\n"    
"loc_FF9659F4:\n"                           
                "LDR     R3, [R4]\n"        
                "LDR     R2, =0x615BC\n"    
                "ADD     R1, R5, R3\n"      
                "LDR     R3, [R2]\n"        
                "ADD     R2, R1, #8\n"      
                "CMP     R2, R3\n"          
                "BLS     loc_FF965A40\n"    
                "LDR     R2, =0x615B8\n"    
                "LDR     R0, =0x614FC\n"    
                "RSB     R3, R3, R1\n"      
                "LDR     R1, [R2]\n"        
                "ADD     R3, R3, #8\n"      
                "LDR     R2, [R0]\n"        
                "ADD     R1, R1, R3\n"      
                "CMP     R2, R1\n"          
                "BCC     loc_FF9659E8\n"    
                "LDR     R3, =0x61500\n"    
                "STR     R1, [R3]\n"        
                "B       loc_FF965A48\n"    
"loc_FF965A40:\n"                           
                "LDR     R3, =0x61500\n"    
                "STR     R2, [R3]\n"        
"loc_FF965A48:\n"                           
                "LDR     R3, [R4]\n"        
                "LDR     R12, =0x61568\n"   
                "ADD     R3, R3, #0x18\n"   
                "LDR     R2, [R12,#4]\n"    
                "MOV     R0, R3\n"          
                "MOV     R1, #0\n"          
                "CMP     R1, R2\n"          
                "BHI     loc_FF965C8C\n"    
                "BNE     loc_FF965A78\n"    
                "LDR     R3, [R12]\n"       
                "CMP     R0, R3\n"          
                "BHI     loc_FF965C8C\n"    
"loc_FF965A78:\n"                           
                "LDR     R4, [R4]\n"        
                "LDR     LR, =0x61570\n"    
                "STR     R4, [SP]\n"        
                "LDR     R12, =0x61568\n"   
                "LDR     R3, =0x61518\n"    
                "LDMIA   LR, {R7,R8}\n"     
                "LDMIA   R12, {R5,R6}\n"    
                "LDR     R10, [R3]\n"       
                "LDR     R2, =0x61598\n"    
                "MOV     R3, R4\n"          
                "MOV     R4, #0\n"          
                "ADDS    R7, R7, R3\n"      
                "ADC     R8, R8, R4\n"      
                "LDR     R9, [R2]\n"        
                "SUBS    R5, R5, R3\n"      
                "SBC     R6, R6, R4\n"      
                "MVN     R2, #0\n"          
                "MVN     R1, #0x17\n"       
                "ADDS    R5, R5, R1\n"      
                "MOV     R4, #0\n"          
                "MOV     R3, #0x18\n"       
                "ADC     R6, R6, R2\n"      
                "ADDS    R7, R7, R3\n"      
                "ADC     R8, R8, R4\n"      
                "STMIA   R12, {R5,R6}\n"    
                "SUB     R0, R10, #1\n"     
                "MOV     R1, R9\n"          
                "STMIA   LR, {R7,R8}\n"     
                "BL      sub_FFB4AF3C\n"       
                "CMP     R10, #1\n"         
                "MLA     R0, R9, R0, R0\n"  
                "BEQ     loc_FF965B40\n"    
                "SUB     R3, R0, #1\n"      
                "MOV     R3, R3,LSL#4\n"    
                "ADD     R4, R11, #0x10\n"  
                "ADD     R5, R11, #0x14\n"  
                "LDR     R1, [R5,R3]\n"     
                "LDR     R2, [R4,R3]\n"     
                "LDR     LR, =0x62773130\n" 
                "ADD     R2, R2, R1\n"      
                "MOV     R3, R0,LSL#4\n"    
                "ADD     R2, R2, #8\n"      
                "MOV     R0, #0\n"          
                "ADD     R12, R11, #0xC\n"  
                "ADD     R1, R11, #8\n"     
                "STR     LR, [R1,R3]\n"     
                "STR     R0, [R12,R3]\n"    
                "STR     R2, [R4,R3]\n"     
                "LDR     R0, [SP]\n"        
                "STR     R0, [R5,R3]\n"     
"loc_FF965B40:\n"                           
                                        
                "LDR     R2, =0x61500\n"    
                "LDR     R3, =0x615BC\n"    
                "LDR     R1, [R2]\n"        
                "LDR     R0, [R3]\n"        
                "ADD     R3, R1, #9\n"      
                "CMP     R3, R0\n"          
                "BLS     loc_FF965B7C\n"    
                "LDR     R2, =0x615B8\n"    
                "LDR     R3, [R2]\n"        
                "ADD     R3, R3, R1\n"      
                "RSB     R3, R0, R3\n"      
                "LDR     R0, [SP,#0x10]\n"  
                "ADD     R3, R3, #8\n"      
                "STR     R3, [R0]\n"        
                "B       loc_FF965B88\n"    
"loc_FF965B7C:\n"                           
                "ADD     R3, R1, #8\n"      
                "LDR     R1, [SP,#0x10]\n"  
                "STR     R3, [R1]\n"        
"loc_FF965B88:\n"                           
                "LDR     R2, [SP,#0x10]\n"  
                "LDR     R1, =0x61560\n"    
                "LDR     R3, =0x615BC\n"    
                "LDR     R12, [R2]\n"       
                "LDR     R2, [R1]\n"        
                "LDR     R0, [R3]\n"        
                "ADD     R3, R12, R2\n"     
                "CMP     R3, R0\n"          
                "BLS     loc_FF965BDC\n"    
                "LDR     R2, [SP,#0xC]\n"   
                "RSB     R0, R12, R0\n"     
                "STR     R0, [R2]\n"        
                "LDR     R2, =0x615B8\n"    
                "LDR     R3, [R1]\n"        
                "LDR     R1, [R2]\n"        
                "RSB     R3, R0, R3\n"      
                "LDR     R0, [SP,#8]\n"     
                "STR     R1, [R0]\n"        
                "LDR     R1, [SP,#4]\n"     
                "STR     R3, [R1]\n"        
                "B       loc_FF965BF8\n"    
"loc_FF965BDC:\n"                           
                "LDR     R0, [SP,#0xC]\n"   
                "STR     R2, [R0]\n"        
                "LDR     R1, [SP,#4]\n"     
                "MOV     R3, #0\n"          
                "STR     R3, [R1]\n"        
                "LDR     R2, [SP,#8]\n"     
                "STR     R3, [R2]\n"        
"loc_FF965BF8:\n"                           
                "LDR     R0, =0x61500\n"    
                "LDR     R1, =0x614FC\n"    
                "LDR     R3, [R0]\n"        
                "LDR     R2, [R1]\n"        
                "CMP     R3, R2\n"          
                "BHI     loc_FF965C24\n"    
                "LDR     R0, [SP,#0xC]\n"   
                "LDR     R3, [R0]\n"        
                "ADD     R3, R12, R3\n"     
                "CMP     R2, R3\n"          
                "BCC     loc_FF9659E8\n"    
"loc_FF965C24:\n"                           
                "LDR     R1, [SP,#8]\n"     
                "LDR     R2, [R1]\n"        
                "CMP     R2, #0\n"          
                "BEQ     loc_FF965C58\n"    
                "LDR     R3, =0x614FC\n"    
                "LDR     R1, [R3]\n"        
                "CMP     R2, R1\n"          
                "BHI     loc_FF965C58\n"    
                "LDR     R0, [SP,#4]\n"     
                "LDR     R3, [R0]\n"        
                "ADD     R3, R2, R3\n"      
                "CMP     R1, R3\n"          
                "BCC     loc_FF9659E8\n"    
"loc_FF965C58:\n"                           
                                        
                "LDR     R3, =0x61560\n"    
                "LDR     R0, =0x61568\n"    
                "LDR     R2, [R3]\n"        
                "LDR     R3, [R0,#4]\n"     
                "ADD     R2, R2, #0x18\n"   
                "MOV     R1, R2\n"          
                "MOV     R2, #0\n"          
                "CMP     R2, R3\n"          
                "BHI     loc_FF965C8C\n"    
                "BNE     loc_FF965C94\n"    
                "LDR     R3, [R0]\n"        
                "CMP     R1, R3\n"          
                "BLS     loc_FF965C94\n"    
"loc_FF965C8C:\n"                           
                                        
                "MOV     R0, #0x80000005\n" 
                "B       loc_FF965E40\n"    
"loc_FF965C94:\n"                           
                                        
                "LDR     R1, =0x61548\n"    
                "LDR     R0, =0x61598\n"    
                "LDR     R3, [R1]\n"        
                "LDR     R2, [R0]\n"        
                "ADD     R3, R3, R2,LSL#4\n" 
                "ADD     R3, R3, R3,LSL#2\n" 
                "LDR     R12, =0x61568\n"   
                "MOV     R3, R3,LSL#1\n"    
                "ADD     R3, R3, #0xA0\n"   
                "LDR     R2, [R12,#4]\n"    
                "MOV     R0, R3\n"          
                "MOV     R1, #0\n"          
                "CMP     R1, R2\n"          
                "BHI     loc_FF965CDC\n"    
                "BNE     loc_FF965D00\n"    
                "LDR     R3, [R12]\n"       
                "CMP     R0, R3\n"          
                "BLS     loc_FF965D00\n"    
"loc_FF965CDC:\n"                           
                "LDR     R4, =0x61580\n"    
                "LDR     R1, [R4]\n"        
                "CMP     R1, #0\n"          
                "BNE     loc_FF965D00\n"    
                "MOV     R0, #0x3140\n"     
                "ADD     R0, R0, #8\n"      
                "BL      sub_FF98B0C4\n"    
                "MOV     R3, #1\n"          
                "STR     R3, [R4]\n"        
"loc_FF965D00:\n"                           
                                        
                "LDR     R1, =0x61548\n"    
                "LDR     R0, =0x61598\n"    
                "LDR     R2, [R1]\n"        
                "LDR     R3, [R0]\n"        
                "LDR     R0, =0x61570\n"    
                "ADD     R2, R2, R3,LSL#4\n" 
                "MVN     R3, #0x9F\n"       
                "ADD     R2, R2, R2,LSL#2\n" 
                "ADD     R3, R3, #0x40000000\n" 
                "SUB     R3, R3, R2,LSL#1\n" 
                "LDR     R1, [R0,#4]\n"     
                "MOV     R4, R3\n"          
                "MOV     R5, #0\n"          
                "CMP     R1, R5\n"          
                "BHI     loc_FF965D4C\n"    
                "BNE     loc_FF965D70\n"    
                "LDR     R3, [R0]\n"        
                "CMP     R3, R4\n"          
                "BLS     loc_FF965D70\n"    
"loc_FF965D4C:\n"                           
                "LDR     R4, =0x61580\n"    
                "LDR     R1, [R4]\n"        
                "CMP     R1, #0\n"          
                "BNE     loc_FF965D70\n"    
                "MOV     R0, #0x3140\n"     
                "ADD     R0, R0, #8\n"      
                "BL      sub_FF98B0C4\n"    
                "MOV     R3, #1\n"          
                "STR     R3, [R4]\n"        
"loc_FF965D70:\n"                           
                                        
                "LDR     R3, =0x61598\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R2, #0x3C\n"       
                "BNE     loc_FF965DA8\n"    
                "LDR     R3, =0x615AA\n"    
                "LDRH    R2, [R3]\n"        
                "CMP     R2, #2\n"          
                "BNE     loc_FF965DA8\n"    
                "LDR     R3, =0x61518\n"    
                "MOV     R2, #0x34800\n"    
                "LDR     R1, [R3]\n"        
                "ADD     R2, R2, #0x90\n"   
                "CMP     R1, R2\n"          
                "B       loc_FF965DD0\n"    
"loc_FF965DA8:\n"                           
                                        
                "LDR     R3, =0x61598\n"    
                "LDR     R0, =0x61530\n"    
                "LDR     R2, [R3]\n"        
                "LDR     R12, =0x61518\n"   
                "LDR     R1, [R0]\n"        
                "ADD     R3, R2, R2,LSL#2\n" 
                "ADD     R2, R2, R3,LSL#1\n" 
                "LDR     R0, [R12]\n"       
                "RSB     R1, R2, R1\n"      
                "CMP     R0, R1\n"          
"loc_FF965DD0:\n"                           
                "BLS     loc_FF965DF8\n"    
                "LDR     R4, =0x61580\n"    
                "LDR     R1, [R4]\n"        
                "CMP     R1, #0\n"          
                "BNE     loc_FF965DF8\n"    
                "MOV     R0, #0x3140\n"     
                "ADD     R0, R0, #8\n"      
                "BL      sub_FF98B0C4\n"    
                "MOV     R3, #1\n"          
                "STR     R3, [R4]\n"        
"loc_FF965DF8:\n"                           
                                        
                "LDR     R3, =0x61570\n"    
                "LDR     R12, =0x61560\n"   
                "LDMIA   R3, {R1,R2}\n"     
                "LDR     R0, [R12]\n"       
                "MOV     R4, #0\n"          
                "MOV     R3, #0x18\n"       
                "ADDS    R1, R1, R0\n"      
                "ADC     R2, R2, #0\n"      
                "ADDS    R1, R1, R3\n"      
                "ADC     R2, R2, R4\n"      
                "CMP     R2, #0\n"          
                "BHI     loc_FF965E34\n"    
                "BNE     loc_FF965E3C\n"    
                "CMP     R1, #0x40000000\n" 
               // "BLS     loc_FF965E3C\n"    // -

                "B       loc_FF965E3C\n"      // +

"loc_FF965E34:\n"                           
                "MOV     R0, #0x80000007\n" 
                "B       loc_FF965E40\n"    
"loc_FF965E3C:\n"                           
                                        
                "MOV     R0, #0\n"          
"loc_FF965E40:\n"                           
                                        
                "ADD     SP, SP, #0x14\n"   
                "LDMFD   SP!, {R4-R11,PC}\n" 

 );
}


void __attribute__((naked,noinline)) sub_FF964B98_my(){
 asm volatile(
                "CMP     R2, #1\n"          
                "STMFD   SP!, {R4-R8,R10,LR}\n" 
                "MOV     R10, R0\n"         
                "MOV     R8, R1\n"          
                "MOVEQ   R3, #0x79\n"       
                "STREQ   R3, [R8]\n"        
                "LDMEQFD SP!, {R4-R8,R10,PC}\n" 
                "LDR     R1, =0x61274\n"    
                "LDR     R5, [R1]\n"        
                "LDR     R3, =0x6127C\n"    
                "CMP     R5, #0\n"          
                "LDR     R0, [R3]\n"        
                "BEQ     loc_FF964BE0\n"    
                "LDR     R2, =0x61280\n"    
                "LDR     R3, [R2]\n"        
                "CMP     R3, #1\n"          
                "BNE     loc_FF964BF4\n"    
                "B       loc_FF964BE4\n"    
"loc_FF964BE0:\n"                           
                "LDR     R2, =0x61280\n"    
"loc_FF964BE4:\n"                           
                "MOV     R3, #0\n"          
                "STR     R3, [R2]\n"        
                "STR     R10, [R1]\n"       
                "B       loc_FF964CB4\n"    
"loc_FF964BF4:\n"                           
                "LDR     R3, =0x61278\n"    
                "LDR     R2, [R3]\n"        
                "LDR     R7, =table1\n" // +  0xFF964984
                "RSB     R3, R2, R2,LSL#3\n" 
                "MOV     R4, R3,LSL#3\n"    
                "LDR     R1, [R7,R4]\n"     
                "ADD     R2, R2, R2,LSL#1\n" 
                "LDR     R6, =table2\n"  // +  0xFF964A2C
                "MOV     LR, R2,LSL#2\n"    
                "RSB     R12, R1, R5\n"     
                "LDR     R3, [R6,LR]\n"     
                "CMP     R12, #0\n"         
                "RSB     R1, R3, R5\n"      
                "BLE     loc_FF964C60\n"    
                "ADD     R3, R7, #4\n"      
                "LDR     R2, [R3,R4]\n"     
                "CMP     R2, R12\n"         
                "ADDGE   R0, R0, #1\n"      
                "BGE     loc_FF964C54\n"    
                "ADD     R3, R7, #8\n"      
                "LDR     R2, [R3,R4]\n"     
                "CMP     R2, R12\n"         
                "ADDGE   R0, R0, #2\n"      
                "ADDLT   R0, R0, #3\n"      
"loc_FF964C54:\n"                           
            //  "CMP     R0, #0xE\n"   // -     
            //  "MOVGE   R0, #0xE\n"   // -     

                "CMP     R0, #0x1A\n"  // +      
                "MOVGE   R0, #0x1A\n"  // +      

                "B       loc_FF964C98\n"    
"loc_FF964C60:\n"                           
                "CMP     R1, #0\n"          
                "BGE     loc_FF964C98\n"    
                "ADD     R3, R6, #4\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R1\n"          
                "SUBLE   R0, R0, #1\n"      
                "BLE     loc_FF964C90\n"    
                "ADD     R3, R6, #8\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R1\n"          
                "SUBLE   R0, R0, #2\n"      
                "SUBGT   R0, R0, #3\n"      
"loc_FF964C90:\n"                           
                "CMP     R0, #0\n"          
                "MOVLT   R0, #0\n"          
"loc_FF964C98:\n"                           
                                        
                "LDR     R1, =0x6127C\n"    
                "LDR     R3, [R1]\n"        
                "CMP     R0, R3\n"          
                "LDRNE   R2, =0x61280\n"    
                "MOVNE   R3, #1\n"          
                "STRNE   R0, [R1]\n"        
                "STRNE   R3, [R2]\n"        
"loc_FF964CB4:\n"                           
                "LDR     R3, =0x6127C\n"    
            //  "LDR     R1, =0x65E0\n"     //-
                "LDR     R1, =video_mode\n" //+
                "LDR     R0, [R3]\n"        
                "LDR     R2, =CompressionRateTable\n" //+ 0xFF964948
                "LDR     R12, [R1]\n"

                "LDR     R12, [R12]\n" //+
                                 
                "LDR     LR, [R2,R0,LSL#2]\n" 
                "LDR     R3, =0x61274\n"    
                "CMP     R12, #1\n"         
                "STR     R10, [R3]\n"       
                "STR     LR, [R8]\n"        
           //   "MOVEQ   R3, #0xB\n"  //-     

                "LDREQ   R3, =video_quality\n"  //+               
                "LDREQ   R3, [R3]\n"      //+              
                "LDREQ   R3, [R3]\n"      //+              

                "STREQ   R3, [R8]\n"        
                "LDMFD   SP!, {R4-R8,R10,PC}\n" 
 );
}
