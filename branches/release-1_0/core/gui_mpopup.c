#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "lang.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_mpopup.h"

// Simple popup menu. No title, no separators, only processing items

//-------------------------------------------------------------------
static enum Gui_Mode            gui_mpopup_mode_old;
static char                     mpopup_to_draw;

static struct {
        unsigned int            flag;
        int                     text;
} actions[] = {
        { MPOPUP_CUT,           LANG_POPUP_CUT    },
        { MPOPUP_COPY,          LANG_POPUP_COPY   },
        { MPOPUP_PASTE,         LANG_POPUP_PASTE  },
        { MPOPUP_DELETE,        LANG_POPUP_DELETE },
        { MPOPUP_SELINV,        LANG_POPUP_SELINV },
        { MPOPUP_RAW_ADD,       LANG_POPUP_RAW_SUM},
        { MPOPUP_RAW_AVERAGE,   LANG_POPUP_RAW_AVERAGE },
        { MPOPUP_RAW_DEVELOP,   LANG_MENU_RAW_DEVELOP },
        { MPOPUP_PURGE,         LANG_POPUP_PURGE  },
        { MPOPUP_SUBTRACT,      LANG_POPUP_SUB_FROM_MARKED  },
#if DNG_SUPPORT
        { MPOPUP_DNG_TO_CRW,    (int)"DNG -> CHDK RAW"},
#endif
};

#define ACTIONSNUM              (sizeof(actions)/sizeof(actions[0]))
#define MAX_ACTIONS             10

static int                      mpopup_actions[MAX_ACTIONS];    // Content of raised popupmenu
static int                      mpopup_actions_num;             // Num of items in raised popupmenu
static int                      mpopup_actions_active;          // Idx of current item (cursor)
static coord                    mpopup_actions_x, mpopup_actions_y;    // top-left coord of window
static unsigned int             mpopup_actions_w;               // width of window
static void (*mpopup_on_select)(unsigned int btn);

//-------------------------------------------------------------------
void gui_mpopup_init(const unsigned int flags, void (*on_select)(unsigned int actn)) {
    int i;

    mpopup_actions_num = 0;
    for (i=0; i<ACTIONSNUM && mpopup_actions_num<MAX_ACTIONS; ++i) {
        if (flags & MPOPUP_MASK & actions[i].flag)
            mpopup_actions[mpopup_actions_num++] = i;
    }
    if (mpopup_actions_num == 0)
        on_select(MPOPUP_CANCEL);

    mpopup_actions_active = 0;

    gui_mpopup_mode_old = gui_get_mode();
    mpopup_to_draw = 1;
    mpopup_on_select = on_select;
    gui_set_mode(GUI_MODE_MPOPUP);
}

//-------------------------------------------------------------------
unsigned int gui_mpopup_result() {
    return actions[mpopup_actions[mpopup_actions_active]].flag;
}

//-------------------------------------------------------------------
static void gui_mpopup_draw_actions() {
    int i;
    coord y = mpopup_actions_y;
    color cl;

    for (i=0; i<mpopup_actions_num; ++i) {
        cl = MAKE_COLOR((mpopup_actions_active==i)?COLOR_RED:COLOR_GREY, (mpopup_actions_active==i)?COLOR_RED:COLOR_GREY);
        draw_filled_rect(mpopup_actions_x, y, mpopup_actions_x+mpopup_actions_w*FONT_WIDTH, y+FONT_HEIGHT-1, cl);
        cl = MAKE_COLOR((mpopup_actions_active==i)?COLOR_RED:COLOR_GREY, COLOR_WHITE);
        draw_string(mpopup_actions_x+FONT_WIDTH, y, lang_str(actions[mpopup_actions[i]].text), cl);
        y+=FONT_HEIGHT;
    }
}

//-------------------------------------------------------------------
void gui_mpopup_draw() {
    if (mpopup_to_draw) {
        int i;
        coord x=0, y=0;
        unsigned int w, h;

        w = 0;
        for (i=0; i<mpopup_actions_num; ++i) {
            h=strlen(lang_str(actions[mpopup_actions[i]].text));
            if (h > w) w=h;
        }
        w+=2;
        h = mpopup_actions_num;
    
        x = 10*FONT_WIDTH;
        y = 5*FONT_HEIGHT;
        draw_rect_shadow(x-3, y-3, x+w*FONT_WIDTH+5, y+h*FONT_HEIGHT+4, COLOR_BLACK, 3); //shadow
        draw_filled_rect_thick(x-4, y-4, x+w*FONT_WIDTH+4, y+h*FONT_HEIGHT+3, MAKE_COLOR(COLOR_GREY, COLOR_WHITE), 3); // main box
    
        mpopup_actions_x = x;
        mpopup_actions_y = y;
        mpopup_actions_w = w;

        gui_mpopup_draw_actions();
        mpopup_to_draw = 0;
    }
}

//-------------------------------------------------------------------
void gui_mpopup_kbd_process() {
    switch (kbd_get_clicked_key() | get_jogdial_direction()) {
    case JOGDIAL_LEFT:
    case KEY_UP:
        if (mpopup_actions_active > 0) --mpopup_actions_active;
        else mpopup_actions_active = mpopup_actions_num-1;
        gui_mpopup_draw_actions();
        break;
    case JOGDIAL_RIGHT:
    case KEY_DOWN:
        if (mpopup_actions_active < mpopup_actions_num-1) ++mpopup_actions_active;
        else mpopup_actions_active = 0;
        gui_mpopup_draw_actions();
        break;
    case KEY_MENU:
    case KEY_LEFT:
        kbd_reset_autoclicked_key();
        gui_set_mode(gui_mpopup_mode_old);
        if (mpopup_on_select) 
            mpopup_on_select(MPOPUP_CANCEL);
        break;
    case KEY_SET:
        kbd_reset_autoclicked_key();
        gui_set_mode(gui_mpopup_mode_old);
        if (mpopup_on_select) 
            mpopup_on_select(actions[mpopup_actions[mpopup_actions_active]].flag);
        break;
    }
}

//-------------------------------------------------------------------
void gui_browser_progress_show(const char* msg, const unsigned int perc) {
    coord x=60, y=100;
    unsigned int w=240, h=40, len;

    draw_rect_shadow(x+1, y+1, x+w+1, y+h+1, COLOR_BLACK, 3); //shadow
    draw_filled_rect(x, y, x+w, y+h, MAKE_COLOR(COLOR_GREY, COLOR_WHITE)); // main box
    len = strlen(msg);
    draw_string(x+((w-len*FONT_WIDTH)>>1), y+2, msg, MAKE_COLOR(COLOR_GREY, COLOR_WHITE)); //title text
    draw_filled_rect(x+10, y+4+FONT_HEIGHT, x+w-10, y+h-10, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE)); // progress rect
    draw_filled_rect(x+11, y+5+FONT_HEIGHT, x+11+(w-22)*perc/100, y+h-11, MAKE_COLOR(COLOR_RED, COLOR_RED)); // progress bar
}