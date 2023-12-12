import time
def progress_bar(procenty=0, szerokosc=40):
    lewa = int(szerokosc * procenty / 100)
    prawa = szerokosc - lewa
    tag = "#" * lewa
    spacja = " " * prawa
    wowey = f"{procenty:.0f}%"
    print("\r[{}{}] {} ".format(tag, spacja, wowey), end="", flush=True)

for i in range(101):
    progress_bar(i)
    time.sleep(0.05)
