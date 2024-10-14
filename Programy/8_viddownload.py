import math
from pytube import YouTube, Playlist
from os.path import expanduser
import time
from concurrent.futures import ThreadPoolExecutor

def on_progress_do(stream, chunk, bytes_remaining):
    total_size = stream.filesize
    bytes_downloaded = total_size - bytes_remaining

    live_speed = (total_size - bytes_remaining) / (time.time() - start_time)
    eta = (total_size - bytes_downloaded) / live_speed

    progress = (bytes_downloaded / total_size) * 100  # Progress in percentage
    progress_bar_len = math.ceil(progress)
    progress_bar = '█' * progress_bar_len + '-' * (100 - progress_bar_len)

    print(f'Progress: {progress:.1f}% [{progress_bar}] Speed: {live_speed:.2f} MB/s ETA: {eta:.2f} s', end='\r')

def select_quality(qualities):
    print("Available video qualities:")
    for i, quality in enumerate(qualities, 1):
        print(f"{i}. {quality.resolution}")
    while True:
        try:
            choice = int(input("Choose the number corresponding to the desired quality: "))
            if 1 <= choice <= len(qualities):
                return choice - 1
            else:
                print("Invalid choice. Please enter a number within the range.")
        except ValueError:
            print("Invalid input. Please enter a number.")

def download_video(link, path, choice):
    global start_time
    start_time = time.time()
    try:
        yt = YouTube(link, on_progress_callback=on_progress_do)
        if yt:
            qualities = yt.streams.filter(progressive=True).order_by('resolution').desc()
            qualities[choice].download(path)
            end_time = time.time()
            total_time = end_time - start_time
            file_size = qualities[choice].filesize / (1024 * 1024)  # File size in MB
            download_speed = file_size / total_time  # Download speed in MB/s
            print(f"\n{yt.title} downloaded in {total_time:.2f} seconds at {download_speed:.2f} Mb/s")
        else:
            print("No available format for this link.")
    except Exception as e:
        print("An error occurred: ", str(e))

while True:
    print("Filmik: 1 ", "playlista: 2 ")
    try:
        choice = int(input("Choose a number: "))
    except ValueError:
        print("Invalid input. Please enter a number.")
        continue

    path = expanduser("F:\\Python")  # Ensure the correct path format for Windows

    if choice == 1:
        link = input('Enter the video link:')
        yt = YouTube(link, on_progress_callback=on_progress_do)
        qualities = yt.streams.filter(progressive=True).order_by('resolution').desc()
        choice = select_quality(qualities)  # Prompt user to select quality
        download_video(link, path, choice)

    elif choice == 2:
        link_p = input("Enter the playlist link: ")
        try:
            playlist = Playlist(link_p)
            yt = YouTube(playlist.video_urls[0], on_progress_callback=on_progress_do)
            qualities = yt.streams.filter(progressive=True).order_by('resolution').desc()
            choice = select_quality(qualities)  # Prompt user to select quality
            with ThreadPoolExecutor(max_workers=5) as executor:  # Adjust max_workers as needed
                executor.map(download_video, playlist.video_urls, [path] * len(playlist.video_urls), [choice] * len(playlist.video_urls))
        except Exception as e:
            print("An error occurred: ", str(e))
    else:
        print("Invalid choice, please enter a different number.")
