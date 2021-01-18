<?php
session_start();
require_once('config.php');
	// connect to database
	

?>


<?php


		$username = $_POST["username"];
		$password = $_POST["password"];

		$stmtselect = $db->prepare($query);			
		$query = "SELECT * FROM Users WHERE username='$username' AND password='$password'";

		$results = mysqli_query($db, $query);
			
	
		//	echo $username;
			//echo $password;
			
			
			
			
			
			//$row_cnt = $results->num_rows;
			
			//printf("Result set has %d rows.\n", $row_cnt);
			
			
		
		if(mysqli_num_rows($results) > 0) {
		$row = mysqli_fetch_array($results);
		$_SESSION['userlogin'] = $user;
		echo'succes';
} else{
	echo"no users for that input";
}