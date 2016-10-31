/* pong.c --- 
 * 
 * Filename: pong.c
 * Description: 
 * Author: Bryce Himebaugh
 * Maintainer: 
 * Created: Mon Aug 11 10:50:08 2014
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* Copyright (c) 2004-2007 The Trustees of Indiana University and 
 * Indiana University Research and Technology Corporation.  
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */

#include "c335sim.h"
#include "rect.h"
#include "screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>

#define PADDLE_MOVE_INCREMENT 3
#define PADDLE_HEIGHT 25
#define PADDLE_THICKNESS 3
#define BALL_DIM 3
#define EVENT_LOOP_TIME 20
#define XAXIS 0
#define YAXIS 41
#define ZAXIS 81

rect_t left_paddle;
rect_t right_paddle;
rect_t ball;

int ball_vx = 1;
int ball_vy = 2;

/*The event loop that handles the key input*/
void event_loop(void) {
  static int paddle_left_move = 0; 
  static int paddle_right_move = 0;
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type) {
  case SDL_KEYUP:
    switch (event.key.keysym.sym) {
    case SDLK_UP:
      paddle_right_move = 0;
      break;
    case SDLK_DOWN:
      paddle_right_move = 0;
      break;
    case SDLK_a:
      paddle_left_move = 0;
      break;
    case SDLK_z:
      paddle_left_move = 0;
      break;
    default:
      break;
    }
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_UP:
      paddle_right_move = -PADDLE_MOVE_INCREMENT;
      break;
    case SDLK_DOWN:
      paddle_right_move = PADDLE_MOVE_INCREMENT;
      break;
    case SDLK_a:
      paddle_left_move = -PADDLE_MOVE_INCREMENT; 
      break;
    case SDLK_z:
      paddle_left_move = PADDLE_MOVE_INCREMENT; 
      break;
    case SDLK_q:
      printf("Q PRESSED - Exit Program\n");
      exit(0);
      break;
    default:
      break;
    }
    break;
  }
  if (paddle_left_move) {
    moveRect(&left_paddle, 0, paddle_left_move, BLACK);
  }
  if (paddle_right_move) {
    moveRect(&right_paddle, 0, paddle_right_move, BLACK);
  }
}

/*Where the collisions are handled*/
void pong_game(void) {
  int collision;

  drawString(40,60,"hit q to quit",WHITE,BLACK);
  redrawRect(&left_paddle);
  redrawRect(&right_paddle);
  event_loop();
  collision = moveRect(&ball, ball_vx, ball_vy, BLACK);

  switch (collision) {
  case COLLISION_TOP:
    ball_vy = -ball_vy;
    break;
  case COLLISION_BOTTOM:
    ball_vy = -ball_vy;
    break;
  case COLLISION_LEFT:
    ball_vx = -ball_vx;
    break;
  case COLLISION_RIGHT:
    ball_vx = -ball_vx;
    break;
  }
}

void drawBarPos(int x,int y,int color){
  uint16_t buf[ST7735_width];
  int i = ST7735_height/2,j;
  for(;i>ST7735_height/2-y/4 ;i--){
    for(j=x;j<x+40;j++)
      buf[j] = color;
  //f3d_lcd_drawPixel(j, i,color);
    ST7735_pushColor(buf,ST7735_width);
  }
}

void drawBarNeg(int x,int y,int color){
  uint16_t buf[ST7735_width];
  int i = ST7735_height/2,j;
  for(;i< ST7735_height/2+y/4 ;i++){
    for(j=x;j<x+40;j++)
      buf[j] = color;
  //f3d_lcd_drawPixel(j, i,color);
    ST7735_pushColor(buf,ST7735_width);
  }
}

void plotValues(float data[]){
  fillScreen(RED);
  char str[40];
  sprintf(str, "X:%.1f,Y:%.1f,Z:%.1f",data[0],data[1],data[2]);
  if(data[0]<0)
    drawBarNeg(XAXIS,abs((int)data[0]),BLACK);
  else
    drawBarPos(XAXIS,(int)data[0],BLACK);
  
  if(data[1]<0)
    drawBarNeg(YAXIS,abs((int)data[1]),GREEN);
  else
    drawBarPos(YAXIS,(int)data[1],GREEN);
  
  if(data[2]<0)
    drawBarNeg(ZAXIS,abs((int)data[2]),BLUE);
  else
    drawBarPos(ZAXIS,(int)data[2],BLUE);
  
    drawString(0,0,str,WHITE,RED);
}

/*Where the pong_game() is called the rectangels are initialized. */
int c335_main( int argc, char *argv[] ) {

  fillScreen(RED);
  //initRect(&left_paddle,0,ST7735_height/2-(PADDLE_HEIGHT/2),PADDLE_THICKNESS,PADDLE_HEIGHT,WHITE);
  //initRect(&right_paddle,ST7735_width-PADDLE_THICKNESS,ST7735_height/2-(PADDLE_HEIGHT/2),PADDLE_THICKNESS,PADDLE_HEIGHT,WHITE);
  //initRect(&ball,ST7735_width/2-(BALL_DIM/2),ST7735_height/2-(BALL_DIM/2),BALL_DIM,BALL_DIM,WHITE);
  SDL_Event event;
  while (1) {
    //pong_game();
    SDL_PollEvent(&event);
    if(event.type == SDLK_q)
      exit(0);
    Delay(EVENT_LOOP_TIME);
  }
} 

/* pong.c ends here */
