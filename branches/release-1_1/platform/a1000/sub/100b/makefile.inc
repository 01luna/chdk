# USB ID: 04a9:318E
PLATFORMID=12686

PLATFORMOS=dryos

MEMBASEADDR=0x1900
RESTARTSTART=0x50000
MEMISOSTART=0xd4ec8
ROMBASEADDR=0xffc00000

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)

NEED_ENCODED_DISKBOOT=1
KEYSYS=d4

PLATFORMOSVER=31