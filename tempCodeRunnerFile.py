from pytube import YouTube
from time import sleep
from os.path import expanduser
url = input("Podaj URL z YouTube'a: ")
path = expanduser("~/Downloads")

try:
    video = YouTube(url).streams.filter(progressive=True, file_extension='mp4').first()
    if video:
        video.download(path)
        print("Download successful! Video saved at:", path)
    else:
        print("No progressive MP4 stream available for the given URL.")
except Exception as e:
    print("An error occurred:", str(e))
