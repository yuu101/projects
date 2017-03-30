function logout() {
    if (loginProvider == 'google') {
        googleLogout();
    } else if (loginProvider == 'fb') {
        fbLogout();
    }
}