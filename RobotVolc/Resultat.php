<!-- // PHP TABLE CAMPAGNE + INCLUDE TABLE MESURES ET LOCALISATION -->
<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="utf-8">
  <title>Robot Volcanique</title>
  <link rel="stylesheet" type="text/css" href="Style.css">
</head>
<body>



  <h1 class="Titre">Table des Resultats</h1>
  <h1 class="Titre2">Robot Explorateur</h1>


  <?php

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

  $sql = "SELECT * FROM campagnes"; // Recupere les informations table campagne

  $result = $conn->query($sql);
  $lines_ = $conn->query($sql);
  $line_num = 0;
  if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
      $Id_Campagne[$line_num] = $row["idCAMPAGNES"];
      $Site[$line_num] = $row["site"];
      $Pilote[$line_num] = $row["pilote"];
      $Date_Heure[$line_num] = $row["Date_Heure"];
      $line_num += 1;
    }
  }
  ?>

  <table style="width:100%">
      <tr>
        <th>idCampagne</th>
        <th>Site</th>
        <th>Pilote</th>
        <th>Date_Heure</th>
      </tr>
    <?php
      for ($i = 0; $i < $line_num; $i++)
      {
        echo "<tr>";
            echo "<th>".$Id_Campagne[$i]."</th>";
            echo "<th>".$Site[$i]."</th>";
            echo "<th>".$Pilote[$i]."</th>";
            echo "<th>".$Date_Heure[$i]."</th>";
        echo "</tr>";
      }
      include 'Resultat2.php';
      include 'Resultat3.php';
    ?>

  </table>
</body>
</html>
