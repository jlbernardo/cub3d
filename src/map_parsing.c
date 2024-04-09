#include "cub3d.h"

int get_player_direction(t_game *cub)
{
	int i;
	int j;

	i = -1;
	while(cub->map_matrix[++i])
	{
		j = 0;
		while((cub->map_matrix[i][j] && ft_isdigit(cub->map_matrix[i][j]))
		|| (cub->map_matrix[i][j] && ft_isspace(cub->map_matrix[i][j])))
			j++;
		if(cub->map_matrix[i][j] && ft_isalpha(cub->map_matrix[i][j]))
		{
			if(cub->map_matrix[i][j] == 'N')
				cub->p1_start_direction = NO;
			else if(cub->map_matrix[i][j] == 'E')
				cub->p1_start_direction = EA;
			else if(cub->map_matrix[i][j] == 'S')
				cub->p1_start_direction = SO;
			else if(cub->map_matrix[i][j] == 'W')
				cub->p1_start_direction = WE;
			cub->p1 = coordinate(j, i);
			return (true);
		}
	}
	return (false);
}

void set_map(t_game * cub, t_get_map_helper *helper)
{
	int i;

	i = 0;
	cub->map_matrix = (char **)ft_calloc(helper->rows + 1, sizeof(char *));
	cub->map_data.raw_data = helper->line_bkp;
	*cub->map_data.raw_data = helper->position_bkp;
	while(*cub->map_data.raw_data && **cub->map_data.raw_data != '\n')
	{
		cub->map_matrix[i] = (char *)ft_calloc(ft_strlen(*cub->map_data.raw_data), sizeof(char));
		ft_strlcpy(cub->map_matrix[i], *cub->map_data.raw_data, ft_strlen(*cub->map_data.raw_data) + 1);
		cub->map_data.raw_data++;
		i++;
	}
	cub->map_matrix[i] = NULL;
}

int find_matrix(t_game *cub, t_get_map_helper *helper)
{
	while(*cub->map_data.raw_data)
	{
		if(ft_isspace(**cub->map_data.raw_data))
		{
			helper->position_bkp = *cub->map_data.raw_data;
			helper->line_bkp = cub->map_data.raw_data;
			while(ft_isspace(**cub->map_data.raw_data))
				(*cub->map_data.raw_data)++;
		}
		if(!ft_isdigit(**cub->map_data.raw_data))
			cub->map_data.raw_data++;
		else
		{
			while(*cub->map_data.raw_data)
			{
				if(ft_blank_line(*cub->map_data.raw_data))
					helper->broken_map = true;
				else if (*cub->map_data.raw_data && !helper->broken_map)
					helper->rows++;
				else
					return (false);
				cub->map_data.raw_data++;
			}
		}
	}
	return (true);
}

int	get_map(t_game *cub)
{
	t_get_map_helper helper;

	helper.position_bkp = NULL;
	helper.line_bkp = NULL;
	helper.rows = 0;
	helper.broken_map = false;
	if (!find_matrix(cub, &helper))
	{
		ft_printf("Broken map.\n");
		return (false);
	}
	set_map(cub, &helper);
	ft_print_matrix(cub->map_matrix);
	return(true);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t rgb_to_hex(t_game *cub, char *rgb, char flag)
{
	char		*trimmed;
	char		**colors;
	int			rgba[3];
	int			i;

	trimmed = ft_strtrim(rgb, "CF ");
	colors = ft_split(trimmed, ',');
	i = -1;
	while (++i < 3)
		rgba[i] = ft_atoi(colors[i]);
	if ((rgba[0] >= 0 && rgba[0] <= 255) && (rgba[1] >= 0 && rgba[1] <= 255)
	&& (rgba[2] >= 0 && rgba[2] <= 255))
	{
		if (flag == 'C')
			cub->map_data.c_color = get_rgba(rgba[0], rgba[1], rgba[2], 0xFF);
		else if (flag == 'F')
			cub->map_data.f_color = get_rgba(rgba[0], rgba[1], rgba[2], 0xFF);
		free(trimmed);
		ft_free_split(colors);
		return (true);
	}
	free(trimmed);
	ft_free_split(colors);
	return (false);
}

int get_colors(t_game *cub)
{
	char	**temp;
	char 	*trimmed;
	int		keys;

	temp = cub->map_data.raw_data;
	keys = 0;
	while (*temp)
	{
		trimmed = ft_strtrim(*temp, " ");
		if(!ft_strncmp("C", trimmed, 1) && (keys & (1 << 1)) < 1)
		{
			if (rgb_to_hex(cub, trimmed, 'C'))
				keys |= (1 << 1);
		}
		if(!ft_strncmp("F", trimmed, 1) && (keys & (1 << 0)) < 1)
		{
			if (rgb_to_hex(cub, trimmed, 'F'))
				keys |= 1;
		}
		temp++;
		free(trimmed);
	}
	if (keys == 3)
		return (true);
	return (false);
}

int set_texture_path(t_game *cub, char *trimmed)
{
	int keys;

	keys = 0;
	if(!ft_strncmp("NO", trimmed, 2) && (keys & (1 << 3)) < 1)
	{
		cub->map_data.north_tex_path = ft_strdup(ft_strchr(trimmed, 46));
		keys |= (1 << 3);
	}
	else if(!ft_strncmp("EA", trimmed, 2) && (keys & (1 << 2)) < 1)
	{
		cub->map_data.east_tex_path = ft_strdup(ft_strchr(trimmed, 46));
		keys |= (1 << 2);
	}
	else if(!ft_strncmp("SO", trimmed, 2) && (keys & (1 << 1)) < 1)
	{
		cub->map_data.south_tex_path = ft_strdup(ft_strchr(trimmed, 46));
		keys |= (1 << 1);
	}
	else if(!ft_strncmp("WE", trimmed, 2) && (keys & (1 << 0)) < 1)
	{
		cub->map_data.west_tex_path = ft_strdup(ft_strchr(trimmed, 46));
		keys |= 1;
	}
	return (keys);
}

int get_texture_path(t_game *cub)
{
	char	**temp;
	char 	*trimmed;
	int		keys;

	temp = cub->map_data.raw_data;
	keys = 0;
	while (*temp)
	{
		trimmed = ft_strtrim(*temp, " ");
		keys += set_texture_path(cub, trimmed);
		if (keys == 15)
		{
			free(trimmed);
			return (true);
		}
		temp++;
		free(trimmed);
	}
	ft_printf("Textture path not found.\n");
	return (false);
}

char **get_raw_data(char *map_path)
{
	int i;
	int fd;
	int rows;
	char *temp_line;
	char **raw_data;

	i = 0;
	fd = open(map_path, O_RDONLY);
	rows = count_rows(fd);
	close(fd);
	fd = open(map_path, O_RDONLY);
	raw_data = (char **)ft_calloc(rows + 1, sizeof(char *));
	while(i < rows)
	{
		temp_line = get_next_line(fd);
		raw_data[i] = (char *)ft_calloc(ft_strlen(temp_line) + 1, sizeof(char));
		if(raw_data[i] && temp_line)
			ft_strlcpy(raw_data[i], temp_line, ft_strlen(temp_line) + 1);
		i++;
		free(temp_line);
	}
	return(raw_data);
}
