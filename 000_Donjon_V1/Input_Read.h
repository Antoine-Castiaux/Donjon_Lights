void Input_Read() {
  DI_Small_BP_State = digitalRead(DI_Small_BP);
  if (DI_Small_BP_State != Prev_DI_Small_BP_State) {
    Prev_DI_Small_BP_State = DI_Small_BP_State;
    if (DI_Small_BP_State == HIGH) {
      if (mode)
        mode = mode - 1;
      CMD_Change_Mode = 1;
      delay(DELTAMS_DEBOUNCE);
    }
  }

  DI_Medium_BP_State = digitalRead(DI_Medium_BP);
  if (DI_Medium_BP_State != Prev_DI_Medium_BP_State) {
    Prev_DI_Medium_BP_State = DI_Medium_BP_State;
    if (DI_Medium_BP_State == HIGH) {
      ;
    }
  }

  DI_Big_BP_State = digitalRead(DI_Big_BP);
  if (DI_Big_BP_State != Prev_DI_Big_BP_State) {
    Prev_DI_Big_BP_State = DI_Big_BP_State;
    if (DI_Big_BP_State == HIGH) {
      mode = mode + 1;
      CMD_Change_Mode = 1;
      delay(DELTAMS_DEBOUNCE);
    }
  }

  DI_Key_State = digitalRead(DI_Key);
  if (DI_Key_State != Prev_DI_Key_State) {
    Prev_DI_Key_State = DI_Key_State;
    if (DI_Key_State == LOW) {
      mode = 2;
      X_Animation_Start = true;
      CMD_Write_Outputs = true;
      delay(DELTAMS_DEBOUNCE);
    } else {
      X_Animation_End = true;
      CMD_Write_Outputs = true;
      delay(DELTAMS_DEBOUNCE);
    }
  }
  return;
}