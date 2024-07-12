/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BSP_H
#define BSP_H

#ifdef __cplusplus
extern "C" {
#endif


#ifdef  _MAIN_C_
#define ex
#define EX
#else
#define ex extern
#define EX extern
#endif



/* Includes ------------------------------------------------------------------*/
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

//---------------------------
#define u8 unsigned char
#define u16 unsigned int
#define   BatV   LL_ADC_CHANNEL_VREFINT
#define 	Hearting_Res1_DetePin   LL_ADC_CHANNEL_1
#define 	Hearting_Res2_DetePin   LL_ADC_CHANNEL_0
#define 	USB_DetePin   LL_ADC_CHANNEL_7
#define 	NTC_Res_DetePin   LL_ADC_CHANNEL_4
#define 	Mic2_DetePin   LL_ADC_CHANNEL_3



//#define FLASH_USER_START_ADDR     0x08004F80UL//写flash开始地址,0x08007f00 32K flash最后2页

#define FLASH_USER_START_ADDR      (0x08000000+20*1024-128*1)//写flash开始地址,0x08007f00 32K flash最后2页

#define Flash_Data_size 16
 ex volatile uint32_t   FLASHData_buffer[Flash_Data_size];


#define BIT0 (0x1 << 0)
#define BIT1 (0x1 << 1)
#define BIT2 (0x1 << 2)
#define BIT3 (0x1 << 3)
#define BIT4 (0x1 << 4)
#define BIT5 (0x1 << 5)
#define BIT6 (0x1 << 6)
#define BIT7 (0x1 << 7)
#define BIT8 (0x1 << 8)
#define BIT9 (0x1 << 9)


#define BITA (0x1 << 0)
#define BITB (0x1 << 1)
#define BITC (0x1 << 2)
#define BITD (0x1 << 3)
#define BITE (0x1 << 4)
#define BITF (0x1 << 5)
#define BITG (0x1 << 6)
#define BITH (0x1 << 7)


//-------------------------
#define Nch 5    //通道数
#define Mch 4    //次数

ex __IO uint32_t ADCxConvertedDatas[Mch][Nch];//ADC
ex  unsigned int AdValChannelTab[10];



void sys_time_isr_process(void);
void DelayTime_ms(uint32_t MsCount);
void Delay( uint32_t nTime);
void SystemClock_Config(void);
void APP_COMP1Init(void);
void APP_COMP2Init(void);
void APP_EnterStop(void);
void APP_CompRccInit(void);
void APP_ConfigPWMChannel(void);
void APP_ConfigADC_DMA(void);
void APP_AdcEnable(void);
void APP_FlashProgram(void);
void APP_FlashOBProgram(void);
void APP_ConfigureEXTI(void);
void GPIOInit(void);
void APP_ConfigTim1(void);

void Error_Handler(void);
void PWM_updata(unsigned char Duty0,unsigned char Duty1 );
void APP_ConfigADC(void);
unsigned int ADC_GetData(uint32_t ADC_Channel,unsigned char count);
void WWDG_Config(void);
void IWDG_Config(void);
void APP_ConfigLPTIM_OneShot(void);
void APP_LPTIM_OneShot(void);
volatile void delay(uint16_t Num);

///////////////////////////////////////////////////////////////////////////////////////////////////////
ex uint32_t R_PowerOn_LED_Time;
#define C_PowerOn_LED_Time (2*1000/5)
ex uint32_t R_Normal_LED_Time;
ex uint32_t R_Hearting_Normal_End_ShuZhi_Hold_Time;

ex uint8_t R_SleepTime;
#define C_TIME_SLEEP	(40/5)
ex uint8_t D_SleepFlag;

ex uint32_t R_Timer1sCnt;
ex uint8_t 	D_Timer1sFlag;
#define C_TIMER1S			(5*1000*1000/40)

ex uint16_t R_Timer100usCnt;
ex uint8_t 	D_Timer100usFlag;
#define C_TIMER100US			(100/50)


ex uint16_t R_Timer5msCnt;
ex uint8_t 	D_Timer5msFlag;
#define C_TIMER5MS			(5*1000/40)


ex uint16_t R_Timer1msCnt;
ex uint8_t 	D_Timer1msFlag;
#define C_TIMER1MS			(1*1000/40)

ex uint32_t R_Timer10msCnt;
ex uint8_t 	D_Timer10msFlag;
#define C_TIMER10MS			(2*1000/40)

ex uint8_t R_USBDebounce;
#define  C_USBDEBOUNCE (25/5)
ex uint8_t D_USBReg;
ex uint8_t D_USBBuf;
ex uint32_t R_Charge_Bat_Level_Up_Cnt;
ex uint8_t D_USBPress;
ex uint8_t D_USBRelease;
#define USB_IN_check	LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_7)




ex uint32_t R_ChargeFullDebounce;
#define  C_ChargeFullDEBOUNCE (1500/5)
ex uint8_t D_ChargeFullReg;
ex uint8_t D_ChargeFullBuf;
ex uint8_t D_ChargeFullPress;
ex uint8_t D_ChargeFullRelease;
#define Charge_FULL_check	LL_GPIO_IsInputPinSet(GPIOB,LL_GPIO_PIN_8)
ex uint8_t R_Charge_Oled_Flash_Time;
#define C_Charge_Oled_Flash_Time  (250/5)

ex uint32_t R_Charge_Full_LED_Hold_Time;
#define C_Charge_Full_LED_Hold_Time (10*1000/5)


ex uint8_t R_MicDebounce;
ex uint8_t R_Mic2Debounce;
#define  C_MicDEBOUNCE (10/5)
#define  C_Mic2DEBOUNCE (10/5)
ex uint8_t D_MicReg;
ex uint8_t D_Mic2Reg;
ex uint8_t D_MicBuf;
ex uint8_t D_Mic2Buf;
ex uint8_t D_MicPress;
ex uint8_t D_Mic2Press;
ex uint8_t D_MicRelease;
ex uint8_t D_Mic2Release;
#define Mic_IN_check	LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_2)
#define Mic2_IN_check	LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_11)
ex uint8_t R_KeyDebounce;
ex uint8_t R_99Debounce;
ex uint8_t R_Key2Debounce;
ex uint8_t R_Key3Debounce;
ex uint8_t R_Key4Debounce;
#define  C_KeyDEBOUNCE (25/5)
#define  C_99DEBOUNCE (2)
#define  C_Key2DEBOUNCE (25/5)
#define  C_Key3DEBOUNCE (25/5)
#define  C_Key4DEBOUNCE (25/5)
ex uint8_t D_KeyReg;
ex uint8_t D_99Reg;
ex uint8_t D_Key2Reg;
ex uint8_t D_Key3Reg;
ex uint8_t D_Key4Reg;
ex uint8_t D_KeyBuf;
ex uint8_t D_99Buf;
ex uint8_t D_Key2Buf;
ex uint8_t D_Key3Buf;
ex uint8_t D_Key4Buf;
ex uint8_t D_KeyPress;
ex uint8_t D_99Press;
ex uint32_t R_KeyTime_Cnt;
#define C_KeyTime_Cnt	(2*1000/5)
ex uint8_t D_Key2Press;
ex uint8_t D_Key3Press;
ex uint8_t D_Key4Press;
ex uint8_t D_KeyPressA;
ex uint8_t D_KeyRelease;
ex uint8_t D_99Release;
ex uint8_t D_Key2Release;
ex uint8_t D_Key3Release;
ex uint8_t D_Key4Release;
ex uint8_t D_KeyReleaseA;
#define Key_IN_check	LL_GPIO_IsInputPinSet(GPIOB,LL_GPIO_PIN_0)
#define Key2_IN_check	LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_6)
#define Key3_IN_check	LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_11)
#define Key4_IN_check	LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_8)
ex uint8_t R_Key_Temp1;
#define C_Key_Time (250/5)
ex uint8_t R_Key_NUM;
ex uint16_t R_Change_Hearting_Power_Time;
ex uint16_t D_Change_Hearting_Power_Oled_Flash_Flag;
ex uint16_t R_Change_Hearting_Power_Oled_Flash_Time;
#define C_Change_Hearting_Power_Oled_Flash_Time (300/5)
ex uint32_t R_Change_Hearting_Power_Check_Key_Time;
ex uint32_t R_Change_Hearting_Power_Check_Key3_Time;
ex uint32_t R_Change_Hearting_Power_Check_Key4_Time;
ex uint8_t D_Change_Hearting_Power_Check_Key_Time_En_Flag;
ex uint8_t D_Change_Hearting_Power_Check_Key3_Time_En_Flag;
ex uint8_t D_Change_Hearting_Power_Check_Key4_Time_En_Flag;
ex uint8_t D_Change_Hearting_Power_Big_Flag;
ex uint8_t D_Change_Hearting_Power_Small_Flag;
ex uint32_t R_Menu_Check_Key_Time;
#define C_Change_Hearting_Power_Check_Key_Time (250/5)
#define C_Change_Hearting_Power_Check_Key3_Time (150/5)
#define C_Change_Hearting_Power_Check_Key4_Time (150/5)
#define C_Menu_Key_Time (1000/5)
ex uint8_t D_KEY_PowerON_Flag;
ex uint8_t D_Key_PowerOn_LED_Hap;
ex uint8_t D_Key_PowerDown_LED_Hap;
ex uint8_t D_Key_PowerDown_TiShi_LED_Hap;

ex uint8_t R_HuoYan_KaiGuan_Flag;

ex uint8_t D_OLED_Menu_Key_En_Flag;

ex uint8_t BatVol_Proce_Flag;
ex uint8_t BatVol_Proce_Flag2;
ex uint8_t BatVol_Proce_Flag3;

ex volatile uint32_t Vref12_Buf;
ex uint32_t BatVoltage,R_AD_I_Aver,R_Temp_Word_Buf0,R_AD_I_Aver_For_BatVol_SOC_Proce;
ex uint32_t R_AD_I_Aver_For_BatVol_Total;
ex uint8_t R_Bat_SOC;
ex uint8_t R_Bat_SOC_Temp_IN_Oled_Ctrl;
ex uint8_t R_Bat_SOC_FloorLimit;
ex uint8_t R_Bat_SOC_TopLimit;
ex uint8_t R_Bat_Level;
ex uint8_t D_Bat_Level_Fall_Luck_After_Smoke_With_USB;
ex uint8_t R_Bat_Level1;
ex uint8_t R_Bat_Level_TopLimit;
ex uint8_t R_Bat_Level_FloorLimit;
ex uint8_t R_Bat_Level_Before_Hearting;
ex uint8_t R_Bat_Level_Temp;
ex uint8_t R_Bat_Level_Temp1;
ex uint8_t R_Bat_Level_Temp_NanGao;
ex uint8_t R_Bat_Level_Temp_Up_FangDou;
ex uint8_t R_Bat_Level_Temp_Down_FangDou;
ex uint8_t R_Bat_Level_99_Flag;
ex uint8_t R_Bat_Level_99;
ex uint8_t R_Bat_Level_FangDou;
ex uint8_t R_Bat_Level_FangDou1;
ex uint8_t R_Bat_Level_FangDou_CNT;
ex uint8_t R_Bat_Level_FangDou_CNT1;
ex uint8_t R_LowPowr_FangDou_CNT;
#define C_Bat_Level_FangDou_CNT 1
#define C_Bat_Level_FangDou_CNT1 40
#define C_LowPowr_FangDou_CNT 50
ex uint8_t R_Temp_Buf0;
#define C_Bat_Level_Shake_Time	(10*1000/5)
ex uint32_t R_LED_Flash_Time;
ex uint32_t R_LED_Flash_Time1;
ex uint32_t R_HuoYan_Level;
ex uint32_t R_LED_Horse_Addend;
#define C_LowPowr_LED_Flash_Time (250/5);
ex uint32_t R_LowPowr_LED_Flash_Num;
ex uint32_t R_USB_Out_LED_Flash_Num;
ex uint8_t D_LowPowr_LED_Hap;
ex uint8_t D_USB_In_LED_Hap;
ex uint8_t D_USB_Out_LED_Hap;
ex uint8_t D_LowPowr_Reg;
#define C_LowPowr_LED_Flash_Num 21;
#define C_USB_Out_LED_Flash_Num 7;
#define C_USB_Out_LED_Flash_Time (250/5)

#define C_BatVol_99_AD		4320	//
#define C_BatVol_99_94_AD_Percent	6
#define C_BatVol_94_AD		4290	//
#define C_BatVol_94_80_AD_Percent	10
#define C_BatVol_80_AD		4150	//
#define C_BatVol_80_70_AD_Percent	7
#define C_BatVol_70_AD		4080	//
#define C_BatVol_70_60_AD_Percent	8
#define C_BatVol_60_AD		4000	//
#define C_BatVol_60_50_AD_Percent	7
#define C_BatVol_50_AD		3930	//
#define C_BatVol_50_40_AD_Percent	8
#define C_BatVol_40_AD		3850	//
#define C_BatVol_40_30_AD_Percent	7
#define C_BatVol_30_AD		3780	//
#define C_BatVol_30_20_AD_Percent	8
#define C_BatVol_20_AD		3700	//
#define C_BatVol_20_0_AD_Percent	20
#define C_BatVol_0_AD			3300	//



//#define C_BatVol_Level_1			3300	
//#define C_BatVol_Level_2			3600
//#define C_BatVol_Level_3			3680
//#define C_BatVol_Level_4			3720
//#define C_BatVol_Level_5			3760
//#define C_BatVol_Level_6			3800
//#define C_BatVol_Level_7			3850
//#define C_BatVol_Level_8			3900

//#define C_BatVol_Level_88			4000
//#define C_BatVol_Level_99			4050

#define C_BatVol_Level_1			3300	
#define C_BatVol_Level_2			3600
#define C_BatVol_Level_3			3655
#define C_BatVol_Level_4			3700
#define C_BatVol_Level_5			3745
#define C_BatVol_Level_6			3790
#define C_BatVol_Level_7			3850
#define C_BatVol_Level_8			3900

#define C_BatVol_Level_88			4000
#define C_BatVol_Level_99			4050

//#define C_BatVol_Level_1			3300	
//#define C_BatVol_Level_2			3600
//#define C_BatVol_Level_3			3685
//#define C_BatVol_Level_4			3740
//#define C_BatVol_Level_5			3790
//#define C_BatVol_Level_6			3840
//#define C_BatVol_Level_7			3890
//#define C_BatVol_Level_8			3940

//#define C_BatVol_Level_88			4000
//#define C_BatVol_Level_99			4050

ex uint8_t D_Have_A_GoodJob_Flag;
ex uint32_t R_Hearting_Time;
ex uint32_t R_Hearting_Time_Temp;
ex uint32_t R_Hearting_Time_Temp_Temp;
ex uint32_t R_Hearting_Time_Total;
ex uint32_t R_YouLiangSuoJianSQ;
ex uint32_t R_YouLiangSuoJianSQ2;
#define C_Hearting_Time_Total (3300*1000/5)
ex uint32_t R_WaWaWaAi;
ex uint32_t R_Hearting_NUM;
ex uint32_t R_Zdscnmd_Gl;
ex uint32_t R_Zdscnmd_Gl_BeiFeng;
ex uint32_t R_Zdscnmd_Gl_Da;
ex uint32_t R_Zdscnmd_Gl_Xiao;
ex uint32_t R_Hearting_Res_Level_Before;
ex uint32_t R_Hearting_Res_Value;
ex uint32_t R_Hearting_Res_Value_BeiFeng;
ex uint32_t R_Hearting_Res_Level;
ex uint32_t R_Hearting_LED_Model;
ex uint32_t R_Charge_LED_Model;
ex uint32_t R_Working_Model;
ex uint32_t R_First_Flash;
ex uint32_t R_Hearting_NUM_Temp;
ex uint32_t R_Hearting_NUM_Temp1;
ex uint32_t R_Hearting_NUM_Temp2;
ex uint32_t R_Hearting_NUM_Temp3;
#define C_Hearting_Time		(99*100/5)
#define C_Hearting_Once_Time		(500/5)
ex uint8_t D_Hearting_Time_Over_LED_Hap;
ex uint32_t R_Hearting_Time_Over_LED_Time;
ex uint32_t R_Hearting_Time_Over_LED_Flash_Num;
#define C_Hearting_Time_Over_LED_Time (1000/5)
#define C_Hearting_Time_Over_LED_Flash_Num 5
#define C_Hearting_Time_Over_LED_Flash_Time (250/5);
//#define Smoke_Res_Hearting				LL_GPIO_ResetOutputPin(GPIOF, LL_GPIO_PIN_1)
#define Smoke_Res1_Hearting				LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4)
#define Smoke_Res2_Hearting				LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5)
#define Smoke_Res_DoNotHearting		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4);LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
#define Charge_Enbale		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1)
#define Charge_Disbale		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_1)

ex uint8_t D_Smoke_Res_Hearting_Flag;
ex uint8_t D_Hearting_Flag;
ex uint8_t D_Hearting_LED_Hap;
ex uint8_t D_Hearting_END_LED_Hap;
ex uint8_t D_Lock_Key_LED_Hap;
ex uint8_t R_Lock_Key_LED_Flash_Num;
#define C_Lock_Key_LED_Flash_Num 7
ex uint8_t D_Charge_LED_Hap;
ex uint8_t D_Charge_LED_Flash_State;
#define C_Charge_LED_Flash_Time (250/5)
ex uint8_t D_Charge_Full_LED_Hap;
ex uint8_t D_Smoke_Res_OUT_LED_Hap;
ex uint8_t D_Smoke_Res_OUT_Oled_Work;
ex uint8_t D_Hearting_Time_Over_Oled_Work;
#define C_Smoke_Res_OUT_LED_Flash_Time (250/5);
ex uint16_t R_Smoke_Res_OUT_LED_Flash_Num;
ex uint16_t R_Smoke_Res_OUT_Oled_Time;
ex uint16_t R_Hearting_Time_Over_Oled_Time;
#define C_Hearting_Time_Over_Oled_Time (1600/5)
#define C_Smoke_Res_OUT_LED_Flash_Num 7
#define C_Smoke_Res_OUT_Oled_Time (1600/5)
ex uint8_t D_Smoke_Res_Short_LED_Hap;
ex uint8_t D_Smoke_Res_Short_Oled_Work;
ex uint16_t R_Smoke_Res_Short_Oled_Time;
#define C_Smoke_Res_Short_LED_Flash_Time (250/5);
ex uint16_t R_Smoke_Res_Short_LED_Flash_Num;
#define C_Smoke_Res_Short_LED_Flash_Num 11
#define C_Smoke_Res_Short_Oled_Time (1600/5)
ex uint8_t R_Hearting_From;
#define C_Hearting_From_Mic 1
#define C_Hearting_From_Key 2
#define C_Hearting_From_Mic_And_KEY 3
ex uint32_t R_Smoke_Res_Hearting_PWM_ON;
ex uint32_t R_Smoke_Res_Hearting_PWM_OFF;
ex uint32_t R_ZuoHuFa;
ex uint32_t R_YouHuFa;
ex uint32_t R_Hearting_Res_Vol;
ex uint32_t R_Smoke_Res_Hearting_PWM_CNT;
ex uint32_t R_LED_RGB_PWM_CNT;
ex uint32_t R_Hearting_LED_PWM_CNT;
ex uint32_t R_Hearting_LED_PWM_ON;
ex uint32_t R_Hearting_END_LED_PWM_ON;
ex uint8_t D_LED_RGB_PWM_Temp;
#define C_LED_RGB_PWM_Total 240
#define C_Hearting_LED_PWM_Total 30
#define C_Hearting_LED_Delay (20*1000/20)
ex uint8_t R_Hearting_LED_Total;
#define C_Hearting_LED_Total 8
#define C_Hearting_LED_Coulour_Total	7
ex uint8_t R_LED_ChangePwm_Time;
#define C_Hearting_LED_ChangePwm_Time (15/5)
ex uint16_t R_Hearting_END_LED_Flash_Time;
#define C_Hearting_END_LED_Flash_Time (250/5)
ex uint8_t R_Hearting_END_LED_Flash_Colour;
#define C_Hearting_END_LED_Flash_Colour_Total 6
ex uint16_t R_Hearting_Time_Count;
//#define C_Hearting_Time_Total 600000;
//#define C_Hearting_Time_Percent_5 30000//(3000*1000*5/100/5)
//#define C_Hearting_Time_Percent_20 120000//(3000*1000*20/100/5)
//#define C_Hearting_Time_Percent_40 240000//(3000*1000*40/100/5)
#define C_Hearting_Time_Percent_5 3000//(3000*1000*5/100/5)
#define C_Hearting_Time_Percent_20 12000//(3000*1000*20/100/5)
#define C_Hearting_Time_Percent_40 24000//(3000*1000*40/100/5)
ex uint16_t R_Hearting_Res_DetePin_AD_Value;
ex uint8_t D_Hearting_Res_GoTo_BJ_Flag;
ex uint16_t R_USB_DetePin_AD_Value;
ex uint8_t D_USB_State;
ex uint8_t D_ChargeFull_State;
ex uint32_t R_jiujiuwoba;
ex uint32_t R_jiujiuwoba1;
ex uint32_t R_jiujiuwoba2;


ex uint8_t R_Hearting_END_LED_ChangePwm_Time;
#define C_Hearting_END_LED_ChangePwm_Time (15/5)
#define C_Hearting_END_LED_PWM_Total 30
ex uint8_t R_Hearting_END_LED_PWM_CNT;
#define C_Hearting_END_LED_Total 8
ex uint8_t R_Hearting_END_LED_Flag1;
ex uint8_t R_Hearting_END_LED_Flag2;
ex uint8_t R_Hearting_END_LED_Flag3;
ex uint8_t R_Hearting_END_LED_Flag4;

ex uint8_t D_LowPower_Oled_Work;
ex uint32_t R_LowPower_Oled_Time;
#define C_LowPower_Oled_Time (5*1000/5+(100/5))


ex uint8_t D_HighTemperature_Oled_Work;
ex uint32_t R_HighTemperature_Oled_Time;
#define C_HighTemperature_Oled_Time (5*1000/5)



ex uint8_t D_LED_Working_Flag;
ex uint8_t D_OLED_Working_Flag;

ex uint32_t R_LED_Rand_Colour;
ex uint32_t R_LED_Rand_Colour_Old;

ex uint32_t R_LED_Colour;
ex uint32_t R_Hearting_LED_Colour_Max;
#define C_Hearting_LED_Flash_Time (200/5)
#define C_Hearting_LED_Flash_Time1 (200/5)
ex uint8_t R_Smoke_Res_Short_Dete_Time;
ex uint8_t R_Smoke_Res_Short_Dete_Flag;
#define C_Smoke_Res_Short_Dete_Time 2

ex uint32_t R_LED_R_PWM_ON;
ex uint32_t R_LED_G_PWM_ON;
ex uint32_t R_LED_B_PWM_ON;


//ex uint8_t R_SSSSS;
//ex uint8_t R_BBBBB;


#define LED_R_ON_LOW		LL_GPIO_ResetOutputPin(GPIOF, LL_GPIO_PIN_2)
#define LED_R_OFF_HIGH		LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_2)
#define LED_G_ON_LOW		LL_GPIO_ResetOutputPin(GPIOF, LL_GPIO_PIN_3)
#define LED_G_OFF_HIGH		LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_3)
#define LED_B_ON_LOW		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0)
#define LED_B_OFF_HIGH		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0)

#define LED1_ON_HIGH		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_2)
#define LED1_OFF_LOW		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_2)
#define LED2_ON_HIGH		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_10)
#define LED2_OFF_LOW		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10)
#define LED3_ON_HIGH		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_15)
#define LED3_OFF_LOW		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_15)


ex uint8_t R_Hearting_Res_Level_FangDou;
ex uint8_t R_Hearting_Res_Zdcnm;
ex int32_t R_Hearting_Res_Level_1R1_3R;
ex int32_t R_Hearting_Res_Level_0R_0R5;
#define  C_Hearting_Res_Level_Short				1//
#define  C_Hearting_Res_Level_0R3_0R49		2//0.4
#define  C_Hearting_Res_Level_0R5_0R72		3//0.6
#define  C_Hearting_Res_Level_0R73_0R92		4//0.8
#define  C_Hearting_Res_Level_0R93_1R12		5//1
#define  C_Hearting_Res_Level_1R13_3R			6//1.2
#define  C_Hearting_Res_Level_LikeOut			7//
#define  C_Hearting_Res_Level_Out					0//
#define Res_Det_Pin_ON_LOW		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8)
#define Res_Det_Pin_OFF_HIGH		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_8)
#define Music_Det_Enable		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_15)
#define Music_Det_Disable		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_15)
#define Music_Det_Disable_Real		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_15)
ex uint8_t D_Hearting_Res_Level_Det_En;
ex uint32_t R_Hearting_Res_Level_Det_Delay;
ex uint32_t R_Bat_Level_Det_Delay;
#define C_Hearting_Res_Level_Det_Delay (50/5)
#define C_Bat_Level_Det_Delay (1000/5)
ex uint32_t abcdefgh;
ex uint8_t R_USB_LED_PWM_CNT;
ex uint8_t R_USB_LED_PWM_ON;
ex uint8_t R_USB_LED_PWM_CNT;
ex uint8_t R_USB_LED_Delay_Time;
#define C_USB_LED_Delay_Time (50/5)
#define C_USB_LED_PWM_Total 30
ex uint8_t R_USB_LED_ChangePwm_Time;
#define C_USB_LED_ChangePwm_Time (20/5)
ex uint8_t D_USB_LED_PWM_CNT_Flag;
ex uint8_t R_USB_LED_OFF_NUM;
ex uint32_t R_Load_In_LED_Time;
ex uint8_t R_Load_OUT_LED_NUM;
#define C_Load_In_LED_Time (600/5)
#define C_Load_OUT_LED_NUM 5
#define C_Load_In_LED_Flash_Time (250/5)
#define C_Load_OUT_LED_Flash_Time (250/5)


ex uint8_t D_Refresh_OLED_En;
ex uint8_t D_Charge_Main_OLED_Flag;
ex uint32_t R_Key_PowerDown_OLED_Time;
ex uint32_t R_Lock_Key_OLED_Time;
ex uint32_t R_ULock_Key_OLED_Time;
ex uint32_t R_Bat_SOC_OLED_Time;
#define C_Bat_SOC_OLED_Time (3000/5)
ex uint8_t D_ULock_Key_Oled_Work;
ex uint8_t D_Lock_Key_Oled_Work;
ex uint8_t D_Bat_SOC_Oled_Work;
ex uint32_t R_Key_PowerOn_OLED_Time1;
ex uint8_t D_OLED_ON_OFF_Flag;
ex uint32_t R_PowerOn_OLED_Time;
ex uint32_t R_OLED_Home_Page_Time;
ex uint8_t D_OLED_Menu_Page_Flag;
ex uint8_t R_OLED_Menu_Page_Select;
ex uint32_t R_OLED_LowPower_Time;
ex uint32_t R_OLED_Short_Time;
ex uint8_t R_Charge_Oled_BatLevel_Seq;
ex uint8_t R_Charge_Led_BatLevel_Seq;
ex uint32_t R_OLED_OUT_Time;
ex uint32_t R_OLED_Over_Time;
ex uint32_t R_Zdscnmd_Gl_Temp;
ex uint32_t R_Zdscnmd_Gl_Temp1;
ex uint32_t R_Zdscnmd_Gl_Temp2;
ex uint32_t plygcj1;
ex uint32_t plygcj2;

ex uint32_t R_LED_Working_Model_Hearting_Delay;
#define C_LED_Working_Model_Hearting_Delay (50/5)
ex uint32_t D_Lock_Key_Flag;
ex uint32_t R_ChargeFull_Oled_Hold_Time;
#define C_ChargeFull_Oled_Hold_Time (1*60*1000/5)
ex uint8_t D_ChargeFull_Oled_Hold_Over_Flag;
ex uint16_t R_NTC_Res_DetePin_AD_Value;
ex uint8_t D_HighTemperature_Reg;
ex uint8_t D_HighTemperature_LED_Hap;
ex uint32_t R_Hearting_Res_Value_Dete_Time;
ex uint32_t R_Hearting_Res_Value_Dete_Delay;
#define C_Hearting_Res_Value_Dete_Time (500/5)
ex uint8_t D_ADWork_State__8888;
ex uint8_t D_HuanXing_From_Res;


#define C_Working_Model_Auto 0
#define C_Working_Model_Diy	 1

ex uint8_t D_KKKKKKKKK;

ex uint32_t R_Dance_Time;
ex uint32_t R_Dance_Dete_Delay;
ex uint8_t R_Dance_Time_First_Dete_Flag;
ex uint32_t R_Dance_LED_Time;
ex uint8_t D_Sleep_Again_Flag;

#define C_Dance_Time (10*1000*1000/40)
#define C_Dance_Time1 (2*60*1000*1000/40)
#define C_Dance_LED_Time (1*1000/5)
#define C_Dance_Dete_Delay (15*100*1000/40)

ex uint8_t R_Temp;

#define C_Hearting_LED_Model_HX 	1
#define C_Hearting_LED_Model_QC 	2
#define C_Hearting_LED_Model_CL 	3
#define C_Hearting_LED_Model_Off 	4
//#define C_Hearting_LED_Model_PM 	5


#define C_Charge_LED_Model_HX 	1
#define C_Charge_LED_Model_Off 	0

ex uint8_t R_YouLiang_Level;
ex uint8_t R_DianLiang_Level;
ex uint8_t R_GongLv_GeWei;
ex uint8_t R_GongLv_ShiWei;
ex uint8_t R_GongLv_Level;
ex uint8_t R_Hearting_Time_GeWei;
ex uint8_t R_Hearting_Time_ShiWei;
ex uint8_t R_KaiGuanJi_State;

ex uint8_t R_Smoke_Res_Model;
ex uint8_t R_Smoke_Res_Model_BeiFeng;

ex uint8_t R_Smoke_Res_Choice;
ex uint8_t R_Smoke_Res_Choice_Cnt;
#define C_Smoke_Res_Choice_1 0
#define C_Smoke_Res_Choice_2 1
#define C_Smoke_Res_Model_Single 0
#define C_Smoke_Res_Model_double 1

ex uint32_t D_Key_PowerDown_LED_Time_Cnt;
ex uint32_t D_Key_PowerDown_TiShi_LED_Time;
#define C_Key_PowerDown_TiShi_LED_Time (2*1000/5)

ex uint32_t D_Key_PowerOn_LED_Time_Cnt;
ex uint32_t R_USB_Out_DoNot_Det_Bat_Time;
#define C_USB_Out_DoNot_Det_Bal_Time (44*1000/5)

ex uint32_t R_Mic2_AD_Cnt;
ex uint32_t R_Mic2_AD;
ex uint32_t R_Mic2_AD_Temp;
ex uint32_t R_Mic2_LL_Temp;
ex uint32_t R_Mic2_LL;
ex uint32_t R_AD_I_Aver_For_TiaoWu;

void Led_Ctrl(void);
void ChargeDete(void);
void CheckSleep(void);
void MicDete(void);
void Mic2Dete(void);
void BatVol_SOC_Proce(void);
void BatVol_SOC_Proce1(void);
void Hearting_Ctrl(void);
void Hearting_Res_OUT_Short_Dete(void);
void read_Hearting_Res_DetePin_Vol(void);
void OLED_Ctrl(void);
void KeyDete(void);
void Key2Dete(void);
void Key3Dete(void);
void Key4Dete(void);
void Hearting_Working(void);
void APP_FlashErase(void);
void APP_FlashProgram(void);
void APP_FlashWrite(void); 
void APP_Flash_GetDate(void);
void NTC_Res_Dete(void);
void Hearting_Res_Dete(void);
void Set_OLED_Home_Page_Time(void);
void Clear_Oled_Old_Happen(void);
void Clear_LED_Old_Happen(void);
void Clear_LED_Old_Happen_WithOut_Charge_LED_Hap(void);
void Safe_Stop_Hearting(void);
void LED_parameter_Reset(void);
void LED_R_ALL_On(void);
void LED_G_ALL_On(void);
void LED_B_ALL_On(void);
void LED_W_ALL_On(void);
void LED_ALL_Off(void);
void LED_RGB_PWM_SET(void);
void Hearting_LED_Ctrl(void);
void Charge_LED_Ctrl(void);
void Charge_LED_HX_Colour(void);
void R_LED_Colour_JIaJIa(void);
void R_Bat_Level_Temp1_Process(void);
void R_LED_Colour_Process(void);
void R_LED_RGB_PWM_CNT_AND_RGB_Ctrl(void);
void LED_En_ALL_On(void);
void JIUMINGDAOCAO(uint32_t JiuMingA,uint32_t JiuMingB);
void read_Batvol(void);
void read_Batvol0(void);
void LL_Init100usTick(uint32_t HCLKFrequency);
void init_devices(void);


#ifdef __cplusplus
}
#endif

#endif /* PY32F003XX_LL_START_KIT_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/




