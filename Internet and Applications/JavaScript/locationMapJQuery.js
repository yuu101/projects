var map;
var geocoder;
var marker;
var position;
var latLabel;
var lngLabel;

window.onload = function () {
    latLabel = $("#latLabel");
    lngLabel = $("#lngLabel");
    latLabel.text("25.0419");
    lngLabel.text("121.5353");

    position = new google.maps.LatLng(latLabel.text(), lngLabel.text());

    var mapOptions = {
        zoom: 15,
        center: position,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        panControl: false,
        zoomControl: false,
        mapTypeControl: false,
        streetViewControl: false,
        disableDoubleClickZoom: true
    };

    map = new google.maps.Map($("#mapCanvas")[0], mapOptions);
    geocoder = new google.maps.Geocoder();
    var markerOptions = {
        map: map,
        position: position,
        draggable: true
    };
    marker = new google.maps.Marker(markerOptions);

    google.maps.event.addListener(marker, 'dragstart', clearLocation);
    google.maps.event.addListener(marker, 'dragend', showLocation);
}

function codeAddress() {

    var address = $("#addressTextBox").val();
    var request = {
        'address': address
    };

    if (address != "") {
        if (address.match(/^[a-zA-Z]+$/)) {
            alert("請輸入中文地名！")
        }
        else {
            geocoder.geocode(request, showMarker);
        }
    }
}

function showMarker(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
        position = results[0].geometry.location;

        map.setCenter(position);
        marker.setPosition(position);

        latLabel.text(position.lat());
        lngLabel.text(position.lng());
    }
    else {
        alert('無效地址！');		
    }
}

function clearLocation(event) {
    latLabel.text("");
    lngLabel.text("");
}

function showLocation(event) {
    var request = {
        location: {
            lat: event.latLng.lat(),
            lng: event.latLng.lng()
        }
    };

    geocoder.geocode(request, showAddress);

    latLabel.text(event.latLng.lat());
    lngLabel.text(event.latLng.lng());
}

function showAddress(request, status) {
    $("#addressTextBox").val(request[0].formatted_address);
}