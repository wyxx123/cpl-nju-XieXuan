#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SwapPacket(a, b) do{Packet* t = a; a = b; b = t;}while(0)
#define abs(x) ((x) < 0 ? -(x) : (x))
#define dist(x1, y1, x2, y2) (abs((x1) - (x2)) + abs((y1) - (y2)))

typedef struct Packet
{
	bool type; // false = Send, true = Receive
	int Time;
	int HP;
	int ATK;
	int DEF;
	int Speed;
	int X, Y;
} Packet;

Packet* LastReceive = NULL,
	* LastSend = NULL;
int HostHPLimit,
	GuestHPLimit;

void GetPacket(Packet* packet)
{
	char* info = malloc(15 * sizeof(char));
	scanf("%s", info);
	if (strcmp(info, "Send") == 0)
		packet->type = false;
	else packet->type = true;
	scanf("%s", info);
	scanf("%s%d", info, &packet->Time);
	scanf("%s%d", info, &packet->HP);
	scanf("%s%d", info, &packet->ATK);
	scanf("%s%d", info, &packet->DEF);
	scanf("%s%d", info, &packet->Speed);
	scanf("%s%s%d", info, info, &packet->X);
	scanf("%s%s%d", info, info, &packet->Y);
	free(info);
}

bool ApplyAntiCheat(Packet* last, Packet* now, int HPLimit)
{
	int DeltaTime = now->Time - last->Time;
	if (
		DeltaTime <= 0 ||
			now->HP > HPLimit ||
			now->HP < 0 ||
			now->ATK != last->ATK ||
			now->DEF != last->DEF ||
			now->Speed != last->Speed ||
			dist(now->X, now->Y, last->X, last->Y) > now->Speed * DeltaTime
		)
	{
		return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int T;
	scanf("%d", &T);
	bool Host = false, Guest = false;
	while (T--)
	{
		Packet* new_packet = malloc(sizeof(Packet));
		GetPacket(new_packet);
		if (new_packet->type) // Receive
		{
			if (LastReceive == NULL)
			{
				LastReceive = malloc(sizeof(Packet));
				GuestHPLimit = new_packet->HP;
			}
			else if (ApplyAntiCheat(LastReceive, new_packet, GuestHPLimit))
				Guest = true;
			SwapPacket(LastReceive, new_packet);
		}
		else // Send
		{
			if (LastSend == NULL)
			{
				LastSend = malloc(sizeof(Packet));
				HostHPLimit = new_packet->HP;
			}
			else if (ApplyAntiCheat(LastSend, new_packet, HostHPLimit))
				Host = true;
			SwapPacket(LastSend, new_packet);
		}
		free(new_packet);
	}
	if (Host && Guest)
	{
		printf("This game is terrible!\n");
	}
	else if (Host)
	{
		printf("Host Cheated!\n");
	}
	else if (Guest)
	{
		printf("Guest Cheated!\n");
	}
	else
	{
		printf("Good Game!\n");
	}
	return 0;
}
