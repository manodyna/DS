#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#include<csv.h>
#include"PES2UG20CS187_H.h""
#include"PES2UG20CS187_F.c"



int main()
{
    list spm;
    initlist(&spm);
	listmove move;
	initlistm(&move);
	read(&spm);
	movement(&spm,&move);
	display(&move);
	return 0;
}
