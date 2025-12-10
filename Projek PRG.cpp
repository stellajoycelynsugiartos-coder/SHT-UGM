#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama;
    float suhu;
    int sistol, diastol, tidur, olahraga;

    cout << "=== Smart Health Checker ===\n\n";

    cout << "Nama: ";
    getline(cin, nama);
    if (nama == "") nama = "Pengguna";

    cout << "Suhu tubuh (C): ";
    cin >> suhu;

    cout << "Tekanan darah sistolik: ";
    cin >> sistol;

    cout << "Tekanan darah diastolik: ";
    cin >> diastol;

    cout << "Durasi tidur (jam): ";
    cin >> tidur;

    cout << "Frekuensi olahraga/minggu: ";
    cin >> olahraga;

    cout << "\n--- HASIL ANALISIS ---\n";

    // ==========================
    // 1. SUHU
    // ==========================
    string statusSuhu;
    int skorSuhu = 0;

    if (suhu < 36.1) {
        statusSuhu = "Terlalu Rendah (Hipotermia Ringan)";
        skorSuhu = 10;
    }
    else if (suhu <= 37.5) {
        statusSuhu = "Normal";
        skorSuhu = 25;
    }
    else if (suhu <= 38.0) {
        statusSuhu = "Demam Ringan";
        skorSuhu = 15;
    }
    else {
        statusSuhu = "Demam Tinggi";
        skorSuhu = 5;
    }

    // ==========================
    // 2. TEKANAN DARAH 
    // ==========================
    string statusBP;
    int skorBP = 0;

    if (sistol < 90 || diastol < 60) {
        statusBP = "Hipotensi";
        skorBP = 10;
    }
    else if (sistol < 120 && diastol < 80) {
        statusBP = "Normal";
        skorBP = 35;
    }
    else if (sistol >= 120 && sistol <= 129 && diastol < 80) {
        statusBP = "Elevated";
        skorBP = 25;
    }
    else if ((sistol >= 130 && sistol <= 139) || (diastol >= 80 && diastol <= 89)) {
        statusBP = "Hipertensi Stage 1";
        skorBP = 15;
    }
    else if ((sistol >= 140 && sistol <= 180) || (diastol >= 90 && diastol <= 120)) {
        statusBP = "Hipertensi Stage 2";
        skorBP = 5;
    }
    else if (sistol > 180 || diastol > 120) {
        statusBP = "Hypertensive Crisis";
        skorBP = 0;
    }

    // ==========================
    // 3. TIDUR 
    // ==========================
    string statusTidur;
    int skorTidur = 0;

    if (tidur >= 7 && tidur <= 9) {
        statusTidur = "Ideal";
        skorTidur = 20;
    }
    else if (tidur >= 6 && tidur < 7) {
        statusTidur = "Cukup (Kurang Ideal)";
        skorTidur = 15;
    }
    else if (tidur < 6) {
        statusTidur = "Kurang Tidur";
        skorTidur = 5;
    }
    else { // >9 jam
        statusTidur = "Terlalu Lama (Oversleep)";
        skorTidur = 10;
    }

    // ==========================
    // 4. OLAHRAGA 
    // ==========================
    string statusOlahraga;
    int skorOlahraga = 0;

    if (olahraga >= 3 && olahraga <= 5) {
        statusOlahraga = "Aktif Ideal";
        skorOlahraga = 20;
    }
    else if (olahraga >= 1 && olahraga <= 2) {
        statusOlahraga = "Aktif Ringan";
        skorOlahraga = 15;
    }
    else if (olahraga >= 6) {
        statusOlahraga = "Sangat Aktif (Potensi Overtraining)";
        skorOlahraga = 10;
    }
    else { // 0
        statusOlahraga = "Tidak Aktif";
        skorOlahraga = 5;
    }

    // ==========================
    // TAMPILKAN HASIL
    // ==========================
    cout << "- Suhu       : " << statusSuhu << endl;
    cout << "- Tekanan BP : " << statusBP << endl;
    cout << "- Tidur      : " << statusTidur << endl;
    cout << "- Olahraga   : " << statusOlahraga << endl;

    // ==========================
    // TOTAL SKOR
    // ==========================
    int skorTotal = skorSuhu + skorBP + skorTidur + skorOlahraga;

    cout << "\nSkor Kesehatan: " << skorTotal << "/100" << endl;

    cout << "Kesimpulan: ";
    if (skorTotal >= 85) cout << "Sangat Sehat";
    else if (skorTotal >= 70) cout << "Cukup Sehat";
    else if (skorTotal >= 50) cout << "Kurang Sehat";
    else cout << "Perlu Perhatian Serius";
    cout << "\n\n";

    // ==========================
    // REKOMENDASI
    // ==========================
    cout << "--- Rekomendasi ---\n";

    if (suhu > 37.5)
        cout << "- Perbanyak minum dan istirahat.\n";
    if (statusBP == "Hipotensi")
        cout << "- Perbanyak cairan, konsumsi garam secukupnya, hindari berdiri tiba-tiba.\n";
    if (statusBP == "Hipertensi Stage 2")
        cout << "- Pertimbangkan konsultasi ke dokter.\n";
    if (statusBP == "Hipertensi Stage 1")
        cout << "- Kurangi garam, jaga berat badan, pantau tekanan darah.\n";
    if (tidur < 6)
        cout << "- Usahakan tidur minimal 7 jam.\n";
    if (olahraga == 0)
        cout << "- Mulai rutin berolahraga minimal 3x per minggu.\n";

    cout << "\nTerima kasih telah menggunakan program ini!\n";

    return 0;
}

