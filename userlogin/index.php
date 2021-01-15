<?php
	session_start();
	
	if(isset($_SESSION['userlogin'])){
		header("Location: login.php");
	}
	if(isset($_GET['logout'])){
		session_destroy();
		unset($_SESSION);
		header("Location: login.php");
	}

 ?>

<a href="index.php?logout=true">Logout</a>

<!DOCTYPE html>
<html lang="en">
<title>W3.CSS Template</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta http-equiv="X-UA-Compatible" content="ie=edge" />
<link rel="stylesheet" href="https://unpkg.com/leaflet@1.7.1/dist/leaflet.css"
integrity="sha512-xodZBNTC5n17Xt2atTPuE1HxjVMSvLVW9ocqUKLsCC5CXdbqCmblAshOMAS6/keqq/sMZMZ19scR4PsZChSR7A=="
crossorigin=""/>
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Lato">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">


<script 
 
src="https://unpkg.com/leaflet@1.7.1/dist/leaflet.js"
    integrity="sha512-XQoYMqMTK8LvdxXYG3nZ448hOEQiglfqkJs1NOQV44cWnUrBc8PkAOcXy20w0vlaXaVUearIOBhiXZ5V3ynxwA=="
    crossorigin="">
 </script>






<style>
body {font-family: "Lato", sans-serif}
.mySlides {display: none}
 
 #issMap {
        height: 360px;
      }

</style>
<body>

<!-- Navbar -->
<div class="w3-top">
  <div class="w3-bar w3-black w3-card">
    <a class="w3-bar-item w3-button w3-padding-large w3-hide-medium w3-hide-large w3-right" href="javascript:void(0)" onclick="myFunction()" title="Toggle Navigation Menu"><i class="fa fa-bars"></i></a>
    <a href="#" class="w3-bar-item w3-button w3-padding-large">HOME</a>
    <a href="#band" class="w3-bar-item w3-button w3-padding-large w3-hide-small">PROJECT</a>
    <a href="#tour" class="w3-bar-item w3-button w3-padding-large w3-hide-small">CONTACT</a>
    <a href="#contact" class="w3-bar-item w3-button w3-padding-large w3-hide-small">MAP</a>
    <a href="javascript:void(0)" class="w3-padding-large w3-hover-red w3-hide-small w3-right"><i class="fa fa-search"></i></a>
  </div>
</div>

<!-- Navbar on small screens (remove the onclick attribute if you want the navbar to always show on top of the content when clicking on the links) -->
<div id="navDemo" class="w3-bar-block w3-black w3-hide w3-hide-large w3-hide-medium w3-top" style="margin-top:46px">
  <a href="#band" class="w3-bar-item w3-button w3-padding-large" onclick="myFunction()">BAND</a>
  <a href="#tour" class="w3-bar-item w3-button w3-padding-large" onclick="myFunction()">TOUR</a>
  <a href="#contact" class="w3-bar-item w3-button w3-padding-large" onclick="myFunction()">CONTACT</a>
  <a href="#" class="w3-bar-item w3-button w3-padding-large" onclick="myFunction()">MERCH</a>
</div>

<!-- Page content -->
<div class="w3-content" style="max-width:2000px;margin-top:46px">

  <!-- Automatic Slideshow Images -->
    <div class="mySlides w3-display-container w3-center">
    <img src="img/cart1.png" style="width:100%">
    <div class="w3-display-bottommiddle w3-container w3-text-white w3-padding-32 w3-hide-small">  
    </div>
  </div>
     <div class="mySlides w3-display-container w3-center">
    <img src="img/cart2.png" style="width:100%">
    <div class="w3-display-bottommiddle w3-container w3-text-white w3-padding-32 w3-hide-small">  
    </div>
  </div>
  <div class="mySlides w3-display-container w3-center">
    <img src="img/iot.jpeg" style="width:100%">
    <div class="w3-display-bottommiddle w3-container w3-text-white w3-padding-32 w3-hide-small">  
    </div> 
  </div>
  <div class="mySlides w3-display-container w3-center">
    <img src="img/ai.png" style="width:100%">
    <div class="w3-display-bottommiddle w3-container w3-text-white w3-padding-32 w3-hide-small">   
    </div>
  </div>
  <div class="mySlides w3-display-container w3-center">
    <img src="img/auto.jpg" style="width:100%">
    <div class="w3-display-bottommiddle w3-container w3-text-white w3-padding-32 w3-hide-small"> 
    </div>
  </div>
    <div class="mySlides w3-display-container w3-center">
    <img src="img/cart3.png" style="width:100%">
    <div class="w3-display-bottommiddle w3-container w3-text-white w3-padding-32 w3-hide-small"> 
    </div>
  </div>
 

  <!-- The Band Section -->
  <div class="w3-container w3-content w3-center w3-padding-64" style="max-width:800px" id="band">
    <h2 class="w3-wide">Autonomous Cart</h2>
    <p class="w3-opacity"><i>brief explanation</i></p>
    <p class="w3-justify">Autonomous Cart is a project made by students of the college-university PXL. The project is made by the use of several key-technologies of this era namely: Iot, Artificial intelligence and Automation. The main goal was simple "The golf cart has to be able to take the passenger to his/her destination". But that doesn't mean the project was such as well. But as proud makers of this project we can assure you that it was a great honour to be a part of this project. 
<a href="https://github.com/KingAbad/Autonomous_Cart_2"> Visit our github.</a></p>
<div class="w3-row-padding">
    <div class="w3-col l3 m6 w3-margin-bottom">
      <img src="img/kew.jpeg" alt="img Kazim" style="width:100%">
      <h3>Kazim Bozca</h3>
      <p class="w3-opacity">Engineer</p>
      <p>Hi, I am Kazim. The main task that was given to me was developing the printed circuit board for all the components.</p>
      <p><button class="w3-button w3-light-grey w3-block">Contact</button></p>
    </div>
    <div class="w3-col l3 m6 w3-margin-bottom">
      <img src="img/abad1.png" alt="Jane" style="width:100%">
      <h3>Abad Sethi</h3>
      <p class="w3-opacity">Engineer</p>
      <p>Hi, I am Abad. As leader of my group it was my most important task to be able to help my team with any problem they might encounter. I also worked a lot on the IoT side and such things as this website.</p>
      <p><button class="w3-button w3-light-grey w3-block">Contact</button></p>
    </div>
    <div class="w3-col l3 m6 w3-margin-bottom">
      <img src="img/meto.png" alt="Mike" style="width:100%">
      <h3>Metehan A.</h3>
      <p class="w3-opacity">Engineer</p>
      <p>Hi, I am Metehan. The main task that i did was doing the communication with the other groups and to maintain the back end</p>
      <p><button class="w3-button w3-light-grey w3-block">Contact</button></p>
    </div>
    
  </div>
</div>

  <!-- The Contact Section -->
  <div class="w3-container w3-content w3-padding-64" style="max-width:800px" id="tour">
    <h2 class="w3-wide w3-center">CONTACT</h2>
    <div class="w3-row w3-padding-32">
      <div class="w3-col m6 w3-large w3-margin-bottom">
        <i class="fa fa-map-marker" style="width:30px"></i>Elfde-Liniestraat 24, 3500 Hasselt<br>
        <i class="fa fa-phone" style="width:30px"></i> Phone:  +32 11 77 55 55<br>
        <i class="fa fa-envelope" style="width:30px"> </i> Email: pxl@mail.com<br>
      </div>
	      <div class="w3-col m6">
		<img src="img/pxl.png" alt="pxl logo" width="120" height="120">
      </div>
    </div>
  </div>
    <div class="w3-container w3-content w3-padding-64" style="max-width:800px" id="tour">
    <div class="w3-row w3-padding-32">
      <div class="w3-col m6 w3-large w3-margin-bottom">
        <i class="fa fa-map-marker" style="width:30px"></i>Kempische Steenweg 293, 3500 Hasselt<br>
        <i class="fa fa-phone" style="width:30px"></i> Phone: +32 11 26 51 30<br>
        <i class="fa fa-envelope" style="width:30px"> </i> Email: corda@mail.com<br>
      </div>
	   <div class="w3-col m6">
		<img src="img/corda.png" alt="corda logo" width="140" height="140">
      </div>
    </div>
  </div>
<!-- End Page Content -->
</div>
/**
<!-- Image of location/map -->
     <h1>Where is the CART?</h1>

    <p>
      latitude: <span id="lat"></span>°<br />
      longitude: <span id="lon"></span>° <br />
    </p>

    <div id="issMap"></div>
	
	
<script src="js/jquery-3.5.1.min.js"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
	
    <script>
      // Making a map and tiles
      // Setting a higher initial zoom to make effect more obvious
	  
      const mymap = L.map('issMap').setView([0, 0], 13, );
      const attribution =
        '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors';

      const tileUrl = 'https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png';
      const tiles = L.tileLayer(tileUrl, { attribution , maxZoom:25});     
      tiles.addTo(mymap);

      // Making a marker with a custom icon
      const issIcon = L.icon({
        iconUrl: 'img/auto.png',
        iconSize: [32, 50],
        iconAnchor: [25, 16]
      });
      let marker = L.marker([0, 0], { icon: issIcon }).addTo(mymap);

     // const api_url = 'http://svg.pxl-ea-ict.be/userlogin/selectLastRow.php';

      let firstTime = true;
	  



      async function getISS() {
	  
        let response = await fetch('http://svg.pxl-ea-ict.be/userlogin/selectLastRow.php');
       const data = await response.json();


        const { latitude, longitude } = data;
		
        marker.setLatLng([latitude, longitude]);
        if (firstTime) {
          mymap.setView([latitude, longitude], 18);
          firstTime = false;
        }
        document.getElementById('lat').textContent = parseFloat(latitude).toFixed(6);
        document.getElementById('lon').textContent = parseFloat(longitude).toFixed(6);
      }

      getISS();
      setInterval(getISS, 1000);
    </script>
	


<!-- Footer -->
<footer class="w3-container w3-padding-64 w3-center w3-opacity w3-light-grey w3-xlarge">
  <i class="fa fa-facebook-official w3-hover-opacity"></i>
  <i class="fa fa-instagram w3-hover-opacity"></i>
  <i class="fa fa-snapchat w3-hover-opacity"></i>
  <i class="fa fa-pinterest-p w3-hover-opacity"></i>
  <i class="fa fa-twitter w3-hover-opacity"></i>
  <i class="fa fa-linkedin w3-hover-opacity"></i>
  <p class="w3-medium">Copyright <a href="https://www.w3schools.com/w3css/default.asp" target="_blank"></a></p>
</footer>

<script>
// Automatic Slideshow - change image every 4 seconds
var myIndex = 0;
carousel();

function carousel() {
  var i;
  var x = document.getElementsByClassName("mySlides");
  for (i = 0; i < x.length; i++) {
    x[i].style.display = "none";  
  }
  myIndex++;
  if (myIndex > x.length) {myIndex = 1}    
  x[myIndex-1].style.display = "block";  
  setTimeout(carousel, 4000);    
}

// Used to toggle the menu on small screens when clicking on the menu button
function myFunction() {
  var x = document.getElementById("navDemo");
  if (x.className.indexOf("w3-show") == -1) {
    x.className += " w3-show";
  } else { 
    x.className = x.className.replace(" w3-show", "");
  }
}

// When the user clicks anywhere outside of the modal, close it
var modal = document.getElementById('ticketModal');
window.onclick = function(event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
}
</script>

</body>
</html>