#if !defined(have_System_stddef)
#warning "System.stddef.h not included"
#include <meta/System.stddef.h>
#endif
#if !defined(have_ISO)
#define have_ISO


/* this is GNU libc runtime  */

#define ISO_terminate  _Exit
#define ISO_exit  exit

__import void ISO_terminate(System_int32 status) __noreturn;
__import void ISO_exit(System_int32 status) __noreturn;


/* ISO_errno */

#define ISO_errno_location  __errno_location

__import System_int32 * ISO_errno_location();


/* ISO_malloc and _free */

#define ISO_malloc  malloc
#define ISO_realloc  realloc
#define ISO_free  free

__import void  * ISO_malloc(System_size length);
__import void  * ISO_realloc(void * that, System_size length);
__import void  ISO_free(void  * that);

/* ISO_File */

typedef struct class_ISO_File  * ISO_File;


/* ISO_vxfprintf */

#define ISO_fprintf  fprintf
#define ISO_vfprintf  vfprintf
#define ISO_putc  putc

__import System_int32  ISO_fprintf(ISO_File filePtr, const System_string8  format, ...);
__import System_int32  ISO_vfprintf(ISO_File filePtr, const System_string8  format, System_arguments  args);
__import System_int32  ISO_putc(System_int32  character, ISO_File);


/* ISO_stdin _stdout and _stderr */

#define ISO_stdin  stdin
#define ISO_stdout  stdout
#define ISO_stderr  stderr

__import ISO_File  ISO_stdin;
__import ISO_File  ISO_stdout;
__import ISO_File  ISO_stderr;

/* ISO_f*lose */

typedef System_int32  ISO_seekorigin;
#define ISO_SEEK_BEGIN  0
#define ISO_SEEK_CURRENT  1
#define ISO_SEEK_END  2

#define ISO_fopen  fopen
#define ISO_fclose  fclose
#define ISO_fwrite  fwrite
#define ISO_fflush  fflush
#define ISO_fread  fread
#define ISO_fseek  fseek
#define ISO_ftell  ftell

__import ISO_File  ISO_fopen(System_string8 filename, System_string8 modes);
__import System_int32  ISO_fclose(ISO_File file);
__import System_size  ISO_fwrite(const void  * value, System_size size, System_size n, ISO_File file);
__import void  ISO_fflush(ISO_File file);
__import System_size  ISO_fread(void  * value, System_size size, System_size n, ISO_File file);
__import void  ISO_fseek(ISO_File file, System_size offset, ISO_seekorigin whence);
__import System_size  ISO_ftell(ISO_File file);


/* ISO_assembly */

typedef struct class_ISO_Library  * ISO_Library;


/* ISO_assembly_load */

#define ISO_dlopen  dlopen
#define ISO_dlclose  dlclose
#define ISO_dlsym  dlsym

__import ISO_Library  ISO_dlopen(const System_string8 filename, System_int32 flags);
__import System_int32  ISO_dlclose(ISO_Library  that);
__import void  * ISO_dlsym(ISO_Library  that, const System_string8 symbol);


#endif
