window.onload = function () {
    var centerLatLng = new google.maps.LatLng(25.0419, 121.5353);

    var panoramaOptions = {
        position: centerLatLng,

        pov: {
            heading: 0,
            pitch: 0,
            zoom: 1
        }
    };

    var streetView = new google.maps.StreetViewPanorama($("#streetViewCanvas")[0], panoramaOptions);
}