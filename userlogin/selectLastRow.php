<?php
    // Connect to MySQL
    include("config.php");

    // Prepare the SQL statement
     
    $SQL = " SELECT * FROM Location ORDER BY id DESC LIMIT 1;";     

    // Execute SQL statement
 

	
	$result = $db->query($SQL);
	


if ($result->num_rows > 0) {
	
	
  // output data of each row
  while($row = $result->fetch_assoc()) {
    //echo "id: " . $row["id"]. " - Name: " . $row["lon"]. " " . $row["lat"]. "<br>";
	
	$longitude = $row["lon"];
	$latitude = $row["lat"];
	//echo json_encode(array($longitude,$latitude));
	
	$array = array("longitude" => $row["lon"], "latitude" => $row["lat"]);
	echo json_encode($array);
	
  }
} else {
  echo "0 results";
}
$db->close();
	
	
 
?>
