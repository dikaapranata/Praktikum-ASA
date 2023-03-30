/******************************************************************************

*******************************************************************************/
#include <stdio.h>

int main()
{
    int angka;
    int pangkat;
    int jumlah=1;
    
    scanf("%d %d",&angka,&pangkat);
    for (int i=0;i<pangkat;i++){
        jumlah=jumlah*angka;
    }
    for (int step=1;step<=jumlah;step++){
        printf("step %d\n",step);
    }
    printf("%d",jumlah);

    return 0;
}
