window.onload = function () {
    var placeRadioButtonListItems = document.getElementById("placeRadioButtonList").getElementsByTagName("input");

    for (var i = 0; i < placeRadioButtonListItems.length; i++) {
        if (placeRadioButtonListItems[i].checked) {
            var pid = placeRadioButtonListItems[i].value;
            placeRadioButtonList_onclick(pid);
        }
    }
}

function placeRadioButtonList_onclick(pid) {
    LocationService.getLocation(Number(pid), showPlaceData);
}

function showPlaceData(placeData) {
    document.getElementById("placeImage").setAttribute(['src'], ["http://farm9.staticflickr.com/"+placeData.flickrId]);
    document.getElementById("latitudeLabel").innerHTML = placeData.latitude;
    document.getElementById("longitudeLabel").innerHTML = placeData.longitude;

}