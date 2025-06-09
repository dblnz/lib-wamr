/*
 * Custom byteswap.h implementation for Unikraft
 * This file provides byte order macros that won't conflict with lwIP
 */

#ifndef _BYTESWAP_H
#define _BYTESWAP_H

/* We need to undefine any existing byte order macros to avoid conflicts */
#ifdef BYTE_ORDER
#undef BYTE_ORDER
#endif
#ifdef BIG_ENDIAN
#undef BIG_ENDIAN
#endif
#ifdef LITTLE_ENDIAN
#undef LITTLE_ENDIAN
#endif

/* Define our own byte order macros with unique names */
#define WAMR_BYTE_ORDER 1234
#define WAMR_BIG_ENDIAN 4321
#define WAMR_LITTLE_ENDIAN 1234

/* Define byte swapping functions */
#define bswap_16(x) ((((x) & 0xff00) >> 8) | (((x) & 0x00ff) << 8))
#define bswap_32(x) ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >> 8) | \
                     (((x) & 0x0000ff00) << 8) | (((x) & 0x000000ff) << 24))
#define bswap_64(x) ((((x) & 0xff00000000000000ull) >> 56) | \
                     (((x) & 0x00ff000000000000ull) >> 40) | \
                     (((x) & 0x0000ff0000000000ull) >> 24) | \
                     (((x) & 0x000000ff00000000ull) >> 8) | \
                     (((x) & 0x00000000ff000000ull) << 8) | \
                     (((x) & 0x0000000000ff0000ull) << 24) | \
                     (((x) & 0x000000000000ff00ull) << 40) | \
                     (((x) & 0x00000000000000ffull) << 56))

#endif /* _BYTESWAP_H */
