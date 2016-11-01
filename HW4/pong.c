/* pong.c --- 
 * 
 * Filename: pong.c
 * Description: 
 * Author: Bryce Himebaugh
 * Maintainer: 
 * Created: Mon Aug 11 10:50:08 2014
 * Last-Updated: Mon Oct 31 22:20:00 2016
 *           By: Srikanth Kanuri (srkanuri)
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
#define XAXIS 35
#define YAXIS 65
#define ZAXIS 95

rect_t left_paddle;
rect_t right_paddle;
rect_t ball;

int ball_vx = 1;
int ball_vy = 2;
int new = 0;
int fsize = 0;
int pmode = 0;
int cur_ptr = 0;
char *fc;

void drawBarPos(int x,int y,int color){
  int factor = pmode?5:6;
  drawRect(x,65-y/factor,30,y/factor,color);
}

void drawBarNeg(int x,int y,int color){
  int factor = pmode?5:6;
  drawRect(x,65,30,y/factor,color);
}

void plotValues(float data[]){
  fillScreen(BLACK);
  char str[40];
  sprintf(str,"X:%.1f,Y:%.1f,Z:%.1f",data[0],data[1],data[2]);
  if(data[0]<0)
    drawBarNeg(XAXIS,abs((int)data[0]),RED);
  else
    drawBarPos(XAXIS,(int)data[0],RED);

  if(data[1]<0)
    drawBarNeg(YAXIS,abs((int)data[1]),GREEN);
  else
    drawBarPos(YAXIS,(int)data[1],GREEN);
  
  if(data[2]<0)
    drawBarNeg(ZAXIS,abs((int)data[2]),BLUE);
  else
    drawBarPos(ZAXIS,(int)data[2],BLUE);
  if(!pmode)
    drawString(0,0,str,RED,BLACK);
}

void drawGyro(){
  char coords[20];
  int axis,i;
  float vals[3];
  for(i=0,axis=0;(*fc != '\n') && (cur_ptr <= fsize); fc++,cur_ptr++){
    if(*fc == ','){
      coords[i] = '\0';
      //printf("Axis %d is %s\n",axis, coords);
      vals[axis] = atof(coords);
      axis++;
      i = 0;
    }else{
      coords[i]=*fc;
      i++;
    }
  }
  fc++;coords[i]='\0';vals[axis] = atof(coords);
  if(axis == 2){
    plotValues(vals);
  }
}

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
    case SDLK_n:
      if(new){drawGyro();Delay(1000);}
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

/*Where the pong_game() is called the rectangels are initialized. */
int c335_main( int argc, char *argv[] ) {
  int i = 0;
  char *mode;
  if(argc == 3){
    mode = argv[1];
    new = 1;
    if (!strcmp(mode, "LANDSCAPE") || !strcmp(mode, "PORTRAIT")){
      if(!strcmp(mode, "LANDSCAPE"))
	pmode = 1;
      else
	pmode = 0;
      FILE *fp = fopen(argv[2], "r");
      fseek (fp, 0, SEEK_END);
      fsize = ftell(fp);
      fseek (fp, 0, SEEK_SET);
      fc = malloc(fsize);
      if(fc){
	fread(fc, 1, fsize, fp);
      }
      fclose(fp);
    }
    else{
      printf("The 1st argument should be the following :\n1. LANDSCAPE\n2. PORTRAIT\n");
      exit(1);
    }
  }
  fillScreen(BLACK);
  initRect(&left_paddle,0,ST7735_height/2-(PADDLE_HEIGHT/2),PADDLE_THICKNESS,PADDLE_HEIGHT,WHITE);
  initRect(&right_paddle,ST7735_width-PADDLE_THICKNESS,ST7735_height/2-(PADDLE_HEIGHT/2),PADDLE_THICKNESS,PADDLE_HEIGHT,WHITE);
  initRect(&ball,ST7735_width/2-(BALL_DIM/2),ST7735_height/2-(BALL_DIM/2),BALL_DIM,BALL_DIM,WHITE);
  if(!pmode)
    drawString(40,60,"hit q to quit",WHITE,BLACK);
  while (1) {
    pong_game();
    Delay(EVENT_LOOP_TIME);
  }
} 

/* pong.c ends here */
