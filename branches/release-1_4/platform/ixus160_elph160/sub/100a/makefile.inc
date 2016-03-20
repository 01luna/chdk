PLATFORMID=12970
PLATFORMOS=dryos
PLATFORMOSVER=55

# Force ARAM on for ixus160_elph160; but do not load CHDK in ARAM (not enough memory)
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=

# Set up size variables for AgentRAM
ARAM_HEAP_START=0x60e000
ARAM_HEAP_SIZE=0x22000

# start of firmware
ROMBASEADDR=0xFF810000
MAXRAMADDR=0x07ffffff

MEMISOSTART=0x00185cb0

KEYSYS = d4g
NEED_ENCODED_DISKBOOT = 13
