  #define limitswitch1 PORTA.F1
#define limitswitch2 PORTA.F2
#define limitswitch3 PORTA.F3
#define limitswitch4 PORTA.F4
#define relaydoor1 PORTC.F0
#define relaydoor2 PORTC.F1
#define relaywindow1 PORTC.F6
#define relaywindow2 PORTC.F7
#define windowswitch PORTA.F0

unsigned int mr, mr2;
unsigned short kp;
unsigned char passworda[5];
unsigned char passwordaa[5];
unsigned char data1[512]  ;
unsigned int i;
unsigned char count = 0;
unsigned int m;
unsigned short x;
sfr sbit Mmc_Chip_Select at RC2_bit;
sfr sbit Mmc_Chip_Select_Direction at TRISC2_bit;
char  keypadPort at PORTD;

sbit LCD_RS at RB5_bit;
sbit LCD_EN at RB4_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB5_bit;
sbit LCD_EN_Direction at TRISB4_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
unsigned char mm;
unsigned int pp;

 unsigned char check = 40;
  unsigned char save = 20;
const char code1[] = {4,5,6,1,3,4,3,5,9,7,0,0,0,0,0};
const char code2[] = {0,9,2,4,9,4,4,4,3,7,0,0,0,0,0};
const char code3[] = {7,8,8,0,1,7,5,2,3,1,0,0,0,0,0};
void main()
{
unsigned int ppp =0;
unsigned int mm = 0;
unsigned char access = 40;
unsigned char change= 40;
ADCON1 = 0b10000111;
  Keypad_Init();                           // Initialize Keypad
 TRISA = 255;
 TRISC.F1 = 0;
 TRISC.F0 = 0;
TRISB.F7 = 1;
TRISB.F6 = 1;    //rain input sensor
TRISC.F6 = 0;    //relay
TRISC.F7 = 0;   // relay
PORTB.F6 = 1;
PORTC.F6 = 0;
PORTC.F7 = 0;
// Initialise the SD card
// Spi_Init_Advanced(MASTER_OSC_DIV16,DATA_SAMPLE_MIDDLE,CLK_IDLE_LOW, LOW_2_HIGH);
//
//SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV64, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH);

SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV16, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH);


Lcd_Init();                              // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);                // Cursor off
  Lcd_Out(1, 3, "DESIGNED BY");
  Lcd_Out(2, 3, "UDEZE KENETH");                 // Write message text on LCD
delay_ms(3000);
  Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(1, 5, "AND");
  Lcd_Out(2, 3, "OWOEYE TOPE");                 // Write message text on LCD
delay_ms(3000);
  Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(1, 2, "SUPERVISED BY");
  Lcd_Out(2, 3, "ENGR.MRS ADETOYI");                 // Write message text on LCD
delay_ms(3000);
Lcd_Cmd(_LCD_CLEAR);

// begin of password
/*
mm = 0;
  do {
    kp = 0;
    ppp = 0;                                // Reset key code variable
    mm++;
    // Wait for key to be pressed and released
    do {
      // kp = Keypad_Key_Press();          // Store key code in kp variable
      kp = Keypad_Key_Click();             // Store key code in kp variable
      ppp++;
      if (ppp > 1400) break;
    } while (!kp);
        if (kp != 0) {
        mm = 0;
        ppp = 0;
            switch (kp) {
      case  1: kp = 49;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 1        // Uncomment this block for keypad4x4
      case  2: kp = 50;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 2
      case  3: kp = 51;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 3
      case  4: kp = 65;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // A
      case  5: kp = 52;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 4
      case  6: kp = 53;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 5
      case  7: kp = 54;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 6
      case  8: kp = 66;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // B
      case  9: kp = 55;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 7
      case 10: kp = 56;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 8
      case 11: kp = 57;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 9
      case 12: kp = 67;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // C
      case 13: kp = 42;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // *
      case 14: kp = 48;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // 0
      case 15: kp = 35;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // #
      case 16: kp = 68;   Lcd_Chr_Cp(kp);break;// Lcd_Out_Cp(kp); break; // D

         }
}

  } while (mm < 100);
   Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(1, 2, "THAT'S ALL");
delay_ms(2000);
 Lcd_Cmd(_LCD_CLEAR);
*/
  // end of password

    //  password();



  for(;;) {
  if ((PORTB.F7 == 1) && (access == 20)) {
  delay_ms(1000);
  access = 40;
  save = 20;
 // PORTC.F1 = 1;
 relaydoor1 = 1;
 relaydoor2 = 0;
  Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,3,"ACCESS GRANTED");
      Lcd_Out(2,2,"DOOR OPENED");
        Lcd_Cmd(_LCD_CURSOR_OFF);                // Cursor off

 for (mr = 0; mr < 10000; mr++) {
   if (limitswitch1 == 0) {
 relaydoor1 = 0;
 relaydoor2 = 0;
 delay_ms(3000);
  relaydoor1 = 0;
 relaydoor2 = 1;

 for (mr2 = 0; mr2 < 10000; mr2++) {
   if (limitswitch2 == 0) {
 relaydoor1 = 0;
 relaydoor2 = 0;
 break;
}
delay_ms(1);
}

  break;
   }
delay_ms(1);
   }
 relaydoor1 = 0;
 relaydoor2 = 0;

   //  delay_ms(10000);
    //  PORTC.F1 = 0;
     Lcd_Out(2,2,"DOOR CLOSED");
     delay_ms(1000);

  }
 //rain detector



if (PORTB.F6 == 0) {

  if (limitswitch3 == 1) {
relaywindow1 = 1;
relaywindow2 = 0;
  Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,5,"WINDOW");
      Lcd_Out(2,2,"IS CLOSING");
for (mr = 0; mr < 5000; mr++) {
  if (limitswitch3 == 0) {
relaywindow1 = 0;
relaywindow2 = 0;
break;
  }
  delay_ms(1);
}
  relaywindow1 = 0;
relaywindow2 = 0;
  Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,5,"WINDOW");
      Lcd_Out(2,5,"CLOSED");
   delay_ms(1000);

}

else {
 relaywindow1 = 0;
 relaywindow2 = 0;
}
  // PORTC.F6 = 1;
  // PORTC.F7 = 0;
  }

 if (windowswitch == 0) {
  if (limitswitch4 == 1) {
relaywindow1 = 0;
relaywindow2 = 1;
  Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,5,"WINDOW");
      Lcd_Out(2,2,"IS OPENING");
for (mr = 0; mr < 5000; mr++) {
  if (limitswitch4 == 0) {
relaywindow1 = 0;
relaywindow2 = 0;
break;
  }
  delay_ms(1);
}
  relaywindow1 = 0;
relaywindow2 = 0;
  Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,5,"WINDOW");
      Lcd_Out(2,5,"OPENED");
  }
  

 else if (limitswitch4 == 0) {
relaywindow1 = 1;
relaywindow2 = 0;
  Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,5,"WINDOW");
      Lcd_Out(2,2,"IS CLOSING");
for (mr = 0; mr < 5000; mr++) {
  if (limitswitch3 == 0) {
relaywindow1 = 0;
relaywindow2 = 0;
break;
  }
  delay_ms(1);
}
  relaywindow1 = 0;
relaywindow2 = 0;
  Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,5,"WINDOW");
      Lcd_Out(2,5,"CLOSED");
   delay_ms(1000);

}
  
   delay_ms(1000);


 }
/*
  if (limitswitch4 == 0) {
 relaywindow1 = 0;
 relaywindow2 = 1;
 delay_ms(1000);
  }
 */
  if (PORTB.F7 == 1) {
delay_ms(200);
  Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,3,"INSERT YOUR");
      Lcd_Out(2,2,"IDENTITY CARD");
     delay_ms(2000);

   save = 20;
  }
  if ((PORTB.F7 == 0) && (save == 20)) {
  delay_ms(500);
  check = 40;
    Lcd_Cmd(_LCD_CLEAR);
  for (m = 0; m < 20; m++) {
     if (Mmc_Init() == 0) {
     check = 20;
      Lcd_Out(1,3,"MEMORY GOOD");
     delay_ms(1000);
      break;
     }
  }
    if (check == 20) {
  x = Mmc_Read_Sector(10,data1);
  Lcd_Cmd(_LCD_CLEAR);
if (((data1[0] == code1[0]) && (data1[1] == code1[1]) &&(data1[2] == code1[2]) && (data1[3] == code1[3]) && (data1[4] == code1[4]) &&
(data1[5] == code1[5]) &&(data1[6] == code1[6]) &&(data1[7] == code1[7]) &&(data1[8] == code1[8]) &&(data1[9] == code1[9])) ||
((data1[0] == code2[0]) && (data1[1] == code2[1]) &&(data1[2] == code2[2]) && (data1[3] == code2[3]) && (data1[4] == code2[4]) &&
(data1[5] == code2[5]) &&(data1[6] == code2[6]) &&(data1[7] == code2[7]) &&(data1[8] == code2[8]) &&(data1[9] == code2[9]))  ||
((data1[0] == code3[0]) && (data1[1] == code3[1]) &&(data1[2] == code3[2]) && (data1[3] == code3[3]) && (data1[4] == code3[4]) &&
(data1[5] == code3[5]) &&(data1[6] == code3[6]) &&(data1[7] == code3[7]) &&(data1[8] == code3[8]) &&(data1[9] == code3[9]))) {


   Lcd_Out(1,1,"ENTER PASSWORD");
   Lcd_Out(2,3," ");
   Lcd_Cmd(_LCD_BLINK_CURSOR_ON);

 //BEGIN OF PASSWORD

  mm = 0;
  count = 0;
  do {
    kp = 0;
    ppp = 0;                                // Reset key code variable
    mm++;
    // Wait for key to be pressed and released
    do {
      // kp = Keypad_Key_Press();          // Store key code in kp variable
      kp = Keypad_Key_Click();             // Store key code in kp variable
      ppp++;
      if (ppp > 2000) break;
    } while (!kp);
        if (kp != 0) {
        mm = 0;
        ppp = 0;
            switch (kp) {
      case  3: kp = 1;   passworda[count] = kp ; count++; Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 1        // Uncomment this block for keypad4x4
      case  2: kp = 2;    passworda[count] = kp ; count++;  Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 2
      case  1: kp = 3;    passworda[count] = kp ; count++; Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 3
      case  4: kp = 65;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // A
      case  7: kp = 4;    passworda[count] = kp ; count++;  Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 4
      case  6: kp = 5;    passworda[count] = kp ;count++; Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 5
      case  5: kp = 6;    passworda[count] = kp ; count++; Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 6
      case  8: kp = 66;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // B
      case  11: kp = 7;    passworda[count] = kp ; count++; Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 7
      case 10: kp = 8;    passworda[count] = kp ; count++; Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 8
      case 9: kp = 9;    passworda[count] = kp ; count++; Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 9
      case 12: kp = 67;   Lcd_Chr_Cp(kp);break;//Lcd_Out_Cp(kp); break; // C
      case 15: Lcd_Out(2,1,"               "); Lcd_Out(2,3," "); count = 0; break;//Lcd_Out_Cp(kp); break; // *
      case 14: kp = 0;    passworda[count] = kp ; count++; Lcd_Chr_Cp('*');break;//Lcd_Out_Cp(kp); break; // 0
      case 13: Lcd_Out(1,1,"OLD PASSWORD");Lcd_Out(2,1,"               "); Lcd_Out(2,3," "); count = 0; change = 20; break;//Lcd_Out_Cp(kp); break; // #
      case 16: kp = 68;   Lcd_Chr_Cp(kp);break;// Lcd_Out_Cp(kp); break; // D

         }
}

if ((count >= 5) && (change == 60)) {
 change = 40;
 count = 0;
 data1[10] = passworda[0];
 data1[11] = passworda[1];
 data1[12] = passworda[2];
 data1[13] = passworda[3];
 data1[14] = passworda[4];
 x  = Mmc_Write_Sector(10, data1);
  Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(1, 1, "PASSWORD CHANGED");
  Lcd_Out(2, 1, "TO  ");
  passwordaa[0] = passworda[0] + 48 ;
    passwordaa[1] = passworda[1] + 48;
      passwordaa[2] = passworda[2] + 48;
        passwordaa[3] = passworda[3] + 48;
          passwordaa[4] = passworda[4] + 48;
  Lcd_Out(2, 5, passwordaa);
  Lcd_Cmd(_LCD_CURSOR_OFF);                // Cursor off
delay_ms(2000);
  Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(1, 1, "REMOVE YOUR CARD");
  //Lcd_Out(2, 1, "TO  ");
  delay_ms(1000);
  break;
}
if ((count >= 5) && (change == 20)) {
 //count = 0;
 if ((data1[10] == passworda[0]) &&  (data1[11] == passworda[1]) && (data1[12] == passworda[2]) && (data1[13] == passworda[3]) && (data1[14] == passworda[4])) {
 count = 0;
 Lcd_Out(1,1,"NEW PASSWORD");
 Lcd_Out(2,3," ");
  change = 60;
  mm = 0;
  ppp = 0;

 }
 else change = 40;
}
if ((count >= 5) && (change == 40)) {
 count = 0;
 if ((data1[10] == passworda[0]) &&  (data1[11] == passworda[1]) && (data1[12] == passworda[2]) && (data1[13] == passworda[3]) && (data1[14] == passworda[4])) {
   access = 20;
   Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(2, 1, "REMOVE YOUR CARD");
  Lcd_Out(1, 2, "PASSWORD OK");
  Lcd_Cmd(_LCD_CURSOR_OFF);                // Cursor off
delay_ms(1500);

 }
 else {
   Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(2, 1, "REMOVE YOUR CARD");
  Lcd_Out(1, 1, "INVALID PASSWORD");
  Lcd_Cmd(_LCD_CURSOR_OFF);                // Cursor off
delay_ms(1500);

 }
 break;
}

  } while (mm < 200);
  if (mm >= 199) {
  save = 40;
  Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(1, 1, "TIME OUT, PLEASE");
  Lcd_Out(2, 1, "REMOVE YOUR CARD");
  Lcd_Cmd(_LCD_CURSOR_OFF);                // Cursor off
delay_ms(2000);

  }
 /*
   Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Out(1, 2, "THAT'S ALL");
delay_ms(2000);
 Lcd_Cmd(_LCD_CLEAR);
   */
//END OF PASSWORD

}
    }
  else   {
   Lcd_Out(1,1,"MEMORY INITERROR");
   Lcd_Out(2,3,"REMOVE CARD");
   delay_ms(2000);
   }
   save = 40;
}
}
}
