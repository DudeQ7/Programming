#!/bin/bash
# Tworzy środowisko wirtualne i instaluje zależności dla Zadania 5

set -e
cd "$(dirname "$0")"

python3 -m venv .venv
source .venv/bin/activate

pip install --upgrade pip
pip install pytest pytest-playwright playwright

# Pobierz przeglądarki (wystarczy Chromium)
python -m playwright install chromium

echo ""
echo "=== Gotowe! Uruchom testy: ==="
echo "  source .venv/bin/activate"
echo "  pytest test_kalkulator.py -v"
echo "  pytest test_kalkulator.py -v --headed    # z oknem przeglądarki"
