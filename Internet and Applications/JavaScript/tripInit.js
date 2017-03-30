$(document).ready(function () {
    open('homePage.html', 'mainFrame');

    if (loginProvider != '') {
        $('#fbLoginButton').hide();
        $('#googleLoginButton').css('display', 'none');
        $('#logoutButton').css('display', 'inherit');
    }
});