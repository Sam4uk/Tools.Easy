/**
 * @file Tools.Easy.h
 * @author Sam4uk
 * @brief
 * @version 0.1.2
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#if !defined(_TOOLS_EASY_HPP_)
#define _TOOLS_EASY_HPP_

//----------------------------------------------------------------------
// Bit operations
//----------------------------------------------------------------------

/// @brief
#define _bv(num) (1 << num)

/// @brief set bit
#define sbi(reg, bit) (reg |= _bv(bit))

/// @brief cler bit
#define cbi(reg, bit) (reg &= ~_bv(bit))

/// @brief toggle bit
#define tbi(reg, bit) (reg ^= _bv(bit))

/// @brief Write bit
#define wbi(reg, bit, value) (value ? sbi(reg, bit) : cbi(reg, bit))

/// @brief read bit
#define rbi(reg, bit) ((reg >> bit) & 0x1)

/// @brief get value by bit count
#define maxBitValue(bits) ((1ULL << (bits)) - 1)

//----------------------------------------------------------------------
// Bit operations
//----------------------------------------------------------------------

/// @brief get size array
#define getArraySize(X) (sizeof(X) / sizeof(*X))

#if 0

/// @brief
#if defined(M_PI)
#define PI (M_PI)
#else
#define PI (3.1415926535897932384626433832795028841971693993751)
#endif

/// @brief
#define RAD_TO_DEG (180. / PI)

/// @brief
#define DEG_TO_RAD (PI / 180.)

#ifdef abs
#undef abs
#endif

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define constrain(amt, low, high)                                              \
  ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))
#define round(x) ((x) >= 0 ? (long)((x) + 0.5) : (long)((x) - 0.5))
#define radians(deg) ((deg) * DEG_TO_RAD)
#define degrees(rad) ((rad) * RAD_TO_DEG)
#define map(value, in_min, in_max, out_min, out_max)                           \
  ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
#endif

#endif ///< _TOOLS_EASY_HPP_
