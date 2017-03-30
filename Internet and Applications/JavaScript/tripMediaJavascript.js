var isPlay = true;
var player = document.getElementById("tripMediaPlayer");

function playButton_onclick() {
    player.play();
    isPlay = true;
}

function pauseButton_onclick() {
    if (isPlay) {
        player.pause();
        isPlay = false;
    }
    else {
        player.play();
        isPlay = true;
    }
}

function stopButton_onclick() {
    player.stop();
    player.play();
    player.pause();
    isPlay = false;
}