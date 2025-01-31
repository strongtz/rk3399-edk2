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

#define MHz 1000000
#define KHz 1000

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

VOID
rk3399_pmu_clock_init(
  VOID
  );

VOID
rk3399_clock_init(
  VOID
  );

UINT32
rk3399_pll_get_rate(
  IN  rk3399_pll_id pll_id
  );

void
rk3399_configure_cpu(
  IN  apll_frequencies freq,
  IN  cpu_cluster cluster
  );

/* core clocks */
#define PLL_APLLL       1
#define PLL_APLLB       2
#define PLL_DPLL        3
#define PLL_CPLL        4
#define PLL_GPLL        5
#define PLL_NPLL        6
#define PLL_VPLL        7
#define ARMCLKL         8
#define ARMCLKB         9

/* sclk gates (special clocks) */
#define SCLK_I2C1                       65
#define SCLK_I2C2                       66
#define SCLK_I2C3                       67
#define SCLK_I2C5                       68
#define SCLK_I2C6                       69
#define SCLK_I2C7                       70
#define SCLK_SPI0                       71
#define SCLK_SPI1                       72
#define SCLK_SPI2                       73
#define SCLK_SPI4                       74
#define SCLK_SPI5                       75
#define SCLK_SDMMC                      76
#define SCLK_SDIO                       77
#define SCLK_EMMC                       78
#define SCLK_TSADC                      79
#define SCLK_SARADC                     80
#define SCLK_UART0                      81
#define SCLK_UART1                      82
#define SCLK_UART2                      83
#define SCLK_UART3                      84
#define SCLK_SPDIF_8CH                  85
#define SCLK_I2S0_8CH                   86
#define SCLK_I2S1_8CH                   87
#define SCLK_I2S2_8CH                   88
#define SCLK_I2S_8CH_OUT                89
#define SCLK_TIMER00                    90
#define SCLK_TIMER01                    91
#define SCLK_TIMER02                    92
#define SCLK_TIMER03                    93
#define SCLK_TIMER04                    94
#define SCLK_TIMER05                    95
#define SCLK_TIMER06                    96
#define SCLK_TIMER07                    97
#define SCLK_TIMER08                    98
#define SCLK_TIMER09                    99
#define SCLK_TIMER10                    100
#define SCLK_TIMER11                    101
#define SCLK_MACREF                     102
#define SCLK_MAC_RX                     103
#define SCLK_MAC_TX                     104
#define SCLK_MAC                        105
#define SCLK_MACREF_OUT                 106
#define SCLK_VOP0_PWM                   107
#define SCLK_VOP1_PWM                   108
#define SCLK_RGA_CORE                   109
#define SCLK_ISP0                       110
#define SCLK_ISP1                       111
#define SCLK_HDMI_CEC                   112
#define SCLK_HDMI_SFR                   113
#define SCLK_DP_CORE                    114
#define SCLK_PVTM_CORE_L                115
#define SCLK_PVTM_CORE_B                116
#define SCLK_PVTM_GPU                   117
#define SCLK_PVTM_DDR                   118
#define SCLK_MIPIDPHY_REF               119
#define SCLK_MIPIDPHY_CFG               120
#define SCLK_HSICPHY                    121
#define SCLK_USBPHY480M                 122
#define SCLK_USB2PHY0_REF               123
#define SCLK_USB2PHY1_REF               124
#define SCLK_UPHY0_TCPDPHY_REF          125
#define SCLK_UPHY0_TCPDCORE             126
#define SCLK_UPHY1_TCPDPHY_REF          127
#define SCLK_UPHY1_TCPDCORE             128
#define SCLK_USB3OTG0_REF               129
#define SCLK_USB3OTG1_REF               130
#define SCLK_USB3OTG0_SUSPEND           131
#define SCLK_USB3OTG1_SUSPEND           132
#define SCLK_CRYPTO0                    133
#define SCLK_CRYPTO1                    134
#define SCLK_CCI_TRACE                  135
#define SCLK_CS                         136
#define SCLK_CIF_OUT                    137
#define SCLK_PCIEPHY_REF                138
#define SCLK_PCIE_CORE                  139
#define SCLK_M0_PERILP                  140
#define SCLK_M0_PERILP_DEC              141
#define SCLK_CM0S                       142
#define SCLK_DBG_NOC                    143
#define SCLK_DBG_PD_CORE_B              144
#define SCLK_DBG_PD_CORE_L              145
#define SCLK_DFIMON0_TIMER              146
#define SCLK_DFIMON1_TIMER              147
#define SCLK_INTMEM0                    148
#define SCLK_INTMEM1                    149
#define SCLK_INTMEM2                    150
#define SCLK_INTMEM3                    151
#define SCLK_INTMEM4                    152
#define SCLK_INTMEM5                    153
#define SCLK_SDMMC_DRV                  154
#define SCLK_SDMMC_SAMPLE               155
#define SCLK_SDIO_DRV                   156
#define SCLK_SDIO_SAMPLE                157
#define SCLK_VDU_CORE                   158
#define SCLK_VDU_CA                     159
#define SCLK_PCIE_PM                    160
#define SCLK_SPDIF_REC_DPTX             161
#define SCLK_DPHY_PLL                   162
#define SCLK_DPHY_TX0_CFG               163
#define SCLK_DPHY_TX1RX1_CFG            164
#define SCLK_DPHY_RX0_CFG               165
#define SCLK_RMII_SRC                   166
#define SCLK_PCIEPHY_REF100M            167
#define SCLK_USBPHY0_480M_SRC           168
#define SCLK_USBPHY1_480M_SRC           169
#define SCLK_DDRCLK                     170
#define SCLK_TESTOUT2                   171

#define DCLK_VOP0                       180
#define DCLK_VOP1                       181
#define DCLK_VOP0_DIV                   182
#define DCLK_VOP1_DIV                   183
#define DCLK_M0_PERILP                  184

#define FCLK_CM0S                       190

/* aclk gates */
#define ACLK_PERIHP                     192
#define ACLK_PERIHP_NOC                 193
#define ACLK_PERILP0                    194
#define ACLK_PERILP0_NOC                195
#define ACLK_PERF_PCIE                  196
#define ACLK_PCIE                       197
#define ACLK_INTMEM                     198
#define ACLK_TZMA                       199
#define ACLK_DCF                        200
#define ACLK_CCI                        201
#define ACLK_CCI_NOC0                   202
#define ACLK_CCI_NOC1                   203
#define ACLK_CCI_GRF                    204
#define ACLK_CENTER                     205
#define ACLK_CENTER_MAIN_NOC            206
#define ACLK_CENTER_PERI_NOC            207
#define ACLK_GPU                        208
#define ACLK_PERF_GPU                   209
#define ACLK_GPU_GRF                    210
#define ACLK_DMAC0_PERILP               211
#define ACLK_DMAC1_PERILP               212
#define ACLK_GMAC                       213
#define ACLK_GMAC_NOC                   214
#define ACLK_PERF_GMAC                  215
#define ACLK_VOP0_NOC                   216
#define ACLK_VOP0                       217
#define ACLK_VOP1_NOC                   218
#define ACLK_VOP1                       219
#define ACLK_RGA                        220
#define ACLK_RGA_NOC                    221
#define ACLK_HDCP                       222
#define ACLK_HDCP_NOC                   223
#define ACLK_HDCP22                     224
#define ACLK_IEP                        225
#define ACLK_IEP_NOC                    226
#define ACLK_VIO                        227
#define ACLK_VIO_NOC                    228
#define ACLK_ISP0                       229
#define ACLK_ISP1                       230
#define ACLK_ISP0_NOC                   231
#define ACLK_ISP1_NOC                   232
#define ACLK_ISP0_WRAPPER               233
#define ACLK_ISP1_WRAPPER               234
#define ACLK_VCODEC                     235
#define ACLK_VCODEC_NOC                 236
#define ACLK_VDU                        237
#define ACLK_VDU_NOC                    238
#define ACLK_PERI                       239
#define ACLK_EMMC                       240
#define ACLK_EMMC_CORE                  241
#define ACLK_EMMC_NOC                   242
#define ACLK_EMMC_GRF                   243
#define ACLK_USB3                       244
#define ACLK_USB3_NOC                   245
#define ACLK_USB3OTG0                   246
#define ACLK_USB3OTG1                   247
#define ACLK_USB3_RKSOC_AXI_PERF        248
#define ACLK_USB3_GRF                   249
#define ACLK_GIC                        250
#define ACLK_GIC_NOC                    251
#define ACLK_GIC_ADB400_CORE_L_2_GIC    252
#define ACLK_GIC_ADB400_CORE_B_2_GIC    253
#define ACLK_GIC_ADB400_GIC_2_CORE_L    254
#define ACLK_GIC_ADB400_GIC_2_CORE_B    255
#define ACLK_CORE_ADB400_CORE_L_2_CCI500 256
#define ACLK_CORE_ADB400_CORE_B_2_CCI500 257
#define ACLK_ADB400M_PD_CORE_L          258
#define ACLK_ADB400M_PD_CORE_B          259
#define ACLK_PERF_CORE_L                260
#define ACLK_PERF_CORE_B                261
#define ACLK_GIC_PRE                    262
#define ACLK_VOP0_PRE                   263
#define ACLK_VOP1_PRE                   264

/* pclk gates */
#define PCLK_PERIHP                     320
#define PCLK_PERIHP_NOC                 321
#define PCLK_PERILP0                    322
#define PCLK_PERILP1                    323
#define PCLK_PERILP1_NOC                324
#define PCLK_PERILP_SGRF                325
#define PCLK_PERIHP_GRF                 326
#define PCLK_PCIE                       327
#define PCLK_SGRF                       328
#define PCLK_INTR_ARB                   329
#define PCLK_CENTER_MAIN_NOC            330
#define PCLK_CIC                        331
#define PCLK_COREDBG_B                  332
#define PCLK_COREDBG_L                  333
#define PCLK_DBG_CXCS_PD_CORE_B         334
#define PCLK_DCF                        335
#define PCLK_GPIO2                      336
#define PCLK_GPIO3                      337
#define PCLK_GPIO4                      338
#define PCLK_GRF                        339
#define PCLK_HSICPHY                    340
#define PCLK_I2C1                       341
#define PCLK_I2C2                       342
#define PCLK_I2C3                       343
#define PCLK_I2C5                       344
#define PCLK_I2C6                       345
#define PCLK_I2C7                       346
#define PCLK_SPI0                       347
#define PCLK_SPI1                       348
#define PCLK_SPI2                       349
#define PCLK_SPI4                       350
#define PCLK_SPI5                       351
#define PCLK_UART0                      352
#define PCLK_UART1                      353
#define PCLK_UART2                      354
#define PCLK_UART3                      355
#define PCLK_TSADC                      356
#define PCLK_SARADC                     357
#define PCLK_GMAC                       358
#define PCLK_GMAC_NOC                   359
#define PCLK_TIMER0                     360
#define PCLK_TIMER1                     361
#define PCLK_EDP                        362
#define PCLK_EDP_NOC                    363
#define PCLK_EDP_CTRL                   364
#define PCLK_VIO                        365
#define PCLK_VIO_NOC                    366
#define PCLK_VIO_GRF                    367
#define PCLK_MIPI_DSI0                  368
#define PCLK_MIPI_DSI1                  369
#define PCLK_HDCP                       370
#define PCLK_HDCP_NOC                   371
#define PCLK_HDMI_CTRL                  372
#define PCLK_DP_CTRL                    373
#define PCLK_HDCP22                     374
#define PCLK_GASKET                     375
#define PCLK_DDR                        376
#define PCLK_DDR_MON                    377
#define PCLK_DDR_SGRF                   378
#define PCLK_ISP1_WRAPPER               379
#define PCLK_WDT                        380
#define PCLK_EFUSE1024NS                381
#define PCLK_EFUSE1024S                 382
#define PCLK_PMU_INTR_ARB               383
#define PCLK_MAILBOX0                   384
#define PCLK_USBPHY_MUX_G               385
#define PCLK_UPHY0_TCPHY_G              386
#define PCLK_UPHY0_TCPD_G               387
#define PCLK_UPHY1_TCPHY_G              388
#define PCLK_UPHY1_TCPD_G               389
#define PCLK_ALIVE                      390

/* hclk gates */
#define HCLK_PERIHP                     448
#define HCLK_PERILP0                    449
#define HCLK_PERILP1                    450
#define HCLK_PERILP0_NOC                451
#define HCLK_PERILP1_NOC                452
#define HCLK_M0_PERILP                  453
#define HCLK_M0_PERILP_NOC              454
#define HCLK_AHB1TOM                    455
#define HCLK_HOST0                      456
#define HCLK_HOST0_ARB                  457
#define HCLK_HOST1                      458
#define HCLK_HOST1_ARB                  459
#define HCLK_HSIC                       460
#define HCLK_SD                         461
#define HCLK_SDMMC                      462
#define HCLK_SDMMC_NOC                  463
#define HCLK_M_CRYPTO0                  464
#define HCLK_M_CRYPTO1                  465
#define HCLK_S_CRYPTO0                  466
#define HCLK_S_CRYPTO1                  467
#define HCLK_I2S0_8CH                   468
#define HCLK_I2S1_8CH                   469
#define HCLK_I2S2_8CH                   470
#define HCLK_SPDIF                      471
#define HCLK_VOP0_NOC                   472
#define HCLK_VOP0                       473
#define HCLK_VOP1_NOC                   474
#define HCLK_VOP1                       475
#define HCLK_ROM                        476
#define HCLK_IEP                        477
#define HCLK_IEP_NOC                    478
#define HCLK_ISP0                       479
#define HCLK_ISP1                       480
#define HCLK_ISP0_NOC                   481
#define HCLK_ISP1_NOC                   482
#define HCLK_ISP0_WRAPPER               483
#define HCLK_ISP1_WRAPPER               484
#define HCLK_RGA                        485
#define HCLK_RGA_NOC                    486
#define HCLK_HDCP                       487
#define HCLK_HDCP_NOC                   488
#define HCLK_HDCP22                     489
#define HCLK_VCODEC                     490
#define HCLK_VCODEC_NOC                 491
#define HCLK_VDU                        492
#define HCLK_VDU_NOC                    493
#define HCLK_SDIO                       494
#define HCLK_SDIO_NOC                   495
#define HCLK_SDIOAUDIO_NOC              496

#define CLK_NR_CLKS                     (HCLK_SDIOAUDIO_NOC + 1)

#endif /* _CRU_LIB_H_ */
