<?php

//buatlah koneksi ke database
$konek = mysqli_connect("localhost", "root", "","dbmultisensor");

//baca data dari tabel sensor
$sql = mysqli_query($konek, "select * from tb_sensor order by id desc"); //data terakhir atau terbaru yang paling atas

//baca paling atas
$data = mysqli_fetch_array($sql);
$ldr = $data['ldr'];

//uji, apalila nilai suhu belum ada, maka dianggap suhunya = 0
if($ldr == "") $ldr = 0;

//cetak nilai suhu
echo $ldr;

?>