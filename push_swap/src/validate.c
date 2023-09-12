#include "common.h"

static bool	is_numeric(char *value)
{
	if (*value == '-')
		++value;
	while (*value != '\0')
		if (!ft_isdigit(*value++))
			return (false);
	return (true);
}

bool	is_numeric_array(int count, char **values)
{
	int	i;

	i = 1;
	while (i < count)
		if (!is_numeric(values[i++]))
			return (false);
	return (true);
}

void	on_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static int	nbr_count(int value, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value == value)
			++i;
		stack = stack->next;
	}
	return (i);
}

bool	has_duplicates(t_stack *stack)
{
	t_stack	*first;

	first = stack_first(stack);
	while (stack != NULL)
	{
		if (nbr_count(stack->value, first) > 1)
			return (true);
		stack = stack->next;
	}
	return (false);
}
