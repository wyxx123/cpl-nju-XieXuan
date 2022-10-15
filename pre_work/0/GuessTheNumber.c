//
// Created by xiexu on 2022/9/24.
//

/*{
	 * 1.print the menu--function-menu
	 * 1.5 . pro-setting: range:1-100 chances: 7
	 * [2].0.escape  1.print the rules 2.setting 3.play
	 * case 2: user input MaxRange, chances
	 * case 3: 1.use LeftChances = chances-- fuction-game
	 *         {
	 *         		1.say: please input a number
	 *         		2.users input a number
	 *         		[3]. more:  >
	 *         			 less:  <
	 *         			 =:     break
	 *         		4.LeftChances--
	 *         }(when LeftChances > 0)
	 * 2.LeftChances=0:loss
	 *   >0   win
	 *}(input)
	 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

int menu(void)
{
	printf("*****************************************************\n");
	printf("***         1.rules             2.setting         ***\n");
	printf("***         3.play              0.exit            ***\n");
	printf("*****************************************************\n");
}

void prosetting(int* Maxrange, int* chances)
{
	*Maxrange = 100;
	*chances = 7;
}

int game(int Maxrange, int chances)
{
	int Truth = rand() % Maxrange + 1;
	int input = 0;
	do
	{
		printf("you have %d chance(s), please guess a number:>", chances);
		scanf("%d", &input);
		if (input == Truth)
		{
			break;
		}
		else if (input > Truth)
		{
			printf("the target number is smaller.\n");
		}
		else
		{
			printf("the target number is bigger.\n");
		}
		chances--;
	} while (chances);
	return chances;
}

int main()
{
	srand(time(NULL));
	int Maxrange = 100;
	int chances = 7;
	int input = 0;
	int LeftChances = 0;
	prosetting(&Maxrange, &chances);
	do
	{
		menu();
		printf("please make a choice:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			printf("guess a number between 1 and %d within %d times,you will be told "
				   "whether the target number is smaller or bigger than the number you guess.\n", Maxrange, chances);
			break;
		case 2:
			printf("you can choose Maxrange and chances by yourself.\n");
			printf("Maxrange:>");
			scanf("%d", &Maxrange);
			assert(Maxrange > 0);
			printf("chances:>");
			scanf("%d", &chances);
			assert(chances > 0);
			printf("setting save!\n");
			break;
		case 3:
			LeftChances = game(Maxrange, chances);
			if (LeftChances == 0)
			{
				printf("you loss\n");
			}
			else
			{
				printf("you win\n");
			}
			break;
		default:
			printf("please input right number!\n");
		}
	} while (input);
	return 0;
}