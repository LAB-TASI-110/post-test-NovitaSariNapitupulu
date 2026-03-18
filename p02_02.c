#include <stdio.h>
#include <string.h> // Diperlukan untuk fungsi strcmp (membandingkan teks)

int main() {
    int n, i;
    int stok[100];            // Array untuk menyimpan deret stok
    char kategori[100][20];   // Array 2 dimensi untuk menyimpan deret kode kategori
    char target_kategori[20]; // Kategori yang ingin dicari
    int total_stok_target = 0;

    // 1. Input Jumlah Total Data (N)
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &n);

    // 2. Input Deret Stok dan Kategori
    for (i = 0; i < n; i++) {
        printf("\nData ke-%d:\n", i + 1);
        printf("  Masukkan Kode Kategori: ");
        scanf("%s", kategori[i]);
        printf("  Masukkan Jumlah Stok  : ");
        scanf("%d", &stok[i]);
    }

    // 3. Input Kategori yang ingin dicari
    printf("\n------------------------------------\n");
    printf("Masukkan Kode Kategori yang ingin ditotal: ");
    scanf("%s", target_kategori);

    // 4. Proses Filter dan Penjumlahan
    for (i = 0; i < n; i++) {
        // strcmp mengembalikan 0 jika kedua teks sama persis
        if (strcmp(kategori[i], target_kategori) == 0) {
            total_stok_target += stok[i];
        }
    }

    // 5. Output Hasil
    printf("\n====================================\n");
    printf("Total stok untuk kategori '%s' adalah: %d\n", target_kategori, total_stok_target);
    printf("====================================\n");

    return 0;
}