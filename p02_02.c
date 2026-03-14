#include <stdio.h>

int main() {
    int n, i, kategoriDicari;
    int totalStokKategori = 0;

    // 1. Input jumlah total data (N)
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &n);

    // Deklarasi array untuk menyimpan deret stok dan kategori
    int deretStok[n];
    int kodeKategori[n];

    // 2. Input deret stok dan kategori barang
    printf("\n--- Input Data Inventaris Rak ---\n");
    for(i = 0; i < n; i++) {
        printf("Barang ke-%d:\n", i + 1);
        printf("  Jumlah stok (s%d): ", i + 1);
        scanf("%d", &deretStok[i]);
        printf("  Kode kategori   : ");
        scanf("%d", &kodeKategori[i]);
    }

    // 3. Input kategori yang ingin dicari
    printf("\nMasukkan kode kategori yang ingin dihitung total stoknya: ");
    scanf("%d", &kategoriDicari);

    // 4. Proses Filter dan Penjumlahan
    for(i = 0; i < n; i++) {
        // Cek apakah kategori barang saat ini sesuai dengan yang diminta
        if(kodeKategori[i] == kategoriDicari) {
            totalStokKategori += deretStok[i];
        }
    }

    // 5. Output Hasil
    printf("\n-------------------------------------------");
    printf("\nTotal stok untuk kategori %d adalah: %d unit", kategoriDicari, totalStokKategori);
    printf("\n-------------------------------------------\n");

    return 0;
}