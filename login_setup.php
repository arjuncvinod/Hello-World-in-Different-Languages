<?php
include_once("connection.php");
ob_start();
session_start();
ob_end_clean();

$username = $_POST["username"];
$password = $_POST["password"];

$query = "SELECT * FROM tb_user WHERE nama = '$username' AND pass = '$password'";
$data = mysqli_query($conn, $query);


if ($username == "admin" and $password == "admin123") {
    $_SESSION["username"] = $username;
    header("location:admin_home.php");
} elseif (mysqli_num_rows($data) > 0) {
    $_SESSION["username"] = $username;
    header("location:home.php");
} else {
    header("location:login.php?login_error");
}
?>