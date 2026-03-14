#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char kode[10];
    int jumlah;
    int subtotal = 0;
    int totalBayar = 0;
    
    printf("==========================================\n");
    printf("     SISTEM OPERASIONAL KAFETARIA IT DEL  \n");
    printf("==========================================\n");
    printf("DAFTAR MENU:\n");
    printf("KODE  | MENU             | HARGA\n");
    printf("------------------------------------------\n");
    printf("M01   | Nasi Goreng      | Rp15.000\n");
    printf("M02   | Ayam Penyet      | Rp18.000\n");
    printf("M03   | Mie Goreng       | Rp12.000\n");
    printf("D01   | Teh Manis (Es/P) | Rp5.000\n");
    printf("D02   | Kopi Del         | Rp7.000\n");
    printf("------------------------------------------\n");
    printf("Ketik 'END' pada Kode Menu untuk selesai.\n\n");

    // Perulangan untuk mencatat pesanan
    do {
        printf("Masukkan Kode Menu   : ");
        scanf("%s", kode);

        // Cek apakah user ingin mengakhiri input
        if (strcmp(kode, "END") == 0 || strcmp(kode, "end") == 0) {
            break;
        }

        printf("Masukkan Jumlah      : ");
        scanf("%d", &jumlah);

        // Percabangan untuk menentukan harga berdasarkan kode
        if (strcmp(kode, "M01") == 0) {
            subtotal = 15000 * jumlah;
            printf("-> Nasi Goreng x%d : Rp%d\n", jumlah, subtotal);
        } else if (strcmp(kode, "M02") == 0) {
            subtotal = 18000 * jumlah;
            printf("-> Ayam Penyet x%d : Rp%d\n", jumlah, subtotal);
        } else if (strcmp(kode, "M03") == 0) {
            subtotal = 12000 * jumlah;
            printf("-> Mie Goreng x%d  : Rp%d\n", jumlah, subtotal);
        } else if (strcmp(kode, "D01") == 0) {
            subtotal = 5000 * jumlah;
            printf("-> Teh Manis x%d   : Rp%d\n", jumlah, subtotal);
        } else if (strcmp(kode, "D02") == 0) {
            subtotal = 7000 * jumlah;
            printf("-> Kopi Del x%d    : Rp%d\n", jumlah, subtotal);
        } else {
            printf("!! Kode Menu Tidak Dikenal !!\n");
            subtotal = 0;
        }

        totalBayar += subtotal;
        printf("------------------------------------------\n");

    } while (1); // Terus berjalan sampai bertemu 'break' di dalam

    // Menampilkan Struk Pembayaran
    printf("\n\n==========================================");
    printf("\n          STRUK PEMBAYARAN KAFETARIA      ");
    printf("\n==========================================");
    printf("\nTOTAL YANG HARUS DIBAYAR: Rp%d", totalBayar);
    printf("\n==========================================");
    printf("\nTerima kasih! Selamat menikmati hidangan.\n");

    return 0;
}