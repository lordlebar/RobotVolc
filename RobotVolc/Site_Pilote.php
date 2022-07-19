<html>
<head>
<style>

form {
    /* Uniquement centrer le formulaire sur la page */
margin: 0 auto;
width: 400px;
    /* Encadré pour voir les limites du formulaire */
padding: 1em;
border: 1px solid #CCC;
    border-radius: 1em;
}

form div + div {
    margin-top: 1em;
}

label {
    /* Pour être sûrs que toutes les étiquettes ont même taille et sont correctement alignées */
display: inline-block;
width: 90px;
    text-align: right;
}

input, textarea {
    /* Pour s'assurer que tous les champs texte ont la même police.
     Par défaut, les textarea ont une police monospace */
font: 1em sans-serif;
    
    /* Pour que tous les champs texte aient la même dimension */
width: 300px;
    box-sizing: border-box;
    
    /* Pour harmoniser le look & feel des bordures des champs texte */
border: 1px solid #999;
}

input:focus, textarea:focus {
    /* Pour souligner légèrement les éléments actifs */
    border-color: #000;
}

textarea {
    /* Pour aligner les champs texte multi‑ligne avec leur étiquette */
    vertical-align: top;
    
    /* Pour donner assez de place pour écrire du texte */
    height: 5em;
}

.button {
    /* Pour placer le bouton à la même position que les champs texte */
    padding-left: 90px; /* même taille que les étiquettes */
}

#Site {
    /* Cette marge supplémentaire représente grosso modo le même espace que celui
     entre les étiquettes et les champs texte */
    margin-left: 4em;
    margin-bottom: 0.9em;
    border-radius: 10px;
    height:28px;
    width: 170px;
}

#Site:hover {
cursor: pointer;
background-color : grey;
}

</style>
</head>
<body>
<?php
$servername = 'localhost';
$dbname = "robotvolc";
$username = 'AdminRobot';
$password = '';

//try connecting
try{
  $conn = new PDO("mysql:host=$servername;dbname=robotvolc;charset=utf8", $username, $password ,  array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));
    //echo 'Connexion reussi';
    
  //On définit le mode d'erreur de PDO sur Exception
  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  echo '';
}

/*On capture les exceptions si une exception est lancée et on affiche
*les informations relatives à celle-ci*/
catch(PDOException $e){
  echo "Erreur : " . $e->getMessage();
}

?>
<form method = 'POST'>
<div>
<label for="name">Nom Pilote :</label>
<input type="text" id="name" name="user_name">
</div>
<div>
<label for="inSite">Site :</label>
<input type="text" id="inSite" name="Site">
</div>

<div class="button">
<input type="submit" id="Site" name="Envoyer" value = "Envoyer">
</div>

<?php
if($_POST['Envoyer'] && $_POST['user_name'] != "" && $_POST['Site'] != ""){
    try{
        $Name_Pilote = $_POST['user_name'] ;
        $Site =  $_POST['Site'] ;
        
        $Insertion = $conn->prepare("INSERT INTO `campagnes` (`pilote`, `site`) VALUES (?, ?)");

        $Insertion -> execute(array($Name_Pilote, $Site));
        
        echo 'Votre Nom : ' , $Name_Pilote , ', et le Site de la mission : ' , $Site , ", ont bien été enregistrer dans la base de données. <br>";
        echo 'Vous pouvez fermer cette fenêtre ...';
                
    }
    catch(Exception $e){
      echo 'Erreur ! :'. $e -> Get.Message();
    }
}
?>
</form>

</body>
</html>
