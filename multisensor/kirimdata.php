<?php
    //koneksi ke database
    $konek = mysqli_connect("localhost", "root", "","dbmultisensor");
    
    //baca data yang dikirim data esp32
    $suhu = $_GET['suhu'];
    $kelembapan = $_GET['kelembapan'];
    $ldr = $_GET['ldr'];

    //simpan ke tabel tb_sensor

    //auto increment = 1 / mengembalikan ID menjadi 1 apabila dikosongkan
    mysqli_query($konek, "ALTER TABLE tb_sensor AUTO_INCREMENT=1");
    //simpan data sensor ke tabel tb_sensor
    $simpan = mysqli_query($konek, "insert into tb_sensor(suhu, kelembapan, ldr)values('$suhu', '$kelembapan', '$ldr')");
    
    //uji simpan untuk memberikan respon
    if($simpan)
        echo "Berhasil dikirim" ;
    else
        echo "Gagal terkirim" ;


?>