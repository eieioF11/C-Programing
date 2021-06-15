#include <stdio.h>

struct student
{
	int num;
	char name[10];
	int score;
};

void Swap(struct student *a, struct student *b)
{
	struct student tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(struct student array[], int left, int right)
{
	int i, j, pivot;
	i = left;
	j = right + 1;
	pivot = left;
	do
	{
		do
		{
			i++;
		} while (array[i].score < array[pivot].score);
		do
		{
			j--;
		} while (array[pivot].score < array[j].score);
		//pivotより小さいものを左へ，大きいものを右へ
		if (i < j)
		{
			Swap(&array[i], &array[j]);
		}
	} while (i < j);
	Swap(&array[pivot], &array[j]);
	return j;
}
void quick_sort(struct student array[], int left, int right)
{
	int pivot;
	if (left < right)
	{
		pivot = partition(array, left, right);
		quick_sort(array, left, pivot - 1);
		quick_sort(array, pivot + 1, right);
	}
}

void babulsort(struct student st[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (st[j - 1].score > st[j].score)
				Swap(&st[j - 1], &st[j]);
		}
	}
}

int main()
{
	const int num = 9;
	struct student St[] =
		{
			{1, "Ichi", 90},
			{2, "Ni", 70},
			{3, "San", 80},
			{4, "Yon", 40},
			{5, "Go", 60},
			{6, "Roku", 81},
			{7, "Nana", 20},
			{8, "Hati", 95},
			{9, "Que", 10}};
	//babulsort(St,num);
	quick_sort(St, 0, num - 1);
	int i;
	for (i = 0; i < num; i++)
		printf("%d,%s,%d\n", St[i].num, St[i].name, St[i].score);
	return 0;
}
/*
[m17307@a717-pc14 T4]$ ./a.out
9,Que,10
7,Nana,20
4,Yon,40
5,Go,60
2,Ni,70
3,San,80
6,Roku,81
1,Ichi,90
8,Hati,95
[m17307@a717-pc14 T4]$ 
*/
