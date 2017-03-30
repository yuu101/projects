var map;
var centerLatLng;

window.onload = function () {

    var mapOptions = {
        zoom: 15,
       // center: centerLatLng,
        //panControl:false,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        mapTypeControl: false
    };

    map = new google.maps.Map($("#mapCanvas")[0], mapOptions);
    var pid = $("input[name=placeRadioButtonList]:checked").val();
    placeRadioButtonList_onclick(pid);
}

function placeRadioButtonList_onclick(pid) {
    var locationService = new LocationService();
    locationService.getLocation(pid, showGoogleMap);
}

function showGoogleMap(placeData) {
    centerLatLng = new google.maps.LatLng(placeData.d.latitude, placeData.d.longitude);
    map.setCenter(centerLatLng);
}