// CakeCutting.cpp : Defines the entry point for the console application.
// http://www.algospot.com/judge/problem/read/CAKECUT

#include "stdafx.h"
#include <iostream>

int W = 0;
int H = 0;
int M = 0;

int Process(int w, int h, int m)
{
	if (m == 0)
	{
		return 0;
	}

	if (w >= h)
	{
		Process(w/m, h, m-w/m);
		Process(w-w/m, h, m-w-w/m);
	}
	else
	{
	}
}

int main()
{
	for (;;)
	{
		std::cin >> W >> H >> M;
		if ((W | H | M) == 0) {	break; }
		Process(W, H, M);
	}
	return 0;
}
/*
#include <stdio.h>

int best[21][21][21];

int main() {
  int a, b, c, i, j, k, l, max;

  for (i=1; i<21; i++)
    for (j=1; j<21; j++)
      for (k=1; k<21; k++)
	best[i][j][k]=999;

  for (i=1; i<21; i++)
    for (j=1; j<21; j++) 
      best[i][j][1] = i*j;
  
  for (k=2; k<21; k++)
    for (i=1; i<21; i++)
      for (j=1; j<21; j++)
	for (a=1; a<k; a++) {
	  
	  for (l=1; l<i; l++) {
	    if (best[l][j][a] > best[i-l][j][k-a])
	      max = best[l][j][a];
	    else
	      max = best[i-l][j][k-a];
	    if (max < best[i][j][k])
	      best[i][j][k] = max;
	  }
	   
	  for (l=1; l<j; l++) {
	    if (best[i][l][a] > best[i][j-l][k-a])
	      max = best[i][l][a];
	    else
	      max = best[i][j-l][k-a];
	    if (max < best[i][j][k])
	      best[i][j][k] = max;
	  }
	}
  
  while (1) {
    scanf("%d %d %d", &a, &b, &c);
    if (a == 0 && b == 0 && c == 0)
      break;
    printf("%d\n", best[a][b][c]);
  }
  
  return 0;
}
*/