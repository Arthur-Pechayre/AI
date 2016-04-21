#include "header.h"

void 	count_size_tab(t_game *game, char *content_map)
{
	int l;
	int c;
	int i;

	i = 0;
	l = 0;
	c = 0;
	while (content_map[i] != '\0')
	{
		if (content_map[i] != '\n')
			c++;
		else
		{
			c = 0;
			l++;
		}
		i++;
	}
	game->map.l = l + 1;
	game->map.c = c;
}

char 	*get_content_map(char *map)
{
	char *content;
	int	handle;

	if ((content = malloc(sizeof(char) * 1024)) == 0)
		return ("NULL");
	handle = open(map, O_RDONLY);
	if (handle < 0)
	{
		my_putstr("\nProblème d'ouverture du fichier map\n");
		return ("NULL");
	}
	if (read(handle, content, 1024) < 0)
	{
		my_putstr("\nProblème de lecture du fichier map\n");
		return ("NULL");
	}
	close(handle);
	return (content);
}

int init_map(t_game *game, char* content_map)
{
	int    	i;
	int    	j;
	int 	cursor;

	cursor = 0;
	if((game->map.map = malloc(sizeof(char*) * (game->map.l + 1))) == NULL)
		return (0);
	for (i = 0; i < game->map.l; ++i)
	{
		if((game->map.map[i] = malloc((game->map.c + 1))) == NULL)
			return (0);
		for (j = 0; j < game->map.c; ++j)
			game->map.map[i][j] = content_map[cursor++];
		cursor++;
	}
	return (1);
}

int 	is_correct(char *map)
{
	int 	i;
	int 	start;
	int 	finish;

	start = 0;
	finish = 0;
	for (i = 0; map[i] != '\0'; i++)
	{
		if (map[i] != ' ' && map[i] != '+' && map[i] != '@' 
			&& map[i] != '#' && map[i] != '\n')
		{
			error_reporting(&error_reporting_map_null);
			return (0);
		}
		if (map[i] == '@')
			start++;
		else if (map[i] == '#')
			finish++;
	}
	if (start != 1 || finish != 1)
	{
		error_reporting(&multi_start_or_finish);
		return (0);
	}
	return (1);
}

int		check_map(char** argv, t_game *game)
{
	char	*content_map;

	content_map = get_content_map(argv[3]);
	if (my_strcmp(content_map, "NULL") != 0 && is_correct(content_map))
	{
		count_size_tab(game, content_map);
		init_map(game, content_map);
		free(content_map);
		return(1);
	}
	return (0);
}