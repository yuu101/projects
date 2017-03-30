
function LocationService() {
    this.getLocation = function (placeId, onSuccess) {
        $.ajax({
            type: "GET",
            url:"http://iweb.csie.ntut.edu.tw:9080/www71/Webservices/LocationService.svc/getLocation?placeId="+placeId,
            //url: "http://localhost:53201/WebServices/LocationService.svc/getLocation?placeId=" + placeId,
            dataType: "json",
            success: onSuccess
        });
    };
}