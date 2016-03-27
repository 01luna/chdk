#0x314F
PLATFORMID=12623

PLATFORMOS=vxworks

MEMBASEADDR=0x1900
RESTARTSTART=0x50000
MEMISOSTART=0xBEF70
MEMISOSIZE=0x40000
ROMBASEADDR=0xff810000

TARGET_PRIMARY=$(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)/PRIMARY.BIN

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)