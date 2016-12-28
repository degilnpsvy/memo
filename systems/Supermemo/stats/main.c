#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    unsigned int buf[3];
    int i,max=0;

    for(i=0;i<3;i++)
        buf[i]=0;

    fp=fopen("time.tim" ,"rb");
    for(i=0;i<4000;i++)
    {
        fread(buf,sizeof(unsigned int), 3, fp);
        if (buf[1]-buf[0]> max) max=buf[1]-buf[0];
        /* printf("%X-%X=%d\n", buf[0], buf[1], buf[1]-buf[0]); */
    }

    printf("%d\n", max);
    close(fp);
    return 0;
}
