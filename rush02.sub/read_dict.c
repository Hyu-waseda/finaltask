#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define BUF_SIZE 512

int main(void)
{
    // 変数定義
    int fd1, fd2;
    int byte_num;
    char buf[BUF_SIZE];
	int i;

    // 変数初期化
    fd1 = 0;
    fd2 = 0;
    byte_num = 0;
	// ファイルのオープン
    fd1 = open("./numbers.dict", O_RDONLY);  // 読み込み専用でファイルを開く
	byte_num = read(fd1, &buf[0], 150);  // ファイルから100バイト読み込み
	i = 0;
	while (buf[i] != '\0')
	{
		write(1, &buf[i], 1);
		i++;
	}
	printf("%s\n", buf);
}