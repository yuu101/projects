var map;
var markerLatLng;
var streetViewPanorama;
var panoramaOptions;
var streetViewService;
var originalMarker;
var destinationMarker;

window.onload = function () {
    var mapOptions = {
        zoom: 15,
        //center: markerLatLng,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        mapTypeControl: false,
        panControl: false,
        zoomControl: false,
        streetViewControl: false,
        disableDoubleClickZoom:true
    };
    map = new google.maps.Map($("#mapCanvas")[0], mapOptions);

    var originalMarkerOptions = { //起點
        map: map
    };
    originalMarker = new google.maps.Marker(originalMarkerOptions);

    var icon = {
        url: 'http://localhost:53201/Image/destinationMarker.jpg',
        //url:'http://iweb.csie.ntut.edu.tw:9080/www71/Image/destinationMarker.jpg',
        anchor: new google.maps.Point(3, 42)
    };

    var destinationMarkerOptions = {  //終點
        map: map,
        icon: icon,
        draggable: true,
        visible: false
    };
    destinationMarker = new google.maps.Marker(destinationMarkerOptions);
    google.maps.event.addListener(map, 'dblclick', updateMarker);
    google.maps.event.addListener(destinationMarker, 'dragend', updateMarker);

    var directionMarkerOptions = {
        visible: false
    };

    var directionsRendererOptions = {
        markerOptions: directionMarkerOptions,
        map: map
    };
    directionsService = new google.maps.DirectionsService();
    directionsDisplay = new google.maps.DirectionsRenderer(directionsRendererOptions);

    panoramaOptions = {
        pov: {
            heading: 0,
            pitch: 0,
            zoom: 1
        },
        panControl: false,
        zoomControl: false,
        addressControl: false
    };

    streetViewPanorama = new google.maps.StreetViewPanorama($("#streetViewCanvas")[0], panoramaOptions);
    streetViewService = new google.maps.StreetViewService();

    var pid = $("input[name=placeRadioButtonList]:checked").val();
    placeRadioButtonList_onclick(pid);
}

function placeRadioButtonList_onclick(pid) {
    var locationService = new LocationService();
    locationService.getLocation(pid, showGoogleMap);
}

function showGoogleMap(placeData) {
    $("#placeImage").attr("src", "http://farm9.staticflickr.com/" + placeData.d.flickrId);
    markerLatLng = new google.maps.LatLng(placeData.d.latitude, placeData.d.longitude);
    map.setCenter(markerLatLng);
    originalMarker.setPosition(markerLatLng);
    streetViewPanorama.setPosition(markerLatLng);
    streetViewService.getPanoramaByLocation(markerLatLng, 100, updateStreetView);
}

function updateMarker(event) {
    markerLatLng = event.latLng;
    
    destinationMarker.setPosition(markerLatLng);
    if (destinationMarker.getVisible() == false) {
        destinationMarker.setVisible(true);
    }
    var request = { //路線規劃
        origin: originalMarker.getPosition(),
        destination: markerLatLng,
        travelMode: google.maps.TravelMode.DRIVING
    };
    directionsService.route(request, updateDirection);

    streetViewPanorama.setPosition(markerLatLng);
    streetViewService.getPanoramaByLocation(markerLatLng, 100, updateStreetView);
}

function updateDirection(result, status) {
    if (status == google.maps.DirectionsStatus.OK) {
        var leg = result.routes[0].legs[0];
        directionsDisplay.setDirections(result);
        var distance = ((((leg.distance.value) * 1.6092) / 1000).toFixed(1)).toString() + "公里";//英吋轉換
        $("#distanceLabel").text(distance);
        $("#durationLabel").text(leg.duration.text);
    }
    else {
        alert('抱歉! 此處無路徑服務');
    }
}

function updateStreetView(data, status) {
    if (status == google.maps.StreetViewStatus.OK) {
        streetViewPanorama.setPano(data.location.pano);
        streetViewPanorama.setPov(panoramaOptions.pov);
    }
    else {
        alert('抱歉!此處無街景服務');
    }
}