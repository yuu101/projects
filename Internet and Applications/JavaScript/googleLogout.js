function googleLogout() {
    gapi.auth.signOut();
    location.href = 'tripMenu.aspx';
}