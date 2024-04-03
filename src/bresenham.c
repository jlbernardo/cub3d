#include "cub3d.h"

int		absolute(int num);

void	line(t_game *cub, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;

	sx = 1;
	sy = 1;
	dx = absolute(x2 - x1);
	dy = absolute(y2 - y1);
	if (x1 > x2)
		sx = -1;
	if (y1 > y2)
		sy = -1;
	error = dx - dy;
	while (true)
	{
		mlx_put_pixel(cub->gen, y1, x1, 0x21F2FCFF);
		if (x1 == x2 && y1 == y2)
			break ;
		if (error * 2 >= -dy)
		{
			if (x1 == x2)
				break ;
			error -= dy;
			x1 += sx;
		}
		if (error * 2 <= dx)
		{
			if (y1 == y2)
				break ;
			error += dx;
			y1 += sy;
		}
	}
}

int	absolute(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}