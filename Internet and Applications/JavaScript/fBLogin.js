function FacebookInit() {
    FB.init({
        appId: '1593153210973619',
        status: true,
        cookie: true
    });
}

function facebookLogin() {

    FacebookInit();
    FB.login(function (loginResponse) {
        if (loginResponse.authResponse) {
            FB.api('/me', function (apiResponse) {
                var fbID = apiResponse.id;
                var fbName = apiResponse.name;
                var fbEmail = apiResponse.email;
                var image = "https://graph.facebook.com/" + fbID + "/picture";

                location.href = 'tripMenu.aspx?id=' + fbID + '&name=' + fbName + '&email=' + fbEmail + "&picture=" + image + '&loginProvider=fb';
            });
        }
    }, { scope: 'email' });
}