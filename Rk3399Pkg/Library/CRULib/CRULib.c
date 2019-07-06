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

#include <PiDxe.h>
#include <Library/DebugLib.h>
#include <Library/ArmLib.h>
#include <Library/BaseLib.h>
#include <Library/TimerLib.h>
#include <Library/IoLib.h>
#include <Library/CRULib.h>


UINT32
RkClkPllGetRate (
  enum RkPllsId pll_id
  )
{
  UINT32 Con, PllCon0, PllCon1, PllCon2, Dsmp;

  if (pll_id == PPLL_ID) {
    Con = PmuCruReadl(PMUCRU_PLL_CON(0, 3)) & PLL_MODE_MSK;
    PllCon0 = PmuCruReadl(PMUCRU_PLL_CON(0, 0));
    PllCon1 = PmuCruReadl(PMUCRU_PLL_CON(0, 1));
    PllCon2 = PmuCruReadl(PMUCRU_PLL_CON(0, 2));
    Dsmp = PLL_GET_DSMPD(PmuCruReadl(PMUCRU_PLL_CON(0, 3)));
  } else {
    Con = CruReadl(CRU_PLL_CON(pll_id, 3)) & PLL_MODE_MSK;
    PllCon0 = CruReadl(CRU_PLL_CON(pll_id, 0));
    PllCon1 = CruReadl(CRU_PLL_CON(pll_id, 1));
    PllCon2 = CruReadl(CRU_PLL_CON(pll_id, 2));
    Dsmp = PLL_GET_DSMPD(CruReadl(CRU_PLL_CON(pll_id, 3)));
  }

  if (Con == PLL_MODE_SLOW) { /* slow mode */
    return 24 * MHZ;
  } else if (Con == PLL_MODE_NORM) { /* normal mode */
    UINT32 Rate = 0, FracRate64 = 0;

    /* integer mode */
    Rate = (UINT32)(24) * PLL_GET_FBDIV(PllCon0);
    Rate = Rate / PLL_GET_REFDIV(PllCon1);
    if (FRAC_MODE == Dsmp) {
    /* fractional mode */
      FracRate64 = (UINT32)(24) * PLL_GET_FRAC(PllCon2);
      FracRate64 = FracRate64 / PLL_GET_REFDIV(PllCon1);
      Rate += FracRate64 >> 24;
    }
    Rate = Rate / PLL_GET_POSTDIV1(PllCon1);
    Rate = Rate / PLL_GET_POSTDIV2(PllCon1);
    return Rate * MHZ;
  } else { /* deep slow mode */
    return 32768;
  }
}
