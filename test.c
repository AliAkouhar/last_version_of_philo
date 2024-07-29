#include <unistd.h>

// void	ft_sort_int_tab(int *tab, int size)
// {
// 	int	i;
// 	int	j;
// 	int	min;
//     int swap;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		min = i;
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (tab[j] < tab[min])
// 				min = j;
// 			j++;
// 		}
//         swap = tab[min];
//         tab[min] = tab[i];
//         tab[i] = swap;
// 		i++;
// 	}
// }
 void ft_sort_int_tab(int *tab, int size)
{
    int i;
    int j = 0;
    int swap;
    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (tab[j] > tab[j + 1])
            {
                swap = tab[j + 1];
                tab[j + 1] = tab[j];
                tab[j] = swap;
            }
            j++;
        }
        i++;
    }
}
 #include <stdio.h>
 int main()
 {
     int i = 0;
     int size = 5;
     int s[]= {2, 5, 8, 0, 1};
     ft_sort_int_tab(s,size);
     while(i < size )
     {
         printf("%d", s[i]);
         i++;
     }
 }