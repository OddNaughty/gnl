#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static int	read_line2(int fd, char **wip)
{
	char	*buf;
	int		rode;

	if ((buf = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (FAILURE);
	while ((rode = read(fd, buf, BUFF_SIZE)) > 0)
	{
		*wip = ft_strfreejoin(wip, buf);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
		ft_strclr(buf);
	}
	ft_strdel(&buf);
	if (rode == 0 && *wip == NULL)
		return (0);
	return (rode == -1 ? -1 : 1);
}

void		wip_to_line(char **line, char **wip)
{
	char	*n;
	char	*tmp;

	n = ft_strchr(*wip, '\n');
	if (n == NULL)
	{
		*line = ft_strdup(*wip);
		ft_strdel(wip);
		return ;
	}
	*line = ft_strsub(*wip, 0, ft_strlen(*wip) - ft_strlen(n));
	tmp = ft_strsub(*wip, ft_strlen(*line) + 1, ft_strlen(n + 1));
	ft_strdel(wip);
	if (ft_strlen(tmp))
		*wip = tmp;
}

int			add_to_struct(t_gnl *list, char **line, int fd)
{
	int		ret;

	list = malloc(sizeof(t_gnl));
	if (list->wip == NULL || ft_strchr(list->wip, '\n') == NULL)
		if ((ret = read_line2(fd, &list->wip)) != 1)
			return (ret);
	wip_to_line(line, &(list->wip));
	return (1);
}

int			choose_fd(t_list **list, int fd, char **line)
{
	int		ret;
	t_list	*tmp;
	t_gnl	*link;
	t_gnl	*test;

	if ((ret = add_to_struct(link, line, fd)) != 1)
		return (ret);
	tmp = *list;
	while (tmp)
	{
		test =
		if (tmp->content->fd == (int)fd)
		{
			tmp->content = link;
			tmp->content_size = sizeof(link);
		}
		tmp = tmp->next;
	}
	if (!tmp)
		ft_lstadd(&tmp, ft_lstnew(link, sizeof(link)));
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static t_list	 	*b_list = NULL;
	t_gnl				*link;
	int			ret;

	link = NULL;
	if (!line)
		return (FAILURE);
	*line = NULL;
	if (b_list == NULL)
	{
		ret = add_to_struct(link, line, fd);
		b_list = ft_lstnew(link, sizeof(link));
		return (ret);
	}
	return (choose_fd(&b_list, fd, line));
}