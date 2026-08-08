int check_line(int *arr, int size) // size = 4
{
    int building_count;
    int i;
    int tmp;

    building_count = 0;
    i = 1;
    tmp =arr[0];
    while (i < size)
    {
        if (tmp < arr[i])
        {
            building_count++;
            tmp = arr[i];
        } 
        i++;
    }
    return (building_count);
}

int *make_line_array(int **src_arr, int pos) // 1 col1top  2 col2
{
    int *res_arr;

    res_arr = (int *)malloc(sizeof(int) * 4);
    if (res_arr == NULL)
        return ;

    int x;
    int y;
    int i;

    i = 0;
    if (pos >= 1 && pos <= 4)
    {
        x = 0;   
        while (size > x)
        {
            res_arr[i] = src_arr[pos - 1][x];
            x++;
            i++;
        }
    }
    if (pos >= 5 && pos <= 8)
    {
        x = 4;
        while (0 < x)
        {
            res_arr[i] = src_arr[pos - 5][x];
            x--;
            i++;
        }
    }
    if (pos >= 9 && pos <= 12)
    {    
        y = 0;
        while (size > y)
        {
            res_arr[i] = src_arr[y][pos - 9];
            y++;
            i++;
        }    
    }
    if (pos >= 13 && pos <= 16)
    {
        y = 4;
        while (0 < y)
        {
            res_arr[i] = src_arr[y][pos - 13]
            y--;
            i++;
        }
    }
    return res_arr;
}

make_boord_random() {

}


int *arr = {1, 3,  4, 5, 5, 6}
int arr[4][4] = { // arr[y][x]
    {1,2,3,4},
    {2,0,0,0},
    {3,0,0,0},
    {4,0,0,0}
}


char *argv[] = [
    "aaaaa",
    "bbbbbb",
    "cccccc"
]

argv[0] = "aaaaaa"
argv[1] = "bbbbb"
