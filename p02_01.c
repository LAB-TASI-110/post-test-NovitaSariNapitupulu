#include <stdio.h>
#include <string.h>

int main() {
    char kota[20];
    float beratButet, beratUcok, totalBerat, hargaPerKg, totalOngkir;
    char promo[30];

    printf("=== Sistem Pengiriman Del-Express ===\n");
    printf("Ketik 'END' pada Kode Kota untuk keluar.\n\n");

    while (1) {
        printf("Masukkan Kode Kota Tujuan: ");
        scanf("%s", kota);

        // Berhenti jika input adalah END
        if (strcmp(kota, "END") == 0) {
            printf("Program Selesai. Terima kasih!\n");
            break;
        }

        printf("Masukkan Berat Paket Butet (kg): ");
        scanf("%f", &beratButet);

        // Logika: Berat Ucok 2kg lebih berat dari Butet
        beratUcok = beratButet + 2;
        totalBerat = beratButet + beratUcok;

        // Menentukan harga per kg berdasarkan kota
        if (strcmp(kota, "MDN") == 0) {
            hargaPerKg = 10000; // Contoh harga Medan
        } else if (strcmp(kota, "JKT") == 0) {
            hargaPerKg = 20000; // Contoh harga Jakarta
        } else if (strcmp(kota, "BLG") == 0) {
            hargaPerKg = 15000; // Contoh harga Balige
        } else {
            hargaPerKg = 0;
            printf("Kota tidak terdaftar! Mengasumsikan biaya Rp 0.\n");
        }

        // Hitung ongkos kirim dasar
        totalOngkir = totalBerat * hargaPerKg;

        // Logika Promo dan Diskon
        if (totalBerat >= 10) {
            strcpy(promo, "Diskon 10%");
            totalOngkir = totalOngkir * 0.90; // Potong 10%
        } else if (totalBerat >= 5) {
            strcpy(promo, "Diskon 5%");
            totalOngkir = totalOngkir * 0.95; // Potong 5%
        } else {
            strcpy(promo, "Tidak ada promo");
        }

        // Menampilkan Struk Pembayaran
        printf("\n------------------------------\n");
        printf("Struk Pembayaran\n");
        printf("Kota Tujuan: %s\n", kota);
        printf("Berat Paket Butet: %.1f kg\n", beratButet);
        printf("Berat Paket Ucok: %.1f kg\n", beratUcok);
        printf("Total Berat: %.1f kg\n", totalBerat);
        printf("Total Ongkos Kirim: Rp %.0f\n", totalOngkir);
        printf("Promo: %s\n", promo);
        printf("------------------------------\n\n");
    }

    return 0;
}