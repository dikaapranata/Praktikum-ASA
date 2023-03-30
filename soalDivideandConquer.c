/******************************************************************************

*******************************************************************************/
#include <stdio.h>

int main()
{
    int angka;
    int pangkat;
    long jumlah=1;
    long hasilmod;
    int mod=1000000;
    
    scanf("%d %d",&angka,&pangkat);
    for (int i=0;i<pangkat;i++){
        jumlah=(jumlah*angka)%mod;
    }
    printf("%ld\n",jumlah);

    return 0;
}
