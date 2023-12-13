from pytube import YouTube
from pytube import Playlist
from pytube.cli import on_progress
from os.path import expanduser

print("Filmik: 1 ", "playlista: 2 ")
wybor = int(input("Wybierz cyfre: "))
path = expanduser("~/Downloads")

if wybor == 1:
    link = input('Podaj link do filmiku:')
    try:
        yt = YouTube(link, on_progress_callback=on_progress)
        if yt:
            yt.streams.filter(progressive=True, file_extension='mp4').first().download(path)
            print("(:",{yt.title})
        else:
            print("Brak formatu mp4 dla tego linku ://")
    except Exception as e:
        print("Wystapil blad: ", str(e))

elif wybor == 2:
    link_p = (input("Podaj link do playlisty: "))
    try:
        playlist = Playlist(link_p)
        for video_url in playlist.video_urls:
            yt = YouTube(video_url, on_progress_callback=on_progress)
            if yt:
                yt.streams.filter(progressive=True, file_extension='mp4').first().download(path)
                print("(:",{yt.title})
            else:
                print("Brak formatu mp4 dla tego linku")
    except Exception as e:
        print("Wystapil blad: ", str(e))
else:
    print("Zly wybor podaj inna liczbe ")
