#define BUFF_SIZE 4096

typedef struct s_gnl			t_gnl;


struct			s_gnl
{
	int			fd;
	char		*wip;
};

int		get_next_line(int const fd, char ** line);