#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genfile(const char *fn)
{
	FILE *f;
	f=fopen(fn,"w");
	if (!f)
	{
		puts("���ļ�ʧ��");
		system("pause");
		return;
	}
	fprintf(f," ");
	fclose(f);
}

int main()
{
	char s[200],cmd[200];
	int n;
	puts("�������̷���");
	gets(s);
	puts("�������ļ�������");
	scanf("%d",&n);
	puts("���ڴ���Ŀ¼");
	srand(time(0));
	sprintf(s,"%c:\\%d",s[0],rand());
	sprintf(cmd,"md %s",s);
	system(cmd);
	puts("���������ļ�");
	for (int i=1;i<=n;i++)
	{
		sprintf(cmd,"%s\\%d",s,i);
		genfile(cmd);
		if (i%10000==0) printf("������%d��\n",i);
	}
	puts("����ɾ���ļ�");
	sprintf(cmd,"rd /s /q %s",s);
	system(cmd);
	puts("����ɹ�");
	system("pause");
	return 0;
}
