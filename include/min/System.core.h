/* Gemeinfrei. Public Domain. */
#if defined(have_System_core)
#warning Multiple inclusion of System.core.h
#else
#define have_System_core

#include "System.Type.h" /* see System.Type.h */
#include "System.Memory.h"
#include "System.String.h"
#include "System.String8.h"
#include "System.Decimal.h"
#include "System.Integers.auto.h"
#include "System.IntegerArrays.auto.h"

#include "System.VarArray.h"
#include "System.VarDictionary.h"

#include "System.String8Array.h"
#include "System.String8Dictionary.h"

#include "System.Syscall.h"
#include "System.FileInfo.h"
#include "System.IEnumerable.h"
#include "System.ICollection.h"
#include "System.IStream.h"
#include "System.File.h"
#include "System.Directory.h"
#include "System.Console.h"
#include "System.Terminal.h"
#include "System.Exception.h"
#include "System.Environment.h"
#include "System.Signal.h"
#include "System.Thread.h"
#include "System.Atomic.h"

#include "Crypto.SipHash48.h"
#include "Crypto.CubeHash512.h"

#include "System.DateTime.h"

#endif