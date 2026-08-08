#include <unistd.h>

int check_queens(int *ten, int y, int x)//新しいクイーンを置けるかどうかチェックする関数
{
	int i;

	i = 0;

	while (i < y) //0列目から自分の手前の列まで確認
	//すでにクイーンを置いた０列目から、yー１列目までを一つずつ確認します
	{
		if (ten[i] == x) //同じ行に誰かいる //行の衝突、すでに他の列の同じ行にクイーンがいたら０（false）を返す
			return (0);
		if (ten[i] - i == (x - y))//斜め方向に誰かいる // x - y の値が同じなら、右下がりの斜めライン上にいる。
			return (0);
		if (ten[i] + i == (x + y))// もう一つの斜めに誰かいる// 右上がりの斜めライン上にいる。
			return (0);
		i++;
	}
	return 1; // OKなら１
}

//再帰的にクイーンを置いていく関数//バックトラッキング
int	queen_add(int *ten, int y)//y列目にクイーンを置く処理
{
	int	count;
	int	x;
	int	i;
	char	c;

	i = 0;
	count = 0;
	if (y == 10)
	// 配列ten[10]は要素数が10個あるから、y==10は10列全てにクイーンを置き終わった状態
	{
		while(i < 10)
		{
			c = ten[i] + '0';
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		return (1);
	}
	x = 0;
	while (x < 10)
	{
		if (check_queens(ten, y, x))
		{
			ten[y] = x; //記録
			count += queen_add(ten, y + 1);
			//次の列へ進み、戻ってきたら回の数を加算
		}
		x++;
	}
	return (count);
}

int ft_ten_queens_puzzle(void)
{
	//x 横（行）、y 縦（列）
	//x の行にはクイーンは１コマだけ
	//y の列にはクイーンは１コマだけ
	//斜めにも置いてはダメ
	int ten[10];

	return (queen_add(ten, 0)); //0行目からスタート
}

#include <stdio.h>

int main(void)
{
	int count;

	count = ft_ten_queens_puzzle();
	printf ("%d", count);
	return 0;
}
