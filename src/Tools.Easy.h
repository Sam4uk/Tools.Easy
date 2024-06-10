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

/// @brief
#if !defined(M_PI)
#define M_PI (3.1415926535897932384626433832795028841971693993751)
#endif

/// @brief
#define RAD_TO_DEG (180. / M_PI)

/// @brief
#define DEG_TO_RAD (M_PI / 180.)

#if defined(abs)
#undef abs
#endif

#if defined(min)
#undef min
#endif

#if defined(max)
#undef max
#endif

#if defined(round)
#undef round
#endif

#if defined(sq)
#undef sq
#endif

#if defined(radians)
#undef radians
#endif

#if defined(degrees)
#undef degrees
#endif

#if defined(constrain)
#undef constrain
#endif

#if defined(__cplusplus)
/// @brief
/// @tparam T
/// @param value
/// @return
template <class T>
auto abs(const T &value) -> decltype(value > 0 ? value : -value) {
  return value > 0 ? value : -value;
}

/// @brief
/// @tparam T1
/// @tparam T2
/// @param value_a
/// @param value_b
/// @return
template <class T1, class T2>
auto min(const T1 &value_a, const T2 &value_b)
    -> decltype((value_b < value_a) ? value_b : value_a) {
  return (value_b < value_a) ? value_b : value_a;
}

/// @brief
/// @tparam T1
/// @tparam T2
/// @param value_a
/// @param value_b
/// @return
template <class T1, class T2>
auto max(const T1 &value_a, const T2 &value_b)
    -> decltype((value_b < value_a) ? value_b : value_a) {
  return (value_a < value_b) ? value_b : value_a;
}

/// @brief
/// @tparam T
/// @param value
/// @return
template <class T> long round(const T &value) {
  return (long)(value >= 0 ? (value + 0.5) : (value - 0.5));
}

/// @brief
/// @tparam T
/// @param value
/// @return
template <class T> auto sq(const T &value) -> decltype(value * value) {
  return value * value;
}

/// @brief
/// @tparam T
/// @param deg
/// @return
template <class T> auto radians(const T &deg) -> decltype(deg * DEG_TO_RAD) {
  return deg * DEG_TO_RAD;
}

/// @brief
/// @tparam T
/// @param rad
/// @return
template <class T> auto degrees(const T &rad) -> decltype(rad * RAD_TO_DEG) {
  return rad * RAD_TO_DEG;
}

/// @brief
/// @tparam T
/// @tparam TL
/// @tparam TH
/// @param value
/// @param low
/// @param high
/// @return
template <class T, class TL, class TH>
auto constrain(const T &value, const TL &low, const TH &high)
    -> decltype((value < low)    ? low
                : (value > high) ? high
                                 : value) {
  return (value < low) ? low : (value > high) ? high : value;
}

#else // __cplusplus

/// @brief
#define abs(value)                                                             \
  ({                                                                           \
    typeof(value) _value = (value);                                            \
    _value > 0 ? _value : -_value;                                             \
  })

/// @brief
#define min(value_a, value_b)                                                  \
  ({                                                                           \
    typeof(value_a) _value_a = (value_a);                                      \
    typeof(value_b) _value_b = (value_b);                                      \
    _value_a < _value_b ? _value_a : _value_b;                                 \
  })

/// @brief
#define max(value_a, value_b)                                                  \
  ({                                                                           \
    typeof(value_a) _value_a = (value_a);                                      \
    typeof(value_b) _value_b = (value_b);                                      \
    _value_a > _value_b ? _value_a : _value_b;                                 \
  })

/// @brief
#define sq(value)                                                              \
  ({                                                                           \
    typeof(value) _value = (value);                                            \
    _value *_value;                                                            \
  })

/// @brief
#define radians(deg) ((deg)*DEG_TO_RAD)

/// @brief
#define degrees(rad) ((rad)*RAD_TO_DEG)

/// @brief
#define constrain(value, low, high)                                            \
  ({                                                                           \
    typeof(value) _value = (value);                                            \
    typeof(low) _low = (low);                                                  \
    typeof(high) _high = (high);                                               \
    _value<_low ? _low : _value> _high ? _high : _value;                       \
  })

#endif // __cplusplus
#if 0
#define map(value, in_min, in_max, out_min, out_max)                           \
  ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
#endif

#endif ///< _TOOLS_EASY_HPP_
