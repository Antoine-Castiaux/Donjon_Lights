void Output_Write() {
  if (CMD_Write_Outputs == true) {
    if(X_Animation_Start == true){
      X_Animation_Start = 0; 
      CMD_Write_Outputs = false;
      
      digitalWrite(DO_RELAY_POWER_12V, true);
      delay(DELTAMS_START);
      digitalWrite(DO_LED_YELLOW_2, true);
      delay(DELTAMS_START);
      digitalWrite(DO_LED_WHITE_1, true);
      digitalWrite(DO_LED_WHITE_2, true);
      delay(DELTAMS_START);
      digitalWrite(DO_LED_YELLOW_1, true);
      digitalWrite(DO_LED_YELLOW_3, true);
      return;
    }
    else if (X_Animation_End == true){
      X_Animation_End = 0; 
      CMD_Write_Outputs = false;

      digitalWrite(DO_LED_YELLOW_1, false);
      digitalWrite(DO_LED_YELLOW_3, false);
      delay(DELTAMS_END);
      digitalWrite(DO_LED_WHITE_1, false);
      digitalWrite(DO_LED_WHITE_2, false);
      delay(DELTAMS_END);
      digitalWrite(DO_LED_YELLOW_2, false);
      delay(DELTAMS_END);
      digitalWrite(DO_RELAY_POWER_12V, false);
      return;
    }

    digitalWrite(DO_RELAY_POWER_12V, DO_RELAY_POWER_12V_State);

    if ((now_millis > (prev_millis + DELTAMS)) || Fast_Next_Output) {
      Fast_Next_Output = false;
      prev_millis = now_millis;

      output_Selection++;
      switch (output_Selection) {
        case 5:
          if (digitalRead(DO_LED_YELLOW_1) != DO_LED_YELLOW_1_State) {
            digitalWrite(DO_LED_YELLOW_1, DO_LED_YELLOW_1_State);
          } else {
            Fast_Next_Output = true;
          }
          break;
        case 4:
          if (digitalRead(DO_LED_WHITE_2) != DO_LED_WHITE_2_State) {
            digitalWrite(DO_LED_WHITE_2, DO_LED_WHITE_2_State);
          } else {
            Fast_Next_Output = true;
          }
          break;
        case 3:
          if (digitalRead(DO_LED_YELLOW_2) != DO_LED_YELLOW_2_State) {
            digitalWrite(DO_LED_YELLOW_2, DO_LED_YELLOW_2_State);
          } else {
            Fast_Next_Output = true;
          }
          break;
        case 2:
          if (digitalRead(DO_LED_WHITE_1) != DO_LED_WHITE_1_State) {
            digitalWrite(DO_LED_WHITE_1, DO_LED_WHITE_1_State);
          } else {
            Fast_Next_Output = true;
          }
          break;
        case 1:
          if (digitalRead(DO_LED_YELLOW_3) != DO_LED_YELLOW_3_State) {
            digitalWrite(DO_LED_YELLOW_3, DO_LED_YELLOW_3_State);
          } else {
            Fast_Next_Output = true;
          }
          break;
        default:
          CMD_Write_Outputs = false;
          output_Selection = false;
          Fast_Next_Output = false;
          break;
      }
    }
  }
  return;
}