/**
  ******************************************************************************
  * @file    py32c6xx_it.c
  * @author  MCU Application Team
  * @brief   Interrupt Service Routines.
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
#include "main.h"
#include "bsp.h"
#include "py32c6xx_it.h"
#include "py32c6xx_ll_iwdg.h"
#include "py32c6xx_ll_lptim.h"

/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers         */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
}


extern void sys_time_isr_process(void);
/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
	sys_time_isr_process();
}
void EXTI0_1_IRQHandler(void)
{
	LL_IWDG_ReloadCounter(IWDG); /*喂狗*/
 
  /* 处理EXTI中断请求 */
  LL_EXTI_ClearFlag(LL_EXTI_LINE_0);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_1);
}

void EXTI2_3_IRQHandler(void)
{
	LL_IWDG_ReloadCounter(IWDG); /*喂狗*/

  /* 处理EXTI中断请求 */
  LL_EXTI_ClearFlag(LL_EXTI_LINE_2);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_3);
}
void EXTI4_15_IRQHandler(void)
{
	LL_IWDG_ReloadCounter(IWDG); /*喂狗*/

  /* 处理EXTI中断请求 */
  LL_EXTI_ClearFlag(LL_EXTI_LINE_4);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_5);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_6);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_7);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_8);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_9);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_10);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_11);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_12);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_13);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_14);
  LL_EXTI_ClearFlag(LL_EXTI_LINE_15);

}
void LPTIM1_IRQHandler(void)
{
  if(LL_LPTIM_IsActiveFlag_ARRM(LPTIM) == 1)
  {
    LL_LPTIM_ClearFLAG_ARRM(LPTIM);
    
		
		LL_IWDG_ReloadCounter(IWDG); /*喂狗*/
		APP_LPTIM_OneShot();//2S唤醒一次

		D_Sleep_Again_Flag = 1;



  }
}

/******************************************************************************/
/* PY32C6xx Peripheral Interrupt Handlers                                     */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file.                                          */
/******************************************************************************/

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
