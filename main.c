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
    printf("������Ҫ���Ƶ�����:");
    while(~scanf("%s",text))
    {
            DrawText(p,q,q+1);
            DrawText(p+4,q+2,q+3);
            printf("������Ҫ���Ƶ�����:");
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
    if( (HZK = fopen("G:\\CodeData\\C����\\HZK16","rb")) == NULL )
    {
        printf("�ļ�������!");
        exit(-1);
    }

    /*��ȡ�����λ��*/
    i = (text[0]&0x00ff) - 0xa0;
    j = (text[1]&0x00ff) - 0xa0;
    m = (text[2]&0x00ff) - 0xa0;
    n = (text[3]&0x00ff) - 0xa0;
    fseek(HZK,(94*(i-1) + (j-1))*32, SEEK_SET); //��HZK16���ҵ����ֵĵ���λ��
    fread(mat,32,1,HZK); //��ȡ32�ֽڵĵ�����Ϣ

    fseek(HZK,(94*(m-1) + (n-1))*32, SEEK_SET);
    fread(second,32,1,HZK);

    for(j=0; j<16; j++)
    {
        for(i=0; i<2; i++)
        {
            for(k=0; k<8; k++)
            {
                if( mat[j][i] & (0x80 >> k) ) //���Ϊ1��λ����ʾ
                {
                    printf("%c ",*a);
                }else {
                    printf("  "); //���Ǿ�����ո�
                }
            }

        }
        printf("     ");
        for(i=0; i<2; i++)
        {
            for(k=0; k<8; k++)
            {
                if( second[j][i] & (0x80 >> k) ) //���Ϊ1��λ����ʾ
                {
                    printf("%c ",*b);
                }else {
                    printf("  "); //���Ǿ�����ո�
                }
            }

        }
        printf("\n");
    }
    printf("\n");
}
