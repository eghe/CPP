#ifndef _MEDIA_PLAYER_H_
#define _MEDIA_PLAYER_H_

#include <iostream>
#include <string>

class VlcPlayer {
public:
    void play(std::string filename) const
    {
        std::cout << "Vlc play: " << filename << std::endl;
    }
};

class Mp4Player {
public:
    void play(std::string filename) const
    {
        std::cout << "Mp4 play: " << filename << std::endl;
    }
};

class AdvancedMediaPlayer {
    VlcPlayer vlc;
    Mp4Player mp4;
public:
    void playVlc(std::string filename) const
    {
        vlc.play(filename);
    }

    void playMp4(std::string filename) const
    {
        mp4.play(filename);
    }
};

class MediaPlayer {
public:
    virtual void play(std::string format, std::string filename) const = 0;
};

class MediaAdapter: public MediaPlayer {
    AdvancedMediaPlayer amp;
public:
    void play(std::string format, std::string filename) const
    {
       if(!format.compare("vlc"))
           amp.playVlc(filename); 
       else if(!format.compare("mp4"))
           amp.playMp4(filename);    
       else
           std::cout << "AdvancedMediaPlayer: invalid format" << std::endl;    
    }
};

class AudioPlayer: public MediaPlayer {
    MediaAdapter ma;
public:    
    void play(std::string format, std::string filename) const
    {
        if(!format.compare("mp3"))
            std::cout << "AudioPlayer play: " << filename << std::endl;     
        else
            ma.play(format, filename);    
    }
};


#endif
