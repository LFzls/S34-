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
**�������� ��EXTI���ú���
**������� ��
**������� ��
*******************************************************************************/
void APP_ConfigureEXTI(void)
{
	
	/* ѡ��EXTI0���ⲿ�ж����� */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTB,LL_EXTI_CONFIG_LINE0);	//key_shang
	LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* ѡ��EXTI0 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_0;
	/* ʹ�� */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* ѡ���ж�ģʽ */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* ѡ�������ش��� */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
	/* �ⲿ�жϳ�ʼ�� */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* �����ж����ȼ� */
	NVIC_SetPriority(EXTI0_1_IRQn,0);
	/*ʹ���ж�*/
	NVIC_EnableIRQ(EXTI0_1_IRQn);

	/* ѡ��EXTI6���ⲿ�ж����� */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE6);	//key_xia
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* ѡ��EXTI6 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_6;
	/* ʹ�� */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* ѡ���ж�ģʽ */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* ѡ�������ش��� */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
	/* �ⲿ�жϳ�ʼ�� */
	LL_EXTI_Init(&EXTI_InitStruct);	
		/* �����ж����ȼ� */
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	/*ʹ���ж�*/
	NVIC_EnableIRQ(EXTI4_15_IRQn);


		/* ѡ��EXTI3���ⲿ�ж����� */
//	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE11);	//key_dec
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* ѡ��EXTI3 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_11;
	/* ʹ�� */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* ѡ���ж�ģʽ */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	
	/* ѡ�������ش��� */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
		
	/* �ⲿ�жϳ�ʼ�� */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* �����ж����ȼ� */
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	/*ʹ���ж�*/
	NVIC_EnableIRQ(EXTI4_15_IRQn);


	/* ѡ��EXTI8���ⲿ�ж����� */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE8);	//key_inc
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* ѡ��EXTI8 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_8;
	/* ʹ�� */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* ѡ���ж�ģʽ */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* ѡ�������ش��� */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
	/* �ⲿ�жϳ�ʼ�� */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* �����ж����ȼ� */
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	/*ʹ���ж�*/
	NVIC_EnableIRQ(EXTI4_15_IRQn);


	/* ѡ��EXTI7���ⲿ�ж����� */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE7);	//usb
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* ѡ��EXTI7 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_7;
	/* ʹ�� */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* ѡ���ж�ģʽ */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* ѡ�������ش��� */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING;
	/* �ⲿ�жϳ�ʼ�� */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* �����ж����ȼ� */
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	/*ʹ���ж�*/
	NVIC_EnableIRQ(EXTI4_15_IRQn);
	

	/* ѡ��EXTI2���ⲿ�ж����� */
	LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA,LL_EXTI_CONFIG_LINE2);	//mic
	//LL_EXTI_InitTypeDef EXTI_InitStruct;
	/* ѡ��EXTI2 */
	EXTI_InitStruct.Line = LL_EXTI_LINE_2;
	/* ʹ�� */
	EXTI_InitStruct.LineCommand = ENABLE;
	/* ѡ���ж�ģʽ */
	EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
	/* ѡ�������ش��� */
	EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING;
	/* �ⲿ�жϳ�ʼ�� */
	LL_EXTI_Init(&EXTI_InitStruct);	
	/* �����ж����ȼ� */
	NVIC_SetPriority(EXTI2_3_IRQn,0);
	/*ʹ���ж�*/
	NVIC_EnableIRQ(EXTI2_3_IRQn);

}

//-------------------------
void APP_PvdConfig(void)
{
	LL_EXTI_InitTypeDef EXTI_InitStruct;

  /* ʹ��PWRʱ�� */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* ���PB07��Ϊ���Դ���˲���������Ч */
  LL_PWR_SetPVDLevel(LL_PWR_PVDLEVEL_2);

  /* �˲����ܽ�ֹ */
  LL_PWR_DisablePVDFilter();
  LL_PWR_SetPVDFilter(LL_PWR_PVD_FILTER_1CLOCK);

  /* PVD���Ϊ */
  LL_PWR_SetPVDSource(LL_PWR_PVD_SOURCE_VCC);

//-----------------------------
  /* ѡ��EXTI16 */
  EXTI_InitStruct.Line = LL_EXTI_LINE_16;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);
//---------------------------

  NVIC_SetPriority(PVD_IRQn, 1);
  NVIC_EnableIRQ(PVD_IRQn);

  /* ʹ��PVD */
  LL_PWR_EnablePVD();

}


//-----------------
//ʵ��10000=2ms
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
**�������� ������ִ�к���
**������� ��
**������� ��
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
  /*����FLASH*/
  HAL_FLASH_Unlock();

  /*����FLASH*/
  APP_FlashErase();

  /*дFLASH*/
  APP_FlashProgram();

  /*����FLASH*/
  HAL_FLASH_Lock();


}
//------------
void APP_FlashErase(void)
{
  uint32_t PAGEError = 0;
  FLASH_EraseInitTypeDef EraseInitStruct;
  /*��д����FLASH_TYPEERASE_PAGEERASE=Page��, FLASH_TYPEERASE_SECTORERASE=Sector��*/
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGEERASE;  
  /*��д��ʼ��ַ*/
  EraseInitStruct.PageAddress = FLASH_USER_START_ADDR;
  /*��Ҫ��д��ҳ����*/
  EraseInitStruct.NbPages  = 1;//sizeof(R_Hearting_NUM) / FLASH_PAGE_SIZE;
  /*ִ��page����,PAGEError���ز�д�����page,����0xFFFFFFFF,��ʾ��д�ɹ�*/
  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
  {
    Error_Handler();
  }
}
void APP_FlashProgram(void)
{
  /*flashд��ʼ��ַ*/
  uint32_t flash_program_start = FLASH_USER_START_ADDR ;
  /*flashд������ַ*/
  uint32_t flash_program_end = (FLASH_USER_START_ADDR + 128);
  /*����ָ��*/
  uint32_t *src = (uint32_t *)(&R_Hearting_NUM);

  while (flash_program_start < flash_program_end)
  {
    /*ִ��Program*/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_PAGE, flash_program_start, src) == HAL_OK)
    {
      /*flash��ʼָ��ָ���һ��page*/
      flash_program_start += FLASH_PAGE_SIZE; 
      /*��������ָ��*/
      src += FLASH_PAGE_SIZE / 4;
    }
  }

}

void APP_FlashOBProgram(void)
{
  FLASH_OBProgramInitTypeDef OBInitCfg;
  if(READ_BIT(FLASH->OPTR, FLASH_OPTR_NRST_MODE) == 0)
  {
  HAL_FLASH_Unlock();/*����FLASH*/
  HAL_FLASH_OB_Unlock();/*����OPTION*/

  /*����OPTIONѡ��*/
  OBInitCfg.OptionType = OPTIONBYTE_USER;
  OBInitCfg.USERType = OB_USER_BOR_EN | OB_USER_BOR_LEV | OB_USER_IWDG_SW | OB_USER_WWDG_SW | OB_USER_NRST_MODE | OB_USER_nBOOT1;

  /*BOR��ʹ��/BOR����2.0,�½�1.9/���ģʽ���Ź�/����λ����/System memory��Ϊ������*/
  OBInitCfg.USERConfig = OB_BOR_ENABLE | OB_BOR_LEVEL_1p7_1p8 | OB_IWDG_SW | OB_WWDG_SW | OB_RESET_MODE_GPIO | OB_BOOT1_SYSTEM;

  /*BOR��ʹ��/BOR����3.2,�½�3.1/���ģʽ���Ź�/����λ����/System memory��Ϊ������*/
//  OBInitCfg.USERConfig = OB_BOR_DISABLE | OB_BOR_LEVEL_3p1_3p2 | OB_IWDG_SW | OB_WWDG_SW | OB_RESET_MODE_RESET | OB_BOOT1_SYSTEM;/*�ָ�OPTION*/

  /* ����option byte��� */
  HAL_FLASH_OBProgram(&OBInitCfg);

  HAL_FLASH_Lock();/*����FLASH*/
  HAL_FLASH_OB_Lock();/*����OPTION*/


  /*����һ����λ��option byteװ��*/
  HAL_FLASH_OB_Launch();
  }
}


//-----------------
void APP_AdcEnable(void)
{
  /* ʹ��ADC */
  LL_ADC_Enable(ADC1);

  /* ʹ��ADC �ȶ�ʱ�䣬���8��ADC Clock */
  Delay(5);//10
}

//===============

/*******************************************************************************
**�������� ����WWDG����
**������� ��
**������� ��
*******************************************************************************/
void WWDG_Config(void)
{
  /* ʹ��WWDGʱ�� */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_WWDG);

  /*���ü�����*/
  LL_WWDG_SetCounter(WWDG, 0x7F);
  /*���÷�Ƶ*/
  LL_WWDG_SetPrescaler(WWDG, LL_WWDG_PRESCALER_8);
  /*���ô���ֵ*/
  LL_WWDG_SetWindow(WWDG, 0x7F);
  /* ʹ����ǰ�ж�*/
  LL_WWDG_EnableIT_EWKUP(WWDG);

  /*�����ж����ȼ�*/
  NVIC_SetPriority(WWDG_IRQn,0);
  /* ʹ���ж� */
  NVIC_EnableIRQ(WWDG_IRQn);
  /* ʹ��WWDG */
  LL_WWDG_Enable(WWDG);
}
/*******************************************************************************
**�������� ��iwdg����
**������� ��
**������� ��
*******************************************************************************/
void IWDG_Config(void)
{
  /* ʹ��LSI */
  LL_RCC_LSI_Enable();
  while (LL_RCC_LSI_IsReady() == 0U) {;}

  /* ʹ��IWDG */
  LL_IWDG_Enable(IWDG);
  /* ����дȨ�� */
  LL_IWDG_EnableWriteAccess(IWDG);
  /* ����IWDG��Ƶ */
  LL_IWDG_SetPrescaler(IWDG, LL_IWDG_PRESCALER_32); // T=1MS
  /* ����ι���¼�*/
  LL_IWDG_SetReloadCounter(IWDG, 4000); // 1ms*1000=1s
  /* IWDG��ʼ��*/
  while (LL_IWDG_IsReady(IWDG) == 0U) {;}
  /*ι��*/
  LL_IWDG_ReloadCounter(IWDG);
}


/*******************************************************************************
**�������� ������LPTIM����ģʽ
**������� ��
**������� ��
*******************************************************************************/
void APP_ConfigLPTIM_OneShot(void)
{
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_LPTIM1);

	/*����LSI*/
	LL_RCC_LSI_Enable();

	/*�ȴ�LSI����*/
	while(LL_RCC_LSI_IsReady() == 0)
	{}

	/*����LSIΪLPTIMʱ��Դ*/
	LL_RCC_SetLPTIMClockSource(LL_RCC_LPTIM1_CLKSOURCE_LSI);
//---------------------
  /*����LPTIM*/
  /*LPTIMԤ��Ƶ��128��Ƶ*/
  LL_LPTIM_SetPrescaler(LPTIM1,LL_LPTIM_PRESCALER_DIV128);

  /*LPTIM�������ڽ�������ARR*/
  LL_LPTIM_SetUpdateMode(LPTIM1,LL_LPTIM_UPDATE_MODE_ENDOFPERIOD);


  /*ʹ��ARR�ж�*/
  LL_LPTIM_EnableIT_ARRM(LPTIM1);

  /*ʹ��NVIC����*/
  NVIC_EnableIRQ(LPTIM1_IRQn);
  NVIC_SetPriority(LPTIM1_IRQn,0);

  /*ʹ��LPTIM*/
  LL_LPTIM_Enable(LPTIM1);

  /*������װ��ֵ��51=200ms*/
  LL_LPTIM_SetAutoReload(LPTIM1,800);//2s
//  LL_LPTIM_SetAutoReload(LPTIM1,75);//0.3s
}

void APP_LPTIM_OneShot(void)
{

/*ʧ��LPTIM*/
LL_LPTIM_Disable(LPTIM1);
/*ʹ��LPTIM*/
LL_LPTIM_Enable(LPTIM1);



/*��ʱ60us*/
//APP_uDelay(60);
Delay(600);//ʵ��С��460=60us��ʱ�����ỽ��,600=76us,1000=126us

/*��������ģʽ*/
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
    /* У׼ʱ�ر�ADC��DMA���� */
    backup_setting_adc_dma_transfer = LL_ADC_REG_GetDMATransfer(ADC1);
    LL_ADC_REG_SetDMATransfer(ADC1, LL_ADC_REG_DMA_TRANSFER_NONE);

    /* ʹ��У׼ */
    LL_ADC_StartCalibration(ADC1);

#if (USE_TIMEOUT == 1)
    Timeout = ADC_CALIBRATION_TIMEOUT_MS;
#endif

    while (LL_ADC_IsCalibrationOnGoing(ADC1) != 0)
    {
#if (USE_TIMEOUT == 1)
      /* ���У׼�Ƿ�ʱ */
      if (LL_SYSTICK_IsActiveCounterFlag())
      {
        if(Timeout-- == 0)
        {

        }
      }
#endif
    }

    /* ADCУ׼������ʹ��ADC֮�����ʱ���4��ADC Clock */
    //LL_mDelay(1);
    Delay(10);//10
    /* ��ԭADC��DMA���� */
    LL_ADC_REG_SetDMATransfer(ADC1, backup_setting_adc_dma_transfer);
  }
}

void APP_DmaConfig(void)
{

  /* ʹ��DMA1 ʱ�� */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

  /* ʹ��syscfg ʱ�� */
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_SYSCFG);

  /* ADC��Ӧͨ��LL_DMA_CHANNEL_1 */
  SET_BIT(SYSCFG->CFGR3, 0x0);

  /* ����DMA���䷽��Ϊ���赽�洢�� */
  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);

  /* ����DMA���ȼ�Ϊ�� */
  LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PRIORITY_HIGH);

  /* ����DMAѭ��ģʽ */
  LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MODE_CIRCULAR);

  /* ����DMA�����ַ����ģʽ */
  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PERIPH_NOINCREMENT);

  /* ����DMA�洢��ַ����ģʽ */
  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MEMORY_INCREMENT);

  /* ����DMA���贫�䷽ʽΪ�� */
  LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PDATAALIGN_WORD);

  /* ����DMA�洢�����䷽ʽΪ�� */
  LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MDATAALIGN_WORD);

  /* ����DMA���䳤��Ϊ4 */
  LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, Nch);

  /* ����DMA����ʹ洢���ĵ�ַ */
  LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_1, (uint32_t)&ADC1->DR,\
                         (uint32_t)ADCxConvertedDatas, LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1));

  /* ʹ��DMA��������ж� */
  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1);

  /* DMA�ж����� */
  NVIC_SetPriority(DMA1_Channel1_IRQn, 0);
  NVIC_EnableIRQ(DMA1_Channel1_IRQn);

  /* ʹ��DMA */
  LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);
}

//-------------
void APP_AdcConfig(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct;

  /* ����ADCͨ���͹ܽ� */

  /* ʹ��GPIOAʱ�� */
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);

  /* ���ùܽ�PA4/5/6/7Ϊģ������ */
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


  /* ADCͨ����ʱ��Դ����ADEN=0ʱ���ã����������ADSTART=0ʱ���� */
  /* �����ڲ�ת��ͨ�� */
  LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_PATH_INTERNAL_VREFINT);

  /* ����ADCʱ�� */
  LL_ADC_SetClock(ADC1, LL_ADC_CLOCK_SYNC_PCLK_DIV2);

  /* ����12λ�ֱ��� */
  LL_ADC_SetResolution(ADC1, LL_ADC_RESOLUTION_12B);

  /* ���������Ҷ��� */
  LL_ADC_SetResolution(ADC1, LL_ADC_DATA_ALIGN_RIGHT);

  /* ���õ͹���ģʽ�� */
  LL_ADC_SetLowPowerMode(ADC1, LL_ADC_LP_MODE_NONE);

  /* ����ͨ��ת��ʱ�� */
  LL_ADC_SetSamplingTimeCommonChannels(ADC1, LL_ADC_SAMPLINGTIME_41CYCLES_5);

  /* ���ô���ԴΪSoftware */
  LL_ADC_REG_SetTriggerSource(ADC1, LL_ADC_REG_TRIG_SOFTWARE);

  /* ����ת��ģʽΪ����ת�� */
  LL_ADC_REG_SetContinuousMode(ADC1, LL_ADC_REG_CONV_SINGLE);
//  LL_ADC_REG_SetContinuousMode(ADC1, LL_ADC_REG_CONV_CONTINUOUS);
  /* ����DMAģʽΪѭ�� */
//  LL_ADC_REG_SetDMATransfer(ADC1, LL_ADC_REG_DMA_TRANSFER_UNLIMITED);

  /* ���ù��ع���ģʽΪ������һ��ֵ */
  LL_ADC_REG_SetOverrun(ADC1, LL_ADC_REG_OVR_DATA_OVERWRITTEN);

  /* ɨ�跽��Ϊ���� */
  LL_ADC_REG_SetSequencerScanDirection(ADC1,LL_ADC_REG_SEQ_SCAN_DIR_BACKWARD);//LL_ADC_REG_SEQ_SCAN_DIR_FORWARD

  /* ���÷�����ģʽΪ��ʹ�� */
  LL_ADC_REG_SetSequencerDiscont(ADC1, LL_ADC_REG_SEQ_DISCONT_DISABLE);

  /* ����ͨ��4/5/6/7Ϊת��ͨ�� */
//  LL_ADC_REG_SetSequencerChannels(ADC1,LL_ADC_CHANNEL_0 | LL_ADC_CHANNEL_1  \
//                                  | LL_ADC_CHANNEL_2 | LL_ADC_CHANNEL_6|LL_ADC_CHANNEL_VREFINT);
}

#if 1
void APP_ConfigADC_DMA(void)
{
	__IO uint32_t wait_loop_index = 0;
  __IO uint32_t backup_setting_adc_dma_transfer = 0;

  /* ��λADCʱ�� */
  LL_ADC_Reset(ADC1);

  /* ʹ��ADC1ʱ�� */
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_ADC1);

  /* ADCУ׼ */
  APP_AdcCalibrate();

  /* ����DMA */
  APP_DmaConfig();

  /* ����ADC���� */
  APP_AdcConfig();

  /* ʹ��ADC */
  APP_AdcEnable();

  /* ��ʼADCת�� */
  LL_ADC_REG_StartConversion(ADC1);


}
#endif

void APP_ConfigADC(void)
{

  /* ��λADCʱ�� */
  LL_ADC_Reset(ADC1);

  /* ʹ��ADC1ʱ�� */
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_ADC1);

  /* ADCУ׼ */
  APP_AdcCalibrate();

  /* ����ADC���� */
  APP_AdcConfig();
}

void APP_ConfigTim1(void)
{
  /* ʹ��TIM1ʱ�� */
  LL_APB1_GRP2_EnableClock(RCC_APBENR2_TIM1EN);

  /* ���ò�����TIM1����ģʽ */

  /* ����TIM1 */
  LL_TIM_InitTypeDef TIM1CountInit = {0};
  
  TIM1CountInit.ClockDivision       = LL_TIM_CLOCKDIVISION_DIV1; /* ʱ�Ӳ���Ƶ */
  TIM1CountInit.CounterMode         = LL_TIM_COUNTERMODE_UP;     /* ���ϼ���ģʽ */
  TIM1CountInit.Prescaler           = 24-1;                    /* Ԥ��Ƶֵ��8000 */
  TIM1CountInit.Autoreload          = 20-1;                    /* �Զ���װ��ֵ��1000 */
  TIM1CountInit.RepetitionCounter   = 0;                         /* �ظ�����ֵ��0 */
  
  /* ��ʼ��TIM1 */
  LL_TIM_Init(TIM1,&TIM1CountInit);
  
  /* ʹ��UPDATA�ж� */
  LL_TIM_EnableIT_UPDATE(TIM1);
  
  /* ʹ��TIM1������ */
  LL_TIM_EnableCounter(TIM1);
  
  /* ����UPDATA�ж����� */
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

    
    	
    //ADC_EnableChannel(ADC_Channel);//����ͨ�� ���ͨ��û�иı�������δ˴�
    LL_ADC_REG_SetSequencerChannels(ADC1,ADC_Channel);
	temp_value = GET_ADCValue();//����
	if(count==0)
	{
		D_ADWork_State__8888 = 0;
		return temp_value;
	}
    for (channel = 0; channel < (count+2); channel++)
    {
        temp_value = GET_ADCValue();
        if (temp_value > AdcMAX)
            AdcMAX = temp_value; //���
        if (temp_value < AdcMIN)
            AdcMIN = temp_value; //��С
        tmpBuff += temp_value;
    }
    tmpBuff -= AdcMAX;           //ȥ��һ�����
    tmpBuff -= AdcMIN;           //ȥ��һ����С
    temp_value = (tmpBuff/count); //����16,ȡƽ��ֵ
    
    D_ADWork_State__8888 = 0;
    
    return temp_value;

    
}



/*******************************************************************************
**�������� ������TIM base
**������� ��
**������� ��
*******************************************************************************/
void APP_ConfigTIM3_14Base(void)
{
  /*����TIM14*/
  LL_TIM_InitTypeDef TIM14CountInit = {0};
	LL_TIM_InitTypeDef TIM3CountInit = {0};
  /***********************************************
  ** ����ʱ�ӣ�    24000000
  ** ����ģʽ��    ���ϼ���ģʽ
  ** ʱ��Ԥ��Ƶ��  2400
  ** �Զ���װ��ֵ��1000
  ** �ظ�����ֵ��  0
  ************************************************/
  TIM14CountInit.ClockDivision       = LL_TIM_CLOCKDIVISION_DIV1;
  TIM14CountInit.CounterMode         = LL_TIM_COUNTERMODE_UP;
  TIM14CountInit.Prescaler           = 1-1;
  TIM14CountInit.Autoreload          = 160-1;//150K
  TIM14CountInit.RepetitionCounter   = 0;

  /*��ʼ��TIM14*/
  LL_TIM_Init(TIM14,&TIM14CountInit);

  /*�����ʹ��*/
  LL_TIM_EnableAllOutputs(TIM14);

  /*ʹ��TIM14������*/
  LL_TIM_EnableCounter(TIM14);


	TIM3CountInit.ClockDivision       = LL_TIM_CLOCKDIVISION_DIV1;
  TIM3CountInit.CounterMode         = LL_TIM_COUNTERMODE_UP;
  TIM3CountInit.Prescaler           = 1-1;
  TIM3CountInit.Autoreload          = 160-1;//150K
  TIM3CountInit.RepetitionCounter   = 0;

  /*��ʼ��TIM3*/
  LL_TIM_Init(TIM3,&TIM3CountInit);

  /*�����ʹ��*/
  LL_TIM_EnableAllOutputs(TIM3);

  /*ʹ��TIM3������*/
  LL_TIM_EnableCounter(TIM3);
}

void APP_ConfigPWMChannel(void)
{
  LL_GPIO_InitTypeDef TIM14CH1MapInit= {0};//PF0
  LL_TIM_OC_InitTypeDef TIM_OC_Initstruct ={0};

	/*ʹ��TIM14��GPIOʱ��*/
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_TIM14);
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOF);

  /*����PF0ΪTIM14_CH1*/
  TIM14CH1MapInit.Pin        = LL_GPIO_PIN_1;
  TIM14CH1MapInit.Mode       = LL_GPIO_MODE_ALTERNATE;
  TIM14CH1MapInit.Alternate  = LL_GPIO_AF_13;
  LL_GPIO_Init(GPIOF,&TIM14CH1MapInit);


  /*����PWMͨ��*/
  /***********************************************
  ** ͨ��ģʽ��        PWM1
  ** ͨ��״̬��        ����
  ** ͨ����Ч���ԣ�    �ߵ�ƽ
  ** ͨ�����м��ԣ�    �͵�ƽ
  ************************************************/
  TIM_OC_Initstruct.OCMode        = LL_TIM_OCMODE_PWM2;
  TIM_OC_Initstruct.OCState       = LL_TIM_OCSTATE_ENABLE;
  TIM_OC_Initstruct.OCPolarity    = LL_TIM_OCPOLARITY_LOW;
  TIM_OC_Initstruct.OCIdleState   = LL_TIM_OCIDLESTATE_LOW;
  /*ͨ��1�Ƚ�ֵ:250*/
  TIM_OC_Initstruct.CompareValue  = 0;
  /*����ͨ��1*/
  LL_TIM_OC_Init(TIM14,LL_TIM_CHANNEL_CH1,&TIM_OC_Initstruct);

	/*
	----------------------------------------------------------
	*/
	LL_GPIO_InitTypeDef TIM3CH2MapInit= {0};//PB5
  LL_TIM_OC_InitTypeDef TIM_OC_Initstruct_B5 ={0};

	/*ʹ��TIM3��GPIOʱ��*/
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB);

  /*����PB5ΪTIM3_CH2*/
  TIM3CH2MapInit.Pin        = LL_GPIO_PIN_5;
  TIM3CH2MapInit.Mode       = LL_GPIO_MODE_ALTERNATE;
  TIM3CH2MapInit.Alternate  = LL_GPIO_AF_1;
  LL_GPIO_Init(GPIOB,&TIM3CH2MapInit);


  /*����PWMͨ��*/
  /***********************************************
  ** ͨ��ģʽ��        PWM1
  ** ͨ��״̬��        ����
  ** ͨ����Ч���ԣ�    �ߵ�ƽ
  ** ͨ�����м��ԣ�    �͵�ƽ
  ************************************************/
  TIM_OC_Initstruct_B5.OCMode        = LL_TIM_OCMODE_PWM2;
  TIM_OC_Initstruct_B5.OCState       = LL_TIM_OCSTATE_ENABLE;
  TIM_OC_Initstruct_B5.OCPolarity    = LL_TIM_OCPOLARITY_LOW;
  TIM_OC_Initstruct_B5.OCIdleState   = LL_TIM_OCIDLESTATE_LOW;
  /*ͨ��1�Ƚ�ֵ:250*/
  TIM_OC_Initstruct_B5.CompareValue  = 0;
  /*����ͨ��1*/
  LL_TIM_OC_Init(TIM3,LL_TIM_CHANNEL_CH2,&TIM_OC_Initstruct_B5);

	APP_ConfigTIM3_14Base();
}

void PWM_updata(unsigned char Duty0,unsigned char Duty1 )
{
	LL_TIM_OC_SetCompareCH2(TIM3,Duty0);//BUCK
	LL_TIM_OC_SetCompareCH1(TIM14,Duty1);//BOOST
}


/*******************************************************************************
**�������� ���Ƚ�����ʼ��
**������� ��
**������� ��
*******************************************************************************/
void APP_COMP1Init(void)
{
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
  /**�Ƚ���1��GPIO����
  PA1   ------> �Ƚ���1��Plus������
	*/
//  LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_ANALOG);

  /* ʹ�ܱȽ���1ʱ��*/
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_COMP1);

	/* ����Plus��ѡ��PA1 */
  LL_COMP_SetInputPlus(COMP1,LL_COMP_INPUT_PLUS_IO3);

  /* ����Minus��ѡ��VREFINT */
  LL_COMP_SetInputMinus(COMP1,LL_COMP_INPUT_MINUS_VREFINT);//LL_COMP_INPUT_MINUS_VREFINT

  /* ʹ��Scaler */
  LL_COMP_EnableScaler(COMP1);

  /* ���͹ر� */
  LL_COMP_SetInputHysteresis(COMP1,LL_COMP_HYSTERESIS_ENABLE);// LL_COMP_HYSTERESIS_DISABLE

  /* ���Բ����� */
  LL_COMP_SetOutputPolarity(COMP1,LL_COMP_OUTPUTPOL_NONINVERTED);

  /* ����ģʽ���� */
  LL_COMP_SetPowerMode(COMP1, LL_COMP_POWERMODE_HIGHSPEED);

  /* ����ģʽʹ��ѡ��COMP1��Plus������ */
  LL_COMP_SetCommonWindowMode(__LL_COMP_COMMON_INSTANCE(COMP1), LL_COMP_WINDOWMODE_DISABLE);

  __IO uint32_t wait_loop_index = 0;
  wait_loop_index = (LL_COMP_DELAY_VOLTAGE_SCALER_STAB_US * (SystemCoreClock / (1000000 * 2)));
  while(wait_loop_index != 0)
  {
    wait_loop_index--;
  }

  /* ʹ���������ж� */
//  LL_EXTI_EnableRisingTrig(LL_EXTI_LINE_17);
//  LL_EXTI_EnableFallingTrig(LL_EXTI_LINE_17);

  /* ʹ���ж� */
  LL_EXTI_EnableIT(LL_EXTI_LINE_17);

  NVIC_SetPriority(ADC_COMP_IRQn, 0);
  NVIC_EnableIRQ(ADC_COMP_IRQn);

  /* ʹ�ܱȽ���1 */
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
  /**�Ƚ���1��GPIO����
  PA1   ------> �Ƚ���1��Plus������
	*/
//  LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_ANALOG);

  /* ʹ�ܱȽ���1ʱ��*/
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_COMP2);

	/* ����Plus��ѡ��PA1 */
  LL_COMP_SetInputPlus(COMP2,LL_COMP_INPUT_PLUS_IO3);

  /* ����Minus��ѡ��VREFINT */
  LL_COMP_SetInputMinus(COMP2,LL_COMP_INPUT_MINUS_VREFINT);//LL_COMP_INPUT_MINUS_VREFINT

  /* ʹ��Scaler */
  LL_COMP_EnableScaler(COMP2);

  /* ���͹ر� */
  LL_COMP_SetInputHysteresis(COMP2,LL_COMP_HYSTERESIS_ENABLE);// LL_COMP_HYSTERESIS_DISABLE

  /* ���Բ����� */
  LL_COMP_SetOutputPolarity(COMP2,LL_COMP_OUTPUTPOL_NONINVERTED);

  /* ����ģʽ���� */
  LL_COMP_SetPowerMode(COMP2, LL_COMP_POWERMODE_HIGHSPEED);

  /* ����ģʽʹ��ѡ��COMP1��Plus������ */
  LL_COMP_SetCommonWindowMode(__LL_COMP_COMMON_INSTANCE(COMP2), LL_COMP_WINDOWMODE_DISABLE);

  __IO uint32_t wait_loop_index = 0;
  wait_loop_index = (LL_COMP_DELAY_VOLTAGE_SCALER_STAB_US * (SystemCoreClock / (1000000 * 2)));
  while(wait_loop_index != 0)
  {
    wait_loop_index--;
  }

  /* ʹ���������ж� */
//  LL_EXTI_EnableRisingTrig(LL_EXTI_LINE_18);
//  LL_EXTI_EnableFallingTrig(LL_EXTI_LINE_18);

  /* ʹ���ж� */
  LL_EXTI_EnableIT(LL_EXTI_LINE_18);

  NVIC_SetPriority(ADC_COMP_IRQn, 0);
  NVIC_EnableIRQ(ADC_COMP_IRQn);

  /* ʹ�ܱȽ���1 */
  LL_COMP_Enable(COMP2);
  wait_loop_index = ((LL_COMP_DELAY_STARTUP_US / 10UL) * (SystemCoreClock / (100000UL * 2UL)));
  while(wait_loop_index != 0UL)
  {
    wait_loop_index--;
  }
}


/*******************************************************************************
**�������� ���Ƚ���ʱ���л�
**������� ��
**������� ��
*******************************************************************************/
void APP_CompRccInit(void)
{
  /* ʹ��LSI */
  LL_RCC_LSI_Enable();

  /* �ȴ�LSI�ȶ� */
  while(LL_RCC_LSI_IsReady() != 1)
  {
  }

  /* ʹ��PWRʱ�� */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* ʹ��DBP */
  LL_PWR_EnableBkUpAccess();

  /* ʹ��LSC */
  LL_RCC_LSCO_Enable();

	/* ����COMP��ʱ��ԴΪLSC */
  LL_RCC_SetCOMPClockSource(LL_RCC_COMP1_CLKSOURCE_LSC);

	/* ����COMP��ʱ��ԴΪLSC */
  LL_RCC_SetCOMPClockSource(LL_RCC_COMP2_CLKSOURCE_LSC);
}

/*******************************************************************************
**�������� ������Stopģʽ
**������� ��
**������� ��
*******************************************************************************/
void APP_EnterStop(void)
{

  /*ʹ��PWRʱ��*/
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  SET_BIT(PWR->CR1 ,PWR_CR1_VOS); //VOS=1(vdd=1.0)��VOS=0(vdd=1.2)


 /* ���͹��ĵ�������ֹͣģʽ */
 LL_PWR_EnableLowPowerRunMode();
 /* ����Cortexϵͳ���ƼĴ�����SLEEPDEEPλ */
 LL_LPM_EnableDeepSleep();
 
 /* �ȴ��ж�ָ�� */
 __WFI();

 /* ��λCortexϵͳ���ƼĴ�����SLEEPDEEPλ */
 LL_LPM_EnableSleep();



}


/*******************************************************************************
**�������� ��ϵͳʱ�����ú���
**������� ��
**������� ��
*******************************************************************************/
void SystemClock_Config(void)
{
  /* ʹ��HSI */
  LL_RCC_HSI_Enable();
	LL_RCC_HSI_SetCalibFreq(LL_RCC_HSICALIBRATION_24MHz);
  while(LL_RCC_HSI_IsReady() != 1)
  {
  }

  /* ���� AHB ��Ƶ*/
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  /* ����HSISYS��Ϊϵͳʱ��Դ */
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSISYS);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSISYS)
  {
  }

	LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

  /* ���� APB1 ��Ƶ*/
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  //LL_Init1msTick(24000000);
  LL_Init100usTick(24000000);
  

  /* ����ϵͳʱ��ȫ�ֱ���SystemCoreClock(Ҳ����ͨ������SystemCoreClockUpdate��������) */
  LL_SetSystemCoreClock(24000000);
}

//======================

#define FLASH_UID_START_ADDR  0x1FFF0E00 //ID��ַ
typedef struct
{
  uint32_t arrA[7];
} NewDataType;                                                      //�ṹ�嶨��
#define VarA (*(volatile NewDataType *)FLASH_UID_START_ADDR)       //Flash�洢��ַ����
uint32_t UID_data[7];
extern uint8_t VER_data[];



//�û��ص��������˴��޸���Ҫ��¼�ĺ���
void TBEF_data_CallBack(u8 *dataBuf, u16 len)
{
	//���������޸Ĵ˴�sFLASH_WriteBuffer
	//sFLASH_WriteBuffer(dataBuf, TBEF_W25QXX_StorageAddress + bytesStored, len);
	//bytesStored += len;
}



/************************ (C) COPYRIGHT Puya *****END OF FILE****/
