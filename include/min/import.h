
#if defined(export)
#undef export
#endif

#if defined(MSVCC)
#define export  extern __declspec(dllexport)

#else /* if defined(GNUCC) */
#define export  __attribute__((visibility("default")))

#endif
