function fbLogout() {
    FacebookInit();
    FB.getLoginStatus(function (statusResponse) {
        if (statusResponse.status === 'connected') {
            FB.logout(function (response) {
                location.href = 'tripMenu.aspx';
            });
        }
    });
}