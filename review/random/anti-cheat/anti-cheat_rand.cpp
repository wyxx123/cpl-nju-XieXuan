#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <time.h>
#define getCommand(num) ("anti-cheat.exe < anti-cheat_data/anti-cheat_" + to_string(num) + ".in > anti-cheat_data/anti-cheat_" + to_string(num) + ".out").c_str()
#define getFilename(num) ("anti-cheat_data/anti-cheat_" + to_string(num) + ".in").c_str()

template <typename T>
T random(T l, T r)
{
    unsigned long long num = rand() * rand();
    return (T)(num % (unsigned long long)(r - l + 1) + (unsigned long long)l);
}

std::string to_string(int x)
{
    std::string ans = "";
    while (x)
    {
        ans = (char)(x % 10 + '0') + ans;
        x /= 10;
    }
    return ans;
}

typedef struct Packet
{
    bool type; // false = Send, true = Receive
    int Time;
    int HP;
    int ATK;
    int DEF;
    int Speed;
    int X, Y;
}Packet;

void PutPacket(Packet packet)
{
    printf("%s Packet:\n", packet.type ? "Receive" : "Send");
    printf("Time: %d\n", packet.Time);
    printf("HP: %d\n", packet.HP);
    printf("ATK: %d\n", packet.ATK);
    printf("DEF: %d\n", packet.DEF);
    printf("Speed: %d\n", packet.Speed);
    printf("Coordinate X: %d\n", packet.X);
    printf("Coordinate Y: %d\n", packet.Y);
    printf("\n");
}
void RandPacket(Packet* packet)
{
    packet->ATK = random(1, 10000);
    packet->DEF = random(1, 10000);
    packet->HP = random(100, 10000);
    packet->Speed = random(1, 10);
    packet->X = random(1, 1000);
    packet->Y = random(1, 1000);
    packet->Time = 1;
}

void ModifyPacket(Packet* packet)
{
    int DeltaTime = random(1, 10);
    packet->Time += DeltaTime;
    packet->HP -= random(1, 10);
    if (packet->HP < 0)
        packet->HP = 0;
    int DeltaX = random(0, packet->Speed * DeltaTime);
    packet->X += (random(0, 1) ? -1 : 1) * DeltaX;
    packet->Y += (random(0, 1) ? -1 : 1) * random(0, packet->Speed * DeltaTime - DeltaX);
}

void CheatPacket(Packet* packet)
{
    int type = random(1, 5);
    if (type == 1)
    {
        packet->Time -= random(1, 10000);
    }
    else if (type == 2)
    {
        packet->HP = -1;
    }
    else if (type == 3)
    {
        packet->ATK = 114;
        packet->DEF = 514;
    }
    else if (type == 4)
    {
        packet->Speed = 65536;
    }
    else if (type == 5)
    {
        packet->X += 32767;
        packet->Y -= 128;
    }
}

int main(int argc, char *argv[])
{
	system("mkdir anti-cheat_data"); 
    srand(time(NULL));
    for (int k = 1; k <= 50; ++k)
    {
        freopen(getFilename(k), "w", stdout);
        Packet send, receive;
        send.type = false, receive.type = true;
        RandPacket(&send);
        RandPacket(&receive);
        int T = random(2, 100000);
        printf("%d\n", T);
        T -= 2;
        PutPacket(send);
        PutPacket(receive);
        int AnswerType = random(1, 4);
        while (T--)
        {
            int PacketType = random(1, 2);
            if (PacketType == 1)
            {
                bool cheat = false;
                if (AnswerType == 2 || AnswerType == 4)
                {
                    int chance = random(0, 5000);
                    if (chance <= 1)
                    {
                        cheat = true;
                        CheatPacket(&send);
                    }
                }
                if (!cheat)
                    ModifyPacket(&send);
                PutPacket(send);
            }
            else if (PacketType == 2)
            {
                bool cheat = false;
                if (AnswerType == 3 || AnswerType == 4)
                {
                    int chance = random(0, 10000);
                    if (chance <= 1)
                    {
                        cheat = true;
                        CheatPacket(&receive);
                    }
                }
                if (!cheat)
                    ModifyPacket(&receive);
                PutPacket(receive);
            }
        }
        fclose(stdout);
        system(getCommand(k));
    }
    return 0;
}
