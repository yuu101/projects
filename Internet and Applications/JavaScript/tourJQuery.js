var map;
var geocoder;
var marker;
var position;
var latTextBox;
var lngTextBox;

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

    geocoder = new google.maps.Geocoder();

    var markerOptions = {
        map: map,
        position: position,
        draggable: true
    };
    marker = new google.maps.Marker(markerOptions);
    google.maps.event.addListener(marker, 'dragstart', clearLocation);
    google.maps.event.addListener(marker, 'dragend', showLocation);

    latTextBox = $("#tourDetailsView tr:eq(4) td:eq(1)").find("input");
    lngTextBox = $("#tourDetailsView tr:eq(5) td:eq(1)").find("input");
    $("#addressTextBox").val("國立台北科技大學");
    codeAddress();
}

function codeAddress() {

    var address = $("#addressTextBox").val();

    if (address != "") {
        if (address.match(/^[a-zA-Z]+$/)) {
            alert("請輸入中文地名！")
        }
        else {
            $("#tourDetailsView tr:eq(0) td:eq(1)").find("input").val(address);
            var request = {
                'address': address
            };
            geocoder.geocode(request, showMarker);
        }
    }
}

function showMarker(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
        position = results[0].geometry.location;

        map.setCenter(position);
        marker.setPosition(position);

        latTextBox.val(position.lat());
        lngTextBox.val(position.lng());
    }
    else {
        alert('無效地址！');
    }
}

function clearLocation(event) {
    latTextBox.val("");
    lngTextBox.val("");
}

function showLocation(event) {
    latTextBox.val(event.latLng.lat());
    lngTextBox.val(event.latLng.lng());
}

function addressTextBox_onFocus() {
    $("#addressTextBox").val("");
    $("#tourDetailsView tr:eq(0) td:eq(1)").find("input").val("");
    latTextBox.val("");
    lngTextBox.val("");
}