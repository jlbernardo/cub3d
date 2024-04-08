#include "cub3d.h"

// # define NO			0
// # define SO			1
// # define EA			2
// # define WE			3

// typedef struct s_coord
// {
// 	double		x;
// 	double		y;
// }				t_coord;

// typedef enum t_bool
// {
// 	false,
// 	true
// }	t_bool;

// typedef struct s_map_data
// {
// 	char		*north_tex_path;
// 	char		*east_tex_path;
// 	char		*south_tex_path;
// 	char		*west_tex_path;
// 	uint32_t	ceiling_color;
// 	uint32_t	floor_color;
// }				t_map_data;

// typedef struct s_game
// {
// 	int			p1_start_direction;
// 	char		**map_matrix;
// 	t_coord		p1;
// 	t_map_data	map_data;
// }				t_game;

// int	ft_isspace(char c)
// {
// 	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\n'
// 		|| c == '\f')
// 		return (1);
// 	return (0);
// }

// int ft_blank_line(char *line)
// {
// 	while(*line && ft_isspace(*line))
// 		line++;
// 	if(*line)
// 		return (0);
// 	return (1);
// }

// void	ft_print_matrix(char **matrix)
// {
// 	while (*matrix)
// 	{
// 		ft_printf("%s", *matrix);
// 		matrix++;
// 	}
// }

// int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// int get_player_direction(t_game *cub, char **map)
int get_player_direction(t_game *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(cub->map_matrix[i])
	{
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
		i++;
		j = 0;
	}
	return (false);
}

void set_map(t_game * cub, char **matrix, int rows)
{
	int i;

	i = 0;
	cub->map_matrix = (char **)ft_calloc(rows + 1, sizeof(char *));
	cub->map_data.raw_data = matrix;
	// *cub->map_data.raw_data = position_bkp;
	while(*cub->map_data.raw_data && **cub->map_data.raw_data != '\n')
	{
		cub->map_matrix[i] = (char *)ft_calloc(ft_strlen(*cub->map_data.raw_data), sizeof(char));
		ft_strlcpy(cub->map_matrix[i], *cub->map_data.raw_data, ft_strlen(*cub->map_data.raw_data) + 1);
		cub->map_data.raw_data++;
		i++;
	}
	cub->map_matrix[i] = NULL;
}

int find_matrix(t_game *cub, s_temp *temp)
{
	while(*cub->map_data.raw_data)
	{
		if(ft_isspace(**cub->map_data.raw_data))
		{
			s_temp->line_bkp = cub->map_data.raw_data;
			// position_bkp = *cub->map_data.raw_data;
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
					s_temp->broken_map = true;
				else if (*cub->map_data.raw_data && !s_temp->broken_map)
					s_temp->rows++;
				else
					return (false);
				cub->map_data.raw_data++;
			}
		}
	}
	return (true);
}

// int	get_map(t_game *cub, char **raw_data)
int	get_map(t_game *cub)
{
	struct s_temp {
		char **line_bkp;
		int rows;
		t_bool broken_map;
	}	temp;
	// char *position_bkp;
	// int i = 0;

	temp.line_bkp = NULL;
	// *position_bkp = NULL;
	temp.rows = 0;
	temp.broken_map = false;
	if (!find_matrix(cub, &temp))
		return (false);
	set_map(cub, temp.line_bkp, temp.rows);
	// while(*cub->map_data.raw_data)
	// {
	// 	if(ft_isspace(**cub->map_data.raw_data))
	// 	{
	// 		line_bkp = cub->map_data.raw_data;
	// 		position_bkp = *cub->map_data.raw_data;
	// 		while(ft_isspace(**cub->map_data.raw_data))
	// 			(*cub->map_data.raw_data)++;
	// 	}
	// 	if(!ft_isdigit(**cub->map_data.raw_data))
	// 		cub->map_data.raw_data++;
	// 	else
	// 	{
	// 		while(*cub->map_data.raw_data)
	// 		{
	// 			if(ft_blank_line(*cub->map_data.raw_data))
	// 				broken_map = true;
	// 			else if (*cub->map_data.raw_data && !broken_map)
	// 				rows++;
	// 			else
	// 				return (false);
	// 			cub->map_data.raw_data++;
	// 		}
	// 	}
	// }
	// cub->map_matrix = (char **)ft_calloc(rows + 1, sizeof(char *));
	// cub->map_data.raw_data = line_bkp;
	// *cub->map_data.raw_data = position_bkp;
	// while(*cub->map_data.raw_data && **cub->map_data.raw_data != '\n')
	// {
	// 	cub->map_matrix[i] = (char *)ft_calloc(ft_strlen(*cub->map_data.raw_data), sizeof(char));
	// 	ft_strlcpy(cub->map_matrix[i], *cub->map_data.raw_data, ft_strlen(*cub->map_data.raw_data) + 1);
	// 	cub->map_data.raw_data++;
	// 	i++;
	// }
	// cub->map_matrix[i] = NULL;
	return(true);
}

uint32_t rgb_to_hex(t_game *cub, char *rgb, char flag)
{
	uint32_t 	hex;
	char		**colors;
	int			red;
	int			green;
	int			blue;

	hex = 0x00000000;
	colors = ft_split(rgb, ',');
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	// if ((red >= 0 && red <= 255)
	// && (green >= 0 && green <= 255)
	// && (blue >= 0 && blue <= 255))
	// 	hex = get_rgba(red, green, blue, 0xFF);
	if ((red >= 0 && red <= 255)
	&& (green >= 0 && green <= 255)
	&& (blue >= 0 && blue <= 255))
	{
		if (flag == 'C')
			cub->map_data.ceiling_color = get_rgba(red, green, blue, 0xFF);
		else if (flag == 'F')
			cub->map_data.floor_color = get_rgba(red, green, blue, 0xFF);
		return (true);
	}
	return (false);
}

// int get_colors(t_game *cub, char **raw_data)
int get_colors(t_game *cub)
{
	char 	*trimmed;
	// char	*trimmed_bkp;
	int		keys;

	keys = 0;
	while (*cub->map_data.raw_data)
	{
		trimmed = ft_strtrim(*cub->map_data.raw_data, " ");
		// trimmed_bkp = trimmed;
		if(!ft_strncmp("C", trimmed, 1) && (keys & (1 << 1)) < 1)
		{
			(*trimmed)++;
			// cub->map_data.ceiling_color = rgb_to_hex(cub, trimmed);
			// if(cub->map_data.ceiling_color == 256)
			// 	return (false);
			if (rgb_to_hex(cub, trimmed, 'C'))
				keys |= (1 << 1);
		}
		if(!ft_strncmp("F", trimmed, 1) && (keys & (1 << 0)) < 1)
		{
			(*trimmed)++;
			// cub->map_data.floor_color = rgb_to_hex(cub, trimmed);
			// if(cub->map_data.floor_color == 256)
			// 	return (false);
			if (rgb_to_hex(cub, trimmed, 'F'))
				keys |= 1;
		}
		cub->map_data.raw_data++;
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

// int get_texture_path(t_game *cub, char **raw_data)
int get_texture_path(t_game *cub)
{
	char 	*trimmed;
	int		keys;

	keys = 0;
	while (*cub->map_data.raw_data)
	{
		trimmed = ft_strtrim(*cub->map_data.raw_data, " ");
		// if(!ft_strncmp("NO", trimmed, 2) && (keys & (1 << 3)) < 1)
		// {
		// 	cub->map_data.north_tex_path = ft_strdup(ft_strchr(trimmed, 46));
		// 	keys |= (1 << 3);
		// }
		// else if(!ft_strncmp("EA", trimmed, 2) && (keys & (1 << 2)) < 1)
		// {
		// 	cub->map_data.east_tex_path = ft_strdup(ft_strchr(trimmed, 46));
		// 	keys |= (1 << 2);
		// }
		// else if(!ft_strncmp("SO", trimmed, 2) && (keys & (1 << 1)) < 1)
		// {
		// 	cub->map_data.south_tex_path = ft_strdup(ft_strchr(trimmed, 46));
		// 	keys |= (1 << 1);
		// }
		// else if(!ft_strncmp("WE", trimmed, 2) && (keys & (1 << 0)) < 1)
		// {
		// 	cub->map_data.west_tex_path = ft_strdup(ft_strchr(trimmed, 46));
		// 	keys |= 1;
		// }
		keys += set_texture_path(cub, trimmed);
		if (keys == 15)
			return (true);
		cub->map_data.raw_data++;
		free(trimmed);
	}
	return (false);
}

// int count_rows(int fd)
// {
// 	int rows;
// 	char *temp_line;

// 	rows = 0;
// 	temp_line = get_next_line(fd);
// 	while(temp_line)
// 	{
// 		rows++;
// 		free(temp_line);
// 		temp_line = get_next_line(fd);
// 	}
// 	return (rows);
// }

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

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	t_game	cub;

// 	// RAW DATAFILE TEST
// 	char **raw_data_bkp = get_raw_data(argv);
	// char **raw_data = raw_data_bkp;
	// while(*raw_data)
	// {
	// 	printf("%s", *raw_data);
	// 	free(*raw_data);
	// 	raw_data++;
	// }
	// free(raw_data_bkp);

	// TEXTURE TO PATH TEST
	// if(get_texture_path(&cub, raw_data_bkp))
	// 	printf("RIGHT INPUT\n");
	// else
	// 	printf("WRONG OUTPUT\n");
	// printf("%s\n", cub.map_data.north_tex_path);
	// printf("%s\n", cub.map_data.west_tex_path);
	// printf("%s\n", cub.map_data.south_tex_path);
	// printf("%s\n", cub.map_data.east_tex_path);

	// COLOR TEST
	// if(!get_colors(&cub, raw_data_bkp))
	// {
	// 	printf("WRONG COLOR\n");
	// 	return (0);
	// }
	// printf("Ceiling color: %08X \n", cub.map_data.ceiling_color);
	// printf("Floor color: %08X \n", cub.map_data.floor_color);

	//MATRIX TEST
// 	if(!get_map(&cub, raw_data_bkp))
// 		printf("BROKEN MAP!\n");
// 	else
// 		ft_print_matrix(cub.map_matrix);

// 	//P1 POSITION TEST
// 	if(!get_player_direction(&cub, cub.map_matrix))
// 		printf("Player not found\n");
// 	else
// 		printf("Player looking for: %d\n", cub.p1_start_direction);
// 		printf("Player x: %f\n", cub.p1.x);
// 		printf("Player y: %f\n", cub.p1.y);
// 	return (0);
// }