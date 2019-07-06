/** @file
*
*  Copyright (c) 2017, Rockchip Inc. All rights reserved.
*  Copyright (c) 2019, Andrey Warkentin <andrey.warkentin@gmail.com>
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#ifndef _CRU_LIB_H_
#define _CRU_LIB_H_

#include <Rk3399/Rk3399.h>
#include <Rk3399/Rk3399Cru.h>

#define FRAC_MODE       0
#define MHZ             (1000 * 1000)

UINT32 RkClkPllGetRate (
  IN  enum RkPllsId pll_id
  );

#endif /* _CRU_LIB_H_ */
