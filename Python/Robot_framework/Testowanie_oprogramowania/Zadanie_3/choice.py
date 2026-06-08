import subprocess
import os
import sys

def main():
    print("Które testy chcesz uruchomić?")
    print("1. Horizon")
    print("2. Sikuli")
    
    choice = input("Wybierz opcję (1 lub 2): ").strip()
    
    current_dir = os.path.dirname(os.path.abspath(__file__))
    
    if choice == "1":
        script_path = os.path.join(current_dir, "Horizon", "run_tests.py")
        print(f"Uruchamianie testów Horizon: {script_path}")
        subprocess.run([sys.executable, script_path])
    elif choice == "2":
        script_path = os.path.join(current_dir, "Sikuli", "run_tests.py")
        print(f"Uruchamianie testów Sikuli: {script_path}")
        subprocess.run([sys.executable, script_path])
    else:
        print("Nieprawidłowy wybór. Proszę wybrać 1 lub 2.")

if __name__ == "__main__":
    main()
