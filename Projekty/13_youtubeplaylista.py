import csv
import subprocess
import json

# === KONFIGURACJA ===
PLAYLIST_URL = "https://www.youtube.com/watch?v=KiEptGbnEBc&list=PLG49S3nxzAnl4QDVqK-hOnoqcSKEIDDuv"   # np. https://www.youtube.com/playlist?list=XXXX
OUTPUT_CSV = "security_plus_youtube.csv"

def get_playlist_items(playlist_url: str):
    """
    Zwraca listę filmów (dict) z playlisty:
    [{'title': '...', 'index': 1}, ...]
    używając yt-dlp w trybie JSON.
    """
    # yt-dlp zwróci po jednym obiekcie JSON na linię
    cmd = [
        "yt-dlp",
        "--flat-playlist",
        "--dump-json",
        playlist_url
    ]
    result = subprocess.run(cmd, capture_output=True, text=True, check=True)
    
    videos = []
    for line in result.stdout.splitlines():
        if not line.strip():
            continue
        data = json.loads(line)
        # data zawiera m.in. 'title' i 'playlist_index'
        videos.append({
            "title": data.get("title", "").strip(),
            "index": data.get("playlist_index")
        })
    # posortuj po indexie na wszelki wypadek
    videos.sort(key=lambda x: x["index"] or 0)
    return videos

def export_to_csv(videos, output_csv: str):
    """
    Zapisuje dane do CSV w formacie:
    Numer lekcji[Youtube], Topic, Status
    Status = 'Not Done'
    """
    with open(output_csv, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        # nagłówki dokładnie jak na screenie
        writer.writerow(["Numer lekcji[Youtube]", "Topic", "Status"])
        
        for v in videos:
            num = v["index"]
            title = v["title"]
            status = "Not Done"
            writer.writerow([num, title, status])

def main():
    print(f"Pobieram playlistę: {PLAYLIST_URL}")
    videos = get_playlist_items(PLAYLIST_URL)
    print(f"Znaleziono {len(videos)} filmów, zapisuję do: {OUTPUT_CSV}")
    export_to_csv(videos, OUTPUT_CSV)
    print("Gotowe. Otwórz plik w Excelu / LibreOffice i jedziesz z trackingiem :)")

if __name__ == "__main__":
    main()