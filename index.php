<?php
// panggil koneksi
require_once "connection.php";


// query memanggil seluruh data
$query = "SELECT * FROM `tb_buku` ORDER BY kd_buku DESC LIMIT 1;";

// jalankan query
$data = mysqli_query($conn, $query);

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="Style.css?v=<?php echo time(); ?>">
    <title>Perpustakaan Online</title>
</head>

<body>

    <div id="container">
        <div class="header">
            <h1>Perpustakaan Universitas Bumigora</h1>
        </div>

        <div class="main">
            <div class="left">
                <h3 align="center">MENU</h3>
                <ul>
                    <li><a href="http://localhost/web-uas/php/login.php">Login</a></li>
                    <li><a href="http://localhost/web-uas/php/login.php">Daftar Buku</a></li>
                </ul>
            </div>

            <div class="middle">
                <?php
                while ($hasil = mysqli_fetch_array($data)) {
                    ?>
                    <h3 align="center">Artikel/Berita/Buku Terbaru</h3>
                    <h2 align="center">Buku:
                        <?= $hasil['judul']; ?>
                    </h2><br>
                    <div align="center">
                        <img src="gambar_upload/<?= $hasil['gambar']; ?>" width="240">
                    </div>
                <?php } ?>
                <p><a href="login.php">Baca Selengkapnya >></a></p>
            </div>
        </div>

        <div class="right">
            <h3 align="center">BUKU TERPOPULER</h3>
            <ul>
                <li><a href="#">Web Design</a></li>
                <li><a href="#">Pemrograman</a></li>
                <li><a href="#">Database</a></li>
            </ul>
        </div>
    </div>
    </div>

    <div class="footer">
        <p align="center">Copyright © 2023 - Kelompok Prikitiew</a></p>
    </div>
    </div>
</body>

</html>