/**
 * @file Tools.Easy.h
 * @author Sam4uk
 * @brief
 * @version 0.1
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#if !defined(_TOOLS_EASY_HPP_)
#define _TOOLS_EASY_HPP_

#define _bv(num) (1 << num)
#define sbi(reg, bit) (reg |= _bv(bit))
#define cbi(reg, bit) (reg &= ~_bv(bit))
#define tbi(reg, bit) (reg ^= _bv(bit))

#define wbi(reg, bit, value) (value ? sbi(reg, bit) : cbi(reg, bit))
#define rbi(reg, bit) ((reg >> bit) & 0x1)

#define PI (3.1415926535897932384626433832795028841971693993751)
#define DEG_TO_RAD (0.0174532925199432957692369076848861271344287188854)
#define RAD_TO_DEG (57.295779513082320876798154814105170332405472466564)

#ifdef abs
#undef abs
#endif

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define constrain(amt, low, high)                                              \
  ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))
#define round(x) ((x) >= 0 ? (long)((x) + 0.5) : (long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define map(value, in_min, in_max, out_min, out_max)                           \
  ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

#define maxBitValue(bits) ((1ULL << (bits)) - 1)
  
#endif ///< _TOOLS_EASY_HPP_
