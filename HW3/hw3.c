#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*****************************************************************
 * hw3.c - Deassembler
 *
 *
 * Author: Srikanth Kanuri
 * Date Created: 10/17/2016
 * Last Modified by: Srikanth Kanuri
 * Date Last Modified: 10/17/2016
 * Assignment: HW3
 * Part of: HW3
 ****************************************************************/
const char *hexValues[] = {"0000", "0001", "0010", "0011",
			   "0100", "0101", "0110", "0111",
			   "1000", "1001", "1010", "1011",
			   "1100", "1101", "1110", "1111"};

char *regnames[] = {"r0", "r1", "r2", "r3",
		    "r4", "r5", "r6", "r7",
		    "r8", "r9", "r10", "r11",
		    "r12", "sp", "lr", "pc"};

char *opname[]   = {"ands", "eors", "lsls", "lsrs", 
		    "asrs", "adcs", "sbcs", "rors", 
		    "tst", "rsbs", "cmp", "cmn", 
		    "orrs", "muls", "bics", "mvns"};

int bin_to_dec(char* bnum, int size){
  int i = 0, res = 0;
  for (i = 0; i < size; i++){
    res += (int)(pow(2,(size-i-1)) * (bnum[i]-'0'));
  }
  return res;
}

void opcode_selector(char* bin_inp, char* asm_code){
  char sub3[4], sub2[3], sub4[5], sub5[6];
  int  rm_idx, rn_idx, op_idx, rd_idx, imm5, temp;
  strncpy((char*)sub3,bin_inp+10, 3);
  rm_idx = bin_to_dec(sub3, 3);
  strncpy((char*)sub3,bin_inp+13, 3);
  rn_idx = bin_to_dec(sub3, 3);
  if(bin_inp[0] == '0' && bin_inp[2] == '0'){
    if(bin_inp[1] == '0'){
      strncpy((char*)sub2,bin_inp+3, 2);
      strncpy((char*)sub5,bin_inp+5, 5);
      imm5 = bin_to_dec(sub5, 5);
      switch(bin_to_dec(sub2,2)){
      case 0: 
	if(imm5 == 0){
	  sprintf(asm_code, "movs %s,%s",regnames[rm_idx],regnames[rn_idx]);
	}
	else{
	  sprintf(asm_code, "lsls %s,%s,#%d",regnames[rn_idx], regnames[rm_idx], imm5);
	}
	break;
      case 1: sprintf(asm_code, "lsrs %s,%s,#%d",regnames[rn_idx], regnames[rm_idx], imm5); break;
      case 2: sprintf(asm_code, "asrs %s,%s,#%d",regnames[rn_idx], regnames[rm_idx], imm5); break;
      case 3: 
	strncpy((char*)sub2,bin_inp+5, 2);
	strncpy((char*)sub3,bin_inp+7, 3);
	rd_idx = bin_to_dec(sub3, 3);
	switch(bin_to_dec(sub2, 2)){
	case 0: sprintf(asm_code, "adds %s,%s,%s",regnames[rn_idx], regnames[rm_idx], regnames[rd_idx]); break;
	case 1: sprintf(asm_code, "subs %s,%s,%s",regnames[rn_idx], regnames[rm_idx], regnames[rd_idx]); break;
	default: sprintf(asm_code, "hword");
	}
	break;
      default: sprintf(asm_code, "hword");
      }
    }
    else{
      strncpy((char*)sub3,bin_inp+3, 3);
      if(bin_to_dec(sub3,3) == 0){
	strncpy((char*)sub4,bin_inp+6, 4);
	op_idx = bin_to_dec(sub4, 4);
      }
      if(strcmp(opname[op_idx],"rsbs") == 0)
	sprintf(asm_code, "%s %s,%s,#0", opname[op_idx], regnames[rn_idx], regnames[rm_idx]);
      else
	sprintf(asm_code, "%s %s,%s", opname[op_idx], regnames[rn_idx], regnames[rm_idx]);
    }
  }
  else{
    sprintf(asm_code, "hword");
  }
}

void hex_to_binary(char* inp, char* binp){
  int i = 0;
  int bitValue = 0;
  for(i = 0; i<4; i++){
    bitValue = inp[i];
    if (bitValue >= '0' && bitValue <= '9')
      if(i == 0)
	strcpy(binp,  hexValues[bitValue - '0']);
      else
	strcat(binp, hexValues[bitValue - '0']);
    if (bitValue >= 'A' && bitValue <= 'F')
      if(i == 0)
	strcpy(binp, hexValues[10 + bitValue - 'A']);
      else
	strcat(binp, hexValues[10 + bitValue - 'A']);
    if (bitValue >= 'a' && bitValue <= 'f')
      if(i == 0)
        strcpy(binp, hexValues[10 + bitValue - 'a']);
      else
        strcat(binp, hexValues[10 + bitValue - 'a']);
  }
}

int main(){
  int i = 0, j =0;
  char inp[4];
  char binp[50][17];
  char asmcode[50][50];
  printf(".test\n.syntax unified\n.thumb\n");
  while(scanf("%s",inp) == 1){
    if(strcmp(inp,"exit") == 0){
      printf("The De-assembled program is :\n");
      printf(".test\n.syntax unified\n.thumb\n");
      for(j=0; j<i; j++)
	printf("\t%s\n", asmcode[j]);
      return 0;
    }
    else{
      hex_to_binary(inp, binp[i]);
      binp[i][16] = '\0';
    }
    opcode_selector(binp[i], asmcode[i]);
    if(strcmp(asmcode[i],"hword") == 0)
      sprintf(asmcode[i], ".hword 0x%s", inp);
    printf("%s\n", asmcode[i]);
    i++;
  } 
}
