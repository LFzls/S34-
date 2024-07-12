/**

 */

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"
#include "main.h"

#define u8 unsigned char
#define u16 unsigned int

//-----------------------------
void GPIOInit(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct={0};
//	GPIO_InitTypeDef  HAL_GPIO_InitStruct;

	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB);
	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOF);

//	GPIO_InitStruct.Pin = 0;
//	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
//	GPIO_InitStruct.Pull = LL_GPIO_PULL_DOWN;
//	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LL_GPIO_PIN_9|LL_GPIO_PIN_10|LL_GPIO_PIN_11|LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_DOWN;
	LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LL_GPIO_PIN_5|LL_GPIO_PIN_6|LL_GPIO_PIN_7|LL_GPIO_PIN_8|LL_GPIO_PIN_9|\
			LL_GPIO_PIN_10|LL_GPIO_PIN_11|LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_DOWN;
	LL_GPIO_Init(GPIOF, &GPIO_InitStruct);



	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_15);


	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_3);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);

	
//	LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_1);
//	LL_GPIO_ResetOutputPin(GPIOF, LL_GPIO_PIN_2);
//	LL_GPIO_ResetOutputPin(GPIOF, LL_GPIO_PIN_3);
	

	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_0, LL_GPIO_MODE_ANALOG);//res2_test_ad
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_1, LL_GPIO_MODE_ANALOG);//res1_test_ad
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_2, LL_GPIO_MODE_INPUT);//mic
	LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_2, LL_GPIO_PULL_DOWN);

	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_3, LL_GPIO_MODE_ANALOG);//music

	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);//pwm1
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);//pwm2
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_INPUT);//key_xia
	LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_6, LL_GPIO_PULL_UP);

	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_INPUT);//usb_in

	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_8, LL_GPIO_MODE_INPUT);//key_inc
	LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_8, LL_GPIO_PULL_UP);
	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_9, LL_GPIO_MODE_ANALOG);//incharge

	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_11, LL_GPIO_MODE_INPUT);//key_dec
	LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_11, LL_GPIO_PULL_UP);

	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_15, LL_GPIO_MODE_OUTPUT);//music_en


	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_0, LL_GPIO_MODE_INPUT);//key_shang
	LL_GPIO_SetPinPull(GPIOB, LL_GPIO_PIN_0, LL_GPIO_PULL_UP);

	
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_1, LL_GPIO_MODE_OUTPUT);//charge_en
	
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);//led_power_en

	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinPull(GPIOB, LL_GPIO_PIN_4, LL_GPIO_PULL_DOWN);

	
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);//
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_6, LL_GPIO_MODE_OUTPUT);//
	
	
	LL_GPIO_SetPinMode(GPIOF, LL_GPIO_PIN_0, LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinPull(GPIOF, LL_GPIO_PIN_0, LL_GPIO_PULL_DOWN);
	
	LL_GPIO_SetPinMode(GPIOF, LL_GPIO_PIN_2, LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinPull(GPIOF, LL_GPIO_PIN_2, LL_GPIO_PULL_DOWN);

	

	DelayTime_ms(1);	



}

/*******************************************************************************
**功能描述 ：EXTI配置函数
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void APP_ConfigureEXTI(void)
{
	
	/* 选择EXTI0做外部中断输入 */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTB,LL_EXTI_CONFIG_LINE0);	//key_shang
	LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* 选择EXTI0 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_0;
	/* 使能 */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* 选择中断模式 */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* 选择上升沿触发 */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
	/* 外部中断初始化 */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* 设置中断优先级 */
	NVIC_SetPriority(EXTI0_1_IRQn,0);
	/*使能中断*/
	NVIC_EnableIRQ(EXTI0_1_IRQn);

	/* 选择EXTI6做外部中断输入 */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE6);	//key_xia
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* 选择EXTI6 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_6;
	/* 使能 */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* 选择中断模式 */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* 选择上升沿触发 */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
	/* 外部中断初始化 */
	LL_EXTI_Init(&EXTI_InitStruct);	
		/* 设置中断优先级 */
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	/*使能中断*/
	NVIC_EnableIRQ(EXTI4_15_IRQn);


		/* 选择EXTI3做外部中断输入 */
//	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE11);	//key_dec
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* 选择EXTI3 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_11;
	/* 使能 */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* 选择中断模式 */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	
	/* 选择上升沿触发 */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
		
	/* 外部中断初始化 */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* 设置中断优先级 */
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	/*使能中断*/
	NVIC_EnableIRQ(EXTI4_15_IRQn);


	/* 选择EXTI8做外部中断输入 */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE8);	//key_inc
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* 选择EXTI8 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_8;
	/* 使能 */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* 选择中断模式 */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* 选择上升沿触发 */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
	/* 外部中断初始化 */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* 设置中断优先级 */
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	/*使能中断*/
	NVIC_EnableIRQ(EXTI4_15_IRQn);


	/* 选择EXTI7做外部中断输入 */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE7);	//usb
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* 选择EXTI7 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_7;
	/* 使能 */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* 选择中断模式 */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* 选择上升沿触发 */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING;
	/* 外部中断初始化 */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* 设置中断优先级 */
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	/*使能中断*/
	NVIC_EnableIRQ(EXTI4_15_IRQn);
	

	/* 选择EXTI2做外部中断输入 */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE2);	//mic
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* 选择EXTI2 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_2;
	/* 使能 */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* 选择中断模式 */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* 选择上升沿触发 */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING;
	/* 外部中断初始化 */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* 设置中断优先级 */
	NVIC_SetPriority(EXTI2_3_IRQn,0);
	/*使能中断*/
	NVIC_EnableIRQ(EXTI2_3_IRQn);

}

//-------------------------
void APP_PvdConfig(void)
{
	LL_EXTI_InitTypeDef EXTI_InitStruct;

  /* 使能PWR时钟 */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* 如果PB07作为检测源，此参数设置无效 */
  LL_PWR_SetPVDLevel(LL_PWR_PVDLEVEL_2);

  /* 滤波功能禁止 */
  LL_PWR_DisablePVDFilter();
  LL_PWR_SetPVDFilter(LL_PWR_PVD_FILTER_1CLOCK);

  /* PVD检测为 */
  LL_PWR_SetPVDSource(LL_PWR_PVD_SOURCE_VCC);

//-----------------------------
  /* 选择EXTI16 */
  EXTI_InitStruct.Line = LL_EXTI_LINE_16;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);
//---------------------------

  NVIC_SetPriority(PVD_IRQn, 1);
  NVIC_EnableIRQ(PVD_IRQn);

  /* 使能PVD */
  LL_PWR_EnablePVD();

}


//-----------------
//实测10000=2ms
void Delay( uint32_t nTime)
{
  while(nTime != 0)nTime--;
}

void DelayTime_ms(uint32_t MsCount)
 {
 	D_Timer1msFlag=0;
 	while(MsCount)
 	{
//	  Board_ClrWdt();
 		if(D_Timer1msFlag)
 		{
 			D_Timer1msFlag=0;
 		    MsCount--;
 	    }
 	}
 }
//--------


/*******************************************************************************
**功能描述 ：错误执行函数
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void Error_Handler(void)
{
  while(1)
  {
  printf("error");
  }
}

//--------------------------------
void APP_FlashWrite(void)
{
  /*解锁FLASH*/
  HAL_FLASH_Unlock();

  /*擦除FLASH*/
  APP_FlashErase();

  /*写FLASH*/
  APP_FlashProgram();

  /*锁定FLASH*/
  HAL_FLASH_Lock();


}
//------------
void APP_FlashErase(void)
{
  uint32_t PAGEError = 0;
  FLASH_EraseInitTypeDef EraseInitStruct;
  /*擦写类型FLASH_TYPEERASE_PAGEERASE=Page擦, FLASH_TYPEERASE_SECTORERASE=Sector擦*/
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGEERASE;  
  /*擦写起始地址*/
  EraseInitStruct.PageAddress = FLASH_USER_START_ADDR;
  /*需要擦写的页数量*/
  EraseInitStruct.NbPages  = 1;//sizeof(R_Hearting_NUM) / FLASH_PAGE_SIZE;
  /*执行page擦除,PAGEError返回擦写错误的page,返回0xFFFFFFFF,表示擦写成功*/
  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
  {
    Error_Handler();
  }
}
void APP_FlashProgram(void)
{
  /*flash写起始地址*/
  uint32_t flash_program_start = FLASH_USER_START_ADDR ;
  /*flash写结束地址*/
  uint32_t flash_program_end = (FLASH_USER_START_ADDR + 128);
  /*数组指针*/
  uint32_t *src = (uint32_t *)(&R_Hearting_NUM);

  while (flash_program_start < flash_program_end)
  {
    /*执行Program*/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_PAGE, flash_program_start, src) == HAL_OK)
    {
      /*flash起始指针指向第一个page*/
      flash_program_start += FLASH_PAGE_SIZE; 
      /*更新数据指针*/
      src += FLASH_PAGE_SIZE / 4;
    }
  }

}

void APP_FlashOBProgram(void)
{
  FLASH_OBProgramInitTypeDef OBInitCfg;
  if(READ_BIT(FLASH->OPTR, FLASH_OPTR_NRST_MODE) == 0)
  {
  HAL_FLASH_Unlock();/*解锁FLASH*/
  HAL_FLASH_OB_Unlock();/*解锁OPTION*/

  /*配置OPTION选项*/
  OBInitCfg.OptionType = OPTIONBYTE_USER;
  OBInitCfg.USERType = OB_USER_BOR_EN | OB_USER_BOR_LEV | OB_USER_IWDG_SW | OB_USER_WWDG_SW | OB_USER_NRST_MODE | OB_USER_nBOOT1;

  /*BOR不使能/BOR上升2.0,下降1.9/软件模式看门狗/仅复位输入/System memory作为启动区*/
  OBInitCfg.USERConfig = OB_BOR_ENABLE | OB_BOR_LEVEL_1p7_1p8 | OB_IWDG_SW | OB_WWDG_SW | OB_RESET_MODE_GPIO | OB_BOOT1_SYSTEM;

  /*BOR不使能/BOR上升3.2,下降3.1/软件模式看门狗/仅复位输入/System memory作为启动区*/
//  OBInitCfg.USERConfig = OB_BOR_DISABLE | OB_BOR_LEVEL_3p1_3p2 | OB_IWDG_SW | OB_WWDG_SW | OB_RESET_MODE_RESET | OB_BOOT1_SYSTEM;/*恢复OPTION*/

  /* 启动option byte编程 */
  HAL_FLASH_OBProgram(&OBInitCfg);

  HAL_FLASH_Lock();/*锁定FLASH*/
  HAL_FLASH_OB_Lock();/*锁定OPTION*/


  /*产生一个复位，option byte装载*/
  HAL_FLASH_OB_Launch();
  }
}


//-----------------
void APP_AdcEnable(void)
{
  /* 使能ADC */
  LL_ADC_Enable(ADC1);

  /* 使能ADC 稳定时间，最低8个ADC Clock */
  Delay(5);//10
}

//===============

/*******************************************************************************
**功能描述 ：：WWDG配置
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void WWDG_Config(void)
{
  /* 使能WWDG时钟 */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_WWDG);

  /*设置计数器*/
  LL_WWDG_SetCounter(WWDG, 0x7F);
  /*设置分频*/
  LL_WWDG_SetPrescaler(WWDG, LL_WWDG_PRESCALER_8);
  /*设置窗口值*/
  LL_WWDG_SetWindow(WWDG, 0x7F);
  /* 使能提前中断*/
  LL_WWDG_EnableIT_EWKUP(WWDG);

  /*设置中断优先级*/
  NVIC_SetPriority(WWDG_IRQn,0);
  /* 使能中断 */
  NVIC_EnableIRQ(WWDG_IRQn);
  /* 使能WWDG */
  LL_WWDG_Enable(WWDG);
}
/*******************************************************************************
**功能描述 ：iwdg配置
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void IWDG_Config(void)
{
  /* 使能LSI */
  LL_RCC_LSI_Enable();
  while (LL_RCC_LSI_IsReady() == 0U) {;}

  /* 使能IWDG */
  LL_IWDG_Enable(IWDG);
  /* 开启写权限 */
  LL_IWDG_EnableWriteAccess(IWDG);
  /* 设置IWDG分频 */
  LL_IWDG_SetPrescaler(IWDG, LL_IWDG_PRESCALER_32); // T=1MS
  /* 设置喂狗事件*/
  LL_IWDG_SetReloadCounter(IWDG, 4000); // 1ms*1000=1s
  /* IWDG初始化*/
  while (LL_IWDG_IsReady(IWDG) == 0U) {;}
  /*喂狗*/
  LL_IWDG_ReloadCounter(IWDG);
}


/*******************************************************************************
**功能描述 ：配置LPTIM单次模式
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void APP_ConfigLPTIM_OneShot(void)
{
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_LPTIM1);

	/*开启LSI*/
	LL_RCC_LSI_Enable();

	/*等待LSI就绪*/
	while(LL_RCC_LSI_IsReady() == 0)
	{}

	/*配置LSI为LPTIM时钟源*/
	LL_RCC_SetLPTIMClockSource(LL_RCC_LPTIM1_CLKSOURCE_LSI);
//---------------------
  /*配置LPTIM*/
  /*LPTIM预分频器128分频*/
  LL_LPTIM_SetPrescaler(LPTIM1,LL_LPTIM_PRESCALER_DIV128);

  /*LPTIM计数周期结束更新ARR*/
  LL_LPTIM_SetUpdateMode(LPTIM1,LL_LPTIM_UPDATE_MODE_ENDOFPERIOD);


  /*使能ARR中断*/
  LL_LPTIM_EnableIT_ARRM(LPTIM1);

  /*使能NVIC请求*/
  NVIC_EnableIRQ(LPTIM1_IRQn);
  NVIC_SetPriority(LPTIM1_IRQn,0);

  /*使能LPTIM*/
  LL_LPTIM_Enable(LPTIM1);

  /*配置重装载值：51=200ms*/
  LL_LPTIM_SetAutoReload(LPTIM1,800);//2s
//  LL_LPTIM_SetAutoReload(LPTIM1,75);//0.3s
}

void APP_LPTIM_OneShot(void)
{

/*失能LPTIM*/
LL_LPTIM_Disable(LPTIM1);
/*使能LPTIM*/
LL_LPTIM_Enable(LPTIM1);



/*延时60us*/
//APP_uDelay(60);
Delay(600);//实测小于460=60us定时器不会唤醒,600=76us,1000=126us

/*开启单次模式*/
LL_LPTIM_StartCounter(LPTIM1,LL_LPTIM_OPERATING_MODE_ONESHOT);
}
//-----------------

void APP_AdcCalibrate(void)
{
  __IO uint32_t wait_loop_index = 0;
  __IO uint32_t backup_setting_adc_dma_transfer = 0;
#if (USE_TIMEOUT == 1)
  uint32_t Timeout = 0;
#endif

  if (LL_ADC_IsEnabled(ADC1) == 0)
  {
    /* 校准时关闭ADC的DMA配置 */
    backup_setting_adc_dma_transfer = LL_ADC_REG_GetDMATransfer(ADC1);
    LL_ADC_REG_SetDMATransfer(ADC1, LL_ADC_REG_DMA_TRANSFER_NONE);

    /* 使能校准 */
    LL_ADC_StartCalibration(ADC1);

#if (USE_TIMEOUT == 1)
    Timeout = ADC_CALIBRATION_TIMEOUT_MS;
#endif

    while (LL_ADC_IsCalibrationOnGoing(ADC1) != 0)
    {
#if (USE_TIMEOUT == 1)
      /* 检测校准是否超时 */
      if (LL_SYSTICK_IsActiveCounterFlag())
      {
        if(Timeout-- == 0)
        {

        }
      }
#endif
    }

    /* ADC校准结束和使能ADC之间的延时最低4个ADC Clock */
    //LL_mDelay(1);
    Delay(10);//10
    /* 还原ADC的DMA配置 */
    LL_ADC_REG_SetDMATransfer(ADC1, backup_setting_adc_dma_transfer);
  }
}

void APP_DmaConfig(void)
{

  /* 使能DMA1 时钟 */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

  /* 使能syscfg 时钟 */
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_SYSCFG);

  /* ADC对应通道LL_DMA_CHANNEL_1 */
  SET_BIT(SYSCFG->CFGR3, 0x0);

  /* 配置DMA传输方向为外设到存储器 */
  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);

  /* 配置DMA优先级为高 */
  LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PRIORITY_HIGH);

  /* 配置DMA循环模式 */
  LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MODE_CIRCULAR);

  /* 配置DMA外设地址不变模式 */
  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PERIPH_NOINCREMENT);

  /* 配置DMA存储地址自增模式 */
  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MEMORY_INCREMENT);

  /* 配置DMA外设传输方式为字 */
  LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PDATAALIGN_WORD);

  /* 配置DMA存储器传输方式为字 */
  LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MDATAALIGN_WORD);

  /* 配置DMA传输长度为4 */
  LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, Nch);

  /* 配置DMA外设和存储器的地址 */
  LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_1, (uint32_t)&ADC1->DR,\
                         (uint32_t)ADCxConvertedDatas, LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1));

  /* 使能DMA传输完成中断 */
  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1);

  /* DMA中断配置 */
  NVIC_SetPriority(DMA1_Channel1_IRQn, 0);
  NVIC_EnableIRQ(DMA1_Channel1_IRQn);

  /* 使能DMA */
  LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);
}

//-------------
void APP_AdcConfig(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct;

  /* 配置ADC通道和管脚 */

  /* 使能GPIOA时钟 */
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);

  /* 配置管脚PA4/5/6/7为模拟输入 */
//  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4| LL_GPIO_PIN_5| LL_GPIO_PIN_6  \
//                     | LL_GPIO_PIN_7, LL_GPIO_MODE_ANALOG);
//  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_0, LL_GPIO_MODE_ANALOG);
//  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_1, LL_GPIO_MODE_ANALOG);
//  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_2, LL_GPIO_MODE_ANALOG);
//  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_ANALOG);


//  GPIO_InitStruct.Pin = LL_GPIO_PIN_1|LL_GPIO_PIN_2;
//  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
//  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
//  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//  GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
//  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
//  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
//  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);


  /* ADC通道和时钟源需在ADEN=0时配置，其余的需在ADSTART=0时配置 */
  /* 配置内部转换通道 */
  LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_PATH_INTERNAL_VREFINT);

  /* 设置ADC时钟 */
  LL_ADC_SetClock(ADC1, LL_ADC_CLOCK_SYNC_PCLK_DIV2);

  /* 设置12位分辨率 */
  LL_ADC_SetResolution(ADC1, LL_ADC_RESOLUTION_12B);

  /* 设置数据右对齐 */
  LL_ADC_SetResolution(ADC1, LL_ADC_DATA_ALIGN_RIGHT);

  /* 设置低功耗模式无 */
  LL_ADC_SetLowPowerMode(ADC1, LL_ADC_LP_MODE_NONE);

  /* 设置通道转换时间 */
  LL_ADC_SetSamplingTimeCommonChannels(ADC1, LL_ADC_SAMPLINGTIME_41CYCLES_5);

  /* 设置触发源为Software */
  LL_ADC_REG_SetTriggerSource(ADC1, LL_ADC_REG_TRIG_SOFTWARE);

  /* 设置转换模式为单次转换 */
  LL_ADC_REG_SetContinuousMode(ADC1, LL_ADC_REG_CONV_SINGLE);
//  LL_ADC_REG_SetContinuousMode(ADC1, LL_ADC_REG_CONV_CONTINUOUS);
  /* 设置DMA模式为循环 */
//  LL_ADC_REG_SetDMATransfer(ADC1, LL_ADC_REG_DMA_TRANSFER_UNLIMITED);

  /* 设置过载管理模式为覆盖上一个值 */
  LL_ADC_REG_SetOverrun(ADC1, LL_ADC_REG_OVR_DATA_OVERWRITTEN);

  /* 扫描方向为向上 */
  LL_ADC_REG_SetSequencerScanDirection(ADC1,LL_ADC_REG_SEQ_SCAN_DIR_BACKWARD);//LL_ADC_REG_SEQ_SCAN_DIR_FORWARD

  /* 设置非连续模式为不使能 */
  LL_ADC_REG_SetSequencerDiscont(ADC1, LL_ADC_REG_SEQ_DISCONT_DISABLE);

  /* 设置通道4/5/6/7为转换通道 */
//  LL_ADC_REG_SetSequencerChannels(ADC1,LL_ADC_CHANNEL_0 | LL_ADC_CHANNEL_1  \
//                                  | LL_ADC_CHANNEL_2 | LL_ADC_CHANNEL_6|LL_ADC_CHANNEL_VREFINT);
}

#if 1
void APP_ConfigADC_DMA(void)
{
	__IO uint32_t wait_loop_index = 0;
  __IO uint32_t backup_setting_adc_dma_transfer = 0;

  /* 复位ADC时钟 */
  LL_ADC_Reset(ADC1);

  /* 使能ADC1时钟 */
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_ADC1);

  /* ADC校准 */
  APP_AdcCalibrate();

  /* 配置DMA */
  APP_DmaConfig();

  /* 配置ADC参数 */
  APP_AdcConfig();

  /* 使能ADC */
  APP_AdcEnable();

  /* 开始ADC转换 */
  LL_ADC_REG_StartConversion(ADC1);


}
#endif

void APP_ConfigADC(void)
{

  /* 复位ADC时钟 */
  LL_ADC_Reset(ADC1);

  /* 使能ADC1时钟 */
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_ADC1);

  /* ADC校准 */
  APP_AdcCalibrate();

  /* 配置ADC参数 */
  APP_AdcConfig();
}

void APP_ConfigTim1(void)
{
  /* 使能TIM1时钟 */
  LL_APB1_GRP2_EnableClock(RCC_APBENR2_TIM1EN);

  /* 配置并开启TIM1计数模式 */

  /* 配置TIM1 */
  LL_TIM_InitTypeDef TIM1CountInit = {0};
  
  TIM1CountInit.ClockDivision       = LL_TIM_CLOCKDIVISION_DIV1; /* 时钟不分频 */
  TIM1CountInit.CounterMode         = LL_TIM_COUNTERMODE_UP;     /* 向上计数模式 */
  TIM1CountInit.Prescaler           = 24-1;                    /* 预分频值：8000 */
  TIM1CountInit.Autoreload          = 20-1;                    /* 自动重装载值：1000 */
  TIM1CountInit.RepetitionCounter   = 0;                         /* 重复计数值：0 */
  
  /* 初始化TIM1 */
  LL_TIM_Init(TIM1,&TIM1CountInit);
  
  /* 使能UPDATA中断 */
  LL_TIM_EnableIT_UPDATE(TIM1);
  
  /* 使能TIM1计数器 */
  LL_TIM_EnableCounter(TIM1);
  
  /* 开启UPDATA中断请求 */
  NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);
  NVIC_SetPriority(TIM1_BRK_UP_TRG_COM_IRQn,0);

}

void ADC_EnableChannel(unsigned char ch)
{
	switch(ch)
	{
		case 0:
		LL_ADC_REG_SetSequencerChannels(ADC1,LL_ADC_CHANNEL_0);break;
		case 1:
		LL_ADC_REG_SetSequencerChannels(ADC1,LL_ADC_CHANNEL_1);break;
		case 2:
		LL_ADC_REG_SetSequencerChannels(ADC1,LL_ADC_CHANNEL_2);break;
		case 3:
		LL_ADC_REG_SetSequencerChannels(ADC1,LL_ADC_CHANNEL_6);break;
		case 4:
		LL_ADC_REG_SetSequencerChannels(ADC1,LL_ADC_CHANNEL_VREFINT);break;
	}
//	APP_AdcEnable();
//	LL_ADC_REG_StartConversion(ADC1);
}


unsigned int GET_ADCValue(void)
{
	unsigned int uhADCxConvertedData;
	static unsigned i;
	APP_AdcEnable();
	LL_ADC_REG_StartConversion(ADC1);

	i=250;
	while(i--)
	{
	    if(LL_ADC_IsActiveFlag_EOS(ADC1))
	    {
	      LL_ADC_ClearFlag_EOS(ADC1);
	      uhADCxConvertedData = LL_ADC_REG_ReadConversionData12(ADC1);
	      //uhADCxConvertedData_Voltage_mVolt=__LL_ADC_CALC_VREFANALOG_VOLTAGE(uhADCxConvertedData, LL_ADC_RESOLUTION_12B);
	      break;
	    }
    }
return uhADCxConvertedData;
}


unsigned int ADC_GetData(uint32_t ADC_Channel,unsigned char count)
{
		D_ADWork_State__8888= 1;

    uint8_t channel = 0;
    uint32_t tmpBuff = 0;
    uint16_t AdcMAX = 0;
    uint16_t AdcMIN = 0xffff;
    uint16_t temp_value = 0;

    
    	
    //ADC_EnableChannel(ADC_Channel);//设置通道 如果通道没有改变可以屏蔽此处
    LL_ADC_REG_SetSequencerChannels(ADC1,ADC_Channel);
	temp_value = GET_ADCValue();//丢弃
	if(count==0)
	{
		D_ADWork_State__8888 = 0;
		return temp_value;
	}
    for (channel = 0; channel < (count+2); channel++)
    {
        temp_value = GET_ADCValue();
        if (temp_value > AdcMAX)
            AdcMAX = temp_value; //最大
        if (temp_value < AdcMIN)
            AdcMIN = temp_value; //最小
        tmpBuff += temp_value;
    }
    tmpBuff -= AdcMAX;           //去掉一个最大
    tmpBuff -= AdcMIN;           //去掉一个最小
    temp_value = (tmpBuff/count); //除以16,取平均值
    
    D_ADWork_State__8888 = 0;
    
    return temp_value;

    
}



/*******************************************************************************
**功能描述 ：配置TIM base
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void APP_ConfigTIM3_14Base(void)
{
  /*配置TIM14*/
  LL_TIM_InitTypeDef TIM14CountInit = {0};
	LL_TIM_InitTypeDef TIM3CountInit = {0};
  /***********************************************
  ** 输入时钟：    24000000
  ** 计数模式：    向上计数模式
  ** 时钟预分频：  2400
  ** 自动重装载值：1000
  ** 重复计数值：  0
  ************************************************/
  TIM14CountInit.ClockDivision       = LL_TIM_CLOCKDIVISION_DIV1;
  TIM14CountInit.CounterMode         = LL_TIM_COUNTERMODE_UP;
  TIM14CountInit.Prescaler           = 1-1;
  TIM14CountInit.Autoreload          = 160-1;//150K
  TIM14CountInit.RepetitionCounter   = 0;

  /*初始化TIM14*/
  LL_TIM_Init(TIM14,&TIM14CountInit);

  /*主输出使能*/
  LL_TIM_EnableAllOutputs(TIM14);

  /*使能TIM14计数器*/
  LL_TIM_EnableCounter(TIM14);


	TIM3CountInit.ClockDivision       = LL_TIM_CLOCKDIVISION_DIV1;
  TIM3CountInit.CounterMode         = LL_TIM_COUNTERMODE_UP;
  TIM3CountInit.Prescaler           = 1-1;
  TIM3CountInit.Autoreload          = 160-1;//150K
  TIM3CountInit.RepetitionCounter   = 0;

  /*初始化TIM3*/
  LL_TIM_Init(TIM3,&TIM3CountInit);

  /*主输出使能*/
  LL_TIM_EnableAllOutputs(TIM3);

  /*使能TIM3计数器*/
  LL_TIM_EnableCounter(TIM3);
}

void APP_ConfigPWMChannel(void)
{
  LL_GPIO_InitTypeDef TIM14CH1MapInit= {0};//PF0
  LL_TIM_OC_InitTypeDef TIM_OC_Initstruct ={0};

	/*使能TIM14、GPIO时钟*/
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_TIM14);
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOF);

  /*配置PF0为TIM14_CH1*/
  TIM14CH1MapInit.Pin        = LL_GPIO_PIN_1;
  TIM14CH1MapInit.Mode       = LL_GPIO_MODE_ALTERNATE;
  TIM14CH1MapInit.Alternate  = LL_GPIO_AF_13;
  LL_GPIO_Init(GPIOF,&TIM14CH1MapInit);


  /*配置PWM通道*/
  /***********************************************
  ** 通道模式：        PWM1
  ** 通道状态：        开启
  ** 通道有效极性：    高电平
  ** 通道空闲极性：    低电平
  ************************************************/
  TIM_OC_Initstruct.OCMode        = LL_TIM_OCMODE_PWM2;
  TIM_OC_Initstruct.OCState       = LL_TIM_OCSTATE_ENABLE;
  TIM_OC_Initstruct.OCPolarity    = LL_TIM_OCPOLARITY_LOW;
  TIM_OC_Initstruct.OCIdleState   = LL_TIM_OCIDLESTATE_LOW;
  /*通道1比较值:250*/
  TIM_OC_Initstruct.CompareValue  = 0;
  /*配置通道1*/
  LL_TIM_OC_Init(TIM14,LL_TIM_CHANNEL_CH1,&TIM_OC_Initstruct);

	/*
	----------------------------------------------------------
	*/
	LL_GPIO_InitTypeDef TIM3CH2MapInit= {0};//PB5
  LL_TIM_OC_InitTypeDef TIM_OC_Initstruct_B5 ={0};

	/*使能TIM3、GPIO时钟*/
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB);

  /*配置PB5为TIM3_CH2*/
  TIM3CH2MapInit.Pin        = LL_GPIO_PIN_5;
  TIM3CH2MapInit.Mode       = LL_GPIO_MODE_ALTERNATE;
  TIM3CH2MapInit.Alternate  = LL_GPIO_AF_1;
  LL_GPIO_Init(GPIOB,&TIM3CH2MapInit);


  /*配置PWM通道*/
  /***********************************************
  ** 通道模式：        PWM1
  ** 通道状态：        开启
  ** 通道有效极性：    高电平
  ** 通道空闲极性：    低电平
  ************************************************/
  TIM_OC_Initstruct_B5.OCMode        = LL_TIM_OCMODE_PWM2;
  TIM_OC_Initstruct_B5.OCState       = LL_TIM_OCSTATE_ENABLE;
  TIM_OC_Initstruct_B5.OCPolarity    = LL_TIM_OCPOLARITY_LOW;
  TIM_OC_Initstruct_B5.OCIdleState   = LL_TIM_OCIDLESTATE_LOW;
  /*通道1比较值:250*/
  TIM_OC_Initstruct_B5.CompareValue  = 0;
  /*配置通道1*/
  LL_TIM_OC_Init(TIM3,LL_TIM_CHANNEL_CH2,&TIM_OC_Initstruct_B5);

	APP_ConfigTIM3_14Base();
}

void PWM_updata(unsigned char Duty0,unsigned char Duty1 )
{
	LL_TIM_OC_SetCompareCH2(TIM3,Duty0);//BUCK
	LL_TIM_OC_SetCompareCH1(TIM14,Duty1);//BOOST
}


/*******************************************************************************
**功能描述 ：比较器初始化
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void APP_COMP1Init(void)
{
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
  /**比较器1的GPIO配置
  PA1   ------> 比较器1的Plus端输入
	*/
//  LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_ANALOG);

  /* 使能比较器1时钟*/
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_COMP1);

	/* 输入Plus端选择PA1 */
  LL_COMP_SetInputPlus(COMP1,LL_COMP_INPUT_PLUS_IO3);

  /* 输入Minus端选择VREFINT */
  LL_COMP_SetInputMinus(COMP1,LL_COMP_INPUT_MINUS_VREFINT);//LL_COMP_INPUT_MINUS_VREFINT

  /* 使能Scaler */
  LL_COMP_EnableScaler(COMP1);

  /* 迟滞关闭 */
  LL_COMP_SetInputHysteresis(COMP1,LL_COMP_HYSTERESIS_ENABLE);// LL_COMP_HYSTERESIS_DISABLE

  /* 极性不反向 */
  LL_COMP_SetOutputPolarity(COMP1,LL_COMP_OUTPUTPOL_NONINVERTED);

  /* 功耗模式快速 */
  LL_COMP_SetPowerMode(COMP1, LL_COMP_POWERMODE_HIGHSPEED);

  /* 窗口模式使能选择COMP1的Plus端输入 */
  LL_COMP_SetCommonWindowMode(__LL_COMP_COMMON_INSTANCE(COMP1), LL_COMP_WINDOWMODE_DISABLE);

  __IO uint32_t wait_loop_index = 0;
  wait_loop_index = (LL_COMP_DELAY_VOLTAGE_SCALER_STAB_US * (SystemCoreClock / (1000000 * 2)));
  while(wait_loop_index != 0)
  {
    wait_loop_index--;
  }

  /* 使能上升沿中断 */
//  LL_EXTI_EnableRisingTrig(LL_EXTI_LINE_17);
//  LL_EXTI_EnableFallingTrig(LL_EXTI_LINE_17);

  /* 使能中断 */
  LL_EXTI_EnableIT(LL_EXTI_LINE_17);

  NVIC_SetPriority(ADC_COMP_IRQn, 0);
  NVIC_EnableIRQ(ADC_COMP_IRQn);

  /* 使能比较器1 */
  LL_COMP_Enable(COMP1);
  wait_loop_index = ((LL_COMP_DELAY_STARTUP_US / 10UL) * (SystemCoreClock / (100000UL * 2UL)));
  while(wait_loop_index != 0UL)
  {
    wait_loop_index--;
  }
}

void APP_COMP2Init(void)
{
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
  /**比较器1的GPIO配置
  PA1   ------> 比较器1的Plus端输入
	*/
//  LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_ANALOG);

  /* 使能比较器1时钟*/
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_COMP2);

	/* 输入Plus端选择PA1 */
  LL_COMP_SetInputPlus(COMP2,LL_COMP_INPUT_PLUS_IO3);

  /* 输入Minus端选择VREFINT */
  LL_COMP_SetInputMinus(COMP2,LL_COMP_INPUT_MINUS_VREFINT);//LL_COMP_INPUT_MINUS_VREFINT

  /* 使能Scaler */
  LL_COMP_EnableScaler(COMP2);

  /* 迟滞关闭 */
  LL_COMP_SetInputHysteresis(COMP2,LL_COMP_HYSTERESIS_ENABLE);// LL_COMP_HYSTERESIS_DISABLE

  /* 极性不反向 */
  LL_COMP_SetOutputPolarity(COMP2,LL_COMP_OUTPUTPOL_NONINVERTED);

  /* 功耗模式快速 */
  LL_COMP_SetPowerMode(COMP2, LL_COMP_POWERMODE_HIGHSPEED);

  /* 窗口模式使能选择COMP1的Plus端输入 */
  LL_COMP_SetCommonWindowMode(__LL_COMP_COMMON_INSTANCE(COMP2), LL_COMP_WINDOWMODE_DISABLE);

  __IO uint32_t wait_loop_index = 0;
  wait_loop_index = (LL_COMP_DELAY_VOLTAGE_SCALER_STAB_US * (SystemCoreClock / (1000000 * 2)));
  while(wait_loop_index != 0)
  {
    wait_loop_index--;
  }

  /* 使能上升沿中断 */
//  LL_EXTI_EnableRisingTrig(LL_EXTI_LINE_18);
//  LL_EXTI_EnableFallingTrig(LL_EXTI_LINE_18);

  /* 使能中断 */
  LL_EXTI_EnableIT(LL_EXTI_LINE_18);

  NVIC_SetPriority(ADC_COMP_IRQn, 0);
  NVIC_EnableIRQ(ADC_COMP_IRQn);

  /* 使能比较器1 */
  LL_COMP_Enable(COMP2);
  wait_loop_index = ((LL_COMP_DELAY_STARTUP_US / 10UL) * (SystemCoreClock / (100000UL * 2UL)));
  while(wait_loop_index != 0UL)
  {
    wait_loop_index--;
  }
}


/*******************************************************************************
**功能描述 ：比较器时钟切换
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void APP_CompRccInit(void)
{
  /* 使能LSI */
  LL_RCC_LSI_Enable();

  /* 等待LSI稳定 */
  while(LL_RCC_LSI_IsReady() != 1)
  {
  }

  /* 使能PWR时钟 */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* 使能DBP */
  LL_PWR_EnableBkUpAccess();

  /* 使能LSC */
  LL_RCC_LSCO_Enable();

	/* 设置COMP的时钟源为LSC */
  LL_RCC_SetCOMPClockSource(LL_RCC_COMP1_CLKSOURCE_LSC);

	/* 设置COMP的时钟源为LSC */
  LL_RCC_SetCOMPClockSource(LL_RCC_COMP2_CLKSOURCE_LSC);
}

/*******************************************************************************
**功能描述 ：进入Stop模式
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void APP_EnterStop(void)
{

  /*使能PWR时钟*/
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  SET_BIT(PWR->CR1 ,PWR_CR1_VOS); //VOS=1(vdd=1.0)、VOS=0(vdd=1.2)


 /* 带低功耗调节器的停止模式 */
 LL_PWR_EnableLowPowerRunMode();
 /* 设置Cortex系统控制寄存器的SLEEPDEEP位 */
 LL_LPM_EnableDeepSleep();
 
 /* 等待中断指令 */
 __WFI();

 /* 复位Cortex系统控制寄存器的SLEEPDEEP位 */
 LL_LPM_EnableSleep();



}


/*******************************************************************************
**功能描述 ：系统时钟配置函数
**输入参数 ：
**输出参数 ：
*******************************************************************************/
void SystemClock_Config(void)
{
  /* 使能HSI */
  LL_RCC_HSI_Enable();
	LL_RCC_HSI_SetCalibFreq(LL_RCC_HSICALIBRATION_24MHz);
  while(LL_RCC_HSI_IsReady() != 1)
  {
  }

  /* 设置 AHB 分频*/
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  /* 配置HSISYS作为系统时钟源 */
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSISYS);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSISYS)
  {
  }

	LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

  /* 设置 APB1 分频*/
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  //LL_Init1msTick(24000000);
  LL_Init100usTick(24000000);
  

  /* 更新系统时钟全局变量SystemCoreClock(也可以通过调用SystemCoreClockUpdate函数更新) */
  LL_SetSystemCoreClock(24000000);
}

//======================

#define FLASH_UID_START_ADDR  0x1FFF0E00 //ID地址
typedef struct
{
  uint32_t arrA[7];
} NewDataType;                                                      //结构体定义
#define VarA (*(volatile NewDataType *)FLASH_UID_START_ADDR)       //Flash存储地址定义
uint32_t UID_data[7];
extern uint8_t VER_data[];



//用户回调函数，此处修改需要烧录的函数
void TBEF_data_CallBack(u8 *dataBuf, u16 len)
{
	//根据需求修改此处sFLASH_WriteBuffer
	//sFLASH_WriteBuffer(dataBuf, TBEF_W25QXX_StorageAddress + bytesStored, len);
	//bytesStored += len;
}



/************************ (C) COPYRIGHT Puya *****END OF FILE****/
