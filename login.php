<html>

<head>
    <title>Login Anggota</title>
    <link rel="stylesheet" href="login.css?v=<?php echo time(); ?>">
</head>

<body>
    <form method="post" action="login_setup.php">

        <div class="tampilan">
            <div class="kepala">
                <div class="logo"></div>
                <h2 class="judul">Login Anggota</h2>
            </div>
            <div class="artikel">

                <div class="kesalahan">
                    <?php
                    if (isset($_GET["login_error"])) {
                        echo "Username atau password salah";
                    }
                    ?>
                </div>

                <div class="kotak">
                    <p><input type="text" name="username" value="" placeholder="Masukan Username Anda"></p>
                    <p><input type="text" name="password" value="" placeholder="Masukan Password Anda"></p>
                    <p class="submit"><input type="submit" name="commit" value="Login"></p>
                    <p class="daftar">Tidak punya akun? <a href="tambah_user.php">Daftar</a></p>
                </div>
            </div>

        </div>
        </div>
    </form>
</body>

</html>