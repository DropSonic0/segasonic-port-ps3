/**
*    Name:        le.h
*    Description: the types the game's variables and structure fields are declared with (u16le, s16le,
*                 u32le, s32le): plain integers on a little-endian host, where the memory image of the V60
*                 (little endian) is read as it lies; on a big-endian host (the PS3) small types that keep
*                 their bytes in the V60's order and swap on every read and write
*    License:     BSD-3-Clause
*
*    Define S32_BIG_ENDIAN to get the wrappers; they need C++ (every file that includes game/support.h or
*    ram.h is then compiled as C++). The wrappers are plain data (an array of bytes, no constructors, so
*    they can sit in unions and packed structures) with the operators the generated C uses.
*/
#ifndef GAME_LE_H
#define GAME_LE_H

#include <stdint.h>

#if !defined(S32_BIG_ENDIAN)

typedef uint16_t u16le;
typedef int16_t  s16le;
typedef uint32_t u32le;
typedef int32_t  s32le;

#elif defined(__cplusplus)

template <typename T, typename U>
struct le_value
{
	uint8_t bytes[sizeof(T)];

	operator T() const
	{
		U value = 0;

		for (int index = (int)sizeof(T) - 1; index >= 0; index--)
			value = (U)((value << 8) | bytes[index]);
		return (T)value;
	}

	le_value &operator=(T new_value)
	{
		U value = (U)new_value;

		for (unsigned index = 0; index < sizeof(T); index++)
		{
			bytes[index] = (uint8_t)value;
			value = (U)(value >> 8);
		}
		return *this;
	}

	/* (the copy assignment le_value = le_value is the compiler's: bytes copied as they are) */

	template <typename V> le_value &operator+=(V x)  { return *this = (T)((T)*this + x); }
	template <typename V> le_value &operator-=(V x)  { return *this = (T)((T)*this - x); }
	template <typename V> le_value &operator*=(V x)  { return *this = (T)((T)*this * x); }
	template <typename V> le_value &operator/=(V x)  { return *this = (T)((T)*this / x); }
	template <typename V> le_value &operator%=(V x)  { return *this = (T)((T)*this % x); }
	template <typename V> le_value &operator&=(V x)  { return *this = (T)((T)*this & x); }
	template <typename V> le_value &operator|=(V x)  { return *this = (T)((T)*this | x); }
	template <typename V> le_value &operator^=(V x)  { return *this = (T)((T)*this ^ x); }
	template <typename V> le_value &operator<<=(V x) { return *this = (T)((U)*this << x); }
	template <typename V> le_value &operator>>=(V x) { return *this = (T)((T)*this >> x); }

	le_value &operator++()   { return *this = (T)((T)*this + 1); }
	le_value &operator--()   { return *this = (T)((T)*this - 1); }
	T operator++(int)        { const T old = *this; *this = (T)(old + 1); return old; }
	T operator--(int)        { const T old = *this; *this = (T)(old - 1); return old; }
};

typedef le_value<uint16_t, uint16_t> u16le;
typedef le_value<int16_t, uint16_t>  s16le;
typedef le_value<uint32_t, uint32_t> u32le;
typedef le_value<int32_t, uint32_t>  s32le;

#else
#error "S32_BIG_ENDIAN: the game's files must be compiled as C++ (game/le.h)"
#endif

#endif
