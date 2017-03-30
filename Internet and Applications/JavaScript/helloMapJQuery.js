window.onload = function () {
    var centerLatLng = new google.maps.LatLng(25.0419, 121.5353);

    var mapOptions = {
        zoom: 15,
        center: centerLatLng,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        mapTypeControl: false
    };

    var map = new google.maps.Map($("#mapCanvas")[0], mapOptions);
}