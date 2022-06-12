/* Gemeinfrei. Public Domain. */
#if defined(have_System)
#warning Multiple inclusion of System.h
#else
#define have_System

#include "System.Type.h" /* see System.Type.h */


#include "System.Math.h"

#include "Crypto.SipHash48.h"


#include "System.List.h"
#include "System.ListEnumerator.h"

#include "System.Dictionary.h"


#include "System.Syscall.h"


#include "System.IStream.h"

#include "System.StreamWriter.h"

#include "System.File.h"

#include "System.FileInfo.h"

#include "System.Directory.h"


#include "System.Assembly.h"


/* #include "System.Signals.h" */

/* #include "System.Thread.h" */

/* #include "System.Socket.h" */


#undef  __fixed
#define __fixed  /* noconst */

#endif
