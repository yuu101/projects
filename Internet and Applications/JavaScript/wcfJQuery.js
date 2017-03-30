window.onload = function () {
    var pid = $("input[name=placeRadioButtonList]:checked").val();
    placeRadioButtonList_onclick(pid);
}

function placeRadioButtonList_onclick(pid) {
    var locationService = new LocationService();
    locationService.getLocation(pid, showPlaceData);
}

function showPlaceData(placeData) {
    $("#placeImage").attr("src", "http://farm9.staticflickr.com/" + placeData.d.flickrId);
    $("#latitudeLabel").text(placeData.d.latitude);
    $("#longitudeLabel").text(placeData.d.longitude);

}