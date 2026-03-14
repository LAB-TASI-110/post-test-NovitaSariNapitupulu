#include <stdio.h>
#include <string.h>

int main() {
    char kota[4];
    float beratButet, beratUcok, totalBerat;
    long hargaPerKg = 0;
    long totalOngkir, diskon = 0;
    char promo[50] = "Tidak Ada Promo";

    // 1. Input Data
    printf("Masukkan Kode Kota (MDN/JKT/BLG): ");
    scanf("%s", kota);
    printf("Masukkan Berat Paket Butet (kg): ");
    scanf("%f", &beratButet);

    // 2. Logika Penentuan Harga per Kota
    if (strcmp(kota, "MDN") == 0) {
        hargaPerKg = 15000;
    } else if (strcmp(kota, "JKT") == 0) {
        hargaPerKg = 20000;
    } else if (strcmp(kota, "BLG") == 0) {
        hargaPerKg = 5000;
    } else {
        printf("Kode Kota tidak dikenal!\n");
        return 1;
    }

    // 3. Perhitungan Berat (Asumsi: Barang Ucok akan lebih berat 2kg dari Butet)
    beratUcok = beratButet + 2.0;
    totalBerat = beratButet + beratUcok;

    // 4. Hitung Total Ongkos Sebelum Promo
    totalOngkir = totalBerat * hargaPerKg;

    // 5. Logika Promo (Contoh: Diskon 10% jika berat > 10kg)
    if (totalBerat > 10) {
        diskon = totalOngkir * 0.10;
        totalOngkir = totalOngkir - diskon;
        strcpy(promo, "Diskon Hemat 10% (Berat > 10kg)");
    }

    // 6. Output Struk Pembayaran
    printf("\n==================================\n");
    printf("       STRUK PEMBAYARAN DEL-EXPRESS\n");
    printf("==================================\n");
    printf("Kota Tujuan          : %s\n", kota);
    printf("Berat Paket Butet    : %.2f kg\n", beratButet);
    printf("Berat Paket Ucok     : %.2f kg\n", beratUcok);
    printf("Total Berat          : %.2f kg\n", totalBerat);
    printf("----------------------------------\n");
    printf("Total Ongkos Kirim   : Rp %ld\n", totalOngkir);
    printf("Informasi Promo      : %s\n", promo);
    printf("==================================\n");

    return 0;
}