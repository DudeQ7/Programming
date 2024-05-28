
from pytube import YouTube
from pytube import Playlist
from pytube.cli import on_progress
from os.path import expanduser
import time

def display_available_qualities(yt):
    video_streams = yt.streams.filter(only_video=True).order_by('resolution').desc()
    print("Available video qualities:")
    for i, stream in enumerate(video_streams):
        resolution = stream.resolution or "audio only"
        fps = getattr(stream, 'fps', 'N/A')
        print(f"{i+1}: {resolution}, {stream.mime_type}, {fps}fps, {stream.filesize / (1024 * 1024):.2f}MB")
    return video_streams
def download_video(link, path):
    try:
        yt = YouTube(link, on_progress_callback=on_progress)
        if yt:
            video_streams = display_available_qualities(yt)
            choice = int(input("Choose the quality number to download: ")) - 1
            start_time = time.time()
            video_streams[choice].download(path)
            end_time = time.time()
            total_time = end_time - start_time
            file_size = video_streams[choice].filesize / (1024 * 1024)  # File size in MB
            download_speed = file_size / total_time  # Download speed in MB/s
            print(f"(: {yt.title} downloaded in {total_time:.2f} seconds at {download_speed:.2f} Mb/s)")
        else:
            print("No available format for this link ://")
    except Exception as e:
        print("An error occurred: ", str(e))
print("Filmik: 1 ", "playlista: 2 ")
wybor = int(input("Wybierz cyfre: "))
path = expanduser("F:\\Python")  # Ensure the correct path format for Windows
if wybor == 1:
    link = input('Podaj link do filmiku:')
    download_video(link, path)
elif wybor == 2:
    link_p = input("Podaj link do playlisty: ")
    try:
        playlist = Playlist(link_p)
        for video_url in playlist.video_urls:
            download_video(video_url, path)
    except Exception as e:
        print("An error occurred: ", str(e))
else:
    print("Invalid choice, please enter a different number.")