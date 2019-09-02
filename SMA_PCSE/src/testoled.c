/*
 * testoled.c
 *
 *  Created on: 28 ago. 2019
 *      Author: leandro
 */
#include "sapi.h"
#include "oled.h"

void testdrawcircle(void) {
  for (int8_t i = 0; i < SSD1306_LCDHEIGHT; i += 2) {
    SSD1306_DrawCircle(SSD1306_LCDWIDTH/2, SSD1306_LCDHEIGHT/2, i);
    SSD1306_Display();
    delay(1);
  }
}

void testfillrect(void) {
  bool_t color = TRUE;
  for (int8_t i = 0; i < SSD1306_LCDHEIGHT/2; i += 3) {
    // alternate colors
    SSD1306_FillRect(i, i, SSD1306_LCDWIDTH - i*2, SSD1306_LCDHEIGHT - i*2, color);
    SSD1306_Display();
    delay(1);
    if(color)  color = FALSE;
    else       color = TRUE;
  }
}

void testdrawtriangle(void) {
  for (int8_t i = 0; i < SSD1306_LCDHEIGHT/2; i += 5) {
    SSD1306_DrawTriangle(SSD1306_LCDWIDTH/2,     SSD1306_LCDHEIGHT/2 - i,
                         SSD1306_LCDWIDTH/2 - i, SSD1306_LCDHEIGHT/2 + i,
                         SSD1306_LCDWIDTH/2 + i, SSD1306_LCDHEIGHT/2 + i);
    SSD1306_Display();
    delay(1);
  }
}

void testfilltriangle(void) {
  bool_t color = TRUE;
  for ( int16_t i = SSD1306_LCDHEIGHT/2; i > 0; i -= 5) {
    SSD1306_FillTriangle(SSD1306_LCDWIDTH/2,     SSD1306_LCDHEIGHT/2 - i,
                         SSD1306_LCDWIDTH/2 - i, SSD1306_LCDHEIGHT/2 + i,
                         SSD1306_LCDWIDTH/2 + i, SSD1306_LCDHEIGHT/2 + i, color);
    if(color)  color = FALSE;
    else       color = TRUE;
    SSD1306_Display();
    delay(1);
  }
}

void testdrawroundrect(void) {
  for (int8_t i = 0; i < SSD1306_LCDHEIGHT/2 - 2; i += 2) {
    SSD1306_DrawRoundRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i, SSD1306_LCDHEIGHT/4 - i/2);
    SSD1306_Display();
    delay(1);
  }
}

void testfillroundrect(void) {
  bool_t color = TRUE;
  for (int8_t i = 0; i < SSD1306_LCDHEIGHT/2 - 2; i += 2) {
    SSD1306_FillRoundRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i, SSD1306_LCDHEIGHT/4 - i/2, color);
    if(color)  color = FALSE;
    else       color = TRUE;
    SSD1306_Display();
    delay(1);
  }
}

void testdrawrect(void) {
  for (int8_t i = 0; i < SSD1306_LCDHEIGHT/2; i += 2) {
    SSD1306_DrawRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i);
    SSD1306_Display();
    delay(1);
  }
}

void testdrawline() {
  int16_t i;
  for (i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(0, 0, i, SSD1306_LCDHEIGHT - 1, TRUE);
    SSD1306_Display();
    delay(1);
  }
  for (i = 0; i < SSD1306_LCDHEIGHT; i += 4) {
    SSD1306_DrawLine(0, 0, SSD1306_LCDWIDTH - 1, i, TRUE);
    SSD1306_Display();
    delay(1);
  }
  delay(250);

  SSD1306_ClearDisplay();
  for (i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(0, SSD1306_LCDHEIGHT - 1, i, 0, TRUE);
    SSD1306_Display();
    delay(1);
  }
  for (i = SSD1306_LCDHEIGHT - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(0, SSD1306_LCDHEIGHT - 1, SSD1306_LCDWIDTH - 1, i, TRUE);
    SSD1306_Display();
    delay(1);
  }
  delay(250);

  SSD1306_ClearDisplay();
  for (i = SSD1306_LCDWIDTH - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, SSD1306_LCDHEIGHT - 1, i, 0, TRUE);
    SSD1306_Display();
    delay(1);
  }
  for (i = SSD1306_LCDHEIGHT - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, SSD1306_LCDHEIGHT - 1, 0, i, TRUE);
    SSD1306_Display();
    delay(1);
  }
  delay(250);

  SSD1306_ClearDisplay();
  for (i = 0; i < SSD1306_LCDHEIGHT; i += 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, 0, 0, i, TRUE);
    SSD1306_Display();
    delay(1);
  }
  for (i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, 0, i, SSD1306_LCDHEIGHT - 1, TRUE);
    SSD1306_Display();
    delay(1);
  }
  delay(250);
}

void testscrolltext(void) {
  SSD1306_ClearDisplay();
  SSD1306_DrawText(58, 8, "scroll", 2);
  SSD1306_Display();
  delay(1);

  SSD1306_StartScrollRight(0x00, 0x0F);
  delay(2000);
  SSD1306_StopScroll();
  delay(1000);
  SSD1306_StartScrollLeft(0x00, 0x0F);
  delay(2000);
  SSD1306_StopScroll();
  delay(1000);
  SSD1306_StartScrollDiagRight(0x00, 0x07);
  delay(2000);
  SSD1306_StartScrollDiagLeft(0x00, 0x07);
  delay(2000);
  SSD1306_StopScroll();
}
