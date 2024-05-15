void Mode_Choice() {
  if (CMD_Change_Mode == true) {
    CMD_Change_Mode = false;
    CMD_Write_Outputs = true;

    DO_RELAY_POWER_12V_State = 0;
    DO_LED_WHITE_1_State = 0;
    DO_LED_WHITE_2_State = 0;
    DO_LED_YELLOW_1_State = 0;
    DO_LED_YELLOW_2_State = 0;
    DO_LED_YELLOW_3_State = 0;
    switch (mode) {
      case 0:
        DO_RELAY_POWER_12V_State = 1;
        // white
        DO_RELAY_POWER_12V_State = 1;
        //DO_LED_WHITE_1_State = 1;
        DO_LED_WHITE_2_State = 1;
        break;
      case 1:
        DO_RELAY_POWER_12V_State = 1;
        // white
        DO_RELAY_POWER_12V_State = 1;
        DO_LED_WHITE_1_State = 1;
        DO_LED_WHITE_2_State = 1;
        break;
      case 2:
        //ALL
        DO_RELAY_POWER_12V_State = 1;
        DO_LED_WHITE_1_State = 1;
        DO_LED_WHITE_2_State = 1;
        DO_LED_YELLOW_1_State = 1;
        DO_LED_YELLOW_2_State = 1;
        DO_LED_YELLOW_3_State = 1;

        break;
      case 3:
        DO_RELAY_POWER_12V_State = 1;
        // Yellow
        DO_LED_YELLOW_1_State = 1;
        DO_LED_YELLOW_2_State = 1;
        DO_LED_YELLOW_3_State = 1;
        break;
      case 4:
        DO_RELAY_POWER_12V_State = 1;
        // Yellow
        DO_LED_YELLOW_1_State = 1;
        //DO_LED_YELLOW_2_State = 1;
        DO_LED_YELLOW_3_State = 1;
        break;
      case 5:
        DO_RELAY_POWER_12V_State = 1;
        // Yellow
        //DO_LED_YELLOW_1_State = 1;
        DO_LED_YELLOW_2_State = 1;
        //DO_LED_YELLOW_3_State = 1;
        break;

      default:
        //Statement
        break;
    }
  }
  return;
}