<?php 

$db_user = "project_svg";
$db_pass = "Dw78OXDGN00oWj2R";
$db_name = "project_svg";

$db = new PDO('mysql:host=localhost;dbname=' . $db_name . ';charset=utf8', $db_user, $db_pass);
$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);