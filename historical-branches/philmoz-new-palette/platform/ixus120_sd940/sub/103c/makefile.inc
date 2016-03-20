PLATFORMID=12774

PLATFORMOS=dryos

# Force ARAM on for ixus120_sd940, and load CHDK in ARAM
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=1

# Set up size variables for AgentRAM
ARAM_HEAP_START=0x34e000
ARAM_HEAP_SIZE=0x32000

ifdef OPT_CHDK_IN_ARAM
MEMISOSTART=$(ARAM_HEAP_START)
else
MEMISOSTART=0x13CA18
endif

ROMBASEADDR=0xFF810000

NEED_ENCODED_DISKBOOT=3

KEYSYS=d4

PLATFORMOSVER=39