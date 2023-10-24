  //map for KU-area
  var map = L.map('map').setView([27.62028, 85.53842439756468], 16);
//   map.on('click', function (e) {
//       alert("Lat, Lon : " + e.latlng.lat + ", " + e.latlng.lng)
//   });
  //customed icon 
  var customIcon = L.icon({
      iconUrl: './icon.png',
      iconSize: [32, 32],         // Width and height of the icon
      iconAnchor: [16, 32],      // Anchor point (relative to iconSize)
      popupAnchor: [0, -32]      // Popup anchor (relative to iconSize)
  });

  L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png').addTo(map);

  // landmarker locations
  var marker1 = L.marker([27.625007254498687, 85.54099380970001]).addTo(map);
  var marker2 = L.marker([27.621395005146194, 85.54116010665894]).addTo(map);
  var marker3 = L.marker([27.617687572684925, 85.53752303123476]).addTo(map);

  marker1.bindPopup("landmark1:28-Kilo");
  marker2.bindPopup("landmark2: LMTC-Junction")
  marker3.bindPopup("landmark3: Ku-Mesh")


  // ploygon for showing clustering
  var polygon1 = L.polygon([
      [27.62640459267399, 85.53943276405334],
      [27.626385581389943, 85.54249584674837],
      [27.62371921609822, 85.54256558418274],
      [27.623676439655192, 85.53952395915987]
  ]).addTo(map);
  var polygon2 = L.polygon([
      [27.62274485963978, 85.53935766220094],
      [27.62281140133232, 85.54271578788759],
      [27.62016396136402, 85.54271578788759],
      [27.620168714455417, 85.53943812847139]
  ]).addTo(map);
  var polygon3 = L.polygon([
      [27.61910401682659, 85.53592443466187],
      [27.618994694609025, 85.53906798362732],
      [27.616309136300124, 85.53925037384035],
      [27.616299629782073, 85.53612291812897]
  ]).addTo(map);

  //used for distance between 
  // var point1 = L.latLng(27.621475806763716, 85.54181993007661);
  // var point2 = L.latLng(27.62165642192841, 85.54144442081453);
  // var distance = point1.distanceTo(point2);

  var pointer1 = L.marker([27.6242515437688, 85.54042518138887], { icon: customIcon }).addTo(map);//marker for building4 from 28-kilo

  var pointer2 = L.marker([27.624474688998998, 85.5413444430451], { icon: customIcon }).addTo(map);//marker for health care

  var pointer3 = L.marker([27.622435915537572, 85.54087042808533], { icon: customIcon }).addTo(map);//marker for temple

  var pointer4 = L.marker([27.621166859080763, 85.54104745388031], { icon: customIcon }).addTo(map);//marker for Building2 from the LMTC Junction towards south

  var pointer5 = L.marker([27.620805626838337, 85.54135859012604], { icon: customIcon }).addTo(map);//marker for Building4 from the LMTC Junction towards south

  var pointer6 = L.marker([27.617454665686274, 85.53893387317657], { icon: customIcon }).addTo(map);//marker for bank

  var pointer7 = L.marker([27.61855740464745, 85.53701877593994], { icon: customIcon }).addTo(map);//marker for playground

  var pointer8 = L.marker([27.621475806763716, 85.54181993007661], { icon: customIcon }).addTo(map); //marker for the building where direct connection of road is not found

  pointer1.bindPopup("28k_S21_W85_B4")//Building4 from 28-kilo towards south-west

  pointer2.bindPopup("28k_S70_H")//Health Care from 28-Kilo

  pointer3.bindPopup("LJ_N37_W100_T")//Temple location from LMTC Junction

  pointer4.bindPopup("LJ_S29_B2")//Building2 from the LMTC Junction towards south

  pointer5.bindPopup("LJ_S99_B4")//Building4 from the LMTC Junction towards south
  
  pointer6.bindPopup("KM_E131_S43_W25_BA")//NIMB bank location

  pointer7.bindPopup("KM_N45_W32_G") //playground location

  pointer8.bindPopup("LJ_N38_E42_B") //location for the building where direct connection of road is not found