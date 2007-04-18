#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"
#include "stdlib.h"
#include "gui.h"
#include "histogram.h"
#include "raw.h"

static int raw_need_postprocess;

#if 0
int taskop_txt_p;
char taskop_txt[6][32];
#endif

void core_hook_task_create(void *tcb)
{
#if 0
    char *name = (char*)(*(long*)((char*)tcb+0x34));
    strcpy(taskop_txt[taskop_txt_p]+1, name);
    taskop_txt[taskop_txt_p][0] = 'S';
    taskop_txt_p++;
    if (taskop_txt_p>5)
	taskop_txt_p = 0;
#endif
}

void core_hook_task_delete(void *tcb)
{
#if 0
    char *name = (char*)(*(long*)((char*)tcb+0x34));
    strcpy(taskop_txt[taskop_txt_p]+1, name);
    taskop_txt[taskop_txt_p][0] = 'E';

    taskop_txt_p++;
    if (taskop_txt_p>5)
	taskop_txt_p = 0;
#endif
}

void dump_memory()
{
    int fd;
    static int cnt=0;
    static char fn[32];

//((void (*)(int v))(0xFFC5BCC0))(0x7F); //Make_BOOTDISK
    started();

	sprintf(fn, "A/DCIM/100CANON/CRW_%04d.JPG", cnt++);
	fd = open(fn, O_WRONLY|O_CREAT, 0777);
	if (fd) {
//            fwrite((void*)vid_get_viewport_fb(), 360*240*3, 1, fd);
//            fwrite((void*)vid_get_bitmap_fb(), 360*240, 1, fd);
	    write(fd, (void*)0, 0x1900);
	    write(fd, (void*)0x1900, 32*1024*1024-0x1900);
	    close(fd);
	}
    finished();
}

static volatile long raw_data_available;

/* called from another process */
void core_rawdata_available()
{
    raw_data_available = 1;
}


void core_spytask()
{
    int cnt = 0;

    raw_need_postprocess = 0;

    msleep(2000);

    conf_restore();
    gui_init();

    started();
    msleep(50);
    finished();

    mkdir("A/FONTS");
    mkdir("A/SCRIPTS");

    while (1){

	if (raw_data_available){
            raw_need_postprocess = raw_savefile();
	    hook_raw_save_complete();
	    raw_data_available = 0;
	    continue;
	}

	if (((cnt++) & 3) == 0)
	    gui_redraw();

	histogram_process();

	hook_raw_install();

	if ((state_shooting_progress == SHOOTING_PROGRESS_PROCESSING) && (!shooting_in_progress())) {
	    state_shooting_progress = SHOOTING_PROGRESS_DONE;
            if (raw_need_postprocess) raw_postprocess();
        }

	msleep(20);
    }
}

