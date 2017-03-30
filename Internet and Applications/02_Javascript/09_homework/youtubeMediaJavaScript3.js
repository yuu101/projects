﻿var player;
var videoURL;

function onYouTubeIframeAPIReady() {
    videoURL = 'WO5fIA71FJc';

    player = new YT.Player('player', {
        height: '200',
        width: '200',
        videoId: videoURL,
        events: {
            'onReady': onPlayerReady,
            'onStateChange': onPlayerStateChange
        }
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