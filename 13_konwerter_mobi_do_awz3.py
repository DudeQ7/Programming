import os
import subprocess

def convert_to_awz3(directory):
    for filename in os.listdir(directory):
        if filename.endswith('.mobi') or filename.endswith('.epub'):
            file_path = os.path.join(directory, filename)
            output_path = os.path.splitext(file_path)[0] + '.azw3'
            try:
                subprocess.run(['ebook-convert', file_path, output_path], check=True)
                print(f'Successfully converted {file_path} to {output_path}')
            except subprocess.CalledProcessError as e:
                print(f'Failed to convert {file_path} to {output_path}. Error: {e}')

# Example usage:
convert_to_awz3(r'C:\Users\dudeq\Desktop\manka')
