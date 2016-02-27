PLATFORMID=12774

PLATFORMOS=dryos

MEMBASEADDR=0x1900
MEMISOSTART=0x13CA18
ROMBASEADDR=0xFF810000


PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)

NEED_ENCODED_DISKBOOT=3

KEYSYS=d4

PLATFORMOSVER=39