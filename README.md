# SoalShiftSISOP20_modul2_C08

### Vania Meilani Taqiyyah 05111840000045
### Ivan Abdillah Rahman 05111840000137

#### SOAL 1 
```
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan
ketentuan sebagai berikut:
a. Program menerima 4 argumen berupa:
i. Detik: 0-59 atau * (any value)
ii. Menit: 0-59 atau * (any value)
iii. Jam: 0-23 atau * (any value)
iv. Path file .sh
b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak
sesuai
c. Program hanya menerima 1 config cron
d. Program berjalan di background (daemon)
e. Tidak boleh menggunakan fungsi system()
Contoh: ./program \* 34 7 /home/somi/test.sh
Program dengan argumen seperti contoh di atas akan menjalankan script test.sh setiap
detik pada jam 07:34.
```
##### Penjelasan soal 1a
`int cekangka (char a[]){
  for (int x = 0; x < strlen(a); x++){
    if (a[x] < '0' || a[x] > '9'){
      return 0;
    }
  }
  return 1;
}`
Fungsi ini digunakan untuk mengecek input yang dimasukkan adalah angka atau bukan.

`int argumen[4];
    for (int x = 1; x < 4; x++){
      if (cekangka(argv[x])){
        argumen[x]=atoi(argv[x]);
        if (argumen[x] < 0) printf("Input ke %d tidak valid\n", x);`
Digunakan untuk melakukan comparing, jika yang diinput bukan angka, program tidak bisa dijalankan.

`if (argumen[1] > 59 && argumen [2] > 59 && argumen [3] >23){
    printf("Input out of range\n");
    exit(EXIT_FAILURE);`
Digunakan untuk membatasi nilai input, bahwa batas nilai maksimal detik harus 59, menit 59, dan jam 23. Jika melakukan input di luar batas, program tidak bisa dijalankan.

##### Penjelasan soal 1b
`if (argc == 5){
    int argumen[4];
    for (int x = 1; x < 4; x++){
      if (cekangka(argv[x])){
        argumen[x]=atoi(argv[x]);
        if (argumen[x] < 0) printf("Input ke %d tidak valid\n", x);
      }
      else if (cekbintang(argv[x])) argumen[x] = -1;
    
    else{
      printf("Input ke %d tidak valid\n", x);
      exit(EXIT_FAILURE);
    }
  }`
`printf("Input ke %d tidak valid\n", x);` yang pertama akan muncul apabila input yang dimasukkan bukan angka. Sedangkan untuk yang kedua akan muncul apabila input yang dimasukkan bukan angka maupun bintang.
  
`if (argumen[1] > 59 && argumen [2] > 59 && argumen [3] >23){
    printf("Input out of range\n");
    exit(EXIT_FAILURE);`
`printf("Input out of range\n");` akan muncul apabila input yang dimasukkan di luar range yang telah ditentukan (batas maksima detik adalah 59, menit 59, jam 23).
 
`else{
printf("Argumen tidak valid\n");
exit(EXIT_FAILURE);`

`printf("Argumen tidak valid\n");` akan muncul apabila jumlah argumen yang dimasukkan tid.ak sesuai dengan jumlah yang diminta, yaitu 5.

##### Penjelasan soal 1c
`if (argc == 5)`, argc yang diinput adalah 5, karena soal yang diminta adalah hanya menerima 1 config cron.

##### Penjelasan soal 1d
`pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process


  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  
  while(1){
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    if ((tm->tm_sec==argumen[1] || argumen[1]==-1) && (tm->tm_min==argumen[2] || argumen[2]==-1) && (tm->tm_hour==argumen[3] || argumen[3]==-1)){
      pid_t child_id;
      child_id = fork();

      int status;

      if (child_id == 0){
        char *argexe[]={"bash", argv[4], NULL};
        execv("/bin/bash", argexe);
      }
    }
    sleep(1);
  }
}`
Program di atas menunjukkan bahwa program yang dieksekusi berjalan di daemon, menggunakan template daemon yang telah dimodifikasi pada perulangan while(1).

##### Penjelasan soal 1e
`char *argexe[]={"bash", argv[4], NULL};
        execv("/bin/bash", argexe);`
Fungsi di atas digunakan untuk menjalankan program .sh tanpa menggunakan fungsi system().

#### SOAL 2
```
Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia
merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat
sebuah program.
a. Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat
sebuah program C yang per 30 detik membuat sebuah folder dengan nama
timestamp [YYYY-mm-dd_HH:ii:ss].
b. Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari
https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap
gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah

detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-
mm-dd_HH:ii:ss].

c. Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan
folder akan di delete(sehingga hanya menyisakan .zip).

d. Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut men-
generate sebuah program "killer" yang siap di run(executable) untuk

menterminasi semua operasi program tersebut. Setelah di run, program yang
menterminasi ini lalu akan mendelete dirinya sendiri.
e. Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu
MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan
dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen
-b. Ketika dijalankan dalam MODE_A, program utama akan langsung
menghentikan semua operasinya ketika program killer dijalankan. Untuk
MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi
membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua
folder terisi gambar, terzip lalu di delete).
Kiwa lalu terbangun dan sedih karena menyadari programnya hanya sebuah mimpi.
Buatlah program dalam mimpi Kiwa jadi nyata!
Catatan:
- Tidak boleh memakai system().
- Program utama harus ter-detach dari terminal
Hint:
- Gunakan fitur picsum.photos untuk mendapatkan gambar dengan ukuran
tertentu
- Epoch Unix bisa didapatkan dari time()
```
##### Penjelasan soal 2a
nomor 2 menggunakan daemon :
```
pid_t pid, sid;        // Variabel untuk menyimpan PID
  int stat; 

  pid = fork();     // Menyimpan PID dari Child Process

  if (pid < 0) 
  {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) 
  {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) 
  {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) 
  {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
```

```
  rawtime = time(NULL);
  timeinfo = localtime ( &rawtime ); 
  strcpy (file, "/home/vaniameith/khususoal2/");
  strftime (lalaland, SIZE, "%Y-%m-%d_%H:%M:%S", timeinfo);
  strcat (file, lalaland);

    child = fork();
   if (child == 0) {
     sleep(30);
     char *argv[] = {"mkdir","-p",file,NULL};
     execv("/bin/mkdir", argv);
   } 
 ```
 - `rawtime = time(NULL);`, untuk mengambil local time pada linux.
 - `timeinfo = localtime ( &rawtime ); `, membuat variabel `timeinfo` untuk menyimpan local waktu yang telah diperoleh.
 - `strcpy (file, "/home/vaniameith/khususoal2/");`. `strcpy` untuk meng-copy `"/home/vaniameith/khususoal2/"` ke variabel string file.
 - `strftime (lalaland, SIZE, "%Y-%m-%d_%H:%M:%S", timeinfo);`. `strftime` fungsi untuk format tanggal dan waktu dan diambil dari variable string timeinfo tersebut.
 - `strcat (file, lalaland);`, untuk menggabungkan isi dalam `file` dan `lalaland`.
 - ` sleep(30);`, memberikan jeda waktu 30 detik antara pembuatan file/direktori pertama dengan direktori selanjutnya.
 - `char *argv[] = {"mkdir","-p",file,NULL};`, untuk membuat direktori baru dengan nama format dari `file` berupa timestamp dan isi dari direktori tersebut kosong.

#### SOAL 3
```
Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia
memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan
(multiprocessing).
a. Program buatan jaya harus bisa membuat dua direktori di
“/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu
lima detik kemudian membuat direktori yang kedua bernama “sedaap”.
b. Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori
“/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak
hanya itu tugasnya.
c. Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di
dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan
pengelompokan, semua file harus dipindahkan ke
“/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke
“/home/[USER]/modul2/indomie/”.
d. Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/”
harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu
3 detik kemudian membuat file bernama “coba2.txt”.
(contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).
Karena Jaya terlalu banyak tugas dia jadi stress, jadi bantulah Jaya agar bisa membuat
program tersebut.
Catatan :
- Tidak boleh memakai system().
- Tidak boleh memakai function C mkdir() ataupun rename().
- Gunakan exec dan fork
- Direktori “.” dan “..” tidak termasuk
```
##### Penjelasan soal 3a
```
child = fork();
  if (child == 0) {
    char *argv[] = {"mkdir","-p","/home/vaniameith/modul2/indomie",NULL};
    execv("/bin/mkdir", argv);
  }
  ```
  - `child = fork()`, untuk membuat proses baru (child) dengan menduplikasi proses utama.
  - `child == 0`, bernilai sama dengan 0 untuk menandakan bahwa proses tersebut sukses.
  - `char *argv[]`, mendeklarasikan sebuah penyimpanan hasil dari proses/perintah di dalamnya.
  - `"mkdir","-p","/home/vaniameith/modul2/indomie",NULL`. `mkdir` untuk membuat sebuah direktori/folder baru. `-p` yang berarti parent atau path yang berarti membuat semua direktori yang ada mengarah ke direktori baru/yang belum ada sebelumnya. `/home/vaniameith/modul2/indomie` adalah untuk mengarah tempat pembuatan direktori baru di dalam folder modul2 dengan nama indomie.
  - `execv("/bin/mkdir", argv);`, mengeksekusi argv.
  
  ```
  while((waitpid(child,&status,0))>0);
  child1 = fork();
  if (child1 == 0) {
    sleep(5);
    char *argv[] = {"mkdir","-p","/home/vaniameith/modul2/sedaap",NULL};
    execv("/bin/mkdir", argv);
  }
  ```
  - `while((waitpid(child,&status,0))>0)`, untuk menunggu child proses untuk berhenti 
  - `sleep(5)`, untuk memberikan jeda 5 detik dalam pembuatan antara output satu dengan output selanjutnya. Di soal ini, memberikan jeda pembuatan direktori indomie dengan direktori sedaap.
  - `/home/vaniameith/modul2/sedaap`, membuat direktori baru di dalam modul2 dengan nama sedaap.
  
 ##### Penjelasan soal 3b
 ```
  child2 = fork();
  if (child2 == 0) { 
    char *argv[] = {"unzip","/home/vaniameith/modul2/jpg.zip","-d","/home/vaniameith/modul2",NULL};
    execv("/usr/bin/unzip", argv);
  }
  ```
  - `unzip -d`, untuk meng-unzip sebuah folder/file 
  - `"/home/vaniameith/modul2/jpg.zip","-d","/home/vaniameith/modul2"`. `/home/vaniameith/modul2/jpg.zip` untuk menunjukkan letak dari file/folder yang akan di unzip. `/home/vaniameith/modul2` menentukan tempat untuk unzip dari folder tersebut.
  
##### Penjelasan soal 3c
```
if (child3 == 0){
    char *argv[] = {"find","/home/vaniameith/modul2/jpg",
                    "-mindepth","1","-type","f","-exec","mv",
                    "{}","/home/vaniameith/modul2/sedaap",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }
  ```
  - `"find","/home/vaniameith/modul2/jpg"`, berfungsi untuk menemukan isi/file/direktori yang sedang dicari dalam direktori/folder jpg.
  - `"-mindepth","1"`, fungsi yang menandakan bahwa proses masuk ke dalam direktori tujuan sejumlah satu kali saja. Fungsi ini masih berhubungan dengan fungsi `find`. Fungsi ini mengecek semua isi dalam direktori tujuan tersebut.
  - `"-type","f"`, fungsi ini juga masih berhubungan dengan find dimana menjelaskan kepada proses bahwa untuk mencari isi di dalam direktori tujuan dengan tipe data file.
  - `"mv",{}","/home/vaniameith/modul2/sedaap"`, untuk memindahkan suatu file yang telah ditemukan tersebut ke direktori/folder sedaap.

```
child4 = fork();
  if (child4 == 0){
    char *argv[] = {"find","/home/vaniameith/modul2/jpg",
                    "-mindepth","1","-type","d","-exec","mv",
                    "{}","/home/vaniameith/modul2/indomie",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }
  ```
  Program diatas sama halnya dengan program diatas, perbedaannya adalah menemukan isi dengan tipe data directory/folder dan memindahkannya ke directory/folder indomie.
  
##### Penjelasan soal 3d
```
 child5 = fork();
  if (child5 == 0){
    char *argv[] = {"find","/home/vaniameith/modul2/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba1.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
  }
```
- `touch`, command ini berfungsi untuk membuat sebuah file/direktori tanpa isi apapun didalamnya. Dalam soal ini, program diatas membuat file `coba1.txt` ke dalam direktori indomie.

```
child6 = fork();
  if (child6 == 0) {
    sleep(3);
    char *argv[] = {"find","/home/vaniameith/modul2/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba2.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
 }
 ```
 - program diatas untuk membuat file `coba2.txt` ke dalam direktori indomie.
 
 
