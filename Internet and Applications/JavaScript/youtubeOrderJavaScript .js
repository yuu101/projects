var player;
var youtubeID;

function onYouTubeIframeAPIReady()
{
    youtubeID = document.getElementById("youtubeIdHiddenField").value;

    player = new YT.Player('player', {
        height: '480', width: '640', videoId: youtubeID,
        events:{'onReady':onPlayerReady,'onStateChange':onPlayerStateChange}
    });

}

    function onPlayerReady(event)
    {
        player.playVideo();
    }

    function onPlayerStateChange(event)
    {
        if(event.data==YT.PlayerState.ENDED)
        {
            player.playVideo();
            player.pauseVideo();
        }
    }