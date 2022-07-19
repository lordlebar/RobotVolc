<!DOCTYPE HTML>
<html>
  <head>
    <title>OpenLayers Demo</title>
    <style type="text/css">
      html, body, #mapdiv {
          width: 650px;
          height: 450px;
          margin: 0;
      }
    </style>
    <script src="http://www.openlayers.org/api/OpenLayers.js"></script>
    <link href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.17/themes/base/jquery-ui.css" rel="stylesheet" type="text/css" />
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
    <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.17/jquery-ui.min.js"></script>

  </head>

  <body>
  <div id="mapdiv"></div>
  <script>
  map = new OpenLayers.Map("mapdiv");
    map.addLayer(new OpenLayers.Layer.OSM());
        var lonLat = new OpenLayers.LonLat( 2.6 , 48.8 )
          .transform(
            new OpenLayers.Projection("EPSG:4326"), // transform from WGS 1984
            map.getProjectionObject() // to Spherical Mercator Projection
          );

    var zoom=12;

    var markers = new OpenLayers.Layer.Markers( "Markers" );
    map.addLayer(markers);
    markers.addMarker(new OpenLayers.Marker(lonLat));
    map.setCenter (lonLat, zoom);

    function lire_waypoints()
    {
          $.get('Connexion.php',function(data)
          {
          alert(data);
            var points=JSON.parse(data);
            for(point in points)
            {
              var lonLatn = new OpenLayers.LonLat(parseFloat(points[point].longitude),parseFloat(points[point].latitude))
              .transform(
                new OpenLayers.Projection("EPSG:4326"),
                map.getProjectionObject()
              );
              markers.addMarker(new OpenLayers.Marker(lonLatn));
            }
          });
    }
      setInterval(lire_waypoints, 4000);     // CECI PERMET DE RAFRAICHIR LA LECTURE DE VOTRE BASE DE DONNEES TOUTES les ' SECONDES

</script>
</body>
</html>
