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

#include <string.h>

#include "example.h"

static inline uint8_t pack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t pack_right_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t unpack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) << shift);
}

static inline uint16_t unpack_left_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) << shift);
}

static inline uint8_t unpack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) >> shift);
}

static inline uint16_t unpack_right_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) >> shift);
}

int example_foo_pack(
    uint8_t *dst_p,
    const struct example_foo_t *src_p,
    size_t size)
{
    uint16_t current;

    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    current = (uint16_t)src_p->current;
    dst_p[0] |= pack_left_shift_u16(current, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(current, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->voltage, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->voltage, 8u, 0xffu);

    return (4);
}

int example_foo_unpack(
    struct example_foo_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t current;

    if (size < 4u) {
        return (-EINVAL);
    }

    current = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    current |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->current = (int16_t)current;
    dst_p->voltage = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->voltage |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int16_t example_foo_current_encode(double value)
{
    return (int16_t)(value / 0.0625);
}

double example_foo_current_decode(int16_t value)
{
    return ((double)value * 0.0625);
}

bool example_foo_current_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

uint16_t example_foo_voltage_encode(double value)
{
    return (uint16_t)(value / 0.000976562);
}

double example_foo_voltage_decode(uint16_t value)
{
    return ((double)value * 0.000976562);
}

bool example_foo_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int example_foo_inexact_pack(
    uint8_t *dst_p,
    const struct example_foo_inexact_t *src_p,
    size_t size)
{
    uint16_t current;

    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    current = (uint16_t)src_p->current;
    dst_p[0] |= pack_left_shift_u16(current, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(current, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->voltage, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->voltage, 8u, 0xffu);

    return (4);
}

int example_foo_inexact_unpack(
    struct example_foo_inexact_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t current;

    if (size < 4u) {
        return (-EINVAL);
    }

    current = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    current |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->current = (int16_t)current;
    dst_p->voltage = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->voltage |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int16_t example_foo_inexact_current_encode(double value)
{
    return (int16_t)(value / 0.001);
}

double example_foo_inexact_current_decode(int16_t value)
{
    return ((double)value * 0.001);
}

bool example_foo_inexact_current_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

uint16_t example_foo_inexact_voltage_encode(double value)
{
    return (uint16_t)(value / 0.001);
}

double example_foo_inexact_voltage_decode(uint16_t value)
{
    return ((double)value * 0.001);
}

bool example_foo_inexact_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int example_bar_pack(
    uint8_t *dst_p,
    const struct example_bar_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->two, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->one, 6u, 0xc0u);
    dst_p[1] |= pack_left_shift_u8(src_p->three, 3u, 0x38u);
    dst_p[1] |= pack_left_shift_u8(src_p->four, 1u, 0x06u);
    dst_p[3] |= pack_left_shift_u8(src_p->type, 6u, 0x40u);

    return (8);
}

int example_bar_unpack(
    struct example_bar_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->two = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->one = unpack_right_shift_u8(src_p[1], 6u, 0xc0u);
    dst_p->three = unpack_right_shift_u8(src_p[1], 3u, 0x38u);
    dst_p->four = unpack_right_shift_u8(src_p[1], 1u, 0x06u);
    dst_p->type = unpack_right_shift_u8(src_p[3], 6u, 0x40u);

    return (0);
}

uint8_t example_bar_two_encode(double value)
{
    return (uint8_t)(value / 0.39);
}

double example_bar_two_decode(uint8_t value)
{
    return ((double)value * 0.39);
}

bool example_bar_two_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t example_bar_one_encode(double value)
{
    return (uint8_t)(value);
}

double example_bar_one_decode(uint8_t value)
{
    return ((double)value);
}

bool example_bar_one_is_in_range(uint8_t value)
{
    return (value <= 3u);
}

uint8_t example_bar_three_encode(double value)
{
    return (uint8_t)(value);
}

double example_bar_three_decode(uint8_t value)
{
    return ((double)value);
}

bool example_bar_three_is_in_range(uint8_t value)
{
    return (value <= 7u);
}

uint8_t example_bar_four_encode(double value)
{
    return (uint8_t)(value);
}

double example_bar_four_decode(uint8_t value)
{
    return ((double)value);
}

bool example_bar_four_is_in_range(uint8_t value)
{
    return (value <= 3u);
}

uint8_t example_bar_type_encode(double value)
{
    return (uint8_t)(value);
}

double example_bar_type_decode(uint8_t value)
{
    return ((double)value);
}

bool example_bar_type_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int example__4_wd_pack(
    uint8_t *dst_p,
    const struct example__4_wd_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[1] |= pack_left_shift_u8(src_p->_4_drive, 3u, 0x38u);

    return (8);
}

int example__4_wd_unpack(
    struct example__4_wd_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->_4_drive = unpack_right_shift_u8(src_p[1], 3u, 0x38u);

    return (0);
}

uint8_t example__4_wd__4_drive_encode(double value)
{
    return (uint8_t)(value);
}

double example__4_wd__4_drive_decode(uint8_t value)
{
    return ((double)value);
}

bool example__4_wd__4_drive_is_in_range(uint8_t value)
{
    return (value <= 7u);
}

int example_amet_pack(
    uint8_t *dst_p,
    const struct example_amet_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->two, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->one, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->three, 2u, 0x1cu);
    dst_p[3] |= pack_left_shift_u8(src_p->four, 5u, 0x60u);
    dst_p[5] |= pack_left_shift_u8(src_p->five, 0u, 0x01u);

    return (8);
}

int example_amet_unpack(
    struct example_amet_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->two = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->one = unpack_right_shift_u8(src_p[1], 6u, 0xc0u);
    dst_p->three = unpack_right_shift_u8(src_p[2], 2u, 0x1cu);
    dst_p->four = unpack_right_shift_u8(src_p[3], 5u, 0x60u);
    dst_p->five = unpack_right_shift_u8(src_p[5], 0u, 0x01u);

    return (0);
}

uint8_t example_amet_two_encode(double value)
{
    return (uint8_t)(value / 0.39);
}

double example_amet_two_decode(uint8_t value)
{
    return ((double)value * 0.39);
}

bool example_amet_two_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t example_amet_one_encode(double value)
{
    return (uint8_t)(value);
}

double example_amet_one_decode(uint8_t value)
{
    return ((double)value);
}

bool example_amet_one_is_in_range(uint8_t value)
{
    return (value <= 3u);
}

uint8_t example_amet_three_encode(double value)
{
    return (uint8_t)(value);
}

double example_amet_three_decode(uint8_t value)
{
    return ((double)value);
}

bool example_amet_three_is_in_range(uint8_t value)
{
    return (value <= 7u);
}

uint8_t example_amet_four_encode(double value)
{
    return (uint8_t)(value);
}

double example_amet_four_decode(uint8_t value)
{
    return ((double)value);
}

bool example_amet_four_is_in_range(uint8_t value)
{
    return (value <= 3u);
}

uint8_t example_amet_five_encode(double value)
{
    return (uint8_t)(value);
}

double example_amet_five_decode(uint8_t value)
{
    return ((double)value);
}

bool example_amet_five_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int example_dolor_pack(
    uint8_t *dst_p,
    const struct example_dolor_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->one_float, 11u, 0x01u);
    dst_p[1] |= pack_right_shift_u16(src_p->one_float, 3u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->one_float, 5u, 0xe0u);

    return (8);
}

int example_dolor_unpack(
    struct example_dolor_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->one_float = unpack_left_shift_u16(src_p[0], 11u, 0x01u);
    dst_p->one_float |= unpack_left_shift_u16(src_p[1], 3u, 0xffu);
    dst_p->one_float |= unpack_right_shift_u16(src_p[2], 5u, 0xe0u);

    return (0);
}

uint16_t example_dolor_one_float_encode(double value)
{
    return (uint16_t)(value / 0.5);
}

double example_dolor_one_float_decode(uint16_t value)
{
    return ((double)value * 0.5);
}

bool example_dolor_one_float_is_in_range(uint16_t value)
{
    return (value <= 260u);
}

int example_multiplex_test_pack(
    uint8_t *dst_p,
    const struct example_multiplex_test_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->multiplexor, 0u, 0x0fu);
    dst_p[0] |= pack_left_shift_u8(src_p->unmultiplexed_signal, 4u, 0xf0u);
    dst_p[1] |= pack_right_shift_u8(src_p->unmultiplexed_signal, 4u, 0x0fu);

    switch (src_p->multiplexor) {

    case 0:
        dst_p[1] |= pack_left_shift_u8(src_p->multiplexed_signal_zero_a, 4u, 0xf0u);
        dst_p[2] |= pack_right_shift_u8(src_p->multiplexed_signal_zero_a, 4u, 0x0fu);
        dst_p[2] |= pack_left_shift_u8(src_p->multiplexed_signal_zero_b, 4u, 0xf0u);
        dst_p[3] |= pack_right_shift_u8(src_p->multiplexed_signal_zero_b, 4u, 0x0fu);
        break;

    case 1:
        dst_p[1] |= pack_left_shift_u8(src_p->multiplexed_signal_one_a, 4u, 0xf0u);
        dst_p[2] |= pack_right_shift_u8(src_p->multiplexed_signal_one_a, 4u, 0x0fu);
        dst_p[2] |= pack_left_shift_u8(src_p->multiplexed_signal_one_b, 4u, 0xf0u);
        dst_p[3] |= pack_right_shift_u8(src_p->multiplexed_signal_one_b, 4u, 0x0fu);
        break;

    default:
        break;
    }

    return (8);
}

int example_multiplex_test_unpack(
    struct example_multiplex_test_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->multiplexor = unpack_right_shift_u8(src_p[0], 0u, 0x0fu);
    dst_p->unmultiplexed_signal = unpack_right_shift_u8(src_p[0], 4u, 0xf0u);
    dst_p->unmultiplexed_signal |= unpack_left_shift_u8(src_p[1], 4u, 0x0fu);

    switch (dst_p->multiplexor) {

    case 0:
        dst_p->multiplexed_signal_zero_a = unpack_right_shift_u8(src_p[1], 4u, 0xf0u);
        dst_p->multiplexed_signal_zero_a |= unpack_left_shift_u8(src_p[2], 4u, 0x0fu);
        dst_p->multiplexed_signal_zero_b = unpack_right_shift_u8(src_p[2], 4u, 0xf0u);
        dst_p->multiplexed_signal_zero_b |= unpack_left_shift_u8(src_p[3], 4u, 0x0fu);
        break;

    case 1:
        dst_p->multiplexed_signal_one_a = unpack_right_shift_u8(src_p[1], 4u, 0xf0u);
        dst_p->multiplexed_signal_one_a |= unpack_left_shift_u8(src_p[2], 4u, 0x0fu);
        dst_p->multiplexed_signal_one_b = unpack_right_shift_u8(src_p[2], 4u, 0xf0u);
        dst_p->multiplexed_signal_one_b |= unpack_left_shift_u8(src_p[3], 4u, 0x0fu);
        break;

    default:
        break;
    }

    return (0);
}

uint8_t example_multiplex_test_multiplexor_encode(double value)
{
    return (uint8_t)(value);
}

double example_multiplex_test_multiplexor_decode(uint8_t value)
{
    return ((double)value);
}

bool example_multiplex_test_multiplexor_is_in_range(uint8_t value)
{
    return (value <= 2u);
}

uint8_t example_multiplex_test_unmultiplexed_signal_encode(double value)
{
    return (uint8_t)(value);
}

double example_multiplex_test_unmultiplexed_signal_decode(uint8_t value)
{
    return ((double)value);
}

bool example_multiplex_test_unmultiplexed_signal_is_in_range(uint8_t value)
{
    return (value <= 4u);
}

uint8_t example_multiplex_test_multiplexed_signal_zero_a_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double example_multiplex_test_multiplexed_signal_zero_a_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool example_multiplex_test_multiplexed_signal_zero_a_is_in_range(uint8_t value)
{
    return (value <= 30u);
}

uint8_t example_multiplex_test_multiplexed_signal_one_a_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double example_multiplex_test_multiplexed_signal_one_a_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool example_multiplex_test_multiplexed_signal_one_a_is_in_range(uint8_t value)
{
    return (value <= 60u);
}

uint8_t example_multiplex_test_multiplexed_signal_zero_b_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double example_multiplex_test_multiplexed_signal_zero_b_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool example_multiplex_test_multiplexed_signal_zero_b_is_in_range(uint8_t value)
{
    return (value <= 30u);
}

uint8_t example_multiplex_test_multiplexed_signal_one_b_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double example_multiplex_test_multiplexed_signal_one_b_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool example_multiplex_test_multiplexed_signal_one_b_is_in_range(uint8_t value)
{
    return (value <= 60u);
}
