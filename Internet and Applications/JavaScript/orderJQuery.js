var map;
var originalMarker;
var destinationMarker;
var panoramaOptions;
var streetViewPanorama;
var streetViewService;
var position;

window.onload = function () {
    var mapOptions = {
        zoom: 15,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        panControl: false,
        zoomControl: false,
        mapTypeControl: false,
        streetViewControl: false,
        disableDoubleClickZoom: true
    };
    map = new google.maps.Map($("#mapCanvas")[0], mapOptions);
    google.maps.event.addListener(map, 'dblclick', updateMarker);

    var originalMarkerOptions = {
        map: map
    };
    originalMarker = new google.maps.Marker(originalMarkerOptions);

    var icon = {
        //url: 'http://localhost:53201/Image/destinationMarker.jpg',
        url: 'http://iweb.csie.ntut.edu.tw:9080/www71/Image/destinationMarker.jpg',
        anchor: new google.maps.Point(3, 42)
    };
    var destinationMarkerOptions = {
        map: map,
        icon: icon,
        draggable: true,
        visible: false
    };
    destinationMarker = new google.maps.Marker(destinationMarkerOptions);
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

    showGoogleMap();
}

function showGoogleMap() {
    var latitude = parseFloat($("#latitudeHiddenField").val());
    var longitude = parseFloat($("#longitudeHiddenField").val());
    position = {
        lat: latitude,
        lng: longitude
    };
    map.setCenter(position);
    originalMarker.setPosition(position);
    streetViewPanorama.setPosition(position);
}

function updateMarker(event) {
    position = event.latLng;

    destinationMarker.setPosition(position);
    if (destinationMarker.getVisible() == false) {
        destinationMarker.setVisible(true);
    }
    var request = {
        origin: originalMarker.getPosition(),
        destination: position,
        travelMode: google.maps.TravelMode.DRIVING
    };
    directionsService.route(request, updateDirection);

    streetViewService.getPanoramaByLocation(position, 100, updateStreetView);
}

function updateDirection(result, status) {
    if (status == google.maps.DirectionsStatus.OK) {
        var leg = result.routes[0].legs[0];
        directionsDisplay.setDirections(result);
        var distance = ((((leg.distance.value) * 1.6092) / 1000).toFixed(1)).toString() + " 公里";
        $("#distanceLabel").text("距離： " + distance);
        $("#durationLabel").text("時間： " + leg.duration.text);
    }
    else {
        alert('抱歉！此處無路徑服務');
    }
}

function updateStreetView(data, status) {
    if (status == google.maps.StreetViewStatus.OK) {
        streetViewPanorama.setPano(data.location.pano);
        streetViewPanorama.setPov(panoramaOptions.pov);
    }
    else {
        alert('抱歉！此處無街景服務');
    }
}