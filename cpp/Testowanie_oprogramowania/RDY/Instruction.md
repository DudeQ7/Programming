Instrukcja generowania raportu pokrycia (Coverage)

   /mnt/shared/Programming/cpp/Testowanie_oprogramowania/RDY
   - lcov (zawiera genhtml)
   - cmake, make, gcc/g++
sudo pacman -S lcov cmake make gcc

Komenda (zbuduje, uruchomi testy i wygeneruje HTML):
   cmake -S . -B . && make -j run_tests && ./scripts/coverage/coverage_report.sh .

4) Jeżeli używasz katalogu build/:
   cmake -S . -B build && make -C build -j run_tests && ./scripts/coverage/coverage_report.sh build

6) Wynik:
   Plik HTML z raportem będzie w katalogu coverage_report/index.html w wskazanym build_dir.

