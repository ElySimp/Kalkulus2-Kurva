# Kalkulus2-Kurva

Proyek Kalkulus2-Kurva merupakan sebuah aplikasi untuk memvisualisasikan dan menganalisis kurva 2D dan 3D menggunakan bahasa pemrograman C++. Proyek ini dibuat untuk mendukung pembelajaran Kalkulus II, terutama pada topik kurva dan grafik.

Catatan: Anda dapat mengimpor pustaka eksternal lainnya, namun file main harus tetap berupa file C++.

### Fitur

- Visualisasi Kurva 2D: Implementasi dan contoh kasus untuk memplot kurva dua dimensi.
- Visualisasi Kurva 3D: Contoh penerapan visualisasi kurva dalam ruang tiga dimensi.
- Integrasi dengan Pustaka Plotting: Menggunakan header matplotlibcpp.h untuk memanfaatkan kemampuan plotting dari Python (matplotlib).
- File Uji Coba: Terdapat direktori khusus untuk file test guna memastikan implementasi berjalan dengan baik.

### Struktur Direktori

- 2 Dimensi/ : Berisi kode sumber dan contoh implementasi untuk kurva 2D.
- 3 Dimensi/ : Berisi kode sumber dan contoh implementasi untuk kurva 3D.
- Progress/ : Berisi riwayat pengembangan program 2D & 3D dari waktu ke waktu
- Test Files/ : Kumpulan file untuk pengujian dan validasi implementasi.
- matplotlibcpp.h : Header file untuk integrasi dengan pustaka matplotlib di C++.

  File Utama :
- [Program 2 Dimensi](https://github.com/ElySimp/Kalkulus2-Kurva/blob/main/2%20Dimensi/2dimensi.cpp) : Berisi file AKHIR program 2 dimensi
- [Program 3 Dimensi](https://github.com/ElySimp/Kalkulus2-Kurva/blob/main/3%20Dimensi/3dimensi.cpp) : Berisi file AKHIR program 3 dimensi

### Persyaratan

- Compiler C++: Pastikan anda memiliki compiler C++ yang mendukung standar minimal C++11 (misalnya, g++ atau clang).
- Python & matplotlib: Karena pustaka plotting menggunakan Python, pastikan Python dan modul matplotlib telah terinstall di sistem anda.

### Instalasi & Penggunaan

Siapkan 4 path directory file yang dibutuhkan sebelum running program. Yaitu :

1. Path ke directory matplotlib berada saat ini [File Matplotlib
   ](https://github.com/ElySimp/Kalkulus2-Kurva/blob/main/matplotlibcpp.h)Jangan lupa untuk mengganti line 5 & line 20 File matplotlibcpp.h sesuai dengan PATH directory kalian

   ```bash
   "C:\Kalkulus2-Kurva"
   ```
2. Path ke file include python yang anda gunakan

   ```bash
   "C:\Python\Python311\include"
   ```
3. Path ke file include numpy python

   ```bash
   "C:\Python\Python311\Lib\site-packages\numpy\_core\include"
   ```
4. Path ke python libs

   ```bash
   "C:\Python\Python311\libs"
   ```

Setelah itu gabung semua path diatasmenjadi satu command untuk execute programnya melalui terminal. Contoh seperti ini

```bash
g++ NamaFile.cpp -o NamaOutput(Bebas) -I "PATH_1" -I "PATH_2" -I "PATH_3" -L "PATH_4" -lVersiPython
```

```bash
g++ 2dimensi.cpp -o 2dimensi -I "C:\Kalkulus2-Kurva" -I "C:\Programs\Python\Python311\include" -I "C:\Python\Python311\Lib\site-packages\numpy\_core\include" -L "C:\Python\Python311\libs" -lpython311
```

Setelah command diatas dimasukkan ke terminal, akan ada file exe yang keluar dan buka file tersebut dari file manager. Selamat mencoba
