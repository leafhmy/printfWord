# include <stdio.h>
# include <stdlib.h>

void DrawText(char text[],char *a,char *b);

int main(void)
{
    char text[15];
    char tmp[4]={'1','3','1','4'};
    char *p,*q;
    p = text;
    q = tmp;
    printf("请输入要绘制的文字:");
    while(~scanf("%s",text))
    {
            DrawText(p,q,q+1);
            DrawText(p+4,q+2,q+3);
            printf("请输入要绘制的文字:");
    }

    return 0;
}

void DrawText(char text[],char *a,char *b)
{
    int i,j,k;
    int m,n,p;
    char mat[16][2];
    char second[16][2];
    FILE * HZK;
    if( (HZK = fopen("G:\\CodeData\\C语言\\HZK16","rb")) == NULL )
    {
        printf("文件不存在!");
        exit(-1);
    }

    /*获取区码和位码*/
    i = (text[0]&0x00ff) - 0xa0;
    j = (text[1]&0x00ff) - 0xa0;
    m = (text[2]&0x00ff) - 0xa0;
    n = (text[3]&0x00ff) - 0xa0;
    fseek(HZK,(94*(i-1) + (j-1))*32, SEEK_SET); //在HZK16中找到该字的点阵位置
    fread(mat,32,1,HZK); //读取32字节的点阵信息

    fseek(HZK,(94*(m-1) + (n-1))*32, SEEK_SET);
    fread(second,32,1,HZK);

    for(j=0; j<16; j++)
    {
        for(i=0; i<2; i++)
        {
            for(k=0; k<8; k++)
            {
                if( mat[j][i] & (0x80 >> k) ) //如果为1的位就显示
                {
                    printf("%c ",*a);
                }else {
                    printf("  "); //不是就输出空格
                }
            }

        }
        printf("     ");
        for(i=0; i<2; i++)
        {
            for(k=0; k<8; k++)
            {
                if( second[j][i] & (0x80 >> k) ) //如果为1的位就显示
                {
                    printf("%c ",*b);
                }else {
                    printf("  "); //不是就输出空格
                }
            }

        }
        printf("\n");
    }
    printf("\n");
}
