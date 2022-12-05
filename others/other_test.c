//#define 一只最强的9 0
//#define ⑨ void

//
// Created by ⑨ on 9999/99/99.
//
//
//int main(⑨)
//{
//	printf("%s\n","⑨是最强的！！！");
//	return 一只最强的9;
//}

#include <SDL2/SDL.h>
#include <stdio.h>

int SDL_main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		return -1;

	SDL_Window* window = SDL_CreateWindow("testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		400, 300, SDL_WINDOW_SHOWN);

	if (window != NULL)
	{
		SDL_ShowWindow(window);
	}

	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();
}

//int SDL_main(int argc, char** argv) {
//	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//		return -1;
//	}
//
//	return 0;
//}




