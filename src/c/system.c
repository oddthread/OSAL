#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#include "../h/system.h"
#include "../h/gpu.h"
#include "../h/util.h"
#include <time.h>


char *get_clipboard_text()
{
	return SDL_GetClipboardText();
}
void sdl_free(void* p)
{
	SDL_free(p);
}
void set_clipboard_text(char *c)
{
	SDL_SetClipboardText(c);
}
s64 milli_current_time()
{
	return SDL_GetTicks();
}
void sleep_milli(u32 milliseconds)
{
	SDL_Delay(milliseconds);
}


char *malloc_file_cstr(char const *path)
{//at least 2x slower than it should be
#ifdef  __APPLE__
	char adjpath[1024];
	uint32_t size = sizeof(adjpath);
	_NSGetExecutablePath(adjpath, &size);
	string adjpathstr=adjpath;
	for(int i=adjpathstr.size(); i>0; i--)
	{
		if(adjpathstr[i]=='/' || adjpathstr[i]=='\\')
		{
			adjpathstr=adjpathstr.slice(0,i-1);
			break;
		}
	}
	string finalpathadj=adjpathstr+("/")+(path);
	path=finalpathadj.c_str();
#endif

    FILE* fp=fopen(path, "rb");
    if(!fp)
    {
        printf("Could not open file.");
        return NULL;
    }
	
	fseek(fp, 0L, SEEK_END);
	u32 sz = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	char *buff=(char*)malloc(sz+1);
	fread(buff, 1, sz, fp);
	buff[sz]=0;
	//printf("%d\n",buff[sz-1]);
    return buff;
}
void write_file_cstr(char const *path, char const *cstr)
{
#ifdef  __APPLE__
	char adjpath[1024];
	uint32_t size = sizeof(adjpath);
	_NSGetExecutablePath(adjpath, &size);
	string adjpathstr=adjpath;
	for(int i=adjpathstr.size(); i>0; i--)
	{
		if(adjpathstr[i]=='/' || adjpathstr[i]=='\\')
		{
			adjpathstr=adjpathstr.slice(0,i-1);
			break;
		}
	}
	string finalpathadj=adjpathstr+("/")+(path);
	path=finalpathadj.c_str();
#endif

    FILE* fp=fopen(path, "w");
    if(!fp)
    {
        printf("Could not open file: %s\n",path);
		return;
    }

    fprintf(fp,"%s",cstr);
    fclose(fp);
}

#if 0
int rand_num(s32 min, s32 max)
{
    return 42;//@todo @bug @temp
}
#endif
/*
struct raw_thread;
void wait_thread(raw_thread *t,int *status_out);
raw_thread *ctor_raw_thread(int(*func)(void*),char const *name,void *data);

struct mutex;
mutex *ctor_mutex();
void dtor_mutex(mutex* m);
void lock_mutex(mutex *m);
void unlock_mutex(mutex *m);
*/