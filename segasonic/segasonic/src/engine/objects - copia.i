# 1 "C:\\segasonic-port-main\\segasonic\\src\\engine\\objects - copia.cpp"
/**
 *    Name:        engine/objects.c
 *    Description: the object system: the object list and its two pools, allocating, linking and deleting objects, spawning them from the stage lists (by type, by handler, in groups led by a leader), and what the stage objects share
 *    Version:     0.1.0
 *    Created:     12-10-2026
 *    Modified:    23-10-2026
 *    Author:      Sebastian Toyos
 *
 *    SegaSonic The Hedgehog (arcade, Sega System 32): the game's V60 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
# 1 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\game.h"
/**
 *    Name:        game.h
 *    Description: prototypes of the game's functions and the addresses of the code it keeps in memory slots
 *    Version:     0.1.0
 *    Created:     12-10-2026
 *    Modified:    23-10-2026
 *    Author:      Sebastian Toyos
 *
 *    SegaSonic The Hedgehog (arcade, Sega System 32): the game's V60 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */



# 1 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"
/**
*    Name:        support.h
*    Description: what the decompiled game program uses besides memory: the processor status, the frame
*                 loop and its interrupts, calls by address, and the V60's string and bit-string moves
*                 and searches
*    Version:     0.1.0
*    Created:     11-10-2026
*    Modified:    20-10-2026
*    Author:      Sebastian Toyos
*
*    license:BSD-3-Clause
*    Behavior follows MAME's V60 core (src/devices/cpu/v60, Farfetch'd, R. Belmont) where the program
*    leans on the processor: its status word, interrupt entry and exit, MOVCU/MOVCFU/MOVCD,
*    MOVBSD/MOVBSU and SCH0BSU/SCH1BSU. The condition flags are variables of the decompiled functions;
*    'psw' keeps the rest.
*/



# 1 "C:/usr/local/cell\\target\\ppu\\include/stdbool.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2005 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
/* stdbool.h standard header */
# 1 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2006 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
/* yvals.h values header for conforming compilers on various systems */
# 1 "C:/usr/local/cell\\target\\ppu\\include/sys/types.h" 3
/*   SCE CONFIDENTIAL                                       */
/*   PlayStation(R)3 Programmer Tool Runtime Library 475.001 */
/*   Copyright (C) 2008 Sony Computer Entertainment Inc.    */
/*   All Rights Reserved.                                   */




# 1 "C:/usr/local/cell\\target\\ppu\\include/sys/syscall.h" 3
/*   SCE CONFIDENTIAL                                       */
/*   PlayStation(R)3 Programmer Tool Runtime Library 475.001 */
/*   Copyright (C) 2005 Sony Computer Entertainment Inc.    */
/*   All Rights Reserved.                                   */




# 248 "C:/usr/local/cell\\target\\ppu\\include/sys/syscall.h" 3



/* The following macros represent the numbers for the SPU library functions. */
# 262 "C:/usr/local/cell\\target\\ppu\\include/sys/syscall.h" 3

# 1 "C:/usr/local/cell\\target\\ppu\\include/sys/types.h" 3
/*   SCE CONFIDENTIAL                                       */
/*   PlayStation(R)3 Programmer Tool Runtime Library 475.001 */
/*   Copyright (C) 2008 Sony Computer Entertainment Inc.    */
/*   All Rights Reserved.                                   */

# 264 "C:/usr/local/cell\\target\\ppu\\include/sys/syscall.h" 3




/* __system_call_NNN is converted to an inline "sc" instruction */






































/*
 * Calling this macro lets the stub return to the user program.
 * 
 * \param ret_type The return parameter type
 */


/*
 * Macros to obtain the register passing return arguments.
 * 
 * __reg( n ) intrinsic gets the returned register value from the previous call/syscall
 */
# 326 "C:/usr/local/cell\\target\\ppu\\include/sys/syscall.h" 3

# 525 "C:/usr/local/cell\\target\\ppu\\include/sys/syscall.h" 3

/*
 * Macros used for register passing output arguments.
 */







# 10 "C:/usr/local/cell\\target\\ppu\\include/sys/types.h" 3
# 1 "C:/usr/local/cell\\target\\common\\include/sys/sys_types.h" 3
/*   SCE CONFIDENTIAL                                       */
/*   PlayStation(R)3 Programmer Tool Runtime Library 475.001 */
/*   Copyright (C) 2009 Sony Computer Entertainment Inc.    */
/*   All Rights Reserved.                                   */




# 1 "C:/usr/local/cell\\target\\ppu\\include/sys/cdefs.h" 3
/*   SCE CONFIDENTIAL                                       */
/*   PlayStation(R)3 Programmer Tool Runtime Library 475.001 */
/*   Copyright (C) 2006 Sony Computer Entertainment Inc.    */
/*   All Rights Reserved.                                   */




# 20 "C:/usr/local/cell\\target\\ppu\\include/sys/cdefs.h" 3

# 32 "C:/usr/local/cell\\target\\ppu\\include/sys/cdefs.h" 3






# 10 "C:/usr/local/cell\\target\\common\\include/sys/sys_types.h" 3
# 1 "C:/usr/local/cell\\target\\ppu\\include/sys/integertypes.h" 3
/*   SCE CONFIDENTIAL                                       */
/*   PlayStation(R)3 Programmer Tool Runtime Library 475.001 */
/*   Copyright (C) 2005 Sony Computer Entertainment Inc.    */
/*   All Rights Reserved.                                   */






namespace std { typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;


typedef signed long long int64_t;
typedef unsigned long long uint64_t;
typedef signed int intptr_t;
typedef unsigned int uintptr_t;
# 29 "C:/usr/local/cell\\target\\ppu\\include/sys/integertypes.h" 3

}

	using ::std:: int8_t;
using ::std:: uint8_t;
using ::std:: int16_t;
using ::std:: uint16_t;
using ::std:: int32_t;
using ::std:: uint32_t;
using ::std:: int64_t;
using ::std:: uint64_t;
using ::std:: intptr_t;
using ::std:: uintptr_t;



# 11 "C:/usr/local/cell\\target\\common\\include/sys/sys_types.h" 3





/*
 * Timer
 */
typedef ::std:: uint64_t callout_t;
typedef ::std:: uint64_t timer_t;

/*
 * Data types
 */
namespace std {
# 35 "C:/usr/local/cell\\target\\common\\include/sys/sys_types.h" 3
typedef ::std:: uint32_t size_t;
typedef ::std:: int32_t off_t;




typedef ::std:: int64_t off64_t;
typedef ::std:: int64_t time_t;




}
/*
 * Process
 */
/** \brief process id (opaque value) */
typedef ::std:: uint32_t sys_pid_t;

/* \brief program segment id (opaque value) */
typedef ::std:: uint32_t sys_program_segment_t;

/* \brief overlay module id (opaque value) */
typedef ::std:: uint32_t sys_overlay_t;


/*
 * PPU thread
 */
typedef ::std:: uint64_t sys_ppu_thread_t;

/** \brief interrupt tag id (opaque value for users) */
typedef ::std:: uint32_t sys_interrupt_tag_t;

/*
 * Synchronization
 */
typedef ::std:: uint32_t sys_mutex_t;
typedef ::std:: uint32_t sys_cond_t;
typedef ::std:: uint32_t sys_shared_mutex_t;
typedef ::std:: uint32_t sys_sync_point_t;
typedef ::std:: uint32_t sys_rwlock_t;

typedef ::std:: uint32_t sys_protocol_t;
typedef ::std:: uint32_t sys_recursive_t;
typedef ::std:: uint32_t sys_process_shared_t;
typedef ::std:: uint32_t sys_adaptive_t;

typedef ::std:: uint32_t _sys_sleep_queue_t;
typedef ::std:: uint32_t _sys_lwcond_queue_t;
typedef ::std:: uint32_t sys_semaphore_t;
typedef ::std:: uint32_t sys_event_flag_t;


/*
 * Event 
 */
typedef ::std:: uint32_t sys_event_queue_t;
typedef ::std:: uint32_t sys_event_port_t;
typedef ::std:: uint32_t sys_event_type_t;

/* 
 * SPU Thread
 */
typedef ::std:: uint32_t sys_spu_thread_group_t;
typedef ::std:: uint32_t sys_spu_thread_t;

/*
 * SPU System Module
 */
typedef ::std:: uint32_t sys_spu_system_module_t;


/*
 * Invalid values for IDs
 */





/*
 * timer
 */
typedef ::std:: uint32_t sys_timer_t;


/*
 * Time
 */
typedef ::std:: int64_t system_time_t;
typedef ::std:: uint64_t usecond_t;
typedef ::std:: uint32_t second_t;

/* IPC key */
typedef ::std:: uint64_t sys_ipc_key_t;

/*
 * Addresses and memory
 */
typedef ::std:: uintptr_t lparaddr_t;
typedef ::std:: uintptr_t sys_addr_t;
typedef ::std:: uint32_t sys_memory_t;
typedef ::std:: uint32_t sys_memory_container_t;


/*
 * System call trace
 */
typedef ::std:: uint32_t sys_trace_t;
typedef ::std:: uint32_t sys_trace_buffer_t;



/*
 * Data type for PPU GUID information
 */
namespace std { typedef struct sys_ppu_guid_info {
	const char magic[5];		/*  5 bytes : '\177'GUID              */
	const ::std:: uint8_t id_revision;	/*  1 byte  : PPU GUID revision (0x1) */
	const ::std:: uint16_t reserved1;	/*  2 bytes : Reserved (0x0)          */
	const ::std:: uint32_t ppu_guid[5];	/* 20 bytes : PPU GUID                */
	const ::std:: uint32_t reserved2;	/*  4 bytes : Reserved (0x0)          */
} sys_ppu_guid_info_t;

}
/*
 * Data types for SDK Library
 */
	namespace std {


typedef int32_t ssize_t;



typedef int mode_t;
typedef long int useconds_t;
typedef long key_t;
typedef uint32_t pid_t;
typedef unsigned long dev_t;
typedef unsigned long ino_t;
typedef unsigned long nlink_t;
typedef long blkcnt_t;
typedef long blksize_t;


}

	using ::std:: size_t;

using ::std:: off_t;
using ::std:: off64_t;
using ::std:: ssize_t;
using ::std:: mode_t;
using ::std:: useconds_t;
using ::std:: key_t;
using ::std:: dev_t;
using ::std:: ino_t;
using ::std:: nlink_t;
using ::std:: blkcnt_t;
using ::std:: blksize_t;
using ::std:: time_t;

using ::std:: sys_ppu_guid_info_t;




# 11 "C:/usr/local/cell\\target\\ppu\\include/sys/types.h" 3

/* PPU specific type declarations */

# 10 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

# 24 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

# 1 "C:/usr/local/cell\\target\\ppu\\include/stdarg.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/





typedef char *   va_list;


  extern  "C"
  {

    extern char  *__va_funcx(int, va_list, ...) ; /* expanded by compiler */

  }


# 28 "C:/usr/local/cell\\target\\ppu\\include/stdarg.h" 3

# 39 "C:/usr/local/cell\\target\\ppu\\include/stdarg.h" 3

# 26 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3




/* You can predefine (on the compile command line, for example):

_ALT_NS=1 -- to use namespace _Dinkum_std for C++
_ALT_NS=2 -- to use namespace _Dinkum_std for C++ and C
_C_AS_CPP -- to compile C library as C++
_C_IN_NS -- to define C names in std/_Dinkum_std instead of global namespace
_C99 -- to turn ON C99 library support
_NO_EX -- to turn OFF use of try/throw
_NO_MT -- to turn OFF thread synchronization
_NO_NS -- to turn OFF use of namespace declarations
_STL_DB (or _STLP_DEBUG) -- to turn ON iterator/range debugging
__NO_LONG_LONG -- to define _Longlong as long, not long long

You can change (in this header):

_COMPILER_TLS -- from 0 to 1 if _TLS_QUAL is not nil
_EXFAIL -- from 1 to any nonzero value for EXIT_FAILURE
_FILE_OP_LOCKS -- from 0 to 1 for file atomic locks
_GLOBAL_LOCALE -- from 0 to 1 for shared locales instead of per-thread
_HAS_IMMUTABLE_SETS -- from 1 to 0 to permit alterable set elements
_HAS_STRICT_CONFORMANCE -- from 0 to 1 to disable nonconforming extensions
_HAS_TRADITIONAL_IOSTREAMS -- from 1 to 0 to omit old iostreams functions
_HAS_TRADITIONAL_ITERATORS -- from 0 to 1 for vector/string pointer iterators
_HAS_TRADITIONAL_POS_TYPE -- from 0 to 1 for streampos same as streamoff
_HAS_TRADITIONAL_STL -- from 1 to 0 to omit old STL functions
_IOSTREAM_OP_LOCKS -- from 0 to 1 for iostream atomic locks
_TLS_QUAL -- from nil to compiler TLS qualifier, such as __declspec(thread)
_USE_EXISTING_SYSTEM_NAMES -- from 1 to 0 to disable mappings (_Open to open)

Include directories needed to compile with Dinkum C:

C -- include/c
C99 -- include/c (define _C99)
Standard C++ -- include/c include

Include directories needed to compile with native C:

C -- none
C99 -- N/A
Standard C++ -- include
 */

 /* Dinkumware configuration defines for ppu-lv2.  These are dinkumware
    implementation details, so we set them here, rather than having the
    compiler set them. */



 /* We set _C_IN_NS so it compliant with C++ standard.  An end user
    can prevent it from being set by setting _C_IN_GLOBAL. */




















		/* DETERMINE MACHINE TYPE */

# 109 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

# 119 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

# 127 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

		/* DETERMINE _Ptrdifft AND _Sizet FROM MACHINE TYPE */


typedef int _Int32t;
typedef unsigned int _Uint32t;







typedef int _Ptrdifft;






typedef unsigned int _Sizet;









		/* EXCEPTION CONTROL */
# 165 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3



		/* NAMING PROPERTIES */
/* #define _STD_LINKAGE	defines C names as extern "C++" */
/* #define _STD_USING	defines C names in namespace std or _Dinkum_std */



















		/* THREAD AND LOCALE CONTROL */












/* LV2-MODIFIED */


/* LV2-MODIFIED END */

		/* THREAD-LOCAL STORAGE */
# 216 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

# 223 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3







# 236 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

		/* NAMESPACE CONTROL */




namespace std {}





# 278 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

# 287 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3






# 309 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3












# 327 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3





# 350 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

# 369 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

/* Inline definitions are only supported in C99 or C++. */




     /* GCC doesn't handle C99 inline definitions correctly, but will
      * give the same behaviour if we explicitly say 'extern'. */
# 387 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

# 410 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3


namespace std {
typedef bool _Bool;
}


		/* VC++ COMPILER PARAMETERS */



# 427 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

namespace std {
		/* FLOATING-POINT PROPERTIES */






		/* INTEGER PROPERTIES */
















typedef long long _Longlong;
typedef unsigned long long _ULonglong;

# 462 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

		/* wchar_t AND wint_t PROPERTIES */



typedef wchar_t _Wchart;


# 482 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3
 /* Values for the SN Systems SNC for PS3 compiler. */




  




typedef int _Wintt;

# 506 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

		/* POINTER PROPERTIES */


		/* signal PROPERTIES */




		/* stdarg PROPERTIES */
typedef va_list _Va_list;



# 526 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3



		/* stdlib PROPERTIES */


extern "C" {
void _Atexit(void (*)(void));
}

		/* stdio PROPERTIES */









typedef char _Sysch_t;

		/* STORAGE ALIGNMENT PROPERTIES */


		/* time PROPERTIES */
/** LV2_MODIFIED **/


}

extern "C" {
# 566 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3
typedef void *_Rmtx;

}

		/* MULTITHREAD PROPERTIES */


extern "C" {
void _Locksyslock(int);
void _Unlocksyslock(int);
}






		/* LOCK MACROS */
# 594 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3










namespace std {
extern "C++" {	// in case of _C_AS_CPP
		// CLASS _Lockit
class _Lockit
	{	// lock while object in existence -- MUST NEST
public:

# 628 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3

	explicit _Lockit()
		: _Locktype(1)
		{	// set default lock
		
			_Locksyslock(_Locktype);
		}

	explicit _Lockit(int _Type)
		: _Locktype(_Type)
		{	// set the lock
		
			_Locksyslock(_Locktype);
		}

	~_Lockit()
		{	// clear the lock
		
			_Unlocksyslock(_Locktype);
		}

private:
	int _Locktype;
public:
	_Lockit(const _Lockit&);			// not defined
	_Lockit& operator=(const _Lockit&);	// not defined


	};

class _Mutex
	{	// lock under program control
public:

# 672 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3
	_Mutex();
	~_Mutex();
	void _Lock();
	void _Unlock();

private:
	_Mutex(const _Mutex&);				// not defined
	_Mutex& operator=(const _Mutex&);	// not defined
	_Rmtx *_Mtx;


	};
}	// extern "C++"
}


		/* MISCELLANEOUS MACROS */


















namespace std {
using ::va_list;
}





# 723 "C:/usr/local/cell\\target\\ppu\\include/yvals.h" 3



/*
 * Copyright (c) 1992-2003 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:0216 */
# 11 "C:/usr/local/cell\\target\\ppu\\include/stdbool.h" 3


namespace std {



# 31 "C:/usr/local/cell\\target\\ppu\\include/stdbool.h" 3

}


/*
 * Copyright (c) 1992-2003 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:0216 */
# 21 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"
# 1 "C:/usr/local/cell\\target\\ppu\\include/stddef.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2005 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
/* stddef.h standard header */








namespace std {

		/* macros */








# 35 "C:/usr/local/cell\\target\\ppu\\include/stddef.h" 3



		/* type definitions */





typedef _Ptrdifft ptrdiff_t;







}





using ::std:: ptrdiff_t;




/*
 * Copyright (c) 1992-2003 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:0216 */
# 22 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"
# 1 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2006 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
/* stdint.h standard header */










/* NB: also assumes
	long is 32 bits
	pointer can convert to and from long long
	long long is longest type
 */

/* Get the int types from Lv-2's sys/integertypes.h */


namespace std {

		/* TYPE DEFINITIONS */



typedef signed char int_least8_t;
typedef short int_least16_t;
typedef _Int32t int_least32_t;
typedef _Longlong int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef _Uint32t uint_least32_t;
typedef _ULonglong uint_least64_t;


typedef int32_t int_fast8_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast8_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;










typedef int64_t int_fast64_t;
typedef uint64_t uint_fast64_t;



typedef _Longlong intmax_t;
typedef _ULonglong uintmax_t;


		/* LIMIT MACROS */
# 123 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

# 141 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

# 191 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

# 198 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3
}








using ::std:: int_least8_t; using ::std:: int_least16_t;
using ::std:: int_least32_t;  using ::std:: int_least64_t;
using ::std:: uint_least8_t; using ::std:: uint_least16_t;
using ::std:: uint_least32_t; using ::std:: uint_least64_t;

using ::std:: intmax_t; using ::std:: uintmax_t;


using ::std:: int_fast8_t; using ::std:: int_fast16_t;
using ::std:: int_fast32_t; using ::std:: int_fast64_t;
using ::std:: uint_fast8_t; using ::std:: uint_fast16_t;
using ::std:: uint_fast32_t; using ::std:: uint_fast64_t;


/*
 * Copyright (c) 1992-2003 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:0216 */
# 23 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"

# 1 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/bus.h"
/**
 *    Name:        bus.h
 *    Description: the game program's view of memory: reads and writes through the System 32 bus
 *    Version:     0.1.0
 *    Created:     11-10-2026
 *    Modified:    15-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The V60 drives 24 address lines, so an address wraps at 16 MB. Values are little endian, as the V60
 *    keeps them.
 */



# 1 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2006 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
/* stdint.h standard header */
# 201 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

# 220 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

/*
 * Copyright (c) 1992-2003 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:0216 */
# 17 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/bus.h"

# 1 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/machine.h"
/**
 *    Name:        machine.h
 *    Description: Sega System 32 board as the SegaSonic program sees it: memory map, interrupts, timers, I/O
 *    Version:     0.1.0
 *    Created:     11-10-2026
 *    Modified:    13-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME: sega/segas32.cpp, segas32_v.cpp, segas32_m.cpp (Aaron Giles),
 *    sega/315_5296.cpp (hap), machine/eepromser.cpp and machine/eeprom.cpp (Aaron Giles),
 *    machine/upd4701.cpp. MAME's terms are in tools/reference/mame/LICENSE.
 *
 *    The V60 side is reached through s32_read* / s32_write*: a 16-bit little-endian bus with
 *    24 address lines.
 *
 *    Time runs one of two ways. With cycle timing the caller advances s32_board.cycles as the CPU runs
 *    and calls the frame events itself (tools/reference/s32ref, to follow the real CPU's pace). With
 *    frame timing the program takes no time at all: when it waits for the next frame it calls
 *    s32_wait(), which moves the board to its next event (a timer, the start or end of VBLANK, the
 *    sprite list) and runs it. That is the CPU of a decompiled program, and it never lags.
 */



# 1 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2006 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
/* stdint.h standard header */
# 201 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

# 220 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

/*
 * Copyright (c) 1992-2003 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:0216 */
# 28 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/machine.h"


extern "C" {







# 46 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/machine.h"

/* The sound board: a Z80 and two YM3438 on 32.2159 MHz / 4, an RF5C68 on 50 MHz / 4 */





/* Work RAM the V60 stacks use (0x20FE00-0x20FFFF), left out of state comparisons: a decompiled
   program has no V60 stack */


/* Interrupt controller sources, highest priority first */
enum
{
	S32_IRQ_VBLANK_START,
	S32_IRQ_VBLANK_END,
	S32_IRQ_SOUND,
	S32_IRQ_TIMER0,
	S32_IRQ_TIMER1
};

/* Sound interrupt controller inputs */
enum
{
	S32_SOUND_IRQ_FM,           /* the first YM3438's timers */
	S32_SOUND_IRQ_V60           /* the V60 writes the interrupt controller's 0x0C-0x0F */
};

/* The sound chips as the Z80 reaches them: the reference plugs in MAME's, the game its own */
typedef struct s32_sound_chips
{
	uint8_t (*fm_read)(int chip, int offset);               /* YM3438 0-1, offsets 0-3 */
	void (*fm_write)(int chip, int offset, uint8_t data);
	void (*pcm_write)(int offset, uint8_t data);            /* RF5C68 registers 0-8 */
	uint8_t (*pcm_memory_read)(int offset);                 /* its 4 KB window on the wave memory */
	void (*pcm_memory_write)(int offset, uint8_t data);
} s32_sound_chips;

/* Controls, active low like the board: a cleared bit is a pressed button */
typedef struct s32_inputs
{
	uint8_t port_a;              /* bit 0: player 1 button, bit 2: player 3 button */
	uint8_t port_b;              /* bit 0: player 2 button */
	uint8_t port_c;
	uint8_t port_e;              /* 0: service, 1: test, 2-3: coins 1-2, 4-5: starts 1-2, 6: coin 3, 7: start 3 */
	uint8_t port_f;              /* 0-3: DIP switches, 4-5: PCB buttons; bit 7 is the EEPROM data line */
	uint16_t trackball_x[3];     /* free-running counters, 12 bits are used */
	uint16_t trackball_y[3];
} s32_inputs;

/* 93C46 serial EEPROM in 16-bit mode */
typedef struct s32_eeprom
{
	uint16_t data[64];
	int state;
	int command;
	int address;
	int bits;
	uint32_t shift;
	uint32_t command_bits;
	bool cs;
	bool clk;
	bool di;
	bool locked;
	uint64_t busy_until;         /* V60 cycle when the internal write or erase ends */
	bool dirty;                  /* contents changed since the last save */
} s32_eeprom;

typedef struct s32_machine
{
	const uint8_t *program;                        /* V60 program image (2 MB), owned by the caller */
	uint8_t work_ram[0x10000];
	uint8_t video_ram[0x20000];          /* 16-bit words, little endian */
	uint8_t sprite_ram[0x20000];        /* 16-bit words, little endian */
	uint16_t palette[0x4000];          /* stored as xBBBBBGGGGGRRRRR */
	uint16_t mixer[0x40];
	uint8_t shared_ram[0x2000];        /* shared with the Z80 sound CPU */

	uint8_t sprite_control[8];
	uint8_t sprite_control_latched[8];
	uint8_t sprite_buffer;                          /* bit read back at 0x500000 */
	int sprite_render_count;
	uint32_t sprite_lists;                          /* sprite lists sent to the renderer so far */

	uint8_t irq_control[16];
	uint64_t timer_deadline[2];                     /* cycle when timer 0/1 fires; 0 = stopped */
	uint64_t next_timer;                            /* earliest timer deadline, UINT64_MAX when none */
	uint64_t cycles;                                /* board time, in V60 cycles since reset */
	bool frame_timing;                              /* see the top of this file */
	uint64_t frame;                                 /* frame whose events come next */
	int frame_phase;                                /* frame timing: 0 = VBLANK start next, 1 = its end, 2 = sprites */

	uint8_t io_latch[8];                            /* 315-5296 ports A-H */
	uint8_t io_direction;
	uint8_t io_cnt;
	uint8_t tilebank_external;                      /* port H */
	s32_inputs input;
	uint16_t trackball_start_x[3];                  /* uPD4701 counter origin, set by a reset */
	uint16_t trackball_start_y[3];
	s32_eeprom eeprom;

	const uint8_t *sound_rom;                       /* 4 MB, owned by the caller; set after s32_init */
	uint8_t pcm_ram[0x10000];
	uint16_t sound_bank;                            /* the 8 KB page of the sound ROM at Z80 0xA000 */
	uint8_t sound_irq_control[4];                   /* the input of vectors 0-2, and the mask */
	uint8_t sound_irq_input;                        /* pending, by vector */
	uint8_t sound_spare;                            /* the byte at Z80 port 0xF1 */
	uint64_t sound_cycles;                          /* when the Z80's reads and writes happen (board cycles) */
	s32_sound_chips chips;

	uint32_t random_state;
	uint32_t sound_requests;                        /* V60 -> Z80 interrupt requests */
	uint32_t unmapped_reads;
	uint32_t unmapped_writes;
	uint32_t pc;                                    /* instruction being executed, for diagnostics */

	void (*irq_changed)(bool asserted);             /* interrupt line to the V60 */
	void (*controls_update)(void);                  /* when VBLANK starts, where MAME polls the controls */
	void (*frame_shown)(void);                      /* when VBLANK starts: the video draws the frame (MAME's
	                                                   screen update) from the memories as they are */
	void (*sprites_due)(bool erase, bool draw);     /* when the sprite list goes out, once the board took the
	                                                   commands: erase the shown buffer, and swap the buffers
	                                                   and draw the list (with the controls just latched) */
	void (*time_passes)(uint64_t until);            /* the board's time is about to move on to 'until': the
	                                                   sound board runs up to then */
	void (*sound_irq_changed)(bool asserted, uint8_t vector);   /* interrupt line to the Z80 */
	void (*sound_reset_changed)(bool held);         /* the I/O chip's CNT2 output holds the Z80 in reset */
	void (*log)(const char *message);
} s32_machine;

extern s32_machine s32_board;

void s32_init(const uint8_t *program);
void s32_reset(void);

uint8_t s32_read8(uint32_t address);
uint16_t s32_read16(uint32_t address);
uint32_t s32_read32(uint32_t address);
void s32_write8(uint32_t address, uint8_t data);
void s32_write16(uint32_t address, uint16_t data);
void s32_write32(uint32_t address, uint32_t data);

void s32_signal_irq(int source);
bool s32_irq_asserted(void);
uint8_t s32_irq_acknowledge(void);

uint64_t s32_next_timer(void);
void s32_run_timers(void);

void s32_vblank_start(void);
void s32_vblank_end(void);
void s32_sprite_update(void);   /* MAME runs it 50 us after the end of VBLANK */

/* The Z80's side of the sound board (sound.c): its memory (the program, the banked page of the sound
   ROM, the RF5C68 and the shared RAM) and its I/O ports (the YM3438s, the bank, the interrupt
   controller) */
uint8_t s32_z80_read(uint16_t address);
void s32_z80_write(uint16_t address, uint8_t data);
uint8_t s32_z80_in(uint8_t port);
void s32_z80_out(uint8_t port, uint8_t data);
void s32_sound_signal_irq(int input);
void s32_sound_clear_irq(int input);

/* Board time when a frame starts (VBLANK ends) and when one of its lines starts */
uint64_t s32_frame_start(uint64_t frame);
uint64_t s32_line_start(uint64_t frame, int line);

/* Frame timing: the program waits, the board runs its next event (it may raise an interrupt) */
void s32_wait(void);

/* Hash of the state a frame leaves behind: work RAM but the stacks, video RAM, sprite RAM, palette
   and mixer (FNV-1a, 64 bits) */
uint64_t s32_state_hash(void);


}


# 19 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/bus.h"


extern "C" {


static inline uint8_t mem_read8(uint32_t address)
{
	return s32_read8(address & 0xffffff);
}

static inline uint16_t mem_read16(uint32_t address)
{
	return s32_read16(address & 0xffffff);
}

static inline uint32_t mem_read32(uint32_t address)
{
	return s32_read32(address & 0xffffff);
}

static inline void mem_write8(uint32_t address, uint8_t data)
{
	s32_write8(address & 0xffffff, data);
}

static inline void mem_write16(uint32_t address, uint16_t data)
{
	s32_write16(address & 0xffffff, data);
}

static inline void mem_write32(uint32_t address, uint32_t data)
{
	s32_write32(address & 0xffffff, data);
}

static inline uint64_t mem_read64(uint32_t address)
{
	const uint64_t low = mem_read32(address);
	return low | ((uint64_t)mem_read32(address + 4) << 32);
}

static inline void mem_write64(uint32_t address, uint64_t data)
{
	mem_write32(address, (uint32_t)data);
	mem_write32(address + 4, (uint32_t)(data >> 32));
}

# 117 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/bus.h"


}


# 25 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"
# 1 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/program.h"
/**
 *    Name:        program.h
 *    Description: what a port needs from the game program: start it, wire its interrupt line, hear about
 *                 every frame it finishes
 *    Version:     0.1.0
 *    Created:     11-10-2026
 *    Modified:    11-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Two builds provide it: the decompiled game (runtime/src/game.c with the C of tools/decompile.py)
 *    and the translation scaffold (runtime/src/v60.c with the C of tools/recompile.py). The program
 *    never returns on its own: the port leaves it from program_frame_done (with longjmp) when it has
 *    run the frames it wanted.
 */



# 1 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2006 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
/* stdint.h standard header */
# 201 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

# 220 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

/*
 * Copyright (c) 1992-2003 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:0216 */
# 21 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\s32/program.h"


extern "C" {


/* Puts the program in its power-on state; the board is set up apart (s32_init) */
void program_reset(void);

/* Runs the program from its reset vector */
void program_run(void);

/* The board's interrupt line (s32_board.irq_changed) */
void program_irq_line(bool asserted);

uint64_t program_frames(void);          /* frames the program finished */
uint32_t program_interrupts(void);      /* interrupts it took */

/* Called each time the program finishes a frame */
extern void (*program_frame_done)(void);


}


# 27 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"
# 1 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\v60/arith.h"
/**
 *    Name:        arith.h
 *    Description: V60 arithmetic as pure functions: results and flags of MAME's core, each one on its own
 *    Version:     0.1.0
 *    Created:     11-10-2026
 *    Modified:    11-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Ported from MAME src/devices/cpu/v60 (v60.cpp macros and op12.hxx, Farfetch'd, R. Belmont), the same
 *    behavior as ops.h but with no state: code generated from tools/v60/ir.py computes each flag where it
 *    needs it. Shift counts are masked as on x86-64, where the reference runs (see ops.h).
 */



# 1 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3
/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 475.001
* Copyright (C) 2006 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
/* stdint.h standard header */
# 201 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

# 220 "C:/usr/local/cell\\target\\ppu\\include/stdint.h" 3

/*
 * Copyright (c) 1992-2003 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:0216 */
# 19 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\v60/arith.h"


extern "C" {


static inline uint32_t shl32(uint32_t value, int count) { return value << (count & 31); }
static inline uint32_t shr32(uint32_t value, int count) { return value >> (count & 31); }
static inline int32_t sar32(int32_t value, int count) { return value >> (count & 31); }
static inline uint64_t shl64(uint64_t value, int count) { return value << (count & 63); }
static inline uint64_t shr64(uint64_t value, int count) { return value >> (count & 63); }

/* ---- add / subtract: carry and overflow of a + b + carry_in and a - b - borrow_in ---- */

static inline uint32_t v60_carry_add8(uint32_t a, uint32_t b, uint32_t carry) { return ((a + b + carry) >> 8) & 1; }
static inline uint32_t v60_carry_add16(uint32_t a, uint32_t b, uint32_t carry) { return ((a + b + carry) >> 16) & 1; }
static inline uint32_t v60_carry_add32(uint32_t a, uint32_t b, uint32_t carry)
{
	return (uint32_t)((((uint64_t)a + b + carry) >> 32) & 1);
}

static inline uint32_t v60_overflow_add8(uint32_t a, uint32_t b, uint32_t carry)
{
	const uint32_t result = a + b + carry;
	return ((result ^ b) & (result ^ a) & 0x80) ? 1 : 0;
}

static inline uint32_t v60_overflow_add16(uint32_t a, uint32_t b, uint32_t carry)
{
	const uint32_t result = a + b + carry;
	return ((result ^ b) & (result ^ a) & 0x8000) ? 1 : 0;
}

static inline uint32_t v60_overflow_add32(uint32_t a, uint32_t b, uint32_t carry)
{
	const uint64_t result = (uint64_t)a + b + carry;
	return ((result ^ b) & (result ^ a) & 0x80000000u) ? 1 : 0;
}

static inline uint32_t v60_carry_sub8(uint32_t a, uint32_t b, uint32_t borrow) { return ((a - b - borrow) >> 8) & 1; }
static inline uint32_t v60_carry_sub16(uint32_t a, uint32_t b, uint32_t borrow) { return ((a - b - borrow) >> 16) & 1; }
static inline uint32_t v60_carry_sub32(uint32_t a, uint32_t b, uint32_t borrow)
{
	return (uint32_t)((((uint64_t)a - b - borrow) >> 32) & 1);
}

static inline uint32_t v60_overflow_sub8(uint32_t a, uint32_t b, uint32_t borrow)
{
	const uint32_t result = a - b - borrow;
	return ((a ^ b) & (a ^ result) & 0x80) ? 1 : 0;
}

static inline uint32_t v60_overflow_sub16(uint32_t a, uint32_t b, uint32_t borrow)
{
	const uint32_t result = a - b - borrow;
	return ((a ^ b) & (a ^ result) & 0x8000) ? 1 : 0;
}

static inline uint32_t v60_overflow_sub32(uint32_t a, uint32_t b, uint32_t borrow)
{
	const uint64_t result = (uint64_t)a - b - borrow;
	return (((uint64_t)a ^ b) & ((uint64_t)a ^ result) & 0x80000000u) ? 1 : 0;
}

/* ---- divide: no change when dividing by zero; signed division overflows on MIN / -1 ---- */

static inline uint32_t v60_div_overflow8(uint32_t a, uint32_t b) { return a == 0x80 && b == 0xff; }
static inline uint32_t v60_div_overflow16(uint32_t a, uint32_t b) { return a == 0x8000 && b == 0xffff; }
static inline uint32_t v60_div_overflow32(uint32_t a, uint32_t b) { return a == 0x80000000u && b == 0xffffffffu; }

static inline uint32_t v60_div_value8(uint32_t a, uint32_t b)
{
	return (b && !v60_div_overflow8(a, b)) ? (uint8_t)((int8_t)a / (int8_t)b) : a;
}

static inline uint32_t v60_div_value16(uint32_t a, uint32_t b)
{
	return (b && !v60_div_overflow16(a, b)) ? (uint16_t)((int16_t)a / (int16_t)b) : a;
}

static inline uint32_t v60_div_value32(uint32_t a, uint32_t b)
{
	return (b && !v60_div_overflow32(a, b)) ? (uint32_t)((int32_t)a / (int32_t)b) : a;
}

static inline uint32_t v60_divu_value8(uint32_t a, uint32_t b) { return b ? (uint8_t)(a / b) : a; }
static inline uint32_t v60_divu_value16(uint32_t a, uint32_t b) { return b ? (uint16_t)(a / b) : a; }
static inline uint32_t v60_divu_value32(uint32_t a, uint32_t b) { return b ? a / b : a; }

static inline uint32_t v60_rem_value8(uint32_t a, uint32_t b) { return b ? (uint8_t)((int8_t)a % (int8_t)b) : a; }
static inline uint32_t v60_rem_value16(uint32_t a, uint32_t b) { return b ? (uint16_t)((int16_t)a % (int16_t)b) : a; }

static inline uint32_t v60_rem_value32(uint32_t a, uint32_t b)
{
	if (!b)
		return a;
	/* INT_MIN % -1 traps on x86; its value is 0 */
	return (a == 0x80000000u && b == 0xffffffffu) ? 0 : (uint32_t)((int32_t)a % (int32_t)b);
}

static inline uint32_t v60_remu_value8(uint32_t a, uint32_t b) { return b ? (uint8_t)(a % b) : a; }
static inline uint32_t v60_remu_value16(uint32_t a, uint32_t b) { return b ? (uint16_t)(a % b) : a; }
static inline uint32_t v60_remu_value32(uint32_t a, uint32_t b) { return b ? a % b : a; }

/* ---- shifts and rotates: the count is the low byte of the operand, signed; negative goes right ---- */

static inline uint32_t v60_width_mask(int bits) { return bits == 32 ? 0xffffffffu : (1u << bits) - 1; }

static inline uint32_t v60_shl_value(uint32_t value, uint32_t operand, int bits)
{
	const int count = (int8_t)(operand & 0xff);
	if (count > 0)
		return shl32(value, count) & v60_width_mask(bits);
	if (count < 0)
		return shr32(value, -count) & v60_width_mask(bits);
	return value;
}

static inline uint32_t v60_shl_cy(uint32_t value, uint32_t operand, int bits)
{
	const int count = (int8_t)(operand & 0xff);
	if (count > 0)
		return bits == 32 ? (uint32_t)((shl64(value, count) >> 32) & 1) : (shl32(value, count) >> bits) & 1;
	if (count < 0)
		return (uint32_t)((bits == 32 ? shr64(value, -count - 1) : shr32(value, -count - 1)) & 1);
	return 0;
}

static inline uint32_t v60_shl_ov(uint32_t value, uint32_t operand, int bits)
{
	(void)value;
	(void)operand;
	(void)bits;
	return 0;
}

static inline uint32_t v60_sha_value(uint32_t value, uint32_t operand, int bits)
{
	int8_t count = (int8_t)(operand & 0xff);
	const uint32_t mask = v60_width_mask(bits);
	const uint32_t sign = (value >> (bits - 1)) & 1;

	if (count == 0)
		return value;
	if (count > 0)
		return count >= bits ? 0 : shl32(value, count) & mask;
	count = (int8_t)-count;    /* -128 stays -128, as in MAME's int8_t arithmetic */
	if (count >= bits)
		return sign ? mask : 0;
	{
		const int32_t extended = bits == 8 ? (int8_t)value : bits == 16 ? (int16_t)value : (int32_t)value;
		return (uint32_t)sar32(extended, count) & mask;
	}
}

static inline uint32_t v60_sha_cy(uint32_t value, uint32_t operand, int bits)
{
	int8_t count = (int8_t)(operand & 0xff);
	if (count == 0)
		return 0;
	if (count > 0)
		return (uint32_t)(shr32(value, bits - count) & 1);
	count = (int8_t)-count;
	return (uint32_t)(shr32(value, count - 1) & 1);
}

static inline uint32_t v60_sha_ov(uint32_t value, uint32_t operand, int bits)
{
	const int8_t count = (int8_t)(operand & 0xff);
	if (count > 0)
	{
		const uint32_t sign = (value >> (bits - 1)) & 1;
		uint32_t out = count == 32 ? 0xffffffffu : shl32(1, count) - 1;
		out = shl32(out, bits - count);
		return sign ? (value & out) != out : (value & out) != 0;
	}
	return 0;
}

static inline uint32_t v60_rot_value(uint32_t value, uint32_t operand, int bits)
{
	int8_t count = (int8_t)(operand & 0xff);
	const uint32_t mask = v60_width_mask(bits);
	const uint32_t top = 1u << (bits - 1);

	if (count > 0)
	{
		for (int8_t i = 0; i < count; i++)
			value = ((value << 1) | ((value & top) ? 1 : 0)) & mask;
	}
	else if (count < 0)
	{
		count = (int8_t)-count;
		for (int8_t i = 0; i < count; i++)
			value = (value >> 1) | ((value & 1) ? top : 0);
	}
	return value;
}

static inline uint32_t v60_rot_cy(uint32_t value, uint32_t operand, int bits)
{
	const int8_t count = (int8_t)(operand & 0xff);
	const uint32_t result = v60_rot_value(value, operand, bits);
	if (count > 0)
		return result & 1;
	if (count < 0)
		return (result & (1u << (bits - 1))) ? 1 : 0;
	return 0;
}

static inline uint32_t v60_rot_ov(uint32_t value, uint32_t operand, int bits)
{
	(void)value;
	(void)operand;
	(void)bits;
	return 0;
}

/* ROTC rotates through the carry: 'carry' is the flag before the instruction */
static inline uint32_t v60_rotc_both(uint32_t value, uint32_t operand, uint32_t carry, int bits, uint32_t *carry_out)
{
	int8_t count = (int8_t)(operand & 0xff);
	const uint32_t mask = v60_width_mask(bits);
	const uint32_t top = 1u << (bits - 1);

	if (count > 0)
	{
		for (int8_t i = 0; i < count; i++)
		{
			const uint32_t in = carry;
			carry = (value & top) ? 1 : 0;
			value = ((value << 1) | in) & mask;
		}
	}
	else if (count < 0)
	{
		count = (int8_t)-count;
		for (int8_t i = 0; i < count; i++)
		{
			const uint32_t in = carry;
			carry = value & 1;
			value = (value >> 1) | (in ? top : 0);
		}
	}
	else
		carry = 0;
	*carry_out = carry;
	return value;
}

static inline uint32_t v60_rotc_value(uint32_t value, uint32_t operand, uint32_t carry, int bits)
{
	uint32_t carry_out;
	return v60_rotc_both(value, operand, carry, bits, &carry_out);
}

static inline uint32_t v60_rotc_cy(uint32_t value, uint32_t operand, uint32_t carry, int bits)
{
	uint32_t carry_out;
	v60_rotc_both(value, operand, carry, bits, &carry_out);
	return carry_out;
}

static inline uint32_t v60_rotc_ov(uint32_t value, uint32_t operand, uint32_t carry, int bits)
{
	(void)value;
	(void)operand;
	(void)carry;
	(void)bits;
	return 0;
}

/* ---- MOVT: overflow unless the dropped bits are a sign extension of the result ---- */

static inline uint32_t v60_movt_overflow(uint32_t value, int from_bits, int to_bits)
{
	const uint32_t result = value & ((1u << to_bits) - 1);
	const uint32_t dropped = v60_width_mask(from_bits) & ~((1u << to_bits) - 1);
	const bool negative = (result >> (to_bits - 1)) & 1;
	return !((negative && (value & dropped) == dropped) || (!negative && (value & dropped) == 0));
}

/* ---- SETF: 1 when the condition named by the low 4 bits holds ---- */

static inline uint32_t v60_condition(uint32_t condition, uint32_t z, uint32_t s, uint32_t ov, uint32_t cy)
{
	switch (condition & 0xf)
	{
		case 0: return ov;
		case 1: return !ov;
		case 2: return cy;
		case 3: return !cy;
		case 4: return z;
		case 5: return !z;
		case 6: return cy | z;
		case 7: return !(cy | z);
		case 8: return s;
		case 9: return !s;
		case 10: return 1;
		case 11: return 0;
		case 12: return s ^ ov;
		case 13: return !(s ^ ov);
		case 14: return (s ^ ov) | z;
		default: return !((s ^ ov) | z);
	}
}

/* ---- RVBYT: the four bytes in reverse order ---- */

static inline uint32_t v60_byte_swap(uint32_t value)
{
	return (value >> 24) | ((value >> 8) & 0xff00) | ((value << 8) & 0xff0000) | (value << 24);
}


}


# 28 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"


extern "C" {


	/* Work RAM holds the game's variables, at the addresses the original program used, so its state compares
	byte for byte with the original. A variable is an lvalue of its type at its address; ram.h (written
	by tools/decompile.py) names them. The V60 is little endian and lets a halfword or word sit at any
	address, like the targets this runs on; the build turns strict aliasing off for this code. */
	/* Functions that stop the game: the C compiler knows they do not come back */
# 47 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"

# 61 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"

	/* a structure pointer that is not in work RAM: in the program ROM (a link left at 0 in an object a
	scenario crafted), the bus reads the ROM there and drops writes, so it gets a copy of the ROM to read
	and write; anywhere else the program stops */
	uint8_t *ram_outside(uint32_t address);

	static inline uint8_t *ram(uint32_t address)
	{
		const uint32_t region = address & 0xf00000u;

		if (region == 0x200000u)
			return &s32_board.work_ram[address & 0xffffu];
		if (region == 0x300000u)
			return &s32_board.video_ram[address & 0x1ffffu];
		if (region == 0x400000u)
			return &s32_board.sprite_ram[address & 0x1ffffu];
		if (region == 0x500000u)
			return &s32_board.sprite_control[(address >> 1) & 7u];
		if (region == 0x600000u)
		{
			if (address & 0x10000u)
				return (uint8_t *)&s32_board.mixer[(address >> 1) & 0x3fu];
			return (uint8_t *)s32_board.palette + (address & 0x7fffu);
		}
		if (region == 0x700000u)
			return &s32_board.shared_ram[address & 0x1fffu];
		if ((address & 0xc00000u) == 0x800000u || region == 0xe00000u)
			return (uint8_t *)&s32_board.program[address & 0x1fffffu];
		if (region == 0xc00000u)
			return &s32_board.io_latch[address & 7u];
		if (region == 0xd00000u)
			return &s32_board.irq_control[address & 0xfu];
		return ram_outside(address);
	}

	/* The program ROM, which the game's code also reads as data (tables): the user's ROM image, as the board
	maps it (the first 2 MB, and the first 1 MB again from 0xF00000). A pointer the code sets to the ROM
	can hold a work RAM address instead (a list the game was poked to read from RAM): the read goes there,
	as the bus would send it */
	__attribute__((noreturn)) void rom_outside(uint32_t address);

	static inline const uint8_t *rom(uint32_t address)
	{
		if ((address & 0xf00000u) == 0xf00000u)
			return &s32_board.program[address & 0xfffffu];
		if ((address & 0xc00000u) == 0x800000u || (address & 0xf00000u) == 0xe00000u)
			return &s32_board.program[address & 0x1fffffu];
		if ((address & 0xffffffu) < 0x200000u)
			return &s32_board.program[address & 0x1fffffu];
		return ram(address);
	}

# 119 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"

# 126 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"

	/* The game links its objects by the low halfword of their addresses: the object 'link' names, in the
	page of work RAM 'base' points into */


	/* the board's memories (addresses the code computes into them) */
# 145 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"

	/* A variable read with another width than its own, or a part of one */
# 153 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\runtime\\include\\game/support.h"

	/* Processor status word: interrupt enable (bit 18), stacks and levels; the flags (bits 0-3) are local
	variables of the code, merged in when the program reads the whole word */
	extern uint32_t psw;



	uint32_t psw_read(uint32_t z, uint32_t s, uint32_t ov, uint32_t cy);
	void psw_write(uint32_t value);
	uint32_t psw_update(uint32_t current, uint32_t value, uint32_t mask);   /* UPDPSW; gives the new word */

	/* The program turns the interrupts off around what they must not cut in on (the EEPROM, the protection) */
	static inline void interrupts_off(void)
	{
		psw_update(psw, 0, (1u << 18));
	}

	static inline void interrupts_on(void)
	{
		psw_update(psw, (1u << 18), (1u << 18));
	}

	/* Arithmetic the code does with values it computes, the way the game's processor does it:
	- a division by 0 leaves the dividend as it was, and so does the one quotient that does not fit (the
	lowest number divided by -1); by a constant the C divides with / and %;
	- a shift or rotation by a computed count takes the count's low byte as signed: left when positive,
	right when negative; 'bits' is the width of the value */
	static inline uint32_t divide_s8(uint32_t a, uint32_t b) { return v60_div_value8(a, b); }
	static inline uint32_t divide_s16(uint32_t a, uint32_t b) { return v60_div_value16(a, b); }
	static inline uint32_t divide_s32(uint32_t a, uint32_t b) { return v60_div_value32(a, b); }
	static inline uint32_t divide_u8(uint32_t a, uint32_t b) { return v60_divu_value8(a, b); }
	static inline uint32_t divide_u16(uint32_t a, uint32_t b) { return v60_divu_value16(a, b); }
	static inline uint32_t divide_u32(uint32_t a, uint32_t b) { return v60_divu_value32(a, b); }
	static inline uint32_t remainder_s8(uint32_t a, uint32_t b) { return v60_rem_value8(a, b); }
	static inline uint32_t remainder_s16(uint32_t a, uint32_t b) { return v60_rem_value16(a, b); }
	static inline uint32_t remainder_s32(uint32_t a, uint32_t b) { return v60_rem_value32(a, b); }
	static inline uint32_t remainder_u8(uint32_t a, uint32_t b) { return v60_remu_value8(a, b); }
	static inline uint32_t remainder_u16(uint32_t a, uint32_t b) { return v60_remu_value16(a, b); }
	static inline uint32_t remainder_u32(uint32_t a, uint32_t b) { return v60_remu_value32(a, b); }
	static inline uint32_t shift_by(uint32_t value, uint32_t count, int bits) { return v60_shl_value(value, count, bits); }
	static inline uint32_t shift_signed_by(uint32_t value, uint32_t count, int bits) { return v60_sha_value(value, count, bits); }
	static inline uint32_t rotate_by(uint32_t value, uint32_t count, int bits) { return v60_rot_value(value, count, bits); }
	static inline uint32_t rotate_with_carry_by(uint32_t value, uint32_t count, uint32_t carry, int bits)
	{
		return v60_rotc_value(value, count, carry, bits);
	}
	static inline uint32_t byte_swap32(uint32_t value) { return v60_byte_swap(value); }

	/* LDPR: the privileged registers (the system base register says where the interrupt vectors are) */
	void load_privileged(uint32_t number, uint32_t value);

	/* The frame loop: while the program waits for a frame, the board runs its next event; then the
	program takes the interrupts that event raised; when the wait is over, a frame is done */
	void frame_wait(uint32_t frames_to_wait);
	void take_interrupts(void);
	void frame_end(void);

	/* HALT: the V60 stops until an interrupt comes. MAME's core goes on with the next instruction at once,
	and so does the game here (the program's only halts start int_default and int_vector_02, the handlers
	of the interrupts it does not expect, where two checks for states that should not happen jump too:
	build_sprite_list's and delete_object_and_children's) */
	static inline void halt(void)
	{
	}

	/* Calls through addresses the program keeps in memory (object handlers, interrupt hooks) */
	typedef struct game_code_entry
	{
		uint32_t address;
		void(*function)(void);
	} game_code_entry;

	extern const game_code_entry game_code[];      /* sorted by address; written by tools/decompile.py */
	extern const size_t game_code_count;
	void game_entry(void);                          /* the code at the reset vector */

	void call_code(uint32_t address);
	__attribute__((noreturn)) void unknown_code(uint32_t address);    /* a jump or call to an address no code was found at */
	/* the default of a switch on a jump table's index: the original checks nothing, and an index past the table
	would jump to 'address', which no case handles */
	__attribute__((noreturn)) void invalid_jump(uint32_t address);
	__attribute__((noreturn)) void invalid_operand(uint32_t address); /* an instruction the V60 cannot run (code the game never calls) */

	/* With tools/decompile.py --trace, every function calls game_trace when it starts (the calls go to stderr)
	and every block of code game_trace_block (the V60 addresses of the blocks that ran are written to
	blocks_run.txt when the program ends) */
	void game_trace(uint32_t address);
	void game_trace_block(uint32_t address);

	/* MOVCU / MOVCFU / MOVCD: 'fill' is the fill value (R26); they leave in 'dest_end' and 'source_end'
	(R27, R28) the addresses past the last element moved */
	void move_string(uint32_t source, uint32_t source_length, uint32_t dest, uint32_t dest_length, uint32_t element_size,
		uint32_t fill_rest, uint32_t downward, uint32_t fill, uint32_t *dest_end, uint32_t *source_end);

	/* the string moves the game makes most, when nothing reads the end addresses: 'count' elements copied
	from the first one up, or from the last one down (MOVCD), and 'count' elements set to 'value' */
	void move_bytes(uint32_t dest, uint32_t source, uint32_t count);
	void move_halfwords(uint32_t dest, uint32_t source, uint32_t count);
	void move_bytes_backward(uint32_t dest, uint32_t source, uint32_t count);
	void move_halfwords_backward(uint32_t dest, uint32_t source, uint32_t count);
	void set_bytes(uint32_t dest, uint32_t count, uint32_t value);
	void set_halfwords(uint32_t dest, uint32_t count, uint32_t value);

	/* MOVBSD / MOVBSU: bit strings, the offsets already split into byte address and bit */
	void move_bits_down(uint32_t source, uint32_t source_offset, uint32_t dest, uint32_t dest_offset, uint32_t length,
		uint32_t *dest_end, uint32_t *source_end);
	void move_bits_up(uint32_t source, uint32_t source_offset, uint32_t dest, uint32_t dest_offset, uint32_t length,
		uint32_t *dest_end, uint32_t *source_end);

	/* SCH0BSU / SCH1BSU: how many of the 'length' bits up from the bit string's start come before the first
	one equal to 'bit' ('length' when none is); 'work' (R28) is left at the byte of the last bit looked at */
	uint32_t search_bits_up(uint32_t address, uint32_t offset, uint32_t length, uint32_t bit, uint32_t *work);

	/* DIVX / DIVUX into a register pair: the 64-bit dividend is high:low, the quotient goes to low and the
	remainder to high */
	void divx_pair(uint32_t divisor, uint32_t *low, uint32_t *high);
	void divux_pair(uint32_t divisor, uint32_t *low, uint32_t *high);

	/* A function of the game the board puts its own in place of, in every build (runtime/replaced.txt,
	tools/decompile.py): the game's is original_NAME, the runtime's is NAME (runtime/src/game.c) */


	/* A function of the game the console build (console/, SEGASONIC_CONSOLE) puts its own in place of: there the
	game's is original_NAME, which the console's can call; elsewhere it is the game's, as it was. The functions
	are listed in console/replaced.txt (tools/decompile.py). */







}


# 16 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\game.h"
# 1 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"
/**
 *    Name:        ram.h
 *    Description: the game's variables, tables, board registers and structures
 *    Version:     0.1.0
 *    Created:     12-10-2026
 *    Modified:    22-10-2026
 *    Author:      Sebastian Toyos
 *
 *    SegaSonic The Hedgehog (arcade, Sega System 32): the game's V60 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */



# 28 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

/* the game's variables in work RAM (the original code reaches them from R25, which holds
   GAME_VARIABLES; some code adds offsets it reads from tables) */
# 1344 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

/* work RAM as one family of functions uses it (their scratch variables) */
# 1580 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

/* data in the program ROM the code reads */
# 2386 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

/* the board's registers (read and written through the bus) */
# 2467 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

/* data in the program ROM symbols.txt labels */
# 3966 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

/* numbers the code uses, by name (symbols.txt constant lines) */
# 3985 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

/* the game's structures in work RAM */
#pragma pack(push, 1)
struct object
{
	union
	{
		uint32_t credit_part_slot;
		uint16_t draw_next;
		struct
		{
			uint8_t pad_00[0x2];
			uint16_t sprite_flags;
		};
	};
	union
	{
		uint32_t part_list;
		uint16_t sprite_frame;
		struct
		{
			uint8_t pad_04[0x2];
			uint16_t sprite_palette;
		};
	};
	uint16_t sprite_scale;
	uint16_t sprite_layer;
	int16_t screen_y;
	int16_t screen_x;
	union
	{
		struct
		{
			union
			{
				uint16_t hitbox_size_x;
				uint8_t shadow_blink;
			};
			union
			{
				uint16_t hitbox_size_y;
				int8_t hitbox_centre_x;
				struct
				{
					uint8_t pad_12[0x1];
					int8_t hitbox_centre_y;
				};
			};
			int16_t anchor_x;
			int16_t anchor_y;
			int16_t sprite_height;
			int16_t sprite_width;
			union
			{
				uint32_t handler;
				uint16_t handler_low;
				struct
				{
					uint8_t pad_1C[0x2];
					uint16_t handler_high;
				};
			};
			uint16_t previous;
			uint16_t next;
			union
			{
				uint16_t direction;
				uint8_t direction_low;
				struct
				{
					uint8_t pad_24[0x1];
					uint8_t direction_high;
				};
			};
			union
			{
				uint16_t parent;
				struct
				{
					uint8_t pad_26[0x1];
					int8_t hud_anim_timer;
				};
			};
			union
			{
				uint32_t hud_anim;
				uint16_t child;
				struct
				{
					uint8_t pad_28[0x2];
					union
					{
						int16_t projected_x;
						uint8_t letter_fraction;
						struct
						{
							uint8_t pad_2A[0x1];
							int8_t letter_code;
						};
					};
				};
			};
			union
			{
				int32_t projected_y;
				int8_t hud_anim_repeats;
				uint16_t projected_y_fraction;
				struct
				{
					uint8_t pad_2C[0x1];
					int8_t piece_frame;
					union
					{
						int16_t projected_y_int;
						uint8_t piece_value;
					};
				};
			};
			union
			{
				uint32_t flags;
				uint8_t flags_low_byte;
				uint16_t flags_low;
				struct
				{
					uint8_t pad_30[0x1];
					uint8_t step;
					int16_t timer;
				};
			};
			union
			{
				int32_t speed_x;
				uint8_t speed_x_low_byte;
				uint16_t speed_x_fraction;
				struct
				{
					uint8_t pad_34[0x2];
					int16_t speed_x_int;
				};
			};
			union
			{
				int32_t speed_y;
				uint16_t speed_y_fraction;
				struct
				{
					uint8_t pad_38[0x2];
					int16_t speed_y_int;
				};
			};
			union
			{
				int32_t speed_z;
				uint16_t speed_z_fraction;
				struct
				{
					uint8_t pad_3C[0x2];
					int16_t speed_z_int;
				};
			};
			union
			{
				int32_t z;
				uint16_t z_fraction;
				struct
				{
					uint8_t pad_40[0x2];
					int16_t z_int;
				};
			};
			uint8_t animation_speed;
			int8_t animation_timer;
			uint8_t animation_frame;
			uint8_t kind;
			uint32_t animation;
			union
			{
				int32_t x;
				uint16_t x_fraction;
				struct
				{
					uint8_t pad_4C[0x2];
					int16_t x_int;
				};
			};
			union
			{
				int32_t y;
				uint16_t y_fraction;
				struct
				{
					uint8_t pad_50[0x2];
					int16_t y_int;
				};
			};
			union
			{
				int32_t floor_z;
				uint16_t floor_z_fraction;
				struct
				{
					uint8_t pad_54[0x2];
					int16_t floor_z_int;
				};
			};
			union
			{
				int32_t previous_floor_z;
				uint16_t previous_floor_z_fraction;
				struct
				{
					uint8_t pad_58[0x2];
					int16_t previous_floor_z_int;
				};
			};
			int32_t floor_block;
			union
			{
				int32_t previous_floor_block;
				struct
				{
					uint8_t pad_60[0x2];
					uint16_t cycle_count;
				};
			};
			int8_t sprite_offset_x;
			int8_t sprite_offset_y;
			union
			{
				uint16_t hitbox_height;
				struct
				{
					uint8_t pad_66[0x1];
					uint8_t tally_gets_bonus;
				};
			};
			uint16_t hit_list_next;
			union
			{
				uint16_t touched_by;
				uint8_t tally_character;
			};
			int16_t touch_distance;
			union
			{
				int32_t speed;
				uint8_t member_state;
				uint16_t speed_fraction;
				struct
				{
					uint8_t pad_6E[0x1];
					uint8_t member_number;
					int16_t speed_int;
				};
			};
			uint16_t platform_list_next;
			uint16_t platform;
			uint8_t floor_slope;
			uint8_t floor_type;
			uint16_t wall;
			uint16_t floor_attribute;
			int8_t hitbox_offset_x;
			int8_t hitbox_offset_y;
			int8_t health;
			uint8_t var_7F;
			uint8_t var_80;
			uint8_t var_81;
			union
			{
				uint16_t var_82;
				uint8_t var_82_low;
				struct
				{
					uint8_t pad_82[0x1];
					uint8_t var_83;
				};
			};
			union
			{
				uint16_t var_84;
				uint8_t var_84_low;
				struct
				{
					uint8_t pad_84[0x1];
					uint8_t var_85;
				};
			};
			uint16_t var_86;
			union
			{
				uint16_t draw_depth;
				uint8_t var_88_low;
			};
			uint16_t var_8A;
			uint16_t var_8C;
			uint8_t var_8E;
			uint8_t var_8F;
			union
			{
				uint16_t var_90;
				struct
				{
					uint8_t pad_90[0x1];
					uint8_t var_91;
				};
			};
			union
			{
				uint16_t spawn_arg_1;
				uint8_t spawn_arg_1_low;
				struct
				{
					uint8_t pad_92[0x1];
					uint8_t spawn_arg_1_high;
				};
			};
			union
			{
				uint16_t spawn_arg_2;
				uint8_t spawn_arg_2_low;
				struct
				{
					uint8_t pad_94[0x1];
					uint8_t spawn_arg_2_high;
				};
			};
			uint16_t var_96;
			union
			{
				uint16_t var_98;
				struct
				{
					uint8_t pad_98[0x1];
					uint8_t var_99;
				};
			};
			union
			{
				uint16_t var_9A;
				uint8_t player;
			};
			uint32_t next_handler;
		};
		struct
		{
			uint8_t pad_10[0x22];
			int16_t timer;
			uint8_t pad_34[0x4];
			uint32_t legs;
			uint8_t pad_3C[0x10];
			uint32_t body_frames;
			uint32_t leg_frames;
			uint8_t pad_54[0xC];
			int8_t frame_index;
			uint8_t pad_61[0x1];
			uint16_t cycle_count;
		} animate_ending;
		struct
		{
			uint8_t pad_10[0x22];
			uint8_t timer_low;
		} animate_ending_debris;
		struct
		{
			uint8_t pad_10[0x50];
			uint8_t frame_index;
		} animate_horizon_blast;
		struct
		{
			uint8_t pad_10[0x15];
			uint8_t frame;
			uint8_t anim_delay;
			int8_t anim_timer;
			uint32_t anim;
		} animate_hud;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
		} animate_sign;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t sink_step;
		} animate_sinking_mine;
		struct
		{
			uint8_t pad_10[0x50];
			uint8_t frame_index;
		} animate_tower_blast;
		struct
		{
			uint8_t pad_10[0x38];
			uint8_t bite_step;
			int8_t bite_timer;
			uint8_t bob_counter;
			int8_t bounce_index;
			uint8_t pad_4C[0x34];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
		} biting_head_view;
		struct
		{
			uint8_t pad_10[0x20];
			uint16_t step_timer;
		} blink_current_map_marker;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t draw_depth;
		} board_prop;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t wait_timer;
		} boulder;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t frame_timer;
		} breakable_panel;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t wait_timer;
		} brick_dust;
		struct
		{
			uint8_t pad_10[0x6F];
			uint8_t state;
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			union
			{
				int32_t fixed_projected_x;
				uint16_t projected_x_fraction;
				struct
				{
					uint8_t pad_94[0x2];
					int16_t projected_x_whole;
				};
			};
			uint8_t off_screen;
			uint8_t sound_timer;
		} bridge_fire;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t frame_timer;
		} bubble_column;
		struct
		{
			uint8_t pad_10[0x74];
			uint16_t draw_depth;
		} bubble_near_parent_update;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t base_x;
			uint16_t base_y;
			uint16_t draw_depth;
			uint16_t variant;
		} bubble_pop;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t base_x;
			uint16_t base_y;
			uint8_t pad_84[0x2];
			uint16_t variant;
		} bubble_start;
		struct
		{
			uint8_t pad_10[0x74];
			uint16_t draw_depth;
		} bubble_update;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t rows_left;
			int32_t row_projected_y;
			uint8_t pad_86[0xE];
			union
			{
				int32_t row_projected_x;
				struct
				{
					uint8_t pad_94[0x2];
					int16_t row_projected_x_whole;
				};
			};
		} build_grate_steps;
		struct
		{
			uint8_t pad_10[0x28];
			uint32_t bonus_label;
			uint8_t pad_3C[0x4];
			uint32_t backdrop;
			uint32_t part_3;
			uint32_t units_digit;
			uint32_t tens_digit;
			uint32_t hundreds_digit;
			uint8_t pad_54[0x8];
			uint32_t result_frames;
			uint8_t pad_60[0x7];
			uint8_t gets_bonus;
		} build_ring_tally_panel;
		struct
		{
			uint8_t pad_10[0x84];
			union
			{
				int32_t fixed_projected_x;
				uint16_t projected_x_fraction;
				struct
				{
					uint8_t pad_94[0x2];
					int16_t projected_x_whole;
				};
			};
		} build_saw_shaft_base;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t invisible;
			uint8_t no_second_sprite;
		} build_wall_parts;
		struct
		{
			uint8_t pad_10[0x4E];
			int16_t floor_block_high;
			uint8_t pad_60[0x20];
			union
			{
				uint32_t path;
				struct
				{
					uint8_t pad_80[0x2];
					uint16_t path_high;
				};
			};
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			uint8_t pad_94[0x2];
			uint8_t state;
			uint8_t rumble_timer;
			int16_t start_delay;
			uint16_t draw_depth;
			uint16_t depth_offset;
			int16_t slow_timer;
		} burning_boulder;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t boulder;
			uint8_t pad_28[0x58];
			int16_t offset_x;
			int16_t offset_y;
			int16_t pause_timer;
		} burning_boulder_flame;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			uint8_t step;
			uint8_t pad_81[0x1];
			uint16_t step_timer;
		} button_box;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t lifted;
			uint16_t angle;
			uint16_t spiral_speed;
		} cactus;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} cage_bar;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t glint_timer;
			uint8_t glint_timer_high;
			uint16_t hover_height;
		} carried_ring;
		struct
		{
			uint8_t pad_10[0x24];
			uint8_t state;
			uint8_t pad_35[0x1];
			uint16_t launch_position;
			uint8_t launch_kind;
			uint8_t rides_platform;
		} catapult;
		struct
		{
			uint8_t pad_10[0x71];
			int8_t path_write_index;
			uint16_t wobble_angle;
			uint8_t pad_84[0x2];
			uint16_t hop_timer;
		} centipede;
		struct
		{
			uint8_t pad_10[0x72];
			int16_t path_index;
		} centipede_follow_path;
		struct
		{
			uint8_t pad_10[0x72];
			int16_t path_index;
			uint8_t pad_84[0x2];
			uint16_t hop_timer;
		} centipede_segment;
		struct
		{
			uint8_t pad_10[0x72];
			int16_t path_index;
			uint8_t pad_84[0x2];
			uint16_t hop_timer;
			uint8_t pad_88[0xA];
			uint32_t segment_ahead;
		} centipede_tail;
		struct
		{
			union
			{
				uint32_t player_block;
				struct
				{
					uint8_t pad_10[0x2];
					uint8_t name_changed;
					int8_t turn_direction;
				};
			};
			uint8_t pad_14[0x6C];
			uint8_t idle_step;
			uint8_t character;
			int16_t step_timer;
			uint16_t turn_timer;
			uint8_t pad_86[0xC];
			union
			{
				uint16_t right_count;
				struct
				{
					uint8_t pad_92[0x1];
					uint8_t right_turns;
				};
			};
			union
			{
				uint16_t left_count;
				struct
				{
					uint8_t pad_94[0x1];
					uint8_t left_turns;
				};
			};
		} character_chooser;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t shown_seconds;
		} character_select_countdown;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t end_position;
		} chaser_back_zone;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
		} chaser_back_zone_check_parent;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t palette_list;
		} check_player;
		struct
		{
			uint8_t pad_10[0x70];
			union
			{
				uint16_t frame_index_word;
				int8_t frame_index;
			};
			uint16_t frame_timer;
		} checker_pad;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t copy_object;
			uint8_t pad_82[0x6];
			uint16_t draw_depth;
		} clipped_copy_sprite;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t plank_index;
			uint8_t pad_70[0x10];
			union
			{
				uint32_t angle;
				struct
				{
					uint8_t pad_80[0x2];
					int16_t angle_whole;
				};
			};
			int32_t angle_speed;
			uint16_t draw_depth;
			uint8_t swing_count;
			uint8_t pad_8B[0x1];
			uint16_t roll_frames;
			uint16_t roll_timer;
			uint8_t pad_90[0x5];
			uint8_t bridge;
			int16_t depth_offset;
			uint8_t pad_98[0x2];
			uint16_t previous_plank;
		} collapsing_bridge_plank;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			int8_t walk_step;
			uint8_t moving;
			int16_t frame_timer;
			uint8_t pad_84[0x2];
			uint16_t step_timer;
			uint8_t pad_88[0xA];
			uint8_t variant;
			uint8_t on_platform;
		} crawler;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t over_pit;
			uint8_t pad_81[0xB];
			uint16_t triggered;
			uint8_t pad_8E[0x4];
			uint8_t variant;
			uint8_t on_platform;
		} crawler_head;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t pad_6F[0x19];
			uint16_t draw_depth;
			uint8_t pad_8A[0x7];
			uint8_t silent_row;
			uint8_t pad_92[0x4];
			int16_t depth_offset;
			uint16_t normal_palette;
		} crumbling_floor;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
		} cycle_part_palettes;
		struct
		{
			uint8_t pad_10[0x50];
			int8_t palette_index;
			uint8_t pad_61[0x1];
			uint16_t palette_delay;
		} cycle_ring_tally_backdrop_palette;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t last_frame;
			uint16_t frame_timer;
			uint16_t lifetime;
		} debris;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t state;
			uint8_t pad_81[0x1];
			union
			{
				int16_t roll_out_timer;
				struct
				{
					uint8_t pad_82[0x1];
					uint8_t off_screen;
				};
			};
		} door_roller;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t state;
			uint8_t pad_81[0x1];
			int16_t roll_out_timer;
		} door_roller_roll_out;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t fragment;
			int8_t pieces_left;
		} door_wall;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
		} draw_breakable_panel;
		struct
		{
			uint8_t pad_10[0x2];
			uint8_t name_changed;
			uint8_t pad_13[0x6E];
			uint8_t character;
		} draw_character_chooser_labels;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t step;
			uint8_t pad_81[0x3];
			int16_t slide_y;
		} draw_eggman_booth;
		struct
		{
			uint8_t pad_10[0x22];
			int16_t timer;
			uint8_t pad_34[0x2C];
			uint8_t frame_index;
		} draw_ending_blast_frame;
		struct
		{
			uint8_t pad_10[0x3A];
			int8_t trail_done;
			uint8_t pad_4B[0xC];
			uint16_t marker_blink_count;
		} draw_map_stage_markers;
		struct
		{
			uint8_t pad_10[0x22];
			int16_t base_x;
			int16_t base_y;
			int32_t step_x;
			int32_t step_y;
			int32_t offset_x;
			int32_t offset_y;
			uint8_t pad_46[0x4];
			int8_t trail_done;
			uint16_t segment_frames;
			uint8_t pad_4D[0x4];
			uint32_t next_trail_point;
			uint16_t segment_timer;
		} draw_map_trail_dot;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t pad_6F[0x1B];
			uint16_t group_slot;
			uint8_t pad_8C[0x6];
			int8_t takes_slot;
		} draw_rope_bridge_ropes;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			uint8_t pad_84[0x12];
			union
			{
				uint16_t dropper_flags;
				uint8_t rides_platform;
			};
		} drop_icicle_row;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t pausing;
			int8_t stretch_step;
			uint16_t pause_timer;
			uint8_t pad_84[0xE];
			uint8_t facing;
			uint8_t den_number;
			int8_t piece_count;
		} eel_anchor;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t frame_timer;
		} eel_den;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t stretch_step;
			uint16_t explode_delay;
			uint16_t frame_timer;
			uint8_t pad_86[0xE];
			uint8_t facing;
			uint8_t den_number;
		} eel_head;
		struct
		{
			uint8_t pad_10[0x71];
			int8_t stretch_step;
			uint8_t pad_82[0x10];
			uint8_t facing;
			uint8_t pad_93[0x1];
			uint8_t piece_count;
			uint8_t wave_step;
		} eel_init;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t stretch_step;
			uint16_t frame_timer;
		} eel_piece;
		struct
		{
			uint8_t pad_10[0x71];
			int8_t stretch_step;
			uint16_t explode_delay;
			uint8_t pad_84[0x8];
			uint32_t height_offset;
			uint8_t pad_90[0x5];
			uint8_t den_number;
		} eel_segment;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t step;
			uint8_t pad_81[0x1];
			int16_t step_timer;
			int16_t slide_y;
		} eggman_booth;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t step;
			uint8_t phase;
			uint16_t step_timer;
			uint16_t talk_timer;
		} eggman_scene;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t frame_count;
			uint32_t script;
		} eggman_speech;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t step;
			uint8_t frame_index;
			uint16_t step_timer;
			uint16_t flicker_phase;
			uint16_t beam_phase;
		} eggman_teleport;
		struct
		{
			uint8_t pad_10[0x70];
			union
			{
				int16_t frame_index_word;
				int8_t frame_index;
				struct
				{
					uint8_t pad_80[0x1];
					int8_t last_frame;
				};
			};
			uint16_t frame_toggle;
			uint16_t draw_offset_y;
		} electric_pole;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t travel_direction;
			int16_t spawn_timer;
			uint16_t end_position;
		} ember_emitter;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t step;
			int16_t timer;
			uint8_t pad_34[0x10];
			uint32_t part_3;
			uint8_t pad_48[0x18];
			uint8_t frame_index;
			uint8_t list_index;
			int16_t cycle_count;
		} ending;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t step;
			int16_t timer;
			uint32_t exhaust_flame;
			uint32_t path;
			uint8_t pad_3C[0x4];
			uint32_t puff_1;
			uint32_t puff_2;
			uint32_t puff_3;
			uint32_t puff_4;
			uint32_t puff_5;
			uint32_t puff_6;
			uint32_t puff_7;
			uint32_t puff_8;
		} ending_eggman_fly_in;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			int16_t step_timer;
			uint8_t pad_34[0x2D];
			uint8_t counting_up;
		} escape_alarm_flash;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t last_frame;
			uint16_t frame_toggle;
		} explode_object;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t last_frame;
			uint16_t frame_toggle;
		} explosion;
		struct
		{
			uint8_t pad_10[0x4E];
			int16_t floor_block_high;
			uint8_t pad_60[0x20];
			uint8_t state;
			uint8_t travel_direction;
		} falling_ember;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t pad_6F[0x11];
			int16_t rattle_step;
			uint8_t pad_82[0x6];
			uint16_t draw_depth;
			uint8_t pad_8A[0xC];
			int16_t depth_offset;
		} falling_grate;
		struct
		{
			uint8_t pad_10[0x82];
			uint8_t extra_posts;
			uint8_t pad_93[0x1];
			uint8_t row_direction;
			uint8_t arc_phase;
		} fence_post;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
		} fire_front;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t flame_timer;
		} fire_trench_start;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t flame_timer;
		} fire_trench_update;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			uint32_t palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
			uint8_t pad_87[0x1];
			uint8_t burst_state;
			uint8_t pad_89[0x1];
			int16_t blast_delay;
		} fire_vent;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t shot;
		} fireball_emitter;
		struct
		{
			uint8_t pad_10[0x14];
			uint32_t arc_angle;
			uint8_t pad_28[0x57];
			uint8_t state;
			uint8_t pad_80[0x2];
			int16_t flight_timer;
		} fireball_fly;
		struct
		{
			uint8_t pad_10[0x6F];
			uint8_t state;
			uint8_t pad_80[0x16];
			int16_t target_x;
			uint8_t pad_98[0x2];
			int16_t target_y;
		} fireball_start;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t frame_phase;
			uint16_t angle;
			int16_t growth_rate;
			uint16_t growth_rate_high;
		} flame_jet;
		struct
		{
			uint8_t pad_10[0x14];
			int8_t side;
			uint8_t arm_index;
			uint8_t pad_26[0x5A];
			uint8_t frame_index;
			uint8_t sway_step;
			uint16_t frame_toggle;
			union
			{
				int16_t rest_timer;
				uint8_t sway_toggle;
				struct
				{
					uint8_t pad_84[0x1];
					int8_t sway_count;
				};
			};
		} flame_machine_arm;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t frame;
			int8_t frame_index;
			uint16_t frame_phase;
			int16_t pause_timer;
		} flame_machine_back_wall;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t frame_toggle;
		} flame_machine_flame;
		struct
		{
			uint8_t pad_10[0x76];
			uint16_t time_left;
		} flame_machine_init;
		struct
		{
			uint8_t pad_10[0x14];
			int8_t previous_health;
			uint8_t pad_25[0x5D];
			uint16_t flash_frame_count;
			uint8_t pad_84[0x2];
			uint16_t time_left;
			uint8_t pad_88[0x4];
			uint16_t destroyed_frames;
		} flame_machine_update;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t palette_list;
			uint8_t flash_on;
			uint8_t flash_period;
			uint8_t flash_timer;
		} flash_hurt_palette;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t flash_step;
			uint8_t pad_82[0x2];
			uint16_t flash_timer;
		} flash_mine_palette;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t palette_list;
		} follow_player_path;
		struct
		{
			uint8_t pad_10[0x2C];
			uint16_t turn_speed;
			uint16_t base_y;
			uint8_t pad_40[0x14];
			int8_t hop_timer;
			uint8_t step;
			uint8_t pad_56[0x2];
			int32_t drop_height;
		} gauge_ring;
		struct
		{
			uint8_t pad_10[0x72];
			uint16_t draw_depth;
		} geyser_erupt;
		struct
		{
			uint8_t pad_10[0x58];
			uint32_t next_listed_geyser;
			uint8_t pad_6C[0x12];
			int16_t sound_timer;
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			uint32_t row_pattern;
			union
			{
				int32_t fixed_projected_x;
				uint16_t projected_x_fraction;
				struct
				{
					uint8_t pad_98[0x2];
					int16_t projected_x_whole;
				};
			};
			int16_t top_height;
		} geyser_front;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			uint8_t pad_84[0x4];
			int16_t speed;
			uint8_t pad_8A[0x4];
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			int16_t travel;
		} geyser_line;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			uint16_t erupt_delay;
			uint16_t draw_depth;
		} geyser_wait;
		struct
		{
			uint8_t pad_10[0x84];
			union
			{
				int32_t fixed_projected_x;
				uint16_t projected_x_fraction;
				struct
				{
					uint8_t pad_94[0x2];
					int16_t projected_x_whole;
				};
			};
		} grate_step_debris_view;
		struct
		{
			uint8_t pad_10[0x74];
			int16_t cut_z;
			uint8_t copied_animation_speed;
			int8_t copied_animation_timer;
		} grate_step_update;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t rows_left;
			int32_t row_projected_y;
			uint8_t pad_86[0x10];
			int16_t row_projected_x;
		} grate_steps;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t leader;
			uint8_t pad_81[0x1];
			int16_t coordinate;
			uint16_t end_position;
			uint16_t which_flag;
		} group_leader_hold;
		struct
		{
			uint8_t pad_10[0x24];
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t pad_3F[0x9];
			uint32_t path;
			uint8_t pad_4C[0x34];
			int16_t wait_timer;
			uint16_t hold_start_position;
			uint8_t hold_timer;
		} group_leader_move;
		struct
		{
			uint8_t pad_10[0x7A];
			uint16_t group_slot;
			uint8_t pad_8C[0x5];
			uint8_t silent_row;
			uint8_t pad_92[0x4];
			int16_t depth_offset;
			uint16_t normal_palette;
			uint16_t previous_member;
		} group_member;
		struct
		{
			uint8_t pad_10[0x70];
			union
			{
				uint32_t next_trigger;
				uint16_t next_trigger_low;
			};
		} group_slot_trigger;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x59];
			uint8_t swing_side;
			uint16_t angle;
			union
			{
				int16_t angle_speed;
				struct
				{
					uint8_t pad_84[0x1];
					int8_t angle_speed_int;
				};
			};
			int16_t swing_accel;
			uint8_t pad_88[0xA];
			uint8_t handle_count;
			uint8_t drops_players;
			uint16_t end_position;
		} handle_rod;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			union
			{
				uint16_t index_word;
				uint8_t index;
				struct
				{
					uint8_t pad_80[0x1];
					uint8_t grip;
				};
			};
			uint16_t start_angle;
			int16_t rod_angle_speed;
			uint16_t rod;
		} handle_rod_handle;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t handle_index;
			uint8_t fallen;
		} handle_rod_post;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t next_press;
		} how_to_play_button_hand;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t step;
			int8_t pause_timer;
		} how_to_play_trackball_hand;
		struct
		{
			uint8_t pad_10[0x72];
			uint8_t state;
		} ice_block;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t blocks_left;
		} ice_block_row;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t state;
			uint8_t shake_timer;
			int16_t shake_duration;
			int16_t shake_offset;
			uint8_t pad_86[0x2];
			uint16_t draw_depth;
		} ice_floor_block;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t step;
			int8_t last_step;
			uint16_t step_timer;
			uint8_t pad_84[0xE];
			uint8_t cube_speed_index;
			uint8_t step_duration_index;
		} ice_launcher;
		struct
		{
			uint8_t pad_10[0x7C];
			int16_t travel;
			uint16_t end_position;
		} ice_platform_leader;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t member;
			uint8_t pad_70[0x18];
			uint16_t draw_depth;
			uint8_t pad_8A[0x8];
			uint8_t icicle_landed;
			uint8_t pad_93[0x3];
			int16_t depth_offset;
		} ice_platform_piece;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t next_depth;
		} icicle_cracks;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			int16_t travel;
			union
			{
				uint16_t record_flags;
				uint8_t rides_platform;
				struct
				{
					uint8_t pad_96[0x1];
					uint8_t last_dropper;
				};
			};
			union
			{
				int32_t platform_offset;
				struct
				{
					uint8_t pad_98[0x2];
					int16_t platform_offset_int;
				};
			};
			uint16_t finish_timer;
		} icicle_dropper;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x5E];
			union
			{
				uint16_t blink_timer_word;
				uint8_t blink_timer;
			};
		} icicle_shadow;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t timer;
			uint8_t state;
			uint8_t pad_83[0x1];
			uint16_t line_coordinate;
			uint8_t pad_86[0x2];
			uint16_t draw_depth;
			uint8_t pad_8A[0xC];
			union
			{
				uint16_t dropper_flags;
				uint8_t rides_platform;
				struct
				{
					uint8_t pad_96[0x1];
					uint8_t counts_goal;
				};
			};
		} icicle_update;
		struct
		{
			uint8_t pad_10[0x6F];
			uint8_t state;
			uint8_t pad_80[0x2];
			int16_t flight_timer;
			uint8_t pad_84[0x12];
			int16_t target_x;
			uint8_t pad_98[0x2];
			int16_t target_y;
		} init_fireball_flight;
		struct
		{
			union
			{
				uint32_t player_block;
				struct
				{
					uint8_t pad_10[0x3];
					int8_t turn_direction;
				};
			};
			uint8_t pad_14[0x6C];
			uint8_t portrait_changed;
			uint8_t character;
			uint16_t countdown;
		} join_character_chooser;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t base_x;
			int16_t base_y;
			uint8_t pad_84[0x8];
			uint16_t side;
			uint8_t pad_8E[0x2];
			int8_t standing;
			uint8_t pad_91[0x5];
			int16_t depth_offset;
		} lava_column;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			uint8_t pad_94[0x2];
			uint16_t unused_word;
			uint8_t sound_timer;
		} lava_flow;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x46];
			uint8_t state;
			uint8_t member;
			int16_t erupt_delay;
			uint8_t pad_72[0xE];
			uint32_t palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
			uint8_t pad_87[0x1];
			uint16_t draw_depth;
			uint16_t group_slot;
			uint8_t pad_8C[0x2];
			uint16_t rise_limit;
			uint8_t pad_90[0x2];
			uint8_t takes_slot;
			uint8_t pad_93[0x3];
			int16_t depth_offset;
		} lava_rock;
		struct
		{
			uint8_t pad_10[0x71];
			uint8_t sprung;
		} lid_trap;
		struct
		{
			uint8_t pad_10[0x38];
			int16_t move_frames;
			uint8_t pad_4A[0x28];
			int8_t sound_timer;
			uint8_t off_screen;
			uint8_t pad_74[0xB];
			uint8_t state;
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			union
			{
				int32_t fixed_projected_x;
				uint16_t projected_x_fraction;
				struct
				{
					uint8_t pad_92[0x2];
					int16_t projected_x_whole;
				};
			};
			uint8_t pad_96[0x2];
			uint16_t hold_start_position;
		} machine_fire;
		struct
		{
			uint8_t pad_10[0x20];
			uint16_t timer;
			uint8_t pad_32[0x16];
			uint16_t hold_frames;
			uint8_t pad_4A[0x7];
			uint32_t gesture_list;
			uint8_t pad_55[0x4];
			uint8_t unused_step;
			uint8_t pad_5A[0x3];
			uint8_t sound_step;
		} map_eggman;
		struct
		{
			uint8_t pad_10[0x20];
			uint16_t timer;
			uint8_t pad_32[0x27];
			uint8_t frame_step;
			uint8_t frame_step_pad;
		} map_eggman_hands;
		struct
		{
			uint8_t pad_10[0x20];
			int16_t timer;
			int16_t base_x;
			int16_t base_y;
			int32_t step_x;
			int32_t step_y;
			int32_t offset_x;
			int32_t offset_y;
		} map_intro;
		struct
		{
			uint8_t pad_10[0x20];
			int16_t timer;
			int16_t base_x;
			int16_t base_y;
			int32_t step_x;
			int32_t step_y;
			uint8_t pad_3E[0xA];
			int16_t blink_frames;
			int8_t trail_done;
			uint8_t pad_4B[0x2];
			int16_t target_x;
			int16_t target_y;
			uint8_t pad_51[0x6];
			uint16_t marker_blink_count;
			uint8_t pad_59[0x2];
			int8_t blink_phase;
		} map_screen;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			uint8_t state;
			uint8_t pad_81[0x1];
			int16_t timer;
			uint16_t frame;
		} metal_platform;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			int8_t rise_limit;
			int16_t frame_count;
			uint16_t dust_timer;
			uint8_t pad_86[0xC];
			uint8_t last_health;
			uint8_t pad_93[0x1];
			uint8_t flipped;
			uint8_t ring_count;
		} metal_wall;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t timer;
		} mine;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t frame_timer;
		} mine_splash;
		struct
		{
			uint8_t pad_10[0x20];
			int16_t timer;
			int16_t base_x;
			int16_t base_y;
			int32_t step_x;
			int32_t step_y;
			int32_t offset_x;
			int32_t offset_y;
			uint8_t pad_46[0x15];
			uint8_t blink_phase;
		} move_map_stage_icon;
		struct
		{
			uint8_t pad_10[0x78];
			union
			{
				int32_t projected_x_carry;
				struct
				{
					uint8_t pad_88[0x2];
					int16_t projected_x_carry_int;
				};
			};
		} move_object_projected;
		struct
		{
			uint8_t pad_10[0x22];
			int16_t base_x;
			int16_t base_y;
			int32_t step_x;
			int32_t step_y;
			int32_t offset_x;
			uint8_t pad_42[0x8];
			int8_t trail_done;
			uint16_t segment_frames;
			int16_t target_x;
			int16_t target_y;
			uint32_t next_trail_point;
		} next_map_trail_segment;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t scene_step_seen;
			uint8_t pad_81[0x1];
			union
			{
				int32_t zoom;
				struct
				{
					uint8_t pad_82[0x2];
					int16_t zoom_int;
				};
			};
			int32_t zoom_speed;
			int8_t phase;
			uint8_t pad_8B[0x1];
			uint16_t draw_depth;
		} opening_machine;
		struct
		{
			uint8_t pad_10[0x72];
			uint16_t wave_angle;
			uint8_t pad_84[0x8];
			uint32_t height_offset;
			uint8_t pad_90[0x2];
			uint16_t wave_amplitude;
		} place_eel_piece;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
			uint8_t pad_4C[0x10];
			int16_t floor_block_low;
			int16_t floor_block_high;
			uint8_t pad_60[0x1F];
			uint8_t health_pad;
			uint32_t palette_list;
			uint8_t hurt_flash_on;
			uint8_t hurt_flash_period;
			uint8_t hurt_flash_timer;
			uint8_t pad_87[0x15];
			uint32_t block;
		} player_view;
		struct
		{
			uint8_t pad_10[0x86];
			int16_t depth_offset;
		} player_effect;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
			uint8_t pad_4C[0x34];
			uint32_t palette_list;
		} player_object_climb;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} player_state_bouncing;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} player_state_dropping;
		struct
		{
			uint8_t pad_10[0x5A];
			uint16_t touched_by;
		} player_state_stuck;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} player_stuck_jump_out;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} player_stuck_on_object_jump_out;
		struct
		{
			uint8_t pad_10[0x5A];
			uint16_t touched_by;
		} player_stuck_wait_release;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			uint16_t sound_timer;
		} propeller_machine;
		struct
		{
			uint8_t pad_10[0x24];
			union
			{
				int16_t shake_strength;
				uint8_t shake_strength_low;
			};
			uint8_t shake_step;
			uint8_t pad_37[0x49];
			int16_t shake_dx;
			uint16_t draw_depth;
		} propped_board;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			uint8_t break_frame;
			uint8_t stopped;
			uint16_t frame_count;
			int16_t ring_timer;
			uint8_t pad_86[0xC];
			uint8_t push_quadrant;
			uint8_t post_distance;
			int16_t ring_count;
		} push_crate;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
		} quicksand;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t last_spawn_position;
		} railing_spawner;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t appear_state;
			uint8_t pad_81[0x1];
			uint16_t variant;
			int8_t hit_count;
			uint8_t pad_85[0x1];
			uint32_t damage_script;
		} ram_target;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t rows_animate;
			uint8_t rows_remove;
			uint8_t rows_remove_pad;
			uint8_t pad_83[0x1];
			int16_t hold_timer;
		} ranking_display;
		struct
		{
			uint32_t player_block;
			uint8_t pad_14[0x10];
			uint16_t rank;
			uint8_t pad_26[0xE];
			int16_t rings;
			uint8_t character;
			uint8_t stages_reached;
			union
			{
				uint32_t initials;
				uint8_t first_initial;
				struct
				{
					uint8_t pad_38[0x1];
					uint8_t second_initial;
					uint8_t third_initial;
					uint8_t initials_pad;
				};
			};
			uint32_t trackball;
			uint8_t pad_40[0x40];
			uint8_t button_bit;
			uint8_t pad_81[0x1];
			uint16_t out_of_rank_timer;
			uint16_t time_left;
		} ranking_entry;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			uint8_t animate;
			uint8_t remove;
			uint8_t pad_82[0x10];
			uint16_t row;
		} ranking_row;
		struct
		{
			uint8_t pad_10[0x72];
			int16_t pause_timer;
		} ranking_title;
		struct
		{
			uint8_t pad_10[0x6E];
			int16_t pickup_delay;
			int16_t lifetime;
			uint8_t pad_82[0x2];
			uint16_t release_delay;
			uint8_t pad_86[0x4];
			int16_t projected_x_carry_int;
			uint8_t pad_8C[0x6];
			int32_t bounce_speed;
		} released_ring;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t zoom_step;
			uint8_t pad_82[0x2];
			uint16_t open_position;
			uint16_t edge_zone;
			uint16_t draw_depth;
			uint8_t pad_8A[0x2];
			uint16_t unscaled_hitbox_size_x;
		} rimmed_sinkhole;
		struct
		{
			uint8_t pad_10[0x6E];
			uint16_t spawn_scroll_position;
			uint16_t unused_glint_timer;
		} ring_spin;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			uint16_t roll_delay;
			uint8_t pad_34[0x10];
			uint32_t tens_digit;
			uint8_t pad_48[0x14];
			uint16_t results_timer;
			uint8_t pad_5E[0x2];
			uint8_t blink_index;
			uint8_t pad_61[0x1];
			uint16_t blink_delay;
		} ring_tally_percent_view;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			uint16_t step_delay;
			uint8_t pad_34[0x4];
			uint32_t bonus_label;
			uint8_t pad_3C[0x4];
			uint32_t backdrop;
			uint32_t part_3;
			uint32_t units_digit;
			uint32_t tens_digit;
			uint32_t hundreds_digit;
			uint8_t pad_54[0xC];
			int8_t rings_counted;
			uint8_t step;
			uint16_t palette_delay;
			uint8_t pad_64[0x6];
			uint8_t character;
		} ring_tally_player;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			int16_t timer;
		} ring_tally_ticker;
		struct
		{
			uint8_t pad_10[0x6F];
			uint8_t state;
			uint8_t pad_80[0x1];
			uint8_t off_screen;
		} rising_flame;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			union
			{
				int32_t fixed_projected_x;
				uint16_t projected_x_fraction;
				struct
				{
					uint8_t pad_94[0x2];
					int16_t projected_x_whole;
				};
			};
		} rising_saw;
		struct
		{
			uint8_t pad_10[0x74];
			uint8_t unused_state;
		} river_raft_foam;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t entry;
			uint16_t end_position;
			uint32_t list_start;
			union
			{
				int32_t last_raft_y;
				struct
				{
					uint8_t pad_8A[0x2];
					int16_t last_raft_y_int;
				};
			};
			uint32_t last_raft_speed;
		} river_raft_spawner;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
			uint8_t pad_4C[0x38];
			uint8_t state;
			uint8_t pad_85[0x3];
			uint16_t draw_depth;
		} river_raft_update;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
			uint8_t pad_4C[0x22];
			uint8_t state;
			uint8_t pad_6F[0x19];
			uint16_t draw_depth;
			uint8_t pad_8A[0xC];
			int16_t depth_offset;
		} river_water;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t break_frame;
			uint8_t breaking;
			int16_t frame_count;
			uint16_t twinkle_delay;
		} rock_wall;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t limit;
		} roller_back_zone;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t plank_index;
			uint8_t pad_70[0x18];
			uint16_t draw_depth;
			uint16_t group_slot;
			uint8_t pad_8C[0x6];
			int8_t takes_slot;
			uint8_t pad_93[0x2];
			uint8_t bridge;
			int16_t depth_offset;
		} rope_bridge_plank;
		struct
		{
			uint8_t pad_10[0x6E];
			uint16_t spawn_scroll_position;
			uint16_t glint_timer;
			uint16_t hover_height;
		} row_ring;
		struct
		{
			uint8_t pad_10[0x22];
			int16_t timer;
			uint8_t pad_34[0x2D];
			uint8_t list_index;
		} run_timed_spawns;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			int8_t balls_gone;
			uint8_t row_position;
			int16_t bob_phase;
			uint8_t pad_84[0xE];
			uint8_t row_direction;
			int8_t ball_count;
		} sand_arch;
		struct
		{
			uint8_t pad_10[0x5E];
			uint8_t state;
			uint8_t pad_6F[0x19];
			uint16_t draw_depth;
			uint16_t face_object;
			uint8_t pad_8C[0xA];
			int16_t depth_offset;
		} sand_block;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
		} sand_block_leader;
		struct
		{
			uint8_t pad_10[0x86];
			int16_t depth_offset;
		} sand_face;
		struct
		{
			uint8_t pad_10[0x72];
			uint16_t lifetime;
			int16_t frame_index;
		} sand_puff;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t crumble_frame;
			uint8_t crumbling;
			int16_t frame_count;
			uint8_t pad_84[0xE];
			uint8_t ring_count;
		} sand_rock;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
		} sand_streams;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			int16_t next_shaft_z;
			uint8_t pad_82[0x1];
			uint8_t state;
			int16_t sound_timer;
			uint8_t pad_86[0x2];
			uint16_t draw_depth;
		} saw_blade;
		struct
		{
			uint8_t pad_10[0x72];
			uint8_t state;
		} saw_shaft_base_draw;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t next_step_z;
			uint8_t state;
		} saw_shaft_update;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
		} saw_sparks;
		struct
		{
			uint8_t pad_10[0x6E];
			int16_t pickup_delay;
			int16_t lifetime;
		} scattered_ring;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t end_position;
		} scene_anchor;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t end_position;
		} scene_carrier;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t end_position;
			uint16_t radius_x4;
		} scene_object_view;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
			uint8_t pad_87[0x1];
			uint16_t unused_stage;
			int16_t depth_offset;
		} scenery_sprite;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t palette_list;
			uint8_t palette_index;
			uint8_t palette_delay;
			uint8_t palette_timer;
		} screen_sign;
		struct
		{
			uint8_t pad_10[0x21];
			uint8_t scrolled_out;
			int16_t timer;
		} scroll_credits;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} seesaw;
		struct
		{
			uint8_t pad_10[0x4E];
			uint16_t floor_block_high;
		} set_player_entry_by_scene;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t flicker_timer;
		} shadow;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t frame_timer;
		} shaking_block;
		struct
		{
			uint8_t pad_10[0x86];
			int16_t depth_offset;
		} sink_swirl;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t zoom_step;
			uint8_t pad_82[0x2];
			uint16_t open_position;
			uint8_t pad_86[0x2];
			uint16_t draw_depth;
			int8_t unscaled_offset_x;
			int8_t unscaled_offset_y;
			uint16_t unscaled_hitbox_size_x;
		} sinkhole;
		struct
		{
			uint8_t pad_10[0x86];
			int16_t depth_offset;
		} sinking_effect;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} skid_dust;
		struct
		{
			uint8_t pad_10[0x72];
			uint16_t open_delay;
		} sliding_door;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t burst_frame;
			uint8_t bursting;
			int16_t frame_count;
			int16_t part_3_count;
			uint16_t part_3_frame;
			uint8_t pad_88[0xA];
			uint8_t ring_count;
			uint8_t random_scatter;
		} snow_mound;
		struct
		{
			uint8_t pad_10[0x74];
			int16_t cut_z;
		} spawn_grate_step_debris;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t wait_timer;
		} spawn_group_leader;
		struct
		{
			uint8_t pad_10[0x82];
			uint8_t takes_slot;
			uint8_t pad_93[0x3];
			int16_t depth_offset;
		} spawn_lava_column;
		struct
		{
			uint8_t pad_10[0x58];
			uint32_t next_listed_geyser;
		} spawn_listed_geyser;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} spawn_slip_piece;
		struct
		{
			uint8_t pad_10[0x72];
			uint16_t phase_timer;
			int32_t spear_z;
		} spear_trap;
		struct
		{
			uint8_t pad_10[0x71];
			int8_t bounce_count;
			uint16_t pause_timer;
		} spike_gate_beam;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			int8_t frame_index;
			int8_t step;
			int16_t step_timer;
			uint8_t pad_84[0x2];
			uint16_t trigger_delay;
			uint8_t pad_88[0xB];
			uint8_t start_step;
		} spike_panel;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
			uint8_t pad_28[0x58];
			uint8_t spin_frame;
			uint8_t arm_frame;
			uint16_t spin_toggle;
		} spiked_disc;
		struct
		{
			uint8_t pad_10[0x70];
			int16_t sound_timer;
			int16_t frame_count;
			int16_t stopped_frames;
			uint8_t pad_86[0x8];
			uint8_t holding_back;
			uint8_t hold_timer;
		} spiked_press;
		struct
		{
			uint8_t pad_10[0x62];
			union
			{
				uint32_t event_offset_long;
				uint16_t event_offset;
				struct
				{
					uint8_t pad_72[0x2];
					uint16_t roller_kind;
				};
			};
			uint8_t pad_76[0xA];
			union
			{
				uint16_t state_word;
				uint8_t state;
				struct
				{
					uint8_t pad_80[0x1];
					uint8_t holding_back;
				};
			};
			int16_t wait_timer;
			int16_t saved_base_speed;
			uint16_t leader;
			int16_t screen_threshold;
			uint32_t path;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			uint16_t path_direction;
			uint8_t rumble_timer;
			uint8_t rumble_off_screen;
			uint8_t substate;
			uint8_t pause_timer;
			uint8_t pad_9A[0x2];
			uint16_t hold_start_position;
			uint8_t hold_timer;
		} spiked_roller;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} stage_03_floor_block;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
			uint8_t pad_4C[0x34];
			uint16_t sparkle_offset;
		} stage_clear_banner;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			int16_t timer;
			uint8_t pad_34[0x2C];
			uint8_t frame_index;
		} start_ending_blast;
		struct
		{
			uint8_t pad_10[0x3A];
			int8_t trail_done;
			uint16_t segment_frames;
			uint8_t pad_4D[0x8];
			uint16_t segment_timer;
		} start_map_trail;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t frame_index_high;
			uint16_t frame_timer;
		} static_triangle;
		struct
		{
			uint8_t pad_10[0x86];
			int16_t depth_offset;
		} stone_block;
		struct
		{
			uint8_t pad_10[0x70];
			uint16_t draw_depth;
		} stuck_effect;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			int16_t timer;
			uint8_t pad_34[0x2D];
			uint8_t list_index;
		} timed_spawner;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			union
			{
				int16_t timer;
				uint8_t timer_low;
			};
			uint8_t pad_34[0x10];
			uint32_t emblem_bottom_left;
			uint8_t pad_48[0x19];
			uint8_t frame_index;
		} title;
		struct
		{
			uint8_t pad_10[0x20];
			uint8_t started;
			uint8_t pad_31[0x1];
			int16_t timer;
			uint8_t pad_34[0x10];
			uint32_t cloud_4;
		} title_clouds;
		struct
		{
			uint8_t pad_10[0x62];
			uint8_t sound_timer;
			uint8_t off_screen;
			uint8_t pad_74[0xC];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			uint16_t rotation_angle;
			uint16_t columns;
		} tornado;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t player_block;
		} trap;
		struct
		{
			uint8_t pad_10[0x7C];
			uint8_t sound_c_timer;
			uint8_t sound_1e_timer;
			uint32_t reached_top;
		} treadmill_gate_update;
		struct
		{
			uint8_t pad_10[0x16];
			uint16_t parent;
		} treadmill_roller;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t belt_phase;
		} treadmill_update;
		struct
		{
			uint8_t pad_10[0x38];
			uint32_t animation;
		} tumble_effect;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t stroke_step;
			uint8_t pad_81[0x1];
			uint16_t stroke_timer;
		} turtle;
		struct
		{
			uint8_t pad_10[0x22];
			uint16_t step_delay;
			uint8_t pad_34[0x4];
			uint32_t bonus_label;
			uint8_t pad_3C[0x4];
			uint32_t backdrop;
			uint32_t part_3;
			uint32_t units_digit;
			uint32_t tens_digit;
			uint32_t hundreds_digit;
			uint8_t pad_54[0x8];
			uint32_t result_frames;
			int8_t rings_counted;
			uint8_t step;
			uint8_t pad_62[0x4];
			int8_t ring_total;
			uint8_t gets_bonus;
			uint8_t pad_68[0x2];
			uint8_t character;
		} update_ring_tally_panel;
		struct
		{
			uint8_t pad_10[0x4C];
			uint16_t results_timer;
			uint8_t pad_5E[0x2];
			uint8_t blink_index;
			uint8_t pad_61[0x1];
			uint16_t blink_delay;
		} update_ring_tally_percent;
		struct
		{
			uint8_t pad_10[0x14];
			uint16_t vine;
			uint8_t pad_26[0x5A];
			uint8_t holding;
			uint8_t pad_81[0x1];
			int16_t anchor_z;
		} vine_bar;
		struct
		{
			uint8_t pad_10[0x4];
			int32_t base_x;
			uint8_t pad_18[0x6A];
			int16_t depth_offset;
			uint8_t pad_84[0xF];
			uint8_t segment_count;
			uint8_t phase_step;
		} vine_init;
		struct
		{
			uint8_t pad_10[0x4];
			union
			{
				int32_t base_x;
				struct
				{
					uint8_t pad_14[0x2];
					int16_t base_x_int;
				};
			};
			uint8_t pad_18[0x30];
			union
			{
				uint32_t segment_angle;
				struct
				{
					uint8_t pad_48[0x2];
					int16_t segment_angle_int;
				};
			};
			uint8_t pad_4C[0x34];
			uint8_t holding;
			uint8_t pad_81[0x1];
			int16_t depth_offset;
			uint8_t pad_84[0x11];
			uint8_t curl_scale;
		} vine_swing;
		struct
		{
			uint8_t pad_10[0x27];
			uint8_t depth_from_next;
		} wall_editor;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t frame_step;
			uint8_t pad_81[0x1];
			uint16_t frame_timer;
		} wall_pad;
		struct
		{
			uint8_t pad_10[0x27];
			uint8_t depth_from_next;
			uint8_t edge_flags;
			uint8_t pad_39[0x47];
			uint8_t invisible;
			uint8_t no_second_sprite;
			uint16_t end_position;
		} wall_update;
		struct
		{
			uint8_t pad_10[0x70];
			uint32_t path;
			int16_t screen_threshold;
			uint16_t catch_up_factor;
			int16_t base_speed;
			int16_t saved_threshold;
			int16_t saved_base_speed;
			uint8_t holding_back;
			uint8_t hold_timer;
			int16_t wait_timer;
			uint16_t hold_start_position;
			uint16_t sound_timer;
		} waterfall;
		struct
		{
			uint8_t pad_10[0x70];
			int8_t frame_index;
			uint8_t self_copied_byte;
			uint16_t spin_angle;
			int16_t timer;
			uint16_t spin_step;
		} whirlwind;
		struct
		{
			uint8_t pad_10[0x70];
			uint8_t frame_index;
			uint8_t pad_81[0x1];
			uint16_t frame_timer;
		} white_puff;
	};
};

struct player
{
	uint8_t state;
	uint8_t facing;
	uint8_t pad_02[0x1];
	uint8_t substate;
	int16_t state_timer;
	uint8_t control_lock;
	int8_t jump_delay;
	uint8_t standing_started;
	uint8_t is_joining;
	int16_t trackball_x;
	int16_t trackball_y;
	int16_t invulnerable_timer;
	uint8_t pad_10[0x2];
	uint16_t heading;
	uint16_t object;
	uint8_t pad_16[0x4];
	uint16_t last_hazard;
	union
	{
		int32_t scene_hop_z;
		struct
		{
			uint8_t pad_1C[0x2];
			int16_t scene_hop_z_int;
		};
	};
	int16_t ledge_pullback;
	int16_t ledge_side;
	int32_t slip_distance;
	uint16_t target_heading;
	uint8_t pad_2A[0x2];
	int16_t climb_remaining;
	uint8_t climb_from_top;
	uint8_t hit_stop;
	union
	{
		int32_t step_accumulator;
		uint16_t step_accumulator_low;
		struct
		{
			uint8_t pad_30[0x2];
			int16_t step_accumulator_int;
		};
	};
	union
	{
		int32_t screen_x;
		uint16_t screen_x_fraction;
		struct
		{
			uint8_t pad_34[0x2];
			int16_t screen_x_int;
		};
	};
	int8_t in_game;
	uint8_t unused_hud_byte;
	uint8_t pad_3A[0x2];
	int32_t skid_slowdown;
	int32_t skid_speed_slowdown;
	uint8_t pad_44[0x2];
	uint8_t free_turn_timer;
	uint8_t pad_47[0x1];
	int8_t skid_dust_timer;
	uint8_t bounce_direction;
	int32_t bounce_speed_z;
	int32_t bounce_step;
	uint8_t previous_state;
	uint8_t ignore_screen_edges;
	uint8_t drift_turned_back;
	uint8_t drift_done;
	uint16_t pull_distance_factor;
	uint16_t unused_hud_word;
	uint8_t pad_5A[0x2];
	uint32_t path_pointer;
	uint8_t pad_60[0x4];
	union
	{
		int32_t ground_speed;
		struct
		{
			uint8_t pad_64[0x2];
			uint16_t ground_speed_int;
		};
	};
	union
	{
		int16_t walk_cycle;
		struct
		{
			uint8_t pad_68[0x1];
			uint8_t walk_cycle_high;
		};
	};
	int32_t walk_pending_x;
	int32_t walk_pending_y;
	int8_t attack_power;
	uint8_t alternate_run_toggle;
	uint8_t pad_74[0x1];
	uint8_t joined_health_setting;
	int32_t previous_x;
	int32_t previous_y;
	union
	{
		int32_t previous_z;
		uint8_t previous_z_low;
		struct
		{
			uint8_t pad_7E[0x2];
			int16_t previous_z_int;
		};
	};
	uint8_t pad_82[0x2];
	uint16_t screen_edge;
	uint16_t hud_portrait;
	uint16_t hud_gauge;
	uint16_t heading_snapped;
	uint8_t pad_8C[0x8];
	union
	{
		uint32_t push_xy;
		int16_t push_x;
		struct
		{
			uint8_t pad_94[0x2];
			int16_t push_y;
		};
	};
	union
	{
		int32_t animation_speed;
		struct
		{
			uint8_t pad_98[0x2];
			int16_t animation_speed_int;
		};
	};
	uint16_t holder;
	uint8_t pad_9E[0x1];
	uint8_t grey_screen_request;
	int8_t pushed_out;
	int8_t push_out_delay;
	int32_t push_out_x;
	int32_t push_out_y;
	uint16_t fall_draw_depth;
	uint16_t jump_first_tile;
	uint8_t pad_AE[0x2];
	uint16_t path_speed;
	uint8_t path;
	uint8_t unused_reset_byte;
	uint8_t mishap_flag;
	uint8_t saved_substate;
	uint16_t facing_angle;
	uint8_t scene_step_seen;
	uint8_t path_request;
	union
	{
		int32_t scene_zoom;
		uint16_t scene_zoom_fraction;
		struct
		{
			uint8_t pad_BA[0x2];
			uint16_t scene_zoom_int;
		};
	};
	int8_t hud_blink_timer;
	uint8_t hud_blink_on;
	int16_t path_wait;
	uint8_t entry_status;
	int8_t hurt_contact_delay;
	uint16_t speed_scale;
	uint16_t last_damaged;
	union
	{
		int32_t escape_progress;
		int16_t escape_progress_low;
		struct
		{
			uint8_t pad_C8[0x2];
			int16_t escape_progress_int;
		};
	};
	uint16_t draw_depth;
	union
	{
		int32_t side_step_accumulator;
		struct
		{
			uint8_t pad_CE[0x2];
			int16_t side_step_accumulator_int;
		};
	};
	int32_t saved_screen_x;
	int32_t saved_screen_y;
	uint16_t saved_climb_remaining;
	uint8_t goal_step;
	uint8_t effect_spawned;
	uint16_t own_view_y;
	uint16_t last_wall;
	int8_t wall_timer;
	uint8_t drift_anim_step;
	union
	{
		uint16_t continue_countdown;
		int8_t continue_frames;
		struct
		{
			uint8_t pad_E4[0x1];
			int8_t continue_seconds;
		};
	};
	uint16_t pull_angle;
	uint16_t pull_start_distance;
	uint8_t sequence_step;
	int8_t ledge_direction;
	uint16_t struggle_speed;
	int16_t sink_depth;
	uint8_t pad_F0[0x4];
	uint16_t ground_clip_bottom;
	uint8_t pad_F6[0x1E];
	uint32_t flags;
	uint16_t swirl_turn_rate;
	uint16_t unused_reset_word;
	uint8_t unused_jump_byte;
	uint8_t enter_on_respawn;
	uint16_t object_climb_steps;
	int8_t climb_hand;
	uint8_t pad_121[0x1];
	uint8_t entry_step;
	uint8_t hud_message_shown;
	int16_t jump_frames;
	uint16_t hud_ring_effect;
	uint8_t scene_path;
	uint8_t ending_step;
	uint16_t edge_object;
	uint16_t stage_rings_shown;
	uint8_t fast_climb;
	uint8_t sequence_bounced;
	union
	{
		int32_t climb_base_z;
		uint16_t climb_base_z_fraction;
		struct
		{
			uint8_t pad_130[0x2];
			int16_t climb_base_z_int;
		};
	};
	uint8_t ending_done;
	uint8_t game_over_done;
	uint8_t unused_start_byte;
	uint8_t stages_reached;
	uint16_t ridden_object;
	uint16_t rings;
	uint16_t stage_rings;
	uint8_t splash_zone;
	uint8_t was_in_splash_zone;
	uint8_t stage_b_path_done;
	int8_t rings_to_health;
	uint8_t pad_142[0x2];
	uint16_t hud_gauge_flags;
	uint16_t hud_gauge_tile;
	uint16_t hud_gauge_palette;
	uint16_t hud_gauge_address;
	uint8_t pad_14C[0x2];
	uint16_t hud_gauge_y;
	uint16_t hud_gauge_x;
	uint8_t pad_152[0x8];
	uint16_t hud_gauge_height;
	uint8_t pad_15C[0xA];
	uint8_t hud_gauge_health;
	uint8_t hud_gauge_frame;
	uint8_t hud_gauge_anim_delay;
	uint8_t pad_169[0x1];
	uint32_t hud_gauge_anim;
	uint8_t hud_gauge_anim_repeats;
	uint8_t hud_gauge_reset;
	uint8_t pad_170[0x4];
	uint16_t hud_portrait_flags;
	uint16_t hud_portrait_tile;
	uint16_t hud_portrait_palette;
	uint8_t pad_17A[0x4];
	uint16_t hud_portrait_y;
	uint16_t hud_portrait_x;
	uint8_t pad_182[0x8];
	uint16_t hud_portrait_height;
	uint8_t pad_18C[0xB];
	uint8_t hud_portrait_frame;
	uint8_t hud_portrait_anim_delay;
	uint8_t pad_199[0x1];
	uint32_t hud_portrait_anim;
	uint8_t hud_portrait_anim_repeats;
	uint8_t pad_19F[0x5];
	uint16_t hud_ring_effect_flags;
	uint8_t pad_1A6[0x2];
	uint16_t hud_ring_effect_palette;
	uint8_t pad_1AA[0x4];
	uint16_t hud_ring_effect_y;
	uint16_t hud_ring_effect_x;
	uint8_t pad_1B2[0x15];
	uint8_t hud_ring_effect_frame;
	uint8_t hud_ring_effect_anim_delay;
	uint8_t hud_ring_effect_anim_timer;
	uint32_t hud_ring_effect_anim;
	uint8_t pad_1CE[0x4];
	uint32_t join_time;
	uint16_t last_scroll;
	int16_t stall_frames;
	uint8_t pad_1DA[0x26];
};

struct object_type_record
{
	uint32_t part_count;
	uint32_t handler;
};

struct type_spawn_record
{
	uint16_t position;
	uint16_t projected_x;
	int16_t projected_y;
	int16_t z;
	uint16_t object_type;
	uint16_t spawn_arg_1;
	uint16_t spawn_arg_2;
};

struct handler_spawn_record
{
	uint16_t position;
	uint16_t x;
	uint16_t y;
	uint16_t handler_arg;
	uint32_t handler;
};

struct object_start_list
{
	uint16_t count;
};

struct machine_fireball_spawns
{
	uint16_t count;
};

struct machine_fireball_spawn
{
	int16_t x;
	int16_t y;
	int16_t target_x;
	int16_t target_y;
	int16_t z;
	uint32_t next_handler;
};

struct ring_row
{
	uint16_t position;
	uint16_t template_offset;
	int16_t ring_count;
	uint16_t x;
	uint16_t y;
	int8_t dx;
	int8_t dy;
};

struct group_spawn_record
{
	uint16_t position;
	uint8_t kind;
	uint8_t leader;
	uint8_t takes_slot;
	uint8_t pad_05[0x1];
	uint32_t floor_block;
	uint16_t member_count;
	uint16_t step_x;
	uint16_t step_y;
	uint16_t direction;
	uint16_t member_x;
	uint16_t member_y;
	uint16_t member_template;
};

struct sprite_buffer_swap
{
	uint16_t back_buffer_offset;
	uint16_t list_jump;
};

struct sine_and_cosine
{
	uint16_t sine;
	uint8_t pad_02[0x1FE];
	uint16_t cosine;
};

struct floor_attribute_record
{
	union
	{
		int16_t push_x;
		uint8_t axis;
	};
	int16_t push_y;
	union
	{
		int16_t x_per_rise;
		uint8_t ride;
	};
	int16_t height;
	int16_t top_z;
	uint16_t along_min;
	uint16_t along_length;
	uint16_t rise;
};

struct floor_block_type
{
	uint8_t floor_type;
	uint8_t pad_01[0x1];
	uint16_t floor_attribute;
};

struct floor_outline_list
{
	uint16_t count;
};

struct floor_outline
{
	int16_t left_x;
	int16_t left_y;
	int16_t right_x;
	int16_t right_y;
	int16_t top_x;
	int16_t top_y;
	int16_t bottom_x;
	int16_t bottom_y;
};

struct floor_outline_corner
{
	uint16_t x;
	uint16_t y;
};

struct stage_event
{
	uint16_t position;
	uint8_t next_game_mode;
	uint8_t pad_03[0x1];
};

struct stage_link_point
{
	uint16_t from_block;
	uint16_t to_block;
};

struct layer_blend_list
{
	uint8_t count;
};

struct layer_blend_record
{
	uint8_t blend_mask;
	uint8_t layer_bit;
	uint16_t shadow_offset;
	uint16_t blend_factor;
};

struct restart_point_record
{
	uint16_t position;
	uint8_t pad_02[0x6];
};

struct stage_palette
{
	uint32_t source;
	uint32_t halfword_count;
};

struct stage_name_banner
{
	uint16_t screen_x;
	uint16_t screen_y;
};

struct scroll_mode_step
{
	uint16_t mode;
	uint16_t duration;
};

struct event_0f_message
{
	int16_t show_time;
	uint16_t screen_x;
	uint16_t screen_y;
	uint16_t kind;
	uint16_t frames;
};

struct message_box_kind
{
	uint16_t sprite_frame;
	uint16_t palette;
	uint16_t width;
	uint16_t height;
};

struct stage_06_lightning_strike
{
	int16_t strike_time;
	uint16_t screen_x;
	uint16_t screen_y;
	uint32_t animation;
};

struct event_1a_scroll_step
{
	uint16_t position;
	uint16_t mode;
	uint16_t speed;
};

struct stage_03_floor_block_kind
{
	uint16_t shape;
	uint16_t fall_flag;
};

struct stage_03_floor_block_shape
{
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	uint16_t depth_offset;
};

struct stage_03_floor_block_animation
{
	uint16_t last_frame;
	uint16_t first_frame;
	uint8_t pad_04[0x4];
};

struct rock_debris_piece
{
	uint16_t sprite_flags;
	uint16_t offset_x;
	uint16_t offset_y;
	uint16_t speed_x;
	uint16_t speed_y;
	uint16_t animation_offset;
};

struct spiked_roller_kind
{
	uint8_t part_count;
	uint16_t layout;
	uint16_t first_state;
	uint16_t back_zone;
};

struct spiked_roller_chase_step
{
	uint16_t position;
	int16_t screen_threshold;
	int16_t catch_up_factor;
	int16_t base_speed;
	uint16_t wait;
};

struct spiked_roller_layout
{
	int8_t step_x;
	int8_t step_y;
	uint8_t pad_02[0xE];
};

struct spiked_roller_part
{
	uint16_t sprite_flags;
	uint16_t hitbox_size_x;
	uint16_t hitbox_size_y;
	uint16_t path_direction;
	uint32_t flags;
	int8_t hitbox_offset_x;
	int8_t hitbox_offset_y;
};

struct spiked_roller_event
{
	uint16_t position;
	uint16_t test;
	int16_t coordinate;
	uint16_t state;
};

struct door_roller_spawn
{
	int16_t x;
	int16_t y;
	uint8_t first_frame;
	uint8_t pad_05[0x1];
};

struct door_fragment
{
	uint8_t pad_00[0x8];
	uint16_t animation;
};

struct fireball_emitter_list
{
	int16_t x;
	int16_t y;
	int16_t floor_z;
};

struct fireball_type
{
	uint16_t sprite_flags;
	uint16_t sprite_palette;
	uint16_t sprite_scale;
	uint16_t hitbox_height;
	uint16_t hitbox_size_x;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	int8_t hitbox_centre_x;
	int8_t hitbox_centre_y;
	uint16_t animation;
};

struct machine_fire_script_step
{
	int16_t height;
	int16_t screen_threshold;
	int16_t catch_up_factor;
	int16_t base_speed;
	uint16_t wait;
};

struct cage_bar_animation
{
	uint16_t last_frame;
	uint8_t pad_02[0x4];
	uint16_t broken_frame;
};

struct fire_vent_spawn
{
	uint16_t position;
	int16_t x;
	int16_t y;
	int16_t z;
	int16_t blast_delay;
};

struct icicle_dropper_record
{
	int16_t x;
	int16_t y;
	int16_t z;
	uint16_t direction;
	uint16_t flags;
	uint16_t script;
};

struct icicle_dropper_step
{
	uint16_t position;
	int16_t screen_threshold;
	int16_t catch_up_factor;
	int16_t base_speed;
	uint16_t wait;
	int16_t end_coordinate;
};

struct sink_swirl_effect
{
	int16_t depth_offset;
	uint32_t streak_animation;
	uint32_t puff_animation;
};

struct object_start_place
{
	int16_t x;
	int16_t y;
	int16_t floor_z;
	uint16_t end_position;
};

struct river_raft_entry
{
	int16_t distance;
	uint16_t speed;
	uint32_t floor_block;
};

struct geyser_front_record
{
	int16_t start_z;
	int16_t top_height;
	uint16_t geyser_list;
};

struct chase_step_at_scroll
{
	uint16_t position;
	int16_t screen_threshold;
	int16_t catch_up_factor;
	int16_t base_speed;
	uint16_t wait;
};

struct listed_geyser
{
	uint16_t position;
	uint16_t x;
	uint16_t y;
	uint16_t z;
	uint16_t erupt_position;
};

struct stone_block_position
{
	int16_t x;
	int16_t y;
	int16_t z;
	int16_t depth_offset;
};

struct geyser_line_start
{
	int16_t x;
	int16_t y;
	int16_t z;
	uint16_t script;
};

struct geyser_line_step
{
	uint16_t position;
	int16_t y_limit;
	int16_t speed;
	int16_t wait;
};

struct propeller_machine_animation_step
{
	uint16_t parts_6_9_frame;
	uint16_t part_4_frame;
};

struct rope_bridge_rope_offset
{
	int16_t dx;
	int16_t dy;
};

struct spike_panel_screen_offset
{
	int16_t dx;
	int16_t dy;
};

struct spike_panel_part_offset
{
	int16_t dx;
	int16_t dy;
	int16_t dz;
};

struct flame_machine_offset
{
	int16_t dx;
	int16_t dy;
};

struct flame_machine_arm_sway
{
	int8_t dx;
	int8_t dy;
};

struct spiked_disc_hold_offset
{
	int16_t dx;
	int16_t dz;
};

struct hitbox_size_pair
{
	uint16_t size_x;
	uint16_t size_y;
};

struct hitbox_offset_pair
{
	int8_t x;
	int8_t y;
};

struct crawler_walk_row
{
	uint8_t steps[0x6];
};

struct hitbox_size_and_offset
{
	uint16_t size_x;
	uint16_t size_y;
	int8_t offset_x;
	int8_t offset_y;
};

struct crawler_piece_offset
{
	int16_t dx;
	int16_t dy;
};

struct fence_offset
{
	uint16_t dx;
	uint16_t dy;
};

struct fence_post_box
{
	uint16_t size_x;
	uint16_t size_y;
};

struct fence_post_box_offset
{
	int8_t x;
	int8_t y;
};

struct sprite_palette_cycle
{
	uint16_t last_index;
	uint16_t palettes[];
};

struct hud_step_list
{
	uint16_t last_index;
	uint16_t steps[];
};

struct eggman_speech_step
{
	int16_t delay;
	uint16_t command;
	uint16_t arguments[];
};

struct how_to_play_button_press
{
	uint16_t press_time;
	uint16_t frame;
};

struct coin_setting_value
{
	uint8_t coins_per_credit;
	uint8_t bonus_coins;
	uint8_t chute_1_coin_value;
	uint8_t chute_2_coin_value;
};

struct ending_tower_frame
{
	int16_t end_time;
	uint16_t sprite_frame;
	uint16_t sprite_palette;
};

struct ending_explosion_frame
{
	uint16_t sprite_frame;
	uint16_t sprite_flags;
};

struct ending_music_cue
{
	int16_t time;
	uint16_t sound_id;
};

struct ending_timed_frame
{
	int16_t end_time;
	uint16_t sprite_frame;
};

struct ending_timed_palette
{
	int16_t end_time;
	uint16_t sprite_palette;
};

struct scenery_kind_record
{
	uint16_t sprite_flags;
	uint16_t sprite_frame;
	uint16_t sprite_palette;
	int16_t depth_offset;
	uint32_t handler;
};

struct group_leader_hold_record
{
	uint8_t leader;
	uint8_t direction;
	int16_t coordinate;
	uint16_t end_position;
	uint16_t which_flag;
};

struct tornado_start_record
{
	uint16_t x;
	uint16_t y;
	uint16_t hazard_list_offset;
	uint16_t whirlwind_list_offset;
};

struct tornado_path_step
{
	uint16_t position;
	int16_t coordinate;
	int16_t screen_threshold;
	int16_t catch_up_factor;
	int16_t base_speed;
	uint16_t wait;
	uint16_t direction;
};

struct default_ranking_record
{
	uint16_t rings;
	uint16_t character_and_stages;
	uint8_t first_letter;
	uint8_t second_letter;
	uint8_t third_letter;
	uint8_t letters_pad;
};

struct wall_kind_offsets
{
	int8_t hitbox_offset_x;
	int8_t hitbox_offset_y;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	uint8_t direction;
	uint8_t pad_05[0x1];
};

struct wall_kind_parts
{
	uint16_t size_x;
	uint16_t size_y;
	uint16_t palette;
	uint8_t part_step_x;
	uint8_t part_step_y;
	int16_t part_sprite;
	uint8_t second_offset_x;
	uint8_t second_offset_y;
	int16_t second_sprite;
};

struct timed_spawn
{
	int16_t time;
	uint16_t handler_offset;
};

struct crt_test_color_bar_row
{
	uint16_t x;
	uint16_t y;
	uint8_t first_color;
};

struct sound_command_bytes
{
	uint8_t group;
	uint8_t number;
};

struct chooser_voice_row
{
	uint8_t sounds[0x4];
};

struct map_icon_position
{
	uint16_t x;
	uint16_t y;
};

struct crt_test_line
{
	uint16_t start_x;
	uint16_t start_y;
	uint16_t end_x;
	uint16_t end_y;
};

struct screen_sign_kind
{
	uint16_t sprite_frame;
	uint16_t duration;
	uint16_t palette_list_offset;
};

struct ram_target_damage_step
{
	int8_t hits;
	uint8_t pad_01[0x1];
	uint16_t animation;
};

struct falling_rock
{
	uint16_t x;
	uint16_t y;
	uint16_t z;
	int16_t speed_x;
	int16_t speed_y;
	uint32_t animation;
};

struct line_direction_step
{
	int16_t row_step;
	int16_t column_step;
};

struct flood_fill_record
{
	uint16_t direction_and_y;
	uint16_t right_x;
	uint32_t right_address;
	uint16_t left_x;
	uint32_t left_address;
	uint16_t parent_right_x;
	uint32_t parent_right_address;
	uint16_t parent_left_x;
	uint32_t parent_left_address;
};

struct floor_block
{
	int32_t x_min;
	int32_t x_max;
	int32_t y_min;
	int32_t y_max;
	int16_t height;
	uint8_t type_index;
	uint8_t slope;
	uint8_t fall_priorities;
	uint8_t travel_direction;
};

struct bridge_load
{
	uint8_t count;
	uint8_t pad_01[0x4F];
};

struct stage_object_record
{
	uint16_t sprite_flags;
	uint16_t sprite_frame;
	uint16_t sprite_palette;
	uint32_t handler;
	uint32_t animation;
	uint16_t hitbox_size_x;
	uint16_t hitbox_size_y;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	int16_t depth_offset;
};

struct stage_object_record_2
{
	uint16_t sprite_flags;
	uint16_t sprite_frame;
	uint16_t sprite_palette;
	uint32_t handler;
	uint32_t animation;
	uint32_t odd_member_animation;
	uint16_t hitbox_size_x;
	uint16_t hitbox_size_y;
	int16_t depth_offset;
};

struct stage_object_template
{
	uint16_t sprite_flags;
	uint16_t sprite_frame;
	uint16_t sprite_palette;
	uint16_t hitbox_size_x;
	uint16_t hover_height;
	uint8_t animation_speed;
	int8_t animation_timer;
	uint8_t animation_frame;
	uint8_t kind;
	uint32_t animation;
	uint32_t handler;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	uint16_t hitbox_height;
};

struct sprite_part_list
{
	uint16_t count;
	uint16_t part_0_frame;
	uint8_t pad_04[0x6];
	uint16_t part_1_frame;
	uint8_t pad_0C[0x76];
};

struct sprite_part
{
	uint16_t frame;
	uint16_t flags;
	int8_t dx;
	int8_t dy;
	uint16_t palette;
};

struct frame_animation
{
	uint16_t last_frame;
	uint16_t frames[];
};

struct animation_step
{
	uint16_t frame;
	int8_t dx;
	int8_t dy;
};

struct sign_kind
{
	int16_t z;
	uint16_t sprite_frame;
	uint16_t duration;
	uint16_t palette_list_offset;
	uint32_t handler;
};

struct back_zone_record
{
	uint16_t limit;
	uint32_t handler;
};

struct metal_wall_part_offset
{
	int8_t dx;
	int8_t dy;
};

struct wall_spawn
{
	uint16_t position;
	uint16_t end_position;
	uint16_t x;
	uint16_t y;
	uint16_t z;
	uint16_t kind;
	uint8_t part_count;
	uint8_t depth_from_next;
};

struct object_pair_template
{
	uint32_t handler;
	uint32_t animation;
	int8_t sprite_offset_x;
	int8_t sprite_offset_y;
	uint8_t launch_kind;
	uint8_t pad_0B[0x1];
	uint16_t base_hitbox_size_x;
	uint16_t base_hitbox_size_y;
	int8_t base_hitbox_offset_x;
	int8_t base_hitbox_offset_y;
	uint32_t base_handler;
	uint32_t base_animation;
};

struct fireball_shot
{
	uint16_t position;
	int16_t x;
	int16_t dy;
	int16_t speed_y;
	int16_t speed_z;
	uint16_t type;
};

struct tornado_hazard
{
	uint16_t position;
	int16_t coordinate;
};

struct sinkhole_growth
{
	uint16_t zoom_step;
	uint16_t open_delay;
};

struct centipede_path_point
{
	int16_t projected_x;
	int16_t projected_y;
};

struct clip_entry
{
	uint16_t draw_next;
	uint16_t command;
	uint16_t bottom;
	uint16_t left;
	uint16_t right;
	uint16_t unk_0A;
	uint16_t unk_0C;
	uint16_t unk_0E;
	uint16_t unk_10;
};

struct grate_debris_piece
{
	int16_t dx;
	int16_t dy;
	int16_t speed_x;
	int16_t speed_z;
	uint16_t animation;
};

struct opening_scene_position
{
	int16_t screen_x;
	int16_t projected_y;
	uint16_t zoom;
};

struct leader_spawn
{
	uint8_t leader;
	int16_t x;
	int16_t y;
	int16_t z;
	uint16_t direction;
	uint16_t path;
};

struct ice_leader_spawn
{
	uint8_t leader;
	uint16_t end_position;
	int16_t reference_x;
	int16_t x;
	int16_t y;
	int16_t z;
};

struct credit_block
{
	union
	{
		uint32_t counts_long;
		uint8_t coins;
		uint16_t counts;
		struct
		{
			uint8_t pad_00[0x1];
			uint8_t credits;
			uint8_t bonus_coins;
			uint8_t changed;
		};
	};
};

struct trackball_motion
{
	int16_t x;
	int16_t y;
};

struct flagged_step
{
	uint16_t flags;
	uint16_t frame;
};

struct player_palette_list
{
	uint16_t last_index;
	uint16_t normal_palette;
	uint8_t pad_04[0x4];
};

struct edge_voice_scroll_range
{
	uint16_t start;
	uint16_t length;
};

struct screen_edge_push
{
	uint16_t limit_direction;
	uint16_t push_direction;
};

struct slope_speed_pair
{
	uint16_t speed_factor;
	uint16_t direction;
};

struct floor_type_player_state
{
	uint8_t state;
};

struct teeter_record
{
	uint16_t first_frame;
};

struct teeter_animation_offsets
{
	uint16_t offsets[0x2];
};

struct shocked_palette_row
{
	uint16_t palettes[0x8];
};

struct edge_hang_animations
{
	uint8_t pad_00[0x36];
	uint16_t hold_frame;
	uint16_t let_go_frame;
	uint16_t slip_piece_frame;
};

struct player_bounce_record
{
	uint16_t direction;
	uint16_t sprite_flags;
	uint16_t animation_offset;
};

struct knocked_out_entry
{
	uint16_t sprite_flags;
	uint16_t animation_offset;
};

struct restart_point
{
	uint16_t until;
	uint8_t kind;
	uint8_t screen_y;
	uint16_t x;
	uint16_t y_or_height;
};

struct stage_start_point
{
	uint16_t spacing_shift;
	uint16_t x;
	uint16_t y;
};

struct stage_goal
{
	uint16_t position;
	uint16_t direction;
	uint16_t line;
	uint8_t exit_path;
	uint8_t pad_07[0x5];
};

struct stage_goal_line_range
{
	uint16_t line_min;
	uint16_t line_max;
};

struct player_path_step
{
	int16_t speed;
	uint16_t x_or_wait;
	uint16_t y;
	uint16_t flags;
};

struct hud_portrait_sprite
{
	uint16_t frame;
	uint16_t palette;
};

struct hud_palette_cycle
{
	uint16_t last_index;
};

struct floor_slope
{
	uint8_t flags;
	uint8_t pad_01[0x1];
	int32_t factor;
	uint16_t direction_table;
};

struct sand_block_part_list
{
	uint16_t count;
	uint8_t pad_02[0x6];
	uint16_t first_palette;
};

struct flagged_animation_start
{
	uint16_t last_step;
	uint16_t first_flags;
	uint16_t first_frame;
	uint16_t second_flags;
};

struct debris_path_step
{
	int16_t end_time;
	int16_t screen_x;
	int16_t screen_y;
	uint16_t sprite_frame;
};

struct dust_cloud_frame
{
	int16_t screen_y;
	uint16_t sprite_frame;
};

struct credit_part
{
	uint16_t sprite_frame;
	int16_t screen_y;
	uint16_t sprite_palette;
	uint16_t slot;
};

struct screen_point
{
	int16_t x;
	int16_t y;
};

struct map_marker_layout
{
	uint16_t sprite_layer;
	int16_t screen_x;
	int16_t screen_y;
	uint16_t sprite_frame;
	uint16_t sprite_palette;
	uint16_t cleared_palette;
};

struct map_marker_blink
{
	uint16_t sprite_layer;
	int16_t screen_x;
	int16_t screen_y;
	uint16_t sprite_frame;
	uint16_t sprite_palette;
};

struct wipe_window
{
	int16_t left;
	int16_t top;
	uint16_t frames;
};

struct ranking_record
{
	union
	{
		uint32_t rings_long;
		int16_t rings;
		struct
		{
			uint8_t pad_00[0x2];
			union
			{
				uint16_t character_and_stages;
				uint8_t character;
				struct
				{
					uint8_t pad_02[0x1];
					uint8_t stages_reached;
				};
			};
		};
	};
	union
	{
		uint32_t initials;
		uint8_t first_initial;
		struct
		{
			uint8_t pad_04[0x1];
			uint8_t second_initial;
			uint8_t third_initial;
			uint8_t initials_pad;
		};
	};
};

struct ranking_row_number
{
	uint8_t tens_code;
	uint8_t units_code;
};

struct ring_tally_portrait
{
	uint16_t sprite_palette;
	uint16_t sprite_frame;
	uint16_t no_bonus_frame;
	uint16_t bonus_frame;
};

struct ring_tally_result_faces
{
	uint16_t no_bonus_frame;
	uint16_t bonus_frame;
};

struct geyser_rise_step
{
	uint16_t frames;
	uint16_t rise_speed;
};

struct palette_set_cycle
{
	uint32_t frames;
	uint32_t dest;
	uint8_t timer;
	uint8_t rows_left;
	uint8_t delay;
	uint8_t rows;
	int8_t frame;
	int8_t frame_count;
	uint8_t pad_0E[0x2];
};

struct palette_cycle
{
	uint8_t delay;
	int8_t frame_count;
	uint8_t pad_02[0x1];
	int8_t frame;
	int8_t timer;
};

struct coin_counter
{
	union
	{
		uint16_t pulse_timers;
		uint8_t on_frames;
		struct
		{
			uint8_t pad_00[0x1];
			uint8_t off_frames;
		};
	};
	uint8_t pending_coins;
	uint8_t chute_multiplier;
};

struct text_cell_position
{
	uint8_t column;
	uint8_t row;
};

struct polygon_span
{
	uint32_t address;
	int16_t length;
};

struct quad_vertex
{
	int16_t x;
	int16_t y;
};

struct picture_colour_slot
{
	uint8_t next;
	uint8_t previous;
	uint8_t colour;
};

struct saved_bitmap_rect
{
	uint32_t row_bits;
	uint32_t rows;
};

struct demo_header
{
	uint16_t stage_number;
	uint16_t start_section;
	uint8_t pad_04[0xC];
};

struct vblank_copy
{
	uint32_t source;
	uint32_t dest;
	uint16_t halfwords;
};

struct sprite_frame_record
{
	uint16_t width;
	uint16_t height;
	uint16_t bank_bits;
	uint16_t address;
};

struct string_record
{
	uint16_t x;
	uint16_t y;
	uint16_t palette;
	uint16_t scale;
};

struct queued_string
{
	int16_t x;
	int16_t y;
	uint16_t palette;
	uint16_t scale;
	uint32_t text;
};

struct placed_text
{
	uint16_t position;
	uint8_t string[];
};

struct tilemap_skip
{
	int8_t cells;
};

struct tilemap_long_skip
{
	int16_t cells;
};

struct vram_script_address
{
	uint16_t cell;
};

struct vram_script_cell_run
{
	uint8_t count;
	uint16_t cell;
};

struct vram_script_byte_cells
{
	uint8_t count;
	uint8_t high_byte;
};

struct vram_script_word_cells
{
	uint8_t count;
};

struct vram_script_page_clear
{
	uint16_t cell;
	uint8_t pages;
};

struct video_register_defaults_tail
{
	uint32_t text_backdrop_control;
	uint32_t bitmap_scroll;
	uint32_t bitmap_control;
};

struct palette_load_list
{
	uint16_t entry_count;
};

struct palette_list_entry
{
	uint32_t source;
	uint16_t palette_offset;
	uint16_t copy_mode;
};

struct palette_pens_1_15
{
	uint32_t pens_1_2;
	uint32_t pens_3_4;
	uint32_t pens_5_6;
	uint32_t pens_7_8;
	uint32_t pens_9_10;
	uint32_t pens_11_12;
	uint32_t pens_13_14;
	uint16_t pen_15;
};

struct palette_repeat_source
{
	uint32_t palettes;
};

struct chase_step_with_limit
{
	uint16_t position;
	int16_t limit;
	int16_t screen_threshold;
	int16_t catch_up_factor;
	int16_t base_speed;
	uint16_t wait;
};

struct biting_head_path_entry
{
	uint16_t position;
	int16_t limit;
	int16_t screen_threshold;
	int16_t catch_up_factor;
	int16_t base_speed;
	uint16_t wait;
	uint16_t direction;
};

struct bridge_fire_script_entry
{
	int16_t height;
	uint16_t position;
	int16_t screen_threshold;
	int16_t catch_up_factor;
	int16_t base_speed;
	uint16_t wait;
};

struct fire_front_path_start
{
	int16_t x;
	int16_t y;
	int16_t floor_z;
	uint16_t direction;
};

struct biting_head_path_start
{
	int16_t x;
	int16_t y;
};

struct rising_saw_path_start
{
	int16_t x;
	int16_t y;
	int16_t z;
};

struct brick_wall_brick
{
	uint16_t sprite_flags;
	uint16_t offset_x;
	uint16_t offset_y;
	uint16_t speed_x;
	uint16_t speed_y;
	uint16_t look;
};

struct brick_look
{
	uint16_t palette;
};

struct brick_dust_puff
{
	uint16_t sprite_flags;
	uint16_t offset_x;
	uint16_t offset_y;
	uint16_t delay;
};

struct biting_head_bite_step
{
	uint16_t jaw_frame;
	uint8_t hold;
	uint8_t pad_03[0x1];
};

struct grate_step_debris_list
{
	int16_t count;
};

struct burning_boulder_record
{
	int16_t x;
	int16_t start_delay;
	uint32_t path;
};

struct burning_boulder_flame_offset
{
	int16_t dx;
	int16_t dy;
	uint16_t animation;
};

struct falling_ember_speed
{
	int16_t speed_z;
	int16_t speed_y;
};

struct scene_carrier_record
{
	int16_t x;
	int16_t y;
	int16_t z;
	int32_t speed_x;
	int32_t speed_y;
	int32_t speed_z;
	uint16_t end_position;
};

struct lava_steam_puff_offset
{
	int16_t dx;
	int16_t dy;
};

struct group_slot_trigger_record
{
	uint16_t position;
	int16_t slot;
	uint16_t delay;
};

#pragma pack(pop)

typedef char static_assert_8651[(sizeof(struct object) == 0xA0) ? 1 : -1];
typedef char static_assert_8652[(sizeof(struct player) == 0x200) ? 1 : -1];
typedef char static_assert_8653[(sizeof(struct object_type_record) == 0x8) ? 1 : -1];
typedef char static_assert_8654[(sizeof(struct type_spawn_record) == 0xE) ? 1 : -1];
typedef char static_assert_8655[(sizeof(struct handler_spawn_record) == 0xC) ? 1 : -1];
typedef char static_assert_8656[(sizeof(struct object_start_list) == 0x2) ? 1 : -1];
typedef char static_assert_8657[(sizeof(struct machine_fireball_spawns) == 0x2) ? 1 : -1];
typedef char static_assert_8658[(sizeof(struct machine_fireball_spawn) == 0xE) ? 1 : -1];
typedef char static_assert_8659[(sizeof(struct ring_row) == 0xC) ? 1 : -1];
typedef char static_assert_8660[(sizeof(struct group_spawn_record) == 0x18) ? 1 : -1];
typedef char static_assert_8661[(sizeof(struct sprite_buffer_swap) == 0x4) ? 1 : -1];
typedef char static_assert_8662[(sizeof(struct sine_and_cosine) == 0x202) ? 1 : -1];
typedef char static_assert_8663[(sizeof(struct floor_attribute_record) == 0x10) ? 1 : -1];
typedef char static_assert_8664[(sizeof(struct floor_block_type) == 0x4) ? 1 : -1];
typedef char static_assert_8665[(sizeof(struct floor_outline_list) == 0x2) ? 1 : -1];
typedef char static_assert_8666[(sizeof(struct floor_outline) == 0x10) ? 1 : -1];
typedef char static_assert_8667[(sizeof(struct floor_outline_corner) == 0x4) ? 1 : -1];
typedef char static_assert_8668[(sizeof(struct stage_event) == 0x4) ? 1 : -1];
typedef char static_assert_8669[(sizeof(struct stage_link_point) == 0x4) ? 1 : -1];
typedef char static_assert_8670[(sizeof(struct layer_blend_list) == 0x1) ? 1 : -1];
typedef char static_assert_8671[(sizeof(struct layer_blend_record) == 0x6) ? 1 : -1];
typedef char static_assert_8672[(sizeof(struct restart_point_record) == 0x8) ? 1 : -1];
typedef char static_assert_8673[(sizeof(struct stage_palette) == 0x8) ? 1 : -1];
typedef char static_assert_8674[(sizeof(struct stage_name_banner) == 0x4) ? 1 : -1];
typedef char static_assert_8675[(sizeof(struct scroll_mode_step) == 0x4) ? 1 : -1];
typedef char static_assert_8676[(sizeof(struct event_0f_message) == 0xA) ? 1 : -1];
typedef char static_assert_8677[(sizeof(struct message_box_kind) == 0x8) ? 1 : -1];
typedef char static_assert_8678[(sizeof(struct stage_06_lightning_strike) == 0xA) ? 1 : -1];
typedef char static_assert_8679[(sizeof(struct event_1a_scroll_step) == 0x6) ? 1 : -1];
typedef char static_assert_8680[(sizeof(struct stage_03_floor_block_kind) == 0x4) ? 1 : -1];
typedef char static_assert_8681[(sizeof(struct stage_03_floor_block_shape) == 0x4) ? 1 : -1];
typedef char static_assert_8682[(sizeof(struct stage_03_floor_block_animation) == 0x8) ? 1 : -1];
typedef char static_assert_8683[(sizeof(struct rock_debris_piece) == 0xC) ? 1 : -1];
typedef char static_assert_8684[(sizeof(struct spiked_roller_kind) == 0x7) ? 1 : -1];
typedef char static_assert_8685[(sizeof(struct spiked_roller_chase_step) == 0xA) ? 1 : -1];
typedef char static_assert_8686[(sizeof(struct spiked_roller_layout) == 0x10) ? 1 : -1];
typedef char static_assert_8687[(sizeof(struct spiked_roller_part) == 0xE) ? 1 : -1];
typedef char static_assert_8688[(sizeof(struct spiked_roller_event) == 0x8) ? 1 : -1];
typedef char static_assert_8689[(sizeof(struct door_roller_spawn) == 0x6) ? 1 : -1];
typedef char static_assert_8690[(sizeof(struct door_fragment) == 0xA) ? 1 : -1];
typedef char static_assert_8691[(sizeof(struct fireball_emitter_list) == 0x6) ? 1 : -1];
typedef char static_assert_8692[(sizeof(struct fireball_type) == 0x10) ? 1 : -1];
typedef char static_assert_8693[(sizeof(struct machine_fire_script_step) == 0xA) ? 1 : -1];
typedef char static_assert_8694[(sizeof(struct cage_bar_animation) == 0x8) ? 1 : -1];
typedef char static_assert_8695[(sizeof(struct fire_vent_spawn) == 0xA) ? 1 : -1];
typedef char static_assert_8696[(sizeof(struct icicle_dropper_record) == 0xC) ? 1 : -1];
typedef char static_assert_8697[(sizeof(struct icicle_dropper_step) == 0xC) ? 1 : -1];
typedef char static_assert_8698[(sizeof(struct sink_swirl_effect) == 0xA) ? 1 : -1];
typedef char static_assert_8699[(sizeof(struct object_start_place) == 0x8) ? 1 : -1];
typedef char static_assert_8700[(sizeof(struct river_raft_entry) == 0x8) ? 1 : -1];
typedef char static_assert_8701[(sizeof(struct geyser_front_record) == 0x6) ? 1 : -1];
typedef char static_assert_8702[(sizeof(struct chase_step_at_scroll) == 0xA) ? 1 : -1];
typedef char static_assert_8703[(sizeof(struct listed_geyser) == 0xA) ? 1 : -1];
typedef char static_assert_8704[(sizeof(struct stone_block_position) == 0x8) ? 1 : -1];
typedef char static_assert_8705[(sizeof(struct geyser_line_start) == 0x8) ? 1 : -1];
typedef char static_assert_8706[(sizeof(struct geyser_line_step) == 0x8) ? 1 : -1];
typedef char static_assert_8707[(sizeof(struct propeller_machine_animation_step) == 0x4) ? 1 : -1];
typedef char static_assert_8708[(sizeof(struct rope_bridge_rope_offset) == 0x4) ? 1 : -1];
typedef char static_assert_8709[(sizeof(struct spike_panel_screen_offset) == 0x4) ? 1 : -1];
typedef char static_assert_8710[(sizeof(struct spike_panel_part_offset) == 0x6) ? 1 : -1];
typedef char static_assert_8711[(sizeof(struct flame_machine_offset) == 0x4) ? 1 : -1];
typedef char static_assert_8712[(sizeof(struct flame_machine_arm_sway) == 0x2) ? 1 : -1];
typedef char static_assert_8713[(sizeof(struct spiked_disc_hold_offset) == 0x4) ? 1 : -1];
typedef char static_assert_8714[(sizeof(struct hitbox_size_pair) == 0x4) ? 1 : -1];
typedef char static_assert_8715[(sizeof(struct hitbox_offset_pair) == 0x2) ? 1 : -1];
typedef char static_assert_8716[(sizeof(struct crawler_walk_row) == 0x6) ? 1 : -1];
typedef char static_assert_8717[(sizeof(struct hitbox_size_and_offset) == 0x6) ? 1 : -1];
typedef char static_assert_8718[(sizeof(struct crawler_piece_offset) == 0x4) ? 1 : -1];
typedef char static_assert_8719[(sizeof(struct fence_offset) == 0x4) ? 1 : -1];
typedef char static_assert_8720[(sizeof(struct fence_post_box) == 0x4) ? 1 : -1];
typedef char static_assert_8721[(sizeof(struct fence_post_box_offset) == 0x2) ? 1 : -1];
typedef char static_assert_8722[(sizeof(struct sprite_palette_cycle) == 0x2) ? 1 : -1];
typedef char static_assert_8723[(sizeof(struct hud_step_list) == 0x2) ? 1 : -1];
typedef char static_assert_8724[(sizeof(struct eggman_speech_step) == 0x4) ? 1 : -1];
typedef char static_assert_8725[(sizeof(struct how_to_play_button_press) == 0x4) ? 1 : -1];
typedef char static_assert_8726[(sizeof(struct coin_setting_value) == 0x4) ? 1 : -1];
typedef char static_assert_8727[(sizeof(struct ending_tower_frame) == 0x6) ? 1 : -1];
typedef char static_assert_8728[(sizeof(struct ending_explosion_frame) == 0x4) ? 1 : -1];
typedef char static_assert_8729[(sizeof(struct ending_music_cue) == 0x4) ? 1 : -1];
typedef char static_assert_8730[(sizeof(struct ending_timed_frame) == 0x4) ? 1 : -1];
typedef char static_assert_8731[(sizeof(struct ending_timed_palette) == 0x4) ? 1 : -1];
typedef char static_assert_8732[(sizeof(struct scenery_kind_record) == 0xC) ? 1 : -1];
typedef char static_assert_8733[(sizeof(struct group_leader_hold_record) == 0x8) ? 1 : -1];
typedef char static_assert_8734[(sizeof(struct tornado_start_record) == 0x8) ? 1 : -1];
typedef char static_assert_8735[(sizeof(struct tornado_path_step) == 0xE) ? 1 : -1];
typedef char static_assert_8736[(sizeof(struct default_ranking_record) == 0x8) ? 1 : -1];
typedef char static_assert_8737[(sizeof(struct wall_kind_offsets) == 0x6) ? 1 : -1];
typedef char static_assert_8738[(sizeof(struct wall_kind_parts) == 0xE) ? 1 : -1];
typedef char static_assert_8739[(sizeof(struct timed_spawn) == 0x4) ? 1 : -1];
typedef char static_assert_8740[(sizeof(struct crt_test_color_bar_row) == 0x5) ? 1 : -1];
typedef char static_assert_8741[(sizeof(struct sound_command_bytes) == 0x2) ? 1 : -1];
typedef char static_assert_8742[(sizeof(struct chooser_voice_row) == 0x4) ? 1 : -1];
typedef char static_assert_8743[(sizeof(struct map_icon_position) == 0x4) ? 1 : -1];
typedef char static_assert_8744[(sizeof(struct crt_test_line) == 0x8) ? 1 : -1];
typedef char static_assert_8745[(sizeof(struct screen_sign_kind) == 0x6) ? 1 : -1];
typedef char static_assert_8746[(sizeof(struct ram_target_damage_step) == 0x4) ? 1 : -1];
typedef char static_assert_8747[(sizeof(struct falling_rock) == 0xE) ? 1 : -1];
typedef char static_assert_8748[(sizeof(struct line_direction_step) == 0x4) ? 1 : -1];
typedef char static_assert_8749[(sizeof(struct flood_fill_record) == 0x1A) ? 1 : -1];
typedef char static_assert_8750[(sizeof(struct floor_block) == 0x16) ? 1 : -1];
typedef char static_assert_8751[(sizeof(struct bridge_load) == 0x50) ? 1 : -1];
typedef char static_assert_8752[(sizeof(struct stage_object_record) == 0x16) ? 1 : -1];
typedef char static_assert_8753[(sizeof(struct stage_object_record_2) == 0x18) ? 1 : -1];
typedef char static_assert_8754[(sizeof(struct stage_object_template) == 0x1A) ? 1 : -1];
typedef char static_assert_8755[(sizeof(struct sprite_part_list) == 0x82) ? 1 : -1];
typedef char static_assert_8756[(sizeof(struct sprite_part) == 0x8) ? 1 : -1];
typedef char static_assert_8757[(sizeof(struct frame_animation) == 0x2) ? 1 : -1];
typedef char static_assert_8758[(sizeof(struct animation_step) == 0x4) ? 1 : -1];
typedef char static_assert_8759[(sizeof(struct sign_kind) == 0xC) ? 1 : -1];
typedef char static_assert_8760[(sizeof(struct back_zone_record) == 0x6) ? 1 : -1];
typedef char static_assert_8761[(sizeof(struct metal_wall_part_offset) == 0x2) ? 1 : -1];
typedef char static_assert_8762[(sizeof(struct wall_spawn) == 0xE) ? 1 : -1];
typedef char static_assert_8763[(sizeof(struct object_pair_template) == 0x1A) ? 1 : -1];
typedef char static_assert_8764[(sizeof(struct fireball_shot) == 0xC) ? 1 : -1];
typedef char static_assert_8765[(sizeof(struct tornado_hazard) == 0x4) ? 1 : -1];
typedef char static_assert_8766[(sizeof(struct sinkhole_growth) == 0x4) ? 1 : -1];
typedef char static_assert_8767[(sizeof(struct centipede_path_point) == 0x4) ? 1 : -1];
typedef char static_assert_8768[(sizeof(struct clip_entry) == 0x12) ? 1 : -1];
typedef char static_assert_8769[(sizeof(struct grate_debris_piece) == 0xA) ? 1 : -1];
typedef char static_assert_8770[(sizeof(struct opening_scene_position) == 0x6) ? 1 : -1];
typedef char static_assert_8771[(sizeof(struct leader_spawn) == 0xB) ? 1 : -1];
typedef char static_assert_8772[(sizeof(struct ice_leader_spawn) == 0xB) ? 1 : -1];
typedef char static_assert_8773[(sizeof(struct credit_block) == 0x4) ? 1 : -1];
typedef char static_assert_8774[(sizeof(struct trackball_motion) == 0x4) ? 1 : -1];
typedef char static_assert_8775[(sizeof(struct flagged_step) == 0x4) ? 1 : -1];
typedef char static_assert_8776[(sizeof(struct player_palette_list) == 0x8) ? 1 : -1];
typedef char static_assert_8777[(sizeof(struct edge_voice_scroll_range) == 0x4) ? 1 : -1];
typedef char static_assert_8778[(sizeof(struct screen_edge_push) == 0x4) ? 1 : -1];
typedef char static_assert_8779[(sizeof(struct slope_speed_pair) == 0x4) ? 1 : -1];
typedef char static_assert_8780[(sizeof(struct floor_type_player_state) == 0x1) ? 1 : -1];
typedef char static_assert_8781[(sizeof(struct teeter_record) == 0x2) ? 1 : -1];
typedef char static_assert_8782[(sizeof(struct teeter_animation_offsets) == 0x4) ? 1 : -1];
typedef char static_assert_8783[(sizeof(struct shocked_palette_row) == 0x10) ? 1 : -1];
typedef char static_assert_8784[(sizeof(struct edge_hang_animations) == 0x3C) ? 1 : -1];
typedef char static_assert_8785[(sizeof(struct player_bounce_record) == 0x6) ? 1 : -1];
typedef char static_assert_8786[(sizeof(struct knocked_out_entry) == 0x4) ? 1 : -1];
typedef char static_assert_8787[(sizeof(struct restart_point) == 0x8) ? 1 : -1];
typedef char static_assert_8788[(sizeof(struct stage_start_point) == 0x6) ? 1 : -1];
typedef char static_assert_8789[(sizeof(struct stage_goal) == 0xC) ? 1 : -1];
typedef char static_assert_8790[(sizeof(struct stage_goal_line_range) == 0x4) ? 1 : -1];
typedef char static_assert_8791[(sizeof(struct player_path_step) == 0x8) ? 1 : -1];
typedef char static_assert_8792[(sizeof(struct hud_portrait_sprite) == 0x4) ? 1 : -1];
typedef char static_assert_8793[(sizeof(struct hud_palette_cycle) == 0x2) ? 1 : -1];
typedef char static_assert_8794[(sizeof(struct floor_slope) == 0x8) ? 1 : -1];
typedef char static_assert_8795[(sizeof(struct sand_block_part_list) == 0xA) ? 1 : -1];
typedef char static_assert_8796[(sizeof(struct flagged_animation_start) == 0x8) ? 1 : -1];
typedef char static_assert_8797[(sizeof(struct debris_path_step) == 0x8) ? 1 : -1];
typedef char static_assert_8798[(sizeof(struct dust_cloud_frame) == 0x4) ? 1 : -1];
typedef char static_assert_8799[(sizeof(struct credit_part) == 0x8) ? 1 : -1];
typedef char static_assert_8800[(sizeof(struct screen_point) == 0x4) ? 1 : -1];
typedef char static_assert_8801[(sizeof(struct map_marker_layout) == 0xC) ? 1 : -1];
typedef char static_assert_8802[(sizeof(struct map_marker_blink) == 0xA) ? 1 : -1];
typedef char static_assert_8803[(sizeof(struct wipe_window) == 0x6) ? 1 : -1];
typedef char static_assert_8804[(sizeof(struct ranking_record) == 0x8) ? 1 : -1];
typedef char static_assert_8805[(sizeof(struct ranking_row_number) == 0x2) ? 1 : -1];
typedef char static_assert_8806[(sizeof(struct ring_tally_portrait) == 0x8) ? 1 : -1];
typedef char static_assert_8807[(sizeof(struct ring_tally_result_faces) == 0x4) ? 1 : -1];
typedef char static_assert_8808[(sizeof(struct geyser_rise_step) == 0x4) ? 1 : -1];
typedef char static_assert_8809[(sizeof(struct palette_set_cycle) == 0x10) ? 1 : -1];
typedef char static_assert_8810[(sizeof(struct palette_cycle) == 0x5) ? 1 : -1];
typedef char static_assert_8811[(sizeof(struct coin_counter) == 0x4) ? 1 : -1];
typedef char static_assert_8812[(sizeof(struct text_cell_position) == 0x2) ? 1 : -1];
typedef char static_assert_8813[(sizeof(struct polygon_span) == 0x6) ? 1 : -1];
typedef char static_assert_8814[(sizeof(struct quad_vertex) == 0x4) ? 1 : -1];
typedef char static_assert_8815[(sizeof(struct picture_colour_slot) == 0x3) ? 1 : -1];
typedef char static_assert_8816[(sizeof(struct saved_bitmap_rect) == 0x8) ? 1 : -1];
typedef char static_assert_8817[(sizeof(struct demo_header) == 0x10) ? 1 : -1];
typedef char static_assert_8818[(sizeof(struct vblank_copy) == 0xA) ? 1 : -1];
typedef char static_assert_8819[(sizeof(struct sprite_frame_record) == 0x8) ? 1 : -1];
typedef char static_assert_8820[(sizeof(struct string_record) == 0x8) ? 1 : -1];
typedef char static_assert_8821[(sizeof(struct queued_string) == 0xC) ? 1 : -1];
typedef char static_assert_8822[(sizeof(struct placed_text) == 0x2) ? 1 : -1];
typedef char static_assert_8823[(sizeof(struct tilemap_skip) == 0x1) ? 1 : -1];
typedef char static_assert_8824[(sizeof(struct tilemap_long_skip) == 0x2) ? 1 : -1];
typedef char static_assert_8825[(sizeof(struct vram_script_address) == 0x2) ? 1 : -1];
typedef char static_assert_8826[(sizeof(struct vram_script_cell_run) == 0x3) ? 1 : -1];
typedef char static_assert_8827[(sizeof(struct vram_script_byte_cells) == 0x2) ? 1 : -1];
typedef char static_assert_8828[(sizeof(struct vram_script_word_cells) == 0x1) ? 1 : -1];
typedef char static_assert_8829[(sizeof(struct vram_script_page_clear) == 0x3) ? 1 : -1];
typedef char static_assert_8830[(sizeof(struct video_register_defaults_tail) == 0xC) ? 1 : -1];
typedef char static_assert_8831[(sizeof(struct palette_load_list) == 0x2) ? 1 : -1];
typedef char static_assert_8832[(sizeof(struct palette_list_entry) == 0x8) ? 1 : -1];
typedef char static_assert_8833[(sizeof(struct palette_pens_1_15) == 0x1E) ? 1 : -1];
typedef char static_assert_8834[(sizeof(struct palette_repeat_source) == 0x4) ? 1 : -1];
typedef char static_assert_8835[(sizeof(struct chase_step_with_limit) == 0xC) ? 1 : -1];
typedef char static_assert_8836[(sizeof(struct biting_head_path_entry) == 0xE) ? 1 : -1];
typedef char static_assert_8837[(sizeof(struct bridge_fire_script_entry) == 0xC) ? 1 : -1];
typedef char static_assert_8838[(sizeof(struct fire_front_path_start) == 0x8) ? 1 : -1];
typedef char static_assert_8839[(sizeof(struct biting_head_path_start) == 0x4) ? 1 : -1];
typedef char static_assert_8840[(sizeof(struct rising_saw_path_start) == 0x6) ? 1 : -1];
typedef char static_assert_8841[(sizeof(struct brick_wall_brick) == 0xC) ? 1 : -1];
typedef char static_assert_8842[(sizeof(struct brick_look) == 0x2) ? 1 : -1];
typedef char static_assert_8843[(sizeof(struct brick_dust_puff) == 0x8) ? 1 : -1];
typedef char static_assert_8844[(sizeof(struct biting_head_bite_step) == 0x4) ? 1 : -1];
typedef char static_assert_8845[(sizeof(struct grate_step_debris_list) == 0x2) ? 1 : -1];
typedef char static_assert_8846[(sizeof(struct burning_boulder_record) == 0x8) ? 1 : -1];
typedef char static_assert_8847[(sizeof(struct burning_boulder_flame_offset) == 0x6) ? 1 : -1];
typedef char static_assert_8848[(sizeof(struct falling_ember_speed) == 0x4) ? 1 : -1];
typedef char static_assert_8849[(sizeof(struct scene_carrier_record) == 0x14) ? 1 : -1];
typedef char static_assert_8850[(sizeof(struct lava_steam_puff_offset) == 0x4) ? 1 : -1];
typedef char static_assert_8851[(sizeof(struct group_slot_trigger_record) == 0x6) ? 1 : -1];

# 9113 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

/* the program ROM's tables of records, by name: name[i].field */
# 9211 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\ram.h"

# 17 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\game.h"

/* registers the whole program shares */
extern uint32_t r14, current_player, current_object, free_objects, first_object, object_cursor, last_object, fill_value, stack_pointer;

/* where the code the program keeps in memory slots (objects' handlers, hooks) is, as the game's own
   addresses: what it stores and compares, and what call_code() runs */
# 594 "C:\\segasonic-port-main\\segasonic\\segasonic\\..\\..\\src\\game.h"

/* engine/contacts.c: contacts between objects and players: the zones, the hitter, touchable, rider, platform and wall lists, and the checks that pair them */
uint32_t check_zones(uint32_t box_edge);
uint32_t add_to_zone_list(uint32_t old_head);
void check_hits(uint32_t *p_box_edge, uint32_t *p_distance, uint32_t *p_dy, uint32_t *p_edge_or_centre_y, uint32_t *p_radius, uint32_t *p_centre_offset, uint32_t *p_previous);
void check_hit(uint32_t other, uint32_t hitter, uint32_t *p_box_edge, uint32_t *p_distance, uint32_t *p_dy, uint32_t *p_edge_or_centre_y, uint32_t *p_radius, uint32_t *p_centre_offset, uint32_t *p_previous);
void add_to_hitter_list(void);
uint32_t add_to_touchable_list(uint32_t old_head);
void add_to_rider_list(void);
void add_to_platform_list(void);
void check_platforms(uint32_t *p_middle, uint32_t *p_plank, uint32_t *p_span, uint32_t *p_sag, uint32_t *p_sag_step, uint32_t *p_load_count, uint32_t *p_passes_left, uint32_t *p_platform, uint32_t *p_load_list);
void compute_bridge_sag(uint32_t load_list, uint16_t plank_count, uint32_t *p_middle, uint32_t *p_plank, uint32_t *p_span, uint32_t *p_sag, uint32_t *p_sag_step, uint32_t *p_count, uint32_t *p_passes_left, uint32_t *p_load_entry, uint32_t *p_sag_curve);
void add_to_wall_list(void);
uint32_t check_walls(uint32_t hitbox_offset);

/* engine/geometry.c: between the map and the screen: projecting objects, the floor under a point, unprojecting a screen point; square roots, angles and BCD */
void side_of_box(uint32_t other, uint32_t *p_hitbox_offset_y, uint32_t *p_sides);
uint32_t set_speed_from_direction(void);
void polar_to_xy(uint32_t *p_cos_part, uint32_t *p_angle, uint32_t *p_length);
uint32_t set_speed_from_player_speed(void);
void project_object(uint32_t *p_screen_y, uint32_t *p_depth);
void update_screen_position(uint32_t *p_screen_y, uint32_t *p_depth);
void project_point(uint32_t z, uint32_t *p_projected_y, uint32_t *p_point_x, uint32_t *p_point_y);
void point_to_screen(uint16_t projected_x, uint32_t z, uint32_t *p_projected_y, uint32_t *p_screen_x, uint32_t *p_screen_y);
uint32_t project_object_2(void);
void find_nearby_floor_blocks(uint32_t *p_corner_y, uint32_t *p_floor_block, uint32_t *p_bounds_offset, uint32_t *p_nearby_count, uint32_t *p_corners_left, uint32_t *p_left, uint32_t *p_right);
void find_floor(uint32_t *p_x, uint32_t *p_y, uint32_t *p_block_offset, uint32_t *p_slope_height, uint32_t *p_cursor);
void find_floor_no_block(uint32_t *p_x, uint32_t *p_slope_height, uint32_t *p_cursor);
void find_floor_set_floor_z(uint32_t block, uint32_t *p_x, uint32_t *p_slope_height, uint32_t *p_cursor);
void get_floor_z_at_point(uint32_t x, uint32_t y, uint32_t *p_floor_z, uint32_t *p_block);
uint32_t find_floor_block_at_point(uint32_t x, uint32_t y);
void screen_point_to_ground(uint32_t z, uint32_t *p_point_x, uint32_t *p_point_y);
void unproject_point(uint32_t *p_point_x, uint32_t *p_point_y);
void square_root(uint32_t *p_value, uint32_t *p_steps_left);
void angle_of_vector(uint32_t dy, uint32_t *p_dx, uint32_t *p_octant);
uint32_t convert_from_bcd(uint32_t value);
void convert_to_bcd(uint32_t *p_value, uint32_t *p_digit);
void convert_64_to_bcd(uint32_t *p_number_low, uint32_t *p_number_high, uint32_t *p_bcd_high);

/* engine/objects.c: the object system: the object list and its two pools, allocating, linking and deleting objects, spawning them from the stage lists (by type, by handler, in groups led by a leader), and what the stage objects share */
void move_object_to_next_stage_slot(void);
void next_random(uint32_t *p_random_value, uint32_t *p_words_left, uint32_t *p_random_offset);
void create_child_shadow_unscaled(uint32_t shadow);
void create_child_shadow_9ffe(uint16_t scale, uint32_t shadow);
void create_child_shadow(uint16_t scale, uint32_t shadow);
void draw_child_shadow(void);
uint32_t is_floor_block_off_screen(void);
uint32_t is_off_screen(void);
uint32_t is_off_screen_margin(uint16_t margin_x, uint16_t margin_y);
uint32_t check_left_screen(void);
uint32_t check_left_screen_margin(uint16_t margin);
uint32_t check_left_screen_margins(uint16_t margin, uint16_t unseen_margin);
void allocate_object_outside_loop(uint32_t *p_free_count, uint32_t *p_object);
void delete_object_outside_loop(uint32_t object, uint32_t *p_free_count, uint32_t *p_previous);
void spawn_objects_by_handler(uint32_t *p_list_offset, uint32_t *p_record, uint32_t *p_object);
void reset_linked_objects_flag(void);
void start_spawns_by_type(void);
void spawn_objects_by_type(uint32_t *p_player_object, uint32_t *p_player_index, uint32_t *p_first, uint32_t *p_projected_x, uint32_t *p_projected_y, uint32_t *p_object_type, uint32_t *p_object);
void count_active_players(uint32_t *p_player_object, uint32_t *p_player_index);
void spawn_object_with_pieces(uint32_t return_address, uint32_t *p_spawned, uint32_t *p_piece_count, uint32_t *p_free_count, uint32_t *p_first, uint32_t *p_block);
void add_pieces_to_current_object(uint32_t *p_spawned, uint32_t *p_free_count, uint32_t *p_first, uint32_t *p_block);
void add_object_pieces(uint32_t *p_spawned, uint32_t *p_piece_count, uint32_t *p_free_count, uint32_t *p_first, uint32_t *p_block);
void spawn_objects(uint32_t return_address, uint32_t *p_spawned, uint32_t *p_first, uint32_t *p_block);
void unlink_child_chain(uint32_t object);
void init_object(uint32_t object);
void init_object_2(uint32_t object);
void init_object_fields(uint32_t object, uint8_t mode);
void clear_object_speeds(void);
void init_object_fields_tail(uint32_t object, uint8_t mode);
void move_object_projected(uint32_t *p_screen_y, uint32_t *p_block_offset, uint32_t *p_slope_height, uint32_t *p_cursor);
void unproject_object(uint32_t *p_screen_y, uint32_t *p_block_offset, uint32_t *p_slope_height, uint32_t *p_cursor);
uint32_t update_screen_position_no_offset(void);
void move_object_projected_no_floor(void);
uint32_t is_on_screen(void);
void delete_if_off_screen(uint32_t *p_deleted, uint32_t *p_block_offset, uint32_t *p_slope_height);
void delete_object_and_children(uint32_t *p_deleted, uint32_t *p_block_offset, uint32_t *p_slope_height);
void copy_position_to(uint32_t object);
void place_sprite_near_cursor(uint16_t offset_x, uint16_t offset_y);
void copy_position_to_cursor(void);
void copy_position_from_cursor(void);
void copy_screen_position_from_cursor(void);
uint32_t face_nearest_player(uint32_t direction, uint32_t octant);
void find_nearest_player_x(void);
uint32_t face_object(void);
uint32_t distance_to_object(void);
uint32_t direction_to_object(void);
void distance_xy_to_object(uint32_t *p_distance_x, uint32_t *p_distance_y);
void fall_to_floor(uint32_t *p_height, uint32_t *p_over_pit, uint32_t *p_z);
uint32_t place_sprite_at_cursor_floor(void);
void direction_to_speed(uint32_t speed, uint32_t *p_direction, uint32_t *p_speed_x, uint32_t *p_speed_y);
uint32_t cursor_floor_screen_y(uint32_t floor_screen_y);
void explode_object_medium(void);
void explode_object(void);
void explosion_animate(void);
void drop_rings(uint32_t shadow, uint32_t *p_allocated, uint32_t *p_random_value, uint32_t *p_ring);
void released_ring_wait(void);
void released_ring_start(void);
void released_ring_bounce(void);
void released_ring_move(uint32_t cursor);
void spawn_debris(uint32_t spawned, uint16_t count, uint32_t block);
void debris_fly(void);
void spawn_object_groups(uint32_t *p_list_offset, uint32_t *p_free_stack, uint32_t *p_slope_z, uint32_t *p_count, uint32_t *p_object);
void spawn_object_groups_mark_silent(uint32_t record, uint32_t *p_list_offset, uint32_t *p_slope_z, uint32_t *p_count, uint32_t *p_object);
void spawn_object_groups_no_depth_step(uint32_t record, uint32_t *p_list_offset, uint32_t *p_slope_z, uint32_t *p_count, uint32_t *p_object);
void spawn_object_groups_build_group(uint32_t record, uint32_t *p_list_offset, uint32_t *p_slope_z, uint32_t *p_count, uint32_t *p_object);
void crumbling_floor_update(void);
void crumbling_floor_crack(void);
void crumbling_floor_play_crack_steps(void);
void crumbling_floor_start_falling(void);
void crumbling_floor_draw(void);
void spawn_group_leader(uint32_t record, uint32_t *p_spawned, uint32_t *p_leader);
void group_leader_wait(void);
void group_leader_move(void);
void group_leader_read_script(void);
void group_leader_move_step(void);
void spawn_object_groups_2(uint32_t *p_list_offset, uint32_t *p_count, uint32_t *p_object);
void spawn_object_groups_2_pick_bridge(uint32_t record, uint32_t *p_list_offset, uint32_t *p_count, uint32_t *p_object);
void spawn_object_groups_2_build_group(uint32_t record, uint32_t plank_count_var, uint32_t *p_list_offset, uint32_t *p_count, uint32_t *p_object);
void reset_objects(uint32_t *p_block, uint32_t *p_stack_slot);
void reset_objects_alt(void);
void run_objects(void);
void reset_object_list(void);
void take_free_object(uint32_t *p_free_count, uint32_t *p_object);
uint32_t allocate_object_or_start_list(uint32_t object);
void allocate_object(uint32_t *p_free_count, uint32_t *p_object);
void link_object(uint32_t object);
void allocate_object_after_current(void);
void delete_current_object(void);
void push_free_object(void);
void delete_next_object(void);
void delete_object(uint32_t object, uint32_t *p_free_count, uint32_t *p_previous);
void reset_object_pool_2(uint32_t *p_block, uint32_t *p_stack_slot);
void reset_object_pool_2_alt(void);
void allocate_object_2(uint32_t *p_free_count, uint32_t *p_free_stack, uint32_t *p_object);
uint32_t free_object_2(uint16_t object);

/* engine/sprites.c: animation and the sprite list: animation steps (frames, flips, moves, offsets, multi-part sprites), part palette cycles, the depth buckets, build_sprite_list and the buffer swap at VBLANK */
void cycle_part_palettes(void);
void animate_with_flags(uint32_t *p_frame, uint32_t *p_at_last_step);
void animate_step_with_flags(uint32_t *p_frame, uint32_t *p_at_last_step);
void animate(uint32_t *p_frame, uint32_t *p_wrapped, uint32_t *p_at_last_step);
void animate_step(uint32_t *p_frame, uint32_t *p_wrapped, uint32_t *p_at_last_step);
uint32_t animate_and_move(uint32_t at_last_step);
uint32_t animate_around_anchor(void);
void set_step_around_anchor(uint32_t frame, uint32_t steps);
uint32_t animate_with_screen_offset(uint32_t at_last_step);
void apply_step_screen_offset(void);
void add_step_screen_offset(uint32_t step_offset);
void animate_part_list(void);
void animate_part_list_step(void);
void animate_all_parts(uint32_t *p_at_last_step, uint32_t *p_part);
void init_sprites_without_swaps(void);
void init_sprites_swapping_every_frame(void);
void init_sprites(uint32_t *p_end_mark, uint32_t *p_source);
void init_sprites_from_frame_wait(uint32_t *p_end_mark, uint32_t *p_source);
void init_sprite_hardware(uint32_t *p_end_mark, uint32_t *p_source);
uint32_t clear_sprite_buckets(void);
uint32_t queue_sprite(uint32_t depth);
void queue_sprite_at_depth(uint32_t *p_bucket_head, uint32_t *p_depth);
void queue_sprite_in_layer(void);
void queue_sprite_on_top(void);
void queue_sprite_in_bucket(uint32_t bucket);
uint32_t queue_sprite_at_floor(void);
uint32_t queue_sprite_at_previous_floor(void);
uint32_t queue_sprite_at_base(uint32_t depth);
uint32_t depth_to_bucket(uint32_t bucket, uint16_t depth);
void queue_sprite_at_depth_offset(uint16_t depth, uint8_t bucket_offset);
void queue_sprite_at_previous_floor_2(void);
void get_previous_floor_bucket(uint32_t top_bucket, uint32_t *p_floor_depth, uint32_t *p_bucket);
void swap_sprite_buffers(void);
void swap_sprite_buffers_now(void);
void cancel_sprite_buffer_swap(void);
void load_sized_frame_address_at_row(uint16_t row);
void load_sized_frame_address(void);
void load_frame_size(void);
void build_sprite_list(uint32_t *p_height, uint32_t *p_scale_x, uint32_t *p_scale_y, uint32_t *p_sprite_flags, uint32_t *p_sprite_entry);

/* objects/eggman.c: Eggman: his booth that slides in during his speeches, the speech scripts (stages 3, 8, A), his scene with the button box in stage B and the sliding door, his teleport (never spawned) */
void spawn_eggman_booth(uint32_t spawned, uint32_t piece_count, uint32_t booth, uint32_t *p_free_count, uint32_t *p_block);
void eggman_booth_slide_in(void);
void eggman_booth_animate(void);
void draw_eggman_booth(void);
void spawn_eggman_teleport(uint32_t free_count, uint32_t teleport, uint32_t block);
void eggman_teleport_init(void);
void eggman_teleport_animate(void);
void eggman_scene_init(void);
void eggman_scene_wait(void);
void eggman_scene_pause(void);
void eggman_scene_talk(void);
void eggman_scene_press_button(void);
void eggman_scene_run_off(void);
void eggman_scene_move(void);
void button_box_init(void);
void button_box_wait(void);
void button_box_rise(void);
void button_box_press(void);
void draw_button_box(void);
void sliding_door_init(void);
void sliding_door_wait(void);
void sliding_door_open(void);
void sliding_door_draw(void);
void eggman_speech_start(void);
void eggman_speech_run(void);

/* objects/intro.c: the scenes that start a game: stage 6's opening (the rushing ground, the giant machine head) and stage 7's how to play (the panel, the hands on the button and the trackball, the metal wall that rises and breaks) */
void metal_wall_init(void);
void metal_wall_wait(void);
void metal_wall_rise(uint32_t octant);
void metal_wall_update(uint32_t octant);
void metal_wall_broken(void);
void metal_wall_draw(void);
void how_to_play_button_hand_start(void);
void how_to_play_button_hand_update(void);
void how_to_play_trackball_hand_start(void);
void how_to_play_trackball_hand_update(void);
void how_to_play_panel_start(void);
void how_to_play_panel_show(void);
void opening_ground_start(void);
void opening_ground_run(void);
void opening_machine_start(void);
void opening_machine_update(void);
void opening_machine_leap_in(void);
void opening_machine_approach(void);
void opening_machine_lunge(void);
void opening_machine_show_mouth(void);
void opening_machine_engulf(void);
void opening_machine_hold(void);
void draw_opening_machine_shadow(void);
void draw_opening_machine_shadow_spare_return(void);

/* objects/rings.c: rings: the stage rows, spinning, carried and scattered rings, sparkles; the unused gauge ring and template spawner */
void spawn_ring_rows(uint32_t *p_stage_list_offset, uint32_t *p_free_stack, uint32_t *p_slope_height, uint32_t *p_object);
void ring_spin(void);
void ring_spin_keep_spinning(uint32_t sparkle);
void still_ring_wait(void);
void carried_ring_wait(void);
void carried_ring_spin(void);
void carried_ring_keep_spinning(uint32_t sparkle);
void carried_ring_spin_spare_return(void);
void scatter_rings_fixed(uint32_t count, uint32_t *p_random_value, uint32_t *p_allocated);
void scatter_rings_random(uint32_t random_value, uint32_t count, uint32_t *p_allocated, uint32_t *p_ring);
void scatter_rings(uint32_t count, uint32_t *p_random_value, uint32_t *p_allocated, uint32_t *p_ring);
void scattered_ring_wait(void);
void scattered_ring_live(void);
void move_scattered_ring(uint32_t cursor);
void scattered_ring_vanish(void);
void spawn_ring_sparkle(uint32_t sparkle);
void spawn_ring_glint(uint32_t sparkle);
void init_sparkle_object(uint32_t sparkle);
void sparkle_start(void);
void sparkle_animate(void);
void spawn_gauge_ring(uint32_t ring);
void gauge_ring_update(void);
void gauge_ring_rise(void);
void gauge_ring_fall_into_gauge(void);
void spawn_stage_template_0(uint16_t x, uint16_t y, uint16_t z, uint32_t object);
void spawn_stage_template(uint16_t template_index, uint16_t x, uint16_t y, uint16_t z, uint32_t object);

/* objects/shared.c: objects several stages use: the signs, the scenery sprites, the walls players and objects bounce off, the zones behind the chasers, the pacer that keeps two players together, the hold on a group leader; object types 4 and 13; the crawler, which nothing spawns */
void animate_sign(void);
void sign_start_from_type(void);
void crawler_init(void);
void crawler_head_update(void);
void crawler_segment_animate(void);
void crawler_segment_update(void);
void crawler_step(void);
void object_type_4_idle(void);
uint32_t spawn_chaser_back_zone(uint32_t zone_index, uint32_t zone);
void chaser_back_zone_check_parent(void);
void chaser_back_zone_update(void);
void spawn_roller_back_zone(uint32_t zone_index, uint32_t zone);
void roller_back_zone_update(void);
void player_pacer_start(void);
void player_pacer_update(void);
void get_pacing_axis(uint32_t player, uint32_t *p_axis_field, uint32_t *p_decreasing);
void sign_start(void);
void spawn_sign(uint16_t x, uint16_t y, uint16_t kind, uint16_t z, uint32_t *p_depth, uint32_t *p_sign);
uint32_t spawn_sign_2(uint16_t x, uint16_t y, uint16_t kind, uint16_t z, uint32_t sign);
void place_sign(uint16_t x, uint16_t y, uint32_t kind, uint16_t z, uint32_t *p_depth, uint32_t *p_sign);
void init_sign_from_kind(uint32_t record, uint32_t *p_depth, uint32_t *p_sign);
void sign_show_unless_mode_32(void);
void sign_show_while_player_busy(void);
void sign_show_until_goal_unlocked(void);
void sign_show_while_parent_still(void);
void sign_show_until_gate_closed(void);
void sign_show_until_cage_bar_hit(void);
void sign_show_unless_stage_0(void);
void sign_show(void);
void sign_follow_parent(void);
void sign_follow_player(void);
void screen_sign_start(void);
void spawn_screen_sign(uint16_t screen_x, uint16_t screen_y, uint16_t kind, uint32_t sign);
void spawn_screen_sign_2(uint16_t screen_x, uint16_t screen_y, uint16_t kind, uint32_t sign);
void place_screen_sign(uint16_t screen_x, uint16_t screen_y, uint32_t kind, uint32_t sign);
void screen_sign_show(void);
void floor_sign_start(void);
void floor_sign_update(void);
void scenery_sprite_start(void);
void scenery_sprite_draw_until_you_failed(void);
void scenery_sprite_draw(void);
void scenery_sprite_draw_until_offscreen(void);
void scenery_sprite_draw_wide_margin(void);
void scenery_sprite_cycle_palette_start(void);
void scenery_sprite_cycle_palette(void);
void group_leader_hold_start(void);
void group_leader_hold_wait(void);
void spawn_walls(uint32_t *p_spawns_offset, uint32_t *p_part_size, uint32_t *p_second_sprite, uint32_t *p_point_y, uint32_t *p_z, uint32_t *p_wall);
void wall_update(void);
void wall_update_list_and_draw(void);
void wall_update_spare_return(void);
uint32_t check_wall_left_screen(void);
void wall_editor_set_side_label(void);
void wall_editor_draw_arrow(uint32_t marker_x, uint32_t marker_y);
void wall_editor_draw_arrow_at_z(uint32_t marker_x, uint32_t marker_y, uint32_t marker_z);
void wall_editor_draw_pattern_number(void);
void wall_editor_rebuild_parts(uint32_t part);
void build_wall_parts(uint32_t *p_part_size, uint32_t *p_second_sprite, uint32_t *p_part);

/* objects/stage_03.c: stage 3's objects: the spiked panels and the electric poles, the crate pushed to a post, the breakable panel, the spiked roller that chases the players (also in stage E) and the floor that crumbles at the finale, the machine at 8300 with its fire and fireballs, the fire vents, the end pillar */
void spike_panel_init(void);
void spike_panel_hold(void);
void spike_panel_update(void);
void spike_panel_base_draw(void);
void spike_panel_hitbox_update(void);
void spike_panel_part_idle(void);
void electric_pole_init(void);
void electric_pole_wait(void);
void electric_pole_rise(void);
void electric_pole_update(void);
void electric_pole_draw(void);
void push_crate_init(void);
void push_crate_update(void);
void push_crate_break(void);
void push_crate_move(uint32_t cursor, uint32_t random_value, uint32_t ring);
void push_crate_stop_post_update(void);
void push_crate_release_all_rings(uint32_t *p_allocated, uint32_t *p_random_value, uint32_t *p_ring);
void push_crate_release_rings(uint32_t seed, uint32_t *p_allocated, uint32_t *p_random_value, uint32_t *p_ring);
void breakable_panel_init(void);
void breakable_panel_wait(void);
void breakable_panel_break(void);
void draw_breakable_panel(void);
void stage_03_floor_block_start(void);
void stage_03_floor_block_update(void);
void spiked_roller_start(void);
void spiked_roller_update(void);
void spiked_roller_chase(void);
void spiked_roller_chase_read_script(void);
void spiked_roller_chase_move_step(void);
void spiked_roller_chase_rumble(void);
void spiked_roller_chase_check_event(void);
void spiked_roller_fall_off_ledge(void);
void spiked_roller_fall(void);
void spiked_roller_follow_leader(void);
void spiked_roller_wait_hidden(void);
void spiked_roller_drop_in(void);
void spiked_roller_ram(void);
void spiked_roller_ram_charge(void);
void spiked_roller_ram_pause(void);
void spiked_roller_ram_back_off(void);
void spiked_roller_ram_wait(void);
void spiked_roller_remove(void);
void spiked_roller_crash_into_machine(void);
void spiked_roller_sink_and_jump(void);
void spiked_roller_burst_out(void);
void spiked_roller_smash_wall(void);
void spiked_roller_wait_for_turn(void);
void spiked_roller_wait_to_burst_out(void);
void spiked_roller_shift_box(void);
void spiked_roller_spawn_fixed_zone(void);
void roller_fixed_zone_update(void);
void machine_start(void);
void machine_run(void);
void machine_fire_update(void);
void machine_fire_read_script(void);
void machine_fire_climb_step(void);
void start_fireball_flipped(void);
void fireball_start(void);
void init_fireball_flight(void);
void fireball_fly(void);
void flame_start(void);
void flame_burn(void);
void rising_flame_update(void);
void rising_flame_init(void);
void rising_flame_rise(void);
void rising_flame_spawn_next(void);
void rising_flame_wait_offscreen(void);
uint32_t spawn_stage_03_end_pillar(uint32_t pillar);
void stage_03_end_pillar_show(void);
void exit_gate_start(uint32_t sign);
void exit_gate_update(void);
void ram_target_start(void);
void ram_target_update(void);
void ram_target_check_hits(void);
void ram_target_draw(void);
void ram_target_burst(uint32_t piece);
void ram_target_part_start(void);
void ram_target_part_update(void);
void fire_vent_spawner_start(void);
void fire_vent_spawner_update(void);
void fire_vent_start(void);
void fire_vent_update(void);
void fire_vent_blast(void);
void fire_vent_draw(void);
void fire_vent_burst_animate(void);

/* objects/stage_04.c: stage 4's objects: the vines, the catapults, arrow boards, pebbles, the propped board, boulders, the door wall at the start and the rollers behind it, the fireball emitter and the bouncing fireballs, the electric fence and the flame machine at the end */
void vine_init(void);
void vine_swing(void);
void vine_bar_update(void);
void vine_scroll_stop_init(void);
void vine_scroll_stop_wait(void);
void vine_scroll_stop_hold(void);
void vine_scroll_stop_end(void);
void flame_machine_init(void);
void flame_machine_update(void);
void flame_machine_draw(void);
void flame_machine_destroyed(uint32_t free_count, uint32_t first, uint32_t block);
void flame_machine_update_spare_return(void);
void flame_machine_remove(void);
void flame_machine_explosion_start(void);
void flame_machine_back_wall_update(void);
void flame_machine_arm_update(void);
void flame_machine_arm_rest(void);
void flame_machine_arm_draw(void);
void flame_machine_cannon_update(void);
void flame_machine_flame_burn(void);
void flame_machine_arm_take_disc(uint32_t free_count, uint32_t disc, uint32_t block);
void spiked_disc_hold(void);
void spiked_disc_drop(void);
void spiked_disc_draw_held(void);
void spiked_disc_roll(void);
void spiked_disc_draw_shadow(void);
void spiked_disc_spin(void);
void flame_machine_scroll_stop_wait(void);
void flame_machine_scroll_stop_hold(void);
void object_type_9_idle(void);
void flame_machine_wreck_draw(void);
void fence_post_init(void);
void fence_post_start(void);
void fence_post_update(void);
void fence_post_draw(void);
void catapult_x_start(void);
void catapult_y_start(void);
void catapult_wait_for_platform(void);
void catapult_y_start_on_floor(uint32_t object);
void catapult_x_start_on_floor(uint32_t object);
void catapult_wait_for_platform_setup(uint32_t template_offset, uint32_t object);
void catapult_update(void);
void catapult_wait_for_rider(void);
void catapult_launch(void);
void catapult_swing_up(void);
void catapult_hold_up(void);
void catapult_swing_down(void);
void catapult_wait_for_scroll(void);
void catapult_base_update(void);
void catapult_dummy_update(void);
void goal_unlocker_start(void);
void arrow_board_start(void);
void arrow_board_wait_for_platform(void);
void arrow_board_ride(void);
void pebble_start(void);
void pebble_update(void);
void propped_board_start(void);
void propped_board_update(void);
void board_prop_start(void);
void board_prop_update(void);
void release_board_rings(void);
void boulder_start(void);
void boulder_wait(void);
void boulder_roll(void);
void door_wall_start(void);
void door_wall_wait_to_burst(void);
void spawn_door_rollers(uint32_t *p_block_offset, uint32_t *p_slope_height, uint32_t *p_object);
void door_roller_update(void);
void door_roller_wait(void);
void door_roller_drop(void);
void door_roller_roll_out(void);
void door_roller_ride(void);
void fireball_emitter_start(void);
void fireball_emitter_update(void);
void bouncing_fireball_update(void);
void bouncing_fireball_update_spare_return(void);
void bouncing_fireball_knocked_away(void);
void knocked_object_fly(void);

/* objects/stage_05.c: stage 5's objects: the exit door, the floor patch, the bubbles, the spiked press, the cage */
void exit_door_start(void);
void exit_door_wait_for_switch(void);
void exit_door_show(void);
void stage_05_floor_patch_start(void);
void stage_05_floor_patch_show(void);
void bubble_start(void);
void bubble_update(void);
void bubble_near_parent_update(void);
void bubble_pop(void);
void spiked_press_start(void);
void spiked_press_update(void);
void cage_start(void);
void cage_bar_start(void);
void cage_bar_update(void);

/* objects/stage_08.c: stage 8's objects, the lava: the treadmill that raises a gate, the flame jets, the rock wall, the collapsing log bridge, the burning boulders and embers, the carriers and the seesaw, the metal platform and the fire wall, the fire trenches, the lava flow under the hanging bridge, the rock slabs and the lava columns */
void treadmill_init(void);
void treadmill_update(void);
void treadmill_roller_update(void);
void treadmill_gate_update(void);
void treadmill_gate_half_update(void);
void flame_jet_init(void);
void flame_jet_nozzle_update(void);
void flame_jet_pilot(void);
void flame_jet_ignite(void);
void flame_jet_burn(void);
void rock_wall_init(void);
void rock_wall_update(void);
void collapsing_bridge_plank_update(void);
void burning_boulder_start(void);
void burning_boulder_update(void);
void burning_boulder_flame_start(void);
void burning_boulder_flame_flicker(void);
void ember_emitter_start(void);
void ember_emitter_move(void);
void falling_ember_update(void);
void scene_carrier_start(void);
void scene_carrier_move(void);
void seesaw_start(void);
void seesaw_tilt(void);
void metal_platform_base_start(void);
void metal_platform_base_draw(void);
void metal_platform_start(void);
void metal_platform_update(void);
void fire_wall_start(void);
void fire_wall_rise(void);
void fire_trench_start(void);
void fire_trench_update(void);
void spawn_fire_trench_flames(void);
void fire_trench_flame_burn(void);
void ridden_object_start(void);
void ridden_object_fall(void);
void ridden_object_follow(void);
void bridge_fire_start(void);
void bridge_fire_rise(void);
void bridge_fire_read_script(void);
void bridge_fire_climb_step(void);
void lava_flow_start(void);
void lava_flow_wait(void);
void lava_flow_advance(void);
void lava_flow_read_script(void);
void lava_flow_move_step(void);
void extend_lava_flow(uint32_t block);
void lava_flow_segment_follow(void);
uint32_t spawn_lava_flame(uint32_t random_value, uint32_t flame);
void lava_flame_burn(void);
void spawn_lava_steam(void);
void lava_steam_puff_update(void);
void lava_rock_update(void);
void lava_rock_erupt(uint32_t block);
void lava_rock_draw_at_previous_floor(void);
uint32_t spawn_lava_column(uint32_t block);
void lava_column_start(void);
void lava_column_rise(void);
void lava_column_toss_start(void);
void lava_column_toss(void);
void lava_column_land(void);
void lava_column_land_in_place(void);
void lava_column_become_bubble(void);
void spawn_group_slot_trigger(uint32_t record, uint32_t *p_spawned, uint32_t *p_count, uint32_t *p_trigger);
void group_slot_trigger_update(void);

/* objects/stage_09.c: stage 9's objects, the ice: the handle rod between two posts, the spear traps, the ice cube launcher, the padded wall, the snow mound, the ice blocks and the moving ice platform, the crumbling ice floor, the icicles */
void handle_rod_init(void);
void handle_rod_handle_init(void);
void handle_rod_wait(void);
void handle_rod_start_swing(void);
void handle_rod_swing(void);
void handle_rod_hang(void);
void handle_rod_remove(void);
void handle_rod_handle_update(void);
void handle_rod_post_init(void);
void handle_rod_post_update(void);
void handle_rod_post_fall(void);
void spear_trap_init_100(void);
void spear_trap_init_300(void);
void spear_trap_init(void);
void spear_trap_wait(void);
void spear_trap_rise(void);
void spear_trap_stay_up(void);
void spear_trap_retract(void);
void spear_trap_draw_touchable(void);
void spear_trap_draw(void);
void ice_launcher_init(void);
void ice_launcher_update(void);
void ice_cube_slide(void);
void object_type_17_idle(void);
void padded_wall_init(void);
void padded_wall_update(void);
void wall_pad_update(void);
void snow_mound_init(void);
void snow_mound_update(void);
void snow_mound_burst(void);
void snow_mound_draw(void);
void ice_block_row_start(void);
void ice_block_update(void);
void spawn_ice_platform_leader(uint32_t record, uint32_t *p_spawned, uint32_t *p_travel, uint32_t *p_leader);
void ice_platform_leader_move(void);
void ice_platform_piece_update(void);
void ice_floor_start(void);
void ice_floor_block_update(void);
void icicle_dropper_start(void);
void icicle_dropper_move(void);
void icicle_dropper_coordinate_reached(uint32_t path_cursor);
void icicle_dropper_check_scroll_position(uint32_t path_cursor);
void icicle_dropper_load_record(uint32_t path_cursor);
void icicle_dropper_move_step(void);
void icicle_dropper_choose_speed(uint32_t slope_height, uint32_t cursor);
void icicle_dropper_catch_up_speed(uint32_t slope_height, uint32_t cursor);
void icicle_dropper_move_at_speed(uint16_t move_speed, uint32_t slope_height, uint32_t cursor);
void icicle_dropper_finish(void);
void drop_icicle_row(uint32_t random_value, uint32_t block);
void icicle_update(void);
void icicle_buried_part_draw(void);
void icicle_cracks_spread(void);
void icicle_shadow_follow(void);
void set_icicle_wall_box(void);

/* objects/stage_0a.c: stage A's objects, the sand: the cactus, the centipede, the wall pieces, the shaking blocks, the sand rock, the sand arch, the stepped wall, the tornado and the whirlwinds it throws, quicksand, sinkholes, the collapsing sand blocks */
void cactus_init(void);
void cactus_update(void);
uint32_t spawn_whirlwind(uint32_t spawned, uint32_t free_count, uint32_t whirlwind, uint32_t object);
void whirlwind_aim(void);
void whirlwind_move(void);
void whirlwind_vanish(void);
void centipede_init(void);
void centipede_chase(void);
void centipede_leave(void);
void centipede_move(uint32_t block);
void centipede_segment_wait(void);
void centipede_segment_follow(void);
void centipede_tail_wait(void);
void centipede_tail_follow(void);
uint32_t centipede_follow_path(void);
void centipede_hop(uint32_t *p_height, uint32_t *p_z);
void draw_centipede_piece(void);
void spawn_centipede_sand_puff(uint32_t spawned, uint32_t free_count, uint32_t puff, uint32_t block);
void sand_puff_start(void);
void sand_puff_animate(void);
void wall_piece_init(void);
void wall_piece_draw(void);
void shaking_block_init(void);
void shaking_block_animate(void);
void sand_rock_init(void);
void sand_rock_update(void);
void sand_rock_crumble(void);
void sand_rock_draw(void);
void sand_rock_draw_piece(void);
void sand_arch_init(void);
void sand_arch_update(void);
void sand_arch_ball_init(void);
void sand_arch_ball_delay(void);
void sand_arch_ball_move(void);
void sand_arch_ball_gone(void);
void sand_arch_ball_bob(void);
void stepped_wall_init(void);
void stepped_wall_draw(void);
void tornado_start(void);
void tornado_move(void);
void tornado_load_record(uint32_t path_cursor);
void tornado_remove_with_columns(void);
void tornado_move_step(void);
void tornado_choose_speed(void);
void tornado_catch_up_speed(void);
void tornado_move_at_speed(uint16_t move_speed);
void tornado_column_circle(void);
void spawn_tornado_hazard(uint32_t x, uint32_t y, uint32_t z, uint32_t hazard);
void tornado_hazard_update(void);
uint32_t tornado_throw_whirlwinds(uint8_t spawned, uint32_t free_count, uint32_t whirlwind, uint32_t object);
uint32_t spawn_tornado_rear_zone(uint32_t zone);
void tornado_rear_zone_follow(void);
void quicksand_start(void);
void quicksand_swirl(void);
void sinkhole_start(void);
void sinkhole_open(void);
void sand_patch_start(void);
void sand_patch_draw(void);
void rimmed_sinkhole_start(void);
void rimmed_sinkhole_open(void);
void rimmed_sinkhole_edge_zone_update(void);
void spawn_sand_block_leader(uint32_t record, uint32_t *p_spawned, uint32_t *p_leader);
void sand_block_leader_wait(void);
void sand_block_leader_move(void);
void sand_block_leader_read_script(void);
void sand_block_leader_move_step(void);
void sand_block_update(void);
void sand_face_update(void);
void sand_streams_update(void);
uint32_t spawn_sink_swirl(uint32_t allocated);
void sink_swirl_start(void);
void sink_swirl_animate(void);

/* objects/stage_10.c: stage 10's objects, the river: the mines and the bubble column, the lid trap, the turtle, the eel and its den, the rafts, the geysers, the waterfall and the river water, the propeller machine that chases the players, the barred gate, the rope bridge */
void spawn_bubble_column(uint32_t spawned, uint32_t free_count, uint32_t column, uint32_t block);
void bubble_column_init(void);
void bubble_column_animate(void);
void mine_init(void);
void mine_float(void);
void mine_fall(void);
void mine_sink(void);
void mine_explode(void);
void animate_sinking_mine(void);
void draw_mine_with_bubbles(void);
void flash_mine_palette(uint8_t sinking);
void spawn_mine_splash(uint32_t spawned, uint32_t free_count, uint32_t splash, uint32_t block);
void mine_splash_animate(void);
void lid_trap_init(void);
void lid_trap_update(void);
void turtle_init(void);
void turtle_wait(void);
void turtle_surface(void);
void turtle_drop_rings(void);
void turtle_swim(void);
void eel_init(void);
void eel_anchor_update(void);
void eel_anchor_wait_explode(void);
void eel_anchor_stretch(void);
void eel_anchor_draw_shadow(void);
void eel_anchor_wait_explode_spare_return(void);
void eel_head_move(void);
void eel_segment_move(void);
void draw_eel_piece_parts(void);
void place_eel_piece(void);
void eel_head_explode_delay(void);
void eel_segment_explode_delay(void);
void eel_piece_start_explosion(void);
void eel_piece_explode(void);
void eel_piece_gone(void);
void spawn_eel_den(uint32_t spawned, uint32_t free_count, uint32_t den, uint32_t block);
void eel_den_init(void);
void eel_den_wait(void);
void eel_den_collapse(void);
void eel_den_draw(void);
void river_raft_spawner_init(void);
void river_raft_spawner_update(void);
void river_raft_update(void);
void river_raft_foam_update(void);
void clipped_copy_sprite_start(uint32_t copy);
void clipped_copy_sprite_update(void);
void geyser_front_init(void);
void geyser_front_wait(void);
void geyser_front_rise(void);
void geyser_front_read_script(void);
void geyser_front_rise_step(void);
void geyser_front_spawn_geyser_row(void);
void geyser_front_rise_sound(void);
uint32_t spawn_listed_geyser(uint32_t geyser);
void spawn_geyser(uint32_t x, uint32_t y, uint16_t wait, uint32_t *p_spawned, uint32_t *p_geyser);
void geyser_wait(void);
void geyser_erupt(void);
void spawn_waterfall(uint32_t record, uint32_t *p_spawned, uint32_t *p_free_stack, uint32_t *p_block);
void waterfall_move(void);
void waterfall_read_script(void);
void waterfall_move_step(void);
void river_water_update(void);
void stone_block_init(void);
void stone_block_draw(void);
void spawn_geyser_line(uint32_t line);
void geyser_line_move(void);
void spawn_geyser_burst(void);
void geyser_burst_start(void);
void geyser_burst_erupt(void);
void propeller_machine_init(void);
void propeller_machine_chase(void);
void propeller_machine_read_script(void);
void propeller_machine_chase_step(void);
void barred_gate_init(void);
void barred_gate_update(void);
void scene_anchor_init(void);
void scene_anchor_update(void);
void railing_spawner_init(void);
void railing_spawner_update(void);
void railing_segment_start(void);
void railing_segment_draw(void);
void rope_bridge_plank_update(void);
void rope_bridge_plank_start_falling(void);
void rope_bridge_plank_check_rider_and_draw(void);
void draw_rope_bridge_ropes(void);
void event_19_check_rope_bridge(uint32_t position, uint32_t in_play_count, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void event_12_stage_frame(uint32_t pressed, uint32_t position, uint32_t in_play_count, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);

/* objects/stages_0b_0f.c: the objects of stages B to F: the chasers (the brick wall that bursts, the biting head, the fire front) and the flames that spread ahead of it, the spike gate, the falling grates, the rising saws and the steps they cut, the puffs, the checkered pad, the static triangle, the railing */
void white_puff_init(void);
void white_puff_animate(void);
void checker_pad_init(void);
void checker_pad_animate(void);
void static_triangle_init(void);
void static_triangle_animate(void);
void railing_init(void);
void railing_draw(void);
void railing_side_update(void);
void spike_gate_init(void);
void spike_gate_pillar_update(void);
void spike_gate_beam_rise(void);
void spike_gate_beam_hold(void);
void spike_gate_beam_drop(void);
void spike_gate_beam_wait(void);
void spike_gate_beam_update(void);
void spreading_flame_start(void);
void spreading_flame_burn(void);
void brick_wall_init(void);
void brick_wall_wait(void);
void brick_dust_animate(void);
void biting_head_init(void);
void biting_head_wait(void);
void biting_head_chase(void);
void biting_head_read_script(void);
void biting_head_load_record(uint32_t path_cursor);
void biting_head_chase_step(void);
void biting_head_choose_speed(void);
void biting_head_catch_up_speed(void);
void biting_head_move_at_speed(uint16_t move_speed);
void fire_front_init(void);
void fire_front_chase(void);
void fire_front_read_script(void);
void fire_front_load_record(uint32_t path_cursor);
void fire_front_chase_step(void);
void falling_grate_update(void);
void rising_saw_init(void);
void rising_saw_rise(void);
void saw_blade_update(void);
void saw_sparks_update(void);
void saw_shaft_update(void);
void grate_steps_init(void);
void build_grate_steps(void);
void grate_step_update(void);
void spawn_grate_step_debris(void);
void grate_step_debris_fly(void);
void build_saw_shaft_base(void);
void saw_shaft_base_draw(void);

/* player/carried_states.c: the player's states while the stage carries or holds them: thrown, carried off, trapped, riding, the final stage, tripped, swept away, climbing an object, pulled, held still, stuck on an object, caught, sinking, knocked off */
void player_state_scene_thrown(uint32_t depth, uint32_t cursor);
void player_state_carried_off(uint32_t depth, uint32_t cursor);
void player_state_trapped(uint32_t depth, uint32_t cursor);
void trap_flash_start(void);
void trap_flash_update(void);
void trap_start(void);
void trap_update(void);
void player_state_riding(void);
void player_state_final_stage(void);
void player_state_tripped(uint32_t cursor);
void player_state_swept_away(void);
void player_state_climbing_object(uint32_t cursor);
void player_object_climb_begin(void);
void player_object_climb_push(uint32_t cursor);
void player_object_climb_move(void);
void spawn_climb_hand(uint32_t hand);
void climb_hand_update(void);
void player_state_pulled(uint32_t cursor);
void player_state_floor_8_sequence(uint32_t cursor);
void player_floor_8_sequence_struggle(void);
void player_move_with_scroll(uint32_t *p_depth, uint32_t *p_cursor);
uint32_t spawn_player_effect(uint32_t effect);
void player_effect_start(void);
void player_effect_update(void);
uint32_t spawn_struggle_marker(uint32_t marker);
void struggle_marker_update(void);
void scene_object_start(void);
void scene_object_update(void);
void player_state_held_still(void);
void player_state_stuck_on_object(uint32_t depth, uint32_t cursor);
void player_stuck_on_object_begin(uint32_t sign);
void player_stuck_on_object_wait(void);
void player_stuck_on_object_shake(void);
void player_stuck_on_object_jump_out(void);
void player_state_caught(uint32_t cursor);
void player_state_sinking(uint32_t cursor);
void sinking_effect_update(void);
void player_state_knocked_off(uint32_t depth, uint32_t cursor);
void player_knocked_off_start(void);
void player_knocked_off_fly(void);

/* player/effects.c: around the players: the skid dust, the HUD (gauge, portrait, ring count, start prompt, messages), the ride of game mode 0x1C, joining with a character select, the result bonus, the climb zone splash, the intro marker */
void spawn_skid_dust(uint32_t dust);
void skid_dust_update(void);
void player_hud_init(void);
void player_hud_start(void);
void player_hud_update(uint32_t *p_digit_attribute, uint32_t *p_text_position);
uint32_t draw_player_start_prompt(void);
uint32_t original_draw_player_start_prompt(void);
void animate_hud_palette(uint32_t *p_list_index, uint32_t *p_wrapped);
void animate_hud_tiles(uint32_t *p_list_index, uint32_t *p_wrapped);
uint32_t blink_player_hud_message(uint32_t text, uint32_t text_position);
void draw_player_stage_rings(void);
uint32_t spawn_player_ride(uint32_t object);
void player_select_character(uint32_t player_number);
void give_result_bonus(uint32_t player);
void spawn_climb_zone_effect(uint32_t object);
void climb_zone_effect_start(void);
void climb_zone_effect_update(void);
void spawn_intro_marker(uint32_t object);
void intro_marker_update(void);
void update_hurt_output(void);
void check_player_stalled(void);

/* player/player.c: the player: starting, joining, resetting and placing a player, player_update, the movement (screen edges, trackball, turning, jumps, walls), the shadow, the floor checks, the restart point, the checks of every frame, and check_player_contacts (what touching each kind of object does) */
void player_1_start(void);
void player_2_start(void);
void player_3_start(void);
void player_start(void);
void player_resume(void);
void player_join(void);
void player_start_stage(void);
void player_respawn(void);
void player_restart(void);
void player_reset_joined(void);
void player_reset(void);
void player_place(void);
void player_update(void);
void player_dispatch_state(uint32_t depth, uint32_t cursor);
uint32_t keep_player_on_screen(uint32_t depth);
uint32_t push_player_from_screen_edge(void);
void compute_scroll_drift(uint32_t block, uint8_t drift_byte);
void slip_effect_update(void);
uint32_t set_speed_from_trackball(void);
uint32_t set_climb_speed_from_trackball(void);
uint32_t update_ledge_pullback(void);
void get_ledge_side(uint32_t *p_side, uint32_t *p_block);
void check_player_floor_edge(uint32_t *p_depth, uint32_t *p_block);
void check_fall_into_pit(void);
void add_player_to_lists(void);
void remember_platform(void);
void update_player_blink(void);
void toggle_hidden(void);
void check_player_jump(void);
void start_jump_if_pressed(void);
void push_player_out_of_wall(uint32_t *p_angle, uint32_t *p_push_direction, uint32_t *p_record_index);
void push_player_out_of_wall_deflect(uint32_t *p_angle, uint32_t *p_push_direction, uint32_t *p_record_index);
void player_steer_in_air(void);
void player_steer(uint32_t wanted_speed);
void player_steer_speed_from_trackball(void);
void player_steer_approach_speed(uint32_t wanted_speed);
void player_steer_turn_and_ground_speed(void);
void set_target_heading_from_trackball(void);
void turn_player(void);
void set_heading_direction(void);
uint32_t set_facing(uint32_t facing);
uint32_t face_movement_direction(uint32_t facing);
uint32_t compute_ground_speed(void);
void read_player_trackball(void);
void shadow_1_start(void);
void shadow_2_start(void);
void shadow_3_start(void);
void shadow_start(void);
void shadow_update(void);
void draw_attack_effect(uint32_t player);
void check_player_step(uint32_t *p_height_diff, uint32_t *p_cursor);
void check_player_step_against_floor(uint32_t *p_height_diff, uint32_t *p_cursor);
void bounce_off_wall_in_air(void);
uint32_t get_floor_block_side(uint32_t floor_block, uint32_t x, uint32_t y);
void get_floor_block_side_or_corner(uint32_t block, uint32_t x, uint32_t y, uint32_t *p_outcode, uint32_t *p_side_code);
uint32_t place_player_at_restart_point(void);
void aim_at_screen_centre(uint32_t *p_cos_part, uint32_t *p_dx, uint32_t *p_dy);
void flash_hurt_palette(void);
void set_floor_sprite_priority(void);
uint32_t update_quicksand_object(uint32_t sink_offset);
uint32_t update_sinking_floor(uint32_t sink_offset);
void apply_moving_floor(void);
void check_zone_contact(void);
void check_stage_entry_path(void);
void load_stage_goal(void);
void check_player_reached_goal(void);
void spawn_tumble_effect(uint32_t effect);
void tumble_effect_update(void);
uint32_t apply_speed_scale(uint32_t target_speed);
void set_player_entry_by_scene(void);
uint32_t try_continue(uint8_t cost);
uint32_t try_join(void);
uint32_t pay_and_join(uint8_t cost, uint32_t joined);
uint32_t check_scene_states(uint32_t object);
void set_fall_sprite_priority(void);
void start_climb_at_spawn(uint32_t climbed_height);
void start_climb(void);
void add_push_to_player_motion(void);
void apply_floor_push(void);
uint32_t spawn_slip_piece(uint32_t piece);
void slip_piece_update(void);
void spawn_slip_pieces(uint32_t piece);
void slip_pieces_update(void);
uint32_t follow_player_path(uint32_t target_speed);
uint32_t follow_player_path_start(void);
uint32_t follow_player_path_run(void);
uint32_t follow_player_path_next_record(void);
uint32_t follow_player_path_load_record(void);
uint32_t follow_player_path_aim_at_point(void);
uint32_t follow_player_path_target_speed(void);
void check_player_contacts(uint32_t *p_health_limit, uint32_t *p_cursor);
void check_player_contacts_clear_state(void);
void check_player_contacts_hurt_unless_invulnerable(uint32_t toucher);
void check_player_contacts_hurt(uint32_t toucher);
void check_player_contacts_attack_or_hurt(uint8_t new_substate, uint32_t toucher);
uint32_t check_player_contacts_solid(uint32_t health_limit, uint32_t toucher);
void check_player_contacts_attack(uint32_t toucher);

/* player/scene_states.c: the player's states in scenes and stage events: out of the game, continue, entering and leaving a stage, tumbling, blown away, the intro and opening scenes, stunned, choosing a character, YOU FAILED, held, stuck */
void player_state_out_of_game(void);
void player_state_continue(void);
void player_state_in_zone(uint32_t depth, uint32_t cursor);
void player_in_zone_steer(uint32_t depth, uint32_t cursor);
void player_state_entering_stage(uint32_t depth, uint32_t cursor);
void player_state_stage_exit(uint32_t depth, uint32_t cursor);
void player_state_tumbling(uint32_t depth, uint32_t cursor);
void player_tumbling_start(uint32_t cursor);
void player_tumbling_knock_with_toucher_speed(uint32_t toucher, uint32_t effect);
void player_tumbling_set_launch_speed(uint32_t toucher, uint32_t effect);
void player_tumbling_launch(uint32_t toucher, uint32_t effect);
void player_tumbling_fly(void);
void player_state_blown_away(uint32_t cursor);
void blown_away_effect_update(void);
void player_state_intro_turn(uint32_t depth, uint32_t cursor);
void player_state_opening_scene(void);
void player_state_opening_scene_spare_return(void);
void shadow_update_spare_return(void);
void player_state_stage_scene(uint32_t depth, uint32_t cursor);
void player_state_stunned(uint32_t depth, uint32_t cursor);
void player_state_choosing_character(uint32_t cursor);
void player_state_you_failed(void);
void player_state_held(uint32_t depth, uint32_t cursor);
void player_state_stuck(uint32_t cursor);
void player_stuck_begin(uint32_t object);
void player_stuck_wait_release(void);
void player_stuck_shake(void);
void player_stuck_jump_out(void);
void stuck_effect_update(void);
void player_state_stage_b_sequence(uint32_t depth, uint32_t cursor);

/* player/states.c: the player's states in play: standing, walking, running, falling and jumping (player_move, player_animate), teetering on a ledge and going over it, dropping, falling into a pit, climbing a wall, skidding, hopping, dying, launched, hurt, bouncing */
void player_move(uint32_t depth, uint32_t cursor);
void player_move_check_edge(uint32_t depth, uint32_t cursor);
void player_animate(uint32_t depth, uint32_t cursor);
void player_animate_standing(void);
void player_animate_walking(void);
void player_animate_running_fast(void);
void player_animate_running(void);
void player_animate_run_cycle(uint32_t animation_table);
void player_animate_run_cycle_alternate(void);
void player_animate_run_from_table(uint32_t animation_table);
void player_animate_falling(void);
void player_state_inactive(void);
void player_animate_jumping(uint32_t sign);
void player_animate_jumping_land(void);
void player_draw(void);
void player_state_teetering(uint32_t cursor);
void player_state_falling_off_edge(void);
void player_state_falling_off_edge_spare_return(void);
void player_state_over_edge(uint32_t jump_offset, uint32_t cursor);
void player_over_edge_check_pull_up(uint32_t cursor);
void player_over_edge_drop(uint32_t cursor);
void player_over_edge_hang_finish(uint32_t cursor);
void player_state_dropping(uint32_t cursor);
void player_state_dropping_spare_return(void);
void player_state_falling_into_pit(void);
void player_state_falling_into_pit_spare_return(void);
void player_state_climbing(uint32_t depth, uint32_t cursor);
void player_climbing_start(uint32_t cursor, uint32_t attribute_record);
void player_climbing_grab_wall(uint32_t cursor, uint32_t attribute_record);
void player_climbing_descend_over_edge(uint32_t cursor, uint32_t attribute_record);
void player_climbing_begin_climb(uint32_t cursor, uint32_t attribute_record);
void player_climbing_move(uint32_t cursor, uint32_t attribute_record);
void player_climbing_side_step(uint32_t cos_speed, uint32_t cursor, uint32_t attribute_record);
void player_climbing_check_vertical_step(uint32_t cursor, uint32_t attribute_record);
void player_climbing_start_vertical_step(uint32_t cursor, uint32_t attribute_record);
void player_climbing_animate_vertical_step(uint32_t cursor, uint32_t attribute_record);
void player_climbing_update_position(uint32_t cursor, uint32_t attribute_record);
void player_climbing_pull_up(uint32_t attribute_record);
void player_state_not_playing(void);
void player_animate_skidding(uint32_t depth, uint32_t cursor);
void player_animate_skidding_slow_down(uint32_t cursor);
void player_state_game_over(uint32_t jump_offset);
void player_state_short_animation(void);
void player_state_inactive_2(void);
void player_animate_hopping(void);
void player_state_dying(void);
void player_state_launched(void);
void player_state_launched_spare_return(void);
void player_launch_angle_200(void);
void player_launch_angle_100(void);
void player_launch(void);
void player_launched_fly(void);
void player_launched_land(void);
void player_state_hurt(uint32_t depth, uint32_t cursor);
void player_hurt_knockback(uint32_t cursor);
void player_hurt_set_animation(uint32_t cursor);
void player_hurt_fly(uint32_t depth, uint32_t cursor);
void player_hurt_land_after_hop(void);
void player_hurt_get_up(void);
void player_state_hurt_spare_return(void);
void player_state_bouncing(void);

/* scenes/character_select.c: choosing a character: the PLAYER SELECT chooser at a new game and the chooser of a player joining */
void reset_character_select(void);
void start_character_chooser(uint32_t block);
void character_chooser_wait(void);
void original_character_chooser_wait(void);
void character_chooser_confirm(void);
void character_chooser_idle(void);
void draw_character_chooser_labels(void);
void character_chooser_turn(void);
void character_chooser_chosen(void);
void character_select_countdown_update(void);
uint32_t start_join_character_chooser(void);
void join_character_chooser_update(uint32_t text_x);
void original_join_character_chooser_update(uint32_t text_x);
void join_character_chooser_take_character(void);
void count_free_characters(uint32_t *p_characters_left, uint32_t *p_character, uint32_t *p_taken_bit);

/* scenes/ending.c: stage 0x11, the ending: the runners, the tower and the explosions, the flash to white, the credits (portraits, name plates, scrolling blocks), Eggman flying away and the three running across */
void build_ending_scene(uint32_t *p_write_index_address, uint32_t *p_tile_bank_bits, uint32_t *p_color, uint32_t *p_row_pairs_left, uint32_t *p_blocks_per_row, uint32_t *p_scene_actor);
void init_ending_scene_object(uint32_t object);
void ending_tower_animate(void);
void ending_debris_1_fly(void);
void ending_debris_2_fly(void);
void ending_debris_3_fly(void);
void ending_tower_blast_1(void);
void ending_tower_blast_2(void);
void ending_tower_blast_3(void);
void ending_horizon_blast_1(void);
void ending_horizon_blast_2(void);
void ending_horizon_blast_3(void);
void ending_horizon_blast_4(void);
void ending_horizon_blast_5(void);
void ending_horizon_blast_6(void);
void ending_horizon_blast_7(void);
void ending_horizon_blast_8(void);
void ending_horizon_blast_9(void);
void start_ending_blast(void);
void ending_big_explosion(void);
void ending_flash_to_white(void);
void animate_horizon_blast(void);
void draw_ending_blast_frame_copy(uint32_t frame_entry);
void animate_tower_blast(void);
void draw_ending_blast_frame(uint32_t frame_entry);
void animate_ending_debris(uint32_t path);
void run_timed_spawns_2(uint32_t object);
void ending_horizon_show(void);
void ending_dust_cloud_rise(void);
void ending_sonic_run_forward(void);
void ending_ray_run_forward(void);
void ending_mighty_run_forward(void);
void ending_road_scroll(void);
void ending_credits_fade_in(void);
void ending_credits_spawner_run(void);
uint32_t load_credits_palettes(void);
void ending_music_play(void);
void ending_portrait_show(void);
void ending_name_plate_show(void);
void ending_credits_team_logo_scroll(void);
void ending_credits_director_scroll(void);
void scroll_credits_block(void);
void ending_credits_program_scroll(void);
void ending_credits_design_scroll(void);
void ending_credits_sound_scroll(void);
void ending_credits_voice_actor_scroll(void);
void ending_credits_special_thanks_scroll(void);
void scroll_credits_sprite(void);
void wrap_credits_scroll_timer(void);
void init_credits_sprite(void);
void run_timed_spawns_3(void);
void animate_ending_runner(uint32_t frame_entry);
void ending_window_open(void);
void ending_credits_fade_out(void);
void ending_eggman_scene_fade_in(void);
void ending_eggman_fly_in(void);
void init_eggman_smoke_puff(uint32_t piece);
void ending_eggman_turn(void);
void ending_eggman_scene_fade_out(void);
void ending_close_up_fade_in(void);
void ending_eggman_fly_away(void);
void ending_eggman_fly_away_spare_return(void);
void ending_sonic_run_across(void);
void ending_ray_run_across(void);
void ending_mighty_run_across(void);
void init_ending_runner_across(void);
void animate_ending_runner_across(void);

/* scenes/map.c: the map screen between stages (game mode 4): the wipe, the island map, the trail, the markers, Eggman */
uint32_t run_map_screen(uint32_t bottom_speed, uint32_t object);
void run_map_screen_wait_for_wipe(uint32_t edges_done);
void map_intro_update(void);
void move_map_stage_icon(void);
void draw_map_markers_and_trail(void);
void map_screen_draw_flipping_icon(void);
void map_screen_update(void);
void map_eggman_update(void);
void map_eggman_hands_update(void);
void map_eggman_draw_plain(void);
void map_eggman_draw_plain_2(void);
void draw_map_eggman(void);
void start_map_trail(void);
void next_map_trail_segment(uint32_t trail_point);
void draw_map_trail_dot(uint32_t object);
uint32_t draw_map_stage_markers(uint32_t badge_offset);
void blink_current_map_marker(void);
uint32_t start_window_wipe(uint32_t record);
void update_screen_wipe(uint32_t *p_clip_right, uint32_t *p_clip_top, uint32_t *p_clip_bottom, uint32_t *p_edges_done);

/* scenes/ranking.c: the ranking: entering initials at game over, loading and resetting the table, the TOP15 display */
void start_ranking_entry(void);
void enter_ranking_initials(uint32_t jump_offset);
void enter_ranking_initials_count_down(uint32_t button_bit);
void enter_ranking_initials_save_record(void);
uint32_t load_ranking(void);
uint32_t reset_ranking(void);
uint32_t copy_ranking_records(uint32_t source, uint32_t dest, uint32_t count);
uint32_t ascii_to_ranking_letter(uint32_t letter);
void start_ranking_display(uint32_t display, uint32_t *p_rows, uint32_t *p_source);
void build_ranking_display(void);
void ranking_title_spin_in(void);
void ranking_title_pause(void);
void ranking_title_rise(void);
void draw_ranking_title(void);
void ranking_display_scroll_in(void);
void ranking_display_hold(void);
void drift_ranking_background(void);
void ranking_display_end(void);
void ranking_row_update(void);

/* scenes/ring_tally.c: the ring tally after a stage (game mode 0x1D): the total and the players' panels */
void start_ring_tally(uint32_t *p_stage_rings_3, uint32_t *p_player_3_out_flags, uint32_t *p_ring_total, uint32_t *p_p2_object, uint32_t *p_p3_object, uint32_t *p_object);
void pick_ring_bonus_players(uint32_t *p_player_1_rings, uint32_t *p_player_2_rings, uint32_t *p_player_3_rings);
void ring_tally_percent_update(void);
void ring_tally_percent_set_digits(uint8_t shown_percent);
void ring_tally_percent_draw_digits(void);
void update_ring_tally_percent(void);
void ring_tally_end_sound_wait(void);
void ring_tally_ticker_update(void);
void ring_tally_player_1_update(void);
void ring_tally_player_2_update(void);
void ring_tally_player_3_update(void);
void ring_tally_player_3_update_spare_return(void);
void build_ring_tally_panel(uint32_t character);
void update_ring_tally_panel(void);
void update_ring_tally_panel_count_up(void);
void update_ring_tally_panel_tail(void);
void cycle_ring_tally_backdrop_palette(void);

/* scenes/title.c: the title screen: the SEGA logo, the emblem, the land, the craft, Sonic's loop, the clouds and the sky */
void run_title_screen(uint32_t text_position, uint32_t *p_color, uint32_t *p_row_pairs_left, uint32_t *p_blocks_per_row, uint32_t *p_text);
void title_emblem_animate(void);
void title_emblem_animate_spare_return(void);
void draw_title_emblem_part(void);
void title_land_slide(void);
void timed_spawner_run(void);
void title_flying_craft_move(void);
void title_smoke_puff_animate(void);
void init_title_puff_sprite(uint32_t puff);
void title_clouds_1_drift(void);
void title_clouds_2_drift(void);
void title_clouds_3_drift(void);
void init_title_cloud_block(uint32_t cloud);
void drift_title_cloud(void);
void drift_title_cloud_2(void);
void title_sky_wave(void);
void run_sega_logo(uint32_t logo_block, uint32_t *p_color, uint32_t *p_row_pairs_left, uint32_t *p_blocks_per_row, uint32_t *p_lower_row_cursor);
void set_sega_logo_sprite(void);

/* stage/camera.c: the stage view, the scroll and the camera: the view set-up and the tile sets around it, the scroll modes and the screen edges the players push, the camera's speeds, shake and path along the sections, the fades between stages, the start section of the demos and the unused scroll skip panel */
uint32_t compute_camera_ground_speed(uint32_t octant);
uint32_t compute_camera_slope_speed(uint32_t octant, uint32_t slope_factor);
void init_stage_view(uint32_t *p_direction_y, uint32_t *p_direction_x, uint32_t *p_count, uint32_t *p_stage_offset);
void update_stage_tile_layers(uint32_t *p_shifted_tile_set, uint32_t *p_copy_entry, uint32_t *p_columns_left, uint32_t *p_palette_count, uint32_t *p_stage_number, uint32_t *p_row_skip, uint32_t *p_cycle, uint32_t *p_block_cursor, uint32_t *p_dest);
void reload_changed_tile_set(uint32_t *p_shifted_tile_set, uint32_t *p_slots_left, uint32_t *p_set_shift, uint32_t *p_slot_tile_set, uint32_t *p_loaded_shift, uint32_t *p_script, uint32_t *p_dest);
void load_tile_set(uint32_t tile_set, uint32_t *p_count, uint32_t *p_stage_offset, uint32_t *p_script, uint32_t *p_dest);
uint32_t get_tile_set_script_bank(uint32_t script);
uint32_t get_tile_set_list_bank(uint32_t script_list);
void get_tile_set_list(uint32_t tile_set, uint32_t *p_stage_offset, uint32_t *p_script_list);
void clamp_camera_pixels(void);
void update_scroll(uint32_t *p_position, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_second_player_object, uint32_t *p_third_player_object, uint32_t *p_end_script, uint32_t *p_dest);
uint32_t is_player_pushing_edge(uint32_t pushing, uint32_t object);
uint32_t is_player_at_diagonal_edge_30(uint32_t at_edge, uint32_t object, uint16_t edge_offset);
uint32_t is_player_at_diagonal_edge_f0(uint32_t at_edge, uint32_t object, uint16_t edge_offset);
uint32_t is_player_at_diagonal_edge_c0(uint32_t at_edge, uint32_t object, uint16_t edge_offset);
uint32_t is_player_at_diagonal_edge_60(uint32_t at_edge, uint32_t object, uint16_t edge_offset);
uint32_t is_player_at_right_edge(uint32_t at_edge, uint32_t object);
uint32_t is_player_at_left_edge(uint32_t at_edge, uint32_t object);
uint32_t is_player_at_top_edge(uint32_t at_edge, uint32_t object);
uint32_t is_player_at_bottom_edge(uint32_t at_edge, uint32_t object);
void set_screen_push_edges(uint32_t quadrant_bits, uint32_t *p_count, uint32_t *p_sine_entry);
uint32_t is_player_facing_scroll(uint32_t facing, uint16_t heading, uint16_t sine_entry);
void is_direction_in_quadrant(uint32_t count, uint32_t *p_found, uint32_t *p_sine_entry);
void scroll_slowing_down(uint32_t *p_other_list, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_range, uint32_t *p_quadrant_cursor);
void scroll_speeding_up(uint32_t *p_other_list, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_range, uint32_t *p_quadrant_cursor);
void scroll_at_scroll_speed(uint32_t *p_other_list, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_range, uint32_t *p_quadrant_cursor);
void advance_scroll_unless_ended(uint32_t *p_other_list, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_range, uint32_t *p_quadrant_cursor);
void advance_scroll(uint32_t *p_other_list, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_range, uint32_t *p_quadrant_cursor);
void set_camera_velocity(uint32_t *p_scroll_y, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_range, uint32_t *p_quadrant_cursor);
void update_background_scroll(uint32_t *p_fast_scroll_start, uint32_t *p_scroll_y, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_range, uint32_t *p_quadrant_cursor);
void update_scroll_at_end(uint32_t *p_position, uint32_t *p_speed, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_end_script, uint32_t *p_dest);
void spawn_debug_sprite_mover(uint32_t object);
void debug_sprite_mover_update(void);
void start_stage_view(uint32_t *p_direction_y, uint32_t *p_direction_x, uint32_t *p_count, uint32_t *p_stage_offset);
void call_run_map_screen(uint32_t object);
void run_stage_05_switch(uint32_t speed, uint32_t *p_scroll_y, uint32_t *p_speed_value, uint32_t *p_dest);
uint32_t update_fade(uint32_t delta);
void update_stage_00_exit_scene(uint32_t dest, uint32_t *p_speed_value, uint32_t *p_script);
void clamp_colour_offsets(void);
uint32_t update_camera_with_shake(void);
uint32_t set_nbg0_scroll_from_camera(uint32_t scroll_x);
uint32_t original_set_nbg0_scroll_from_camera(uint32_t scroll_x);
uint32_t update_camera_view(void);
uint32_t update_camera_view_y(uint32_t y);
uint32_t move_camera_along_path(uint32_t speed);
void advance_camera_scroll_x_y(uint32_t speed);
void advance_camera_x_y(uint32_t speed);
void advance_camera_y_scroll(uint32_t speed);
void advance_camera_y(uint32_t speed);
void advance_camera_x_scroll(uint32_t speed);
void advance_camera_x(uint32_t speed);
void advance_scroll_position(uint16_t speed);
void snap_camera_to_section_end(void);
void run_scroll_skip_mode(void);
void scroll_skip_next_point(void);
void scroll_skip_previous_point(void);
void scroll_skip_check_exit(void);
void scroll_skip_erase_panel(void);
void scroll_skip_check_call(void);
void move_camera_to_start_section(uint32_t *p_y, uint32_t *p_section_offset, uint32_t *p_stage_index);
void load_camera_start_section(uint32_t *p_section_offset, uint32_t *p_stage_index);
void index_stage_list_pair(uint32_t section_offset, uint32_t stage_offset, uint32_t *p_first_entry, uint32_t *p_second_entry);
uint32_t scroll_skip_x_position_cell(void);
uint32_t scroll_skip_y_position_cell(void);
uint32_t scroll_skip_total_cell(void);
void scroll_skip_draw_values(void);
void scroll_skip_print_panel(void);
void clear_bitmap_lower_half(void);

/* stage/events.c: the scripted game modes run_game_mode jumps into and what they spawn: platforms, rocks, lightning, message boxes, the escape alarm and countdown */
void escape_alarm_flash(void);
void event_0f_start(void);
void event_0f_stop_scroll(void);
void event_0f_show_messages(uint32_t *p_frames, uint32_t *p_box);
void spawn_falling_rocks(uint32_t object);
void falling_rock_bounce(void);
void event_0c_start(uint32_t *p_block_offset, uint32_t *p_slope_height, uint32_t *p_object);
uint32_t event_0c_first_quake(uint32_t write_index_address);
void event_0c_second_quake(uint32_t *p_part_size, uint32_t *p_point_y, uint32_t *p_z, uint32_t *p_wall);
void event_0c_finish(void);
void update_stage_05_event(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void stage_05_event_show_message_11(uint32_t part_size, uint32_t box);
void stage_05_event_show_message_12(uint32_t part_size, uint32_t box);
void stage_05_event_show_message(uint32_t part_size, uint16_t screen_y, uint16_t kind, uint32_t box, uint32_t *p_sag, uint32_t *p_frames, uint32_t *p_z, uint32_t *p_platform);
void stage_05_event_step_3_frame(uint32_t part_size, uint32_t wall, uint32_t *p_sag, uint32_t *p_point_y, uint32_t *p_z, uint32_t *p_platform);
void stage_00_platform_start(void);
void stage_00_platform_stand(void);
void stage_00_platform_break(void);
void stage_00_geyser_rise(void);
void stage_00_geyser_column_start(void);
void stage_00_geyser_column_rise(void);
void rock_debris_fly(void);
void event_1c_follow(void);
void event_1c_stop(void);
void event_1c_scroll(void);
void update_ending(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_platform);
void spawn_stage_06_lightning(uint32_t *p_record, uint32_t *p_bolt);
void stage_06_lightning_animate(void);
uint32_t spawn_message_box(uint16_t screen_x, uint16_t screen_y, uint16_t kind, uint16_t frames, uint32_t box);
void spawn_message_box_2(uint16_t screen_x, uint16_t screen_y, uint16_t kind, uint16_t frames, uint32_t box);
void place_message_box(uint16_t screen_x, uint16_t screen_y, uint32_t kind, uint16_t frames, uint32_t box);
void original_place_message_box(uint16_t screen_x, uint16_t screen_y, uint32_t kind, uint16_t frames, uint32_t box);
void message_box_show(void);
void start_escape_countdown(uint32_t *p_free_stack, uint32_t *p_count, uint32_t *p_digit);
void update_escape_countdown(void);
void start_escape_alarm_flash(uint32_t flash);

/* stage/game_modes.c: the game modes (run_game_mode) and what a stage frame runs: starting a stage, layer blending, the stage clear check, the player summary, stage slots and events, restart points, the player objects, the GAME OVER banner and the demo prompt */
void run_game_mode(uint32_t pressed, uint32_t position, uint32_t speed, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void original_run_game_mode(uint32_t pressed, uint32_t position, uint32_t speed, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_start_game(uint32_t *p_count, uint32_t *p_list_cursor);
void start_stage(uint32_t stage_offset, uint32_t *p_write_index_address, uint32_t *p_floor_block, uint32_t *p_bounds_offset, uint32_t *p_corners_left, uint32_t *p_palette_record, uint32_t *p_source, uint32_t *p_object);
void game_mode_play_stage(uint32_t pressed, uint32_t position, uint32_t in_play_count, uint32_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_intro(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_continue(uint32_t position, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
uint32_t game_mode_stage_end_fade(uint32_t bottom_speed, uint32_t object);
void game_mode_screen_wipe(uint32_t position, uint32_t speed, uint32_t edges_done, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_stage_clear(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_game_over(uint32_t box_edge, uint32_t position, uint16_t scale, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_character_select(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_stage_results(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_stage_change_fade(uint32_t delta, uint32_t position, uint32_t in_play_count, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_you_failed(uint32_t box_edge, uint32_t position, uint32_t in_play_count, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void check_stage_select_buttons(void);
void game_mode_stage_select(uint32_t *p_count, uint32_t *p_list_cursor);
void original_game_mode_stage_select(uint32_t *p_count, uint32_t *p_list_cursor);
void game_mode_event_09(uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_0A(uint32_t pressed, uint32_t position, uint32_t speed, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_0C(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_0D(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_1A(uint32_t pressed, uint32_t position, uint32_t in_play_count, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_0F(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_10(uint32_t random_value, uint32_t object, uint32_t *p_rolls_left, uint32_t *p_words_left, uint32_t *p_list_cursor);
void game_mode_event_12(uint32_t pressed, uint32_t position, uint32_t done_count, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_13(uint32_t pressed, uint32_t position, uint32_t in_play_count, uint32_t edges_done, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_14(uint32_t pressed, uint32_t position, uint32_t unbounced_count, uint16_t x, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_15(uint32_t pressed, uint32_t position, uint32_t speed, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_16(uint32_t box_edge, uint32_t position, uint32_t in_play_count, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_18(uint32_t position, uint32_t speed, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_19(uint32_t pressed, uint32_t position, uint32_t in_play_count, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_1C(uint32_t pressed, uint32_t position, uint32_t in_play_count, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void game_mode_event_1F(uint32_t pressed, uint32_t position, uint32_t in_play_count, uint16_t next_scroll_position, uint32_t object, uint32_t *p_speed_value, uint32_t *p_count, uint32_t *p_cycle, uint32_t *p_list_cursor);
void cleared_banner_wait(void);
void stage_clear_banner_reveal(void);
void stage_clear_banner_hold(void);
void spawn_banner_sparkle(uint16_t offset_x);
void banner_sparkle_animate(void);
void banner_letter_spin(void);
void apply_stage_layer_blending(uint32_t *p_layer_bit, uint32_t *p_count);
void check_stage_clear(uint32_t *p_count, uint32_t *p_finished_flag, uint32_t *p_status);
uint32_t clear_player_blocks(void);
uint32_t update_grey_screen(void);
void update_player_summary(uint32_t *p_in_play_count, uint32_t *p_count, uint32_t *p_cursor, uint32_t *p_player_object);
void continue_to_next_stage_slot(uint32_t *p_table_offset, uint32_t *p_link_record, uint32_t *p_block);
void load_stage_map_pointers(uint32_t *p_table_offset, uint32_t *p_bounds_list);
void run_stage_events(uint32_t *p_table_offset, uint32_t *p_event);
void reset_trackball_step(uint32_t player_number);
void read_trackball_step(uint32_t *p_player_number, uint32_t *p_trackball);
uint32_t update_restart_point(uint32_t position);
uint32_t start_player_objects_alt(uint32_t object);
uint32_t start_player_objects(uint32_t object);
void reset_objects_from_list(uint32_t object, uint32_t *p_player_number, uint32_t *p_handler_cursor);
void draw_game_over_banner(void);
uint32_t blink_demo_prompt(uint32_t prompt_frame, uint32_t credit_block);

/* stage/layers.c: the stage's background: the palettes animated per stage, the palette sets and the backdrop, and the tilemap layers NBG0-NBG3 (pictures, mixing, per-stage scroll) */
void update_stage_06_background(uint32_t random_value, uint32_t dest, uint32_t *p_rolls_left, uint32_t *p_words_left, uint32_t *p_source);
void animate_stage_palette(uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_cycle, uint32_t *p_source, uint32_t *p_dest);
void skip_stage_palette_animation(void);
void animate_palette_stage_10(uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_cycle, uint32_t *p_source, uint32_t *p_dest);
void animate_palette_stage_0c(uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_cycle, uint32_t *p_source, uint32_t *p_dest);
void animate_palette_stage_0d_0e(uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_cycle, uint32_t *p_source, uint32_t *p_dest);
void animate_palette_stage_0f(uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_cycle, uint32_t *p_source, uint32_t *p_dest);
void animate_palette_stage_0a(uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_cycle, uint32_t *p_source, uint32_t *p_dest);
void animate_palette_stage_09(uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_cycle, uint32_t *p_source, uint32_t *p_dest);
void animate_palette_stage_04(uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_cycle, uint32_t *p_source, uint32_t *p_dest);
void cycle_palette(uint32_t cycle, uint16_t halfwords, uint32_t *p_copy_offset, uint32_t *p_copy_entry, uint32_t *p_palette_count, uint32_t *p_source, uint32_t *p_dest);
uint32_t cycle_palette_set_0(uint32_t source);
uint32_t cycle_palette_set_1(uint32_t source);
uint32_t cycle_palette_set(uint32_t source);
void load_stage_palette_set(uint32_t *p_tile_bank_bits, uint32_t *p_dest);
void load_palette_set_and_backdrop(uint32_t stage_index, uint32_t *p_tile_bank_bits, uint32_t *p_source, uint32_t *p_dest);
void set_backdrop_color_19aa(void);
uint32_t init_nbg0_picture_screen(void);
void show_winners_dont_use_drugs_screen(void);
void show_recycle_it_screen(void);
void show_nbg0_picture(uint32_t *p_copy_entry, uint32_t *p_rows, uint32_t *p_source, uint32_t *p_dest);
uint32_t set_stage_layer_mixing(void);
uint32_t init_nbg1_layer(uint32_t dest);
void update_nbg1_scroll(void);
void skip_nbg1_scroll(void);
void set_nbg1_scroll_to_camera(void);
uint32_t init_nbg2_layer(uint32_t dest);
uint32_t update_nbg2_scroll(uint32_t position);
void set_nbg2_scroll_to_camera(void);
void skip_nbg2_scroll(void);
void set_nbg2_scroll_to_camera_2(void);
uint32_t set_nbg2_scroll_stages_03_07(void);
void set_nbg2_scroll_stage_04(void);
void init_nbg3_layer(uint32_t dest);
void init_nbg3_layer_cleared_pages(uint32_t dest);
void set_nbg3_pages_5_6(void);
void set_nbg3_page_5_flags(uint32_t *p_count, uint32_t *p_dest);
void update_nbg3_scroll(uint32_t *p_scroll_y, uint32_t *p_quadrants, uint32_t *p_speed_value, uint32_t *p_next_scroll_position, uint32_t *p_quadrant_cursor);
void select_nbg3_pages(uint32_t *p_block_pages, uint32_t *p_quadrants, uint32_t *p_byte_mask, uint32_t *p_shift, uint32_t *p_quadrant_cursor);
void get_nbg3_block(void);
void load_stage_palette(uint32_t *p_palette_record, uint32_t *p_source, uint32_t *p_dest);

/* system/coins.c: coins and credits: the coin inputs and counters, the credits and start prompts drawn outside a game */
void apply_settings(void);
void update_coins(void);
void pulse_coin_counter(uint32_t counter_bit, uint32_t counter_state, uint16_t service_credits, uint16_t coin_credits);
uint32_t add_service_credit(uint32_t service_credits, uint32_t credit_block, uint8_t max_credits);
uint32_t add_coin(uint32_t chute_offset, uint32_t pending_offset, uint32_t bookkeeping_chute, uint32_t coin_credits, uint32_t credit_block, uint8_t max_credits);
void save_credits(void);
void copy_credit_counts(uint32_t dest, uint32_t credit_block);
void draw_attract_credits(uint32_t *p_credits, uint32_t *p_blink_bit, uint32_t *p_message_text, uint32_t *p_text_position);
void erase_attract_credits(void);
void blink_start_prompt(uint32_t credit_block, uint32_t prompt_texts, uint32_t *p_blink_bit, uint32_t *p_text, uint32_t *p_text_position);
void original_blink_start_prompt(uint32_t credit_block, uint32_t prompt_texts, uint32_t *p_blink_bit, uint32_t *p_text, uint32_t *p_text_position);
void erase_start_prompt(uint32_t text_position, uint32_t prompt_texts);
void draw_credit_count(uint32_t credit_block, uint32_t *p_credits, uint32_t *p_coins_per_credit, uint32_t *p_text, uint32_t *p_text_position);
void draw_credit_count_now(uint32_t credit_block, uint32_t *p_credits, uint32_t *p_coins_per_credit, uint32_t *p_text, uint32_t *p_text_position);
void original_draw_credit_count_now(uint32_t credit_block, uint32_t *p_credits, uint32_t *p_coins_per_credit, uint32_t *p_text, uint32_t *p_text_position);
void build_fraction_glyph(uint32_t numerator, uint32_t denominator, uint32_t *p_numerator_top_rows, uint32_t *p_numerator_bottom_rows, uint32_t *p_denominator_top_rows, uint32_t *p_denominator_bottom_rows);
void erase_credit_count(uint32_t text_position);
uint32_t add_to_credit_pool(uint32_t credits_to_add);
void take_from_credit_pool(uint8_t credits_to_take);

/* system/main.c: the machine's main program: power-on and boot, the frame loop, the attract mode and the system modes, the frame wait and the controls, the interrupt handlers, the reset vector */
void boot(void);
void run_frame(uint32_t pressed, uint32_t released, uint32_t input_cursor, uint32_t count, uint32_t trackball_port, uint32_t trackball_cursor, uint32_t *p_scale, uint32_t *p_cursor, uint32_t *p_height);
void run_frame_check_p2_start(uint32_t credits, uint32_t blink_bit, uint32_t credits_needed, uint32_t count, uint32_t message_text, uint32_t text_position, uint32_t *p_scale, uint32_t *p_cursor, uint32_t *p_height);
void run_frame_start_game(uint32_t credits, uint32_t blink_bit, uint32_t credits_needed, uint32_t count, uint32_t message_text, uint32_t text_position, uint32_t *p_scale, uint32_t *p_cursor, uint32_t *p_height);
void original_run_frame_start_game(uint32_t credits, uint32_t blink_bit, uint32_t credits_needed, uint32_t count, uint32_t message_text, uint32_t text_position, uint32_t *p_scale, uint32_t *p_cursor, uint32_t *p_height);
void attract_title(uint32_t *p_color, uint32_t *p_row_pairs_left, uint32_t *p_blocks_per_row, uint32_t *p_text);
void original_attract_title(uint32_t *p_color, uint32_t *p_row_pairs_left, uint32_t *p_blocks_per_row, uint32_t *p_text);
void attract_ranking(uint32_t *p_rows, uint32_t *p_source);
void attract_demo_1(uint32_t pressed, uint32_t released, uint32_t input_cursor, uint16_t cursor, uint32_t trackball_cursor, uint32_t *p_scale, uint32_t *p_count, uint32_t *p_height, uint32_t *p_trackball_port);
void attract_demo_2(uint32_t pressed, uint32_t released, uint32_t input_cursor, uint16_t cursor, uint32_t trackball_cursor, uint32_t *p_scale, uint32_t *p_count, uint32_t *p_height, uint32_t *p_trackball_port);
void advance_attract_screen(void);
void original_advance_attract_screen(void);
void init_system(uint32_t *p_polynomial, uint32_t *p_words_left);
void init_mixer(void);
void init_io_ports(void);
void clear_work_ram(void);
uint32_t init_game_settings(void);
void delay_after_reset(void);
uint32_t wait_for_frames(void);
void wait_for_frame(uint32_t *p_pressed, uint32_t *p_released, uint32_t *p_input_cursor, uint32_t *p_count, uint32_t *p_trackball_port, uint32_t *p_trackball_cursor);
void read_controls(uint32_t *p_inputs, uint32_t *p_pressed, uint32_t *p_released, uint32_t *p_input_cursor, uint32_t *p_count, uint32_t *p_trackball_port, uint32_t *p_trackball_cursor);
uint32_t play_demo_buttons(uint32_t inputs);
void play_demo_trackballs(uint32_t *p_count, uint32_t *p_demo_cursor, uint32_t *p_trackball_cursor);
void pause_on_start_3(void);
void split_frame_count(uint32_t frames, uint32_t frames_high, uint32_t *p_seconds, uint32_t *p_minutes, uint32_t *p_hours, uint32_t *p_days);
void attract_warning(uint32_t *p_pixels, uint32_t *p_text);
void original_attract_warning(uint32_t *p_pixels, uint32_t *p_text);
void system_mode_idle(void);
void original_system_mode_idle(void);
void wait_attract_timer(void);
void irq_vblank_start(void);
void irq_vblank_end(void);
void irq_sound(void);
void irq_timer0(void);
void irq_timer1(void);
void int_default(uint32_t *p_source, uint32_t *p_dest, uint32_t *p_copies_left, uint32_t *p_copy_entry);
void int_vector_02(uint32_t *p_source, uint32_t *p_dest, uint32_t *p_copies_left, uint32_t *p_copy_entry);
void run_vblank_copies(uint32_t *p_source, uint32_t *p_dest, uint32_t *p_copies_left, uint32_t *p_copy_entry);
void send_sound_command(void);
void read_service_inputs(void);
void count_frames_and_check_test_switch(void);
void reset(void);

/* system/settings.c: what the board keeps when it is off: the settings in the 93C46 EEPROM and the bookkeeping in the backup RAM, with their checksums */
uint32_t compute_crc16_strided(uint32_t crc, uint32_t count, uint32_t data, uint32_t byte_gap);
void eeprom_lock(void);
void eeprom_unlock(void);
uint32_t eeprom_read_word_at(uint32_t data, uint8_t command);
void load_settings(uint32_t crc);
void eeprom_read_all_and_enable_interrupts(uint32_t data);
void eeprom_read_all(uint32_t data);
void eeprom_write_word_at(uint16_t data, uint8_t command);
void eeprom_save_and_lock(uint32_t *p_command, uint32_t *p_words_left);
void eeprom_save(uint32_t *p_command, uint32_t *p_words_left);
void eeprom_read_word(uint8_t command, uint32_t port_f, uint32_t port_d, uint32_t *p_data, uint32_t *p_lines);
uint32_t eeprom_write_word(uint32_t data, uint32_t lines, uint8_t command, uint32_t port_f, uint32_t port_d);
uint32_t eeprom_send_command(uint32_t lines, uint8_t command, uint32_t port_d);
void eeprom_select(uint32_t *p_lines, uint32_t *p_port_f, uint32_t *p_port_d);
uint32_t compute_eeprom_backup_checksum(void);
void compute_eeprom_checksum(uint32_t *p_crc, uint32_t *p_polynomial);
void compute_eeprom_crc(uint32_t *p_crc, uint32_t *p_polynomial);
uint32_t eeprom_deselect(uint32_t lines, uint32_t port_d);
uint32_t eeprom_set_lines(uint32_t data, uint8_t lines, uint32_t port_d);
void load_bookkeeping(void);
void reset_bookkeeping(void);
uint32_t update_bookkeeping_checksum(void);
void compute_bookkeeping_crc(uint32_t *p_crc, uint32_t *p_data);
void compute_crc16(uint32_t count, uint32_t *p_crc, uint32_t *p_data, uint32_t *p_polynomial);
uint32_t compute_crc16_alternate_bytes(uint32_t data, uint32_t count);
void add_play_time(void);
void record_player_game(void);

/* system/sound.c: the sound the game asks the Z80 for: init_sound, play_sound and the sound queue */
uint32_t init_sound(void);
void set_port_d_bit_3_if_sound_allowed(void);
void queue_coin_sound(void);
void play_sound(uint8_t sound_id, uint32_t *p_write_index, uint32_t *p_write_index_address);
void original_play_sound(uint8_t sound_id, uint32_t *p_write_index, uint32_t *p_write_index_address);
void queue_sound(uint8_t sound_id, uint32_t *p_write_index, uint32_t *p_write_index_address);

/* system/test_mode.c: the test mode: the menu, the memory, input and sound tests, the CRT test, the game and coin assignments, the bookkeeping screen, the backup clear, the output test, the exit */
void start_test_mode(uint32_t *p_color, uint32_t *p_blocks_per_row);
void run_test_mode(uint32_t pressed, uint16_t count, uint32_t *p_color, uint32_t *p_blocks_per_row);
void test_menu(void);
void draw_test_menu(void);
void toggle_test_continue_mode(void);
void test_memory(uint32_t *p_results_left, uint32_t *p_blocks_per_row);
void check_rom_checksums(void);
void original_check_rom_checksums(void);
void test_work_ram(void);
void test_work_ram_verify(void);
void test_video_ram(void);
void test_video_ram_verify(void);
void test_sprite_ram(void);
void test_sprite_ram_verify(void);
void test_palette_ram(void);
void test_palette_ram_verify_first_half(void);
void test_palette_ram_fill_second_half(void);
void test_palette_ram_verify_second_half(void);
void test_sound_ram(void);
void test_sound_ram_verify(void);
void test_inputs(uint16_t count, uint32_t *p_panel_color, uint32_t *p_blocks_per_row);
void move_input_test_cursors(uint32_t count, uint32_t text, uint32_t *p_cursors_left, uint32_t *p_height);
uint32_t get_trackball_quadrant(uint8_t dx, uint8_t dy, uint32_t quadrant);
void test_sound(void);
void wrap_sound_test_number(void);
void wrap_sound_test_number_down(void);
void test_crt(uint32_t start_y, uint32_t *p_color, uint32_t *p_blocks_per_row);
void test_game_assignments(uint32_t *p_color, uint32_t *p_blocks_per_row);
void draw_vitality_setting(uint32_t *p_color, uint32_t *p_blocks_per_row);
void draw_difficulty_setting(uint32_t *p_color, uint32_t *p_blocks_per_row);
uint32_t test_coin_assignments(uint32_t color);
void test_coin_assignments_draw_main_page(void);
void test_coin_assignments_spare_return(void);
void apply_coin_setting(void);
void draw_coin_setting_number(uint32_t setting_number);
uint32_t test_coin_assignments_manual_page(uint32_t color);
void test_coin_assignments_spare_return_2(void);
void clamp_coin_setting(uint32_t setting);
uint32_t draw_coin_credit_table(void);
uint32_t draw_coin_credit_cell(uint16_t multiplier, uint16_t coins, uint32_t cell_position);
void draw_test_hex_4(uint32_t value, uint32_t text_position);
void draw_test_hex_2(uint32_t value, uint32_t text_position);
void test_bookkeeping(void);
uint32_t test_backup_clear(uint32_t polynomial);
void test_outputs(void);
void exit_test_mode(void);
void flip_test_coordinates(uint32_t *p_left, uint32_t *p_top, uint32_t *p_right, uint32_t *p_bottom);
void blink_test_cursor(void);
void draw_blinking_test_cursor(uint32_t cursor_char);
void erase_test_cursor(uint32_t cursor_positions);
void set_test_cursor(void);
uint32_t check_moving_seat_dip(uint32_t words_left);

/* video/bitmap.c: the bitmap layer: clearing it, its address, scroll and window, pixels, lines, spans and rectangles; an unused packed picture decoder and LZ unpacker */
void draw_packed_picture(uint32_t picture);
void init_picture_unpacker(uint32_t *p_colour_cache, uint32_t *p_newest_slot, uint32_t *p_done_bits);
void init_picture_colour_cache(uint32_t colour_cache);
uint32_t read_picture_size(uint32_t stream);
void unpack_picture_pixels(uint32_t stream, uint32_t width, uint32_t colour_cache, uint32_t newest_slot, uint32_t done_bits);
void read_picture_colour(uint32_t stream, uint32_t colour_cache, uint32_t *p_colour, uint32_t *p_newest_slot);
void rotate_bitmap_for_monitor_flip(void);
void init_bitmap_layer(uint8_t is_8bpp);
void get_bitmap_address_2(uint16_t x, uint16_t y);
void set_bitmap_scroll_2(uint16_t scroll_x, uint16_t scroll_y, uint8_t is_8bpp);
void set_bitmap_window_2(uint16_t left, uint16_t top, uint16_t right, uint16_t bottom);
void set_bitmap_clip_2(uint16_t left, uint16_t top, uint16_t right, uint16_t bottom);
void unpack_lz_bytes(uint32_t packed, uint32_t dest);
void clear_bitmap_layer(uint8_t is_8bpp, uint32_t *p_top, uint32_t *p_color, uint32_t *p_inner_count, uint32_t *p_row_pairs_left, uint32_t *p_blocks_per_row, uint32_t *p_lower_row_cursor);
void get_bitmap_address(uint16_t x, uint16_t y);
void set_bitmap_scroll(uint16_t scroll_x, uint16_t scroll_y, uint8_t is_8bpp);
void set_bitmap_window(uint16_t left, uint16_t top, uint16_t right, uint16_t bottom);
void set_bitmap_clip(uint16_t left, uint16_t top, uint16_t right, uint16_t bottom);
void draw_pixel(uint32_t x, uint32_t y, uint8_t color);
uint32_t read_pixel(uint32_t x, uint32_t y);
void draw_line(uint32_t end_x, uint32_t end_y, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_color, uint32_t *p_unclipped_y);
void fill_span_8bpp(uint32_t length, uint32_t *p_blocks, uint32_t *p_pixel_address, uint32_t *p_color);
uint32_t draw_vertical_line_8bpp(uint32_t pixel_address, uint8_t color, uint32_t length);
void draw_vertical_span_8bpp(uint32_t row_step, uint8_t color, uint32_t *p_pixel_address, uint32_t *p_length);
uint32_t draw_line_shallow_even_pixel(uint32_t pixel_address, uint16_t fraction, uint8_t low_nibble_color, uint8_t high_nibble_color, uint16_t slope, uint32_t steps_left, uint8_t high_nibble_mask, uint32_t row_step);
uint32_t draw_line_shallow_odd_pixel(uint32_t pixel_address, uint16_t fraction, uint8_t low_nibble_color, uint8_t high_nibble_color, uint16_t slope, uint32_t steps_left, uint8_t high_nibble_mask, uint32_t row_step);
uint32_t draw_line_shallow_set_high_nibble(uint8_t pixel_byte, uint32_t pixel_address, uint16_t fraction, uint8_t low_nibble_color, uint8_t high_nibble_color, uint16_t slope, uint32_t steps_left, uint8_t high_nibble_mask, uint32_t row_step);
void fill_span_4bpp(uint16_t end_x, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_color, uint32_t *p_length);
void draw_vertical_span_4bpp(uint16_t start_x, uint32_t row_step, uint32_t *p_start_y, uint32_t *p_color, uint32_t *p_length);
void draw_vertical_span_4bpp_here(uint8_t start_x, uint32_t row_step, uint32_t *p_pixel_address, uint32_t *p_color, uint32_t *p_length);
void draw_dotted_line_8bpp(uint32_t start_x, uint32_t start_y, uint32_t end_x, uint32_t end_y, uint8_t color);
void draw_rect_outline(uint32_t left, uint32_t top, uint32_t width, uint32_t height, uint32_t color);
uint32_t draw_rect_sides_8bpp(uint32_t pixel_address, uint32_t width, uint32_t height, uint8_t color);
uint32_t draw_rect_top_bottom_8bpp(uint32_t pixel_address, uint32_t width, uint32_t height, uint32_t color);
void fill_rect(uint32_t top, uint32_t right, uint32_t bottom, uint32_t *p_left, uint32_t *p_color, uint32_t *p_blocks_per_row);
void fill_rect_unclipped(uint32_t right, uint32_t bottom, uint32_t *p_left, uint32_t *p_top, uint32_t *p_color, uint32_t *p_inner_count, uint32_t *p_row_pairs_left, uint32_t *p_blocks_per_row, uint32_t *p_lower_row_cursor);

/* video/shapes.c: shapes on the bitmap layer, mostly unused: triangles, quadrilaterals, circles, flood fill, saved rectangles, and the clipping the lines and rectangles use */
void fill_triangle(uint32_t top_x, uint32_t top_y, uint32_t middle_x, uint32_t middle_y, uint32_t bottom_x, uint32_t bottom_y, uint8_t color);
void fill_triangle_sorted(uint32_t top_x, uint32_t top_y, uint32_t middle_x, uint32_t middle_y, uint32_t bottom_x, uint32_t bottom_y, uint8_t color, uint32_t span_cursor);
void fill_flat_top_triangle(uint32_t left_x, uint32_t top_y, uint32_t right_x, uint32_t bottom_x, uint32_t height, uint8_t color, uint32_t span_cursor);
void fill_span_list_from_r8(uint32_t span_count, uint8_t polygon_color);
void fill_span_list(uint32_t span_count, uint32_t color);
void fill_quad(uint32_t left_x, uint32_t top_y, uint32_t second_x, uint32_t second_y, uint32_t third_x, uint32_t third_y, uint32_t bottom_x, uint32_t bottom_y, uint8_t fill_color);
void draw_circle_polygon(uint32_t center_x, uint32_t center_y, uint32_t radius, uint8_t circle_color, uint32_t color);
void draw_circle(uint16_t x, uint16_t y, uint16_t radius, uint8_t color);
void plot_circle_point_4bpp(uint32_t point_x, uint32_t point_y, uint8_t high_color, uint8_t low_color, uint32_t bitmap_base, uint16_t window_top, uint16_t window_right, uint16_t window_bottom);
void plot_circle_point_8bpp(uint32_t point_x, uint32_t point_y, uint8_t color, uint32_t bitmap_base, uint16_t window_top, uint16_t window_right, uint16_t window_bottom);
void flood_fill(uint16_t seed_x, uint16_t seed_y, uint8_t fill_color, uint8_t border_color);
void flood_fill_push_span(uint8_t border_color, uint32_t window_left, uint32_t window_right, uint8_t direction, uint32_t left_x, uint8_t y, uint32_t fill_pattern, uint32_t *p_right_address, uint32_t *p_right_x);
void flood_fill_span(uint8_t border_color, uint32_t window_left, uint32_t window_right, uint32_t fill_pattern, uint32_t *p_left_x, uint32_t *p_right_address, uint32_t *p_right_x);
void flood_fill_span_left_pair(uint32_t scan_count, uint8_t pixel_count, uint8_t border_color, uint32_t window_right, uint32_t fill_pattern, uint32_t seed_address, uint32_t *p_left_x, uint32_t *p_right_address, uint32_t *p_right_x);
void flood_fill_span_left_pixel(uint8_t pixel, uint32_t scan_count, uint8_t pixel_count, uint8_t border_color, uint32_t window_right, uint32_t fill_pattern, uint32_t seed_address, uint32_t *p_left_x, uint32_t *p_right_address, uint32_t *p_right_x);
void flood_fill_span_set_left_x(uint8_t border_color, uint32_t window_right, uint32_t fill_pattern, uint32_t seed_address, uint32_t *p_left_x, uint32_t *p_right_address, uint32_t *p_right_x);
void flood_fill_span_scan_right(uint8_t border_color, uint32_t window_right, uint32_t left_x, uint32_t fill_pattern, uint32_t seed_address, uint32_t *p_right_address, uint32_t *p_right_x);
void flood_fill_span_right_pair(uint32_t scan_count, uint8_t pixel_count, uint8_t border_color, uint32_t left_x, uint32_t fill_pattern, uint16_t seed_address, uint32_t *p_right_cursor, uint32_t *p_right_x);
void flood_fill_span_right_pixel(uint8_t pixel, uint32_t scan_count, uint8_t pixel_count, uint8_t border_color, uint32_t left_x, uint32_t fill_pattern, uint16_t seed_address, uint32_t *p_right_cursor, uint32_t *p_right_x);
void flood_fill_span_set_right_x(uint32_t left_x, uint32_t fill_pattern, uint16_t seed_address, uint32_t *p_right_cursor, uint32_t *p_right_x);
uint32_t flood_fill_span_fill_run(uint32_t left_x, uint32_t fill_pattern, uint32_t right_x);
uint32_t flood_fill_scan_seed_rows(uint8_t border_color, uint32_t window_left, uint16_t window_top, uint32_t window_right, uint16_t window_bottom, uint32_t scan_x, uint16_t y, uint32_t fill_pattern);
uint32_t flood_fill_scan_row(uint8_t border_color, uint32_t window_left, uint32_t window_right, uint32_t direction, uint8_t y, uint32_t fill_pattern);
uint32_t flood_fill_scan_span_rows(uint8_t border_color, uint32_t window_left, uint16_t window_top, uint32_t window_right, uint16_t window_bottom, uint32_t scan_x, uint16_t y, uint32_t fill_pattern);
uint32_t flood_fill_scan_row_skip_parent(uint8_t border_color, uint32_t window_left, uint32_t window_right, uint32_t direction, uint32_t scan_x, uint8_t y, uint32_t fill_pattern);
uint32_t flood_fill_skip_parent_right(uint8_t border_color, uint32_t window_left, uint32_t window_right, uint8_t direction, uint32_t scan_x, uint8_t y, uint32_t fill_pattern);
void fill_span_at_point(uint32_t point_x, uint32_t point_y, uint8_t fill_color, uint8_t border_color, uint32_t right_cursor);
void fill_span_at_point_left_byte(uint32_t scan_count, uint8_t fill_color, uint8_t border_color, uint32_t left_x, uint32_t right_cursor, uint32_t right_x);
void fill_span_at_point_left_even_pixel(uint8_t pixel_byte, uint32_t scan_count, uint8_t fill_color, uint8_t border_color, uint32_t left_x, uint32_t right_cursor, uint32_t right_x);
void fill_span_at_point_scan_right(uint8_t fill_color, uint8_t border_color, uint32_t left_x, uint32_t right_cursor, uint32_t right_x);
void fill_span_at_point_right_byte(uint32_t scan_count, uint8_t fill_color, uint8_t border_color, uint32_t left_x, uint32_t right_cursor, uint32_t right_x);
void fill_span_at_point_right_odd_pixel(uint8_t pixel_byte, uint32_t scan_count, uint8_t fill_color, uint8_t border_color, uint32_t left_x, uint32_t right_cursor, uint32_t right_x);
void fill_span_at_point_fill_run(uint32_t fill_color, uint32_t left_x, uint32_t right_x);
void save_bitmap_rect(uint16_t left, uint16_t top, uint32_t right, uint32_t bottom, uint32_t buffer);
void draw_saved_bitmap_rect(uint32_t buffer);
void get_window_outcode(uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_end_x, uint32_t *p_end_y, uint32_t *p_outcode);
void get_point_outcode(uint32_t *p_point_x, uint32_t *p_point_y, uint32_t *p_outcode);
void clip_line_to_window(uint32_t outcode, uint32_t end_outcode, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_end_x, uint32_t *p_end_y, uint32_t *p_unclipped_y);
void clip_line_end_inside(void);
void clip_line_to_left_edge(uint32_t end_x, uint32_t end_y, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_unclipped_y);
void clip_line_to_right_edge(uint32_t end_x, uint32_t end_y, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_unclipped_y);
void clip_line_at_x(uint32_t end_x, uint32_t end_y, uint32_t dx, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_unclipped_y);
void clip_line_to_top_edge(uint32_t end_x, uint32_t end_y, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_unclipped_y);
void clip_line_to_bottom_edge(uint32_t end_x, uint32_t end_y, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_unclipped_y);
void clip_line_at_y(uint32_t end_x, uint32_t end_y, uint32_t dy, uint32_t *p_start_x, uint32_t *p_start_y, uint32_t *p_unclipped_y);
void clip_rect_to_window(uint32_t *p_left, uint32_t *p_top, uint32_t *p_right, uint32_t *p_bottom, uint32_t *p_window_min, uint32_t *p_unclipped_edges);

/* video/text.c: text: the text layer's font, printing and erasing text, lines, fractions and digits, and the strings drawn with sprites */
void queue_string_record(uint32_t record, uint16_t y, uint32_t scale, uint32_t *p_palette, uint32_t *p_text);
void queue_string_at(uint32_t x, uint16_t y, uint32_t *p_palette, uint32_t *p_scale, uint32_t *p_text);
void queue_string(uint32_t x, uint16_t y, uint8_t mode, uint32_t *p_palette, uint32_t *p_scale, uint32_t *p_text);
void draw_queued_strings(uint16_t size, uint16_t width, uint32_t sprite_entry, uint32_t *p_scale, uint32_t *p_cursor, uint32_t *p_height);
void load_text_font(uint32_t *p_pixels, uint32_t *p_color_index);
void clear_text_layer(uint32_t *p_value, uint32_t *p_count, uint32_t *p_dest);
void expand_font(uint8_t color, uint32_t count, uint32_t source, uint32_t dest, uint32_t *p_pixels, uint32_t *p_color_index);
void expand_font_2bpp(uint8_t color, uint32_t count, uint32_t source, uint32_t dest);
void expand_font_2bpp_transparent(uint8_t color, uint32_t count, uint32_t pixels, uint32_t opaque_mask, uint32_t source, uint32_t dest);
void draw_fraction(uint16_t attribute, uint32_t *p_numerator, uint32_t *p_denominator, uint32_t *p_text_position);
void print_text_list(uint32_t *p_text, uint32_t *p_text_position);
void print_text(uint32_t *p_text, uint32_t *p_text_position);
void print_text_here(uint32_t *p_cell, uint32_t *p_text, uint32_t *p_text_position);
void erase_text_list(uint32_t text);
uint32_t erase_text(uint32_t text);
void erase_text_here(uint16_t cell, uint32_t *p_text, uint32_t *p_text_position);
void print_text_lines(uint32_t *p_text, uint32_t *p_text_position);
void erase_text_lines(uint32_t *p_text, uint32_t *p_text_position);
void print_formatted_text(uint32_t text);
void formatted_text_position_single(uint32_t text, uint32_t text_position);
void formatted_text_attribute_single(uint32_t text, uint32_t text_position);
void formatted_text_single(uint16_t cell, uint32_t text, uint32_t text_position);
void formatted_text_skip_single(uint16_t cell, uint32_t text, uint32_t text_position);
void formatted_text_skip_long_single(uint16_t cell, uint32_t text, uint32_t text_position);
void formatted_text_position_double(uint32_t text, uint32_t text_position);
void formatted_text_attribute_double(uint32_t text, uint32_t text_position);
void formatted_text_double(uint16_t cell, uint32_t text, uint32_t text_position);
void formatted_text_skip_double(uint16_t cell, uint32_t text, uint32_t text_position);
void formatted_text_skip_long_double(uint16_t cell, uint32_t text, uint32_t text_position);
void formatted_text_position_triple(uint32_t text, uint32_t text_position);
void formatted_text_attribute_triple(uint32_t text, uint32_t text_position);
void formatted_text_triple(uint16_t cell, uint32_t text, uint32_t text_position);
void formatted_text_skip_triple(uint16_t cell, uint32_t text, uint32_t text_position);
void formatted_text_skip_long_triple(uint16_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text(uint32_t cell, uint32_t text);
void erase_formatted_text_position_single(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_attribute_single(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_single(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_skip_single(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_position_double(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_attribute_double(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_double(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_skip_double(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_position_triple(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_attribute_triple(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_triple(uint32_t cell, uint32_t text, uint32_t text_position);
void erase_formatted_text_skip_triple(uint32_t cell, uint32_t text, uint32_t text_position);
uint32_t draw_hex_2(uint32_t value, uint32_t attribute, uint32_t text_position);
void draw_hex_4(uint32_t *p_value, uint32_t *p_attribute, uint32_t *p_text_position);
void draw_hex_6(uint32_t value, uint32_t attribute, uint32_t text_position);
void draw_hex_8(uint32_t value, uint32_t attribute, uint32_t text_position);
void draw_hex_digits(uint32_t digit_count, uint32_t *p_value, uint32_t *p_attribute, uint32_t *p_text_position);
void draw_credit_digits(uint32_t value, uint32_t *p_attribute, uint32_t *p_text_position);
void draw_bcd_4(uint32_t value, uint32_t attribute, uint32_t text_position);
void draw_bcd_6(uint32_t value, uint32_t attribute, uint32_t text_position);
void draw_bcd_8(uint32_t value, uint32_t attribute, uint32_t text_position);
void draw_bcd_digits(uint32_t value, uint32_t digit_count, uint32_t *p_attribute, uint32_t *p_text_position);

/* video/video.c: the board's video: the video registers and the screen mode, block copies and fills, palette RAM and its copies at VBLANK, the VRAM scripts that build the tilemaps */
void init_video_registers(void);
uint32_t clear_page_0_and_scroll(void);
void init_video_registers_layers_off(void);
void empty_vblank_hook(void);
void apply_video_registers(void);
uint32_t set_screen_mode(uint16_t mode);
void copy_blocks(uint32_t count, uint32_t *p_source, uint32_t *p_dest);
void clear_blocks(uint32_t *p_value, uint32_t *p_count, uint32_t *p_dest);
uint32_t fill_halfwords(uint16_t value, uint32_t count, uint32_t dest);
void run_vram_script(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_end(void);
void vram_script_set_address(uint32_t script_code, uint32_t *p_script, uint32_t *p_dest);
void vram_script_skip(uint32_t *p_script, uint32_t *p_dest);
void vram_script_skip_long(uint32_t *p_script, uint32_t *p_dest);
void vram_script_fill(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_count_up(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_count_down(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_bytes(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_words(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_words_to_dictionary(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest, uint32_t *p_dictionary_cursor);
void vram_script_clear_pages(uint32_t *p_script, uint32_t *p_dest);
void vram_script_fill_down(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_fill_up(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_fill_down_wide(uint32_t *p_count, uint32_t *p_script, uint32_t *p_dest);
void vram_script_repeat(uint32_t dest, uint32_t *p_count, uint32_t *p_script);
void erase_vram_script(uint32_t script, uint32_t dest);
void erase_vram_script_end(void);
void erase_vram_script_fill(uint16_t cell, uint32_t *p_script, uint32_t *p_dest);
void erase_vram_script_bytes(uint16_t cell, uint32_t *p_script, uint32_t *p_dest);
void erase_vram_script_words(uint16_t cell, uint32_t *p_script, uint32_t *p_dest);
void erase_vram_script_fill_down(uint16_t cell, uint32_t *p_script, uint32_t *p_dest);
void erase_vram_script_fill_up(uint16_t cell, uint32_t *p_script, uint32_t *p_dest);
void erase_vram_script_fill_down_wide(uint16_t cell, uint32_t *p_script, uint32_t *p_dest);
uint32_t erase_vram_script_repeat(uint16_t cell, uint32_t script, uint32_t dest);
uint32_t load_default_palettes(void);
void load_palette_list(uint32_t palette_list, uint32_t *p_source, uint32_t *p_dest);
void copy_palettes_with_pen_0(uint16_t pen_0_color, uint32_t size, uint32_t *p_source, uint32_t *p_dest);
void copy_palette_block(uint32_t size, uint32_t *p_source, uint32_t *p_dest);
void repeat_palette_block(uint32_t size, uint32_t *p_source, uint32_t *p_dest, uint32_t *p_palette_list);
void queue_vblank_copy(uint32_t source, uint32_t dest, uint16_t halfwords, uint32_t *p_copy_offset, uint32_t *p_copy_entry);

# 13 "C:\\segasonic-port-main\\segasonic\\src\\engine\\objects - copia.cpp"

/* Unused: while next_stage_slot_request is set, moves the current object's x, y, z_int,
   previous_floor_z_int and previous_floor_block from this stage's link point to the next one's (-
   stage_link_from_*, + stage_link_to_*), the object side of continue_to_next_stage_slot. */
void move_object_to_next_stage_slot(void)
{
	if ((*(uint8_t *)ram(0x20E538u)) != 0u)
	{
		((struct object *)ram(current_object))->x = (uint32_t)((struct object *)ram(current_object))->x - (*(int32_t *)ram(0x20E522u)) + (*(int32_t *)ram(0x20E52Eu));
		((struct object *)ram(current_object))->y = (uint32_t)((struct object *)ram(current_object))->y - (*(int32_t *)ram(0x20E526u)) + (*(int32_t *)ram(0x20E532u));
		((struct object *)ram(current_object))->previous_floor_z_int = ((struct object *)ram(current_object))->previous_floor_z_int - (*(uint16_t *)ram(0x20E52Au)) + (*(uint16_t *)ram(0x20E536u));
		((struct object *)ram(current_object))->z_int = ((struct object *)ram(current_object))->z_int - (*(uint16_t *)ram(0x20E52Au)) + (*(uint16_t *)ram(0x20E536u));
		((struct object *)ram(current_object))->previous_floor_block = (uint16_t)(((struct object *)ram(current_object))->previous_floor_block - (*(uint16_t *)ram(0x20E520u)) + (*(uint16_t *)ram(0x20E52Cu)));
	}
}

/* Two steps through the random number area at 0xD80000: random_position moves on by the word it points
   at (within 0x80000) and the word at the new place is taken. random_value hands back the two words, the
   first in the low half. */
void next_random(uint32_t *p_random_value, uint32_t *p_words_left, uint32_t *p_random_offset)
{
	uint32_t random_value = *p_random_value;
	uint32_t random_offset = 0, words_left = 0;

	random_offset = (*(uint32_t *)ram(0x20F0FCu));
	words_left = 2u;
	do
	{
		random_offset = (random_offset + mem_read16(random_offset + 0xD80000u)) & 0x7FFFFu;
		random_value = (random_value & ~0xFFFFu) | mem_read16(random_offset + 0xD80000u);
		random_value = (random_value << 16) | (random_value >> 16);
		words_left--;
	} while (words_left != 0u);
	(*(uint32_t *)ram(0x20F0FCu)) = random_offset;
	*p_random_value = random_value;
	*p_words_left = words_left;
	*p_random_offset = random_offset;
}

/* Unused: create_child_shadow with sprite_flags 0x1000 and no sprite_scale, palette 0x9FFE, and without
   touching current_player. */
void create_child_shadow_unscaled(uint32_t shadow)
{
	uint32_t free_count = 0, ignored = 0, owner = 0;

	((struct object *)ram(current_object))->child = 0xFFFFu;
	owner = current_object;
	allocate_object_2(&free_count, &ignored, &shadow);
	if (free_count != 0u)
	{
		((struct object *)ram(shadow))->sprite_flags = 0x1000u;
		((struct object *)ram(shadow))->sprite_palette = 0x9FFEu;
		((struct object *)ram(shadow))->sprite_frame = 0x5D90u;
		((struct object *)ram(shadow))->shadow_blink = 0u;
		((struct object *)ram(owner))->child = shadow;
		((struct object *)ram(shadow))->parent = current_object;
	}
}

/* Unused: create_child_shadow with palette 0x9FFE instead of 0x87A0. */
void create_child_shadow_9ffe(uint16_t scale, uint32_t shadow)
{
	uint32_t free_count = 0, ignored = 0;

	((struct object *)ram(current_object))->child = 0xFFFFu;
	current_player = current_object;
	allocate_object_2(&free_count, &ignored, &shadow);
	if (free_count != 0u)
	{
		((struct object *)ram(shadow))->sprite_flags = 0u;
		((struct object *)ram(shadow))->sprite_palette = 0x9FFEu;
		((struct object *)ram(shadow))->sprite_frame = 0x5D90u;
		((struct object *)ram(shadow))->sprite_scale = scale;
		((struct object *)ram(shadow))->shadow_blink = 0u;
		((struct object *)ram(current_player))->child = shadow;
		((struct object *)ram(shadow))->parent = current_object;
	}
}

/* Gives the current object a shadow: a pool 2 block (allocate_object_2) with sprite 0x5D90, palette
   0x87A0, sprite_flags 0, sprite_scale = scale and parent = the object, kept as its child (0xFFFF when
   pool 2 is empty). It leaves current_player = the object. */
void create_child_shadow(uint16_t scale, uint32_t shadow)
{
	uint32_t free_count = 0, ignored = 0;

	((struct object *)ram(current_object))->child = 0xFFFFu;
	current_player = current_object;
	allocate_object_2(&free_count, &ignored, &shadow);
	if (free_count != 0u)
	{
		((struct object *)ram(shadow))->sprite_flags = 0u;
		((struct object *)ram(shadow))->sprite_palette = 0x87A0u;
		((struct object *)ram(shadow))->sprite_frame = 0x5D90u;
		((struct object *)ram(shadow))->sprite_scale = scale;
		((struct object *)ram(shadow))->shadow_blink = 0u;
		((struct object *)ram(current_player))->child = shadow;
		((struct object *)ram(shadow))->parent = current_object;
	}
}

/* Places the current object's shadow (its pool 2 child) on its floor, at projected_x and projected_y +
   floor_z with the sprite offsets, palette 0x9FFE, queued at its screen_y - 0x10. With flag 0x10:
   palette 0x87A0, drawn every other frame (shadow_blink), and on the skipped frames current_object is
   left at the shadow. */
void draw_child_shadow(void)
{
	uint32_t depth = 0, ignored = 0;
	uint8_t shadow_blink = 0;

	if (((struct object *)ram(current_object))->floor_block < 0 || (int16_t)((struct object *)ram(current_object))->child < 0)
		return;
	current_object = (((current_object) & 0xFFFF0000u) | (((struct object *)ram(object_cursor))->child));
	((struct object *)ram(current_object))->screen_x = ((struct object *)ram(object_cursor))->projected_x - (*(int16_t *)ram(0x20E404u)) + ((struct object *)ram(object_cursor))->sprite_offset_x;
	((struct object *)ram(current_object))->screen_y = ((int32_t)((uint32_t)((struct object *)ram(object_cursor))->projected_y + ((struct object *)ram(object_cursor))->floor_z) >> 16) - (*(int16_t *)ram(0x20E406u)) + ((struct object *)ram(object_cursor))->sprite_offset_y;
	((struct object *)ram(current_object))->sprite_palette = 0x9FFEu;
	if ((((struct object *)ram(object_cursor))->flags & 0x10u) != 0u)
	{
		((struct object *)ram(current_object))->sprite_palette = 0x87A0u;
		shadow_blink = ~((struct object *)ram(current_object))->shadow_blink;
		((struct object *)ram(current_object))->shadow_blink = shadow_blink;
		if (shadow_blink == 0u)
		{
			depth = (uint16_t)(((struct object *)ram(current_object))->screen_y - 0x10u);
			queue_sprite_at_depth(&ignored, &depth);
			current_object = (current_object & ~0xFFFFu) | (uint16_t)object_cursor;
		}
		return;
	}
	depth = (uint16_t)(((struct object *)ram(current_object))->screen_y - 0x10u);
	queue_sprite_at_depth(&ignored, &depth);
	current_object = (current_object & ~0xFFFFu) | (uint16_t)object_cursor;
}

/* Unused: 0 when the current object's floor_block (low half) is one of nearby_floor_blocks, the floor
   blocks near the screen, else 0xFFFFFFFF (also when there are none). */
uint32_t is_floor_block_off_screen(void)
{
	uint32_t zero = 0;
	uint16_t floor_block = 0;
	uint32_t blocks_left = 0, cursor = 0, off_screen = 0;
	uint16_t listed_block = 0;

	off_screen = 0u;
	blocks_left = (*(uint16_t *)ram(0x209F80u));
	cursor = 0x209F82u;
	if (blocks_left == 0u)
	{
		off_screen = 0xFFFFFFFFu;
		return off_screen;
	}
	floor_block = (uint16_t)((struct object *)ram(current_object))->floor_block;
	do
	{
		listed_block = mem_read16(cursor);
		zero = (uint16_t)(floor_block - listed_block) == 0u;
		cursor += 2u;
		blocks_left--;
	} while ((blocks_left != 0u) & (floor_block != listed_block));
	if (zero)
		return off_screen;
	off_screen = 0xFFFFFFFFu;
	return off_screen;
}

/* 0xFFFFFFFF when the current object is more than 0x20 outside the 0x140 x 0xE0 screen (screen_x + 0x20
   >= 0x180 or screen_y + 0x20 >= 0x120, unsigned), else 0. */
uint32_t is_off_screen(void)
{
	uint32_t off_screen = 0;

	off_screen = 0u;
	if ((uint16_t)(((struct object *)ram(current_object))->screen_x + 0x20u) >= 0x180u || (uint16_t)(((struct object *)ram(current_object))->screen_y + 0x20u) >= 0x120u)
		off_screen = 0xFFFFFFFFu;
	return off_screen;
}

/* is_off_screen with margin_x and margin_y in place of 0x20. */
uint32_t is_off_screen_margin(uint16_t margin_x, uint16_t margin_y)
{
	uint32_t off_screen = 0;

	off_screen = 0u;
	if ((uint16_t)(0x140u + margin_x * 2u) <= (uint16_t)(((struct object *)ram(current_object))->screen_x + margin_x) || (uint16_t)(0xE0u + margin_y * 2u) <= (uint16_t)(((struct object *)ram(current_object))->screen_y + margin_y))
		off_screen = 0xFFFFFFFFu;
	return off_screen;
}

/* Hands back 0xFFFFFFFF once the current object, having been on screen (flag 0x800), is more than 0x20
   outside the 0x140 x 0xE0 screen, else 0; sets flag 0x800 while it is on the screen (no margin until
   then). */
uint32_t check_left_screen(void)
{
	uint16_t edge_margin = 0;
	uint32_t off_screen = 0;

	off_screen = 0u;
	edge_margin = 0x20u;
	if ((((struct object *)ram(current_object))->flags & 0x800u) == 0u)
		edge_margin = 0u;
	if (0x140u + edge_margin * 2u <= (uint16_t)(((struct object *)ram(current_object))->screen_x + edge_margin) || 0xE0u + edge_margin * 2u <= (uint16_t)(((struct object *)ram(current_object))->screen_y + edge_margin))
	{
		if ((((struct object *)ram(current_object))->flags & 0x800u) != 0u)
			off_screen = 0xFFFFFFFFu;
	}
	else
		((struct object *)ram(current_object))->flags |= 0x800u;
	return off_screen;
}

/* check_left_screen with margin instead of 0x20 once the object has been on screen (0 before). */
uint32_t check_left_screen_margin(uint16_t margin)
{
	uint32_t off_screen = 0;

	off_screen = 0u;
	if ((((struct object *)ram(current_object))->flags & 0x800u) == 0u)
		margin = 0u;
	if ((uint16_t)(0x140u + margin * 2u) <= (uint16_t)(((struct object *)ram(current_object))->screen_x + margin) || (uint16_t)(0xE0u + margin * 2u) <= (uint16_t)(((struct object *)ram(current_object))->screen_y + margin))
	{
		if ((((struct object *)ram(current_object))->flags & 0x800u) != 0u)
			off_screen = 0xFFFFFFFFu;
	}
	else
		((struct object *)ram(current_object))->flags |= 0x800u;
	return off_screen;
}

/* check_left_screen with margin once the object has been on screen and unseen_margin before. */
uint32_t check_left_screen_margins(uint16_t margin, uint16_t unseen_margin)
{
	uint32_t off_screen = 0;

	off_screen = 0u;
	if ((((struct object *)ram(current_object))->flags & 0x800u) == 0u)
		margin = (uint16_t)unseen_margin;
	if ((uint16_t)(0x140u + margin * 2u) <= (uint16_t)(((struct object *)ram(current_object))->screen_x + margin) || (uint16_t)(0xE0u + margin * 2u) <= (uint16_t)(((struct object *)ram(current_object))->screen_y + margin))
	{
		if ((((struct object *)ram(current_object))->flags & 0x800u) != 0u)
			off_screen = 0xFFFFFFFFu;
	}
	else
		((struct object *)ram(current_object))->flags |= 0x800u;
	return off_screen;
}

/* allocate_object for code outside run_objects (the spawners the game modes run): it first reloads
   free_objects, first_object and last_object from free_object_stack and first/last_object_address. */
void allocate_object_outside_loop(uint32_t *p_free_count, uint32_t *p_object)
{
	free_objects = 0x20E900u;
	first_object = (*(uint32_t *)ram(0x207FE2u));
	last_object = (*(uint32_t *)ram(0x207FE6u));
	allocate_object(p_free_count, p_object);
}

/* delete_object for code outside run_objects: reloads free_objects, first_object and last_object first,
   and stores first_object and last_object back into first/last_object_address after. */
void delete_object_outside_loop(uint32_t object, uint32_t *p_free_count, uint32_t *p_previous)
{
	free_objects = 0x20E900u;
	first_object = (*(uint32_t *)ram(0x207FE2u));
	last_object = (*(uint32_t *)ram(0x207FE6u));
	delete_object(object, p_free_count, p_previous);
	(*(uint32_t *)ram(0x207FE2u)) = first_object;
	(*(uint32_t *)ram(0x207FE6u)) = last_object;
}

/* Spawns the stage's stage_spawns_by_handler records as the scroll reaches them, one a frame (the list
   starts on the stage's first call): an object at the record's x and y with its word in sprite_frame (a
   parameter its handler reads) and its handler. A record 0x100 or more behind the scroll is skipped; it
   waits while no object is free. */
void spawn_objects_by_handler(uint32_t *p_list_offset, uint32_t *p_record, uint32_t *p_object)
{
	uint32_t object = *p_object;
	uint32_t free_count = 0, record = 0;
	uint32_t old_init_flags = 0;

	old_init_flags = (*(uint32_t *)ram(0x20F0BCu));
	(*(uint32_t *)ram(0x20F0BCu)) = old_init_flags | 1u;
	if ((old_init_flags & 1u) == 0u)
	{
		*p_list_offset = ((const uint16_t *)rom(0x081224u))[(*(uint16_t *)ram(0x20F06Eu))];
		(*(uint32_t *)ram(0x20F0DAu)) = 0x081224u + *p_list_offset;
	}
	record = (*(uint32_t *)ram(0x20F0DAu));
	if (((const struct handler_spawn_record *)rom(record))->position <= (*(uint16_t *)ram(0x20E435u)))
	{
		if ((uint16_t)((*(uint16_t *)ram(0x20E435u)) - ((const struct handler_spawn_record *)rom(record))->position) >= 0x100u)
			(*(uint32_t *)ram(0x20F0DAu)) += 0xCu;
		else
		{
			allocate_object_outside_loop(&free_count, &object);
			if (free_count != 0u)
			{
				record = (*(uint32_t *)ram(0x20F0DAu)) + 2u;
				((struct object *)ram(object))->x_int = ((const struct handler_spawn_record *)rom(record - 0x2u))->x;
				((struct object *)ram(object))->x_fraction = 0u;
				record += 2u;
				((struct object *)ram(object))->y_int = ((const struct handler_spawn_record *)rom(record - 0x4u))->y;
				((struct object *)ram(object))->y_fraction = 0u;
				record += 2u;
				((struct object *)ram(object))->sprite_frame = ((const struct handler_spawn_record *)rom(record - 0x6u))->handler_arg;
				record += 2u;
				((struct object *)ram(object))->handler = ((const struct handler_spawn_record *)rom(record - 0x8u))->handler;
				record += 4u;
				(*(uint32_t *)ram(0x20F0DAu)) += 0xCu;
				*p_record = record;
				*p_object = object;
				return;
			}
		}
	}
	*p_record = record;
	*p_object = object;
}

/* electric_fence_state = 0 when a game starts (fence_post_init sets 1, flame_machine_remove 0xFF;
   fence_post_update switches on it). */
void reset_linked_objects_flag(void)
{
	(*(uint8_t *)ram(0x208076u)) = 0u;
}

/* Starts the stage's stage_spawns_by_type list: type_spawn_cursor at its start, type_spawn_stage =
   stage; also clears string_count, stage_trigger_bits and unused_type_spawn_byte. */
void start_spawns_by_type(void)
{
	uint32_t stage_number = 0;

	stage_number = (*(uint16_t *)ram(0x20F06Eu));
	(*(uint16_t *)ram(0x208006u)) = stage_number;
	((uint32_t *)ram(0x208000u))[0] = ((const uint32_t *)rom(0x100168u))[stage_number];
	(*(uint8_t *)ram(0x208078u)) = 0u;
	(*(int16_t *)ram(0x20C800u)) = 0;
	(*(uint32_t *)ram(0x208096u)) = 0u;
}

/* Spawns the next stage_spawns_by_type record once scroll_position passes it: object_types[type] gives
   spawn_count and the handler (spawn_object_with_pieces); its words go to projected_x, projected_y, z,
   spawn_arg_1 and spawn_arg_2 (unproject_object works out x and y). A record the pools cannot take is
   dropped. Then count_active_players. */
void spawn_objects_by_type(uint32_t *p_player_object, uint32_t *p_player_index, uint32_t *p_first, uint32_t *p_projected_x, uint32_t *p_projected_y, uint32_t *p_object_type, uint32_t *p_object)
{
	uint16_t spawn_z = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, record = 0, scroll = 0, trigger_scroll = 0;

	if ((*(uint16_t *)ram(0x208006u)) != (*(uint16_t *)ram(0x20F06Eu)))
	{
		start_spawns_by_type();
		return;
	}
	record = ((uint32_t *)ram(0x208000u))[0];
	scroll = (*(uint16_t *)ram(0x20E435u));
	trigger_scroll = ((const struct type_spawn_record *)rom(record))->position;
	record += 2u;
	if (trigger_scroll == 0xFFFFu || scroll <= trigger_scroll)
	{
		count_active_players(p_player_object, p_player_index);
		return;
	}
	*p_projected_x = ((const struct type_spawn_record *)rom(record - 0x2u))->projected_x;
	record += 2u;
	*p_projected_y = ((const struct type_spawn_record *)rom(record - 0x4u))->projected_y;
	record += 2u;
	spawn_z = (uint16_t)((const struct type_spawn_record *)rom(record - 0x6u))->z;
	record += 2u;
	if ((int32_t)trigger_scroll <= (int32_t)scroll)
	{
		*p_object_type = 0x100000u + ((const struct type_spawn_record *)rom(record - 0x8u))->object_type * 8u;
		(*(uint16_t *)ram(0x208008u)) = ((const struct object_type_record *)rom(*p_object_type))->part_count;
		record += 2u;
		*p_object_type += 4u;
		spawn_object_with_pieces(0x08DCB1u, &scroll, &ignored, p_player_index, p_first, p_object);
		if ((uint8_t)scroll == 0u)
		{
			((uint32_t *)ram(0x208000u))[0] += 0xEu;
			count_active_players(p_player_object, p_player_index);
			return;
		}
		current_object = *p_first;
		*p_projected_y = *p_projected_y << 16;
		((struct object *)ram(current_object))->projected_x = *p_projected_x;
		((struct object *)ram(current_object))->projected_y = *p_projected_y;
		((struct object *)ram(current_object))->z = (uint32_t)spawn_z << 16;
		((struct object *)ram(current_object))->flags = 0u;
		((struct object *)ram(current_object))->handler = ((const struct object_type_record *)rom(*p_object_type - 0x4u))->handler;
		((struct object *)ram(current_object))->spawn_arg_1 = ((const struct type_spawn_record *)rom(record - 0xAu))->spawn_arg_1;
		record += 2u;
		((struct object *)ram(current_object))->spawn_arg_2 = ((const struct type_spawn_record *)rom(record - 0xCu))->spawn_arg_2;
		((uint32_t *)ram(0x208000u))[0] = record + 2u;
		unproject_object(&ignored_2, &ignored_3, p_first, p_object);
		count_active_players(p_player_object, p_player_index);
		return;
	}
	((uint32_t *)ram(0x208000u))[0] += 0xEu;
	count_active_players(p_player_object, p_player_index);
}

/* active_player_count = how many of the three players' objects (player_block_offsets) lack flag 0x400
   (out of the game). */
void count_active_players(uint32_t *p_player_object, uint32_t *p_player_index)
{
	uint32_t player = 0, player_index = 0, players_left = 0;

	players_left = 3u;
	player_index = 2u;
	(*(uint8_t *)ram(0x208028u)) = 0u;
	do
	{
		player = 0x208000u + ((const uint32_t *)rom(0x08E2D5u))[player_index];
		*p_player_object = (((player) & 0xFFFF0000u) | (((struct player *)ram(player))->object));
		if ((((struct object *)ram(*p_player_object))->flags & 0x400u) == 0u)
			(*(uint8_t *)ram(0x208028u))++;
		players_left--;
		player_index--;
	} while (players_left != 0u);
	*p_player_index = player_index;
}

/* Spawns a pool 1 object (init_object, parent = object_cursor, next_handler = return_address) and
   spawn_count - 1 pool 2 pieces chained from it (add_object_pieces): first, spawned 1. Nothing when
   spawn_count <= 0 or the pools are short, but its empty-stack test keeps the high half of the caller's
   free_count: a non-zero one passes. */
void spawn_object_with_pieces(uint32_t return_address, uint32_t *p_spawned, uint32_t *p_piece_count, uint32_t *p_free_count, uint32_t *p_first, uint32_t *p_block)
{
	uint32_t piece_count = *p_piece_count;
	uint32_t ignored = 0, pool_2_free = 0;
	uint16_t free_blocks = 0, spawn_total = 0;

	if ((int16_t)(*(uint16_t *)ram(0x208008u)) > 0)
	{
		free_objects = 0x20E900u;
		first_object = (*(uint32_t *)ram(0x207FE2u));
		last_object = (*(uint32_t *)ram(0x207FE6u));
		*p_spawned &= ~0xFFu;
		*p_free_count = (((*p_free_count) & 0xFFFF0000u) | ((*(int16_t *)ram(0x20E900u))));
		if (*p_free_count != 0u)
		{
			piece_count = (uint16_t)((*(uint16_t *)ram(0x208008u)) - 1u);
			if (piece_count != 0u)
			{
				pool_2_free = (((0x200000u) & 0xFFFF0000u) | (((int16_t *)ram(0x20EA10u))[0]));
				free_blocks = pool_2_free;
				*p_free_count = (pool_2_free & ~0xFFFFu) | (uint16_t)(free_blocks - piece_count);
				if (piece_count <= free_blocks)
				{
					allocate_object(&ignored, p_block);
					init_object(*p_block);
					((struct object *)ram(*p_block))->next_handler = return_address;
					((struct object *)ram(*p_block))->parent = object_cursor;
					((struct object *)ram(*p_block))->child = 0xFFFFu;
					*p_first = *p_block;
					*p_spawned = 1u;
					spawn_total = (*(uint16_t *)ram(0x208008u));
					piece_count = (uint16_t)(spawn_total - 1u);
					if (spawn_total != 1u)
					{
						add_object_pieces(p_spawned, &piece_count, p_free_count, p_first, p_block);
						*p_piece_count = (*p_piece_count & 0xFFFF0000u) | (piece_count & 0xFFFFu);
						return;
					}
				}
				current_object = object_cursor;
				*p_piece_count = (*p_piece_count & 0xFFFF0000u) | (piece_count & 0xFFFFu);
				return;
			}
			allocate_object(&ignored, p_block);
			init_object(*p_block);
			((struct object *)ram(*p_block))->next_handler = return_address;
			((struct object *)ram(*p_block))->parent = object_cursor;
			((struct object *)ram(*p_block))->child = 0xFFFFu;
			*p_first = *p_block;
			*p_spawned = 1u;
			spawn_total = (*(uint16_t *)ram(0x208008u));
			piece_count = (uint16_t)(spawn_total - 1u);
			if (spawn_total != 1u)
			{
				add_object_pieces(p_spawned, &piece_count, p_free_count, p_first, p_block);
				*p_piece_count = (*p_piece_count & 0xFFFF0000u) | (piece_count & 0xFFFFu);
				return;
			}
			current_object = object_cursor;
			*p_piece_count = (*p_piece_count & 0xFFFF0000u) | (piece_count & 0xFFFFu);
			return;
		}
	}
	current_object = object_cursor;
	*p_piece_count = (*p_piece_count & 0xFFFF0000u) | (piece_count & 0xFFFFu);
}

/* add_object_pieces with spawn_count pieces chained after object_cursor. */
void add_pieces_to_current_object(uint32_t *p_spawned, uint32_t *p_free_count, uint32_t *p_first, uint32_t *p_block)
{
	uint32_t piece_count = 0;

	*p_block = object_cursor;
	piece_count = (*(uint16_t *)ram(0x208008u));
	add_object_pieces(p_spawned, &piece_count, p_free_count, p_first, p_block);
}

/* Allocates piece_count pool 2 blocks (init_object_2) chained through child after block, each with
   parent = spawn_first (block) and no child of its own; first = spawn_first, spawned = 1. Nothing
   (spawned 0) when free_object_stack_2 holds fewer than piece_count. */
void add_object_pieces(uint32_t *p_spawned, uint32_t *p_piece_count, uint32_t *p_free_count, uint32_t *p_first, uint32_t *p_block)
{
	uint16_t piece_count = (uint16_t)*p_piece_count;
	uint32_t block = *p_block;
	uint32_t ignored = 0, object = 0, pool_2_free = 0;
	uint16_t free_blocks = 0;

	(*(uint32_t *)ram(0x20800Au)) = block;
	(*(uint32_t *)ram(0x20800Eu)) = block;
	*p_spawned &= ~0xFFu;
	piece_count = (uint16_t)piece_count;
	pool_2_free = (((0x200000u) & 0xFFFF0000u) | (((int16_t *)ram(0x20EA10u))[0]));
	free_blocks = pool_2_free;
	*p_free_count = (pool_2_free & ~0xFFFFu) | (uint16_t)(free_blocks - piece_count);
	if (piece_count <= free_blocks)
	{
		(*(uint16_t *)ram(0x208008u)) = piece_count;
		do
		{
			allocate_object_2(&ignored, p_free_count, &block);
			init_object_2(block);
			object = (*(uint32_t *)ram(0x20800Eu));
			(*(uint16_t *)ram(0x20800Eu)) = block;
			((struct object *)ram(object))->child = block;
			((struct object *)ram(block))->parent = (uint16_t)(*(uint32_t *)ram(0x20800Au));
			((struct object *)ram(block))->child = 0xFFFFu;
			(*(uint16_t *)ram(0x208008u))--;
		} while ((*(uint16_t *)ram(0x208008u)) != 0u);
		*p_first = (*(uint32_t *)ram(0x20800Au));
		*p_spawned = 1u;
	}
	current_object = object_cursor;
	*p_piece_count = (*p_piece_count & 0xFFFF0000u) | piece_count;
	*p_block = block;
}

/* Spawns spawn_count pool 1 objects chained through child (each init_object, parent = object_cursor,
   next_handler = return_address); first = the first one, spawned 1. Nothing when spawn_count <= 0 or
   free_object_stack holds fewer than spawn_count (spawned 0). */
void spawn_objects(uint32_t return_address, uint32_t *p_spawned, uint32_t *p_first, uint32_t *p_block)
{
	uint32_t block = *p_block;
	uint32_t ignored = 0;

	if ((int16_t)(*(uint16_t *)ram(0x208008u)) <= 0)
	{
		*p_first = (*(uint32_t *)ram(0x20800Au));
		current_object = object_cursor;
		return;
	}
	free_objects = 0x20E900u;
	first_object = (*(uint32_t *)ram(0x207FE2u));
	last_object = (*(uint32_t *)ram(0x207FE6u));
	*p_spawned = 0u;
	if ((uint16_t)(*(int16_t *)ram(0x20E900u)) < (*(uint16_t *)ram(0x208008u)))
	{
		*p_first = (*(uint32_t *)ram(0x20800Au));
		current_object = object_cursor;
		return;
	}
	allocate_object(&ignored, &block);
	(*(uint32_t *)ram(0x20800Au)) = block;
	(*(uint32_t *)ram(0x20800Eu)) = block;
	((struct object *)ram(block))->parent = object_cursor;
	((struct object *)ram(block))->child = 0xFFFFu;
	init_object(block);
	((struct object *)ram(block))->next_handler = return_address;
	for (;;)
	{
		(*(uint32_t *)ram(0x20800Eu)) = block;
		(*(uint16_t *)ram(0x208008u))--;
		*p_spawned = 1u;
		if ((*(uint16_t *)ram(0x208008u)) == 0u)
			break;
		allocate_object(&ignored, &block);
		init_object(block);
		((struct object *)ram(block))->next_handler = return_address;
		((struct object *)ram((*(uint32_t *)ram(0x20800Eu))))->child = block;
		((struct object *)ram(block))->parent = object_cursor;
		((struct object *)ram(block))->child = 0xFFFFu;
	}
	*p_first = (*(uint32_t *)ram(0x20800Au));
	current_object = object_cursor;
	*p_block = block;
}

/* Unused: breaks up the child chain from object: each child link becomes 0xFFFF, until one already is. */
void unlink_child_chain(uint32_t object)
{
	uint16_t next_child = 0;

	for (;;)
	{
		next_child = ((struct object *)ram(object))->child;
		if (((struct object *)ram(object))->child == 0xFFFFu)
			break;
		((struct object *)ram(object))->child = 0xFFFFu;
		object = (object & ~0xFFFFu) | next_child;
	}
}

/* init_object_fields with mode 0: the whole object. */
void init_object(uint32_t object)
{
	uint8_t mode = 0;

	mode = 0u;
	init_object_fields(object, mode);
}

/* init_object_fields with mode 1: only the first 0x30 bytes, the size of a pool 2 block. */
void init_object_2(uint32_t object)
{
	uint8_t mode = 0;

	mode = 1u;
	init_object_fields(object, mode);
}

/* Clears an object for use: draw_next 0, sprite_flags 4, sprite_frame and sprite_palette 0, sprite_scale
   0x100, the layer, screen position, hitbox, anchor and size 0, handler = delete_object_and_children,
   direction and projected_x/projected_y 0. With mode 0 also flags and init_object_fields_tail; previous,
   next, parent and child are kept. */
void init_object_fields(uint32_t object, uint8_t mode)
{
	((struct object *)ram(object))->draw_next = 0u;
	((struct object *)ram(object))->sprite_flags = 4u;
	((struct object *)ram(object))->sprite_frame = 0u;
	((struct object *)ram(object))->sprite_palette = 0u;
	((struct object *)ram(object))->sprite_scale = 0x100u;
	((struct object *)ram(object))->sprite_layer = 0u;
	((struct object *)ram(object))->screen_y = 0;
	((struct object *)ram(object))->screen_x = 0;
	((struct object *)ram(object))->hitbox_size_x = 0u;
	((struct object *)ram(object))->hitbox_size_y = 0u;
	((struct object *)ram(object))->anchor_x = 0;
	((struct object *)ram(object))->anchor_y = 0;
	((struct object *)ram(object))->sprite_height = 0;
	((struct object *)ram(object))->sprite_width = 0;
	((struct object *)ram(object))->handler = 0x08E0CEu;
	((struct object *)ram(object))->direction = 0u;
	((struct object *)ram(object))->projected_x = 0;
	((struct object *)ram(object))->projected_y = 0;
	((struct object *)ram(object))->projected_y_int = 0;
	if ((uint8_t)mode != 0u)
		return;
	((struct object *)ram(object))->flags = 0u;
	init_object_fields_tail(object, mode);
}

/* Unused: init_object_fields_tail on the current object with mode 2: only speed_x, speed_y and speed_z
   are cleared. */
void clear_object_speeds(void)
{
	uint8_t mode = 0;
	uint32_t object = 0;

	mode = 2u;
	object = current_object;
	init_object_fields_tail(object, mode);
}

/* speed_x, speed_y and speed_z = 0; unless mode is 2 (clear_object_speeds), also z and every field after
   it up to next_handler. */
void init_object_fields_tail(uint32_t object, uint8_t mode)
{
	((struct object *)ram(object))->speed_x = 0;
	((struct object *)ram(object))->speed_y = 0;
	((struct object *)ram(object))->speed_z = 0;
	if ((uint8_t)mode != 2u)
	{
		((struct object *)ram(object))->z = 0;
		((struct object *)ram(object))->animation_speed = 0u;
		((struct object *)ram(object))->animation_timer = 0;
		((struct object *)ram(object))->animation_frame = 0u;
		((struct object *)ram(object))->kind = 0u;
		((struct object *)ram(object))->animation = 0u;
		((struct object *)ram(object))->x = 0;
		((struct object *)ram(object))->y = 0;
		((struct object *)ram(object))->floor_z = 0;
		((struct object *)ram(object))->previous_floor_z = 0;
		((struct object *)ram(object))->floor_block = 0;
		((struct object *)ram(object))->previous_floor_block = 0;
		((struct object *)ram(object))->sprite_offset_x = 0;
		((struct object *)ram(object))->sprite_offset_y = 0;
		((struct object *)ram(object))->hitbox_height = 0u;
		((struct object *)ram(object))->hit_list_next = 0u;
		((struct object *)ram(object))->touched_by = 0u;
		((struct object *)ram(object))->touch_distance = 0;
		((struct object *)ram(object))->speed = 0;
		((struct object *)ram(object))->platform_list_next = 0u;
		((struct object *)ram(object))->platform = 0u;
		((struct object *)ram(object))->floor_slope = 0u;
		((struct object *)ram(object))->floor_type = 0u;
		((struct object *)ram(object))->wall = 0u;
		((struct object *)ram(object))->floor_attribute = 0u;
		((struct object *)ram(object))->hitbox_offset_x = 0;
		((struct object *)ram(object))->hitbox_offset_y = 0;
		((struct object *)ram(object))->health = 0;
		((struct object *)ram(object))->var_7F = 0u;
		((struct object *)ram(object))->var_80 = 0u;
		((struct object *)ram(object))->var_81 = 0u;
		((struct object *)ram(object))->var_82 = 0u;
		((struct object *)ram(object))->var_84 = 0u;
		((struct object *)ram(object))->var_86 = 0u;
		((struct object *)ram(object))->draw_depth = 0u;
		((struct object *)ram(object))->var_8A = 0u;
		((struct object *)ram(object))->var_8C = 0u;
		((struct object *)ram(object))->var_8E = 0u;
		((struct object *)ram(object))->var_8F = 0u;
		((struct object *)ram(object))->var_90 = 0u;
		((struct object *)ram(object))->spawn_arg_1 = 0u;
		((struct object *)ram(object))->spawn_arg_2 = 0u;
		((struct object *)ram(object))->var_96 = 0u;
		((struct object *)ram(object))->var_98 = 0u;
		((struct object *)ram(object))->var_9A = 0u;
		((struct object *)ram(object))->next_handler = 0u;
	}
}

/* Moves the current object in projected space: speed_x adds up in projected_x_carry, whose whole pixels
   go to projected_x; projected_y + speed_y, z + speed_z; then unproject_object (x and y, the floor, the
   screen position). */
void move_object_projected(uint32_t *p_screen_y, uint32_t *p_block_offset, uint32_t *p_slope_height, uint32_t *p_cursor)
{
	((struct object *)ram(current_object))->move_object_projected.projected_x_carry += ((struct object *)ram(current_object))->speed_x;
	((struct object *)ram(current_object))->projected_x += ((struct object *)ram(current_object))->move_object_projected.projected_x_carry_int;
	((struct object *)ram(current_object))->projected_y += ((struct object *)ram(current_object))->speed_y;
	((struct object *)ram(current_object))->z += ((struct object *)ram(current_object))->speed_z;
	((struct object *)ram(current_object))->move_object_projected.projected_x_carry_int = 0;
	unproject_object(p_screen_y, p_block_offset, p_slope_height, p_cursor);
}

/* Works the current object's x and y out from projected_x and projected_y, the inverse of
   project_object: x = (projected_x * 0x100 - whole projected_y * 0x200) * 0xB5, y the same with +; then
   find_floor and update_screen_position_no_offset. */
void unproject_object(uint32_t *p_screen_y, uint32_t *p_block_offset, uint32_t *p_slope_height, uint32_t *p_cursor)
{
	uint32_t ignored = 0, scaled_x = 0, scaled_y = 0;

	scaled_x = (uint32_t)((struct object *)ram(current_object))->projected_x << 8;
	scaled_y = (uint32_t)((int32_t)((struct object *)ram(current_object))->projected_y >> 16) << 9;
	*p_block_offset = scaled_x;
	((struct object *)ram(current_object))->x = (scaled_x - scaled_y) * 0xB5u;
	((struct object *)ram(current_object))->y = (scaled_y + *p_block_offset) * 0xB5u;
	find_floor(p_screen_y, &ignored, p_block_offset, p_slope_height, p_cursor);
	*p_screen_y = update_screen_position_no_offset();
}

/* screen_x = projected_x - view_x and screen_y = (projected_y + z) >> 16 - view_y, without the sprite
   offsets update_screen_position adds; hands back screen_y. */
uint32_t update_screen_position_no_offset(void)
{
	uint32_t unscrolled_y = 0;

	((struct object *)ram(current_object))->screen_x = ((struct object *)ram(current_object))->projected_x - (*(int16_t *)ram(0x20E404u));
	unscrolled_y = (int32_t)((uint32_t)((struct object *)ram(current_object))->projected_y + ((struct object *)ram(current_object))->z) >> 16;
	unscrolled_y = (unscrolled_y & ~0xFFFFu) | (uint16_t)(unscrolled_y - (*(int16_t *)ram(0x20E406u)));
	((struct object *)ram(current_object))->screen_y = unscrolled_y;
	return unscrolled_y;
}

/* move_object_projected without unproject_object: x, y and the floor stay as they were and only
   screen_x/screen_y follow (without the sprite offsets). */
void move_object_projected_no_floor(void)
{
	((struct object *)ram(current_object))->move_object_projected.projected_x_carry += ((struct object *)ram(current_object))->speed_x;
	((struct object *)ram(current_object))->projected_x += ((struct object *)ram(current_object))->move_object_projected.projected_x_carry_int;
	((struct object *)ram(current_object))->projected_y += ((struct object *)ram(current_object))->speed_y;
	((struct object *)ram(current_object))->z += ((struct object *)ram(current_object))->speed_z;
	((struct object *)ram(current_object))->move_object_projected.projected_x_carry_int = 0;
	((struct object *)ram(current_object))->screen_x = ((struct object *)ram(current_object))->projected_x - (*(int16_t *)ram(0x20E404u));
	((struct object *)ram(current_object))->screen_y = ((int32_t)((uint32_t)((struct object *)ram(current_object))->projected_y + ((struct object *)ram(current_object))->z) >> 16) - (*(int16_t *)ram(0x20E406u));
}

/* 1 while screen_x is within -0xC0..0x200 and screen_y within -0xC0..0x1A0 (delete_if_off_screen's
   bounds), else 0. */
uint32_t is_on_screen(void)
{
	uint16_t screen_x = 0, screen_y = 0;
	uint32_t on_screen = 0;

	screen_x = (uint16_t)((struct object *)ram(current_object))->screen_x;
	screen_y = (uint16_t)((struct object *)ram(current_object))->screen_y;
	on_screen = 0u;
	if ((int16_t)screen_x >= -0xC0 && (int16_t)screen_x <= 0x200 && (int16_t)screen_y >= -0xC0 && (int16_t)screen_y <= 0x1A0)
		on_screen = 1u;
	return on_screen;
}

/* Deletes the current object and its children (delete_object_and_children, deleted = 1) when screen_x
   leaves -0xC0..0x200 or screen_y leaves -0xC0..0x1A0; deleted = 0 otherwise. */
void delete_if_off_screen(uint32_t *p_deleted, uint32_t *p_block_offset, uint32_t *p_slope_height)
{
	uint16_t screen_x = 0, screen_y = 0;

	screen_x = (uint16_t)((struct object *)ram(current_object))->screen_x;
	screen_y = (uint16_t)((struct object *)ram(current_object))->screen_y;
	if ((int16_t)screen_x < -0xC0 || (int16_t)screen_x > 0x200 || (int16_t)screen_y < -0xC0 || (int16_t)screen_y > 0x1A0)
	{
		delete_object_and_children(p_deleted, p_block_offset, p_slope_height);
		return;
	}
	*p_deleted = 0u;
}

/* The default handler (init_object_fields): frees the current object's child chain (pool 1 children with
   delete_object, pool 2 ones with free_object_2), then delete_current_object; deleted = 1. Halts in
   int_default if free_object_stack_2's count goes past 0x100. */
void delete_object_and_children(uint32_t *p_deleted, uint32_t *p_block_offset, uint32_t *p_slope_height)
{
	uint32_t child = 0, ignored = 0, ignored_2 = 0, object = 0;

	if (((struct object *)ram(object_cursor))->child != 0xFFFFu)
	{
		child = (((0x200000u) & 0xFFFF0000u) | (((struct object *)ram(object_cursor))->child));
		(*(uint16_t *)ram(0x208012u)) = child;
		for (;;)
		{
			if ((int16_t)child < 0x5000)
				delete_object(child, &ignored, p_block_offset);
			else
			{
				*p_block_offset = free_object_2((uint16_t)child);
				*p_deleted = (((0x200000u) & 0xFFFF0000u) | (((int16_t *)ram(0x20EA10u))[0]));
				if ((int16_t)*p_deleted > 0x100)
				{
					int_default(p_deleted, p_block_offset, p_slope_height, &ignored_2);
					return;
				}
			}
			object = (((0x200000u) & 0xFFFF0000u) | ((*(uint16_t *)ram(0x208012u))));
			child = (((object) & 0xFFFF0000u) | (((struct object *)ram(object))->child));
			if ((uint16_t)child == 0xFFFFu)
				break;
			(*(uint16_t *)ram(0x208012u)) = child;
		}
	}
	delete_current_object();
	*p_deleted = 1u;
}

/* Copies object_cursor's x, y, projected_x, projected_y, z and floor_z into object. */
void copy_position_to(uint32_t object)
{
	((struct object *)ram(object))->x = ((struct object *)ram(object_cursor))->x;
	((struct object *)ram(object))->y = ((struct object *)ram(object_cursor))->y;
	((struct object *)ram(object))->projected_x = ((struct object *)ram(object_cursor))->projected_x;
	((struct object *)ram(object))->projected_y = ((struct object *)ram(object_cursor))->projected_y;
	((struct object *)ram(object))->z = ((struct object *)ram(object_cursor))->z;
	((struct object *)ram(object))->floor_z = ((struct object *)ram(object_cursor))->floor_z;
}

/* The current object's screen_x and screen_y = object_cursor's + offset_x and offset_y. */
void place_sprite_near_cursor(uint16_t offset_x, uint16_t offset_y)
{
	((struct object *)ram(current_object))->screen_x = ((struct object *)ram(object_cursor))->screen_x;
	((struct object *)ram(current_object))->screen_y = ((struct object *)ram(object_cursor))->screen_y;
	((struct object *)ram(current_object))->screen_x += offset_x;
	((struct object *)ram(current_object))->screen_y += offset_y;
}

/* Copies the current object's projected_x, projected_y, z and floor_z into object_cursor (x and y are
   left alone). */
void copy_position_to_cursor(void)
{
	((struct object *)ram(object_cursor))->projected_x = ((struct object *)ram(current_object))->projected_x;
	((struct object *)ram(object_cursor))->projected_y = ((struct object *)ram(current_object))->projected_y;
	((struct object *)ram(object_cursor))->z = ((struct object *)ram(current_object))->z;
	((struct object *)ram(object_cursor))->floor_z = ((struct object *)ram(current_object))->floor_z;
}

/* The current object takes object_cursor's x, y, projected_x, projected_y, z and floor_z. */
void copy_position_from_cursor(void)
{
	((struct object *)ram(current_object))->x = ((struct object *)ram(object_cursor))->x;
	((struct object *)ram(current_object))->y = ((struct object *)ram(object_cursor))->y;
	((struct object *)ram(current_object))->projected_x = ((struct object *)ram(object_cursor))->projected_x;
	((struct object *)ram(current_object))->projected_y = ((struct object *)ram(object_cursor))->projected_y;
	((struct object *)ram(current_object))->z = ((struct object *)ram(object_cursor))->z;
	((struct object *)ram(current_object))->floor_z = ((struct object *)ram(object_cursor))->floor_z;
}

/* The current object's screen_x and screen_y = object_cursor's. Its only caller, draw_eel_piece_parts,
   is unused. */
void copy_screen_position_from_cursor(void)
{
	((struct object *)ram(current_object))->screen_x = ((struct object *)ram(object_cursor))->screen_x;
	((struct object *)ram(current_object))->screen_y = ((struct object *)ram(object_cursor))->screen_y;
}

/* Distance and angle (square_root, angle_of_vector) to each player in play, players 3, 2, 1, into the
   per-player and nearest_player variables. Its direction then becomes the last angle worked out plus
   direction_to_player_offsets[nearest_player], an offset (0x1C-0x20) rather than that player's angle, so
   it does not face the nearest player. */
uint32_t face_nearest_player(uint32_t direction, uint32_t octant)
{
	uint16_t dy = 0, player_dx = 0, player_dy = 0;
	uint32_t abs_dy = 0, distance = 0, ignored = 0, player_index = 0, player_object = 0;
	uint16_t diff_x = 0, diff_y = 0;
	uint32_t players_left = 0;

	(*(int16_t *)ram(0x208016u)) = 0x7FFF;
	player_index = 3u;
	for (;;)
	{
		players_left = player_index;
		player_index = players_left - 1u;
		if (players_left == 0u)
			break;
		player_object = 0x208000u + ((const uint32_t *)rom(0x08E2D5u))[player_index];
		player_object = (((player_object) & 0xFFFF0000u) | (((struct player *)ram(player_object))->object));
		if ((((struct object *)ram(player_object))->flags & 0x400u) != 0u)
		{
			(*(uint16_t *)ram(0x208000u + ((const uint16_t *)rom(0x08E2E1u))[player_index])) = 0x7FFFu;
			(*(uint16_t *)ram(0x208000u + ((const uint16_t *)rom(0x08E2E7u))[player_index])) = 0x7FFFu;
			continue;
		}
		diff_x = ((struct object *)ram(player_object))->projected_x - ((struct object *)ram(current_object))->projected_x;
		distance = diff_x;
		player_dx = (uint16_t)distance;
		if ((int16_t)diff_x < 0)
			distance = (uint16_t)(0u - distance);
		diff_y = ((struct object *)ram(player_object))->projected_y_int - ((struct object *)ram(current_object))->projected_y_int;
		abs_dy = diff_y;
		player_dy = (uint16_t)abs_dy;
		if ((int16_t)diff_y < 0)
			abs_dy = (uint16_t)(0u - abs_dy);
		distance = (int16_t)distance;
		abs_dy = (int16_t)abs_dy;
		distance = distance * distance + abs_dy * abs_dy;
		square_root(&distance, &ignored);
		if ((int16_t)distance <= (*(int16_t *)ram(0x208016u)))
		{
			(*(uint8_t *)ram(0x208029u)) = player_index;
			(*(int16_t *)ram(0x208016u)) = distance;
			(*(int16_t *)ram(0x208018u)) = player_dx;
			(*(int16_t *)ram(0x20801Au)) = player_dy;
		}
		(*(uint16_t *)ram(0x208000u + ((const uint16_t *)rom(0x08E2E1u))[player_index])) = distance;
		direction = player_dx;
		dy = (uint16_t)player_dy;
		angle_of_vector(dy, &direction, &octant);
		(*(uint16_t *)ram(0x208000u + ((const uint16_t *)rom(0x08E2E7u))[player_index])) = direction;
	}
	player_index = (*(uint8_t *)ram(0x208029u));
	player_object = 0x208000u + ((const uint32_t *)rom(0x08E2D5u))[player_index];
	player_object = (((player_object) & 0xFFFF0000u) | (((struct player *)ram(player_object))->object));
	(*(int16_t *)ram(0x20802Au)) = ((struct object *)ram(player_object))->z_int;
	(*(int16_t *)ram(0x20802Cu)) = ((struct object *)ram(player_object))->floor_z_int;
	direction = (uint16_t)(direction + ((const uint16_t *)rom(0x08E2E7u))[player_index]);
	((struct object *)ram(current_object))->direction = direction;
	(*(uint16_t *)ram(0x20802Eu)) = direction;
	return octant;
}

/* nearest_player_distance = the smallest |player x - x| (whole x) over the three players, in the game or
   not. */
void find_nearest_player_x(void)
{
	uint16_t distance_x = 0;
	uint32_t player_index = 0, player_object = 0;
	uint16_t diff_x = 0;
	uint32_t checked_index = 0;

	(*(int16_t *)ram(0x208016u)) = 0x7FFF;
	player_index = 2u;
	do
	{
		player_object = 0x208000u + ((const uint32_t *)rom(0x08E2D5u))[player_index];
		player_object = (((player_object) & 0xFFFF0000u) | (((struct player *)ram(player_object))->object));
		diff_x = ((struct object *)ram(player_object))->x_int - ((struct object *)ram(current_object))->x_int;
		distance_x = diff_x;
		if ((int16_t)diff_x < 0)
			distance_x = (uint16_t)(0u - distance_x);
		if ((int16_t)distance_x <= (*(int16_t *)ram(0x208016u)))
			(*(int16_t *)ram(0x208016u)) = distance_x;
		checked_index = player_index;
		player_index = checked_index - 1u;
	} while (checked_index != 0u);
}

/* The current object's direction = the angle to the object at r14 (projected coordinates), then
   distance_to_object, whose distance it hands back. */
uint32_t face_object(void)
{
	uint16_t dy = 0;
	uint32_t dx = 0, ignored = 0;

	dx = (uint16_t)(((struct object *)ram(r14))->projected_x - ((struct object *)ram(current_object))->projected_x);
	dy = (uint16_t)(((struct object *)ram(r14))->projected_y_int - ((struct object *)ram(current_object))->projected_y_int);
	angle_of_vector(dy, &dx, &ignored);
	((struct object *)ram(current_object))->direction = dx;
	return distance_to_object();
}

/* nearest_player_distance = the distance from the current object to the object at r14 (square_root of dx
   * dx + dy * dy, projected coordinates), also handed back. */
uint32_t distance_to_object(void)
{
	uint32_t distance = 0, dy = 0, ignored = 0;

	distance = (int16_t)(((struct object *)ram(r14))->projected_x - ((struct object *)ram(current_object))->projected_x);
	dy = (int16_t)(((struct object *)ram(r14))->projected_y_int - ((struct object *)ram(current_object))->projected_y_int);
	if ((int32_t)distance < 0)
		distance = 0u - distance;
	if ((int32_t)dy < 0)
		dy = 0u - dy;
	distance = distance * distance + dy * dy;
	square_root(&distance, &ignored);
	(*(int16_t *)ram(0x208016u)) = distance;
	return distance;
}

/* The current object's direction = the angle (angle_of_vector) to the object at r14 in projected
   coordinates; hands back angle_of_vector's octant. */
uint32_t direction_to_object(void)
{
	uint16_t dy = 0;
	uint32_t dx = 0, octant = 0;

	dx = (uint16_t)(((struct object *)ram(r14))->projected_x - ((struct object *)ram(current_object))->projected_x);
	dy = (uint16_t)(((struct object *)ram(r14))->projected_y_int - ((struct object *)ram(current_object))->projected_y_int);
	angle_of_vector(dy, &dx, &octant);
	((struct object *)ram(current_object))->direction = dx;
	return octant;
}

/* distance_x = |dx| and distance_y = |dy| (whole x and y) from the current object to the object at r14,
   also kept in distance_to_player_1 and distance_to_player_2. */
void distance_xy_to_object(uint32_t *p_distance_x, uint32_t *p_distance_y)
{
	uint32_t distance_x = 0, distance_y = 0, x_int = 0, y_int = 0;
	uint16_t dx = 0, dy = 0;

	x_int = (uint16_t)((struct object *)ram(r14))->x_int;
	dx = x_int - ((struct object *)ram(current_object))->x_int;
	distance_x = dx;
	if ((int16_t)dx < 0)
		distance_x = (uint16_t)(0u - distance_x);
	(*(int16_t *)ram(0x208022u)) = distance_x;
	y_int = (uint16_t)((struct object *)ram(r14))->y_int;
	dy = y_int - ((struct object *)ram(current_object))->y_int;
	distance_y = dy;
	if ((int16_t)dy < 0)
		distance_y = (uint16_t)(0u - distance_y);
	(*(int16_t *)ram(0x208024u)) = distance_y;
	*p_distance_x = distance_x;
	*p_distance_y = distance_y;
}

/* Gravity for the current object: speed_z + 0x6000 each frame z is not floor_z, and when z + speed_z
   would reach floor_z it lands (z = floor_z, speed_z 0); z itself is moved elsewhere. height = floor_z -
   z (0 on the floor); over_pit = 1 when floor_z_int is 0x800 or more. */
void fall_to_floor(uint32_t *p_height, uint32_t *p_over_pit, uint32_t *p_z)
{
	uint8_t over_pit = 0;
	uint32_t height = 0;

	over_pit = 1u;
	if (((struct object *)ram(current_object))->floor_z_int < 0x800)
		over_pit = 0u;
	if ((uint32_t)((struct object *)ram(current_object))->z != (uint32_t)((struct object *)ram(current_object))->floor_z)
	{
		((struct object *)ram(current_object))->speed_z += 0x6000u;
		if ((int32_t)((uint32_t)((struct object *)ram(current_object))->z + ((struct object *)ram(current_object))->speed_z) < ((struct object *)ram(current_object))->floor_z)
		{
			*p_z = ((struct object *)ram(current_object))->z;
			height = ((struct object *)ram(current_object))->floor_z - *p_z;
		}
		else
		{
			((struct object *)ram(current_object))->z = ((struct object *)ram(current_object))->floor_z;
			((struct object *)ram(current_object))->speed_z = 0;
			height = 0u;
		}
	}
	else
	{
		((struct object *)ram(current_object))->speed_z = 0;
		height = 0u;
	}
	*p_height = height;
	*p_over_pit = (*p_over_pit & 0xFFFFFF00u) | over_pit;
}

/* The current object's screen position = object_cursor's, moved down to object_cursor's floor (floor_z -
   z): the place for its shadow. Hands back 0xFF, the bucket drawn first (under everything). */
uint32_t place_sprite_at_cursor_floor(void)
{
	uint32_t bucket = 0;

	((struct object *)ram(current_object))->screen_x = ((struct object *)ram(object_cursor))->screen_x;
	((struct object *)ram(current_object))->screen_y = ((struct object *)ram(object_cursor))->screen_y;
	((struct object *)ram(current_object))->screen_y += ((struct object *)ram(object_cursor))->floor_z_int - ((struct object *)ram(object_cursor))->z_int;
	bucket = 0xFFu;
	return bucket;
}

/* speed_x = sine_table[direction] * speed >> 6 and speed_y = -(cosine_table[direction] * speed >> 6),
   with direction taken & 0x3FF. */
void direction_to_speed(uint32_t speed, uint32_t *p_direction, uint32_t *p_speed_x, uint32_t *p_speed_y)
{
	uint32_t direction = *p_direction;

	direction &= 0x3FFu;
	*p_speed_x = (int32_t)(((const int16_t *)rom(0x101632u))[direction] * speed) >> 6;
	*p_speed_y = 0u - ((int32_t)(((const int16_t *)rom(0x101832u))[direction] * speed) >> 6);
	*p_direction = direction;
}

/* Hands back the current object's screen_y moved down by object_cursor's floor_z - z (whole pixels):
   where object_cursor's floor is on the screen. */
uint32_t cursor_floor_screen_y(uint32_t floor_screen_y)
{
	floor_screen_y = (floor_screen_y & ~0xFFFFu) | (uint16_t)((struct object *)ram(object_cursor))->floor_z_int;
	floor_screen_y = (floor_screen_y & ~0xFFFFu) | (uint16_t)(floor_screen_y - ((struct object *)ram(object_cursor))->z_int);
	floor_screen_y = (floor_screen_y & ~0xFFFFu) | (uint16_t)(floor_screen_y + ((struct object *)ram(current_object))->screen_y);
	return floor_screen_y;
}

/* Unused: sets explosion frames 0xF-0x1F, palette 0x82A0 and handler explosion_animate, then runs on
   into explode_object, which puts frames 0x1F-0x2B and palette 0x86D0 over them (and plays sound 7). */
void explode_object_medium(void)
{
	((struct object *)ram(current_object))->explode_object.frame_index = 0xF;
	((struct object *)ram(current_object))->explode_object.last_frame = 0x1F;
	((struct object *)ram(current_object))->sprite_palette = 0x82A0u;
	((struct object *)ram(current_object))->handler = 0x08E49Eu;
	explode_object();
}

/* Turns the current object into the big explosion: explosion_frames 0x1F-0x2B, palette 0x86D0, handler
   explosion_animate; sound 7. */
void explode_object(void)
{
	uint8_t sound_id = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	((struct object *)ram(current_object))->explode_object.frame_index = 0x1F;
	((struct object *)ram(current_object))->explode_object.last_frame = 0x2B;
	((struct object *)ram(current_object))->sprite_palette = 0x86D0u;
	((struct object *)ram(current_object))->handler = 0x08E49Eu;
	((struct object *)ram(current_object))->explode_object.frame_toggle = 0u;
	sound_id = 7u;
	play_sound(sound_id, &ignored, &ignored_2);
}

/* An explosion: unproject_object, the next explosion_frames frame every other frame until last_frame,
   then removed (delete_object_and_children); drawn every frame (queue_sprite). */
void explosion_animate(void)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t toggle = 0;

	unproject_object(&ignored, &ignored_2, &ignored_3, &ignored_4);
	((struct object *)ram(current_object))->explosion.frame_toggle++;
	toggle = ((struct object *)ram(current_object))->explosion.frame_toggle & 1u;
	((struct object *)ram(current_object))->explosion.frame_toggle = toggle;
	if (toggle == 0u)
	{
		((struct object *)ram(current_object))->explosion.frame_index++;
		if (((struct object *)ram(current_object))->explosion.last_frame < ((struct object *)ram(current_object))->explosion.frame_index)
		{
			delete_object_and_children(&ignored, &ignored_2, &ignored_3);
			return;
		}
	}
	((struct object *)ram(current_object))->sprite_frame = ((const uint16_t *)rom(0x08E4D2u))[(uint8_t)((struct object *)ram(current_object))->explosion.frame_index];
	queue_sprite(0u);
}

/* Releases rings_to_release rings from object_cursor, one scatter_rings_random ring at a time: at its
   position, heading released_ring_angle at speed 0x60 (spread at random with released_rings_random),
   each 0x10 frames after the last (released_ring_wait); released_ring_flip marks their palettes. It
   never checks that a ring was made. */
void drop_rings(uint32_t shadow, uint32_t *p_allocated, uint32_t *p_random_value, uint32_t *p_ring)
{
	uint32_t ring = *p_ring;
	uint32_t count = 0, ignored = 0, ignored_2 = 0, new_ring = 0, random_bits = 0;

	if ((int16_t)(*(uint16_t *)ram(0x208032u)) <= 0)
		return;
	r14 = 0u;
	do
	{
		if ((*(uint8_t *)ram(0x208035u)) != 0u)
		{
			next_random(&shadow, &ignored, &ignored_2);
			*p_random_value = shadow;
		}
		count = 1u;
		scatter_rings_random(shadow, count, p_allocated, &ring);
		new_ring = ring;
		copy_position_to(new_ring);
		((struct object *)ram(new_ring))->parent = object_cursor;
		((struct object *)ram(new_ring))->animation_speed = 0u;
		((struct object *)ram(new_ring))->animation_timer = 0;
		((struct object *)ram(new_ring))->speed_z_int++;
		((struct object *)ram(new_ring))->released_ring.bounce_speed = ((struct object *)ram(new_ring))->speed_z;
		((struct object *)ram(new_ring))->direction = (*(uint16_t *)ram(0x208030u));
		((struct object *)ram(new_ring))->speed = 0x60;
		((struct object *)ram(new_ring))->speed &= 0x3FFu;
		((struct object *)ram(new_ring))->released_ring.release_delay = r14;
		((struct object *)ram(new_ring))->handler = 0x08E61Bu;
		r14 = (uint16_t)(r14 + 0x10u);
		if ((*(uint8_t *)ram(0x208035u)) != 0u)
		{
			random_bits = *p_random_value & 0x7Fu;
			((struct object *)ram(new_ring))->speed += random_bits;
			((struct object *)ram(new_ring))->direction += (random_bits & 0x3Fu) * 2u;
			((struct object *)ram(new_ring))->direction -= 0x40u;
		}
		shadow = (((new_ring) & 0xFFFF0000u) | (((struct object *)ram(new_ring))->child));
		((struct object *)ram(shadow))->child = 0xFFFFu;
		if ((*(uint8_t *)ram(0x208034u)) == 1u)
		{
			((struct object *)ram(ring))->sprite_palette |= 1u;
			((struct object *)ram(shadow))->sprite_palette |= 0x2000u;
			((struct object *)ram(ring))->sprite_palette ^= 0x8000u;
			((struct object *)ram(shadow))->sprite_palette ^= 0x8000u;
		}
		if ((*(uint8_t *)ram(0x208034u)) == 2u)
		{
			((struct object *)ram(ring))->sprite_palette |= 0x4000u;
			((struct object *)ram(shadow))->sprite_palette |= 0x4000u;
			((struct object *)ram(ring))->sprite_palette ^= 0x8000u;
			((struct object *)ram(shadow))->sprite_palette ^= 0x8000u;
		}
		(*(uint16_t *)ram(0x208032u))--;
	} while ((int16_t)(*(uint16_t *)ram(0x208032u)) >= 1);
	*p_ring = ring;
}

/* A released ring waiting release_delay frames, undrawn; then sound 0x13 and it goes on as
   released_ring_start. */
void released_ring_wait(void)
{
	uint8_t sound_id = 0;
	uint32_t ignored = 0, ignored_2 = 0;
	uint16_t release_delay = 0;

	release_delay = ((struct object *)ram(current_object))->released_ring.release_delay;
	((struct object *)ram(current_object))->released_ring.release_delay = release_delay - 1u;
	if (release_delay != 0u)
		return;
	sound_id = 0x13u;
	play_sound(sound_id, &ignored, &ignored_2);
	((struct object *)ram(current_object))->released_ring.release_delay = 0u;
	((struct object *)ram(current_object))->handler = 0x08E639u;
	released_ring_start();
}

/* A released ring that cannot be collected yet: released_ring_move for pickup_delay frames, then it
   clears flag 0x200 and goes on as released_ring_bounce. */
void released_ring_start(void)
{
	uint16_t pickup_delay = 0;

	((struct object *)ram(current_object))->released_ring.projected_x_carry_int = 0;
	pickup_delay = ((struct object *)ram(current_object))->released_ring.pickup_delay;
	((struct object *)ram(current_object))->released_ring.pickup_delay = pickup_delay - 1u;
	if ((int16_t)pickup_delay > 1)
	{
		released_ring_move(0u);
		return;
	}
	((struct object *)ram(current_object))->flags &= ~0x200u;
	((struct object *)ram(current_object))->handler = 0x08E650u;
	released_ring_bounce();
}

/* A released ring that can be collected, for lifetime frames: with flag 0x20 its direction turns by
   0x300 (speeds cleared for the frame); touched (flag 4) it plays sound 0x13 and is removed, unless its
   toucher is a player in state 0xD or 0x20 with hurt_contact_delay. Else released_ring_move; at the end
   it goes on as scattered_ring_vanish. */
void released_ring_bounce(void)
{
	uint8_t sound_id = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, object = 0, player = 0;
	uint16_t lifetime = 0;

	lifetime = ((struct object *)ram(current_object))->released_ring.lifetime;
	((struct object *)ram(current_object))->released_ring.lifetime = lifetime - 1u;
	if ((int16_t)lifetime > 1)
	{
		if ((((struct object *)ram(current_object))->flags & 0x20u) != 0u)
		{
			((struct object *)ram(current_object))->direction += 0x300u;
			((struct object *)ram(current_object))->direction &= 0x3FFu;
			((struct object *)ram(current_object))->speed_x = 0;
			((struct object *)ram(current_object))->speed_y = 0;
		}
		if ((((struct object *)ram(current_object))->flags & 4u) == 0u)
		{
			released_ring_move(player);
			return;
		}
		object = (((current_object) & 0xFFFF0000u) | (((struct object *)ram(current_object))->touched_by));
		if ((int8_t)((struct object *)ram(object))->kind <= 2)
		{
			player = (0x208400u + ((1) - 1u) * 0x200u) + ((uint32_t)((struct object *)ram(object))->player << 9);
			if ((((struct player *)ram(player))->state == 0xDu || ((struct player *)ram(player))->state == 0x20u) && (uint8_t)((struct player *)ram(player))->hurt_contact_delay != 0u)
			{
				released_ring_move(player);
				return;
			}
		}
		sound_id = 0x13u;
		play_sound(sound_id, &ignored, &ignored_2);
		delete_object_and_children(&ignored_3, &ignored_2, &ignored_4);
		return;
	}
	((struct object *)ram(current_object))->sprite_flags = 4u;
	((struct object *)ram(current_object))->sprite_scale = 0x100u;
	object = (((current_object) & 0xFFFF0000u) | (((struct object *)ram(current_object))->child));
	((struct object *)ram(object))->sprite_flags = 0u;
	((struct object *)ram(object))->sprite_scale = 0x100u;
	((struct object *)ram(current_object))->handler = 0x01E9C1u;
	scattered_ring_vanish();
}

/* Moves a released ring (move_object_projected, fall_to_floor): on landing it bounces up again at
   bounce_speed - bounce_speed / 4 + 0x10000, and in the air animation_frame gains 3 a frame. Speeds from
   direction and speed, animate (spawn_ring_glint at frame 4), drawn at its floor with its shadow, in the
   touchable and rider lists. */
void released_ring_move(uint32_t cursor)
{
	uint32_t bounce_speed = 0, direction = 0, height = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0, speed = 0, speed_x = 0, speed_y = 0;

	move_object_projected(&ignored, &ignored_2, &ignored_3, &cursor);
	fall_to_floor(&height, &ignored_4, &ignored_2);
	((struct object *)ram(current_object))->animation_frame += 3u;
	if (height == 0u)
	{
		((struct object *)ram(current_object))->animation_frame -= 3u;
		bounce_speed = ((struct object *)ram(current_object))->released_ring.bounce_speed;
		bounce_speed = bounce_speed - ((int32_t)bounce_speed >> 2) + 0x10000u;
		((struct object *)ram(current_object))->released_ring.bounce_speed = bounce_speed;
		((struct object *)ram(current_object))->speed_z = bounce_speed;
	}
	direction = ((struct object *)ram(current_object))->direction;
	speed = ((struct object *)ram(current_object))->speed;
	direction_to_speed(speed, &direction, &speed_x, &speed_y);
	((struct object *)ram(current_object))->speed_x = speed_x;
	((struct object *)ram(current_object))->speed_y = speed_y;
	animate(&ignored_4, &ignored_5, &ignored_6);
	if (((struct object *)ram(current_object))->animation_frame == 4u)
		spawn_ring_glint(cursor);
	queue_sprite_at_floor();
	add_to_touchable_list(direction);
	add_to_rider_list();
	draw_child_shadow();
}

/* Throws count debris pieces (spawn_objects, handler debris_fly) from the current object: each at its
   position, palette 0x8300, thrown up at a random speed_z, with random extra zoom, direction and speed
   on top of the object's own, debris_frames 0-9 or (odd random) 0xA-0x13. */
void spawn_debris(uint32_t spawned, uint16_t count, uint32_t block)
{
	uint32_t ignored = 0, ignored_2 = 0, object = 0, random_byte = 0, random_value = 0;

	(*(uint16_t *)ram(0x208008u)) = count;
	spawn_objects(0x08E73Au, &spawned, &random_value, &block);
	if (spawned == 0u)
		return;
	r14 = random_value;
	do
	{
		((struct object *)ram(r14))->x = ((struct object *)ram(current_object))->x;
		((struct object *)ram(r14))->y = ((struct object *)ram(current_object))->y;
		((struct object *)ram(r14))->projected_x = ((struct object *)ram(current_object))->projected_x;
		((struct object *)ram(r14))->projected_y = ((struct object *)ram(current_object))->projected_y;
		((struct object *)ram(r14))->z = ((struct object *)ram(current_object))->z;
		((struct object *)ram(r14))->z_int--;
		((struct object *)ram(r14))->floor_z = ((struct object *)ram(current_object))->floor_z;
		((struct object *)ram(r14))->sprite_palette = 0x8300u;
		((struct object *)ram(r14))->debris.last_frame = 9;
		((struct object *)ram(r14))->debris.frame_timer = 3u;
		((struct object *)ram(r14))->debris.lifetime = 0xFu;
		next_random(&random_value, &ignored, &ignored_2);
		((struct object *)ram(r14))->sprite_scale += random_value & 0xFFu;
		((struct object *)ram(r14))->speed_z = -0x40000;
		random_byte = random_value & 0x3FFFFu;
		((struct object *)ram(r14))->speed_z -= random_byte;
		((struct object *)ram(r14))->direction = ((struct object *)ram(current_object))->direction;
		random_byte = random_byte & 0xFFu;
		((struct object *)ram(r14))->direction += random_byte;
		((struct object *)ram(r14))->speed = ((struct object *)ram(current_object))->speed;
		random_byte &= 0x3Fu;
		((struct object *)ram(r14))->speed += random_byte;
		if ((random_byte & 1u) != 0u)
		{
			((struct object *)ram(r14))->debris.frame_index = 0xA;
			((struct object *)ram(r14))->debris.last_frame = 0x13;
		}
		((struct object *)ram(r14))->handler = 0x08E7FDu;
		object = r14;
		r14 = (((r14) & 0xFFFF0000u) | (((struct object *)ram(r14))->child));
		((struct object *)ram(object))->child = 0xFFFFu;
	} while ((uint16_t)r14 != 0xFFFFu);
}

/* A debris piece: move_object_projected, removed off screen (delete_if_off_screen), fall_to_floor. In
   the air its direction and speed are added to speed_x/speed_y every frame and it steps through
   debris_frames every 4 frames (back 9 past last_frame); on the floor it stops and blinks for lifetime
   frames, then goes. */
void debris_fly(void)
{
	uint32_t deleted = 0, direction = 0, height = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, speed = 0, speed_x = 0, speed_y = 0;
	uint16_t phase = 0, lifetime = 0;

	move_object_projected(&ignored, &ignored_2, &ignored_3, &ignored_4);
	delete_if_off_screen(&deleted, &ignored_2, &ignored_3);
	if ((uint8_t)deleted != 0u)
		return;
	fall_to_floor(&height, &ignored_5, &ignored_2);
	if (height != 0u)
	{
		direction = ((struct object *)ram(current_object))->direction;
		speed = ((struct object *)ram(current_object))->speed;
		direction_to_speed(speed, &direction, &speed_x, &speed_y);
		((struct object *)ram(current_object))->speed_x += speed_x;
		((struct object *)ram(current_object))->speed_y += speed_y;
		((struct object *)ram(current_object))->debris.frame_timer++;
		phase = ((struct object *)ram(current_object))->debris.frame_timer & 3u;
		((struct object *)ram(current_object))->debris.frame_timer = phase;
		if (phase != 0u)
		{
			queue_sprite_at_floor();
			return;
		}
		((struct object *)ram(current_object))->debris.frame_index++;
		if (((struct object *)ram(current_object))->debris.last_frame < ((struct object *)ram(current_object))->debris.frame_index)
			((struct object *)ram(current_object))->debris.frame_index -= 9u;
		((struct object *)ram(current_object))->sprite_frame = ((const uint16_t *)rom(0x08E87Eu))[(uint8_t)((struct object *)ram(current_object))->debris.frame_index];
		queue_sprite_at_floor();
		return;
	}
	((struct object *)ram(current_object))->speed_x = 0;
	((struct object *)ram(current_object))->speed_y = 0;
	lifetime = ((struct object *)ram(current_object))->debris.lifetime;
	((struct object *)ram(current_object))->debris.lifetime = lifetime - 1u;
	if (lifetime == 0u)
	{
		delete_current_object();
		return;
	}
	if ((((struct object *)ram(current_object))->debris.lifetime & 1u) != 0u)
		return;
	queue_sprite_at_floor();
}

/* Spawns the stage's object_group_spawns records as the scroll reaches them. Types 0, 2 and 6 build a
   group (spawn_object_groups_build_group; 2 with group_depth_step -8, 6 silent), 1 and 8 spawn a group
   leader, 3 a group slot trigger, 4 an ice platform leader, 5 a sand block leader, 7 a waterfall. */
void spawn_object_groups(uint32_t *p_list_offset, uint32_t *p_free_stack, uint32_t *p_slope_z, uint32_t *p_count, uint32_t *p_object)
{
	uint32_t kind_index = 0, record = 0, spawned = 0;
	uint16_t spawn_position = 0;
	uint32_t init_flags = 0;

	init_flags = (*(uint32_t *)ram(0x20F0BCu));
	(*(uint32_t *)ram(0x20F0BCu)) = init_flags | 0x200u;
	if ((init_flags & 0x200u) == 0u)
	{
		*p_list_offset = ((const uint16_t *)rom(0x0920F9u))[(*(uint16_t *)ram(0x20F06Eu))];
		(*(uint32_t *)ram(0x20E55Cu)) = 0x0920F9u + *p_list_offset;
	}
	for (;;)
	{
		record = (*(uint32_t *)ram(0x20E55Cu));
		spawn_position = ((const struct group_spawn_record *)rom(record))->position;
		record += 2u;
		if ((*(uint16_t *)ram(0x20E435u)) < spawn_position)
		{
			return;
		}
		(*(uint8_t *)ram(0x20F0F6u)) = 0u;
		kind_index = ((const struct group_spawn_record *)rom(record - 0x2u))->kind * 2u;
		record++;
		switch (kind_index)
		{
		case 0x0u:
			spawn_object_groups_no_depth_step(record, p_list_offset, p_slope_z, p_count, p_object);
			return;
		case 0x2u:
		case 0x10u:
			spawn_group_leader(record, &spawned, p_object);
			if (spawned == 0u)
			{
				return;
			}
			(*(uint32_t *)ram(0x20E55Cu)) += 0xEu;
			continue;
		case 0x4u:
			(*(int8_t *)ram(0x20E539u)) = -8;
			spawn_object_groups_build_group(record, p_list_offset, p_slope_z, p_count, p_object);
			return;
		case 0x6u:
			spawn_group_slot_trigger(record, &spawned, p_count, p_object);
			if (spawned == 0u)
			{
				return;
			}
			(*(uint32_t *)ram(0x20E55Cu)) += 0xEu;
			continue;
		case 0x8u:
			spawn_ice_platform_leader(record, &spawned, p_list_offset, p_object);
			if (spawned == 0u)
			{
				return;
			}
			(*(uint32_t *)ram(0x20E55Cu)) += 0xEu;
			continue;
		case 0xAu:
			spawn_sand_block_leader(record, &spawned, p_object);
			if (spawned == 0u)
			{
				return;
			}
			(*(uint32_t *)ram(0x20E55Cu)) += 0xEu;
			continue;
		case 0xCu:
			spawn_object_groups_mark_silent(record, p_list_offset, p_slope_z, p_count, p_object);
			return;
		case 0xEu:
			spawn_waterfall(record, &spawned, p_free_stack, p_object);
			if (spawned == 0u)
			{
				return;
			}
			(*(uint32_t *)ram(0x20E55Cu)) += 0xEu;
			continue;
		default:
			invalid_jump(0x9125Eu + kind_index);
		}
	}
}

/* Type 6 records: group_silent = 0xFF, which the members keep (crumbling_floor_start_falling then plays
   no sound 0xD), then as type 0 (spawn_object_groups_no_depth_step). */
void spawn_object_groups_mark_silent(uint32_t record, uint32_t *p_list_offset, uint32_t *p_slope_z, uint32_t *p_count, uint32_t *p_object)
{
	uint32_t list_offset = *p_list_offset;

	(*(uint8_t *)ram(0x20F0F6u)) = 0xFFu;
	spawn_object_groups_no_depth_step(record, &list_offset, p_slope_z, p_count, p_object);
	*p_list_offset = (*p_list_offset & 0xFFFF0000u) | (list_offset & 0xFFFFu);
}

/* Types 0 and 6: group_depth_step = 0 (type 2 sets -8), then spawn_object_groups_build_group. */
void spawn_object_groups_no_depth_step(uint32_t record, uint32_t *p_list_offset, uint32_t *p_slope_z, uint32_t *p_count, uint32_t *p_object)
{
	uint32_t list_offset = *p_list_offset;

	(*(int8_t *)ram(0x20E539u)) = 0;
	spawn_object_groups_build_group(record, &list_offset, p_slope_z, p_count, p_object);
	*p_list_offset = (*p_list_offset & 0xFFFF0000u) | (list_offset & 0xFFFFu);
}

/* Builds a group when the scroll is within 0x100 past the record (else skips it) and free_object_stack
   has room: a row of stage_object_records members sharing the leader, floor block and direction, each
   numbered and set on the floor (slope too), depth_offset stepped by group_depth_step; a group slot when
   the record asks. */
void spawn_object_groups_build_group(uint32_t record, uint32_t *p_list_offset, uint32_t *p_slope_z, uint32_t *p_count, uint32_t *p_object)
{
	uint16_t list_offset = (uint16_t)*p_list_offset;
	uint32_t count = *p_count;
	uint32_t object = *p_object;
	uint32_t floor_block_record = 0, free_count = 0, member_record = 0, slope_number = 0, slope_record = 0, slot_cursor = 0;
	uint16_t slot_taken = 0, members_left = 0;

	if ((uint16_t)((*(uint16_t *)ram(0x20E435u)) - ((const struct group_spawn_record *)rom(record - 0x3u))->position) >= 0x100u)
	{
		(*(uint32_t *)ram(0x20E55Cu)) += 0x18u;
		*p_list_offset = (*p_list_offset & 0xFFFF0000u) | list_offset;
		*p_count = count;
		*p_object = object;
		return;
	}
	(*(uint16_t *)ram(0x20F0F4u)) = ((uint16_t *)ram(0x20E562u))[((const struct group_spawn_record *)rom(record - 0x3u))->leader];
	record++;
	(*(uint8_t *)ram(0x20E5A8u)) = ((const struct group_spawn_record *)rom(record - 0x4u))->takes_slot;
	record += 2u;
	(*(uint32_t *)ram(0x20F0ECu)) = ((const struct group_spawn_record *)rom(record - 0x6u))->floor_block;
	record += 4u;
	(*(int16_t *)ram(0x20F094u)) = ((const struct group_spawn_record *)rom(record - 0xAu))->member_count;
	record += 2u;
	if ((*(int16_t *)ram(0x20E900u)) < (*(int16_t *)ram(0x20F094u)))
		return;
	(*(uint16_t *)ram(0x20F096u)) = ((const struct group_spawn_record *)rom(record - 0xCu))->step_x;
	record += 2u;
	(*(uint16_t *)ram(0x20F098u)) = ((const struct group_spawn_record *)rom(record - 0xEu))->step_y;
	record += 2u;
	(*(uint16_t *)ram(0x20F0F2u)) = ((const struct group_spawn_record *)rom(record - 0x10u))->direction;
	record += 2u;
	(*(uint16_t *)ram(0x20F09Au)) = ((const struct group_spawn_record *)rom(record - 0x12u))->member_x;
	record += 2u;
	(*(uint16_t *)ram(0x20F09Cu)) = ((const struct group_spawn_record *)rom(record - 0x14u))->member_y;
	object = ((const struct group_spawn_record *)rom(record - 0x14u))->member_template + 0x093269u;
	(*(uint32_t *)ram(0x20F09Eu)) = object;
	(*(uint8_t *)ram(0x20F0A8u)) = 0u;
	if ((*(uint8_t *)ram(0x20E5A8u)) != 0u)
	{
		slot_cursor = 0x209F00u;
		count = 0x40u;
		do
		{
			slot_taken = mem_read16(slot_cursor);
			slot_cursor += 2u;
			count--;
		} while ((count != 0u) & (slot_taken != 0u));
		mem_write16(slot_cursor - 2u, 1u);
		count = (count & ~0xFFFFu) | (uint16_t)(count + 1u);
		list_offset = (uint16_t)(0x40u - count);
		(*(uint16_t *)ram(0x20E5AAu)) = list_offset;
	}
	do
	{
		allocate_object_outside_loop(&free_count, &object);
		if (free_count == 0u)
		{
			*p_list_offset = (*p_list_offset & 0xFFFF0000u) | list_offset;
			*p_count = count;
			*p_object = object;
			return;
		}
		((struct object *)ram(object))->x_int = (*(uint16_t *)ram(0x20F09Au));
		((struct object *)ram(object))->x_fraction = 0u;
		(*(uint16_t *)ram(0x20F09Au)) += (*(uint16_t *)ram(0x20F096u));
		((struct object *)ram(object))->y_int = (*(uint16_t *)ram(0x20F09Cu));
		((struct object *)ram(object))->y_fraction = 0u;
		(*(uint16_t *)ram(0x20F09Cu)) += (*(uint16_t *)ram(0x20F098u));
		member_record = (*(uint32_t *)ram(0x20F09Eu));
		((struct object *)ram(object))->sprite_flags = ((const struct stage_object_record *)rom(member_record))->sprite_flags;
		member_record += 2u;
		((struct object *)ram(object))->sprite_frame = ((const struct stage_object_record *)rom(member_record - 0x2u))->sprite_frame;
		member_record += 2u;
		((struct object *)ram(object))->sprite_palette = ((const struct stage_object_record *)rom(member_record - 0x4u))->sprite_palette;
		member_record += 2u;
		((struct object *)ram(object))->handler = ((const struct stage_object_record *)rom(member_record - 0x6u))->handler;
		member_record += 4u;
		((struct object *)ram(object))->animation = ((const struct stage_object_record *)rom(member_record - 0xAu))->animation;
		member_record += 4u;
		((struct object *)ram(object))->hitbox_size_x = ((const struct stage_object_record *)rom(member_record - 0xEu))->hitbox_size_x;
		member_record += 2u;
		((struct object *)ram(object))->hitbox_size_y = ((const struct stage_object_record *)rom(member_record - 0x10u))->hitbox_size_y;
		member_record += 2u;
		((struct object *)ram(object))->sprite_offset_x = ((const struct stage_object_record *)rom(member_record - 0x12u))->sprite_offset_x;
		member_record++;
		((struct object *)ram(object))->sprite_offset_y = ((const struct stage_object_record *)rom(member_record - 0x13u))->sprite_offset_y;
		((struct object *)ram(object))->group_member.depth_offset = ((const struct stage_object_record *)rom(member_record - 0x13u))->depth_offset;
		((struct object *)ram(object))->floor_block = (*(uint32_t *)ram(0x20F0ECu));
		((struct object *)ram(object))->direction = (*(uint16_t *)ram(0x20F0F2u));
		((struct object *)ram(object))->parent = (*(uint16_t *)ram(0x20F0F4u));
		((struct object *)ram(object))->group_member.normal_palette = ((struct object *)ram(object))->sprite_palette;
		((struct object *)ram(object))->group_member.silent_row = (*(uint8_t *)ram(0x20F0F6u));
		((struct object *)ram(object))->member_number = (*(uint8_t *)ram(0x20F0A8u));
		(*(uint8_t *)ram(0x20F0A8u))++;
		((struct object *)ram(object))->group_member.group_slot = (*(uint16_t *)ram(0x20E5AAu));
		((struct object *)ram(object))->spawn_arg_1_low = (*(uint8_t *)ram(0x20E5A8u));
		((struct object *)ram(object))->animation_frame = 0u;
		((struct object *)ram(object))->animation_timer = 0;
		((struct object *)ram(object))->animation_speed = 6u;
		((struct object *)ram(object))->floor_slope = mem_read8((*(uint32_t *)ram(0x20F070u)) + 2u + ((struct object *)ram(object))->floor_block + 0x13u);
		((struct object *)ram(object))->flags = 0u;
		((struct object *)ram(object))->member_state = 0u;
		if ((uint8_t)(*(int8_t *)ram(0x20E539u)) != 0u)
		{
			list_offset = (uint16_t)(*(int8_t *)ram(0x20E539u));
			((struct object *)ram(object))->group_member.depth_offset += (uint32_t)(*(int16_t *)ram(0x20F094u)) * list_offset;
		}
		floor_block_record = (*(uint32_t *)ram(0x20F070u)) + 2u + ((struct object *)ram(object))->floor_block;
		((struct object *)ram(object))->floor_z_int = ((const struct floor_block *)rom(floor_block_record))->height;
		((struct object *)ram(object))->floor_z_fraction = 0u;
		if (((const struct floor_block *)rom(floor_block_record))->slope != 0u)
		{
			slope_number = ((const struct floor_block *)rom(floor_block_record))->slope;
			slope_record = 0x10DF44u + (uint16_t)(slope_number * 2u) * 4u;
			if ((((const struct floor_slope *)rom(slope_record))->flags & 2u) == 0u)
				*p_slope_z = (uint32_t)((struct object *)ram(object))->y - ((const struct floor_block *)rom(floor_block_record))->y_min;
			else
				*p_slope_z = (uint32_t)((struct object *)ram(object))->x - ((const struct floor_block *)rom(floor_block_record))->x_min;
			*p_slope_z = (uint32_t)((int32_t)*p_slope_z >> 16) * ((const struct floor_slope *)rom(slope_record))->factor;
			((struct object *)ram(object))->floor_z += *p_slope_z;
		}
		((struct object *)ram(object))->z = ((struct object *)ram(object))->floor_z;
		members_left = (*(int16_t *)ram(0x20F094u));
		(*(int16_t *)ram(0x20F094u)) = members_left - 1u;
	} while ((int16_t)members_left > 1);
	(*(uint32_t *)ram(0x20E55Cu)) += 0x18u;
	*p_list_offset = (*p_list_offset & 0xFFFF0000u) | list_offset;
	*p_count = count;
	*p_object = object;
}

/* A crumbling floor block of a group (stage 4 rock ledges, stage 9 ice blocks), a platform: within 0x60
   of its leader (parent) it cracks, once the leader passes it falls with gravity 0x2000 and is removed
   below the screen; a rider with flag 0x400000 makes it fall at once. While grey_screen_active it is
   only drawn, in palette 0x83A0. */
void crumbling_floor_update(void)
{
	uint32_t at_last_step = 0, depth = 0, ignored = 0, ignored_2 = 0;

	switch (((struct object *)ram(current_object))->crumbling_floor.state)
	{
	case 0:
	case 3:
		project_object(&ignored, &ignored_2);
		((struct object *)ram(current_object))->crumbling_floor.state++;
	case 1:
		update_screen_position(&ignored, &ignored_2);
		if ((*(uint8_t *)ram(0x20E59Au)) != 0u)
		{
			((struct object *)ram(current_object))->sprite_palette = 0x83A0u;
			crumbling_floor_draw();
			return;
		}
		if ((*(uint8_t *)ram(0x20E59Bu)) != 0u)
			((struct object *)ram(current_object))->sprite_palette = ((struct object *)ram(current_object))->crumbling_floor.normal_palette;
		if ((((struct object *)ram(current_object))->flags & 8u) != 0u && (((struct object *)ram((((current_object) & 0xFFFF0000u) | (((struct object *)ram(current_object))->platform))))->flags & 0x400000u) != 0u)
			((struct object *)ram(current_object))->flags |= 0x400000u;
		if ((((struct object *)ram(current_object))->flags & 0x400000u) != 0u)
		{
			crumbling_floor_play_crack_steps();
			return;
		}
		current_player = current_object;
		current_player = (((current_player) & 0xFFFF0000u) | (((struct object *)ram(current_object))->parent));
		switch (((struct object *)ram(current_object))->direction)
		{
		case 0:
		case 4:
			if (((struct object *)ram(current_object))->y_int <= ((struct object *)ram(current_player))->y_int)
			{
				crumbling_floor_start_falling();
				return;
			}
			if (((struct object *)ram(current_object))->y_int <= (int16_t)(((struct object *)ram(current_player))->y_int + 0x60u))
			{
				crumbling_floor_crack();
				return;
			}
			crumbling_floor_draw();
			return;
		case 1:
			if (((struct object *)ram(current_player))->y_int <= ((struct object *)ram(current_object))->y_int)
			{
				crumbling_floor_start_falling();
				return;
			}
			if ((int16_t)(((struct object *)ram(current_player))->y_int - 0x60u) <= ((struct object *)ram(current_object))->y_int)
			{
				crumbling_floor_crack();
				return;
			}
			crumbling_floor_draw();
			return;
		case 2:
			if (((struct object *)ram(current_object))->x_int <= ((struct object *)ram(current_player))->x_int)
			{
				crumbling_floor_start_falling();
				return;
			}
			if (((struct object *)ram(current_object))->x_int <= (int16_t)(((struct object *)ram(current_player))->x_int + 0x60u))
			{
				crumbling_floor_crack();
				return;
			}
			crumbling_floor_draw();
			return;
		case 3:
			if (((struct object *)ram(current_player))->x_int <= ((struct object *)ram(current_object))->x_int)
			{
				crumbling_floor_start_falling();
				return;
			}
			if ((int16_t)(((struct object *)ram(current_player))->x_int - 0x60u) <= ((struct object *)ram(current_object))->x_int)
			{
				crumbling_floor_crack();
				return;
			}
			crumbling_floor_draw();
			return;
		default:
			invalid_jump(0x91555u + ((struct object *)ram(current_object))->direction * 2u);
		}
		break;
	case 2:
		((struct object *)ram(current_object))->speed_z += 0x2000u;
		((struct object *)ram(current_object))->z += ((struct object *)ram(current_object))->speed_z;
		project_object(&ignored, &ignored_2);
		if (((struct object *)ram(current_object))->animation_timer < 0)
			apply_step_screen_offset();
		else
		{
			at_last_step = animate_with_screen_offset(0u);
			if ((int8_t)at_last_step < 0)
				((struct object *)ram(current_object))->animation_timer = -1;
		}
		if (((struct object *)ram(current_object))->screen_y > 0x1C0)
		{
			delete_current_object();
			return;
		}
		if ((int8_t)((struct object *)ram(current_object))->animation_frame <= 2)
			add_to_platform_list();
		depth = (uint16_t)(((int32_t)((uint32_t)((struct object *)ram(current_object))->projected_y + ((struct object *)ram(current_object))->floor_z) >> 16) - (*(int16_t *)ram(0x20E406u)) + ((struct object *)ram(current_object))->crumbling_floor.depth_offset);
		queue_sprite_at_depth(&ignored, &depth);
		return;
	default:
		invalid_jump(0x914DFu + ((struct object *)ram(current_object))->crumbling_floor.state * 3u);
	}
}

/* Within 0x60 of the leader: the cracking steps (crumbling_floor_play_crack_steps); once they have
   stopped (animation_timer negative) the block holds the last step's screen offset
   (apply_step_screen_offset) and is drawn. */
void crumbling_floor_crack(void)
{
	if (((struct object *)ram(current_object))->animation_timer < 0)
	{
		apply_step_screen_offset();
		crumbling_floor_draw();
		return;
	}
	crumbling_floor_play_crack_steps();
}

/* Advances the cracking steps (animate_with_screen_offset); at step 4 they stop (animation_timer -1) and
   with flag 0x400000 the block falls at once (crumbling_floor_start_falling); else crumbling_floor_draw. */
void crumbling_floor_play_crack_steps(void)
{
	animate_with_screen_offset(0u);
	if ((int8_t)((struct object *)ram(current_object))->animation_frame < 4)
	{
		crumbling_floor_draw();
		return;
	}
	((struct object *)ram(current_object))->animation_timer = -1;
	if ((((struct object *)ram(current_object))->flags & 0x400000u) != 0u)
	{
		crumbling_floor_start_falling();
		return;
	}
	crumbling_floor_draw();
}

/* The block starts to fall: state + 1 (falling), speed_z 0, the crumbling steps from step 4 at speed 6,
   and sound 0xD unless silent_row is set or screen_x is past an edge that depends on direction; then
   crumbling_floor_draw. */
void crumbling_floor_start_falling(void)
{
	uint8_t sound_id = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	((struct object *)ram(current_object))->crumbling_floor.state++;
	((struct object *)ram(current_object))->speed_z = 0;
	((struct object *)ram(current_object))->animation_speed = 6u;
	((struct object *)ram(current_object))->animation_timer = 0;
	((struct object *)ram(current_object))->animation_frame = 4u;
	if (((struct object *)ram(current_object))->crumbling_floor.silent_row != 0u)
	{
		crumbling_floor_draw();
		return;
	}
	switch (((struct object *)ram(current_object))->direction)
	{
	case 0:
	case 4:
		if (((struct object *)ram(current_object))->screen_x < 0)
		{
			crumbling_floor_draw();
			return;
		}
		sound_id = 0xDu;
		play_sound(sound_id, &ignored, &ignored_2);
		crumbling_floor_draw();
		return;
	case 1:
		if (((struct object *)ram(current_object))->screen_x > 0x180)
		{
			crumbling_floor_draw();
			return;
		}
		sound_id = 0xDu;
		play_sound(sound_id, &ignored, &ignored_2);
		crumbling_floor_draw();
		return;
	case 2:
		if (((struct object *)ram(current_object))->screen_x < -8)
		{
			crumbling_floor_draw();
			return;
		}
		sound_id = 0xDu;
		play_sound(sound_id, &ignored, &ignored_2);
		crumbling_floor_draw();
		return;
	case 3:
		if (((struct object *)ram(current_object))->screen_x > 0x1A0)
		{
			crumbling_floor_draw();
			return;
		}
		sound_id = 0xDu;
		play_sound(sound_id, &ignored, &ignored_2);
		crumbling_floor_draw();
		return;
	default:
		invalid_jump(0x9161Cu + ((struct object *)ram(current_object))->direction * 2u);
	}
}

/* Puts the block in the platform list and, while screen_x is within -0xA0..0x1E0, queues it at screen_y
   + depth_offset - sprite_offset_y, kept in draw_depth (the players standing on it read it). */
void crumbling_floor_draw(void)
{
	uint32_t ignored = 0, sprite_depth = 0;

	add_to_platform_list();
	if ((uint16_t)(((struct object *)ram(current_object))->screen_x + 0xA0u) >= 0x281u)
		return;
	sprite_depth = (uint16_t)(((struct object *)ram(current_object))->screen_y + ((struct object *)ram(current_object))->crumbling_floor.depth_offset - ((struct object *)ram(current_object))->sprite_offset_y);
	((struct object *)ram(current_object))->draw_depth = sprite_depth;
	queue_sprite_at_depth(&ignored, &sprite_depth);
}

/* Spawns group leader n (the record's first byte & 3), kept in group_leaders[n]: sprite_frame = n, the
   record's x, y, z (floor_z = z), direction and path in group_leader_data, handler group_leader_move
   (group_leader_wait while group_leader_0_held or group_leaders_1_3_held). spawned 0xFFFFFFFF, or 0 when
   no object is free. */
void spawn_group_leader(uint32_t record, uint32_t *p_spawned, uint32_t *p_leader)
{
	uint32_t leader = *p_leader;
	uint32_t leader_index = 0;

	allocate_object_outside_loop(p_spawned, &leader);
	if (*p_spawned != 0u)
	{
		leader_index = ((const struct leader_spawn *)rom(record))->leader & 3u;
		((struct object *)ram(leader))->sprite_frame = leader_index;
		((uint16_t *)ram(0x20E562u))[leader_index] = leader;
		record++;
		((struct object *)ram(leader))->x_int = ((const struct leader_spawn *)rom(record - 0x1u))->x;
		((struct object *)ram(leader))->x_fraction = 0u;
		record += 2u;
		((struct object *)ram(leader))->y_int = ((const struct leader_spawn *)rom(record - 0x3u))->y;
		((struct object *)ram(leader))->y_fraction = 0u;
		record += 2u;
		((struct object *)ram(leader))->z_int = ((const struct leader_spawn *)rom(record - 0x5u))->z;
		((struct object *)ram(leader))->z_fraction = 0u;
		((struct object *)ram(leader))->floor_z = ((struct object *)ram(leader))->z;
		record += 2u;
		((struct object *)ram(leader))->direction = ((const struct leader_spawn *)rom(record - 0x7u))->direction;
		((struct object *)ram(leader))->group_leader_move.path = ((const struct leader_spawn *)rom(record - 0x7u))->path + 0x09357Du;
		((struct object *)ram(leader))->handler = 0x09179Au;
		((struct object *)ram(leader))->flags = 0u;
		((struct object *)ram(leader))->sprite_offset_x = 0;
		((struct object *)ram(leader))->sprite_offset_y = 0;
		((struct object *)ram(leader))->group_leader_move.holding_back = 0u;
		((struct object *)ram(leader))->group_leader_move.wait_timer = 1;
		if ((*(uint8_t *)ram(0x20E654u)) != 0u || (*(uint8_t *)ram(0x20E652u)) != 0u)
			((struct object *)ram(leader))->handler = 0x09177Du;
		*p_spawned = 0xFFFFFFFFu;
	}
	*p_leader = leader;
}

/* Holds a new group leader: leader 0 (sprite_frame 0) until group_leader_0_held is clear, the others
   until group_leaders_1_3_held is; then handler group_leader_move. */
void group_leader_wait(void)
{
	if (((struct object *)ram(current_object))->sprite_frame == 0u)
	{
		if ((*(uint8_t *)ram(0x20E652u)) == 0u)
			((struct object *)ram(current_object))->handler = 0x09179Au;
	}
	else if ((*(uint8_t *)ram(0x20E654u)) == 0u)
	{
		((struct object *)ram(current_object))->handler = 0x09179Au;
		return;
	}
}

/* An invisible marker leading a group along its row (direction 0/4 +y, 1 -y, 2 +x, 3 -x) by its
   group_leader_data entries (group_leader_read_script, group_leader_move_step); the members fall as it
   passes. It holds back (base_speed 0) in stage 8 in game modes 0x17 and 0x1D, or while
   no_player_in_play, player_mishap or player_dropping_in. */
void group_leader_move(void)
{
	uint16_t hold_threshold = 0;
	uint32_t flags = 0;

	flags = ((struct object *)ram(current_object))->flags;
	((struct object *)ram(current_object))->flags = flags | 1u;
	if ((flags & 1u) == 0u)
	{
		group_leader_read_script();
		return;
	}
	if (((struct object *)ram(current_object))->group_leader_move.holding_back != 0u)
	{
		group_leader_move_step();
		return;
	}
	if (((*(uint16_t *)ram(0x20F06Eu)) != 8u || ((*(uint8_t *)ram(0x20E5A9u)) != 0x17u && (*(uint8_t *)ram(0x20E5A9u)) != 0x1Du)) && (*(uint8_t *)ram(0x20E599u)) == 0u && (*(uint8_t *)ram(0x20E5A3u)) == 0u && (*(uint8_t *)ram(0x20E596u)) == 0u)
	{
		group_leader_read_script();
		return;
	}
	((struct object *)ram(current_object))->group_leader_move.holding_back = 0xFFu;
	((struct object *)ram(current_object))->group_leader_move.saved_base_speed = ((struct object *)ram(current_object))->group_leader_move.base_speed;
	((struct object *)ram(current_object))->group_leader_move.base_speed = 0;
	((struct object *)ram(current_object))->group_leader_move.hold_start_position = (*(uint16_t *)ram(0x20E435u));
	((struct object *)ram(current_object))->group_leader_move.hold_timer = 0xFFu;
	((struct object *)ram(current_object))->group_leader_move.saved_threshold = ((struct object *)ram(current_object))->group_leader_move.screen_threshold;
	hold_threshold = 0xFF90u;
	if ((((struct object *)ram(current_object))->direction_low & 1u) != 0u)
		hold_threshold = 0x1B0u;
	((struct object *)ram(current_object))->group_leader_move.screen_threshold = hold_threshold;
	group_leader_move_step();
}

/* The leader's wait_timer counts down; then, once scroll_position reaches its next group_leader_data
   entry, the entry gives screen_threshold, catch_up_factor, base_speed and wait_timer (a negative
   catch-up factor ends the path and removes the leader). Then group_leader_move_step. */
void group_leader_read_script(void)
{
	uint32_t cursor = 0;
	uint16_t wait_timer = 0, trigger_scroll = 0;

	wait_timer = ((struct object *)ram(current_object))->group_leader_move.wait_timer;
	((struct object *)ram(current_object))->group_leader_move.wait_timer = wait_timer - 1u;
	if ((int16_t)wait_timer > 1)
	{
		group_leader_move_step();
		return;
	}
	((struct object *)ram(current_object))->group_leader_move.wait_timer = 0;
	cursor = ((struct object *)ram(current_object))->group_leader_move.path;
	trigger_scroll = ((const struct chase_step_at_scroll *)rom(cursor))->position;
	cursor += 2u;
	if ((*(uint16_t *)ram(0x20E435u)) < trigger_scroll)
	{
		group_leader_move_step();
		return;
	}
	if (((const struct chase_step_at_scroll *)rom(cursor - 0x2u))->catch_up_factor < 0)
	{
		delete_current_object();
		return;
	}
	((struct object *)ram(current_object))->group_leader_move.screen_threshold = ((const struct chase_step_at_scroll *)rom(cursor - 0x2u))->screen_threshold;
	cursor += 2u;
	((struct object *)ram(current_object))->group_leader_move.catch_up_factor = ((const struct chase_step_at_scroll *)rom(cursor - 0x4u))->catch_up_factor;
	cursor += 2u;
	((struct object *)ram(current_object))->group_leader_move.base_speed = ((const struct chase_step_at_scroll *)rom(cursor - 0x6u))->base_speed;
	cursor += 2u;
	((struct object *)ram(current_object))->group_leader_move.wait_timer = ((const struct chase_step_at_scroll *)rom(cursor - 0x8u))->wait;
	((struct object *)ram(current_object))->group_leader_move.path = cursor + 2u;
	group_leader_move_step();
}

/* project_object, then chaser_speed: base_speed while screen_x is past screen_threshold, else the
   camera's ground speed * catch_up_factor / 0x100, at least base_speed (which also ends a hold-back, as
   do 0x300 scroll units or hold_timer running out); the leader moves by it along its direction unless
   waiting (wait_timer) or grey_screen_active. */
void group_leader_move_step(void)
{
	uint16_t speed = 0;
	uint32_t ignored = 0, ignored_2 = 0;
	uint8_t hold_timer = 0;

	project_object(&ignored, &ignored_2);
	if (((struct object *)ram(current_object))->group_leader_move.holding_back == 0u)
	{
		switch (((struct object *)ram(current_object))->direction)
		{
		case 0:
		case 2:
		case 4:
			if (((struct object *)ram(current_object))->group_leader_move.screen_threshold <= ((struct object *)ram(current_object))->screen_x)
				speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
			else
			{
				((struct object *)ram(current_object))->group_leader_move.wait_timer = 0;
				if (((struct object *)ram(current_object))->group_leader_move.holding_back != 0u)
				{
					((struct object *)ram(current_object))->group_leader_move.holding_back = 0u;
					((struct object *)ram(current_object))->group_leader_move.screen_threshold = ((struct object *)ram(current_object))->group_leader_move.saved_threshold;
					((struct object *)ram(current_object))->group_leader_move.base_speed = ((struct object *)ram(current_object))->group_leader_move.saved_base_speed;
				}
				compute_camera_ground_speed(0u);
				speed = (uint16_t)((uint32_t)(*(uint16_t *)ram(0x20E512u)) * ((struct object *)ram(current_object))->group_leader_move.catch_up_factor) >> 8;
				if ((int16_t)speed <= ((struct object *)ram(current_object))->group_leader_move.base_speed)
				{
					speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
					(*(int16_t *)ram(0x20E556u)) = speed;
					if (((struct object *)ram(current_object))->group_leader_move.wait_timer > 0 || (*(uint8_t *)ram(0x20E59Au)) != 0u)
						return;
					switch (((struct object *)ram(current_object))->direction)
					{
					case 0:
					case 4:
						((struct object *)ram(current_object))->y += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
						break;
					case 1:
						((struct object *)ram(current_object))->y -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
						break;
					case 2:
						((struct object *)ram(current_object))->x += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
						break;
					case 3:
						((struct object *)ram(current_object))->x -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
						break;
					default:
						invalid_jump(0x918FAu + ((struct object *)ram(current_object))->direction * 2u);
					}
					return;
				}
			}
			break;
		case 1:
		case 3:
			if (((struct object *)ram(current_object))->screen_x <= ((struct object *)ram(current_object))->group_leader_move.screen_threshold)
			{
				speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
				(*(int16_t *)ram(0x20E556u)) = speed;
				if (((struct object *)ram(current_object))->group_leader_move.wait_timer > 0 || (*(uint8_t *)ram(0x20E59Au)) != 0u)
					return;
				switch (((struct object *)ram(current_object))->direction)
				{
				case 0:
				case 4:
					((struct object *)ram(current_object))->y += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
					break;
				case 1:
					((struct object *)ram(current_object))->y -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
					break;
				case 2:
					((struct object *)ram(current_object))->x += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
					break;
				case 3:
					((struct object *)ram(current_object))->x -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
					break;
				default:
					invalid_jump(0x918FAu + ((struct object *)ram(current_object))->direction * 2u);
				}
				return;
			}
			((struct object *)ram(current_object))->group_leader_move.wait_timer = 0;
			if (((struct object *)ram(current_object))->group_leader_move.holding_back != 0u)
			{
				((struct object *)ram(current_object))->group_leader_move.holding_back = 0u;
				((struct object *)ram(current_object))->group_leader_move.screen_threshold = ((struct object *)ram(current_object))->group_leader_move.saved_threshold;
				((struct object *)ram(current_object))->group_leader_move.base_speed = ((struct object *)ram(current_object))->group_leader_move.saved_base_speed;
			}
			compute_camera_ground_speed(0u);
			speed = (uint16_t)((uint32_t)(*(uint16_t *)ram(0x20E512u)) * ((struct object *)ram(current_object))->group_leader_move.catch_up_factor) >> 8;
			if ((int16_t)speed <= ((struct object *)ram(current_object))->group_leader_move.base_speed)
				speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
			break;
		default:
			invalid_jump(0x91887u + ((struct object *)ram(current_object))->direction * 2u);
		}
	}
	else if ((int16_t)((*(uint16_t *)ram(0x20E435u)) - ((struct object *)ram(current_object))->group_leader_move.hold_start_position) >= 0x300)
	{
		((struct object *)ram(current_object))->group_leader_move.holding_back = 0u;
		((struct object *)ram(current_object))->group_leader_move.screen_threshold = ((struct object *)ram(current_object))->group_leader_move.saved_threshold;
		((struct object *)ram(current_object))->group_leader_move.base_speed = ((struct object *)ram(current_object))->group_leader_move.saved_base_speed;
		compute_camera_ground_speed(0u);
		speed = (uint16_t)((uint32_t)(*(uint16_t *)ram(0x20E512u)) * ((struct object *)ram(current_object))->group_leader_move.catch_up_factor) >> 8;
		if ((int16_t)speed <= ((struct object *)ram(current_object))->group_leader_move.base_speed)
			speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
	}
	else
	{
		if ((*(uint8_t *)ram(0x20E599u)) != 0u)
			((struct object *)ram(current_object))->group_leader_move.hold_timer = 0xFFu;
		hold_timer = ((struct object *)ram(current_object))->group_leader_move.hold_timer;
		((struct object *)ram(current_object))->group_leader_move.hold_timer = hold_timer - 1u;
		if (hold_timer == 0u)
		{
			((struct object *)ram(current_object))->group_leader_move.holding_back = 0u;
			((struct object *)ram(current_object))->group_leader_move.screen_threshold = ((struct object *)ram(current_object))->group_leader_move.saved_threshold;
			((struct object *)ram(current_object))->group_leader_move.base_speed = ((struct object *)ram(current_object))->group_leader_move.saved_base_speed;
			compute_camera_ground_speed(0u);
			speed = (uint16_t)((uint32_t)(*(uint16_t *)ram(0x20E512u)) * ((struct object *)ram(current_object))->group_leader_move.catch_up_factor) >> 8;
			if ((int16_t)speed <= ((struct object *)ram(current_object))->group_leader_move.base_speed)
				speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
		}
		else
		{
			switch (((struct object *)ram(current_object))->direction)
			{
			case 0:
			case 2:
			case 4:
				if (((struct object *)ram(current_object))->group_leader_move.screen_threshold <= ((struct object *)ram(current_object))->screen_x)
					speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
				else
				{
					((struct object *)ram(current_object))->group_leader_move.wait_timer = 0;
					if (((struct object *)ram(current_object))->group_leader_move.holding_back != 0u)
					{
						((struct object *)ram(current_object))->group_leader_move.holding_back = 0u;
						((struct object *)ram(current_object))->group_leader_move.screen_threshold = ((struct object *)ram(current_object))->group_leader_move.saved_threshold;
						((struct object *)ram(current_object))->group_leader_move.base_speed = ((struct object *)ram(current_object))->group_leader_move.saved_base_speed;
					}
					compute_camera_ground_speed(0u);
					speed = (uint16_t)((uint32_t)(*(uint16_t *)ram(0x20E512u)) * ((struct object *)ram(current_object))->group_leader_move.catch_up_factor) >> 8;
					if ((int16_t)speed <= ((struct object *)ram(current_object))->group_leader_move.base_speed)
					{
						speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
						(*(int16_t *)ram(0x20E556u)) = speed;
						if (((struct object *)ram(current_object))->group_leader_move.wait_timer > 0 || (*(uint8_t *)ram(0x20E59Au)) != 0u)
							return;
						switch (((struct object *)ram(current_object))->direction)
						{
						case 0:
						case 4:
							((struct object *)ram(current_object))->y += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
							break;
						case 1:
							((struct object *)ram(current_object))->y -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
							break;
						case 2:
							((struct object *)ram(current_object))->x += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
							break;
						case 3:
							((struct object *)ram(current_object))->x -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
							break;
						default:
							invalid_jump(0x918FAu + ((struct object *)ram(current_object))->direction * 2u);
						}
						return;
					}
				}
				break;
			case 1:
			case 3:
				if (((struct object *)ram(current_object))->screen_x <= ((struct object *)ram(current_object))->group_leader_move.screen_threshold)
				{
					speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
					(*(int16_t *)ram(0x20E556u)) = speed;
					if (((struct object *)ram(current_object))->group_leader_move.wait_timer > 0 || (*(uint8_t *)ram(0x20E59Au)) != 0u)
						return;
					switch (((struct object *)ram(current_object))->direction)
					{
					case 0:
					case 4:
						((struct object *)ram(current_object))->y += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
						break;
					case 1:
						((struct object *)ram(current_object))->y -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
						break;
					case 2:
						((struct object *)ram(current_object))->x += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
						break;
					case 3:
						((struct object *)ram(current_object))->x -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
						break;
					default:
						invalid_jump(0x918FAu + ((struct object *)ram(current_object))->direction * 2u);
					}
					return;
				}
				((struct object *)ram(current_object))->group_leader_move.wait_timer = 0;
				if (((struct object *)ram(current_object))->group_leader_move.holding_back != 0u)
				{
					((struct object *)ram(current_object))->group_leader_move.holding_back = 0u;
					((struct object *)ram(current_object))->group_leader_move.screen_threshold = ((struct object *)ram(current_object))->group_leader_move.saved_threshold;
					((struct object *)ram(current_object))->group_leader_move.base_speed = ((struct object *)ram(current_object))->group_leader_move.saved_base_speed;
				}
				compute_camera_ground_speed(0u);
				speed = (uint16_t)((uint32_t)(*(uint16_t *)ram(0x20E512u)) * ((struct object *)ram(current_object))->group_leader_move.catch_up_factor) >> 8;
				if ((int16_t)speed <= ((struct object *)ram(current_object))->group_leader_move.base_speed)
					speed = (uint16_t)((struct object *)ram(current_object))->group_leader_move.base_speed;
				break;
			default:
				invalid_jump(0x91887u + ((struct object *)ram(current_object))->direction * 2u);
			}
		}
	}
	(*(int16_t *)ram(0x20E556u)) = speed;
	if (((struct object *)ram(current_object))->group_leader_move.wait_timer > 0 || (*(uint8_t *)ram(0x20E59Au)) != 0u)
		return;
	switch (((struct object *)ram(current_object))->direction)
	{
	case 0:
	case 4:
		((struct object *)ram(current_object))->y += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
		break;
	case 1:
		((struct object *)ram(current_object))->y -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
		break;
	case 2:
		((struct object *)ram(current_object))->x += (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
		break;
	case 3:
		((struct object *)ram(current_object))->x -= (uint32_t)(*(int16_t *)ram(0x20E556u)) << 12;
		break;
	default:
		invalid_jump(0x918FAu + ((struct object *)ram(current_object))->direction * 2u);
	}
}

/* Spawns the stage's stage_record_spawns records as the scroll reaches them; the first call also clears
   the bridges' plank counts and the group slots. Type 0 builds a group on a free bridge
   (spawn_object_groups_2_pick_bridge), 2 and 3 on bridge 0 and bridge 1, and 1 and 4 spawn a group
   leader. */
void spawn_object_groups_2(uint32_t *p_list_offset, uint32_t *p_count, uint32_t *p_object)
{
	uint32_t fill_word = 0, kind_index = 0, plank_count_var = 0, record = 0, slot_cursor = 0, spawned = 0;
	uint16_t spawn_position = 0;
	uint32_t init_flags = 0;

	init_flags = (*(uint32_t *)ram(0x20F0BCu));
	(*(uint32_t *)ram(0x20F0BCu)) = init_flags | 0x10u;
	if ((init_flags & 0x10u) == 0u)
	{
		(*(uint16_t *)ram(0x20F0A4u)) = 0u;
		(*(uint16_t *)ram(0x20E544u)) = 0u;
		(*(uint16_t *)ram(0x20F0A6u)) = 1u;
		*p_list_offset = ((const uint16_t *)rom(0x093EC9u))[(*(uint16_t *)ram(0x20F06Eu))];
		(*(uint32_t *)ram(0x20F08Cu)) = 0x093EC9u + *p_list_offset;
		(*(uint16_t *)ram(0x20F0B0u)) = 0u;
		(*(uint16_t *)ram(0x20E542u)) = 0u;
		slot_cursor = 0x209F00u;
		*p_count = 0x10u;
		fill_word = 0u;
		do
		{
			mem_write32(slot_cursor, fill_word);
			slot_cursor += 4u;
			(*p_count)--;
		} while (*p_count != 0u);
	}
	for (;;)
	{
		record = (*(uint32_t *)ram(0x20F08Cu));
		spawn_position = ((const struct group_spawn_record *)rom(record))->position;
		record += 2u;
		if ((*(uint16_t *)ram(0x20E435u)) < spawn_position)
		{
			return;
		}
		kind_index = ((const struct group_spawn_record *)rom(record - 0x2u))->kind * 2u;
		record++;
		switch (kind_index)
		{
		case 0x0u:
			spawn_object_groups_2_pick_bridge(record, p_list_offset, p_count, p_object);
			return;
		case 0x2u:
		case 0x8u:
			break;
		case 0x4u:
			(*(uint8_t *)ram(0x20F0F0u)) = 0u;
			plank_count_var = 0x20F0B0u;
			spawn_object_groups_2_build_group(record, plank_count_var, p_list_offset, p_count, p_object);
			return;
		case 0x6u:
			(*(uint8_t *)ram(0x20F0F0u)) = 1u;
			plank_count_var = 0x20E542u;
			spawn_object_groups_2_build_group(record, plank_count_var, p_list_offset, p_count, p_object);
			return;
		default:
			invalid_jump(0x938A6u + kind_index);
		}
		spawn_group_leader(record, &spawned, p_object);
		if (spawned == 0u)
		{
			return;
		}
		(*(uint32_t *)ram(0x20F08Cu)) += 0xEu;
	}
}

/* Type 0: the group goes to bridge 0 if bridge_0_plank_count is 0, else to bridge 1 if
   bridge_1_plank_count is 0 (else it waits); that count + 1, then spawn_object_groups_2_build_group. Its
   free-object wait reads the record's word at +5, the floor block's high half (0), not the member count,
   so it never waits. */
void spawn_object_groups_2_pick_bridge(uint32_t record, uint32_t *p_list_offset, uint32_t *p_count, uint32_t *p_object)
{
	uint8_t bridge_number = 0;
	uint32_t plank_count_var = 0;

	if ((*(int16_t *)ram(0x20E900u)) < (int16_t)(uint16_t)(((const struct group_spawn_record *)rom(record - 0x3u))->floor_block >> 16u))
		return;
	bridge_number = 0u;
	plank_count_var = 0x20F0B0u;
	if ((*(uint16_t *)ram(0x20F0B0u)) == 0u)
	{
		(*(uint8_t *)ram(0x20F0F0u)) = bridge_number;
		mem_write16(plank_count_var, mem_read16(plank_count_var) + 1u);
		(*(uint8_t *)ram(0x20F0A8u)) = 0u;
		spawn_object_groups_2_build_group(record, plank_count_var, p_list_offset, p_count, p_object);
		return;
	}
	bridge_number = 1u;
	plank_count_var = 0x20E542u;
	if ((*(uint16_t *)ram(0x20E542u)) != 0u)
		return;
	(*(uint8_t *)ram(0x20F0F0u)) = bridge_number;
	mem_write16(plank_count_var, mem_read16(plank_count_var) + 1u);
	(*(uint8_t *)ram(0x20F0A8u)) = 0u;
	spawn_object_groups_2_build_group(record, plank_count_var, p_list_offset, p_count, p_object);
}

/* Builds bridge group_bridge_number's planks when the scroll is within 0x100 past the record (else skips
   it): a row of stage_object_records_2 members on the floor block, each linked to the one before
   (var_9A); plank_count_var + the count, and the last plank (spawn_arg_2_low 0xFF) goes in
   bridge_0/1_last_plank. Free objects are never checked. */
void spawn_object_groups_2_build_group(uint32_t record, uint32_t plank_count_var, uint32_t *p_list_offset, uint32_t *p_count, uint32_t *p_object)
{
	uint32_t count = *p_count;
	uint32_t object = *p_object;
	uint32_t floor_block_record = 0, floor_type_record = 0, ignored = 0, last_plank_var = 0, member_record = 0, slot_cursor = 0;
	uint8_t slot_taken = 0;
	uint16_t members_left = 0;

	if ((uint16_t)((*(uint16_t *)ram(0x20E435u)) - ((const struct group_spawn_record *)rom(record - 0x3u))->position) >= 0x100u)
	{
		(*(uint32_t *)ram(0x20F08Cu)) += 0x18u;
		return;
	}
	(*(uint16_t *)ram(0x20F0F4u)) = ((uint16_t *)ram(0x20E562u))[((const struct group_spawn_record *)rom(record - 0x3u))->leader];
	record++;
	(*(uint8_t *)ram(0x20E5A8u)) = ((const struct group_spawn_record *)rom(record - 0x4u))->takes_slot;
	record += 2u;
	(*(uint32_t *)ram(0x20F0ECu)) = ((const struct group_spawn_record *)rom(record - 0x6u))->floor_block;
	record += 4u;
	(*(int16_t *)ram(0x20F094u)) = ((const struct group_spawn_record *)rom(record - 0xAu))->member_count;
	(*(uint16_t *)ram(0x20F0F6u)) = 0xFFFFu;
	mem_write16(plank_count_var, mem_read16(plank_count_var) + (*(int16_t *)ram(0x20F094u)));
	record += 2u;
	(*(uint16_t *)ram(0x20F096u)) = ((const struct group_spawn_record *)rom(record - 0xCu))->step_x;
	record += 2u;
	(*(uint16_t *)ram(0x20F098u)) = ((const struct group_spawn_record *)rom(record - 0xEu))->step_y;
	record += 2u;
	(*(uint16_t *)ram(0x20F0F2u)) = ((const struct group_spawn_record *)rom(record - 0x10u))->direction;
	record += 2u;
	(*(uint16_t *)ram(0x20F09Au)) = ((const struct group_spawn_record *)rom(record - 0x12u))->member_x;
	record += 2u;
	(*(uint16_t *)ram(0x20F09Cu)) = ((const struct group_spawn_record *)rom(record - 0x14u))->member_y;
	(*(uint32_t *)ram(0x20F09Eu)) = ((const struct group_spawn_record *)rom(record - 0x14u))->member_template;
	if ((*(uint8_t *)ram(0x20E5A8u)) != 0u)
	{
		slot_cursor = 0x209F00u;
		count = 0x40u;
		do
		{
			slot_taken = mem_read8(slot_cursor);
			slot_cursor++;
			count--;
		} while ((count != 0u) & (slot_taken != 0u));
		mem_write8(slot_cursor - 1u, 1u);
		count = (count & ~0xFFFFu) | (uint16_t)(count + 1u);
		(*(uint16_t *)ram(0x20E5AAu)) = 0x40u - count;
	}
	do
	{
		allocate_object_outside_loop(&ignored, &object);
		((struct object *)ram(object))->x_int = (*(uint16_t *)ram(0x20F09Au));
		((struct object *)ram(object))->x_fraction = 0u;
		(*(uint16_t *)ram(0x20F09Au)) += (*(uint16_t *)ram(0x20F096u));
		((struct object *)ram(object))->y_int = (*(uint16_t *)ram(0x20F09Cu));
		((struct object *)ram(object))->y_fraction = 0u;
		(*(uint16_t *)ram(0x20F09Cu)) += (*(uint16_t *)ram(0x20F098u));
		member_record = (*(uint32_t *)ram(0x20F09Eu));
		((struct object *)ram(object))->kind = member_record;
		member_record += 0x093F59u;
		((struct object *)ram(object))->sprite_flags = ((const struct stage_object_record_2 *)rom(member_record))->sprite_flags;
		member_record += 2u;
		((struct object *)ram(object))->sprite_frame = ((const struct stage_object_record_2 *)rom(member_record - 0x2u))->sprite_frame;
		member_record += 2u;
		((struct object *)ram(object))->sprite_palette = ((const struct stage_object_record_2 *)rom(member_record - 0x4u))->sprite_palette;
		member_record += 2u;
		((struct object *)ram(object))->handler = ((const struct stage_object_record_2 *)rom(member_record - 0x6u))->handler;
		member_record += 4u;
		((struct object *)ram(object))->animation = ((const struct stage_object_record_2 *)rom(member_record - 0xAu))->animation;
		member_record += 4u;
		*p_list_offset = ((const struct stage_object_record_2 *)rom(member_record - 0xEu))->odd_member_animation;
		member_record += 4u;
		if (((*(uint8_t *)ram(0x20F0A8u)) & 1u) != 0u)
			((struct object *)ram(object))->animation = *p_list_offset;
		((struct object *)ram(object))->hitbox_size_x = ((const struct stage_object_record_2 *)rom(member_record - 0x12u))->hitbox_size_x;
		member_record += 2u;
		((struct object *)ram(object))->hitbox_size_y = ((const struct stage_object_record_2 *)rom(member_record - 0x14u))->hitbox_size_y;
		((struct object *)ram(object))->group_member.depth_offset = ((const struct stage_object_record_2 *)rom(member_record - 0x14u))->depth_offset;
		((struct object *)ram(object))->sprite_offset_x = 0x2E;
		((struct object *)ram(object))->sprite_offset_y = 0x11;
		((struct object *)ram(object))->member_state = 0u;
		(*(uint8_t *)ram(0x20F0A8u))++;
		((struct object *)ram(object))->member_number = (*(uint8_t *)ram(0x20F0A8u));
		((struct object *)ram(object))->floor_block = (*(uint32_t *)ram(0x20F0ECu));
		((struct object *)ram(object))->spawn_arg_2_high = (*(uint8_t *)ram(0x20F0F0u));
		((struct object *)ram(object))->direction = (*(uint16_t *)ram(0x20F0F2u));
		((struct object *)ram(object))->parent = (*(uint16_t *)ram(0x20F0F4u));
		((struct object *)ram(object))->group_member.previous_member = (*(uint16_t *)ram(0x20F0F6u));
		(*(uint16_t *)ram(0x20F0F6u)) = object;
		floor_block_record = (*(uint32_t *)ram(0x20F070u)) + 2u + ((struct object *)ram(object))->floor_block;
		((struct object *)ram(object))->z_int = ((const struct floor_block *)rom(floor_block_record))->height;
		((struct object *)ram(object))->z_fraction = 0u;
		((struct object *)ram(object))->floor_z = ((struct object *)ram(object))->z;
		((struct object *)ram(object))->speed_x = ((struct object *)ram(object))->z;
		((struct object *)ram(object))->floor_slope = ((const struct floor_block *)rom(floor_block_record))->slope;
		floor_type_record = 0x10E14Cu + ((const struct floor_block *)rom(floor_block_record))->type_index * 4u;
		((struct object *)ram(object))->floor_type = ((const struct floor_block_type *)rom(floor_type_record))->floor_type;
		((struct object *)ram(object))->floor_attribute = ((const struct floor_block_type *)rom(floor_type_record))->floor_attribute;
		((struct object *)ram(object))->flags = 0u;
		((struct object *)ram(object))->spawn_arg_2_low = 0u;
		((struct object *)ram(object))->group_member.group_slot = (*(uint16_t *)ram(0x20E5AAu));
		((struct object *)ram(object))->spawn_arg_1_low = (*(uint8_t *)ram(0x20E5A8u));
		members_left = (*(int16_t *)ram(0x20F094u));
		(*(int16_t *)ram(0x20F094u)) = members_left - 1u;
	} while ((int16_t)members_left > 1);
	((struct object *)ram(object))->spawn_arg_2_low = 0xFFu;
	last_plank_var = 0x20E5A4u;
	if ((*(uint8_t *)ram(0x20F0F0u)) != 0u)
		last_plank_var = 0x20E5A6u;
	mem_write16(last_plank_var, object);
	(*(uint32_t *)ram(0x20F08Cu)) += 0x18u;
	*p_count = count;
	*p_object = object;
}

/* Empties the object list and both pools (reset_object_list, reset_object_pool_2); the run_objects after
   it finds no objects and only reloads free_objects. Called when the game mode changes. */
void reset_objects(uint32_t *p_block, uint32_t *p_stack_slot)
{
	reset_object_list();
	reset_object_pool_2(p_block, p_stack_slot);
	run_objects();
}

/* Unused: reset_objects with reset_object_pool_2_alt for the second pool. */
void reset_objects_alt(void)
{
	reset_object_list();
	reset_object_pool_2_alt();
	run_objects();
}

/* Runs every object once: from the one after last_object round to last_object, object_cursor and
   current_object = each and its handler is called (call_code); a handler that deletes its object moves
   object_cursor back. Then first/last_object_address take first_object and last_object. Nothing when
   object_count is 0. */
void run_objects(void)
{
	free_objects = 0x20E900u;
	if ((*(uint16_t *)ram(0x207FE0u)) == 0u)
		return;
	first_object = (*(uint32_t *)ram(0x207FE2u));
	last_object = (*(uint32_t *)ram(0x207FE6u));
	object_cursor = last_object;
	do
	{
		object_cursor = (((object_cursor) & 0xFFFF0000u) | (((struct object *)ram(object_cursor))->next));
		current_object = object_cursor;
		call_code(((struct object *)ram(current_object))->handler);
	} while ((uint16_t)object_cursor != (uint16_t)last_object);
	(*(uint16_t *)ram(0x207FE2u)) = first_object;
	(*(uint16_t *)ram(0x207FE6u)) = last_object;
}

/* Empties the object list: first/last_object_address = 0x200000, object_count 0, and free_object_stack
   holds all 0x80 blocks of 0xA0 bytes (offsets 0x0000-0x4F60 from 0x200000). */
void reset_object_list(void)
{
	uint16_t object_offset = 0;
	uint32_t objects_left = 0, stack_slot = 0;

	object_offset = 0u;
	(*(uint32_t *)ram(0x207FE2u)) = 0x200000u;
	(*(uint32_t *)ram(0x207FE6u)) = 0x200000u;
	objects_left = 0x80u;
	(*(int16_t *)ram(0x20E900u)) = 0x80;
	stack_slot = 0x20E902u;
	do
	{
		mem_write16(stack_slot, object_offset);
		objects_left--;
		stack_slot += 2u;
		object_offset += 0xA0u;
	} while (objects_left != 0u);
	(*(uint16_t *)ram(0x207FE0u)) = objects_left;
}

/* Pops a block off free_object_stack (object = 0x200000 | its entry) without linking it into the list;
   free_count is how many were free (0: none, object left as it was). */
void take_free_object(uint32_t *p_free_count, uint32_t *p_object)
{
	*p_free_count = mem_read16(free_objects);
	if (*p_free_count == 0u)
	{
		return;
	}
	*p_object = 0x200000u | mem_read16(free_objects + *p_free_count * 2u);
	mem_write16(free_objects, mem_read16(free_objects) - 1u);
}

/* allocate_object, or when object_count is 0 pops a block and starts the list with it: first_object and
   last_object (and their addresses) = it, linked to itself (link_object). Hands back the object. */
uint32_t allocate_object_or_start_list(uint32_t object)
{
	uint32_t ignored = 0, new_object = 0;

	if ((*(uint16_t *)ram(0x207FE0u)) != 0u)
	{
		allocate_object(&ignored, &object);
		return object;
	}
	new_object = 0x200000u | mem_read16(free_objects + mem_read16(free_objects) * 2u);
	mem_write16(free_objects, mem_read16(free_objects) - 1u);
	(*(uint16_t *)ram(0x207FE2u)) = new_object;
	first_object = new_object;
	last_object = new_object;
	link_object(new_object);
	return new_object;
}

/* Pops a block off free_object_stack and links it at the end of the object list (link_object): object =
   0x200000 | its entry. free_count is how many were free; 0 means none, and object is left as it was. */
void allocate_object(uint32_t *p_free_count, uint32_t *p_object)
{
	*p_free_count = mem_read16(free_objects);
	if (*p_free_count == 0u)
	{
		return;
	}
	*p_object = 0x200000u | mem_read16(free_objects + *p_free_count * 2u);
	mem_write16(free_objects, mem_read16(free_objects) - 1u);
	link_object(*p_object);
}

/* Links object at the end of the circular list, between last_object and first_object (previous and
   next), makes it last_object (and last_object_address) and adds 1 to object_count. */
void link_object(uint32_t object)
{
	((struct object *)ram(object))->previous = last_object;
	((struct object *)ram(last_object))->next = object;
	((struct object *)ram(first_object))->previous = object;
	((struct object *)ram(object))->next = first_object;
	(*(uint16_t *)ram(0x207FE6u)) = object;
	last_object = object;
	(*(uint16_t *)ram(0x207FE0u))++;
}

/* Unused: allocate_object, but the block is linked right after the current object instead of at the end
   (last_object moves to it when the current object was last); object_count + 1. */
void allocate_object_after_current(void)
{
	uint32_t free_count = 0, new_object = 0, object = 0;

	free_count = mem_read16(free_objects);
	if (free_count == 0u)
		return;
	new_object = 0x200000u | mem_read16(free_objects + free_count * 2u);
	mem_write16(free_objects, mem_read16(free_objects) - 1u);
	object = (((current_object) & 0xFFFF0000u) | (((struct object *)ram(current_object))->next));
	((struct object *)ram(current_object))->next = new_object;
	((struct object *)ram(object))->previous = new_object;
	((struct object *)ram(new_object))->previous = current_object;
	((struct object *)ram(new_object))->next = object;
	(*(uint16_t *)ram(0x207FE0u))++;
	if ((uint16_t)last_object == (uint16_t)current_object)
		last_object = (last_object & ~0xFFFFu) | (uint16_t)new_object;
}

/* Deletes the object at object_cursor: unlinks it (fixing first_object and last_object), object_count -
   1, pushes its block on free_object_stack (current_object = it, push_free_object) and moves
   object_cursor back to the previous object, so run_objects goes on with the right next one. */
void delete_current_object(void)
{
	uint32_t object = 0, object_2 = 0;

	(*(uint16_t *)ram(0x207FE0u))--;
	object = (((object_cursor) & 0xFFFF0000u) | (((struct object *)ram(object_cursor))->previous));
	object_2 = (((object_cursor) & 0xFFFF0000u) | (((struct object *)ram(object_cursor))->next));
	((struct object *)ram(object))->next = object_2;
	((struct object *)ram(object_2))->previous = object;
	if ((uint16_t)object_cursor == (uint16_t)first_object)
		first_object = (first_object & ~0xFFFFu) | (uint16_t)object_2;
	if ((uint16_t)object_cursor == (uint16_t)last_object)
		last_object = (last_object & ~0xFFFFu) | (uint16_t)object;
	current_object = object_cursor;
	object_cursor = (object_cursor & ~0xFFFFu) | (uint16_t)object;
	push_free_object();
}

/* Pushes current_object's block on free_object_stack (count + 1, the entry on top). */
void push_free_object(void)
{
	mem_write16(free_objects, mem_read16(free_objects) + 1u);
	mem_write16(free_objects + mem_read16(free_objects) * 2u, current_object);
}

/* Unused: delete_object of the object after the current one (its next). */
void delete_next_object(void)
{
	uint32_t ignored = 0, ignored_2 = 0, object = 0;

	object = (((object_cursor) & 0xFFFF0000u) | (((struct object *)ram(current_object))->next));
	delete_object(object, &ignored, &ignored_2);
}

/* Deletes object: unlinks it (fixing first_object and last_object), object_count - 1, and pushes its
   block on free_object_stack; free_count is the new count and previous the object before it.
   object_cursor is left alone. */
void delete_object(uint32_t object, uint32_t *p_free_count, uint32_t *p_previous)
{
	uint32_t object_3 = 0;

	(*(uint16_t *)ram(0x207FE0u))--;
	*p_previous = (((object) & 0xFFFF0000u) | (((struct object *)ram(object))->previous));
	object_3 = (((object) & 0xFFFF0000u) | (((struct object *)ram(object))->next));
	((struct object *)ram(object_3))->previous = *p_previous;
	((struct object *)ram(*p_previous))->next = object_3;
	if ((uint16_t)object == (uint16_t)first_object)
		first_object = (first_object & ~0xFFFFu) | (uint16_t)object_3;
	if ((uint16_t)object != (uint16_t)last_object)
	{
		mem_write16(free_objects, mem_read16(free_objects) + 1u);
		*p_free_count = mem_read16(free_objects);
		mem_write16(free_objects + *p_free_count * 2u, object);
		return;
	}
	last_object = (last_object & ~0xFFFFu) | (uint16_t)*p_previous;
	mem_write16(free_objects, mem_read16(free_objects) + 1u);
	*p_free_count = mem_read16(free_objects);
	mem_write16(free_objects + *p_free_count * 2u, object);
}

/* Fills free_object_stack_2 with all 0xFF pool 2 blocks of 0x30 bytes from 0x205000 (offsets 0x5000,
   0x5030 ...). */
void reset_object_pool_2(uint32_t *p_block, uint32_t *p_stack_slot)
{
	uint32_t block = 0, pool_blocks_left = 0, stack_slot = 0;

	block = 0x205000u;
	pool_blocks_left = 0xFFu;
	((int16_t *)ram(0x20EA10u))[0] = 0xFF;
	stack_slot = 0x20EA12u;
	do
	{
		mem_write16(stack_slot, block);
		pool_blocks_left--;
		stack_slot += 2u;
		block += 0x30u;
	} while (pool_blocks_left != 0u);
	*p_block = block;
	*p_stack_slot = stack_slot;
}

/* Unused: reset_object_pool_2 with 0x1D8 blocks of 0x34 bytes (0x205000-0x20AFE0). */
void reset_object_pool_2_alt(void)
{
	uint16_t block = 0;
	uint32_t pool_blocks_left = 0, stack_slot = 0;

	block = 0x5000u;
	pool_blocks_left = 0x1D8u;
	((int16_t *)ram(0x20EA10u))[0] = 0x1D8;
	stack_slot = 0x20EA12u;
	do
	{
		mem_write16(stack_slot, block);
		pool_blocks_left--;
		stack_slot += 2u;
		block += 0x34u;
	} while (pool_blocks_left != 0u);
}

/* Pops a block off free_object_stack_2, the second pool (object = 0x200000 | its entry), without linking
   it into the list; free_count is how many were free (0: none, object left as it was). */
void allocate_object_2(uint32_t *p_free_count, uint32_t *p_free_stack, uint32_t *p_object)
{
	*p_free_stack = 0x20EA10u;
	*p_free_count = (uint16_t)((int16_t *)ram(0x20EA10u))[0];
	if (*p_free_count == 0u)
	{
		return;
	}
	*p_object = 0x200000u | (uint16_t)((int16_t *)ram(0x20EA10u))[*p_free_count];
	((int16_t *)ram(0x20EA10u))[0]--;
}

/* Pushes object back on free_object_stack_2 (pool 2 blocks are never linked into the list). */
uint32_t free_object_2(uint16_t object)
{
	uint32_t free_stack = 0;

	free_stack = 0x20EA10u;
	((int16_t *)ram(0x20EA10u))[0]++;
	((int16_t *)ram(0x20EA10u))[(uint16_t)((int16_t *)ram(0x20EA10u))[0]] = object;
	return free_stack;
}
