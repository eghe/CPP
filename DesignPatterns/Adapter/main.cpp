#include "MediaPlayer.h"

int main()
{
    AudioPlayer mp;
    mp.play("mp3", "file.mp3");
    mp.play("mp4", "file.mp4");
    mp.play("vlc", "file.vlc");
    mp.play("avi", "file.avi");
    return 0;
}
