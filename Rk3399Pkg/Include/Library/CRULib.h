/** @file
 *
 * (C) Copyright 2015 Google, Inc
 * (C) 2017 Theobroma Systems Design und Consulting GmbH
 * (c) Copyright 2019, Andrei Warkentin <andrey.warkentin@gmail.com>
 *
 * SPDX-License-Identifier:     GPL-2.0
 */

#ifndef _CRU_LIB_H_
#define _CRU_LIB_H_

typedef enum rk3399_pll_id {
  APLLL_ID = 0,
  APLLB_ID,
  DPLL_ID,
  CPLL_ID,
  GPLL_ID,
  NPLL_ID,
  VPLL_ID,
  PPLL_ID,
  END_PLL_ID
} rk3399_pll_id;

typedef enum apll_frequencies {
  APLL_1600_MHZ,
  APLL_816_MHZ,
  APLL_600_MHZ,
  APLL_1700_MHZ,
  APLL_1300_MHZ,
} apll_frequencies;

typedef enum cpu_cluster {
  CPU_CLUSTER_LITTLE,
  CPU_CLUSTER_BIG,
} cpu_cluster;

UINT32
rk3399_pll_get_rate(
  IN  rk3399_pll_id pll_id
  );

void
rk3399_configure_cpu(
  IN  apll_frequencies freq,
  IN  cpu_cluster cluster
  );

#endif /* _CRU_LIB_H_ */
