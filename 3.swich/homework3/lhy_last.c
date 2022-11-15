//
// Created by xiexu on 2022/10/18.
//

/*
 * 7 5  // p = 8
 * 1 9 1 9 8 1 0
 * l           r
 *
 *
 *
 */


//#include <stdio.h>
//
//int main(void)
//{
//	int ant[10000] = { 0 };
//	int n = 0;
//	int k = 0;
//
//	scanf("%d%d", &n, &k);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", ant + i);
//	}
//
//	int pivot = ant[k];
//	int l = 0;
//	int r = n - 1;
//
//
//
//
//	while (l != r)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			while ((ant[l] < pivot) && (l != r))  //  <
//			{
//				l++;
//			}
//			while ((ant[r] > pivot) && (l != r))   //equation  >=
//			{
//				r--;
//			}
//			if (((ant[l] >= pivot) && (ant[r] <= pivot)) || (l == r))
//			{
//				break;
//			}
//		}
//		if (l == r)
//		{
//			break;
//		}
//
//		int a = ant[l];
//		ant[l] = ant[r];
//		ant[r] = a;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", ant[i]);
//	}
//
//	return 0;
//}
















#include <stdio.h>

int main(void)
{
	int ant[10000] = { 0 };
	int n = 0;
	int k = 0;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", ant + i);
	}

	int pivot = ant[k - 1];
	int l = 0;
	int r = n - 1;

	while (l != r)
	{
		for (int i = 0; i < n; i++)
		{

			/*
			 * 1 9 1 9 8 1 0  // p = 8
			 * l           r
			 * 1 0 1 9 8 1 9
			 *
			 * 5 3   // p = 5
             * 1 6 5 7 8
			 *
			 */



			if ((ant[l] < pivot) && (l != r))  //  <
			{
				l++;
			}
			if ((ant[r] > pivot) && (l != r))   //equation  >=
			{
				r--;
			}
			if (((ant[l] >= pivot) && (ant[r] <= pivot)) || (l == r))
			{
				break;
			}
		}
		if (l == r)
		{
			break;
		}

		int a = ant[l];
		ant[l] = ant[r];
		ant[r] = a;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", ant[i]);
	}

	return 0;
}





// da cuo te cuo