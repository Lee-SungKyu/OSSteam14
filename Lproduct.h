#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int room_number;
	int bed_count;
	int head_count;
	int check;
}Hotel;

typedef struct
{
	int room_number2;
	int head_count2;
	char name2[100];
}Reserve;



int loadReservation(Reserve *p[], Hotel *h[],int linecount);
void saveReservation(Reserve *p[], Hotel *h[], int count);

void search_room_info(Hotel *p[], int count);
void search_bed_count(Hotel *p[], int count);
void search_head_count(Hotel *p[], int count);
void search_empty_room(Hotel *p[], int count);
void search_name(Reserve *p[], Hotel *h[], int count);
