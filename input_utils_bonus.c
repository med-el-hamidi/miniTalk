#include "client_bonus.h"

static int	_parse(char *str, char *arg, int *len);
static int	_is_int(char *arg, int len);

void	handle_input(char *nbr)
{
	int		len;
	char	arg[12];

	ft_bzero(arg, sizeof(arg));
	len = 0;
	len = _parse(nbr, arg, &len);
	if (len == -1 || !_is_int(arg, len))
		exit_failure("NOT_INT: ./client_bonus <SERVER_PID> <\"MESSAGE\">\n");
}

static int	_parse(char *str, char *arg, int *len)
{
	int	k;
	int	flag;

	k = 0;
	flag = 0;
	if (str[k] == '-' || str[k] == '+')
		arg[(*len)++] = str[k++];
	while (str[k])
	{
		if (!ft_isdigit(str[k]))
			return (-1);
		if (!flag && str[k] != '0')
			flag = 1;
		if (flag)
		{
			arg[(*len)++] = str[k];
			if ((*len) > 11)
				break ;
		}
		k++;
	}
	if (!flag && str[k - 1] == '0')
		arg[(*len)] = '0';
	return (*len);
}

static int	_is_int(char *arg, int len)
{
	int	ans;

	if (len <= 2 && (arg[0] == '0' || arg[1] == '0'))
		ans = 1;
	else if (len == 1 && (arg[0] == '+' || arg[0] == '-'))
		ans = 0;
	else if (len > 11)
		ans = 0;
	else if (len == 11 && (ft_isdigit(arg[0])
			|| (arg[0] == '+' && ft_strncmp(arg, "+2147483647", len) > 0)
			|| (arg[0] == '-' && ft_strncmp(arg, "-2147483648", len) > 0)))
		ans = 0;
	else if (len == 10 && ft_strncmp(arg, "2147483647", len) > 0)
		ans = 0;
	else
		ans = 1;
	return (ans);
}
