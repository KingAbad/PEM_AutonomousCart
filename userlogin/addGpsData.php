<?php
    // Connect to MySQL
    include("config.php");

    // Prepare the SQL statement
	
	
	

	$lon = 
	
	$sql = "INSERT INTO Location (lon, lat)
	VALUES ('".$_GET["lon"]."','".$_GET["lat"]."')";	

	
	if ($db->query($sql) === TRUE) {
		echo "New record created successfully";
	} else {
		echo "Error: " . $sql . "<br>" . $db->error;
	}


?>