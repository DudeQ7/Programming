import yt_dlp
import os

def pobierz_film(url, sciezka):
    try:
        ydl_opts = {
            'outtmpl': os.path.join(sciezka, '%(title)s.%(ext)s'),
            'format': 'bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]',
            'merge_output_format': 'mp4',
            'postprocessors': [{
                'key': 'FFmpegVideoConvertor',
                'preferedformat': 'mp4',
            }],
        }
        with yt_dlp.YoutubeDL(ydl_opts) as ydl:
            ydl.download([url])
        print(f"Film pobrany pomyślnie do: {sciezka}")
    except Exception as e:
        print(f"Coś poszło nie tak: {e}")

def pobierz_playlistę(url, sciezka):
    try:
        ydl_opts = {
            'outtmpl': os.path.join(sciezka, '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s'),
            'format': 'bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]',
            'merge_output_format': 'mp4',
            'postprocessors': [{
                'key': 'FFmpegVideoConvertor',
                'preferedformat': 'mp4',
            }],
        }
        with yt_dlp.YoutubeDL(ydl_opts) as ydl:
            ydl.download([url])
        print(f"Playlistę pobrano pomyślnie do: {sciezka}")
    except Exception as e:
        print(f"Coś poszło nie tak: {e}")

def sprawdz_sciezke(sciezka):
    if not os.path.exists(sciezka):
        os.makedirs(sciezka)
    return sciezka

def menu():
    print("Witaj! Wybierz opcję:")
    print("1. Pobierz film z YouTube")
    print("2. Pobierz playlistę z YouTube")
    print("3. Zakończ")
    
    while True:
        wybor = input("Wybierz numer opcji: ")
        
        if wybor == "1":
            url = input("Podaj URL filmu: ")
            sciezka = input("Podaj ścieżkę do pobrania (zostaw puste dla domyślnej): ")
            sciezka = sciezka if sciezka else os.getcwd()
            sciezka = sprawdz_sciezke(sciezka)
            pobierz_film(url, sciezka)
        elif wybor == "2":
            url = input("Podaj URL playlisty: ")
            sciezka = input("Podaj ścieżkę do pobrania (zostaw puste dla domyślnej): ")
            sciezka = sciezka if sciezka else os.getcwd()
            sciezka = sprawdz_sciezke(sciezka)
            pobierz_playlistę(url, sciezka)
        elif wybor == "3":
            print("Do widzenia!")
            break
        else:
            print("Nieprawidłowa opcja, spróbuj ponownie.")

if __name__ == "__main__":
    menu()
