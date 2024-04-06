# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef enum t_bool
{
	false,
	true
}	t_bool;

typedef struct s_map_data
{
	char		*north_tex_path;
	char		*east_tex_path;
	char		*south_tex_path;
	char		*west_tex_path;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
}				t_map_data;

typedef struct s_game
{
	t_map_data	map_data;
}				t_game;

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
uint32_t rgb_to_hex(char *rgb)
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
	if ((red >= 0 && red <= 255)
	&& (green >= 0 && green <= 255)
	&& (blue >= 0 && blue <= 255))
		hex = get_rgba(red, green, blue, 0xFF);
	else
		return (256);
	return (hex);
}

int get_colors(t_game *cub, char **raw_data)
{
	char 	*trimmed;
	char	*trimmed_bkp;
	int		keys;

	keys = 0;
	while (*raw_data)
	{
		trimmed = ft_strtrim(*raw_data, " ");
		trimmed_bkp = trimmed;
		if(!ft_strncmp("C", trimmed, 1) && (keys & (1 << 1)) < 1)
		{
			(*trimmed)++;
			cub->map_data.ceiling_color = rgb_to_hex(trimmed);
			if(cub->map_data.ceiling_color == 256)
				return (false);
			keys |= (1 << 1);
		}
		if(!ft_strncmp("F", trimmed, 1) && (keys & (1 << 0)) < 1)
		{
			(*trimmed)++;
			cub->map_data.floor_color = rgb_to_hex(trimmed);
			if(cub->map_data.floor_color == 256)
				return (false);
			keys |= 1;
		}
		raw_data++;
		free(trimmed);
	}
	if (keys == 3)
		return (true);
	return (false);
}

// int get_texture_path(t_game *cub, char **raw_data)
// {
// 	char 	*trimmed;
// 	int		keys;

// 	keys = 0;
// 	while (*raw_data)
// 	{
// 		trimmed = ft_strtrim(*raw_data, " ");
// 		if(!ft_strncmp("NO", trimmed, 2) && (keys & (1 << 3)) < 1)
// 		{
// 			cub->map_data.north_tex_path = ft_strdup(ft_strchr(trimmed, 46));
// 			keys |= (1 << 3);
// 		}
// 		else if(!ft_strncmp("EA", trimmed, 2) && (keys & (1 << 2)) < 1)
// 		{
// 			cub->map_data.east_tex_path = ft_strdup(ft_strchr(trimmed, 46));
// 			keys |= (1 << 2);
// 		}
// 		else if(!ft_strncmp("SO", trimmed, 2) && (keys & (1 << 1)) < 1)
// 		{
// 			cub->map_data.south_tex_path = ft_strdup(ft_strchr(trimmed, 46));
// 			keys |= (1 << 1);
// 		}
// 		else if(!ft_strncmp("WE", trimmed, 2) && (keys & (1 << 0)) < 1)
// 		{
// 			cub->map_data.west_tex_path = ft_strdup(ft_strchr(trimmed, 46));
// 			keys |= 1;
// 		}
// 		if (keys == 15)
// 			return (true);
// 		raw_data++;
// 		free(trimmed);
// 	}
// 	return (false);
// }

int count_rows(int fd)
{
	int rows;
	char *temp_line;

	rows = 0;
	temp_line = get_next_line(fd);
	while(temp_line)
	{
		rows++;
		free(temp_line);
		temp_line = get_next_line(fd);
	}
	return (rows);
}

char **get_raw_data(char **argv)
{
	int i;
	int fd;
	int rows;
	char *temp_line;
	char **raw_data;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	rows = count_rows(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
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

int main(int argc, char **argv)
{
	(void)argc;
	t_game	cub;

	// RAW DATAFILE TEST
	char **raw_data_bkp = get_raw_data(argv);
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
	if(!get_colors(&cub, raw_data_bkp))
	{
		printf("WRONG COLOR\n");
		return (0);
	}
	printf("Ceiling color: %08X \n", cub.map_data.ceiling_color);
	printf("Floor color: %08X \n", cub.map_data.floor_color);
	return (0);
}