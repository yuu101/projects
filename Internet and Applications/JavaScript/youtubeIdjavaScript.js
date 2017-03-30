var player;

function onYouTubeIframeAPIReady() {
    var youtubeID = document.getElementById("FormView2_HiddenField2").value;

    player = new YT.Player('player', {
        height: '210', width: '280', videoId: youtubeID,
        events: { 'onReady': onPlayerReady, 'onStateChange': onPlayerStateChange }
    });

}

function onPlayerReady(event) {
    player.playVideo();
}

function onPlayerStateChange(event) {
    if (event.data == YT.PlayerState.ENDED) {
        player.playVideo();
        player.pauseVideo();
    }
}