/*This file was automatically generated.*/
#ifndef d_sound_h
#define d_sound_h

typedef struct sound sound;
void resume_sound(sound *s);
void pause_sound(sound *s);
void play_sound(sound *s);
void dtor_sound(sound *s);
sound *ctor_sound(char *sound_file_path,bool loop);
void init_sound();
#define EXPORT_INTERFACE 0

#endif
