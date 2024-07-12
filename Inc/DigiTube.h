/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DIGITUBE_H
#define DIGITUBE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "py32c6xx_ll_rcc.h"
#include "py32c6xx_ll_bus.h"
#include "py32c6xx_ll_system.h"
#include "py32c6xx_ll_exti.h"
#include "py32c6xx_ll_cortex.h"
#include "py32c6xx_ll_utils.h"
#include "py32c6xx_ll_pwr.h"
#include "py32c6xx_ll_dma.h"
#include "py32c6xx_ll_gpio.h"
#include "py32c6xx_ll_comp.h"
#include "py32c6xx_ll_tim.h"
#include "py32c6xx_ll_adc.h"
#include "py32c6xx_hal.h"
#include "py32c6xx_ll_wwdg.h"
#include "py32c6xx_ll_iwdg.h"
#include "py32c6xx_ll_lptim.h"

void DigiTubeCtr_Seq(void);//timer 1MS

void DigiTubeCtr_Play(void);

void DigiTube_DianLiang_Ctr(uint8_t DigiTube_DianLiang_Inside_Flag,uint8_t DigiTube_DianLiang_Outside_Level);
void DigiTube_DianLiang_Ctr1(uint8_t DigiTube_DianLiang_Inside_Flag,uint8_t DigiTube_DianLiang_Outside_Flag,uint8_t DigiTube_DianLiang_Outside_Level);
void DigiTube_YouLiang_Ctr(uint8_t DigiTube_YouLiang_Inside_Flag,uint8_t DigiTube_YouLiang_Outside_Level);
void DigiTube_GongLv_Ctr(uint8_t DigiTube_GongLv_Inside_Flag,uint8_t DigiTube_GongLv_Inside_GeWei,uint8_t DigiTube_GongLv_Inside_ShiWei,uint8_t DigiTube_GongLv_Outside_Level);
void DigiTube_HuoYan_Ctr(uint8_t DigiTube_HuoYan_Flag);
void DigiTube_ShiJian_Ctr(uint8_t DigiTube_ShiJian_Flag,uint8_t DigiTube_ShiJian_GeWei,uint8_t DigiTube_ShiJian_ShiWei);
void DigiTube_KaiGuanJi_Ctr(uint8_t DigiTube_KaiGuanJi_Flag);
void DigiTube_HuoYan_KaiGuan_Ctr(uint8_t DigiTube_HuoYan_KaiGuan_Flag);
void DigiTube_HuoYan_Level_Ctr(uint32_t DigiTube_HuoYan_Level);

void DigiTubeCtr_Level_State_All_On();
void DigiTubeCtr_Level_State_All_Off();
void DigiTubeCtr_Level_State_Ctrl();



extern uint8_t R_DigiTube_Seq_Buf;
#define C_DigiTube_Start	0
#define	C_DigiTube_Total	7

extern uint8_t DigiTubeCtr_State[13][8];
extern uint8_t DigiTubeCtr_State_COM;

#define DigiTubeCtr_A1_State	DigiTubeCtr_State[0][0]
#define DigiTubeCtr_A2_State	DigiTubeCtr_State[0][1]
#define DigiTubeCtr_A3_State	DigiTubeCtr_State[0][2]
#define DigiTubeCtr_A4_State	DigiTubeCtr_State[0][3]
#define DigiTubeCtr_A5_State	DigiTubeCtr_State[0][4]
#define DigiTubeCtr_A6_State	DigiTubeCtr_State[0][5]
#define DigiTubeCtr_A7_State	DigiTubeCtr_State[0][6]
#define DigiTubeCtr_A8_State	DigiTubeCtr_State[0][7]
	
#define DigiTubeCtr_B1_State	DigiTubeCtr_State[1][0]
#define DigiTubeCtr_B2_State	DigiTubeCtr_State[1][1]
#define DigiTubeCtr_B3_State	DigiTubeCtr_State[1][2]
#define DigiTubeCtr_B4_State	DigiTubeCtr_State[1][3]
#define DigiTubeCtr_B5_State	DigiTubeCtr_State[1][4]
#define DigiTubeCtr_B6_State	DigiTubeCtr_State[1][5]
#define DigiTubeCtr_B7_State	DigiTubeCtr_State[1][6]
#define DigiTubeCtr_B8_State	DigiTubeCtr_State[1][7]
	
#define DigiTubeCtr_C1_State	DigiTubeCtr_State[2][0]
#define DigiTubeCtr_C2_State	DigiTubeCtr_State[2][1]
#define DigiTubeCtr_C3_State	DigiTubeCtr_State[2][2]
#define DigiTubeCtr_C4_State	DigiTubeCtr_State[2][3]
#define DigiTubeCtr_C5_State	DigiTubeCtr_State[2][4]
#define DigiTubeCtr_C6_State	DigiTubeCtr_State[2][5]
#define DigiTubeCtr_C7_State	DigiTubeCtr_State[2][6]
#define DigiTubeCtr_C8_State	DigiTubeCtr_State[2][7]
	
#define DigiTubeCtr_D1_State	DigiTubeCtr_State[3][0]
#define DigiTubeCtr_D2_State	DigiTubeCtr_State[3][1]
#define DigiTubeCtr_D3_State	DigiTubeCtr_State[3][2]
#define DigiTubeCtr_D4_State	DigiTubeCtr_State[3][3]
#define DigiTubeCtr_D5_State	DigiTubeCtr_State[3][4]
#define DigiTubeCtr_D6_State	DigiTubeCtr_State[3][5]
#define DigiTubeCtr_D7_State	DigiTubeCtr_State[3][6]
#define DigiTubeCtr_D8_State	DigiTubeCtr_State[3][7]
	
#define DigiTubeCtr_E1_State	DigiTubeCtr_State[4][0]
#define DigiTubeCtr_E2_State	DigiTubeCtr_State[4][1]
#define DigiTubeCtr_E3_State	DigiTubeCtr_State[4][2]
#define DigiTubeCtr_E4_State	DigiTubeCtr_State[4][3]
#define DigiTubeCtr_E5_State	DigiTubeCtr_State[4][4]
#define DigiTubeCtr_E6_State	DigiTubeCtr_State[4][5]
#define DigiTubeCtr_E7_State	DigiTubeCtr_State[4][6]
#define DigiTubeCtr_E8_State	DigiTubeCtr_State[4][7]
	
#define DigiTubeCtr_F1_State	DigiTubeCtr_State[5][0]
#define DigiTubeCtr_F2_State	DigiTubeCtr_State[5][1]
#define DigiTubeCtr_F3_State	DigiTubeCtr_State[5][2]
#define DigiTubeCtr_F4_State	DigiTubeCtr_State[5][3]
#define DigiTubeCtr_F5_State	DigiTubeCtr_State[5][4]
#define DigiTubeCtr_F6_State	DigiTubeCtr_State[5][5]
#define DigiTubeCtr_F7_State	DigiTubeCtr_State[5][6]
#define DigiTubeCtr_F8_State	DigiTubeCtr_State[5][7]
	
#define DigiTubeCtr_G1_State	DigiTubeCtr_State[6][0]
#define DigiTubeCtr_G2_State	DigiTubeCtr_State[6][1]
#define DigiTubeCtr_G3_State	DigiTubeCtr_State[6][2]
#define DigiTubeCtr_G4_State	DigiTubeCtr_State[6][3]
#define DigiTubeCtr_G5_State	DigiTubeCtr_State[6][4]
#define DigiTubeCtr_G6_State	DigiTubeCtr_State[6][5]
#define DigiTubeCtr_G7_State	DigiTubeCtr_State[6][6]
#define DigiTubeCtr_G8_State	DigiTubeCtr_State[6][7]
	
#define DigiTubeCtr_H1_State	DigiTubeCtr_State[7][0]
#define DigiTubeCtr_H2_State	DigiTubeCtr_State[7][1]
#define DigiTubeCtr_H3_State	DigiTubeCtr_State[7][2]
#define DigiTubeCtr_H4_State	DigiTubeCtr_State[7][3]
#define DigiTubeCtr_H5_State	DigiTubeCtr_State[7][4]
#define DigiTubeCtr_H6_State	DigiTubeCtr_State[7][5]
#define DigiTubeCtr_H7_State	DigiTubeCtr_State[7][6]
#define DigiTubeCtr_H8_State	DigiTubeCtr_State[7][7]
	
#define DigiTubeCtr_I1_State	DigiTubeCtr_State[8][0]
#define DigiTubeCtr_I2_State	DigiTubeCtr_State[8][1]
#define DigiTubeCtr_I3_State	DigiTubeCtr_State[8][2]
#define DigiTubeCtr_I4_State	DigiTubeCtr_State[8][3]
#define DigiTubeCtr_I5_State	DigiTubeCtr_State[8][4]
#define DigiTubeCtr_I6_State	DigiTubeCtr_State[8][5]
#define DigiTubeCtr_I7_State	DigiTubeCtr_State[8][6]
#define DigiTubeCtr_I8_State	DigiTubeCtr_State[8][7]
	
#define DigiTubeCtr_J1_State	DigiTubeCtr_State[9][0]
#define DigiTubeCtr_J2_State	DigiTubeCtr_State[9][1]
#define DigiTubeCtr_J3_State	DigiTubeCtr_State[9][2]
#define DigiTubeCtr_J4_State	DigiTubeCtr_State[9][3]
#define DigiTubeCtr_J5_State	DigiTubeCtr_State[9][4]
#define DigiTubeCtr_J6_State	DigiTubeCtr_State[9][5]
#define DigiTubeCtr_J7_State	DigiTubeCtr_State[9][6]
#define DigiTubeCtr_J8_State	DigiTubeCtr_State[9][7]
	
#define DigiTubeCtr_K1_State	DigiTubeCtr_State[10][0]
#define DigiTubeCtr_K2_State	DigiTubeCtr_State[10][1]
#define DigiTubeCtr_K3_State	DigiTubeCtr_State[10][2]
#define DigiTubeCtr_K4_State	DigiTubeCtr_State[10][3]
#define DigiTubeCtr_K5_State	DigiTubeCtr_State[10][4]
#define DigiTubeCtr_K6_State	DigiTubeCtr_State[10][5]
#define DigiTubeCtr_K7_State	DigiTubeCtr_State[10][6]
#define DigiTubeCtr_K8_State	DigiTubeCtr_State[10][7]
	
#define DigiTubeCtr_L1_State	DigiTubeCtr_State[11][0]
#define DigiTubeCtr_L2_State	DigiTubeCtr_State[11][1]
#define DigiTubeCtr_L3_State	DigiTubeCtr_State[11][2]
#define DigiTubeCtr_L4_State	DigiTubeCtr_State[11][3]
#define DigiTubeCtr_L5_State	DigiTubeCtr_State[11][4]
#define DigiTubeCtr_L6_State	DigiTubeCtr_State[11][5]
#define DigiTubeCtr_L7_State	DigiTubeCtr_State[11][6]
#define DigiTubeCtr_L8_State	DigiTubeCtr_State[11][7]
	
#define DigiTubeCtr_M1_State	DigiTubeCtr_State[12][0]
#define DigiTubeCtr_M2_State	DigiTubeCtr_State[12][1]
#define DigiTubeCtr_M3_State	DigiTubeCtr_State[12][2]
#define DigiTubeCtr_M4_State	DigiTubeCtr_State[12][3]
#define DigiTubeCtr_M5_State	DigiTubeCtr_State[12][4]
#define DigiTubeCtr_M6_State	DigiTubeCtr_State[12][5]
#define DigiTubeCtr_M7_State	DigiTubeCtr_State[12][6]
#define DigiTubeCtr_M8_State	DigiTubeCtr_State[12][7]

#define DigiTube_State_On 1
#define DigiTube_State_Off 0


extern uint8_t DigiTubeCtr_State_Level[13][8];
extern uint8_t DigiTubeCtr_State_COM_Level;
	
extern uint8_t DigiTubeCtr_Level1_State;
extern uint8_t DigiTubeCtr_Level2_State;
extern uint8_t DigiTubeCtr_Level3_State;
extern uint8_t DigiTubeCtr_Level4_State;
extern uint8_t DigiTubeCtr_Level5_State;
extern uint8_t DigiTubeCtr_Level6_State;
extern uint8_t DigiTubeCtr_Level7_State;
extern uint8_t DigiTubeCtr_Level8_State;
extern uint8_t DigiTubeCtr_Level9_State;
extern uint8_t DigiTubeCtr_Level10_State;
	

#define DigiTubeCtr_A1_State_Level	DigiTubeCtr_State_Level[0][0]
#define DigiTubeCtr_A2_State_Level	DigiTubeCtr_State_Level[0][1]
#define DigiTubeCtr_A3_State_Level	DigiTubeCtr_State_Level[0][2]
#define DigiTubeCtr_A4_State_Level	DigiTubeCtr_State_Level[0][3]
#define DigiTubeCtr_A5_State_Level	DigiTubeCtr_State_Level[0][4]
#define DigiTubeCtr_A6_State_Level	DigiTubeCtr_State_Level[0][5]
#define DigiTubeCtr_A7_State_Level	DigiTubeCtr_State_Level[0][6]
#define DigiTubeCtr_A8_State_Level	DigiTubeCtr_State_Level[0][7]
		
#define DigiTubeCtr_B1_State_Level	DigiTubeCtr_State_Level[1][0]
#define DigiTubeCtr_B2_State_Level	DigiTubeCtr_State_Level[1][1]
#define DigiTubeCtr_B3_State_Level	DigiTubeCtr_State_Level[1][2]
#define DigiTubeCtr_B4_State_Level	DigiTubeCtr_State_Level[1][3]
#define DigiTubeCtr_B5_State_Level	DigiTubeCtr_State_Level[1][4]
#define DigiTubeCtr_B6_State_Level	DigiTubeCtr_State_Level[1][5]
#define DigiTubeCtr_B7_State_Level	DigiTubeCtr_State_Level[1][6]
#define DigiTubeCtr_B8_State_Level	DigiTubeCtr_State_Level[1][7]
		
#define DigiTubeCtr_C1_State_Level	DigiTubeCtr_State_Level[2][0]
#define DigiTubeCtr_C2_State_Level	DigiTubeCtr_State_Level[2][1]
#define DigiTubeCtr_C3_State_Level	DigiTubeCtr_State_Level[2][2]
#define DigiTubeCtr_C4_State_Level	DigiTubeCtr_State_Level[2][3]
#define DigiTubeCtr_C5_State_Level	DigiTubeCtr_State_Level[2][4]
#define DigiTubeCtr_C6_State_Level	DigiTubeCtr_State_Level[2][5]
#define DigiTubeCtr_C7_State_Level	DigiTubeCtr_State_Level[2][6]
#define DigiTubeCtr_C8_State_Level	DigiTubeCtr_State_Level[2][7]
		
#define DigiTubeCtr_D1_State_Level	DigiTubeCtr_State_Level[3][0]
#define DigiTubeCtr_D2_State_Level	DigiTubeCtr_State_Level[3][1]
#define DigiTubeCtr_D3_State_Level	DigiTubeCtr_State_Level[3][2]
#define DigiTubeCtr_D4_State_Level	DigiTubeCtr_State_Level[3][3]
#define DigiTubeCtr_D5_State_Level	DigiTubeCtr_State_Level[3][4]
#define DigiTubeCtr_D6_State_Level	DigiTubeCtr_State_Level[3][5]
#define DigiTubeCtr_D7_State_Level	DigiTubeCtr_State_Level[3][6]
#define DigiTubeCtr_D8_State_Level	DigiTubeCtr_State_Level[3][7]
		
#define DigiTubeCtr_E1_State_Level	DigiTubeCtr_State_Level[4][0]
#define DigiTubeCtr_E2_State_Level	DigiTubeCtr_State_Level[4][1]
#define DigiTubeCtr_E3_State_Level	DigiTubeCtr_State_Level[4][2]
#define DigiTubeCtr_E4_State_Level	DigiTubeCtr_State_Level[4][3]
#define DigiTubeCtr_E5_State_Level	DigiTubeCtr_State_Level[4][4]
#define DigiTubeCtr_E6_State_Level	DigiTubeCtr_State_Level[4][5]
#define DigiTubeCtr_E7_State_Level	DigiTubeCtr_State_Level[4][6]
#define DigiTubeCtr_E8_State_Level	DigiTubeCtr_State_Level[4][7]
		
#define DigiTubeCtr_F1_State_Level	DigiTubeCtr_State_Level[5][0]
#define DigiTubeCtr_F2_State_Level	DigiTubeCtr_State_Level[5][1]
#define DigiTubeCtr_F3_State_Level	DigiTubeCtr_State_Level[5][2]
#define DigiTubeCtr_F4_State_Level	DigiTubeCtr_State_Level[5][3]
#define DigiTubeCtr_F5_State_Level	DigiTubeCtr_State_Level[5][4]
#define DigiTubeCtr_F6_State_Level	DigiTubeCtr_State_Level[5][5]
#define DigiTubeCtr_F7_State_Level	DigiTubeCtr_State_Level[5][6]
#define DigiTubeCtr_F8_State_Level	DigiTubeCtr_State_Level[5][7]
		
#define DigiTubeCtr_G1_State_Level	DigiTubeCtr_State_Level[6][0]
#define DigiTubeCtr_G2_State_Level	DigiTubeCtr_State_Level[6][1]
#define DigiTubeCtr_G3_State_Level	DigiTubeCtr_State_Level[6][2]
#define DigiTubeCtr_G4_State_Level	DigiTubeCtr_State_Level[6][3]
#define DigiTubeCtr_G5_State_Level	DigiTubeCtr_State_Level[6][4]
#define DigiTubeCtr_G6_State_Level	DigiTubeCtr_State_Level[6][5]
#define DigiTubeCtr_G7_State_Level	DigiTubeCtr_State_Level[6][6]
#define DigiTubeCtr_G8_State_Level	DigiTubeCtr_State_Level[6][7]
		
#define DigiTubeCtr_H1_State_Level	DigiTubeCtr_State_Level[7][0]
#define DigiTubeCtr_H2_State_Level	DigiTubeCtr_State_Level[7][1]
#define DigiTubeCtr_H3_State_Level	DigiTubeCtr_State_Level[7][2]
#define DigiTubeCtr_H4_State_Level	DigiTubeCtr_State_Level[7][3]
#define DigiTubeCtr_H5_State_Level	DigiTubeCtr_State_Level[7][4]
#define DigiTubeCtr_H6_State_Level	DigiTubeCtr_State_Level[7][5]
#define DigiTubeCtr_H7_State_Level	DigiTubeCtr_State_Level[7][6]
#define DigiTubeCtr_H8_State_Level	DigiTubeCtr_State_Level[7][7]
		
#define DigiTubeCtr_I1_State_Level	DigiTubeCtr_State_Level[8][0]
#define DigiTubeCtr_I2_State_Level	DigiTubeCtr_State_Level[8][1]
#define DigiTubeCtr_I3_State_Level	DigiTubeCtr_State_Level[8][2]
#define DigiTubeCtr_I4_State_Level	DigiTubeCtr_State_Level[8][3]
#define DigiTubeCtr_I5_State_Level	DigiTubeCtr_State_Level[8][4]
#define DigiTubeCtr_I6_State_Level	DigiTubeCtr_State_Level[8][5]
#define DigiTubeCtr_I7_State_Level	DigiTubeCtr_State_Level[8][6]
#define DigiTubeCtr_I8_State_Level	DigiTubeCtr_State_Level[8][7]
		
#define DigiTubeCtr_J1_State_Level	DigiTubeCtr_State_Level[9][0]
#define DigiTubeCtr_J2_State_Level	DigiTubeCtr_State_Level[9][1]
#define DigiTubeCtr_J3_State_Level	DigiTubeCtr_State_Level[9][2]
#define DigiTubeCtr_J4_State_Level	DigiTubeCtr_State_Level[9][3]
#define DigiTubeCtr_J5_State_Level	DigiTubeCtr_State_Level[9][4]
#define DigiTubeCtr_J6_State_Level	DigiTubeCtr_State_Level[9][5]
#define DigiTubeCtr_J7_State_Level	DigiTubeCtr_State_Level[9][6]
#define DigiTubeCtr_J8_State_Level	DigiTubeCtr_State_Level[9][7]
		
#define DigiTubeCtr_K1_State_Level	DigiTubeCtr_State_Level[10][0]
#define DigiTubeCtr_K2_State_Level	DigiTubeCtr_State_Level[10][1]
#define DigiTubeCtr_K3_State_Level	DigiTubeCtr_State_Level[10][2]
#define DigiTubeCtr_K4_State_Level	DigiTubeCtr_State_Level[10][3]
#define DigiTubeCtr_K5_State_Level	DigiTubeCtr_State_Level[10][4]
#define DigiTubeCtr_K6_State_Level	DigiTubeCtr_State_Level[10][5]
#define DigiTubeCtr_K7_State_Level	DigiTubeCtr_State_Level[10][6]
#define DigiTubeCtr_K8_State_Level	DigiTubeCtr_State_Level[10][7]
		
#define DigiTubeCtr_L1_State_Level	DigiTubeCtr_State_Level[11][0]
#define DigiTubeCtr_L2_State_Level	DigiTubeCtr_State_Level[11][1]
#define DigiTubeCtr_L3_State_Level	DigiTubeCtr_State_Level[11][2]
#define DigiTubeCtr_L4_State_Level	DigiTubeCtr_State_Level[11][3]
#define DigiTubeCtr_L5_State_Level	DigiTubeCtr_State_Level[11][4]
#define DigiTubeCtr_L6_State_Level	DigiTubeCtr_State_Level[11][5]
#define DigiTubeCtr_L7_State_Level	DigiTubeCtr_State_Level[11][6]
#define DigiTubeCtr_L8_State_Level	DigiTubeCtr_State_Level[11][7]
		
#define DigiTubeCtr_M1_State_Level	DigiTubeCtr_State_Level[12][0]
#define DigiTubeCtr_M2_State_Level	DigiTubeCtr_State_Level[12][1]
#define DigiTubeCtr_M3_State_Level	DigiTubeCtr_State_Level[12][2]
#define DigiTubeCtr_M4_State_Level	DigiTubeCtr_State_Level[12][3]
#define DigiTubeCtr_M5_State_Level	DigiTubeCtr_State_Level[12][4]
#define DigiTubeCtr_M6_State_Level	DigiTubeCtr_State_Level[12][5]
#define DigiTubeCtr_M7_State_Level	DigiTubeCtr_State_Level[12][6]
#define DigiTubeCtr_M8_State_Level	DigiTubeCtr_State_Level[12][7]

#define DigiTube_Level_State_Off 0
#define DigiTube_Level_State_On 1
#define DigiTube_Level_Total 10

#ifdef __cplusplus
}
#endif

#endif /* PY32F003XX_LL_START_KIT_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/

