import os
import subprocess

def download_video(url):
    # Command to download best quality video
    video_cmd = [
        'youtube-dl',
        '-f', 'bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]/best',
        '--merge-output-format', 'mp4',
        '-o', 'output.%(ext)s',  # Output filename
        url
    ]

    try:
        # Execute command
        subprocess.run(video_cmd, check=True)
        print("Video downloaded successfully.")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred: {str(e)}")

# Replace with your YouTube video URL
url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ"
download_video(url)
