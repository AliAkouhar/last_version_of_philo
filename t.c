#include <stdio.h>
#include <stdlib.h>

 int countnbr(int nbr)
{
    int count;
    while (nbr != 0)
    {
		nbr /= 10;
		count++;
    }
    return (count);
}
char *ft_itoa(int nbr)
{
	int count;
	char *str;
	int i;

	if (nbr == INT_MIN)
	count = countnbr(nbr);
	if (nbr < 0)
	{
		str = malloc(sizeof(char) * (count + 2));
		if (!str)
			return (NULL);
#include <limits.h>
		nbr = -nbr;
		str[0] = '-';
		str[count + 2] = '\0';
		i = count;
		while (i >= 1)
		{
			str[i] = (nbr % 10) + '0';
			nbr = nbr / 10;
			i--;
		}
	}
	else
	{
		str = malloc(sizeof(char) * (count + 1));
		if (!str)
			return (NULL);
		str[count] = '\0';
		i = count - 1;
		while (i >= 0)
		{
			str[i] = (nbr % 10) + '0';
			nbr = nbr / 10;
			i--;
		}
	}
	return (str);
}
int main()
{
	printf("%s\n", ft_itoa(INT_MAX));
}
/* #include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int i = 0;
	int j = 0;
	int size;
	int *ptr;
	size = end - start;
	ptr = (int *) malloc (sizeof (int) * size);
	if (ptr == NULL)
		return (NULL);
	while (end >= start)
	{
		ptr[i] = end;
		end--;
		i++;
	}
	return (ptr);
}
#include <stdio.h>
int main()
{
    int min = -2;
    int max = 8;
    int *result;
    int i;

    result = ft_rrange(-3, 0);

    if (result == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i <= max - min; i++)
        printf("%d ", result[i]);

    printf("\n");

    return 0;
} */