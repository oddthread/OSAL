#ifndef d_input_h
#define d_input_h

#include "opl/src/h/util.h"

void init_input();

vec2 get_mouse_position();
typedef struct event
{
	s64 type;
	bool pressed;
	vec2 mouse_info;
	s64 id;
	char *str;
} event;

/*on windows you must call this every frame*/
event *poll_input(event*);

extern const s32 ALL_EVENTS;
extern const s32 MOUSE_EVENTS;
void flush_events(s32 event_type);

char apply_shift(char c,bool include_non_alpha);

void set_mouse_capture_on_currently_focused_window(bool capture);
typedef struct system_cursor system_cursor;

extern system_cursor *CURSOR_TEXT;
extern system_cursor *CURSOR_NORMAL;
extern system_cursor *CURSOR_HAND;

void set_cursor(system_cursor *);

s32 get_mod_state();//call to get thing to and with mods
/*other constants*/
extern const s32 KEY_MOD_CAPS;
extern const s32 KEY_MOD_SHIFT;

/*event constants*/
extern const s64 LEFT_MOUSE;
extern const s64 RIGHT_MOUSE;
extern const s64 MIDDLE_MOUSE;
extern const s64 MOUSE_MOTION;
extern const s64 MOUSE_WHEEL;

extern const s64 DROP_FILE;

extern const s64 KEY_LEFT;
extern const s64 KEY_RIGHT;
extern const s64 KEY_UP;
extern const s64 KEY_DOWN;
extern const s64 KEY_INSERT;
extern const s64 KEY_DELETE;
extern const s64 KEY_HOME;
extern const s64 KEY_END;
extern const s64 KEY_PAGE_UP;
extern const s64 KEY_PAGE_DOWN;
extern const s64 KEY_PRINT_SCREEN;
extern const s64 KEY_SCROLL_LOCK;
extern const s64 KEY_PAUSE_BREAK;
extern const s64 KEY_KP_0;
extern const s64 KEY_KP_1;
extern const s64 KEY_KP_2;
extern const s64 KEY_KP_3;
extern const s64 KEY_KP_4;
extern const s64 KEY_KP_5;
extern const s64 KEY_KP_6;
extern const s64 KEY_KP_7;
extern const s64 KEY_KP_8;
extern const s64 KEY_KP_9;
extern const s64 KEY_KP_NUM_LOCK;
extern const s64 KEY_KP_DIVIDE;
extern const s64 KEY_KP_MULTIPLY;
extern const s64 KEY_KP_ADD;
extern const s64 KEY_KP_SUBTRACT;
extern const s64 KEY_KP_ENTER;
extern const s64 KEY_KP_PERIOD;
extern const s64 KEY_ESCAPE;
extern const s64 KEY_GRAVE;
extern const s64 KEY_0;
extern const s64 KEY_1;
extern const s64 KEY_2;
extern const s64 KEY_3;
extern const s64 KEY_4;
extern const s64 KEY_5;
extern const s64 KEY_6;
extern const s64 KEY_7;
extern const s64 KEY_8;
extern const s64 KEY_9;
extern const s64 KEY_SUBTRACT;
extern const s64 KEY_EQUALS;
extern const s64 KEY_F1;
extern const s64 KEY_F2;
extern const s64 KEY_F3;
extern const s64 KEY_F4;
extern const s64 KEY_F5;
extern const s64 KEY_F6;
extern const s64 KEY_F7;
extern const s64 KEY_F8;
extern const s64 KEY_F9;
extern const s64 KEY_F10;
extern const s64 KEY_F11;
extern const s64 KEY_F12;
extern const s64 KEY_TAB;
extern const s64 KEY_CAPS_LOCK;
extern const s64 KEY_ENTER;
extern const s64 KEY_BACKSPACE;
extern const s64 KEY_SPACE;
extern const s64 KEY_LEFT_BRACKET;
extern const s64 KEY_RIGHT_BRACKET;
extern const s64 KEY_SEMI_COLON;
extern const s64 KEY_QUOTE;
extern const s64 KEY_PERIOD;
extern const s64 KEY_COMMA;
extern const s64 KEY_DIVIDE;
extern const s64 KEY_BACK_SLASH;
extern const s64 KEY_A;
extern const s64 KEY_B;
extern const s64 KEY_C;
extern const s64 KEY_D;
extern const s64 KEY_E;
extern const s64 KEY_F;
extern const s64 KEY_G;
extern const s64 KEY_H;
extern const s64 KEY_I;
extern const s64 KEY_J;
extern const s64 KEY_K;
extern const s64 KEY_L;
extern const s64 KEY_M;
extern const s64 KEY_N;
extern const s64 KEY_O;
extern const s64 KEY_P;
extern const s64 KEY_Q;
extern const s64 KEY_R;
extern const s64 KEY_S;
extern const s64 KEY_T;
extern const s64 KEY_U;
extern const s64 KEY_V;
extern const s64 KEY_W;
extern const s64 KEY_X;
extern const s64 KEY_Y;
extern const s64 KEY_Z;
extern const s64 KEY_LEFT_SHIFT;
extern const s64 KEY_LEFT_CONTROL;
extern const s64 KEY_LEFT_ALT;
extern const s64 KEY_RIGHT_SHIFT;
extern const s64 KEY_RIGHT_CONTROL;
extern const s64 KEY_RIGHT_ALT;

extern const s64 WINDOW_CLOSE;
extern const s64 FOCUS_GAINED;
extern const s64 FOCUS_LOST;

#endif
