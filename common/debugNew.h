#ifndef DEBUG_NEW_H
#define DEBUG_NEW_H

#ifdef SHOW_MEMORY_LEAKS

#include <QList>
#include <QMetaType>
#define _CRTDBG_MAP_ALLOC #include <stdlib.h> #include <crtdbg.h>
#ifndef DBG_NEW
  #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
  #define new DBG_NEW
#endif

#endif

#endif
