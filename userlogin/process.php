<?php
	require_once('configreg.php');

	$errors = array(); 


		if(isset($_POST)){
			
			$username = $_POST['username'];
			$email = $_POST['email'];
			$password = $_POST['password'];
		


			
		if (count($errors) == 0){	
			
			$sql = "INSERT INTO Users (username, email, password) VALUES(?, ?, ?)";
			
			$stmtinsert = $db->prepare($sql);
			$result =$stmtinsert->execute([$username, $email, $password]);
			
			
			
			
			if($result){
				echo('succes');
			}else{
				echo('error while saving');
			}
			
		}else{
			echo'No data';
		}}
?>