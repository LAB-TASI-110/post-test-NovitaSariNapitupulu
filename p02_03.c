#include <stdio.h>
#include <string.h>

// Struktur untuk data Menu
struct Menu {
    int id;
    char nama[30];
    int harga;
};

// Struktur untuk mencatat pesanan yang dibeli
struct Keranjang {
    char nama[30];
    int qty;
    int subtotal;
};

int main() {
    // 1. Inisialisasi Data Menu Kafetaria
    struct Menu daftarMenu[4] = {
        {1, "Nasi Goreng Del", 15000},
        {2, "Ayam Penyet", 18000},
        {3, "Mie Gomak", 10000},
        {4, "Teh Manis", 5000}
    };

    struct Keranjang belanja[10]; // Maksimal 10 jenis item per transaksi
    int jumlahItemBelanja = 0;
    int totalAkhir = 0;
    int pilihan, qty, uangBayar;
    char lanjut;

    printf("=== SISTEM OPERASIONAL KAFETARIA IT DEL ===\n\n");

    // 2. Menampilkan Menu
    printf("%-3s | %-20s | %-10s\n", "ID", "Menu Makanan", "Harga");
    printf("------------------------------------------\n");
    for(int i = 0; i < 4; i++) {
        printf("%-3d | %-20s | Rp %d\n", daftarMenu[i].id, daftarMenu[i].nama, daftarMenu[i].harga);
    }
    printf("------------------------------------------\n");

    // 3. Proses Input Pesanan
    do {
        printf("\nMasukkan ID Menu: ");
        scanf("%d", &pilihan);

        if(pilihan < 1 || pilihan > 4) {
            printf("ID Menu tidak tersedia!\n");
        } else {
            printf("Jumlah Porsi: ");
            scanf("%d", &qty);

            // Masukkan ke keranjang
            int idx = pilihan - 1;
            strcpy(belanja[jumlahItemBelanja].nama, daftarMenu[idx].nama);
            belanja[jumlahItemBelanja].qty = qty;
            belanja[jumlahItemBelanja].subtotal = daftarMenu[idx].harga * qty;
            
            totalAkhir += belanja[jumlahItemBelanja].subtotal;
            jumlahItemBelanja++;

            printf("Berhasil menambahkan ke pesanan.\n");
        }

        printf("Tambah menu lain? (y/n): ");
        scanf(" %c", &lanjut);

    } while ((lanjut == 'y' || lanjut == 'Y') && jumlahItemBelanja < 10);

    // 4. Output Struk Pembayaran
    printf("\n\n==========================================");
    printf("\n          STRUK KAFETARIA IT DEL          ");
    printf("\n==========================================");
    printf("\n%-20s %-5s %-10s", "Item", "Qty", "Subtotal");
    printf("\n------------------------------------------");
    
    for(int i = 0; i < jumlahItemBelanja; i++) {
        printf("\n%-20s %-5d Rp %-10d", belanja[i].nama, belanja[i].qty, belanja[i].subtotal);
    }

    printf("\n------------------------------------------");
    printf("\nTOTAL YANG HARUS DIBAYAR : Rp %d", totalAkhir);
    printf("\n==========================================");

    // 5. Input Pembayaran & Output Kembalian
    printf("\nMasukkan Uang Pembayaran: Rp ");
    scanf("%d", &uangBayar);

    if(uangBayar >= totalAkhir) {
        printf("Kembalian               : Rp %d", uangBayar - totalAkhir);
        printf("\n\nTransaksi Berhasil. Selamat Menikmati!\n");
    } else {
        printf("Uang tidak cukup! Kurang: Rp %d\n", totalAkhir - uangBayar);
    }

    return 0;
}