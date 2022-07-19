<html>
<body>
  <?php
  $servername = "localhost";
  $username = "AdminRobot";
  $password = "";
  $dbname = "robotvolc";

  // Create connection
  $conn = new mysqli($servername, $username, $password, $dbname);
  // Check connection
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }

  $sql = "SELECT * FROM robotlive";
  $result = $conn->query($sql);


      $lines = $conn->query($sql);
      $line_num = 0;
      if ($lines -> num_rows > 0) {
        while ($row = $lines -> fetch_assoc())
        {
          $Latitude = $row["Latitude"];
          $Longitude = $row["Longitude"];


          $line_num += 1;
        }
      }
      else
      {
        echo "Aucun résultat";
      }


      $conn->close();
  ?>

  <div id="mapdiv"></div>
  <script src="http://www.openlayers.org/api/OpenLayers.js"></script>
  <script>
    map = new OpenLayers.Map("mapdiv");
    map.addLayer(new OpenLayers.Layer.OSM());

    var lonLat = new OpenLayers.LonLat( <?php echo $Longitude ?> , <?php echo $Latitude ?> )
          .transform(
            new OpenLayers.Projection("EPSG:4326"), // transform from WGS 1984
            map.getProjectionObject() // to Spherical Mercator Projection
          );

    var zoom=16;

    var markers = new OpenLayers.Layer.Markers( "Markers" );
    map.addLayer(markers);
      markers.addMarker(new OpenLayers.Marker(lonLat));

    map.setCenter (lonLat, zoom);

    </script>
    <?php
        header("Refresh:5");
    ?>
</body>
</html>
