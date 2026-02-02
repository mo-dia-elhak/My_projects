import yt_dlp
import os

def run():
    url = input("URL: ")
    print("1- Video\n2- Audio")
    c = input("Choice: ")
    
    path = '/storage/emulated/0/Download/%(title)s.%(ext)s'
    
    opts = {
        'outtmpl': path,
        'format': 'best[ext=mp4]/best' if c == '1' else 'bestaudio/best',
    }

    try:
        with yt_dlp.YoutubeDL(opts) as ydl:
            ydl.download([url])
        print("\nSaved to: /storage/emulated/0/Download/")
    except:
        opts['outtmpl'] = '%(title)s.%(ext)s'
        with yt_dlp.YoutubeDL(opts) as ydl:
            info = ydl.extract_info(url, download=True)
            print(f"\nSaved in app folder: {ydl.prepare_filename(info)}")

if __name__ == "__main__":
    run()
