
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	
	int price[10];
	int size;
	cin >> size; // ukuran array
	for(int i=0;i<size;i++){
		// memasukkan nilai pada array
		cin >> price[i];
	}
	
	// awal nilai profit
	int profit=0;
	
	// initial harga tertinggi
	int biggestPrice=0;
	
	// membaca array dari kanan ke kiri 
	for(int i=size-1;i>=0;i--){
		
		// bandingkan nilai biggest price dengan nilai saat ini
		// bila nilai price saat ini lebih besar maka nilai biggestPrice berubah menjadi nilai itu
		/*ketik algo dibawah ini*/
		biggestPrice=max(biggestPrice,price[i]);
		
		// bandingkan nilai biggestPrice dengan nilai saat ini
		// dan SELISIHNYA akan ditambahkan ke dalam profit
		/*ketik algo dibawah ini */
		profit+=(biggestPrice-price[i]);
		
	}
	
	cout << profit;
	
	return 0;
}




















