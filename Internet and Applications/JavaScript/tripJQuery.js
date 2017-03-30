window.onload = function () {
    $.fn.formatMoney = function () {
        return this.each(function () {
            $(this).text($(this).text().replace(/(\d)(?=(\d\d\d)+(?!\d))/g, "$1,"));
        }) //千分位
    }

    $('#calendarCanvas').fdatepicker('show').on('changeDate', function (ev) {
        $('#tripDateHiddenField').val(formatDate(ev.date));
    });  //日曆轉換

    var pid = $("input[name=placeRadioButtonList]:checked").val();
    placeRadioButtonList_onclick(pid);
}

function placeRadioButtonList_onclick(pid) {
    var locationService = new LocationService();
    locationService.getLocation(pid, showPlaceData);
}

function showPlaceData(placeData) {
    $("#placeImage").attr("src", "http://farm9.staticflickr.com/" + placeData.d.flickrId);

    $("#priceLabel").text(placeData.d.price).formatMoney();
    $("#priceHiddenField").val(placeData.d.price);

    $("#youtubeIdHiddenField").val(placeData.d.youtubeId);
    $("#latitudeHiddenField").val(placeData.d.latitude);
    $("#longitudeHiddenField").val(placeData.d.longitude);
    calculateTotal();
}

function calculateTotal() {
    var total = $("#priceHiddenField").val() * $("#daysTextBox").val();
    $("#totalLabel").text(total).formatMoney();
    $("#totalHiddenField").val(total);
}