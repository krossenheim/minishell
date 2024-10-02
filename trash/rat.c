# include <stdio.h>
# include <stdbool.h>

bool	is_quote(char c)
{
	if (c == '\'')
		return (true);
	if (c == '\"')
		return (true);
	return (false);
}

static	int	get_ac_all_size(t_ll_real *src)
{
	int				len;
	t_match_info 	*cur;
	
	len = 0;
	while (src)
	{
		cur = ((t_match_info *) src->content);
		len += ft_strlen(cur->name);
		src = src->next;
		if (src)
			len++;
	}
	return (len + 1);
}

char	*ac_all(t_ll_real *lst)
{
	int				len;
	int				j;
	char			*replaced;
	t_match_info 	*cur;
	
	replaced = malloc(sizeof(char) * get_ac_all_size(lst));
	if (!replaced)
		return (NULL);
	len = 0;
	while (lst)
	{
		j = 0;
		cur = ((t_match_info *) lst->content);
		while (cur->name[j] != '\0')
			replaced[len++] = cur->name[j++];
		lst = lst->next;
		if (lst)
			replaced[len++] = ' ';
	}
	return (replaced);
}


char	*ft_strchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i] != '\0' || (char) c == '\0')
	{
		if ((char) s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

static bool	q_esc(char *str, int index)
{
	if (index < 0)
		return (false);
	if (index == 0 && is_quote(str[index]))
		return (false);
	if (index > 1 && str[index - 1] == '\\' && str[index - 2] == '\\')
		return (false);
	if (index > 0 && str[index - 1] == '\\' && is_quote(str[index]))
		return (true);
	return (false);
}

int	in_q(char *str, int index)
{
	int		s;
	int		d;
	int		i;

	i = 0;
	s = 0;
	d = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && !q_esc(str, i) && d % 2 == 0)
			s++;
		if (str[i] == '\"' && !q_esc(str, i) && s % 2 == 0)
			d++;
		if (i == index)
		{
			if (s % 2 != 0 && (q_esc(str, i) || str[i] != '\''))
				return (2);
			if (d % 2 != 0 && (q_esc(str, i) || str[i] != '\"'))
				return (1);
			return (0);
		}
		i++;
	}
	return (-1);
}




int main() {
    char *str = "h\\ey\"Hey\"'hey\\\''";
  int i = 0;
  while (str[i])
  {
    printf("(I%d)%c=%d\n",i, str[i], in_q(str, i));
    i++;
  }
  return 0;
}
