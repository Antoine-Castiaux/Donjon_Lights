// Include Controllino library if specific functions are needed (optional)
#include <Controllino.h>

#define DO_FREE CONTROLLINO_D0
#define DO_RELAY_POWER_12V CONTROLLINO_D1
#define DO_LED_WHITE_1 CONTROLLINO_D2
#define DO_LED_WHITE_2 CONTROLLINO_D3
#define DO_LED_YELLOW_1 CONTROLLINO_D4
#define DO_LED_YELLOW_2 CONTROLLINO_D5
#define DO_LED_YELLOW_3 CONTROLLINO_D6
#define DO_FREE_1 CONTROLLINO_D7

#define DI_Small_BP CONTROLLINO_A0
#define DI_Medium_BP CONTROLLINO_A1
#define DI_Big_BP CONTROLLINO_A2
#define DI_Key CONTROLLINO_A3
#define AI_4 CONTROLLINO_A4
#define AI_5 CONTROLLINO_A5
#define DI_0 CONTROLLINO_IN0
#define DI_1 CONTROLLINO_IN1

#define DELTAMS 350
#define DELTAMS_START 550
#define DELTAMS_END 750
#define DELTAMS_DEBOUNCE 100


int mode = 0;
int output_Selection = 0;

bool Prev_DI_Small_BP_State = 0;
bool DI_Small_BP_State = 0;
bool Prev_DI_Medium_BP_State = 0;
bool DI_Medium_BP_State = 0;
bool Prev_DI_Big_BP_State = 0;
bool DI_Big_BP_State = 0;
bool Prev_DI_Key_State = 0;
bool DI_Key_State = 0;

bool DO_RELAY_POWER_12V_State = 0;
bool DO_LED_WHITE_1_State = 0;
bool DO_LED_WHITE_2_State = 0;
bool DO_LED_YELLOW_1_State = 0;
bool DO_LED_YELLOW_2_State = 0;
bool DO_LED_YELLOW_3_State = 0;

bool X_Animation_Start = 0;
bool X_Animation_End = 0;

bool CMD_Change_Mode = 0;
bool CMD_Write_Outputs = 0;
bool Fast_Next_Output = 0;

uint32_t now_millis = 0;
uint32_t prev_millis = 0;

#include "Input_Read.h"
#include "Mode_Choice.h"
#include "Output_Write.h"

void setup() {
  pinMode(CONTROLLINO_D0, OUTPUT);
  pinMode(CONTROLLINO_D1, OUTPUT);
  pinMode(CONTROLLINO_D2, OUTPUT);
  pinMode(CONTROLLINO_D3, OUTPUT);
  pinMode(CONTROLLINO_D4, OUTPUT);
  pinMode(CONTROLLINO_D5, OUTPUT);
  pinMode(CONTROLLINO_D6, OUTPUT);
  pinMode(CONTROLLINO_D7, OUTPUT);

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A3, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A5, INPUT);
  pinMode(CONTROLLINO_IN0, INPUT);
  pinMode(CONTROLLINO_IN1, INPUT);
}

void loop() {
  //comptage du temps écoulé
  now_millis = millis();

  Input_Read();
  
  Mode_Choice();
  
  Output_Write();
  
}