/* Gemeinfrei. Public Domain. */
#if defined(have_System)
#warning Multiple inclusion of System.h
#else
#define have_System

#include "System.Type.h" /* see System.Type.h */


#include "System.IEnumerable.h"

#include "System.ICollection.h"

#include "System.IStream.h"


#include "System.values.auto.h"

#include "System.decimal.h"

#include "System.string8.h"


#include "System.Object.h"

#include "System.String.h"

#include "System.Exception.h"


#include "System.Array.h"
#include "System.ArrayEnumerator.h"

/* #include "System.Arrays.auto.h" */

#include "System.Memory.h"

#include "System.Math.h"

#include "Crypto.SipHash48.h"


/* #include "System.StreamWriter.h" */

#include "System.Syscall.h"

#include "System.File.h"

#include "System.FileInfo.h"

#include "System.Console.h"


#include "System.valueArrays.auto.h"

#include "System.List.h"
#include "System.ListEnumerator.h"

#include "System.Dictionary.h"

/* #include "System.Directory.h" */


#include "System.Assembly.h"


/* #include "System.Signals.h" */

/* #include "System.Thread.h" */

/* #include "System.Socket.h" */


#undef  __fixed
#define __fixed  /* noconst */

#endif
