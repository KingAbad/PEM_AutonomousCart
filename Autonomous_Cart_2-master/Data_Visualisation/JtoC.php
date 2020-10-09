<html>
<head>
<title>RFID</title>
<style type="text/css">

table {
margin-left: auto;
margin-right: auto;  
border-spacing: 3px;


}
body{background-color:powderblue;}
td {
font-family: Arial, Helvetica, sans-serif;
font-size: 1.25em;
padding: 2px 6px;
border-collapse: separate;
border: 1px solid #000;
 text-align:center;
}
h1{
  font-family:verdana;
  text-align:center;
}

</style>
</head>
<body>
  <h1>Table subscribed members</h1>
</body>
</html>

<?php

function jsonToCSV($jfilename, $cfilename)
{
    if (($json = file_get_contents($jfilename)) == false)
        die('Error reading json file...');
    $data = json_decode($json, true);
    $fp = fopen($cfilename, 'w');
    $header = false;
    foreach ($data as $row)
    {
        if (empty($header))
        {
            $header = array_keys($row);
            fputcsv($fp, $header);
            $header = array_flip($header);
        }
        fputcsv($fp, array_merge($header, $row));
    }
    fclose($fp);
    return;
}

$json_filename = 'data.json';
$csv_filename = 'rfid.csv';

jsonToCSV($json_filename, $csv_filename);

$filename = 'rfid.csv';
$build ="";


$the_big_array = []; 

if (($h = fopen("{$filename}", "r")) !== FALSE) 
{

  while (($data = fgetcsv($h, 1000, ",")) !== FALSE) 
  {
    $the_big_array[] = $data;       
  }

  // Close the file
  fclose($h);
}
 $build .= '
  <div class="table-responsive">
   <table border=1>
    <tr>
    </tr>
 ';

foreach($the_big_array as $row)
{
$build .= '<tr>';
foreach($row as $item)
{
$build .= "<td>{$item}</td>";
}
$build .= '</tr>';
}
$build .= '</tbody></table>';
echo $build;
?>