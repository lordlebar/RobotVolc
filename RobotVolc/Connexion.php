
<?php
    //  $servername = "172.20.13.250";
    //  $username = "etudiant1";
    //  $password = "1234";
    //  $dbname = "site1";

    $servername = "localhost";
    $username = "AdminRobot";
    $password = "";
    $dbname = "robotvolc";

    // Create connection
    $db = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $sql="SELECT latitude,longitude FROM waypoints where CAMPAGNES_idCAMPAGNES=7";
    $stmt = $db->prepare($sql);
    $stmt->execute();
    $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
    $retour=json_encode($result);
    echo $retour;
    
    $conn->close();
  ?>

