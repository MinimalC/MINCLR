#if !defined(have_System_stddef)
#warning "System.stddef.h not included"
#include <meta/System.stddef.h>
#endif
#if !defined(have_ISO)
#define have_ISO


/* this is GNU libc runtime  */

#define ISO_terminate  _Exit
#define ISO_exit  exit

import void ISO_terminate(System_Int32 status) noreturn;
import void ISO_exit(System_Int32 status) noreturn;


/* ISO_errno */

#define ISO_errno_location  __errno_location

import System_Int32 * ISO_errno_location();


/* ISO_malloc and _free */

#define ISO_malloc  malloc
#define ISO_realloc  realloc
#define ISO_free  free

import void  * ISO_malloc(System_Size length);
import void  * ISO_realloc(void * that, System_Size length);
import void  ISO_free(void  * that);

/* ISO_File */

typedef struct class_ISO_File  * ISO_File;


/* ISO_vxfprintf */

#define ISO_fprintf  fprintf
#define ISO_vfprintf  vfprintf
#define ISO_putc  putc

import System_Int32  ISO_fprintf(ISO_File filePtr, const System_String8  format, ...);
import System_Int32  ISO_vfprintf(ISO_File filePtr, const System_String8  format, System_Arguments  args);
import System_Int32  ISO_putc(System_Int32  character, ISO_File);


/* ISO_stdin _stdout and _stderr */

#define ISO_stdin  stdin
#define ISO_stdout  stdout
#define ISO_stderr  stderr

import ISO_File  ISO_stdin;
import ISO_File  ISO_stdout;
import ISO_File  ISO_stderr;

/* ISO_f*lose */

typedef System_Int32  ISO_seekorigin;
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

import ISO_File  ISO_fopen(System_String8 filename, System_String8 modes);
import System_Int32  ISO_fclose(ISO_File file);
import System_Size  ISO_fwrite(const void  * value, System_Size __size, System_Size n, ISO_File file);
import void  ISO_fflush(ISO_File file);
import System_Size  ISO_fread(void  * value, System_Size __size, System_Size n, ISO_File file);
import void  ISO_fseek(ISO_File file, System_Size offset, ISO_seekorigin whence);
import System_Size  ISO_ftell(ISO_File file);


/* ISO_assembly */

typedef struct class_ISO_Library  * ISO_Library;


/* ISO_assembly_load */

#define ISO_dlopen  dlopen
#define ISO_dlclose  dlclose
#define ISO_dlsym  dlsym

import ISO_Library  ISO_dlopen(const System_String8 filename, System_Int32 flags);
import System_Int32  ISO_dlclose(ISO_Library  that);
import void  * ISO_dlsym(ISO_Library  that, const System_String8 symbol);


#endif
