# Soal Shift Modul 2 E12
by:<br/> 
I Dewa Putu Wiprah A      (05111740000152)<br/>
Reza Adipatria Maranatha  (05111740000186)
# 1

# 2

# 3
Untuk mengerjakan nomor 3, kita download dahulu file campur2.zip ke komputer kita. Untuk mengerjakan perintah-perintah, saya mem-Fork parent process sebanyak 3 kali sehingga mendapatkan 3 child process dan 1 parent process.<br/>
Child ke-1 saya gunakan untuk meng-Unzip file campur2.zip dengan command `char *unzip[] = {"unzip","/home/reza/campur2.zip","-d","/home/reza",NULL};` dan `execvp("unzip",unzip);`<br/><br/>
Child ke-3 saya gunakan untuk membuat file bernama daftar.txt menggunakan command `char *touch[] = {"touch","daftar.txt",NULL};
` dan `execvp("touch",touch);`<br/><br/>
Child ke-2 saya gunakan untuk list isi dari folder campur2 menggunakan command `char *ls[] = {"ls","/home/reza/campur2", NULL};` dan `execvp("ls", ls);`. Sebelum menjalankan command ls, kita terlebih dahulu menjalankan command pipe, pipe merupakan function di c yang memungkinkan untuk berkomunikasi antar proses. kita jalankan pipe menggunakan command `pipe(p);` lalu jalankan command dup2 untuk mengubah file descriptor sesuai dengan yang diinginkan. command dup2() `dup2(p[1], 1); close(p[0]);` angka 1 menandakan stdout <br/><br/>
Parent process saya gunakan untuk mengambil input dari process yang mengirim hasil ls kemudian grep seluruh file yang memiliki ekstensi .txt dengan command `execvp("grep", grep);`

# 4

# 5
