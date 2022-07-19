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

$sql = "SELECT * FROM prelevements";
$result = $conn->query($sql);


    $lines = $conn->query($sql);
    $line_num = 0;
    if ($lines -> num_rows > 0) {
      while ($row = $lines -> fetch_assoc())
      {
        $Prelevement[$line_num] = $row["idPRELEVEMENTS"];
        $Temperature[$line_num] = $row["temperature"];
        $Id_WayPoint[$line_num] = $row["WAYPOINTS_idWAYPOINTS"];
        $Mineraux[$line_num] = $row["mineraux"];
        $Campagne_ID[$line_num] = $row["CAMPAGNES_idCAMPAGNES"];

        $line_num += 1;
      }
    }
    else
    {
      echo "Aucun résultat";
    }


    $conn->close();
?>

<table style="width:100%">
  <tr>
    <th><?php echo  "id_Campagne"; ?></th>
    <th><?php echo  "Id_Prelevement"; ?></th>
    <th><?php echo  "Id_Localisation"; ?></th>
    <th><?php echo  "Mineraux"; ?></th>
    <th><?php echo  "Temperature"; ?></th>



  </tr>

  <?php
    for ($i = 0; $i < $line_num; $i++)
    {
      echo "<tr>";
          echo "<th>".$Campagne_ID[$i]."</th>";
          echo "<th>".$Prelevement[$i]."</th>";
          echo "<th>".$Id_WayPoint[$i]."</th>";
          echo "<th>".$Mineraux[$i]."</th>";
          echo "<th>".$Temperature[$i]."</th>";



      echo "</tr>";
    }
  ?>
