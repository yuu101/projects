var streetView;
var streetViewService;
var centerLatLng;
var panoramaOptions;

window.onload = function () {

    panoramaOptions = {
        position: centerLatLng,

        pov: {
            heading: 0,
            pitch: 0,
            zoom: 1
        }
    };

    streetView = new google.maps.StreetViewPanorama($("#streetViewCanvas")[0], panoramaOptions);
    streetViewService = new google.maps.StreetViewService();

    var pid = $("input[name=placeRadioButtonList]:checked").val();
    placeRadioButtonList_onclick(pid);
}

function placeRadioButtonList_onclick(pid) {
    var locationService = new LocationService();
    locationService.getLocation(pid, getStreetViewPano);
}

function getStreetViewPano(placeData) {
    centerLatLng = new google.maps.LatLng(placeData.d.latitude, placeData.d.longitude);
    streetViewService.getPanoramaByLocation(centerLatLng, 100, showStreetView);
}

function showStreetView(data, status) {
    
    if (status == google.maps.StreetViewStatus.OK) {
        streetView.setPano(data.location.pano);
        streetView.setPov(panoramaOptions.pov);
    }
    else {
        alert('抱歉!此處無街景服務');
    }
}