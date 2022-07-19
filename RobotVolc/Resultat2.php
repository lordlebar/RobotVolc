<?php
//$servername = "172.20.13.250";
//$username = "etudiant1";
//$password = "1234";
//$dbname = "site1";

$servername = "localhost";
$dbname = "robotvolc";
$username = "AdminRobot";
$password = "";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM waypoints";
$result = $conn->query($sql);


    $lines = $conn->query($sql);
    $line_num = 0;
    if ($lines -> num_rows > 0) {
      while ($row = $lines -> fetch_assoc())
      {
        $Latitude[$line_num] = $row["latitude"];
        $Longitude[$line_num] = $row["longitude"];
        $Altitude[$line_num] = $row["altitude"];
        $Id_Campagne[$line_num] = $row["CAMPAGNES_idCAMPAGNES"];
        $Id_WayPoint[$line_num] = $row["idWAYPOINTS"];

        $line_num += 1;
      }
    }
    else
    {
      // echo "Aucun résultat";
    }


    $conn->close();
?>
<table style="width:100%">
  <tr>
    <th><?php echo  "id_Campagne"; ?></th>
    <th><?php echo  "Id_Waypoint"; ?></th>
    <th><?php echo  "Latitude"; ?></th>
    <th><?php echo  "Longitude"; ?></th>
    <th><?php echo  "Altitude"; ?></th>



  </tr>
  <?php
    for ($i = 0; $i < $line_num; $i++)
    {
      echo "<tr>";
          echo "<th>".$Id_Campagne[$i]."</th>";
          echo "<th>".$Id_WayPoint[$i]."</th>";
          echo "<th>".$Latitude[$i]."</th>";
          echo "<th>".$Longitude[$i]."</th>";
          echo "<th>".$Altitude[$i]."</th>";


      echo "</tr>";
    }
  ?>
