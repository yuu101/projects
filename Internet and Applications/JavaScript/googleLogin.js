function googleLogin() {

    var myParams = {
        'clientid': '206845465114-oqsq7pktd92vm8m8uj5ajk8ulqphfaoj.apps.googleusercontent.com',
        'cookiepolicy': 'single_host_origin',
        'callback': 'loginCallback',
        'approvalprompt': 'force',
        'scope': 'https://www.googleapis.com/auth/plus.login https://www.googleapis.com/auth/plus.profile.emails.read'
    };
    gapi.auth.signIn(myParams);
}

function loginCallback(result) {

    if (result['status']['signed_in']) {

        var request = gapi.client.plus.people.get(
        {
            'userId': 'me'
        });

        request.execute(function (resp) {

            var gId = resp['id'];
            var gName = resp['displayName'];
            var gImage = resp['image']['url'];
            var gEmail = resp['emails'][0]['value'];

            location.href = 'tripMenu.aspx?id=' + gId + '&name=' + gName + '&email=' + gEmail + '&picture=' + gImage + '&loginProvider=google';
        });
    }
}

function onLoadCallback() {
    gapi.client.setApiKey('AIzaSyChtIqZMAat6rBRx0givDrDs8uONU3AGZ4');
    gapi.client.load('plus', 'v1', function () { });
}