/**
  ******************************************************************************
  * @file    main.c
  * @author  MCU Application Team
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#define _MAIN_C_
#include <stdlib.h>
#include "main.h"
#include "bsp.h"
#include "DigiTube.h"
#include "py32c616xx_ll_Start_Kit.h"

/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

int main(void)
{
	Delay(2000000);	

	init_devices();

//----更改BOOT配置字，正常程序不用-----
	APP_FlashOBProgram();
//----------------------

	R_SleepTime = C_TIME_SLEEP;
	R_PowerOn_LED_Time = C_PowerOn_LED_Time;
	R_Normal_LED_Time = 3*1000/5;
	D_KEY_PowerON_Flag = 1;	
	R_KaiGuanJi_State = 1;
	R_HuoYan_KaiGuan_Flag = 1;
	R_Smoke_Res_Choice = C_Smoke_Res_Choice_1;
	R_Zdscnmd_Gl = 150;
	R_Zdscnmd_Gl_Da = 400;
	R_Zdscnmd_Gl_Xiao = 100;
	if(R_Zdscnmd_Gl<=150)
	{
		R_Smoke_Res_Model = C_Smoke_Res_Model_Single;
		R_Hearting_Res_Value = 80;
	}
	else
	{
		R_Smoke_Res_Model = C_Smoke_Res_Model_double;
		R_Hearting_Res_Value = 40;
	}
	R_GongLv_Level = ((R_Zdscnmd_Gl-100)/25+1);
	R_GongLv_GeWei = (R_Zdscnmd_Gl%100)/10;
	R_GongLv_ShiWei = R_Zdscnmd_Gl/100;
	R_Hearting_Time_Total = C_Hearting_Time_Total;
	
	R_Hearting_Time_Total = (1500*1000/5);
	if(R_Hearting_Time_Total>=(300*1000/5))
	{
		R_YouLiang_Level = ((R_Hearting_Time_Total-(300*1000/5))/(300*1000/5))+1;
		if(R_YouLiang_Level==11)
			R_YouLiang_Level = 10;
	}
	else
		R_YouLiang_Level = 0;
	R_Hearting_Time_GeWei = 0;
	R_Hearting_Time_ShiWei = 0;
	R_Bat_Level = 8;
	R_Bat_Level_TopLimit = R_Bat_Level;
	R_Bat_Level_FloorLimit = R_Bat_Level;
	R_DianLiang_Level = R_Bat_Level;

	BatVol_Proce_Flag = 1;
	BatVol_Proce_Flag2 = 1;
	BatVol_SOC_Proce(); //ok
	R_Bat_Level_Temp_Down_FangDou = 8;

	Charge_Enbale;
	Music_Det_Enable;	
	
	DigiTubeCtr_Level_State_All_On();	

  while (1)
  {
		LL_IWDG_ReloadCounter(IWDG); /*喂狗*/


		if(D_Timer5msFlag)
		{
			D_Timer5msFlag = 0;
			
			if(R_USB_Out_DoNot_Det_Bat_Time||R_Bat_Level_Det_Delay)
			{
				if(R_USB_Out_DoNot_Det_Bat_Time)
					R_USB_Out_DoNot_Det_Bat_Time--;

				if(R_Bat_Level_Det_Delay)
					R_Bat_Level_Det_Delay--;
			}
			else
				BatVol_SOC_Proce(); //ok

			if(D_USBBuf)
			{
				if(R_Charge_Bat_Level_Up_Cnt<(5*60*1000/5))
					R_Charge_Bat_Level_Up_Cnt++;
				if(D_Hearting_Flag)
				{
					if(R_Charge_Bat_Level_Up_Cnt>=20)
						R_Charge_Bat_Level_Up_Cnt -= 20;
					else
						R_Charge_Bat_Level_Up_Cnt = 0;

				}
			}
			else
			{
				if(R_Charge_Bat_Level_Up_Cnt)
					R_Charge_Bat_Level_Up_Cnt--;
				else if(D_LED_Working_Flag&&!D_Hearting_Flag)
				{
					if(R_Hearting_Time_Temp_Temp<(78*1000/5))
						R_Hearting_Time_Temp_Temp++;
					if(R_Hearting_Time_Temp_Temp>=(78*1000/5))
					{
						R_Hearting_Time_Temp_Temp = 0;
						if(R_Bat_Level_Temp_Down_FangDou<10)
							R_Bat_Level_Temp_Down_FangDou++;
					}
				}
			}

			BatVol_SOC_Proce1(); //ok
			
			if(!R_PowerOn_LED_Time&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
			{
				KeyDete();//ok


				Key2Dete();//ok			
			}

			if(!D_Hearting_Flag&&!R_PowerOn_LED_Time&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
			{
				Key3Dete();//ok
				Key4Dete();//ok
			}
			else
			{
				D_Change_Hearting_Power_Check_Key3_Time_En_Flag = 0;
				R_Change_Hearting_Power_Check_Key3_Time = 0;

				D_Change_Hearting_Power_Check_Key4_Time_En_Flag = 0;
				R_Change_Hearting_Power_Check_Key4_Time = 0;
			}			
			
			if(!R_PowerOn_LED_Time&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
			{ 	
				MicDete();//ok				
			}
	
			if(!R_PowerOn_LED_Time && D_KEY_PowerON_Flag&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
			{
	//			NTC_Res_Dete();
				
				Hearting_Ctrl();//ok
	
//				Hearting_Res_OUT_Short_Dete();//after
							
			}
			else
			{
				D_MicPress = 0;
				D_Key2Press = 0;
			}

		if(R_Hearting_Normal_End_ShuZhi_Hold_Time)
			R_Hearting_Normal_End_ShuZhi_Hold_Time --;	
			
			Led_Ctrl();
	
						
			ChargeDete();
			
			CheckSleep();
	
		}

  }
}

void LL_Init100usTick(uint32_t HCLKFrequency)
{
	/* Use frequency provided in argument */
	LL_InitTick(HCLKFrequency, 25000U);//40us
} 
void init_devices(void)
{

	  /* 配置系统时钟 */
	  SystemClock_Config();
	  GPIOInit();//
	  __enable_irq();
	//  __disable_irq();


	  /* 初始化调试串口(printf使用) */
//		BSP_USART_Config();
	//
	//	/* 比较器时钟切换 */
	//	APP_CompRccInit();

	//	/* 比较器初始化 */
//		 APP_COMP1Init();
//		 APP_COMP2Init();
//		APP_PvdConfig();
	//	/* ADC初始化 */
//	__disable_irq();
//	APP_ConfigADC_DMA();
//	__enable_irq();
		APP_ConfigADC();
		//APP_ConfigEXTI();
//		APP_ConfigTim1();

	  //  /* PWM输出 */
//	APP_ConfigPWMChannel();

		IWDG_Config();
		APP_ConfigLPTIM_OneShot();



}

void sys_time_isr_process(void)//40us
{


//	Charge_LED_Ctrl();	



//	R_Timer100usCnt++;
//	if(R_Timer100usCnt == C_TIMER100US)
//	{
		
//		R_Timer100usCnt = 0;
//		D_Timer100usFlag = 1;
		if(D_KEY_PowerON_Flag)
		{		
			Hearting_Working();
		}

						
//	}


	R_Timer5msCnt++;
	if(R_Timer5msCnt == C_TIMER5MS)
	{
		R_Timer5msCnt = 0;
		D_Timer5msFlag = 1;
	}

	R_Timer1sCnt++;
	if(R_Timer1sCnt == C_TIMER1S)
	{
		R_Timer1sCnt = 0;
		D_Timer1sFlag = 1;
	}

	R_Timer1msCnt++;
	if(R_Timer1msCnt == C_TIMER1MS)
	{
		R_Timer1msCnt = 0;
		D_Timer1msFlag = 1;
	}

	R_Timer10msCnt++;
	if(R_Timer10msCnt == C_TIMER10MS)
	{
		R_Timer10msCnt = 0;
		D_Timer10msFlag = 1;
		
		DigiTubeCtr_Seq();
		DigiTubeCtr_Play();

	}


	if(R_Dance_Time)
	{
		R_Dance_Time--;
		if(R_Dance_Dete_Delay==0)
			Mic2Dete();
		else
			R_Dance_Dete_Delay--;
			
	}





}

void read_Batvol(void)
{
	static uint32_t Machine_VREF_1p2_Val;

	Vref12_Buf=(READ_REG(*((uint32_t *)(UID_BASE + 0x20U)))) ;
	//未校准读取1.2V及电池电压值如下
	//0x1204EDFB->3.817-3.826
	//0x1202EDFD->3.811-3.817
	//0x1203EDFC->3.814-3.820
	//0x1203EDFC->3.823-3.826
	//0x1204EDFB->3.808-3.814
	//0x1204EDFB->3.817-3.823
	//0x1196EE69->3.844-3.850=》3.825-3.834(校准)
	//0x1201EDFE->3.817-3.823
	Machine_VREF_1p2_Val=((Vref12_Buf>>28)*1000)+(((Vref12_Buf>>24)&0x0f)*100)+(((Vref12_Buf>>20)&0x0f)*10)+((Vref12_Buf>>16)&0x0f);
	if((Machine_VREF_1p2_Val>1250)||(Machine_VREF_1p2_Val<1150))
	{
		Machine_VREF_1p2_Val=1200;
	}
	BatVoltage=ADC_GetData(BatV,2);
	BatVoltage=4096*Machine_VREF_1p2_Val/BatVoltage;
	R_AD_I_Aver=BatVoltage+30;

}
void read_Batvol0(void)
{
	static uint32_t Machine_VREF_1p2_Val;

	Vref12_Buf=(READ_REG(*((uint32_t *)(UID_BASE + 0x20U)))) ;
	//未校准读取1.2V及电池电压值如下
	//0x1204EDFB->3.817-3.826
	//0x1202EDFD->3.811-3.817
	//0x1203EDFC->3.814-3.820
	//0x1203EDFC->3.823-3.826
	//0x1204EDFB->3.808-3.814
	//0x1204EDFB->3.817-3.823
	//0x1196EE69->3.844-3.850=》3.825-3.834(校准)
	//0x1201EDFE->3.817-3.823
	Machine_VREF_1p2_Val=((Vref12_Buf>>28)*1000)+(((Vref12_Buf>>24)&0x0f)*100)+(((Vref12_Buf>>20)&0x0f)*10)+((Vref12_Buf>>16)&0x0f);
	if((Machine_VREF_1p2_Val>1250)||(Machine_VREF_1p2_Val<1150))
	{
		Machine_VREF_1p2_Val=1200;
	}
	BatVoltage=ADC_GetData(BatV,200);
	BatVoltage=4096*Machine_VREF_1p2_Val/BatVoltage;
	R_AD_I_Aver=BatVoltage+30;

}

void KeyDete(void)
{


	if(R_KeyDebounce)
		R_KeyDebounce--;

	if(Key_IN_check == 0)
	{
		if(D_KeyReg == 0)
		{
			D_KeyReg = 1;
			R_KeyDebounce = C_KeyDEBOUNCE;
		}
	}
	else
	{
		if(D_KeyReg)
		{
			D_KeyReg = 0;
			R_KeyDebounce = C_KeyDEBOUNCE;
		}
	}
	if(R_KeyDebounce == 0)
	{
		if(D_KeyReg)
		{
			if(D_KeyBuf == 0)
			{
				D_KeyBuf = 1;
				D_KeyPress = 1;
				D_KeyPressA = 1;

				if(!D_KEY_PowerON_Flag&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
				{
					Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
					D_Key_PowerDown_TiShi_LED_Hap = 1;
					D_Key_PowerDown_TiShi_LED_Time = C_Key_PowerDown_TiShi_LED_Time;
					LED_parameter_Reset();
				}

			}
		}
		else
		{
			if(D_KeyBuf)
			{
				D_KeyBuf = 0;
				D_KeyRelease = 1;
				D_KeyReleaseA = 1;
			}
		}
	}

/////////////////////////////////////////////////////////
	if(D_KeyPressA)
	{
		D_KeyPressA = 0;

		if(R_Key_Temp1)
		{
			R_Key_NUM++;
			R_Key_Temp1 = C_Key_Time;
		}
		else
		{
			R_Key_NUM = 1;
			R_Key_Temp1 = C_Key_Time;
		}
	
	}
	if(D_KeyReleaseA)
	{
		D_KeyReleaseA = 0;

		if(R_Key_Temp1)
		{
			R_Key_NUM++;
			R_Key_Temp1 = C_Key_Time;
		}
	
	}

	if(R_Key_Temp1)
	{
		R_Key_Temp1--;
	}


/////////////////////////////////////////////////////////
	if(R_Key_Temp1==0)
	{
		if(R_Key_NUM==9||R_Key_NUM==10)
		{
			R_Key_NUM = 0;

			if(D_KEY_PowerON_Flag)
			{
				D_KEY_PowerON_Flag = 0;
				R_KaiGuanJi_State = 0;

				Safe_Stop_Hearting();
				
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Key_PowerDown_LED_Hap = 1;
				D_Key_PowerDown_LED_Time_Cnt = 0;
				LED_parameter_Reset();


				R_Dance_Time = 0;
				Music_Det_Disable;
				R_Dance_LED_Time = 0;

			}
			else
			{
				D_KEY_PowerON_Flag = 1;
				R_KaiGuanJi_State = 1;

				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Key_PowerOn_LED_Hap = 1;
				D_Key_PowerOn_LED_Time_Cnt = 0;
				DigiTubeCtr_Level_State_All_Off();
				LED_parameter_Reset();		


			}

		}
		else if(R_Key_NUM==1||R_Key_NUM==2)
		{
			R_Key_NUM = 0;

			if(D_KEY_PowerON_Flag)
			{
				if(R_HuoYan_KaiGuan_Flag)
				{
					R_HuoYan_KaiGuan_Flag = 0;
					R_Dance_Time = 0;
					Music_Det_Disable;
					R_Dance_LED_Time = 0;

				}
				else
					R_HuoYan_KaiGuan_Flag = 1;

				if(!D_Hearting_Flag)
				{
					Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
					R_Normal_LED_Time = 3*1000/5;
		//			LED_parameter_Reset();					

					if(D_USBBuf&&!D_ChargeFullBuf)
					{
		//				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
		//				D_Charge_LED_Flash_State = 99;
		//				LED_parameter_Reset();

					}
				}
			}
		}
	}
////////////////////////////////////////////////////////////////
}
void Key2Dete(void)
{

	if(R_Key2Debounce)
		R_Key2Debounce--;

	if(Key2_IN_check == 0)
	{
		if(D_Key2Reg == 0)
		{
			D_Key2Reg = 1;
			R_Key2Debounce = C_Key2DEBOUNCE;
		}
	}
	else
	{
		if(D_Key2Reg)
		{
			D_Key2Reg = 0;
			R_Key2Debounce = C_Key2DEBOUNCE;
		}
	}
	if(R_Key2Debounce == 0)
	{
		if(D_Key2Reg)
		{
			if(D_Key2Buf == 0)
			{
				D_Key2Buf = 1;
				D_Key2Press = 1;		

				if(!D_KEY_PowerON_Flag&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
				{
					Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
					D_Key_PowerDown_TiShi_LED_Hap = 1;
					D_Key_PowerDown_TiShi_LED_Time = C_Key_PowerDown_TiShi_LED_Time;
					LED_parameter_Reset();
				}

			}
		}
		else
		{
			if(D_Key2Buf)
			{
				D_Key2Buf = 0;
				D_Key2Release = 1;
			}
		}
	}

}
void Key3Dete(void)
{

	if(R_Key3Debounce)
		R_Key3Debounce--;

	if(Key3_IN_check == 0)
	{
		if(D_Key3Reg == 0)
		{
			D_Key3Reg = 1;
			R_Key3Debounce = C_Key3DEBOUNCE;
		}
	}
	else
	{
		if(D_Key3Reg)
		{
			D_Key3Reg = 0;
			R_Key3Debounce = C_Key3DEBOUNCE;
		}
	}
	if(R_Key3Debounce == 0)
	{
		if(D_Key3Reg)
		{
			if(D_Key3Buf == 0)
			{
				D_Key3Buf = 1;
				D_Key3Press = 1;

				if(!D_KEY_PowerON_Flag&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
				{
					Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
					D_Key_PowerDown_TiShi_LED_Hap = 1;
					D_Key_PowerDown_TiShi_LED_Time = C_Key_PowerDown_TiShi_LED_Time;
					LED_parameter_Reset();
				}

			}
		}
		else
		{
			if(D_Key3Buf)
			{
				D_Key3Buf = 0;
				D_Key3Release = 1;
			}
		}
	}

/////////////////////////////////////////////////////////
	if(D_Key3Press)
	{
		D_Key3Press = 0;		

		D_Change_Hearting_Power_Check_Key3_Time_En_Flag = 1;
		R_Change_Hearting_Power_Check_Key3_Time = (C_Change_Hearting_Power_Check_Key3_Time - 1);

		D_Change_Hearting_Power_Check_Key4_Time_En_Flag = 0;
		R_Change_Hearting_Power_Check_Key4_Time = 0;

	}
	
	if(D_Key3Buf&&D_Change_Hearting_Power_Check_Key3_Time_En_Flag&&D_KEY_PowerON_Flag)
	{
		R_Change_Hearting_Power_Check_Key3_Time++;
		if(R_Change_Hearting_Power_Check_Key3_Time==C_Change_Hearting_Power_Check_Key3_Time)
		{
			R_Change_Hearting_Power_Check_Key3_Time = 0;
						
			R_Zdscnmd_Gl += 10;
			if(R_Zdscnmd_Gl>R_Zdscnmd_Gl_Da)
				R_Zdscnmd_Gl = R_Zdscnmd_Gl_Da;

			if(R_Zdscnmd_Gl<=150)
			{
				R_Smoke_Res_Model = C_Smoke_Res_Model_Single;
				R_Hearting_Res_Value = 80;
			}
			else
			{
				R_Smoke_Res_Model = C_Smoke_Res_Model_double;
				R_Hearting_Res_Value = 40;
			}

			R_GongLv_Level = ((R_Zdscnmd_Gl-100)/25+1);
			R_GongLv_GeWei = (R_Zdscnmd_Gl%100)/10;
			R_GongLv_ShiWei = R_Zdscnmd_Gl/100;

			Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
			R_Normal_LED_Time = 3*1000/5;
//			LED_parameter_Reset();

			if(D_USBBuf&&!D_ChargeFullBuf)
			{
//				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
//				D_Charge_LED_Flash_State = 99;
//				LED_parameter_Reset();

			}

		}			
	}
	else
	{
		D_Change_Hearting_Power_Check_Key3_Time_En_Flag = 0;
		R_Change_Hearting_Power_Check_Key3_Time = 0;
	}		

}
void Key4Dete(void)
{

	if(R_Key4Debounce)
		R_Key4Debounce--;

	if(Key4_IN_check == 0)
	{
		if(D_Key4Reg == 0)
		{
			D_Key4Reg = 1;
			R_Key4Debounce = C_Key4DEBOUNCE;
		}
	}
	else
	{
		if(D_Key4Reg)
		{
			D_Key4Reg = 0;
			R_Key4Debounce = C_Key4DEBOUNCE;
		}
	}
	if(R_Key4Debounce == 0)
	{
		if(D_Key4Reg)
		{
			if(D_Key4Buf == 0)
			{
				D_Key4Buf = 1;
				D_Key4Press = 1;

				if(!D_KEY_PowerON_Flag&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
				{
					Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
					D_Key_PowerDown_TiShi_LED_Hap = 1;
					D_Key_PowerDown_TiShi_LED_Time = C_Key_PowerDown_TiShi_LED_Time;
					LED_parameter_Reset();
				}

			}
		}
		else
		{
			if(D_Key4Buf)
			{
				D_Key4Buf = 0;
				D_Key4Release = 1;
			}
		}
	}

/////////////////////////////////////////////////////////
	if(D_Key4Press)
	{
		D_Key4Press = 0;		

		D_Change_Hearting_Power_Check_Key4_Time_En_Flag = 1;
		R_Change_Hearting_Power_Check_Key4_Time = (C_Change_Hearting_Power_Check_Key4_Time - 1);

		D_Change_Hearting_Power_Check_Key3_Time_En_Flag = 0;
		R_Change_Hearting_Power_Check_Key3_Time = 0;

	}
	
	if(D_Key4Buf&&D_Change_Hearting_Power_Check_Key4_Time_En_Flag&&D_KEY_PowerON_Flag)
	{
		R_Change_Hearting_Power_Check_Key4_Time++;
		if(R_Change_Hearting_Power_Check_Key4_Time==C_Change_Hearting_Power_Check_Key4_Time)
		{
			R_Change_Hearting_Power_Check_Key4_Time = 0;
						
			R_Zdscnmd_Gl -= 10;
			if(R_Zdscnmd_Gl<R_Zdscnmd_Gl_Xiao)
				R_Zdscnmd_Gl = R_Zdscnmd_Gl_Xiao;

			if(R_Zdscnmd_Gl<=150)
			{
				R_Smoke_Res_Model = C_Smoke_Res_Model_Single;
				R_Hearting_Res_Value = 80;
			}
			else
			{
				R_Smoke_Res_Model = C_Smoke_Res_Model_double;
				R_Hearting_Res_Value = 40;
			}

			R_GongLv_Level = ((R_Zdscnmd_Gl-100)/25+1);
			R_GongLv_GeWei = (R_Zdscnmd_Gl%100)/10;
			R_GongLv_ShiWei = R_Zdscnmd_Gl/100;

			Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
			R_Normal_LED_Time = 3*1000/5;
//			LED_parameter_Reset();

			if(D_USBBuf&&!D_ChargeFullBuf)
			{
//				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
//				D_Charge_LED_Flash_State = 99;
//				LED_parameter_Reset();

			}

		}			
	}
	else
	{
		D_Change_Hearting_Power_Check_Key4_Time_En_Flag = 0;
		R_Change_Hearting_Power_Check_Key4_Time = 0;
	}		

}

void Safe_Stop_Hearting(void)
{
	D_Hearting_Flag = 0;
	Smoke_Res_DoNotHearting;
	D_Smoke_Res_Hearting_Flag = 0;
	Charge_Enbale;
	R_Hearting_Res_Level_Det_Delay = C_Hearting_Res_Level_Det_Delay;
	R_Bat_Level_Det_Delay = C_Bat_Level_Det_Delay;
	BatVol_Proce_Flag = 1;
	R_USB_Out_DoNot_Det_Bat_Time = 0;





}
void Clear_LED_Old_Happen_WithOut_Charge_LED_Hap(void)
{
	D_Hearting_LED_Hap = 0;
//	D_Smoke_Res_OUT_LED_Hap = 0;
	D_Smoke_Res_Short_LED_Hap = 0;
	D_LowPowr_LED_Hap = 0;
//	D_HighTemperature_LED_Hap = 0;
	D_Hearting_Time_Over_LED_Hap = 0;
//	R_Load_In_LED_Time = 0;
//	D_Charge_LED_Hap = 0;
//	R_Load_OUT_LED_NUM = 0;
	R_Normal_LED_Time = 0;
//	D_Hearting_END_LED_Hap = 0;
	D_Charge_Full_LED_Hap = 0;
	D_USB_Out_LED_Hap = 0;

	
	R_Hearting_Normal_End_ShuZhi_Hold_Time = 0;
	D_Key_PowerDown_TiShi_LED_Hap = 0;

}
void MicDete(void)
{
	if(R_MicDebounce)
		R_MicDebounce--;

	if(Mic_IN_check == 1)
	{
		if(D_MicReg == 0)
		{
			D_MicReg = 1;
			R_MicDebounce = C_MicDEBOUNCE;
		}
	}
	else
	{
		if(D_MicReg)
		{
			D_MicReg = 0;
			R_MicDebounce = C_MicDEBOUNCE;
		}
	}

	if(R_MicDebounce == 0)
	{
		if(D_MicReg)
		{
			if(D_MicBuf == 0)
			{
				D_MicBuf = 1;
				D_MicPress = 1;

				if(!D_KEY_PowerON_Flag&&!D_Key_PowerOn_LED_Hap&&!D_Key_PowerDown_LED_Hap)
				{
					Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
					D_Key_PowerDown_TiShi_LED_Hap = 1;
					D_Key_PowerDown_TiShi_LED_Time = C_Key_PowerDown_TiShi_LED_Time;
					LED_parameter_Reset();
				}

			}
		}
		else
		{
			if(D_MicBuf)
			{
				D_MicBuf = 0;
				D_MicRelease = 1;
			}
		}
	}


}

void Mic2Dete(void)
{
	if(R_Mic2_AD_Cnt<(1*1000/40))
	{
		R_Mic2_AD_Cnt++;
		R_Mic2_AD = ADC_GetData(Mic2_DetePin,0);
		R_Mic2_AD = R_Mic2_AD*R_AD_I_Aver_For_TiaoWu/4200;
	
	 if(R_Mic2_AD<=1250)
		 R_Mic2_AD_Temp = 0;
	 else if(R_Mic2_AD>1250&&R_Mic2_AD<=1300)
		 R_Mic2_AD_Temp = 1;
	 else if(R_Mic2_AD>1300&&R_Mic2_AD<=1350)
		 R_Mic2_AD_Temp = 2;
	 else if(R_Mic2_AD>1350&&R_Mic2_AD<=1400)
		 R_Mic2_AD_Temp = 3;
	 else if(R_Mic2_AD>1400&&R_Mic2_AD<=1450)
		 R_Mic2_AD_Temp = 4;
	 else if(R_Mic2_AD>1450&&R_Mic2_AD<=1500)
		 R_Mic2_AD_Temp = 5;
	 else if(R_Mic2_AD>1500&&R_Mic2_AD<=1550)
		 R_Mic2_AD_Temp = 6;
	 else if(R_Mic2_AD>1550&&R_Mic2_AD<=1600)
		 R_Mic2_AD_Temp = 7;
	 else if(R_Mic2_AD>1600&&R_Mic2_AD<=1650)
		 R_Mic2_AD_Temp = 8;
	 else if(R_Mic2_AD>1650)
		R_Mic2_AD_Temp = 9;  

	 if(R_Mic2_AD_Temp>R_Mic2_LL_Temp)
	 	R_Mic2_LL_Temp = R_Mic2_AD_Temp;
	}
	else
	{
		R_Mic2_AD_Cnt = 0;

		R_Mic2_LL = R_Mic2_LL_Temp;

		if(R_Mic2_LL==1)
		{

		}
		else if(R_Mic2_LL==2||R_Mic2_LL==3)
		{
			if(R_LED_Flash_Time1>=2)
				R_LED_Flash_Time1 -= 1;
		}

		else if(R_Mic2_LL==4||R_Mic2_LL==5)
		{
			if(R_LED_Flash_Time1>=3)
				R_LED_Flash_Time1 -= 2;
			else if(R_LED_Flash_Time1)
				R_LED_Flash_Time1 = 1;		
		}
		else if(R_Mic2_LL==6||R_Mic2_LL==7)
		{
			if(R_LED_Flash_Time1>=4)
				R_LED_Flash_Time1 -= 3;
			else if(R_LED_Flash_Time1)
				R_LED_Flash_Time1 = 1;					
		}
		else if(R_Mic2_LL==8||R_Mic2_LL==9)
		{
			if(R_LED_Flash_Time1>=5)
				R_LED_Flash_Time1 -= 4;
			else if(R_LED_Flash_Time1)
				R_LED_Flash_Time1 = 1;				
		}


		R_Mic2_LL_Temp = 0 ;
	}




 	if(R_Mic2_LL)
 	{
		R_Dance_LED_Time = C_Dance_LED_Time;
		if(R_Dance_Time_First_Dete_Flag)
		{
			R_Dance_Time_First_Dete_Flag = 0;
			R_Dance_Time = C_Dance_Time1;
		}

 	}

}


void Hearting_Ctrl(void)
{

	if(!D_Hearting_Time_Over_LED_Hap && !D_LowPowr_LED_Hap && !D_Smoke_Res_Short_LED_Hap \
	\
	&& (D_MicBuf || D_Key2Buf))
	{

		if(D_Hearting_Flag)
		{
			D_MicPress = 0;
			D_Key2Press = 0;		
		}

		if(D_MicPress || D_Key2Press)
		{
			R_Smoke_Res_Model_BeiFeng = R_Smoke_Res_Model;
			R_Hearting_Res_Value_BeiFeng = R_Hearting_Res_Value;
			R_Zdscnmd_Gl_BeiFeng = R_Zdscnmd_Gl;

			Charge_Disbale;
			DelayTime_ms(5);
			
			read_Batvol0();
	
			Charge_Enbale;

				
			if(D_MicPress)
			{
				D_MicPress = 0;
				R_Dance_Time = 0;
				Music_Det_Disable;
				R_Dance_LED_Time = 0;

			}			
			else if(D_Key2Press)
			{
				D_Key2Press = 0;
				R_Dance_Time = 0;
				Music_Det_Disable;
				R_Dance_LED_Time = 0;
				
				R_Smoke_Res_Model = C_Smoke_Res_Model_double;
				R_Hearting_Res_Value = 40;
				R_Zdscnmd_Gl = 400;
				
//				R_GongLv_Level = ((R_Zdscnmd_Gl-100)/25+1);
				R_GongLv_GeWei = (R_Zdscnmd_Gl%100)/10;
				R_GongLv_ShiWei = R_Zdscnmd_Gl/100;


			}

			if(R_Smoke_Res_Model == C_Smoke_Res_Model_Single)
				R_Smoke_Res_Hearting_PWM_ON = R_Zdscnmd_Gl*200*(R_Hearting_Res_Value+10)*(R_Hearting_Res_Value+10)/(R_AD_I_Aver*R_AD_I_Aver*R_Hearting_Res_Value/1000);
			else if(R_Smoke_Res_Model == C_Smoke_Res_Model_double)
				R_Smoke_Res_Hearting_PWM_ON = R_Zdscnmd_Gl*200*(R_Hearting_Res_Value+8)*(R_Hearting_Res_Value+8)/(R_AD_I_Aver*R_AD_I_Aver*R_Hearting_Res_Value/1000);
			
			if(R_Smoke_Res_Hearting_PWM_ON>=200)
				R_Smoke_Res_Hearting_PWM_ON = 200;
			R_Smoke_Res_Hearting_PWM_OFF = 200 - R_Smoke_Res_Hearting_PWM_ON;		
			
			R_Hearting_Time = 0;
			R_Hearting_Time_GeWei = 0;
			R_Hearting_Time_ShiWei = 0;
			if(R_Bat_Level==0)
			{				
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_LowPowr_LED_Hap = 1;				
				R_LowPowr_LED_Flash_Num = C_LowPowr_LED_Flash_Num;
				LED_parameter_Reset();
	
				goto __LowerPower;
			}
/*
			if(D_HighTemperature_Reg)
			{
//				Clear_LED_Old_Happen();
//				D_HighTemperature_LED_Hap = 1; 			
				Clear_LED_Old_Happen();

				Set_OLED_Home_Page_Time();
				Clear_Oled_Old_Happen();
				D_HighTemperature_Oled_Work = 1; 			
				R_HighTemperature_Oled_Time = C_HighTemperature_Oled_Time;
				D_Refresh_OLED_En = 1;	
				goto __LowerPower;
			}
*/
			R_Smoke_Res_Hearting_PWM_CNT = 0;	

//			Hearting_Res_Dete();
//			R_Hearting_Res_Value_Dete_Time = 0;//C_Hearting_Res_Value_Dete_Time;
			


			Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
			D_Hearting_LED_Hap = 1;
			R_LED_Working_Model_Hearting_Delay = C_LED_Working_Model_Hearting_Delay;
			LED_parameter_Reset();
			
			Charge_Disbale;

			if(R_Smoke_Res_Model == C_Smoke_Res_Model_Single)
			{
				R_Smoke_Res_Choice_Cnt++;
				if(R_Smoke_Res_Choice_Cnt>5)
				{
					R_Smoke_Res_Choice_Cnt = 1;
					R_Smoke_Res_Choice ^= 1;
				}
			}
			R_Smoke_Res_Short_Dete_Flag = 1;			
			D_Hearting_Flag = 1;
		}


		if(D_Hearting_Flag)
		{
			if(D_LowPowr_Reg)
			{
				R_Bat_Level = 0;				
				R_Bat_Level_TopLimit = R_Bat_Level;				
				R_Bat_Level_FloorLimit = R_Bat_Level;
				R_Bat_Level_Temp = R_Bat_Level;
				R_Bat_Level_Temp1 = R_Bat_Level;
				R_DianLiang_Level = R_Bat_Level;

				
				Safe_Stop_Hearting();
				R_Smoke_Res_Model = R_Smoke_Res_Model_BeiFeng;
				R_Hearting_Res_Value = R_Hearting_Res_Value_BeiFeng;
				R_Zdscnmd_Gl = R_Zdscnmd_Gl_BeiFeng;

				R_GongLv_Level = ((R_Zdscnmd_Gl-100)/25+1);
				R_GongLv_GeWei = (R_Zdscnmd_Gl%100)/10;
				R_GongLv_ShiWei = R_Zdscnmd_Gl/100;				
				
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_LowPowr_LED_Hap = 1;	
				R_LowPowr_LED_Flash_Num = C_LowPowr_LED_Flash_Num;
				LED_parameter_Reset();
				
				goto __LowerPower;
			}
/*
			if(D_HighTemperature_Reg)
			{
				Safe_Stop_Hearting();
				
//				Clear_LED_Old_Happen();
//				D_HighTemperature_LED_Hap = 1;	
				Clear_LED_Old_Happen();		
				

				Set_OLED_Home_Page_Time();
				Clear_Oled_Old_Happen();
				D_HighTemperature_Oled_Work = 1;				
				R_HighTemperature_Oled_Time = C_HighTemperature_Oled_Time;
				D_Refresh_OLED_En = 1;				
				
				goto __LowerPower;
			}
*/

			R_Hearting_Time ++;
			R_Hearting_Time_GeWei = (R_Hearting_Time*5/100)%10;
			R_Hearting_Time_ShiWei = (R_Hearting_Time*5/100)/10;
			
			R_Hearting_Time_Temp++;
			if(R_Hearting_Time_Temp>=(2*1000/5))
			{
				if(R_Bat_Level_Temp_Down_FangDou<10)
					R_Bat_Level_Temp_Down_FangDou++;
					R_Hearting_Time_Temp -= (2*1000/5);
			}
			
			if(R_Hearting_Time==C_Hearting_Time)
			{
				
				Safe_Stop_Hearting();
				R_Smoke_Res_Model = R_Smoke_Res_Model_BeiFeng;
				R_Hearting_Res_Value = R_Hearting_Res_Value_BeiFeng;
				R_Zdscnmd_Gl = R_Zdscnmd_Gl_BeiFeng;
				
				R_GongLv_Level = ((R_Zdscnmd_Gl-100)/25+1);
				R_GongLv_GeWei = (R_Zdscnmd_Gl%100)/10;
				R_GongLv_ShiWei = R_Zdscnmd_Gl/100;


				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Hearting_Time_Over_LED_Hap = 1;
				R_Hearting_Time_Over_LED_Flash_Num = C_Hearting_Time_Over_LED_Flash_Num;
				LED_parameter_Reset();

				D_Bat_Level_Fall_Luck_After_Smoke_With_USB = 1;

			}
			
			if(R_Hearting_Time_Total)
			{
			
				if(R_Smoke_Res_Model == C_Smoke_Res_Model_Single)
					R_Hearting_Time_Total--;
				else if(R_Smoke_Res_Model == C_Smoke_Res_Model_double)
				{
					if(R_Zdscnmd_Gl<=210)
					{
						R_YouLiangSuoJianSQ++;
						if(R_YouLiangSuoJianSQ>=5)
						{
							R_YouLiangSuoJianSQ = 0;
							if(R_Hearting_Time_Total>=8)
								R_Hearting_Time_Total -= 8;
							else
								R_Hearting_Time_Total = 0;
						}
					}
					else if(R_Zdscnmd_Gl>210)
					{
						R_YouLiangSuoJianSQ2++;
						if(R_YouLiangSuoJianSQ2>=2)
						{
							R_YouLiangSuoJianSQ2 = 0;
							if(R_Hearting_Time_Total>=3)
								R_Hearting_Time_Total -= 3;
							else
								R_Hearting_Time_Total = 0;
						}
					}
				}
			}
			if(R_Hearting_Time_Total>=(300*1000/5))
			{
				R_YouLiang_Level = ((R_Hearting_Time_Total-(300*1000/5))/(300*1000/5))+1;
				if(R_YouLiang_Level==11)
					R_YouLiang_Level = 10;
			}
			else
				R_YouLiang_Level = 0;

		}
	__LowerPower:
	
	}
	else
	{
		if(D_Hearting_Flag)
		{
			Safe_Stop_Hearting();
			R_Smoke_Res_Model = R_Smoke_Res_Model_BeiFeng;
			R_Hearting_Res_Value = R_Hearting_Res_Value_BeiFeng;
			R_Zdscnmd_Gl = R_Zdscnmd_Gl_BeiFeng;
			
			R_GongLv_Level = ((R_Zdscnmd_Gl-100)/25+1);
			R_GongLv_GeWei = (R_Zdscnmd_Gl%100)/10;
			R_GongLv_ShiWei = R_Zdscnmd_Gl/100;

			Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
			R_Normal_LED_Time = 3*1000/5;
			R_Hearting_Normal_End_ShuZhi_Hold_Time = 2*1000/5;
			LED_parameter_Reset();

			D_Bat_Level_Fall_Luck_After_Smoke_With_USB = 1;

			if(D_USBBuf&&!D_ChargeFullBuf)
			{
//				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Charge_LED_Flash_State = 99;
				LED_parameter_Reset();

			} 		

			if(R_HuoYan_KaiGuan_Flag)
			{

				R_Dance_Time_First_Dete_Flag = 1;
				R_Dance_Dete_Delay = C_Dance_Dete_Delay;
				Music_Det_Enable;
				DelayTime_ms(20);
				read_Batvol0();
				R_AD_I_Aver_For_TiaoWu = R_AD_I_Aver;
				R_Dance_Time = C_Dance_Time;


			}
		}

		D_MicPress = 0;
		D_Key2Press = 0;
	}

}
void LED_parameter_Reset(void)
{
	R_LED_Flash_Time = 0;
	R_LED_Horse_Addend = 0;
}
void BatVol_SOC_Proce(void)
{

	if(!D_Hearting_Flag&&(D_Timer1sFlag||BatVol_Proce_Flag))
	{

		D_Timer1sFlag = 0;
		R_Timer1sCnt = 0;
		BatVol_Proce_Flag = 0;

		Charge_Disbale;
		DelayTime_ms(10);


		read_Batvol0();

		Charge_Enbale;

		R_AD_I_Aver_For_BatVol_SOC_Proce = R_AD_I_Aver;

		
		if(R_AD_I_Aver_For_BatVol_SOC_Proce<C_BatVol_Level_1)
			R_Bat_Level_Temp_NanGao = 0;
		if(C_BatVol_Level_1<=R_AD_I_Aver_For_BatVol_SOC_Proce && R_AD_I_Aver_For_BatVol_SOC_Proce<C_BatVol_Level_2)
			R_Bat_Level_Temp_NanGao = 1;
		else if(C_BatVol_Level_2<=R_AD_I_Aver_For_BatVol_SOC_Proce && R_AD_I_Aver_For_BatVol_SOC_Proce<C_BatVol_Level_3)
			R_Bat_Level_Temp_NanGao = 2;
		else if(C_BatVol_Level_3<=R_AD_I_Aver_For_BatVol_SOC_Proce && R_AD_I_Aver_For_BatVol_SOC_Proce<C_BatVol_Level_4)
			R_Bat_Level_Temp_NanGao = 3;
		else if(C_BatVol_Level_4<=R_AD_I_Aver_For_BatVol_SOC_Proce && R_AD_I_Aver_For_BatVol_SOC_Proce<C_BatVol_Level_5)
			R_Bat_Level_Temp_NanGao = 4;
		else if(C_BatVol_Level_5<=R_AD_I_Aver_For_BatVol_SOC_Proce && R_AD_I_Aver_For_BatVol_SOC_Proce<C_BatVol_Level_6)
			R_Bat_Level_Temp_NanGao = 5;
		else if(C_BatVol_Level_6<=R_AD_I_Aver_For_BatVol_SOC_Proce && R_AD_I_Aver_For_BatVol_SOC_Proce<C_BatVol_Level_7)
			R_Bat_Level_Temp_NanGao = 6;
		else if(C_BatVol_Level_7<=R_AD_I_Aver_For_BatVol_SOC_Proce && R_AD_I_Aver_For_BatVol_SOC_Proce<C_BatVol_Level_8)
			R_Bat_Level_Temp_NanGao = 7;
		else if(C_BatVol_Level_8<=R_AD_I_Aver_For_BatVol_SOC_Proce)
			R_Bat_Level_Temp_NanGao = 8;

		R_Bat_Level_FangDou = R_Bat_Level_Temp_NanGao;//强迫
		if(R_Bat_Level_Temp_NanGao == R_Bat_Level_FangDou)
		{
			R_Bat_Level_FangDou_CNT++;

			R_AD_I_Aver_For_BatVol_Total += R_AD_I_Aver_For_BatVol_SOC_Proce;

		}
		else
		{
			R_Bat_Level_FangDou = R_Bat_Level_Temp_NanGao;
			R_Bat_Level_FangDou_CNT = 0;

			R_AD_I_Aver_For_BatVol_Total = 0;
		}
		if(R_Bat_Level_FangDou_CNT == C_Bat_Level_FangDou_CNT)
		{
			R_Bat_Level_FangDou_CNT = 0;

////////////////////////////////////////////////////////////////////////////////////////
			if((C_BatVol_Level_99<=R_AD_I_Aver_For_BatVol_SOC_Proce)&&(R_Bat_Level==8))
				R_Bat_Level_99 = 1;
			else if(C_BatVol_Level_88>R_AD_I_Aver_For_BatVol_SOC_Proce)
				R_Bat_Level_99 = 0;
				
			if(R_99Debounce)
				R_99Debounce--;
			
			if(R_Bat_Level_99==1)
			{
				if(D_99Reg == 0)
				{
					D_99Reg = 1;
					R_99Debounce = C_99DEBOUNCE;
				}
			}
			else
			{
				if(D_99Reg)
				{
					D_99Reg = 0;
					R_99Debounce = C_99DEBOUNCE;
				}
			}
			if(R_99Debounce == 0)
			{
				if(D_99Reg)
				{
					if(D_99Buf == 0)
					{
						D_99Buf = 1;
						D_99Press = 1;
						R_Bat_Level_99_Flag = 1;
					}
				}
				else
				{
					if(D_99Buf)
					{
						D_99Buf = 0;
						D_99Release = 1;
						R_Bat_Level_99_Flag = 0;
					}
				}
			}
//////////////////////////////////////////////////////////////////////////////////
			if(BatVol_Proce_Flag2)
			{
				BatVol_Proce_Flag2 = 0;
				R_Bat_Level_Temp = R_Bat_Level_Temp_NanGao;
				R_Bat_Level_Temp1 = R_Bat_Level_Temp_NanGao;
			}
			else
			{
				if((R_Charge_Bat_Level_Up_Cnt>=(5*60*1000/5))&&(R_Bat_Level_Temp_NanGao>R_Bat_Level_Temp))
				{
					if(R_Bat_Level_Temp_Up_FangDou<6)
						R_Bat_Level_Temp_Up_FangDou++;
					if(R_Bat_Level_Temp_Up_FangDou==6)
					{
						R_Bat_Level_Temp_Up_FangDou = 0;
						R_Bat_Level_Temp += 1;
					}
				}
				else if(R_Bat_Level_Temp_NanGao<R_Bat_Level_Temp)
				{
					if(R_Bat_Level_Temp_Down_FangDou==10)
					{
						R_Bat_Level_Temp -= 1;
					}
					R_Bat_Level_Temp_Up_FangDou = 0;
				}
				else
				{
					R_Bat_Level_Temp_Up_FangDou = 0;
				}
			}			

			if(D_ChargeFullBuf)
			{
				R_Bat_Level = 8;			
				R_Bat_Level_TopLimit = R_Bat_Level;
				R_Bat_Level_FloorLimit = R_Bat_Level;
				R_Bat_Level_Temp = R_Bat_Level;
				R_Bat_Level_Temp1 = R_Bat_Level;
				R_Bat_Level_Temp_Down_FangDou = 5;
				D_Bat_Level_Fall_Luck_After_Smoke_With_USB = 0;			
			}
			else
			{
				R_Bat_Level = R_Bat_Level_Temp;
				if(!D_USBBuf||D_Bat_Level_Fall_Luck_After_Smoke_With_USB)
				{
					D_Bat_Level_Fall_Luck_After_Smoke_With_USB = 0;
					
					if(R_Bat_Level>R_Bat_Level_TopLimit)
						R_Bat_Level = R_Bat_Level_TopLimit;
					else if(R_Bat_Level == R_Bat_Level_TopLimit)
					{	
					}
					else
					{
						R_Bat_Level_TopLimit = R_Bat_Level;
					}

					R_Bat_Level_FloorLimit = R_Bat_Level;
				}
				else
				{
					if(R_Bat_Level<R_Bat_Level_FloorLimit)
						R_Bat_Level = R_Bat_Level_FloorLimit;
					else if(R_Bat_Level == R_Bat_Level_FloorLimit)
					{	
					}
					else
					{
						R_Bat_Level_FloorLimit = R_Bat_Level;
					}

					R_Bat_Level_TopLimit = R_Bat_Level;

				}
				if(R_Bat_Level>R_Bat_Level_Temp1)
				{
					R_Charge_Bat_Level_Up_Cnt = 0;
					R_Bat_Level_Temp_Down_FangDou = 9;

				}
				else if(R_Bat_Level<R_Bat_Level_Temp1)
				{
					R_Bat_Level_Temp_Down_FangDou = 0;

				}
				R_Bat_Level_Temp = R_Bat_Level;			
				R_Bat_Level_Temp1 = R_Bat_Level;
			}
			
			R_AD_I_Aver_For_BatVol_Total = 0;

		}


		R_DianLiang_Level = R_Bat_Level;

	}
	else
	{
		R_Bat_Level_FangDou_CNT = 0;
		R_AD_I_Aver_For_BatVol_Total = 0;
	}
}
void BatVol_SOC_Proce1(void)
{

	if(D_Hearting_Flag)
	{

		read_Batvol();
		
		if((R_AD_I_Aver+(R_AD_I_Aver*5/R_Hearting_Res_Value))<2800)
			R_LowPowr_FangDou_CNT++;
		else
		{
			R_LowPowr_FangDou_CNT = 0;
			D_LowPowr_Reg = 0;
		}
		if(R_LowPowr_FangDou_CNT==C_LowPowr_FangDou_CNT)
		{
			R_LowPowr_FangDou_CNT = 0;
			D_LowPowr_Reg = 1;
		}
	}
	else
	{
		R_LowPowr_FangDou_CNT = 0;
		D_LowPowr_Reg = 0;
	}

}
void ChargeDete(void)
{

	if(!R_PowerOn_LED_Time)
	{

//		R_USB_DetePin_AD_Value=ADC_GetData(USB_DetePin,2);
//		if(R_USB_DetePin_AD_Value<200)
//			D_USB_State = 0;
//		else
//		{
//			D_USB_State = 1;
//		}
//		
//		if(R_USB_DetePin_AD_Value>1500)
//		{
//			D_ChargeFull_State = 1;
//		}
//		else
//		{
//			D_ChargeFull_State = 0;
//		}


		if(R_USBDebounce)
			R_USBDebounce--;

		if(USB_IN_check == 1)
		{
			if(D_USBReg == 0)
			{
				D_USBReg = 1;
				R_USBDebounce = C_USBDEBOUNCE;
			}
		}
		else
		{
			if(D_USBReg)
			{
				D_USBReg = 0;
				R_USBDebounce = C_USBDEBOUNCE;
			}
		}

		if(R_USBDebounce == 0)
		{
			if(D_USBReg)
			{
				if(D_USBBuf == 0)
				{
					D_USBBuf = 1;
					D_USBPress = 1;
		
					D_USB_Out_LED_Hap = 0;

					if(D_ChargeFullBuf)
					{
						if(!D_Hearting_Flag)
						{
							Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
							D_Charge_Full_LED_Hap = 1;				
							R_Charge_Full_LED_Hold_Time = C_Charge_Full_LED_Hold_Time;
							LED_parameter_Reset();
						}
					}
					else
					{
						D_Charge_LED_Hap = 1; 			
						D_Charge_LED_Flash_State = 99;
						LED_parameter_Reset();
					}
		
				}
			}
			else
			{
				if(D_USBBuf)
				{
					D_USBBuf = 0;
					D_USBRelease = 1; 
//					D_ChargeFullBuf = 0;
		
					D_Charge_LED_Hap = 0;
					D_Charge_Full_LED_Hap = 0;

					if(!D_Bat_Level_Fall_Luck_After_Smoke_With_USB)
						R_USB_Out_DoNot_Det_Bat_Time = C_USB_Out_DoNot_Det_Bal_Time;

					if(D_Hearting_Flag==0)
					{
						Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
						D_USB_Out_LED_Hap = 1;				
						R_USB_Out_LED_Flash_Num = C_USB_Out_LED_Flash_Num;
						LED_parameter_Reset();
					}
				}
			}
		}




	///////////充满检测///////////////////////
		if(!D_Hearting_Flag&&D_USBBuf&&!R_USB_Out_DoNot_Det_Bat_Time&&!R_Bat_Level_Det_Delay)
		{
			if(R_ChargeFullDebounce)
				R_ChargeFullDebounce--;

			if(R_Bat_Level_99_Flag)
			{
				if(D_ChargeFullReg == 0)
				{
					D_ChargeFullReg = 1;
					R_ChargeFullDebounce = C_ChargeFullDEBOUNCE;
				}
			}
			else
			{
				if(D_ChargeFullReg)
				{
					D_ChargeFullReg = 0;
					R_ChargeFullDebounce = C_ChargeFullDEBOUNCE;
				}
			}

			if(R_ChargeFullDebounce == 0)
			{
				if(D_ChargeFullReg)
				{
					if(D_ChargeFullBuf == 0)
					{
						D_ChargeFullBuf = 1;
						D_ChargeFullPress = 1;
						
						D_Charge_LED_Hap = 0;
						
						Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
						D_Charge_Full_LED_Hap = 1;				
						R_Charge_Full_LED_Hold_Time = C_Charge_Full_LED_Hold_Time;
						LED_parameter_Reset();
						

					}
				}
				else
				{
					if(D_ChargeFullBuf)
					{
						D_ChargeFullBuf = 0;
						D_ChargeFullRelease = 1;

						D_Charge_Full_LED_Hap = 0;				

						D_Charge_LED_Hap = 1; 			
						D_Charge_LED_Flash_State = 99;
						LED_parameter_Reset();

					}
				}
			}	
		}
		else
		{
			R_ChargeFullDebounce = C_ChargeFullDEBOUNCE;
		}


		if(!D_Hearting_Flag&&!D_USBBuf&&!R_USB_Out_DoNot_Det_Bat_Time&&!R_Bat_Level_Det_Delay)
		{
			if(R_Bat_Level_99_Flag==0)
				D_ChargeFullBuf = 0;
		}
//////////////////////////////////////////




	}

}

void Led_Ctrl()
{

	if(R_PowerOn_LED_Time)
	{
		R_PowerOn_LED_Time--;

		DigiTube_DianLiang_Ctr(1,8);
		DigiTube_YouLiang_Ctr(1,10);
		DigiTube_GongLv_Ctr(1,8,8,13);
		DigiTube_HuoYan_Ctr(1);
		DigiTube_ShiJian_Ctr(1,8,8);
		DigiTube_KaiGuanJi_Ctr(0);
		DigiTube_HuoYan_KaiGuan_Ctr(1);	
		if(R_PowerOn_LED_Time==0)
		{
			if(D_USBBuf&&!D_ChargeFullBuf)
			{
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Charge_LED_Flash_State = 99;
				LED_parameter_Reset();

			} 
		}
		
		D_LED_Working_Flag = 1;
	}
	else if(D_Key_PowerDown_LED_Hap)
	{
		DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
		DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
		DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
		DigiTube_HuoYan_Ctr(0);
		DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
		DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);		
		DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);


		D_Key_PowerDown_LED_Time_Cnt++;



		if(D_Key_PowerDown_LED_Time_Cnt<=(8*100/5))
		{
			if((D_Key_PowerDown_LED_Time_Cnt/((8*100/5)/DigiTube_Level_Total))>=1)
			{
				*(&DigiTubeCtr_Level1_State+(D_Key_PowerDown_LED_Time_Cnt/((8*100/5)/DigiTube_Level_Total))-1) = DigiTube_Level_State_Off;
				DigiTubeCtr_Level_State_Ctrl();

			}
		}
		else
		{
		 	D_Key_PowerDown_LED_Hap = 0;

			DigiTube_DianLiang_Ctr(0,0);
			DigiTube_YouLiang_Ctr(0,0);
			DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
			DigiTube_HuoYan_Ctr(0);
			DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_GeWei);
			DigiTube_KaiGuanJi_Ctr(1);
			DigiTube_HuoYan_KaiGuan_Ctr(0);



			DigiTubeCtr_Level_State_All_On();	

			if(D_USBBuf&&!D_ChargeFullBuf)
			{
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Charge_LED_Flash_State = 99;
				LED_parameter_Reset();

			}


		}

		
		D_LED_Working_Flag = 1;


	}
	else if(D_Key_PowerOn_LED_Hap)
	{
		 

		DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
		DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
		DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
		DigiTube_HuoYan_Ctr(0);
		DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
		DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);		
		DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);



		D_Key_PowerOn_LED_Time_Cnt++;


		if(D_Key_PowerOn_LED_Time_Cnt<=(8*100/5))
		{
			if((D_Key_PowerOn_LED_Time_Cnt/((8*100/5)/DigiTube_Level_Total))>=1)
			{
				*(&DigiTubeCtr_Level10_State-(D_Key_PowerOn_LED_Time_Cnt/((8*100/5)/DigiTube_Level_Total))+1) = DigiTube_Level_State_On;
				DigiTubeCtr_Level_State_Ctrl();

			}

		}

		else
		{


			D_Key_PowerOn_LED_Hap = 0;
			R_Normal_LED_Time = 3*1000/5;
			
			if(D_USBBuf&&!D_ChargeFullBuf)
			{
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Charge_LED_Flash_State = 99;
				LED_parameter_Reset();

			}


		}

		
		D_LED_Working_Flag = 1;


	}

	else if(D_Key_PowerDown_TiShi_LED_Hap)
	{
		if(D_Key_PowerDown_TiShi_LED_Time)
			D_Key_PowerDown_TiShi_LED_Time--;

		DigiTube_DianLiang_Ctr(0,0);
		DigiTube_YouLiang_Ctr(0,0);
		DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
		DigiTube_HuoYan_Ctr(0);
		DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_GeWei);
		DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
		DigiTube_HuoYan_KaiGuan_Ctr(0);

		
		if(D_Key_PowerDown_TiShi_LED_Time==0)
			D_Key_PowerDown_TiShi_LED_Hap = 0;
		if(D_Key_PowerDown_TiShi_LED_Time==0)
		{
			if(D_USBBuf&&!D_ChargeFullBuf)
			{
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Charge_LED_Flash_State = 99;
				LED_parameter_Reset();

			} 
		}
		
		D_LED_Working_Flag = 1;
	}

	else if(D_LowPowr_LED_Hap)
	{
		if(R_LED_Flash_Time)
			R_LED_Flash_Time --;
		else
		{
			if(R_LowPowr_LED_Flash_Num%2==0)
			{
				DigiTube_DianLiang_Ctr(1,0);
				DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
				DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
				DigiTube_HuoYan_Ctr(0);
				DigiTube_ShiJian_Ctr(1,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);
			}
			else
			{
				DigiTube_DianLiang_Ctr(0,0);
				DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
				DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
				DigiTube_HuoYan_Ctr(0);
				DigiTube_ShiJian_Ctr(1,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);
			}
			R_LowPowr_LED_Flash_Num --;
			if(R_LowPowr_LED_Flash_Num != 0)
				R_LED_Flash_Time = C_LowPowr_LED_Flash_Time;
			if(R_LowPowr_LED_Flash_Num==20)
				R_LED_Flash_Time = 100/5;
		}

		if(R_LowPowr_LED_Flash_Num==0)
			D_LowPowr_LED_Hap = 0;
		if(R_LowPowr_LED_Flash_Num==0)
		{
			if(D_USBBuf&&!D_ChargeFullBuf)
			{
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Charge_LED_Flash_State = 99;
				LED_parameter_Reset();

			} 
		}		
		D_LED_Working_Flag = 1;
	}
	else if(D_USB_Out_LED_Hap)
	{
		if(R_LED_Flash_Time)
			R_LED_Flash_Time --;
		else
		{
			if(R_USB_Out_LED_Flash_Num%2==0)
			{
				DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
				DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
				DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
				if(!R_Dance_LED_Time)
					DigiTube_HuoYan_Ctr(0);
				DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

			}
			else
			{
				DigiTube_DianLiang_Ctr(0,0);
				DigiTube_YouLiang_Ctr(0,0);
				DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
				if(!R_Dance_LED_Time)
					DigiTube_HuoYan_Ctr(0);
				DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

			}
			R_USB_Out_LED_Flash_Num --;
			if(R_USB_Out_LED_Flash_Num != 0)
				R_LED_Flash_Time = C_USB_Out_LED_Flash_Time;
			if(R_USB_Out_LED_Flash_Num==6)
				R_LED_Flash_Time = 100/5;
		}

		if(R_USB_Out_LED_Flash_Num==0)
			D_USB_Out_LED_Hap = 0;
		
		D_LED_Working_Flag = 1;
	}
	else if(D_Charge_Full_LED_Hap)
	{
		if(R_Charge_Full_LED_Hold_Time)
			R_Charge_Full_LED_Hold_Time--;

		DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
		DigiTube_YouLiang_Ctr(0,0);
		DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
		if(!R_Dance_LED_Time)
			DigiTube_HuoYan_Ctr(0);
		DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
		DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
		DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

		
		if(R_Charge_Full_LED_Hold_Time==0)
			D_Charge_Full_LED_Hap = 0;

		
		D_LED_Working_Flag = 1;
	}

	else if(D_Hearting_LED_Hap)
	{
		if(R_LED_Working_Model_Hearting_Delay)
		{
			R_LED_Working_Model_Hearting_Delay--;
			
			DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
			DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
			DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
			DigiTube_HuoYan_Ctr(0);
			DigiTube_ShiJian_Ctr(1,0,0);
			DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
			DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

		}
		else
		{
			if(R_LED_Flash_Time)
				R_LED_Flash_Time --;
			else 
			{

				DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
				if(R_YouLiang_Level)
					DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
				else
				{
					if((R_LED_Horse_Addend%2)==0)
					{
						DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);

					}
					else
					{
						DigiTube_YouLiang_Ctr(0,R_YouLiang_Level);
					}
				}
				DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_LED_Horse_Addend);
//					DigiTube_HuoYan_Ctr(0);
				DigiTube_ShiJian_Ctr(1,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

		
				R_LED_Horse_Addend++;
				if(R_LED_Horse_Addend>13)
					R_LED_Horse_Addend = 0;
					

				R_LED_Flash_Time = C_Hearting_LED_Flash_Time;

				if(R_HuoYan_KaiGuan_Flag)
				{
					R_HuoYan_Level = rand()%10;
					DigiTube_HuoYan_Level_Ctr(R_HuoYan_Level);
				}
				else
				{
					DigiTube_HuoYan_Ctr(0);
				}
			}
		
			
		}

		
		D_LED_Working_Flag = 1;
	}
	

	else if(D_Smoke_Res_Short_LED_Hap)
	{
		if(R_LED_Flash_Time)
			R_LED_Flash_Time --;
		else
		{
			if(R_Smoke_Res_Short_LED_Flash_Num%2==0)
			{
				DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
				DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
				DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
				DigiTube_HuoYan_Ctr(1);
				DigiTube_ShiJian_Ctr(1,R_Hearting_Time_GeWei,R_Hearting_Time_GeWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

			}
			else
			{
				DigiTube_DianLiang_Ctr(0,0);
				DigiTube_YouLiang_Ctr(0,0);
				DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
				DigiTube_HuoYan_Ctr(0);
				DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_GeWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

			}
			R_Smoke_Res_Short_LED_Flash_Num --;
			if(R_Smoke_Res_Short_LED_Flash_Num != 0)
				R_LED_Flash_Time = C_Smoke_Res_Short_LED_Flash_Time;
			if(R_Smoke_Res_Short_LED_Flash_Num==10)
				R_LED_Flash_Time = 100/5;

		}

		if(R_Smoke_Res_Short_LED_Flash_Num==0)
			D_Smoke_Res_Short_LED_Hap = 0;
		if(R_Smoke_Res_Short_LED_Flash_Num==0)
		{
			if(D_USBBuf&&!D_ChargeFullBuf)
			{
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Charge_LED_Flash_State = 99;
				LED_parameter_Reset();
			} 
		}

		D_LED_Working_Flag = 1;
	}

//	else if(D_Smoke_Res_OUT_LED_Hap && R_Smoke_Res_OUT_LED_Flash_Num)
//	{
//		if(R_LED_Flash_Time)
//			R_LED_Flash_Time --;
//		else
//		{
//			if(R_Smoke_Res_OUT_LED_Flash_Num%2==0)
//			{
//				LED_B_ALL_On();

//			}
//			else
//			{
//				LED_ALL_Off();

//			}
//			R_Smoke_Res_OUT_LED_Flash_Num --;
//			if(R_Smoke_Res_OUT_LED_Flash_Num != 0)
//				R_LED_Flash_Time = C_Smoke_Res_OUT_LED_Flash_Time;
//			if(R_Smoke_Res_OUT_LED_Flash_Num==8)
//				R_LED_Flash_Time = 100/5;

//		}
//		if(R_Smoke_Res_OUT_LED_Flash_Num==0)
//			D_Smoke_Res_OUT_LED_Hap = 0;
//		if(R_Smoke_Res_OUT_LED_Flash_Num==0)
//		{
//			if(D_USBBuf&&!D_ChargeFullBuf)
//			{
//				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
//				D_Charge_LED_Hap = 1;
//				LED_parameter_Reset();
//				Charge_LED_HX_Colour();

//			} 
//		}

//		D_LED_Working_Flag = 1;
//	}

//	else if(R_Load_In_LED_Time )
//	{
//		R_Load_In_LED_Time--;
//		LED_W_ALL_On();
//		
//		if(R_Load_In_LED_Time==0)
//		{
//			if(D_USBBuf&&!D_ChargeFullBuf)
//			{
//				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
//				D_Charge_LED_Hap = 1;
//				LED_parameter_Reset();
//				Charge_LED_HX_Colour();

//			} 
//		}

//		D_LED_Working_Flag = 1;
//	}

//	else if(R_Load_OUT_LED_NUM )
//	{
//		if(R_LED_Flash_Time)
//			R_LED_Flash_Time --;
//		else
//		{
//			if(R_Load_OUT_LED_NUM%2==0)
//			{
//				LED_ALL_On();

//			}
//			else
//			{
//				LED_ALL_Off();

//			}
//			R_Load_OUT_LED_NUM --;
//			if(R_Load_OUT_LED_NUM != 0)
//				R_LED_Flash_Time = C_Load_OUT_LED_Flash_Time;
//			if(R_Load_OUT_LED_NUM==4)
//				R_LED_Flash_Time = 100/5;

//		}
//		D_LED_Working_Flag = 1;
//	}

	else if(D_Hearting_Time_Over_LED_Hap)
	{
		if(R_LED_Flash_Time)
			R_LED_Flash_Time --;
		else
		{
			if(R_Hearting_Time_Over_LED_Flash_Num%2==0)
			{
				DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
				DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
				DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
				DigiTube_HuoYan_Ctr(1);
				DigiTube_ShiJian_Ctr(1,R_Hearting_Time_GeWei,R_Hearting_Time_GeWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

			}
			else
			{
				DigiTube_DianLiang_Ctr(0,0);
				DigiTube_YouLiang_Ctr(0,0);
				DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
				DigiTube_HuoYan_Ctr(0);
				DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_GeWei);
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

			}
			R_Hearting_Time_Over_LED_Flash_Num --;
			if(R_Hearting_Time_Over_LED_Flash_Num != 0)
				R_LED_Flash_Time = C_Hearting_Time_Over_LED_Flash_Time;
			if(R_Hearting_Time_Over_LED_Flash_Num==4)
				R_LED_Flash_Time = 100/5;
		}

		if(R_Hearting_Time_Over_LED_Flash_Num==0)
			D_Hearting_Time_Over_LED_Hap = 0;
		if(R_Hearting_Time_Over_LED_Flash_Num==0)
		{
			if(D_USBBuf&&!D_ChargeFullBuf)
			{
				Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
				D_Charge_LED_Flash_State = 99;
				LED_parameter_Reset();

			} 
		}		
		D_LED_Working_Flag = 1;
	}


	else if(D_Charge_LED_Hap)//after
	{
		if(R_LED_Flash_Time)
			R_LED_Flash_Time --;
		else
		{
			if(D_Charge_LED_Flash_State==0)
			{
				DigiTube_DianLiang_Ctr1(1,1,(R_DianLiang_Level+R_LED_Horse_Addend));
				if(R_Normal_LED_Time>=C_Charge_LED_Flash_Time)
				{
					R_Normal_LED_Time -= C_Charge_LED_Flash_Time;
					DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
					DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
					if(!R_Dance_LED_Time)
						DigiTube_HuoYan_Ctr(0);
					if(R_Hearting_Normal_End_ShuZhi_Hold_Time)
					{
						DigiTube_ShiJian_Ctr(1,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
					}
					else
						DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);


				}
				else
				{
					R_Normal_LED_Time = 0;
					DigiTube_YouLiang_Ctr(0,0);
					DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
					if(!R_Dance_LED_Time)
						DigiTube_HuoYan_Ctr(0);
					DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
				}
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

			}
			else if(D_Charge_LED_Flash_State==1 | D_Charge_LED_Flash_State==99)
			{
				DigiTube_DianLiang_Ctr1(0,1,(R_DianLiang_Level+R_LED_Horse_Addend));
				if(R_Normal_LED_Time>=(100/5))
				{
					R_Normal_LED_Time -= (100/5);
					DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
					DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
					if(!R_Dance_LED_Time)
						DigiTube_HuoYan_Ctr(0);
					if(R_Hearting_Normal_End_ShuZhi_Hold_Time)
					{
						DigiTube_ShiJian_Ctr(1,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
					}
					else
						DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);


				}
				else
				{
					R_Normal_LED_Time = 0;
					DigiTube_YouLiang_Ctr(0,0);
					DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
					if(!R_Dance_LED_Time)
						DigiTube_HuoYan_Ctr(0);
					DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
				}
				DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);
				DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);

			}

			R_LED_Horse_Addend++;

			if(R_DianLiang_Level==0)
			{
				if((R_DianLiang_Level+R_LED_Horse_Addend)>8)
					R_LED_Horse_Addend = 0;
			}
			else
			{
				if((R_DianLiang_Level+R_LED_Horse_Addend)>8)
					R_LED_Horse_Addend = -1;
			}
			
			if(D_Charge_LED_Flash_State==99)
			{
				R_LED_Flash_Time = 100/5;
				D_Charge_LED_Flash_State = 0;

			}
			else
			{
				D_Charge_LED_Flash_State ^= 1;
				R_LED_Flash_Time = C_Charge_LED_Flash_Time;
			}


		}

		
		D_LED_Working_Flag = 1;
	}
	else if(R_Normal_LED_Time)//after and after
	{
		R_Normal_LED_Time --;

		DigiTube_DianLiang_Ctr(1,R_DianLiang_Level);
		DigiTube_YouLiang_Ctr(1,R_YouLiang_Level);
		DigiTube_GongLv_Ctr(1,R_GongLv_GeWei,R_GongLv_ShiWei,R_GongLv_Level);
		if(!R_Dance_LED_Time)
			DigiTube_HuoYan_Ctr(0);
		if(R_Hearting_Normal_End_ShuZhi_Hold_Time)
		{
			DigiTube_ShiJian_Ctr(1,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
		}
		else
			DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_ShiWei);
		
		DigiTube_KaiGuanJi_Ctr(R_KaiGuanJi_State);		
		DigiTube_HuoYan_KaiGuan_Ctr(R_HuoYan_KaiGuan_Flag);
		
		D_LED_Working_Flag = 1;
	}

	else
	{
		DigiTube_DianLiang_Ctr(0,0);
		DigiTube_YouLiang_Ctr(0,0);
		DigiTube_GongLv_Ctr(0,R_GongLv_GeWei,R_GongLv_ShiWei,0);
		if(!R_Dance_LED_Time)
			DigiTube_HuoYan_Ctr(0);
		DigiTube_ShiJian_Ctr(0,R_Hearting_Time_GeWei,R_Hearting_Time_GeWei);
		DigiTube_KaiGuanJi_Ctr(1);
		DigiTube_HuoYan_KaiGuan_Ctr(0);

		D_LED_Working_Flag = 0;
	}

	if(R_Dance_LED_Time)
	{
	
		R_Dance_LED_Time--;

		if(R_LED_Flash_Time1)
			R_LED_Flash_Time1 --;
		else
		{

			R_LED_Flash_Time1 = C_Hearting_LED_Flash_Time1;

			R_HuoYan_Level = rand()%10;
			DigiTube_HuoYan_Level_Ctr(R_HuoYan_Level);


		}

		
		D_LED_Working_Flag = 1;

	}

}

void Hearting_Working()
{
	if(D_Hearting_Flag)
	{
		R_Smoke_Res_Hearting_PWM_CNT ++;
		if(R_Smoke_Res_Hearting_PWM_CNT>200)
				R_Smoke_Res_Hearting_PWM_CNT = 1;
		
		if(R_Smoke_Res_Hearting_PWM_CNT <= R_Smoke_Res_Hearting_PWM_OFF)
		{
			Smoke_Res_DoNotHearting;
			D_Smoke_Res_Hearting_Flag = 0;
			
		}
		else
		{		
			if(R_Smoke_Res_Model==C_Smoke_Res_Model_Single)
			{
				if(R_Smoke_Res_Choice==C_Smoke_Res_Choice_1)
					Smoke_Res1_Hearting;
				else
					Smoke_Res2_Hearting;
			}
			else
			{
				Smoke_Res1_Hearting;
				Smoke_Res2_Hearting;
			}
			
			D_Smoke_Res_Hearting_Flag = 1;
			
			R_Smoke_Res_Short_Dete_Time++;
			if(R_Smoke_Res_Short_Dete_Time==C_Smoke_Res_Short_Dete_Time)
			{
				R_Smoke_Res_Short_Dete_Time = 0;
				R_Smoke_Res_Short_Dete_Flag = 1;
			}

			if(D_ADWork_State__8888==0&&R_Smoke_Res_Short_Dete_Flag)
			{
				R_Smoke_Res_Short_Dete_Flag = 0;
				
				if(R_Smoke_Res_Model==C_Smoke_Res_Model_Single)
				{
					if(R_Smoke_Res_Choice==C_Smoke_Res_Choice_1)
						R_jiujiuwoba=ADC_GetData(Hearting_Res1_DetePin,0);
					else
						R_jiujiuwoba=ADC_GetData(Hearting_Res2_DetePin,0);
				}	
				else
				{
					R_jiujiuwoba1=ADC_GetData(Hearting_Res1_DetePin,0);
					R_jiujiuwoba2=ADC_GetData(Hearting_Res2_DetePin,0);
					if(R_jiujiuwoba1<=R_jiujiuwoba2)
						R_jiujiuwoba = R_jiujiuwoba1;
					else
						R_jiujiuwoba = R_jiujiuwoba2;
					
				}
			
				if(R_jiujiuwoba<3450)
				{

					if(R_Smoke_Res_Model==C_Smoke_Res_Model_Single)
					{
						if(R_Smoke_Res_Choice==C_Smoke_Res_Choice_1)
							R_jiujiuwoba=ADC_GetData(Hearting_Res1_DetePin,0);
						else
							R_jiujiuwoba=ADC_GetData(Hearting_Res2_DetePin,0);
					} 
					else
					{
						R_jiujiuwoba1=ADC_GetData(Hearting_Res1_DetePin,0);
						R_jiujiuwoba2=ADC_GetData(Hearting_Res2_DetePin,0);
						if(R_jiujiuwoba1<=R_jiujiuwoba2)
							R_jiujiuwoba = R_jiujiuwoba1;
						else
							R_jiujiuwoba = R_jiujiuwoba2;
						
					}

					if(R_jiujiuwoba<3450)
					{				
						Safe_Stop_Hearting();
						R_Smoke_Res_Model = R_Smoke_Res_Model_BeiFeng;
						R_Hearting_Res_Value = R_Hearting_Res_Value_BeiFeng;
						R_Zdscnmd_Gl = R_Zdscnmd_Gl_BeiFeng;

						R_GongLv_Level = ((R_Zdscnmd_Gl-100)/25+1);
						R_GongLv_GeWei = (R_Zdscnmd_Gl%100)/10;
						R_GongLv_ShiWei = R_Zdscnmd_Gl/100;

	//					R_Hearting_Res_Level = C_Hearting_Res_Level_Short;
	//					R_Hearting_Res_Value = 0;

						Clear_LED_Old_Happen_WithOut_Charge_LED_Hap();
						D_Smoke_Res_Short_LED_Hap = 1;
						R_Smoke_Res_Short_LED_Flash_Num = C_Smoke_Res_Short_LED_Flash_Num;
						LED_parameter_Reset();
					}
			
				}
			}		
			
	
		}
	
	}


}
void CheckSleep(void)
{
	if(D_MicReg || D_MicBuf || D_Mic2Reg || D_Mic2Buf || D_USBBuf || D_USBReg || \
	D_Key2Reg || D_Key2Buf || D_Key3Reg || D_Key3Buf || \
	D_Key4Reg || D_Key4Buf || D_KeyReg || D_KeyBuf	|| \
	D_LED_Working_Flag || R_Key_Temp1 || R_Dance_Time || BatVol_Proce_Flag)
	{
		R_SleepTime = C_TIME_SLEEP;
	}

	if(R_SleepTime)
		R_SleepTime--;
	else
	{
		GPIOInit();	
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);//Stop led power
		Music_Det_Disable_Real;
//		LL_COMP_Disable(COMP2);
//		LL_COMP_DeInit(COMP2);
//		LL_APB1_GRP2_DisableClock(LL_APB1_GRP2_PERIPH_COMP2);

		LL_ADC_Disable(ADC1);
		
		
		HAL_SuspendTick();	//systick中断关闭
		LL_IWDG_ReloadCounter(IWDG); /*喂狗*/
		APP_LPTIM_OneShot();//2S唤醒一次
		LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_13, LL_GPIO_PULL_DOWN);//
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_1);//失能充电芯片 防止反向耗电




		APP_ConfigureEXTI();

__Sleep:
		APP_EnterStop();		//
		if(D_Sleep_Again_Flag)
		{
			LL_IWDG_ReloadCounter(IWDG); /*喂狗*/

			D_Sleep_Again_Flag = 0;
			goto __Sleep;
		}
		LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_13, LL_GPIO_PULL_UP);//
		LL_IWDG_ReloadCounter(IWDG); /*喂狗*/


		NVIC_DisableIRQ(EXTI4_15_IRQn);
		NVIC_DisableIRQ(EXTI2_3_IRQn);
		NVIC_DisableIRQ(EXTI0_1_IRQn);
		
		init_devices();		
		Music_Det_Enable;
		R_SleepTime = C_TIME_SLEEP;
		

		/*失能LPTIM*/
		LL_LPTIM_Disable(LPTIM1);


	}	

}



/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
