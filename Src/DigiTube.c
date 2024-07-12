#include "DigiTube.h"
#include "bsp.h"
#include "main.h"

#include "py32c616xx_ll_Start_Kit.h"

uint8_t R_DigiTube_Seq_Buf;

uint8_t DigiTubeCtr_State[13][8];
uint8_t DigiTubeCtr_State_COM;

uint8_t DigiTubeCtr_State_Level[13][8];
uint8_t DigiTubeCtr_State_COM_Level;

uint8_t DigiTubeCtr_Level1_State;//M4 L5 M5 M7 K1 L1 M1 A1 B1 C1 D1 E1 F1 G1 H1 J1 I1
uint8_t DigiTubeCtr_Level2_State;//M8 A8 
uint8_t DigiTubeCtr_Level3_State;//L8 B8 
uint8_t DigiTubeCtr_Level4_State;//K8 C8 H5 I5 J5 K5 K2 L2 M2 A2 B2 C2 D2 E2 F2 G2 H2 J2 I2
uint8_t DigiTubeCtr_Level5_State;//J8 D8
uint8_t DigiTubeCtr_Level6_State;//I8 E8 I4 J4 K4 L4 A3 B3 C3 D3 E3 F3 G3 H3 M6 J3 K3 L3 M3 H4 F4 E4 A4 G4 D4 B4 C4 F5 E5 A5 G5 D5 B5 C5
uint8_t DigiTubeCtr_Level7_State;//H8 K6 G8 K6 L6 F8 
uint8_t DigiTubeCtr_Level8_State;//M7 I6 A6 F6 B6 G6 F7 A7 G7 B7 L7
uint8_t DigiTubeCtr_Level9_State;//J6 E6 D6 C6 H6 E7 D7 C7 H7
uint8_t DigiTubeCtr_Level10_State;//I7 J7 K7 

void DigiTubeCtr_Seq(void)//timer 1MS
{
	R_DigiTube_Seq_Buf ++;
	if(R_DigiTube_Seq_Buf > C_DigiTube_Total)
	{
		R_DigiTube_Seq_Buf = C_DigiTube_Start;
	}

}

void DigiTubeCtr_Play(void)
{

	DigiTubeCtr_State_COM = R_DigiTube_Seq_Buf;
	DigiTubeCtr_State_COM_Level = R_DigiTube_Seq_Buf;
	
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	
	
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);	
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);	
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[12][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[12][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[11][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[11][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[10][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[10][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[9][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[9][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[8][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[8][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[7][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[7][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[6][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[6][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[5][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[5][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[4][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[4][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[3][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[3][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[2][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[2][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[1][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[1][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State[0][DigiTubeCtr_State_COM]&&DigiTubeCtr_State_Level[0][DigiTubeCtr_State_COM_Level])
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	else	
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	if(DigiTubeCtr_State_COM==0)
	{
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	}
	else if(DigiTubeCtr_State_COM==1)
	{
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	}		
	else if(DigiTubeCtr_State_COM==2)
	{
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	}
	else if(DigiTubeCtr_State_COM==3)
	{
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	}
	else if(DigiTubeCtr_State_COM==4)
	{
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	}
	else if(DigiTubeCtr_State_COM==5)
	{
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	}
	else if(DigiTubeCtr_State_COM==6)
	{
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	}
	else if(DigiTubeCtr_State_COM==7)
	{
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
		
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
		LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
		LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	}


	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);

	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);

	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);

}

void DigiTube_DianLiang_Ctr(uint8_t DigiTube_DianLiang_Inside_Flag,uint8_t DigiTube_DianLiang_Outside_Level)
{
	if(DigiTube_DianLiang_Inside_Flag==1)
	{
		DigiTubeCtr_M4_State = DigiTube_State_On;
		DigiTubeCtr_L5_State = DigiTube_State_On;
		DigiTubeCtr_M5_State = DigiTube_State_On;
		DigiTubeCtr_M6_State = DigiTube_State_On;
		DigiTubeCtr_K1_State = DigiTube_State_On;
		DigiTubeCtr_L1_State = DigiTube_State_On;
		DigiTubeCtr_M1_State = DigiTube_State_On;
		DigiTubeCtr_J1_State = DigiTube_State_On;
		DigiTubeCtr_I1_State = DigiTube_State_On;

	}
	else
	{
		DigiTubeCtr_M4_State = DigiTube_State_Off;
		DigiTubeCtr_L5_State = DigiTube_State_Off;
		DigiTubeCtr_M5_State = DigiTube_State_Off;
		DigiTubeCtr_M6_State = DigiTube_State_Off;
		DigiTubeCtr_K1_State = DigiTube_State_Off;
		DigiTubeCtr_L1_State = DigiTube_State_Off;
		DigiTubeCtr_M1_State = DigiTube_State_Off;
		DigiTubeCtr_J1_State = DigiTube_State_Off;
		DigiTubeCtr_I1_State = DigiTube_State_Off;


	}

	if(DigiTube_DianLiang_Outside_Level==0)
	{
		DigiTubeCtr_A1_State = DigiTube_State_Off;
		DigiTubeCtr_B1_State = DigiTube_State_Off;
		DigiTubeCtr_C1_State = DigiTube_State_Off;
		DigiTubeCtr_D1_State = DigiTube_State_Off;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;
	}
	else if(DigiTube_DianLiang_Outside_Level==1)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_Off;
		DigiTubeCtr_C1_State = DigiTube_State_Off;
		DigiTubeCtr_D1_State = DigiTube_State_Off;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==2)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_Off;
		DigiTubeCtr_D1_State = DigiTube_State_Off;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==3)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_Off;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==4)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==5)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_On;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==6)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_On;
		DigiTubeCtr_F1_State = DigiTube_State_On;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==7)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_On;
		DigiTubeCtr_F1_State = DigiTube_State_On;
		DigiTubeCtr_G1_State = DigiTube_State_On;
		DigiTubeCtr_H1_State = DigiTube_State_Off;


	}
	else if(DigiTube_DianLiang_Outside_Level==8)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_On;
		DigiTubeCtr_F1_State = DigiTube_State_On;
		DigiTubeCtr_G1_State = DigiTube_State_On;
		DigiTubeCtr_H1_State = DigiTube_State_On;

	}


}
void DigiTube_DianLiang_Ctr1(uint8_t DigiTube_DianLiang_Inside_Flag,uint8_t DigiTube_DianLiang_Outside_Flag,uint8_t DigiTube_DianLiang_Outside_Level)
{
	if(DigiTube_DianLiang_Inside_Flag==1)
	{
		DigiTubeCtr_J1_State = DigiTube_State_On;
		DigiTubeCtr_I1_State = DigiTube_State_On;
	}
	else
	{
		DigiTubeCtr_J1_State = DigiTube_State_Off;
		DigiTubeCtr_I1_State = DigiTube_State_Off;
	}
	if(DigiTube_DianLiang_Outside_Flag==1)
	{

		DigiTubeCtr_M4_State = DigiTube_State_On;
		DigiTubeCtr_L5_State = DigiTube_State_On;
		DigiTubeCtr_M5_State = DigiTube_State_On;
		DigiTubeCtr_M6_State = DigiTube_State_On;
		DigiTubeCtr_K1_State = DigiTube_State_On;
		DigiTubeCtr_L1_State = DigiTube_State_On;
		DigiTubeCtr_M1_State = DigiTube_State_On;


	}
	else
	{
		DigiTubeCtr_M4_State = DigiTube_State_Off;
		DigiTubeCtr_L5_State = DigiTube_State_Off;
		DigiTubeCtr_M5_State = DigiTube_State_Off;
		DigiTubeCtr_M6_State = DigiTube_State_Off;
		DigiTubeCtr_K1_State = DigiTube_State_Off;
		DigiTubeCtr_L1_State = DigiTube_State_Off;
		DigiTubeCtr_M1_State = DigiTube_State_Off;
	}

	if(DigiTube_DianLiang_Outside_Level==0)
	{
		DigiTubeCtr_A1_State = DigiTube_State_Off;
		DigiTubeCtr_B1_State = DigiTube_State_Off;
		DigiTubeCtr_C1_State = DigiTube_State_Off;
		DigiTubeCtr_D1_State = DigiTube_State_Off;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;
	}
	else if(DigiTube_DianLiang_Outside_Level==1)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_Off;
		DigiTubeCtr_C1_State = DigiTube_State_Off;
		DigiTubeCtr_D1_State = DigiTube_State_Off;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==2)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_Off;
		DigiTubeCtr_D1_State = DigiTube_State_Off;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==3)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_Off;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==4)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_Off;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==5)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_On;
		DigiTubeCtr_F1_State = DigiTube_State_Off;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==6)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_On;
		DigiTubeCtr_F1_State = DigiTube_State_On;
		DigiTubeCtr_G1_State = DigiTube_State_Off;
		DigiTubeCtr_H1_State = DigiTube_State_Off;

	}
	else if(DigiTube_DianLiang_Outside_Level==7)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_On;
		DigiTubeCtr_F1_State = DigiTube_State_On;
		DigiTubeCtr_G1_State = DigiTube_State_On;
		DigiTubeCtr_H1_State = DigiTube_State_Off;


	}
	else if(DigiTube_DianLiang_Outside_Level==8)
	{
		DigiTubeCtr_A1_State = DigiTube_State_On;
		DigiTubeCtr_B1_State = DigiTube_State_On;
		DigiTubeCtr_C1_State = DigiTube_State_On;
		DigiTubeCtr_D1_State = DigiTube_State_On;
		DigiTubeCtr_E1_State = DigiTube_State_On;
		DigiTubeCtr_F1_State = DigiTube_State_On;
		DigiTubeCtr_G1_State = DigiTube_State_On;
		DigiTubeCtr_H1_State = DigiTube_State_On;

	}


}

void DigiTube_YouLiang_Ctr(uint8_t DigiTube_YouLiang_Inside_Flag,uint8_t DigiTube_YouLiang_Outside_Level)
{
	if(DigiTube_YouLiang_Inside_Flag==1)
	{
		DigiTubeCtr_H5_State = DigiTube_State_On;
		DigiTubeCtr_I5_State = DigiTube_State_On;
		DigiTubeCtr_J5_State = DigiTube_State_On;
		DigiTubeCtr_K5_State = DigiTube_State_On;
		DigiTubeCtr_K2_State = DigiTube_State_On;
		DigiTubeCtr_L2_State = DigiTube_State_On;
		DigiTubeCtr_M2_State = DigiTube_State_On;
		DigiTubeCtr_J2_State = DigiTube_State_On;
		DigiTubeCtr_I2_State = DigiTube_State_On;

	}
	else
	{
		DigiTubeCtr_H5_State = DigiTube_State_Off;
		DigiTubeCtr_I5_State = DigiTube_State_Off;
		DigiTubeCtr_J5_State = DigiTube_State_Off;
		DigiTubeCtr_K5_State = DigiTube_State_Off;
		DigiTubeCtr_K2_State = DigiTube_State_Off;
		DigiTubeCtr_L2_State = DigiTube_State_Off;
		DigiTubeCtr_M2_State = DigiTube_State_Off;
		DigiTubeCtr_J2_State = DigiTube_State_Off;
		DigiTubeCtr_I2_State = DigiTube_State_Off;


	}

	if(DigiTube_YouLiang_Outside_Level==0)
	{
		DigiTubeCtr_A2_State = DigiTube_State_Off;
		DigiTubeCtr_B2_State = DigiTube_State_Off;
		DigiTubeCtr_C2_State = DigiTube_State_Off;
		DigiTubeCtr_D2_State = DigiTube_State_Off;
		DigiTubeCtr_E2_State = DigiTube_State_Off;
		DigiTubeCtr_F2_State = DigiTube_State_Off;
		DigiTubeCtr_G2_State = DigiTube_State_Off;
		DigiTubeCtr_H2_State = DigiTube_State_Off;
	}
	else if(DigiTube_YouLiang_Outside_Level==1)
	{
		DigiTubeCtr_A2_State = DigiTube_State_On;
		DigiTubeCtr_B2_State = DigiTube_State_Off;
		DigiTubeCtr_C2_State = DigiTube_State_Off;
		DigiTubeCtr_D2_State = DigiTube_State_Off;
		DigiTubeCtr_E2_State = DigiTube_State_Off;
		DigiTubeCtr_F2_State = DigiTube_State_Off;
		DigiTubeCtr_G2_State = DigiTube_State_Off;
		DigiTubeCtr_H2_State = DigiTube_State_Off;
	}

	else if(DigiTube_YouLiang_Outside_Level==2)
	{
		DigiTubeCtr_A2_State = DigiTube_State_On;
		DigiTubeCtr_B2_State = DigiTube_State_On;
		DigiTubeCtr_C2_State = DigiTube_State_Off;
		DigiTubeCtr_D2_State = DigiTube_State_Off;
		DigiTubeCtr_E2_State = DigiTube_State_Off;
		DigiTubeCtr_F2_State = DigiTube_State_Off;
		DigiTubeCtr_G2_State = DigiTube_State_Off;
		DigiTubeCtr_H2_State = DigiTube_State_Off;
	}

	else if(DigiTube_YouLiang_Outside_Level==3)
	{
		DigiTubeCtr_A2_State = DigiTube_State_On;
		DigiTubeCtr_B2_State = DigiTube_State_On;
		DigiTubeCtr_C2_State = DigiTube_State_On;
		DigiTubeCtr_D2_State = DigiTube_State_Off;
		DigiTubeCtr_E2_State = DigiTube_State_Off;
		DigiTubeCtr_F2_State = DigiTube_State_Off;
		DigiTubeCtr_G2_State = DigiTube_State_Off;
		DigiTubeCtr_H2_State = DigiTube_State_Off;
	}

	else if(DigiTube_YouLiang_Outside_Level==4)
	{
		DigiTubeCtr_A2_State = DigiTube_State_On;
		DigiTubeCtr_B2_State = DigiTube_State_On;
		DigiTubeCtr_C2_State = DigiTube_State_On;
		DigiTubeCtr_D2_State = DigiTube_State_On;
		DigiTubeCtr_E2_State = DigiTube_State_Off;
		DigiTubeCtr_F2_State = DigiTube_State_Off;
		DigiTubeCtr_G2_State = DigiTube_State_Off;
		DigiTubeCtr_H2_State = DigiTube_State_Off;
	}

	else if(DigiTube_YouLiang_Outside_Level==5)
	{
		DigiTubeCtr_A2_State = DigiTube_State_On;
		DigiTubeCtr_B2_State = DigiTube_State_On;
		DigiTubeCtr_C2_State = DigiTube_State_On;
		DigiTubeCtr_D2_State = DigiTube_State_On;
		DigiTubeCtr_E2_State = DigiTube_State_On;
		DigiTubeCtr_F2_State = DigiTube_State_Off;
		DigiTubeCtr_G2_State = DigiTube_State_Off;
		DigiTubeCtr_H2_State = DigiTube_State_Off;
	}

	else if(DigiTube_YouLiang_Outside_Level==6)
	{
		DigiTubeCtr_A2_State = DigiTube_State_On;
		DigiTubeCtr_B2_State = DigiTube_State_On;
		DigiTubeCtr_C2_State = DigiTube_State_On;
		DigiTubeCtr_D2_State = DigiTube_State_On;
		DigiTubeCtr_E2_State = DigiTube_State_On;
		DigiTubeCtr_F2_State = DigiTube_State_On;
		DigiTubeCtr_G2_State = DigiTube_State_Off;
		DigiTubeCtr_H2_State = DigiTube_State_Off;
	}

	else if(DigiTube_YouLiang_Outside_Level==7)
	{
		DigiTubeCtr_A2_State = DigiTube_State_On;
		DigiTubeCtr_B2_State = DigiTube_State_On;
		DigiTubeCtr_C2_State = DigiTube_State_On;
		DigiTubeCtr_D2_State = DigiTube_State_On;
		DigiTubeCtr_E2_State = DigiTube_State_On;
		DigiTubeCtr_F2_State = DigiTube_State_On;
		DigiTubeCtr_G2_State = DigiTube_State_On;
		DigiTubeCtr_H2_State = DigiTube_State_Off;
	}

	else if(DigiTube_YouLiang_Outside_Level==8 || DigiTube_YouLiang_Outside_Level==9 || DigiTube_YouLiang_Outside_Level==10)
	{
		DigiTubeCtr_A2_State = DigiTube_State_On;
		DigiTubeCtr_B2_State = DigiTube_State_On;
		DigiTubeCtr_C2_State = DigiTube_State_On;
		DigiTubeCtr_D2_State = DigiTube_State_On;
		DigiTubeCtr_E2_State = DigiTube_State_On;
		DigiTubeCtr_F2_State = DigiTube_State_On;
		DigiTubeCtr_G2_State = DigiTube_State_On;
		DigiTubeCtr_H2_State = DigiTube_State_On;
	}



}

void DigiTube_GongLv_Ctr(uint8_t DigiTube_GongLv_Inside_Flag,uint8_t DigiTube_GongLv_Inside_GeWei,uint8_t DigiTube_GongLv_Inside_ShiWei,uint8_t DigiTube_GongLv_Outside_Level)
{
	if(DigiTube_GongLv_Inside_Flag==1)
	{
		if(DigiTube_GongLv_Inside_GeWei==0)
		{
			DigiTubeCtr_F5_State = DigiTube_State_On;
			DigiTubeCtr_E5_State = DigiTube_State_On;
			DigiTubeCtr_A5_State = DigiTube_State_On;
			DigiTubeCtr_G5_State = DigiTube_State_Off;
			DigiTubeCtr_D5_State = DigiTube_State_On;
			DigiTubeCtr_B5_State = DigiTube_State_On;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_GeWei==1)
		{
			DigiTubeCtr_F5_State = DigiTube_State_Off;
			DigiTubeCtr_E5_State = DigiTube_State_Off;
			DigiTubeCtr_A5_State = DigiTube_State_Off;
			DigiTubeCtr_G5_State = DigiTube_State_Off;
			DigiTubeCtr_D5_State = DigiTube_State_Off;
			DigiTubeCtr_B5_State = DigiTube_State_On;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_GeWei==2)
		{
			DigiTubeCtr_F5_State = DigiTube_State_Off;
			DigiTubeCtr_E5_State = DigiTube_State_On;
			DigiTubeCtr_A5_State = DigiTube_State_On;
			DigiTubeCtr_G5_State = DigiTube_State_On;
			DigiTubeCtr_D5_State = DigiTube_State_On;
			DigiTubeCtr_B5_State = DigiTube_State_On;
			DigiTubeCtr_C5_State = DigiTube_State_Off;
		}
		else if(DigiTube_GongLv_Inside_GeWei==3)
		{
			DigiTubeCtr_F5_State = DigiTube_State_Off;
			DigiTubeCtr_E5_State = DigiTube_State_Off;
			DigiTubeCtr_A5_State = DigiTube_State_On;
			DigiTubeCtr_G5_State = DigiTube_State_On;
			DigiTubeCtr_D5_State = DigiTube_State_On;
			DigiTubeCtr_B5_State = DigiTube_State_On;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_GeWei==4)
		{
			DigiTubeCtr_F5_State = DigiTube_State_On;
			DigiTubeCtr_E5_State = DigiTube_State_Off;
			DigiTubeCtr_A5_State = DigiTube_State_Off;
			DigiTubeCtr_G5_State = DigiTube_State_On;
			DigiTubeCtr_D5_State = DigiTube_State_Off;
			DigiTubeCtr_B5_State = DigiTube_State_On;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_GeWei==5)
		{
			DigiTubeCtr_F5_State = DigiTube_State_On;
			DigiTubeCtr_E5_State = DigiTube_State_Off;
			DigiTubeCtr_A5_State = DigiTube_State_On;
			DigiTubeCtr_G5_State = DigiTube_State_On;
			DigiTubeCtr_D5_State = DigiTube_State_On;
			DigiTubeCtr_B5_State = DigiTube_State_Off;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_GeWei==6)
		{
			DigiTubeCtr_F5_State = DigiTube_State_On;
			DigiTubeCtr_E5_State = DigiTube_State_On;
			DigiTubeCtr_A5_State = DigiTube_State_On;
			DigiTubeCtr_G5_State = DigiTube_State_On;
			DigiTubeCtr_D5_State = DigiTube_State_On;
			DigiTubeCtr_B5_State = DigiTube_State_Off;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_GeWei==7)
		{
			DigiTubeCtr_F5_State = DigiTube_State_Off;
			DigiTubeCtr_E5_State = DigiTube_State_Off;
			DigiTubeCtr_A5_State = DigiTube_State_On;
			DigiTubeCtr_G5_State = DigiTube_State_Off;
			DigiTubeCtr_D5_State = DigiTube_State_Off;
			DigiTubeCtr_B5_State = DigiTube_State_On;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_GeWei==8)
		{
			DigiTubeCtr_F5_State = DigiTube_State_On;
			DigiTubeCtr_E5_State = DigiTube_State_On;
			DigiTubeCtr_A5_State = DigiTube_State_On;
			DigiTubeCtr_G5_State = DigiTube_State_On;
			DigiTubeCtr_D5_State = DigiTube_State_On;
			DigiTubeCtr_B5_State = DigiTube_State_On;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_GeWei==9)
		{
			DigiTubeCtr_F5_State = DigiTube_State_On;
			DigiTubeCtr_E5_State = DigiTube_State_Off;
			DigiTubeCtr_A5_State = DigiTube_State_On;
			DigiTubeCtr_G5_State = DigiTube_State_On;
			DigiTubeCtr_D5_State = DigiTube_State_On;
			DigiTubeCtr_B5_State = DigiTube_State_On;
			DigiTubeCtr_C5_State = DigiTube_State_On;
		}

		if(DigiTube_GongLv_Inside_ShiWei==0)
		{
			DigiTubeCtr_F4_State = DigiTube_State_On;
			DigiTubeCtr_E4_State = DigiTube_State_On;
			DigiTubeCtr_A4_State = DigiTube_State_On;
			DigiTubeCtr_G4_State = DigiTube_State_Off;
			DigiTubeCtr_D4_State = DigiTube_State_On;
			DigiTubeCtr_B4_State = DigiTube_State_On;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==1)
		{
			DigiTubeCtr_F4_State = DigiTube_State_Off;
			DigiTubeCtr_E4_State = DigiTube_State_Off;
			DigiTubeCtr_A4_State = DigiTube_State_Off;
			DigiTubeCtr_G4_State = DigiTube_State_Off;
			DigiTubeCtr_D4_State = DigiTube_State_Off;
			DigiTubeCtr_B4_State = DigiTube_State_On;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==2)
		{
			DigiTubeCtr_F4_State = DigiTube_State_Off;
			DigiTubeCtr_E4_State = DigiTube_State_On;
			DigiTubeCtr_A4_State = DigiTube_State_On;
			DigiTubeCtr_G4_State = DigiTube_State_On;
			DigiTubeCtr_D4_State = DigiTube_State_On;
			DigiTubeCtr_B4_State = DigiTube_State_On;
			DigiTubeCtr_C4_State = DigiTube_State_Off;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==3)
		{
			DigiTubeCtr_F4_State = DigiTube_State_Off;
			DigiTubeCtr_E4_State = DigiTube_State_Off;
			DigiTubeCtr_A4_State = DigiTube_State_On;
			DigiTubeCtr_G4_State = DigiTube_State_On;
			DigiTubeCtr_D4_State = DigiTube_State_On;
			DigiTubeCtr_B4_State = DigiTube_State_On;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==4)
		{
			DigiTubeCtr_F4_State = DigiTube_State_On;
			DigiTubeCtr_E4_State = DigiTube_State_Off;
			DigiTubeCtr_A4_State = DigiTube_State_Off;
			DigiTubeCtr_G4_State = DigiTube_State_On;
			DigiTubeCtr_D4_State = DigiTube_State_Off;
			DigiTubeCtr_B4_State = DigiTube_State_On;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==5)
		{
			DigiTubeCtr_F4_State = DigiTube_State_On;
			DigiTubeCtr_E4_State = DigiTube_State_Off;
			DigiTubeCtr_A4_State = DigiTube_State_On;
			DigiTubeCtr_G4_State = DigiTube_State_On;
			DigiTubeCtr_D4_State = DigiTube_State_On;
			DigiTubeCtr_B4_State = DigiTube_State_Off;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==6)
		{
			DigiTubeCtr_F4_State = DigiTube_State_On;
			DigiTubeCtr_E4_State = DigiTube_State_On;
			DigiTubeCtr_A4_State = DigiTube_State_On;
			DigiTubeCtr_G4_State = DigiTube_State_On;
			DigiTubeCtr_D4_State = DigiTube_State_On;
			DigiTubeCtr_B4_State = DigiTube_State_Off;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==7)
		{
			DigiTubeCtr_F4_State = DigiTube_State_Off;
			DigiTubeCtr_E4_State = DigiTube_State_Off;
			DigiTubeCtr_A4_State = DigiTube_State_On;
			DigiTubeCtr_G4_State = DigiTube_State_Off;
			DigiTubeCtr_D4_State = DigiTube_State_Off;
			DigiTubeCtr_B4_State = DigiTube_State_On;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==8)
		{
			DigiTubeCtr_F4_State = DigiTube_State_On;
			DigiTubeCtr_E4_State = DigiTube_State_On;
			DigiTubeCtr_A4_State = DigiTube_State_On;
			DigiTubeCtr_G4_State = DigiTube_State_On;
			DigiTubeCtr_D4_State = DigiTube_State_On;
			DigiTubeCtr_B4_State = DigiTube_State_On;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}
		else if(DigiTube_GongLv_Inside_ShiWei==9)
		{
			DigiTubeCtr_F4_State = DigiTube_State_On;
			DigiTubeCtr_E4_State = DigiTube_State_Off;
			DigiTubeCtr_A4_State = DigiTube_State_On;
			DigiTubeCtr_G4_State = DigiTube_State_On;
			DigiTubeCtr_D4_State = DigiTube_State_On;
			DigiTubeCtr_B4_State = DigiTube_State_On;
			DigiTubeCtr_C4_State = DigiTube_State_On;
		}

		DigiTubeCtr_I4_State = DigiTube_State_On;
		DigiTubeCtr_J4_State = DigiTube_State_On;
		DigiTubeCtr_K4_State = DigiTube_State_On;
		DigiTubeCtr_L4_State = DigiTube_State_On;
		DigiTubeCtr_H4_State = DigiTube_State_On;

	}
	else
	{
		DigiTubeCtr_F5_State = DigiTube_State_Off;
		DigiTubeCtr_E5_State = DigiTube_State_Off;
		DigiTubeCtr_A5_State = DigiTube_State_Off;
		DigiTubeCtr_G5_State = DigiTube_State_Off;
		DigiTubeCtr_D5_State = DigiTube_State_Off;
		DigiTubeCtr_B5_State = DigiTube_State_Off;
		DigiTubeCtr_C5_State = DigiTube_State_Off;
		DigiTubeCtr_F4_State = DigiTube_State_Off;
		DigiTubeCtr_E4_State = DigiTube_State_Off;
		DigiTubeCtr_A4_State = DigiTube_State_Off;
		DigiTubeCtr_G4_State = DigiTube_State_Off;
		DigiTubeCtr_D4_State = DigiTube_State_Off;
		DigiTubeCtr_B4_State = DigiTube_State_Off;
		DigiTubeCtr_C4_State = DigiTube_State_Off;
		DigiTubeCtr_I4_State = DigiTube_State_Off;
		DigiTubeCtr_J4_State = DigiTube_State_Off;
		DigiTubeCtr_K4_State = DigiTube_State_Off;
		DigiTubeCtr_L4_State = DigiTube_State_Off;
		DigiTubeCtr_H4_State = DigiTube_State_Off;
	}


	if(DigiTube_GongLv_Outside_Level==0)
	{
		DigiTubeCtr_A3_State = DigiTube_State_Off;
		DigiTubeCtr_B3_State = DigiTube_State_Off;
		DigiTubeCtr_C3_State = DigiTube_State_Off;
		DigiTubeCtr_D3_State = DigiTube_State_Off;
		DigiTubeCtr_E3_State = DigiTube_State_Off;
		DigiTubeCtr_F3_State = DigiTube_State_Off;
		DigiTubeCtr_G3_State = DigiTube_State_Off;
		DigiTubeCtr_H3_State = DigiTube_State_Off;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==1)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_Off;
		DigiTubeCtr_C3_State = DigiTube_State_Off;
		DigiTubeCtr_D3_State = DigiTube_State_Off;
		DigiTubeCtr_E3_State = DigiTube_State_Off;
		DigiTubeCtr_F3_State = DigiTube_State_Off;
		DigiTubeCtr_G3_State = DigiTube_State_Off;
		DigiTubeCtr_H3_State = DigiTube_State_Off;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==2)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_Off;
		DigiTubeCtr_D3_State = DigiTube_State_Off;
		DigiTubeCtr_E3_State = DigiTube_State_Off;
		DigiTubeCtr_F3_State = DigiTube_State_Off;
		DigiTubeCtr_G3_State = DigiTube_State_Off;
		DigiTubeCtr_H3_State = DigiTube_State_Off;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==3)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_Off;
		DigiTubeCtr_E3_State = DigiTube_State_Off;
		DigiTubeCtr_F3_State = DigiTube_State_Off;
		DigiTubeCtr_G3_State = DigiTube_State_Off;
		DigiTubeCtr_H3_State = DigiTube_State_Off;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==4)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_Off;
		DigiTubeCtr_F3_State = DigiTube_State_Off;
		DigiTubeCtr_G3_State = DigiTube_State_Off;
		DigiTubeCtr_H3_State = DigiTube_State_Off;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==5)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_Off;
		DigiTubeCtr_G3_State = DigiTube_State_Off;
		DigiTubeCtr_H3_State = DigiTube_State_Off;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==6)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_On;
		DigiTubeCtr_G3_State = DigiTube_State_Off;
		DigiTubeCtr_H3_State = DigiTube_State_Off;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==7)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_On;
		DigiTubeCtr_G3_State = DigiTube_State_On;
		DigiTubeCtr_H3_State = DigiTube_State_Off;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==8)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_On;
		DigiTubeCtr_G3_State = DigiTube_State_On;
		DigiTubeCtr_H3_State = DigiTube_State_On;
		DigiTubeCtr_I3_State = DigiTube_State_Off;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==9)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_On;
		DigiTubeCtr_G3_State = DigiTube_State_On;
		DigiTubeCtr_H3_State = DigiTube_State_On;
		DigiTubeCtr_I3_State = DigiTube_State_On;		
		DigiTubeCtr_J3_State = DigiTube_State_Off;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==10)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_On;
		DigiTubeCtr_G3_State = DigiTube_State_On;
		DigiTubeCtr_H3_State = DigiTube_State_On;
		DigiTubeCtr_I3_State = DigiTube_State_On;		
		DigiTubeCtr_J3_State = DigiTube_State_On;
		DigiTubeCtr_K3_State = DigiTube_State_Off;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==11)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_On;
		DigiTubeCtr_G3_State = DigiTube_State_On;
		DigiTubeCtr_H3_State = DigiTube_State_On;
		DigiTubeCtr_I3_State = DigiTube_State_On;		
		DigiTubeCtr_J3_State = DigiTube_State_On;
		DigiTubeCtr_K3_State = DigiTube_State_On;
		DigiTubeCtr_L3_State = DigiTube_State_Off;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==12)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_On;
		DigiTubeCtr_G3_State = DigiTube_State_On;
		DigiTubeCtr_H3_State = DigiTube_State_On;
		DigiTubeCtr_I3_State = DigiTube_State_On;		
		DigiTubeCtr_J3_State = DigiTube_State_On;
		DigiTubeCtr_K3_State = DigiTube_State_On;
		DigiTubeCtr_L3_State = DigiTube_State_On;
		DigiTubeCtr_M3_State = DigiTube_State_Off;

	}
	else if(DigiTube_GongLv_Outside_Level==13)
	{
		DigiTubeCtr_A3_State = DigiTube_State_On;
		DigiTubeCtr_B3_State = DigiTube_State_On;
		DigiTubeCtr_C3_State = DigiTube_State_On;
		DigiTubeCtr_D3_State = DigiTube_State_On;
		DigiTubeCtr_E3_State = DigiTube_State_On;
		DigiTubeCtr_F3_State = DigiTube_State_On;
		DigiTubeCtr_G3_State = DigiTube_State_On;
		DigiTubeCtr_H3_State = DigiTube_State_On;
		DigiTubeCtr_I3_State = DigiTube_State_On;		
		DigiTubeCtr_J3_State = DigiTube_State_On;
		DigiTubeCtr_K3_State = DigiTube_State_On;
		DigiTubeCtr_L3_State = DigiTube_State_On;
		DigiTubeCtr_M3_State = DigiTube_State_On;

	}


}
void DigiTube_HuoYan_Ctr(uint8_t DigiTube_HuoYan_Flag)
{
	if(DigiTube_HuoYan_Flag==1)
	{
		DigiTubeCtr_A8_State = DigiTube_State_On;		
		DigiTubeCtr_B8_State = DigiTube_State_On;		
 		DigiTubeCtr_C8_State = DigiTube_State_On;
		DigiTubeCtr_D8_State = DigiTube_State_On;
		DigiTubeCtr_E8_State = DigiTube_State_On;
		DigiTubeCtr_F8_State = DigiTube_State_On;		
		DigiTubeCtr_G8_State = DigiTube_State_On;		
 		DigiTubeCtr_H8_State = DigiTube_State_On;
		DigiTubeCtr_I8_State = DigiTube_State_On;
		DigiTubeCtr_J8_State = DigiTube_State_On;
		DigiTubeCtr_K8_State = DigiTube_State_On;		
		DigiTubeCtr_L8_State = DigiTube_State_On;		
 		DigiTubeCtr_M8_State = DigiTube_State_On;
		DigiTubeCtr_K6_State = DigiTube_State_On;		
		DigiTubeCtr_L6_State = DigiTube_State_On;		
 		DigiTubeCtr_M7_State = DigiTube_State_On;
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;		
		DigiTubeCtr_J7_State = DigiTube_State_On;		
 		DigiTubeCtr_K7_State = DigiTube_State_On;


	}
	else
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;		
		DigiTubeCtr_B8_State = DigiTube_State_Off;		
 		DigiTubeCtr_C8_State = DigiTube_State_Off;
		DigiTubeCtr_D8_State = DigiTube_State_Off;
		DigiTubeCtr_E8_State = DigiTube_State_Off;
		DigiTubeCtr_F8_State = DigiTube_State_Off;		
		DigiTubeCtr_G8_State = DigiTube_State_Off;		
 		DigiTubeCtr_H8_State = DigiTube_State_Off;
		DigiTubeCtr_I8_State = DigiTube_State_Off;
		DigiTubeCtr_J8_State = DigiTube_State_Off;
		DigiTubeCtr_K8_State = DigiTube_State_Off;		
		DigiTubeCtr_L8_State = DigiTube_State_Off;		
 		DigiTubeCtr_M8_State = DigiTube_State_Off;
		DigiTubeCtr_K6_State = DigiTube_State_Off;		
		DigiTubeCtr_L6_State = DigiTube_State_Off;		
 		DigiTubeCtr_M7_State = DigiTube_State_Off;
		DigiTubeCtr_L7_State = DigiTube_State_Off;
		DigiTubeCtr_I7_State = DigiTube_State_Off;		
		DigiTubeCtr_J7_State = DigiTube_State_Off;		
 		DigiTubeCtr_K7_State = DigiTube_State_Off;


	}


}
void DigiTube_ShiJian_Ctr(uint8_t DigiTube_ShiJian_Flag,uint8_t DigiTube_ShiJian_GeWei,uint8_t DigiTube_ShiJian_ShiWei)
{
	if(DigiTube_ShiJian_Flag==1)
	{
		if(DigiTube_ShiJian_GeWei==0)
		{
			DigiTubeCtr_F7_State = DigiTube_State_On;
			DigiTubeCtr_E7_State = DigiTube_State_On;
			DigiTubeCtr_A7_State = DigiTube_State_On;
			DigiTubeCtr_G7_State = DigiTube_State_Off;
			DigiTubeCtr_D7_State = DigiTube_State_On;
			DigiTubeCtr_B7_State = DigiTube_State_On;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_GeWei==1)
		{
			DigiTubeCtr_F7_State = DigiTube_State_Off;
			DigiTubeCtr_E7_State = DigiTube_State_Off;
			DigiTubeCtr_A7_State = DigiTube_State_Off;
			DigiTubeCtr_G7_State = DigiTube_State_Off;
			DigiTubeCtr_D7_State = DigiTube_State_Off;
			DigiTubeCtr_B7_State = DigiTube_State_On;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_GeWei==2)
		{
			DigiTubeCtr_F7_State = DigiTube_State_Off;
			DigiTubeCtr_E7_State = DigiTube_State_On;
			DigiTubeCtr_A7_State = DigiTube_State_On;
			DigiTubeCtr_G7_State = DigiTube_State_On;
			DigiTubeCtr_D7_State = DigiTube_State_On;
			DigiTubeCtr_B7_State = DigiTube_State_On;
			DigiTubeCtr_C7_State = DigiTube_State_Off;
		}
		else if(DigiTube_ShiJian_GeWei==3)
		{
			DigiTubeCtr_F7_State = DigiTube_State_Off;
			DigiTubeCtr_E7_State = DigiTube_State_Off;
			DigiTubeCtr_A7_State = DigiTube_State_On;
			DigiTubeCtr_G7_State = DigiTube_State_On;
			DigiTubeCtr_D7_State = DigiTube_State_On;
			DigiTubeCtr_B7_State = DigiTube_State_On;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_GeWei==4)
		{
			DigiTubeCtr_F7_State = DigiTube_State_On;
			DigiTubeCtr_E7_State = DigiTube_State_Off;
			DigiTubeCtr_A7_State = DigiTube_State_Off;
			DigiTubeCtr_G7_State = DigiTube_State_On;
			DigiTubeCtr_D7_State = DigiTube_State_Off;
			DigiTubeCtr_B7_State = DigiTube_State_On;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_GeWei==5)
		{
			DigiTubeCtr_F7_State = DigiTube_State_On;
			DigiTubeCtr_E7_State = DigiTube_State_Off;
			DigiTubeCtr_A7_State = DigiTube_State_On;
			DigiTubeCtr_G7_State = DigiTube_State_On;
			DigiTubeCtr_D7_State = DigiTube_State_On;
			DigiTubeCtr_B7_State = DigiTube_State_Off;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_GeWei==6)
		{
			DigiTubeCtr_F7_State = DigiTube_State_On;
			DigiTubeCtr_E7_State = DigiTube_State_On;
			DigiTubeCtr_A7_State = DigiTube_State_On;
			DigiTubeCtr_G7_State = DigiTube_State_On;
			DigiTubeCtr_D7_State = DigiTube_State_On;
			DigiTubeCtr_B7_State = DigiTube_State_Off;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_GeWei==7)
		{
			DigiTubeCtr_F7_State = DigiTube_State_Off;
			DigiTubeCtr_E7_State = DigiTube_State_Off;
			DigiTubeCtr_A7_State = DigiTube_State_On;
			DigiTubeCtr_G7_State = DigiTube_State_Off;
			DigiTubeCtr_D7_State = DigiTube_State_Off;
			DigiTubeCtr_B7_State = DigiTube_State_On;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_GeWei==8)
		{
			DigiTubeCtr_F7_State = DigiTube_State_On;
			DigiTubeCtr_E7_State = DigiTube_State_On;
			DigiTubeCtr_A7_State = DigiTube_State_On;
			DigiTubeCtr_G7_State = DigiTube_State_On;
			DigiTubeCtr_D7_State = DigiTube_State_On;
			DigiTubeCtr_B7_State = DigiTube_State_On;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_GeWei==9)
		{
			DigiTubeCtr_F7_State = DigiTube_State_On;
			DigiTubeCtr_E7_State = DigiTube_State_Off;
			DigiTubeCtr_A7_State = DigiTube_State_On;
			DigiTubeCtr_G7_State = DigiTube_State_On;
			DigiTubeCtr_D7_State = DigiTube_State_On;
			DigiTubeCtr_B7_State = DigiTube_State_On;
			DigiTubeCtr_C7_State = DigiTube_State_On;
		}
		if(DigiTube_ShiJian_ShiWei==0)
		{
			DigiTubeCtr_F6_State = DigiTube_State_On;
			DigiTubeCtr_E6_State = DigiTube_State_On;
			DigiTubeCtr_A6_State = DigiTube_State_On;
			DigiTubeCtr_G6_State = DigiTube_State_Off;
			DigiTubeCtr_D6_State = DigiTube_State_On;
			DigiTubeCtr_B6_State = DigiTube_State_On;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_ShiWei==1)
		{
			DigiTubeCtr_F6_State = DigiTube_State_Off;
			DigiTubeCtr_E6_State = DigiTube_State_Off;
			DigiTubeCtr_A6_State = DigiTube_State_Off;
			DigiTubeCtr_G6_State = DigiTube_State_Off;
			DigiTubeCtr_D6_State = DigiTube_State_Off;
			DigiTubeCtr_B6_State = DigiTube_State_On;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_ShiWei==2)
		{
			DigiTubeCtr_F6_State = DigiTube_State_Off;
			DigiTubeCtr_E6_State = DigiTube_State_On;
			DigiTubeCtr_A6_State = DigiTube_State_On;
			DigiTubeCtr_G6_State = DigiTube_State_On;
			DigiTubeCtr_D6_State = DigiTube_State_On;
			DigiTubeCtr_B6_State = DigiTube_State_On;
			DigiTubeCtr_C6_State = DigiTube_State_Off;
		}
		else if(DigiTube_ShiJian_ShiWei==3)
		{
			DigiTubeCtr_F6_State = DigiTube_State_Off;
			DigiTubeCtr_E6_State = DigiTube_State_Off;
			DigiTubeCtr_A6_State = DigiTube_State_On;
			DigiTubeCtr_G6_State = DigiTube_State_On;
			DigiTubeCtr_D6_State = DigiTube_State_On;
			DigiTubeCtr_B6_State = DigiTube_State_On;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_ShiWei==4)
		{
			DigiTubeCtr_F6_State = DigiTube_State_On;
			DigiTubeCtr_E6_State = DigiTube_State_Off;
			DigiTubeCtr_A6_State = DigiTube_State_Off;
			DigiTubeCtr_G6_State = DigiTube_State_On;
			DigiTubeCtr_D6_State = DigiTube_State_Off;
			DigiTubeCtr_B6_State = DigiTube_State_On;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_ShiWei==5)
		{
			DigiTubeCtr_F6_State = DigiTube_State_On;
			DigiTubeCtr_E6_State = DigiTube_State_Off;
			DigiTubeCtr_A6_State = DigiTube_State_On;
			DigiTubeCtr_G6_State = DigiTube_State_On;
			DigiTubeCtr_D6_State = DigiTube_State_On;
			DigiTubeCtr_B6_State = DigiTube_State_Off;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_ShiWei==6)
		{
			DigiTubeCtr_F6_State = DigiTube_State_On;
			DigiTubeCtr_E6_State = DigiTube_State_On;
			DigiTubeCtr_A6_State = DigiTube_State_On;
			DigiTubeCtr_G6_State = DigiTube_State_On;
			DigiTubeCtr_D6_State = DigiTube_State_On;
			DigiTubeCtr_B6_State = DigiTube_State_Off;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_ShiWei==7)
		{
			DigiTubeCtr_F6_State = DigiTube_State_Off;
			DigiTubeCtr_E6_State = DigiTube_State_Off;
			DigiTubeCtr_A6_State = DigiTube_State_On;
			DigiTubeCtr_G6_State = DigiTube_State_Off;
			DigiTubeCtr_D6_State = DigiTube_State_Off;
			DigiTubeCtr_B6_State = DigiTube_State_On;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_ShiWei==8)
		{
			DigiTubeCtr_F6_State = DigiTube_State_On;
			DigiTubeCtr_E6_State = DigiTube_State_On;
			DigiTubeCtr_A6_State = DigiTube_State_On;
			DigiTubeCtr_G6_State = DigiTube_State_On;
			DigiTubeCtr_D6_State = DigiTube_State_On;
			DigiTubeCtr_B6_State = DigiTube_State_On;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		else if(DigiTube_ShiJian_ShiWei==9)
		{
			DigiTubeCtr_F6_State = DigiTube_State_On;
			DigiTubeCtr_E6_State = DigiTube_State_Off;
			DigiTubeCtr_A6_State = DigiTube_State_On;
			DigiTubeCtr_G6_State = DigiTube_State_On;
			DigiTubeCtr_D6_State = DigiTube_State_On;
			DigiTubeCtr_B6_State = DigiTube_State_On;
			DigiTubeCtr_C6_State = DigiTube_State_On;
		}
		DigiTubeCtr_H6_State = DigiTube_State_On;
		DigiTubeCtr_H7_State = DigiTube_State_On;

	}
	else
	{
		DigiTubeCtr_F7_State = DigiTube_State_Off;
		DigiTubeCtr_E7_State = DigiTube_State_Off;
		DigiTubeCtr_A7_State = DigiTube_State_Off;
		DigiTubeCtr_G7_State = DigiTube_State_Off;
		DigiTubeCtr_D7_State = DigiTube_State_Off;
		DigiTubeCtr_B7_State = DigiTube_State_Off;
		DigiTubeCtr_C7_State = DigiTube_State_Off;

		DigiTubeCtr_F6_State = DigiTube_State_Off;
		DigiTubeCtr_E6_State = DigiTube_State_Off;
		DigiTubeCtr_A6_State = DigiTube_State_Off;
		DigiTubeCtr_G6_State = DigiTube_State_Off;
		DigiTubeCtr_D6_State = DigiTube_State_Off;
		DigiTubeCtr_B6_State = DigiTube_State_Off;
		DigiTubeCtr_C6_State = DigiTube_State_Off;

		DigiTubeCtr_H6_State = DigiTube_State_Off;
		DigiTubeCtr_H7_State = DigiTube_State_Off;

	}
}
void DigiTube_KaiGuanJi_Ctr(uint8_t DigiTube_KaiGuanJi_Flag)
{
	if(DigiTube_KaiGuanJi_Flag==1)
	{
		DigiTubeCtr_I6_State = DigiTube_State_Off;
	}
	else
	{
		DigiTubeCtr_I6_State = DigiTube_State_On;
	}
}

void DigiTube_HuoYan_KaiGuan_Ctr(uint8_t DigiTube_HuoYan_KaiGuan_Flag)
{
	if(DigiTube_HuoYan_KaiGuan_Flag==1)
	{
		DigiTubeCtr_J6_State = DigiTube_State_On;
	}
	else
	{
		DigiTubeCtr_J6_State = DigiTube_State_Off;
	}

}

void DigiTube_HuoYan_Level_Ctr(uint32_t DigiTube_HuoYan_Level)
{

	if(DigiTube_HuoYan_Level==0)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_Off;
		DigiTubeCtr_L8_State = DigiTube_State_Off;
		
 		DigiTubeCtr_C8_State = DigiTube_State_Off;
		DigiTubeCtr_K8_State = DigiTube_State_Off;

		DigiTubeCtr_D8_State = DigiTube_State_Off;
		DigiTubeCtr_J8_State = DigiTube_State_Off;

		DigiTubeCtr_E8_State = DigiTube_State_Off;
		DigiTubeCtr_I8_State = DigiTube_State_Off;
		
		DigiTubeCtr_F8_State = DigiTube_State_Off;
		DigiTubeCtr_G8_State = DigiTube_State_Off;
		DigiTubeCtr_H8_State = DigiTube_State_Off;

		DigiTubeCtr_L6_State = DigiTube_State_Off;
		DigiTubeCtr_K6_State = DigiTube_State_Off;
		
		DigiTubeCtr_L7_State = DigiTube_State_Off;
		DigiTubeCtr_M7_State = DigiTube_State_Off;

		
		DigiTubeCtr_K7_State = DigiTube_State_Off;
		DigiTubeCtr_J7_State = DigiTube_State_Off;
		DigiTubeCtr_I7_State = DigiTube_State_Off;

	}

	else if(DigiTube_HuoYan_Level==1)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_Off;
		DigiTubeCtr_L8_State = DigiTube_State_Off;
		
 		DigiTubeCtr_C8_State = DigiTube_State_Off;
		DigiTubeCtr_K8_State = DigiTube_State_Off;

		DigiTubeCtr_D8_State = DigiTube_State_Off;
		DigiTubeCtr_J8_State = DigiTube_State_Off;

		DigiTubeCtr_E8_State = DigiTube_State_Off;
		DigiTubeCtr_I8_State = DigiTube_State_Off;
		
		DigiTubeCtr_F8_State = DigiTube_State_Off;
		DigiTubeCtr_G8_State = DigiTube_State_Off;
		DigiTubeCtr_H8_State = DigiTube_State_Off;

		DigiTubeCtr_L6_State = DigiTube_State_Off;
		DigiTubeCtr_K6_State = DigiTube_State_Off;
		
		DigiTubeCtr_L7_State = DigiTube_State_Off;
		DigiTubeCtr_M7_State = DigiTube_State_Off;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}


	else if(DigiTube_HuoYan_Level==2)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_Off;
		DigiTubeCtr_L8_State = DigiTube_State_Off;
		
 		DigiTubeCtr_C8_State = DigiTube_State_Off;
		DigiTubeCtr_K8_State = DigiTube_State_Off;

		DigiTubeCtr_D8_State = DigiTube_State_Off;
		DigiTubeCtr_J8_State = DigiTube_State_Off;

		DigiTubeCtr_E8_State = DigiTube_State_Off;
		DigiTubeCtr_I8_State = DigiTube_State_Off;
		
		DigiTubeCtr_F8_State = DigiTube_State_Off;
		DigiTubeCtr_G8_State = DigiTube_State_Off;
		DigiTubeCtr_H8_State = DigiTube_State_Off;

		DigiTubeCtr_L6_State = DigiTube_State_Off;
		DigiTubeCtr_K6_State = DigiTube_State_Off;
		
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_M7_State = DigiTube_State_On;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}

	else if(DigiTube_HuoYan_Level==3)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_Off;
		DigiTubeCtr_L8_State = DigiTube_State_Off;
		
 		DigiTubeCtr_C8_State = DigiTube_State_Off;
		DigiTubeCtr_K8_State = DigiTube_State_Off;

		DigiTubeCtr_D8_State = DigiTube_State_Off;
		DigiTubeCtr_J8_State = DigiTube_State_Off;

		DigiTubeCtr_E8_State = DigiTube_State_Off;
		DigiTubeCtr_I8_State = DigiTube_State_Off;
		
		DigiTubeCtr_F8_State = DigiTube_State_Off;
		DigiTubeCtr_G8_State = DigiTube_State_Off;
		DigiTubeCtr_H8_State = DigiTube_State_Off;

		DigiTubeCtr_L6_State = DigiTube_State_On;
		DigiTubeCtr_K6_State = DigiTube_State_On;
		
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_M7_State = DigiTube_State_On;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}

	else if(DigiTube_HuoYan_Level==4)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_Off;
		DigiTubeCtr_L8_State = DigiTube_State_Off;
		
 		DigiTubeCtr_C8_State = DigiTube_State_Off;
		DigiTubeCtr_K8_State = DigiTube_State_Off;

		DigiTubeCtr_D8_State = DigiTube_State_Off;
		DigiTubeCtr_J8_State = DigiTube_State_Off;

		DigiTubeCtr_E8_State = DigiTube_State_Off;
		DigiTubeCtr_I8_State = DigiTube_State_Off;
		
		DigiTubeCtr_F8_State = DigiTube_State_On;
		DigiTubeCtr_G8_State = DigiTube_State_On;
		DigiTubeCtr_H8_State = DigiTube_State_On;

		DigiTubeCtr_L6_State = DigiTube_State_On;
		DigiTubeCtr_K6_State = DigiTube_State_On;
		
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_M7_State = DigiTube_State_On;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}

	else if(DigiTube_HuoYan_Level==5)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_Off;
		DigiTubeCtr_L8_State = DigiTube_State_Off;
		
 		DigiTubeCtr_C8_State = DigiTube_State_Off;
		DigiTubeCtr_K8_State = DigiTube_State_Off;

		DigiTubeCtr_D8_State = DigiTube_State_Off;
		DigiTubeCtr_J8_State = DigiTube_State_Off;

		DigiTubeCtr_E8_State = DigiTube_State_On;
		DigiTubeCtr_I8_State = DigiTube_State_On;
		
		DigiTubeCtr_F8_State = DigiTube_State_On;
		DigiTubeCtr_G8_State = DigiTube_State_On;
		DigiTubeCtr_H8_State = DigiTube_State_On;

		DigiTubeCtr_L6_State = DigiTube_State_On;
		DigiTubeCtr_K6_State = DigiTube_State_On;
		
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_M7_State = DigiTube_State_On;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}


	else if(DigiTube_HuoYan_Level==6)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_Off;
		DigiTubeCtr_L8_State = DigiTube_State_Off;
		
 		DigiTubeCtr_C8_State = DigiTube_State_Off;
		DigiTubeCtr_K8_State = DigiTube_State_Off;

		DigiTubeCtr_D8_State = DigiTube_State_On;
		DigiTubeCtr_J8_State = DigiTube_State_On;

		DigiTubeCtr_E8_State = DigiTube_State_On;
		DigiTubeCtr_I8_State = DigiTube_State_On;
		
		DigiTubeCtr_F8_State = DigiTube_State_On;
		DigiTubeCtr_G8_State = DigiTube_State_On;
		DigiTubeCtr_H8_State = DigiTube_State_On;

		DigiTubeCtr_L6_State = DigiTube_State_On;
		DigiTubeCtr_K6_State = DigiTube_State_On;
		
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_M7_State = DigiTube_State_On;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}

	else if(DigiTube_HuoYan_Level==7)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_Off;
		DigiTubeCtr_L8_State = DigiTube_State_Off;
		
 		DigiTubeCtr_C8_State = DigiTube_State_On;
		DigiTubeCtr_K8_State = DigiTube_State_On;

		DigiTubeCtr_D8_State = DigiTube_State_On;
		DigiTubeCtr_J8_State = DigiTube_State_On;

		DigiTubeCtr_E8_State = DigiTube_State_On;
		DigiTubeCtr_I8_State = DigiTube_State_On;
		
		DigiTubeCtr_F8_State = DigiTube_State_On;
		DigiTubeCtr_G8_State = DigiTube_State_On;
		DigiTubeCtr_H8_State = DigiTube_State_On;

		DigiTubeCtr_L6_State = DigiTube_State_On;
		DigiTubeCtr_K6_State = DigiTube_State_On;
		
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_M7_State = DigiTube_State_On;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}

	else if(DigiTube_HuoYan_Level==8)
	{
		DigiTubeCtr_A8_State = DigiTube_State_Off;
		DigiTubeCtr_M8_State = DigiTube_State_Off;
		
		DigiTubeCtr_B8_State = DigiTube_State_On;
		DigiTubeCtr_L8_State = DigiTube_State_On;
		
 		DigiTubeCtr_C8_State = DigiTube_State_On;
		DigiTubeCtr_K8_State = DigiTube_State_On;

		DigiTubeCtr_D8_State = DigiTube_State_On;
		DigiTubeCtr_J8_State = DigiTube_State_On;

		DigiTubeCtr_E8_State = DigiTube_State_On;
		DigiTubeCtr_I8_State = DigiTube_State_On;
		
		DigiTubeCtr_F8_State = DigiTube_State_On;
		DigiTubeCtr_G8_State = DigiTube_State_On;
		DigiTubeCtr_H8_State = DigiTube_State_On;

		DigiTubeCtr_L6_State = DigiTube_State_On;
		DigiTubeCtr_K6_State = DigiTube_State_On;
		
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_M7_State = DigiTube_State_On;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}

	else if(DigiTube_HuoYan_Level==9)
	{
		DigiTubeCtr_A8_State = DigiTube_State_On;
		DigiTubeCtr_M8_State = DigiTube_State_On;
		
		DigiTubeCtr_B8_State = DigiTube_State_On;
		DigiTubeCtr_L8_State = DigiTube_State_On;
		
 		DigiTubeCtr_C8_State = DigiTube_State_On;
		DigiTubeCtr_K8_State = DigiTube_State_On;

		DigiTubeCtr_D8_State = DigiTube_State_On;
		DigiTubeCtr_J8_State = DigiTube_State_On;

		DigiTubeCtr_E8_State = DigiTube_State_On;
		DigiTubeCtr_I8_State = DigiTube_State_On;
		
		DigiTubeCtr_F8_State = DigiTube_State_On;
		DigiTubeCtr_G8_State = DigiTube_State_On;
		DigiTubeCtr_H8_State = DigiTube_State_On;

		DigiTubeCtr_L6_State = DigiTube_State_On;
		DigiTubeCtr_K6_State = DigiTube_State_On;
		
		DigiTubeCtr_L7_State = DigiTube_State_On;
		DigiTubeCtr_M7_State = DigiTube_State_On;

		
		DigiTubeCtr_K7_State = DigiTube_State_On;
		DigiTubeCtr_J7_State = DigiTube_State_On;
		DigiTubeCtr_I7_State = DigiTube_State_On;

	}


}

void DigiTubeCtr_Level_State_All_On()
{
	DigiTubeCtr_Level1_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level2_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level3_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level4_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level5_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level6_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level7_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level8_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level9_State = DigiTube_Level_State_On;
	DigiTubeCtr_Level10_State = DigiTube_Level_State_On;

	DigiTubeCtr_Level_State_Ctrl();
}
void DigiTubeCtr_Level_State_All_Off()
{
	DigiTubeCtr_Level1_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level2_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level3_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level4_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level5_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level6_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level7_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level8_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level9_State = DigiTube_Level_State_Off;
	DigiTubeCtr_Level10_State = DigiTube_Level_State_Off;

	DigiTubeCtr_Level_State_Ctrl();
}
void DigiTubeCtr_Level_State_Ctrl()
{
	if(DigiTubeCtr_Level1_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_M4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_L5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_M5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_M6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_K1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_L1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_M1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_A1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_B1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_C1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_D1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_E1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_F1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_G1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_H1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_J1_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_I1_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_M4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_L5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_M5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_M6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_K1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_L1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_M1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_A1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_B1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_C1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_D1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_E1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_F1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_G1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_H1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_J1_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_I1_State_Level = DigiTube_Level_State_On;
	}	

	if(DigiTubeCtr_Level2_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_M8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_A8_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_M8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_A8_State_Level = DigiTube_Level_State_On;
	}
	if(DigiTubeCtr_Level3_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_L8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_B8_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_L8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_B8_State_Level = DigiTube_Level_State_On;
	}

	if(DigiTubeCtr_Level4_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_K8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_C8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_H5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_I5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_J5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_K5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_K2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_L2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_M2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_A2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_B2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_C2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_D2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_E2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_F2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_G2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_H2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_J2_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_I2_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_K8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_C8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_H5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_I5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_J5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_K5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_K2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_L2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_M2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_A2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_B2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_C2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_D2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_E2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_F2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_G2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_H2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_J2_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_I2_State_Level = DigiTube_Level_State_On;
	}


	if(DigiTubeCtr_Level5_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_J8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_D8_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_J8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_D8_State_Level = DigiTube_Level_State_On;
	}	

	if(DigiTubeCtr_Level6_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_I8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_E8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_I4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_J4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_K4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_L4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_A3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_B3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_C3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_D3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_E3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_F3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_G3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_H3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_I3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_J3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_K3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_L3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_M3_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_H4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_F4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_E4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_A4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_G4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_D4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_B4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_C4_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_F5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_E5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_A5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_G5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_D5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_B5_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_C5_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_I8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_E8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_I4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_J4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_K4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_L4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_A3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_B3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_C3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_D3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_E3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_F3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_G3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_H3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_I3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_J3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_K3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_L3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_M3_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_H4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_F4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_E4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_A4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_G4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_D4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_B4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_C4_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_F5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_E5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_A5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_G5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_D5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_B5_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_C5_State_Level = DigiTube_Level_State_On;
	}


	if(DigiTubeCtr_Level7_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_H8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_K6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_G8_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_K6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_L6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_F8_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_H8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_K6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_G8_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_K6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_L6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_F8_State_Level = DigiTube_Level_State_On;
	}


	if(DigiTubeCtr_Level8_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_M7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_I6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_A6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_F6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_B6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_G6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_F7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_A7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_G7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_B7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_L7_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_M7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_I6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_A6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_F6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_B6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_G6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_F7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_A7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_G7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_B7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_L7_State_Level = DigiTube_Level_State_On;
	}


	if(DigiTubeCtr_Level9_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_J6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_E6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_D6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_C6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_H6_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_E7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_D7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_C7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_H7_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_J6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_E6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_D6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_C6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_H6_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_E7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_D7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_C7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_H7_State_Level = DigiTube_Level_State_On;
	}

	if(DigiTubeCtr_Level10_State == DigiTube_Level_State_Off)
	{
		DigiTubeCtr_I7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_J7_State_Level = DigiTube_Level_State_Off;
		DigiTubeCtr_K7_State_Level = DigiTube_Level_State_Off;
	}
	else
	{
		DigiTubeCtr_I7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_J7_State_Level = DigiTube_Level_State_On;
		DigiTubeCtr_K7_State_Level = DigiTube_Level_State_On;
	}




}

