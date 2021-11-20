void removeLake(char **map, int width_i, int height_i)
{
    if (map[height_i][width_i] == '#')
        return;

    map[height_i][width_i] = '#';
    removeLake(map, width_i + 1, height_i);
    removeLake(map, width_i - 1, height_i);
    removeLake(map, width_i, height_i + 1);
    removeLake(map, width_i, height_i - 1);
}

int lakes(char **map, int width, int height)
{
    int nb_lakes = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == '.')
            {
                nb_lakes++;
                removeLake(map, j, i);
            }
        }
    }
    return nb_lakes;
}
