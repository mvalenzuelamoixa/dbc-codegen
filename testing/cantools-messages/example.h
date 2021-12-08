/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 36.7.0 Wed Dec  8 12:02:40 2021.
 */

#ifndef EXAMPLE_H
#define EXAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define EXAMPLE_FOO_FRAME_ID (0x100u)
#define EXAMPLE_FOO_INEXACT_FRAME_ID (0x100u)
#define EXAMPLE_BAR_FRAME_ID (0x200u)
#define EXAMPLE__4_WD_FRAME_ID (0x300u)
#define EXAMPLE_AMET_FRAME_ID (0x400u)
#define EXAMPLE_DOLOR_FRAME_ID (0x404u)
#define EXAMPLE_MULTIPLEX_TEST_FRAME_ID (0xc8u)

/* Frame lengths in bytes. */
#define EXAMPLE_FOO_LENGTH (4u)
#define EXAMPLE_FOO_INEXACT_LENGTH (4u)
#define EXAMPLE_BAR_LENGTH (8u)
#define EXAMPLE__4_WD_LENGTH (8u)
#define EXAMPLE_AMET_LENGTH (8u)
#define EXAMPLE_DOLOR_LENGTH (8u)
#define EXAMPLE_MULTIPLEX_TEST_LENGTH (8u)

/* Extended or standard frame types. */
#define EXAMPLE_FOO_IS_EXTENDED (0)
#define EXAMPLE_FOO_INEXACT_IS_EXTENDED (0)
#define EXAMPLE_BAR_IS_EXTENDED (0)
#define EXAMPLE__4_WD_IS_EXTENDED (0)
#define EXAMPLE_AMET_IS_EXTENDED (0)
#define EXAMPLE_DOLOR_IS_EXTENDED (0)
#define EXAMPLE_MULTIPLEX_TEST_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */
#define EXAMPLE_BAR_THREE_OFF_CHOICE (0u)
#define EXAMPLE_BAR_THREE_ON_CHOICE (1u)
#define EXAMPLE_BAR_THREE_ONER_CHOICE (2u)
#define EXAMPLE_BAR_THREE_ONEST_CHOICE (3u)

#define EXAMPLE_BAR_FOUR_OFF_CHOICE (0u)
#define EXAMPLE_BAR_FOUR_ON_CHOICE (1u)
#define EXAMPLE_BAR_FOUR_ONER_CHOICE (2u)
#define EXAMPLE_BAR_FOUR_ONEST_CHOICE (3u)

#define EXAMPLE_BAR_TYPE_0_OFF_CHOICE (0u)
#define EXAMPLE_BAR_TYPE_1_ON_CHOICE (1u)

#define EXAMPLE__4_WD__4_DRIVE_OFF_CHOICE (0u)
#define EXAMPLE__4_WD__4_DRIVE_2_WD_CHOICE (1u)
#define EXAMPLE__4_WD__4_DRIVE_4_WD_CHOICE (2u)
#define EXAMPLE__4_WD__4_DRIVE_ALL_CHOICE (3u)

#define EXAMPLE_DOLOR_ONE_FLOAT_DOLOR_CHOICE (3u)
#define EXAMPLE_DOLOR_ONE_FLOAT_OTHER_CHOICE (5u)

/**
 * Signals in message Foo.
 *
 * All signal values are as on the CAN bus.
 */
struct example_foo_t {
    /**
     * Range: -32768..32767 (-2048..2047.9375 A)
     * Scale: 0.0625
     * Offset: 0
     */
    int16_t current;

    /**
     * Range: 0..65535.03355393717961583596331 (0E-9..63.9990234375 V)
     * Scale: 0.000976562
     * Offset: 0
     */
    uint16_t voltage;
};

/**
 * Signals in message FooInexact.
 *
 * All signal values are as on the CAN bus.
 */
struct example_foo_inexact_t {
    /**
     * Range: -327680..327670 (-327.68..327.67 A)
     * Scale: 0.001
     * Offset: 0
     */
    int16_t current;

    /**
     * Range: 0..655350 (0..655.35 V)
     * Scale: 0.001
     * Offset: 0
     */
    uint16_t voltage;
};

/**
 * Signals in message Bar.
 *
 * All signal values are as on the CAN bus.
 */
struct example_bar_t {
    /**
     * Range: 0..256.4102564102564102564102564 (0.00..100 %)
     * Scale: 0.39
     * Offset: 0
     */
    uint8_t two;

    /**
     * Range: 0..3 (0..3 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t one;

    /**
     * Range: 0..7 (0..7 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t three;

    /**
     * Range: 0..3 (0..3 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t four;

    /**
     * Range: 0..1 (0..1 boolean)
     * Scale: 1
     * Offset: 0
     */
    uint8_t type;
};

/**
 * Signals in message _4WD.
 *
 * All signal values are as on the CAN bus.
 */
struct example__4_wd_t {
    /**
     * Range: 0..7 (0..7 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t _4_drive;
};

/**
 * Signals in message Amet.
 *
 * All signal values are as on the CAN bus.
 */
struct example_amet_t {
    /**
     * Range: 0..256.4102564102564102564102564 (0.00..100 %)
     * Scale: 0.39
     * Offset: 0
     */
    uint8_t two;

    /**
     * Range: 0..3 (0..3 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t one;

    /**
     * Range: 0..7 (0..7 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t three;

    /**
     * Range: 0..3 (0..3 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t four;

    /**
     * Range: 0..1 (0..1 boolean)
     * Scale: 1
     * Offset: 0
     */
    uint8_t five;
};

/**
 * Signals in message Dolor.
 *
 * All signal values are as on the CAN bus.
 */
struct example_dolor_t {
    /**
     * Range: 0..260 (0.00..130.00 -)
     * Scale: 0.5
     * Offset: 0
     */
    uint16_t one_float;
};

/**
 * Signals in message MultiplexTest.
 *
 * All signal values are as on the CAN bus.
 */
struct example_multiplex_test_t {
    /**
     * Range: 0..2 (0..2 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t multiplexor;

    /**
     * Range: 0..4 (0..4 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t unmultiplexed_signal;

    /**
     * Range: 0..30 (0..3 -)
     * Scale: 0.1
     * Offset: 0
     */
    uint8_t multiplexed_signal_zero_a;

    /**
     * Range: 0..60 (0..6 -)
     * Scale: 0.1
     * Offset: 0
     */
    uint8_t multiplexed_signal_one_a;

    /**
     * Range: 0..30 (0..3 -)
     * Scale: 0.1
     * Offset: 0
     */
    uint8_t multiplexed_signal_zero_b;

    /**
     * Range: 0..60 (0..6 -)
     * Scale: 0.1
     * Offset: 0
     */
    uint8_t multiplexed_signal_one_b;
};

/**
 * Pack message Foo.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int example_foo_pack(
    uint8_t *dst_p,
    const struct example_foo_t *src_p,
    size_t size);

/**
 * Unpack message Foo.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int example_foo_unpack(
    struct example_foo_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int16_t example_foo_current_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_foo_current_decode(int16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_foo_current_is_in_range(int16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t example_foo_voltage_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_foo_voltage_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_foo_voltage_is_in_range(uint16_t value);

/**
 * Pack message FooInexact.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int example_foo_inexact_pack(
    uint8_t *dst_p,
    const struct example_foo_inexact_t *src_p,
    size_t size);

/**
 * Unpack message FooInexact.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int example_foo_inexact_unpack(
    struct example_foo_inexact_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
int16_t example_foo_inexact_current_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_foo_inexact_current_decode(int16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_foo_inexact_current_is_in_range(int16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t example_foo_inexact_voltage_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_foo_inexact_voltage_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_foo_inexact_voltage_is_in_range(uint16_t value);

/**
 * Pack message Bar.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int example_bar_pack(
    uint8_t *dst_p,
    const struct example_bar_t *src_p,
    size_t size);

/**
 * Unpack message Bar.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int example_bar_unpack(
    struct example_bar_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_bar_two_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_bar_two_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_bar_two_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_bar_one_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_bar_one_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_bar_one_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_bar_three_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_bar_three_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_bar_three_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_bar_four_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_bar_four_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_bar_four_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_bar_type_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_bar_type_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_bar_type_is_in_range(uint8_t value);

/**
 * Pack message _4WD.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int example__4_wd_pack(
    uint8_t *dst_p,
    const struct example__4_wd_t *src_p,
    size_t size);

/**
 * Unpack message _4WD.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int example__4_wd_unpack(
    struct example__4_wd_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example__4_wd__4_drive_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example__4_wd__4_drive_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example__4_wd__4_drive_is_in_range(uint8_t value);

/**
 * Pack message Amet.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int example_amet_pack(
    uint8_t *dst_p,
    const struct example_amet_t *src_p,
    size_t size);

/**
 * Unpack message Amet.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int example_amet_unpack(
    struct example_amet_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_amet_two_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_amet_two_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_amet_two_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_amet_one_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_amet_one_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_amet_one_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_amet_three_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_amet_three_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_amet_three_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_amet_four_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_amet_four_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_amet_four_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_amet_five_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_amet_five_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_amet_five_is_in_range(uint8_t value);

/**
 * Pack message Dolor.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int example_dolor_pack(
    uint8_t *dst_p,
    const struct example_dolor_t *src_p,
    size_t size);

/**
 * Unpack message Dolor.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int example_dolor_unpack(
    struct example_dolor_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t example_dolor_one_float_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_dolor_one_float_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_dolor_one_float_is_in_range(uint16_t value);

/**
 * Pack message MultiplexTest.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int example_multiplex_test_pack(
    uint8_t *dst_p,
    const struct example_multiplex_test_t *src_p,
    size_t size);

/**
 * Unpack message MultiplexTest.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int example_multiplex_test_unpack(
    struct example_multiplex_test_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_multiplex_test_multiplexor_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_multiplex_test_multiplexor_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_multiplex_test_multiplexor_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_multiplex_test_unmultiplexed_signal_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_multiplex_test_unmultiplexed_signal_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_multiplex_test_unmultiplexed_signal_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_multiplex_test_multiplexed_signal_zero_a_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_multiplex_test_multiplexed_signal_zero_a_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_multiplex_test_multiplexed_signal_zero_a_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_multiplex_test_multiplexed_signal_one_a_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_multiplex_test_multiplexed_signal_one_a_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_multiplex_test_multiplexed_signal_one_a_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_multiplex_test_multiplexed_signal_zero_b_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_multiplex_test_multiplexed_signal_zero_b_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_multiplex_test_multiplexed_signal_zero_b_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t example_multiplex_test_multiplexed_signal_one_b_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double example_multiplex_test_multiplexed_signal_one_b_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool example_multiplex_test_multiplexed_signal_one_b_is_in_range(uint8_t value);


#ifdef __cplusplus
}
#endif

#endif
