<?php
// panggil file koneksi
include_once("connection.php");

$id = $_GET['id_anggota'];

$result = mysqli_query($conn, "DELETE FROM tb_user WHERE id_anggota = '$id'");

// After delete redirect to Home, so that latest user list will be displayed.
header("Location: data_user.php");