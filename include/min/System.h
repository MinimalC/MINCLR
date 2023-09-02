/* Gemeinfrei. Public Domain. */
#if !defined(have_System_core)
#include "System.core.h"
#endif
#if defined(have_System)
#warning Multiple inclusion of System.h
#else
#define have_System

#include "System.Array.h"
/* #include "System.Arrays.auto.h" */
#include "System.Math.h"
#include "System.List.h"
#include "System.ListEnumerator.h"
#include "System.Dictionary.h"
/* #include "System.Directory.h" */
#include "System.Runtime.h"
#include "System.ELFAssembly.h"
#include "System.Path.h"

#include "Network.TCPSocket.h"

#endif
