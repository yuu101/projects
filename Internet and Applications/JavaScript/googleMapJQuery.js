var map;
var markerLatLng;
var streetViewPanorama;
var panoramaOptions;
var streetViewService;
var marker;

window.onload = function () {

    var mapOptions = {
        zoom: 15,
        center: markerLatLng,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        mapTypeControl: false,
        panControl: false,
        zoomControl: false,
        streetViewControl: false,
        disableDoubleClickZoom:true
    };

    map = new google.maps.Map($("#mapCanvas")[0], mapOptions);

    var markerOptions = {
        map: map,
        draggable:true
    };
    marker = new google.maps.Marker(markerOptions);
    google.maps.event.addListener(marker, 'dragend', updateMarker);

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
   // marker.setPosition(markerLatLng);
    streetViewPanorama.setPosition(markerLatLng);
    streetViewService.getPanoramaByLocation(markerLatLng, 100, updateStreetView);
}

function updateMarker(event) {
    markerLatLng = event.latLng;
    marker.setPosition(markerLatLng);
   // streetViewPanorama.setPosition(markerLatLng);
    streetViewService.getPanoramaByLocation(markerLatLng, 100, updateStreetView);
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