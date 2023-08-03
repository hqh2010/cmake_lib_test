/*
 * SPDX-FileCopyrightText: 2023 xxxxxx Software Technology Co., Ltd.
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef __FUNC_UTILS_H__
#define __FUNC_UTILS_H__

// #include <stdio.h>

#ifdef __cplusplus

extern "C" {

#endif

/**
 * @brief 两个整形数相加
 *
 * @param x: op1
 * @param y: op2
 *
 * @return int: 两数相加之和
 */
int func_add(int x, int y);

/**
 * @brief 两个整形数相减
 *
 * @param x: op1
 * @param y: op2
 *
 * @return int: 两数相加之差
 */
int func_minus(int x, int y);

#ifdef __cplusplus
}
#endif

#endif
